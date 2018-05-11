#include <stdio.h>
#include<math.h>

int print(long n){

int i;
int c=0;
if(n<10){
    for(i=1;i<=n;i++)
    {
        if(n%i==0){
            c++;
        }
    }
    if(c==2){
        printf("\nCode says %d is a prime number\n",n);
    }
    else{
        printf("\nCode says %d is not a prime number\n",n);

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
    printf("\nCode says %d is a prime number\n",n);
}
else{
    printf("\nCode says %d is not a prime number\n",n);
}
}
return 0;
}


int test(){
    long n;
    int i;
    int c=0;
    n=0;
    if(n==0 || n==1){
        print(n);
        printf("And facts say 0 and 1 is neither prime nor composite\n");
        }
    n=1;
    if(n==0 || n==1){
        print(n);
        printf("And facts say 0 and 1 is neither prime nor composite\n");
        }
    return 0;
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
        case 2:test();
               break;
        case 3:return 1;
        default:
                printf("\nInvalid choice\n");

    }
    }while(1);
    return 0;

}


