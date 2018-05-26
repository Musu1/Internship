/*word_detection.c - Simple pocketsphinx command-line application to test
 *                both continuous listening/silence filtering from microphone
 *                and continuous file transcription.
 */

/*
 * This is a simple example of pocketsphinx application that uses continuous listening
 * with silence filtering to automatically segment a continuous stream of audio input
 * into utterances that are then decoded.
 * 
 * Remarks:
 *   - Each utterance is ended when a silence segment of at least 1 sec is recognized.
 *   - Single-threaded implementation for portability.
 *   - Uses audio library; can be replaced with an equivalent custom library.
 */


/*Header file for c compiler*/
#include <stdio.h>
#include <string.h>
#include <assert.h>


/*Header files depending on the operating system*/
#if defined(_WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#else
#include <sys/select.h>
#endif

/*Header files for the Sphinxbase*/
#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>

/*Header files for the pocketsphinx features*/
#include <pocketsphinx.h>



static const arg_t cont_args_def[] = {
    POCKETSPHINX_OPTIONS,
    /* Argument file. */
    {"-argfile",
     ARG_STRING,
     NULL,
     "Argument file giving extra arguments."},
    {"-adcdev",
     ARG_STRING,
     NULL,
     "Name of audio device to use for input."},
    {"-infile",
     ARG_STRING,
     NULL,
     "Audio file to transcribe."},
    {"-inmic",
     ARG_BOOLEAN,
     "no",
     "Transcribe audio from microphone."},
    {"-time",
     ARG_BOOLEAN,
     "no",
     "Print word times in file transcription."},
    CMDLN_EMPTY_OPTION
};


//ps-decoder_t -- pocketsphinx speech recognizer object


static ps_decoder_t *ps;
static cmd_ln_t *config;
static FILE *rawfd;



/*
 Function: print_word_times 
 
 Parameter: None
 
 Functionality:It prints the number of times a word has been repeated in the given file
 */

static void
print_word_times()
{
/*Inbuilt Function:cmd_ln_int32_r(config,name) 

Retrieve an integer from a command-line object.

Parameters:
config 	Command-line object.
name 	the command-line flag to retrieve.

Returns:
the integer value associated with name, or 0 if name does not exist. You must use cmd_ln_exists_r() to distinguish between cases where a value is legitimately 
zero and where the corresponding flag is unknown.
 */

    int frame_rate = cmd_ln_int32_r(config, "-frate");
    
/*Inbuilt Function:ps_seg_iter
Returns:Iterator over the best hypothesis at this point in decoding. NULL if no hypothesis is available
 iter will give detailed wor segmentation info
 */  
    ps_seg_t *iter = ps_seg_iter(ps);
    while (iter != NULL) {
        int32 sf, ef, pprob;
        float conf;
/*ps_seg_frames (ps_seg_t *seg, int *out_sf, int *out_ef)
 	Get start and end frames from a segmentation iterator.
*/        
        ps_seg_frames(iter, &sf, &ef);
        
        
/*POCKETSPHINX_EXPORT int32 ps_seg_prob	(	ps_seg_t * 	seg,
int32 * 	out_ascr,
int32 * 	out_lscr,
int32 * 	out_lback	 
)			
Get language, acoustic, and posterior probabilities from a segmentation iterator.

Note:
Unless the -bestpath option is enabled, this function will always return zero (corresponding to a posterior probability of 1.0). Even if -bestpath is enabled, 
it will also return zero when called on a partial result. Ongoing research into effective confidence annotation for partial hypotheses may result in these 
restrictions being lifted in future versions.
Parameters:
out_ascr 	Output: acoustic model score for this segment.
out_lscr 	Output: language model score for this segment.
out_lback 	Output: language model backoff mode for this segment (i.e. the number of words used in calculating lscr). This field is, of course, only meaningful 
for N-Gram models.
Returns:
Log posterior probability of current segment. Log is expressed in the log-base used in the decoder. To convert to linear floating-point,
 use logmath_exp(ps_get_logmath(), pprob).
*/      
  
        pprob = ps_seg_prob(iter, NULL, NULL, NULL);
        conf = logmath_exp(ps_get_logmath(ps), pprob);
        printf("%s %.3f %.3f %f\n", ps_seg_word(iter), ((float)sf / frame_rate),
               ((float) ef / frame_rate), conf);
/*
 ps_seg_next---Get the next segment in a word segmentation.

Returns:
Updated iterator with the next segment. NULL at end of utterance (the iterator will be freed in this case
 */
        iter = ps_seg_next(iter);
    }
}


/* check the link-http://www.topherlee.com/software/pcm-tut-wavformat.html  to get the basic info about the header in wave
file*/

