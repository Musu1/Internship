# Making a virtual sound card using alsa lib on RaspberryPI
A simple process to play a wav file with a virtual sound card. 

## Step-1

Check the existing soundcards in your system using the following command:
 
```cat /proc/asound/cards```

In my case ,I am doing on RaspberryPi and output looks like the following:

```0 [ALSA           ]: bcm2835_alsa - bcm2835 ALSA
                      bcm2835 ALSA```

So this gives us the card no. which is ```card 0``` ,So card and device we will be using  are ```hw:0,0```.

**Note** - This info will vary depending on your system.

## Step-2

Now to create a virtual device you need to create ```asound.conf``` file in ```/etc`` directory :

```cd /etc```

Now create a asound.conf file in this directory as created in this repo. In this file ```samplecard``` is the name of the new card which you can change and add card and device name according to your system.

Finally restart ALSA using : ```alsactl restore```

## Step-3

Now to check whether it's created or not just type the command : ```speaker-test -Dsamplecard -c2```

If it does not throw any error then you are good to go.

## Step-4

Now just play your wav file using the following command on your preferred soundcard:

```aplay -D samplecard test.wav```


## References

- https://github.com/carrotsrc/StrangeIO/wiki/ALSA-Virtual-Device
- https://superuser.com/questions/626606/how-to-make-alsa-pick-a-preferred-sound-device-automatically
- https://www.alsa-project.org/main/index.php/Asoundrc

