#include<stdio.h>

int main(){

int n,i;
int fact=1;
int *ptr2;
printf("Enter the number whose factorial you want to find");
scanf("%d",&n);
ptr2=&fact;
for(i=1;i<=n;i++){
    *ptr2=*ptr2*i;
    printf("The factorial of the %d is = %d\n The address of this is %d\n",i,*ptr2,ptr2);
}
printf("The factorial of the %d is = %d\n",n,*ptr2);

return 0;
}


