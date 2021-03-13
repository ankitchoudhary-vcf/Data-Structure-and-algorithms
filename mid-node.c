#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *CreateNode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    return newnode;
};

void push(struct node **head, int items)
{
    struct node *newnode;
    newnode = CreateNode();
    if (*head == NULL)
    {
        *head = newnode;
        newnode->data = items;
        newnode->next = NULL;
    }
    else
    {
        newnode->data = items;
        newnode->next = *head;
        *head = newnode;
    }
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void mid_node(struct node *head)
{
    struct node *a = head;
    struct node *b = head;

    if(head != NULL)
    {
        while(b != NULL && b->next != NULL)
        {
            b = b->next->next;
            a = a->next;
        }
        printf("The middle element is %d ", a->data);
    }
}


int main()
{
    struct node *Start;
    Start = NULL;
    push(&Start, 10);
    push(&Start, 20);
    push(&Start, 30);
    push(&Start, 40);

    print(Start);
    printf("\n");
    mid_node(Start);
}