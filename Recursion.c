            // Recursion
/***
 * Recursion:- calling a function in the same function is known as recursion.
 * 
 * Types of Recursion:-
 *      - Tail Recursion
 *      - Head Recursion
 *      - Tree Recursion
 *      - Nested Recursion
 ***/

//Tail Recursion
#include<stdio.h>

void fun1(int n)
{
    if (n>0)
    {
        printf("%d\n",n);
        fun1(n-1);
    }
}

//Tree Recursion
void fun6(int n)
{
    if (n>0)
    {
        printf("%d\n",n);
        fun6(n-1);
        fun6(n-1);
    }
}
//Head Recursion
void fun2(int n)
{
    if (n>0)
    {
        fun1(n-1);
        printf("%d\n",n);
    }
}

//
int fun3(int n)
{
    if(n > 0)
    {
        return fun3(n-1) + n;
    }
    return 0;
}

int fun4(int n)
{
    int x = 0;
    if(n > 0)
    {
        x++;
        return fun4(n-1) + x;
    }
    return 0;
}

int fun5(int n)
{
    static int x;
    if(n > 0)
    {
        x++;
        return fun5(n-1) + x;
    }
    return 0;
}

//Nested Recursion
int fun7(int n)
{
    if(n>100)
        return n-10;
    else
        return fun7(fun7(n+11));
}


int main()
{
    int n = 3;
    printf("Example of tail recursion \n");
    fun1(n);
    printf("*******************************************\n");
    printf("Example of Head recursion \n");
    fun2(n);
    printf("*******************************************\n");
    printf("Example of recursion \n");
    printf("%d\n" ,fun3(n));
    printf("*******************************************\n");
    printf("Example of recursion \n");
    printf("%d\n" ,fun4(n));
    printf("*******************************************\n");
    printf("Example of recursion \n");
    printf("%d\n" ,fun5(n));
    printf("*******************************************\n");
    printf("Example of recursion \n");
    fun6(n);
    printf("*******************************************\n");
    printf("Example of recursion \n");
    printf("%d\n" ,fun7(99));
    return 0;
}