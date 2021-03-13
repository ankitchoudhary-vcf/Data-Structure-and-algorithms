/***
 * To find sum of n natural number using recursion
 ***/

#include<stdio.h>
#include<conio.h>

int fun(int n)
{
    if(n >0)
    {
       return n + fun(n-1);
    }
    else
    {
        return 0;
    }
    
    
}

int main()
{
    int n;
    printf("Enter the value of n => ");
    scanf("%d",&n);
    printf("%d",fun(n));
    return 0;
    getch();
}