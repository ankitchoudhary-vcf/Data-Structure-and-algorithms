/***
 * Fibonacci series using recursion
 ***/

#include<stdio.h>
#include<time.h>

int  F[50];

int fib(int n)
{
    if( n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int fib1(int n)
{
    int i;

    for(i = 0; i <= n; i++)
    {
        F[i] = -1;
    }

    if(F[n] == -1)
    {
        if( n <= 1)
            F[n] = n;
        F[n] = fib(n - 1) + fib(n - 2);
    }
    return F[n];
}

int fib2(int n)
{
    int i;
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    for(i=2; i<=n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];

}

int main()
{
    int n;
    clock_t begin, end;
    double time_spend;
    printf("Enter the value of n => ");
    scanf("%d",&n);
    begin = clock();
    printf("%d\n", fib1(n));
    end =clock();
    time_spend = (double)(end - begin)/CLK_TCK;
    printf("Time taken => %lf\n ",time_spend);
    return 0;
}
