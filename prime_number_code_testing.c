#include<stdio.h>
int main(){

int n,i,c=0;
printf("enter the number");
scanf("%d",&n);
for(i=0;i<=n;i++){
    if(n%i==0){
        c++;
    }
}
if(c==2){
    printf("given number is prime");
}
else{
    printf("This is not a prime number");
}
return 0;
}
