#include <stdio.h>
#include "function.c"

int main(void)
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int result;
    float result1;
    result=add(a,b);
    printf("Sum is %d\n",result);
    result=sub(a,b);
    printf("sub is%d\n",result);
    result=mul(a,b);
    printf("mul is%d\n",result);
    result1=divide(a,b);
    printf("divide is%f\n",result1);
    
}