/*Function:check_wav_header

Parameter:
          expected sample rate of the given wav file
          header of the given wav file

Functionality:
            checks wether the given wav file follows the following requirement
            1.Checks its bits per sample, it should be 16
            2.checks wether audio file is compressed or not,it should not be compressed
            3.checks the channel in the audio file we want mono channel
            4.checks the sample rate of the audio file which should match the given sample rate
    
    Returns:0 if the wav file do not follow above requirements
            1 if the wav file is approved

*/


static int
check_wav_header(char *header, int expected_sr)
{
    int sr;

    if (header[34] != 0x10) {
        E_ERROR("Input audio file has [%d] bits per sample instead of 16\n", header[34]);
        return 0;
    }
    if (header[20] != 0x1) {
        E_ERROR("Input audio file has compression [%d] and not required PCM\n", header[20]);
        return 0;
    }
    if (header[22] != 0x1) {
        E_ERROR("Input audio file has [%d] channels, expected single channel mono\n", header[22]);
        return 0;
    }
    sr = ((header[24] & 0xFF) | ((header[25] & 0xFF) << 8) | ((header[26] & 0xFF) << 16) | ((header[27] & 0xFF) << 24));
    if (sr != expected_sr) {
        E_ERROR("Input audio file has sample rate [%d], but decoder expects [%d]\n", sr, expected_sr);
        return 0;
    }
    return 1;
}

/*
 * Continuous recognition from a wav file
 */


static void
recognize_from_file()
{
    int16 adbuf[2048]; //the raw file data will be read by this array
    const char *fname; //To store the file name
    const char *hyp; // String containing best hypothesis at this point in decoding
    int32 k;         // k is the no. of samples
    uint8 utt_started, in_speech; //in_speech stores the data to check whether last buffer had speech or not
    //cmd_ln_boolean_r-Retrieve a boolean from the global command line.
    int32 print_times = cmd_ln_boolean_r(config, "-time");
    //cmd_ln_str_r-Retrieve a string from the global command line.
    fname = cmd_ln_str_r(config, "-infile");
    //trying to open the input file if could not then an error message will be displayed
    if ((rawfd = fopen(fname, "rb")) == NULL) {  //rawfd is raw file data has the data of the given file
        E_FATAL_SYSTEM("Failed to open file '%s' for reading",
                       fname);
    }
/* checking wether the file is in wav format or not if yes then reading the header of wav file in waveheader array and 
    ckecking the whole format by calling check_wav_header function and if the sample rate and other categories do not match 
    an error will occur*/
   
    if (strlen(fname) > 4 && strcmp(fname + strlen(fname) - 4, ".wav") == 0) {
        char waveheader[44]; // wavheader array stores the info of the header of wav file
	fread(waveheader, 1, 44, rawfd); // reading the header info from the file and storing to wavheader
	if (!check_wav_header(waveheader, (int)cmd_ln_float32_r(config, "-samprate")))
	    E_FATAL("Failed to process file '%s' due to format mismatch.\n", fname);
    }
/*Checking if the file is mp3 if yes then triggering error that the following file is mp3 first convert to wav format*/
    if (strlen(fname) > 4 && strcmp(fname + strlen(fname) - 4, ".mp3") == 0) {
	E_FATAL("Can not decode mp3 files, convert input file to WAV 16kHz 16-bit mono before decoding.\n");
    }
/*Function:int ps_start_utt	(ps_decoder_t * 	ps)			
    
This function should be called before any utterance data is passed to the decoder. It marks the start of a new utterance 
and reinitializes internal data structures.

Parameters:
           ps --	Decoder to be started.
Returns:
        0 for success, <0 on error.
*/
    ps_start_utt(ps);
    utt_started = FALSE;

    while ((k = fread(adbuf, sizeof(int16), 2048, rawfd)) > 0) {
       
/* int ps_process_raw(ps_decoder_t * s,int16 const * data,size_t n_samples,int no_search,int full_utt)
			
Decode raw audio data.

Parameters:
            ps 	Decoder.
            no_search 	If non-zero, perform feature extraction but don't do any recognition yet. This may be necessary if
                        your processor has trouble doing recognition in real-time.
            full_utt 	If non-zero, this block of data is a full utterance worth of data. This may allow the recognizer to 
                        produce more accurate results.
Returns:
            Number of frames of data searched, or <0 for error.
*/
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);
/*uint8 ps_get_in_speech(ps_decoder_t * ps)

Checks if the last feed audio buffer contained speech.

Parameters
            ps	Decoder.
Returns
            1 if last buffer contained speech, 0 - otherwise
*/
        in_speech = ps_get_in_speech(ps);
        if (in_speech && !utt_started) {
            utt_started = TRUE;
        } 
        if (!in_speech && utt_started) {
            ps_end_utt(ps);
/*char const* ps_get_hyp(ps_decoder_t* ps,int32* out_best_score,char const** out_uttid)			

Get hypothesis string and path score.

Parameters:
            out_best_score 	Output: path score corresponding to returned string.
            out_uttid 	Output: utterance ID for this utterance.

Returns:
String containing best hypothesis at this point in decoding. NULL if no hypothesis is available.
*/
            hyp = ps_get_hyp(ps, NULL);
            if (hyp != NULL)
        	printf("%s\n", hyp);
            if (print_times)
        	print_word_times();
            fflush(stdout);

            ps_start_utt(ps);
            utt_started = FALSE;
        }
    }
    ps_end_utt(ps);
    if (utt_started) {
        hyp = ps_get_hyp(ps, NULL);
        if (hyp != NULL) {
    	    printf("%s\n", hyp);
    	    if (print_times) {
    		print_word_times();
	    }
	}
    }
    
    fclose(rawfd);
}

