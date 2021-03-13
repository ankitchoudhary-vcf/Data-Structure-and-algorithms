/***
 * Power using Recursion
 ***/

#include<stdio.h>

int pow(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return m*pow(m, (n-1));
        
    }
    
}

int pow1(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return pow1(m*m, n/2);
    }
    else
    {
        return m*pow1(m*m, (n-1)/2);
        
    }
    
}


int main()
{
    int n,m;
    printf("Enter the value of m => ");
    scanf("%d",&m);
    printf("Enter the value of n => ");
    scanf("%d",&n);
    printf("%d",pow1(m, n));
    return 0;
}