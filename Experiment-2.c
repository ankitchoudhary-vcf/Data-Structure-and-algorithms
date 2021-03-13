/***
 * To calculate factorial using recursion
 ***/

#include<stdio.h>

int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
    
}

int main()
{
    int n;
    printf("Enter the value of n => ");
    scanf("%d",&n);
    printf("Factorial of %d is %d ",n,fact(n));
    return 0;
}