#include <stdio.h>
#include<math.h>

char print(long n){

int i;
int c=0;
char output;
if(n<10){
    for(i=1;i<=n;i++)
    {
        if(n%i==0){
            c++;
        }
    }
    if(c==2){
        output='p';
        printf("Code says %d is a prime number\n",n);//p means it is a prime number
    }
    else{
        output='n';
        printf("Code says %d is not a prime number\n",n);//n means not a prime number

    }
}
else{
for(i=2;i<=10;i++){
    int d;
    d=n%i;
    if( d==0 ){
    c=1;
    break;
    }
}
if(c==0){
    output='p';
    printf("Code says %d is a prime number\n",n);//p means it is a prime number
}
else{
    output='n';
    printf("Code says %d is not a prime number\n",n);//n means not a prime number
}
}
return output;
}


int test(int input,char expected,int test_case){
    char output;
    output=print(input);
    if(output==expected){
        printf("TestCase %d passed\n",test_case);
    }
    else{
        printf("Test case %d failed\n",test_case);
    }
}


int main(){
    do{
    printf("\npress 1 to run the code\n");
    printf("press 2 to test the code\n");
    printf("press 3 to exit the code\n");
    printf("\nEnter your choice\n");
    int y;
    long n;
    scanf("%d",&y);
    switch(y){
        case 1:printf("\nenter the number\n");
               scanf("%d",&n);
               print(n);
               break;
        case 2:test(2,'p',1);
               test(3,'p',2);
               test(4,'n',3);
               test(23,'p',4);
               test(27,'n',5);
               test(29,'p',6);
               test(31,'p',7);
               break;
        case 3:return 1;
        default:
                printf("\nInvalid choice\n");

    }
    }while(1);
    return 0;

}