/* Sleep for specified msec */
static void
sleep_msec(int32 ms)
{
#if (defined(_WIN32) && !defined(GNUWINCE)) || defined(_WIN32_WCE)
    Sleep(ms);
#else
    /* ------------------- Unix ------------------ */
    struct timeval tmo;

    tmo.tv_sec = 0;
    tmo.tv_usec = ms * 1000;

    select(0, NULL, NULL, NULL, &tmo);
#endif
}

/*
 * Main utterance processing loop:
 *     for (;;) {
 *        start utterance and wait for speech to process
 *        decoding till end-of-utterance silence will be detected
 *        print utterance result;
 *     }
 */

//Function to recognize from microphone
static void
recognize_from_microphone()
{
    ad_rec_t *ad;
    int16 adbuf[2048];
    uint8 utt_started, in_speech;
    int32 k;
    char const *hyp;

    if ((ad = ad_open_dev(cmd_ln_str_r(config, "-adcdev"),
                          (int) cmd_ln_float32_r(config,
                                                 "-samprate"))) == NULL)
        E_FATAL("Failed to open audio device\n");
    if (ad_start_rec(ad) < 0)
        E_FATAL("Failed to start recording\n");

    if (ps_start_utt(ps) < 0)
        E_FATAL("Failed to start utterance\n");
    utt_started = FALSE;
    E_INFO("Ready....\n");

    for (;;) {
        if ((k = ad_read(ad, adbuf, 2048)) < 0)
            E_FATAL("Failed to read audio\n");
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);
        in_speech = ps_get_in_speech(ps);
        if (in_speech && !utt_started) {
            utt_started = TRUE;
            E_INFO("Listening...\n");
        }
        if (!in_speech && utt_started) {
            /* speech -> silence transition, time to start new utterance  */
            ps_end_utt(ps);
            hyp = ps_get_hyp(ps, NULL );
            if (hyp != NULL) {
                printf("%s\n", hyp);
                fflush(stdout);
            }

            if (ps_start_utt(ps) < 0)
                E_FATAL("Failed to start utterance\n");
            utt_started = FALSE;
            E_INFO("Ready....\n");
        }
        sleep_msec(100);
    }
    ad_close(ad);
}

int
main(int argc, char *argv[])
{
    char const *cfg;

    config = cmd_ln_parse_r(NULL, cont_args_def, argc, argv, TRUE);

    /* Handle argument file as -argfile. */
    if (config && (cfg = cmd_ln_str_r(config, "-argfile")) != NULL) {
        config = cmd_ln_parse_file_r(config, cont_args_def, cfg, FALSE);
    }

    if (config == NULL || (cmd_ln_str_r(config, "-infile") == NULL && cmd_ln_boolean_r(config, "-inmic") == FALSE)) {
	E_INFO("Specify '-infile <file.wav>' to recognize from file or '-inmic yes' to recognize from microphone.\n");
        cmd_ln_free_r(config);
	return 1;
    }

    ps_default_search_args(config);
    ps = ps_init(config);
    if (ps == NULL) {
        cmd_ln_free_r(config);
        return 1;
    }

    E_INFO("%s COMPILED ON: %s, AT: %s\n\n", argv[0], __DATE__, __TIME__);

    if (cmd_ln_str_r(config, "-infile") != NULL) {
        recognize_from_file();
    } else if (cmd_ln_boolean_r(config, "-inmic")) {
        recognize_from_microphone();
    }

    ps_free(ps);
    cmd_ln_free_r(config);

    return 0;
}



/*Compile and run instructions:

Compile 
gcc $(file name) -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" `pkg-config --cflags --libs pocketsphinx sphinxbase

Then export
export LD_LIBRARY_PATH=/usr/local/lib
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig

Run

1.To recognize speech from microphone:-
./a.out -inmic yes -hmm model/en-us/en-us -lm model/en-us/en-us.lm.bin -dict model/en-us/cmudict-en-us.dict

2.To recognize speech from a file:
./a.out -infile test/data/goforward.raw -hmm model/en-us/en-us -lm model/en-us/en-us.lm.bin -keyphrase "test"


Note: Consider the following for the above compile and run model
1.directory of model if not same go to that directory
2.goforward.raw is inbuilt audio filr in the package if youy wand to teat your own just include in the directory and mention
the path here
*/

