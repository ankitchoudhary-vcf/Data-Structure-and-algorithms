#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
    	rear->next = newnode;
        rear = newnode;
    }
}
void display()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("queue is %d\n", temp->data);
            temp = temp->next;
        }
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("the %d element dequeue\n", front->data);
        front = front->next;
        free(temp);
    }
}
void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("the peek value is %d\n", front->data);
    }
}
void main()
{
    enqueue(5);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    display();
    peek();
    dequeue();
    peek();
    display();
}
