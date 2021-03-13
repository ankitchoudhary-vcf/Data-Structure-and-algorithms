#include <conio.h>
#include <stdio.h>
#define N 5
int deque[N];
int f = -1, r = -1;
void enqueuefront(int x)
{
    if ((f == 0 && r == N - 1))
    {
        printf("queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        deque[f] = x;
    }
    else
    {
    	int i;
        r=r+1;
        for(i=r; i>=1; i--)
        {
        	deque[i]=deque[i-1];	
		}
		deque[f]=x;
    }
}
void enqueuerear(int x)
{
    if ((f == 0 && r == N - 1))
    {
        printf("queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}
void display()
{
    int i = f;
    printf("the queue is:- ");
    while (i != r)
    {
        printf(" %d ", deque[i]);
        i = (i + 1) % N;
    }
    printf(" %d \n", deque[r]);
}
void getfront()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("the front of queue is %d \n", deque[f]);
    }
}
void getrear()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("the rear of queue is %d \n", deque[r]);
    }
}
void dequeuefront()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (f == N - 1)
    {
        printf("the dequeue from front is %d \n", deque[f]);
        f = 0;
    }
    else
    {
        printf("the dequeue from front is %d \n", deque[f]);
        f++;
    }
}
void dequeuerear()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (r == 0)
    {
        printf("the dequeue from rear is %d \n", deque[r]);
        r = N - 1;
    }
    else
    {
        printf("the dequeue from rear is %d \n", deque[r]);
        r--;
    }
}
void main()
{
    enqueuefront(2);
    enqueuefront(5);
    enqueuerear(-1);
    enqueuefront(0);
    enqueuefront(7);
    display();
    //getrear();
    //getfront();
    dequeuefront();
    dequeuerear();
    dequeuefront();
    display();
}
