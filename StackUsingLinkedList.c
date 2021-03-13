            // Stack Using Linked List

#include<stdio.h>
#include<stdlib.h>

struct StackNode
{
    int data;
    struct StackNode *next;
};
struct StackNode *Top = NULL;

struct StackNode **Stack = &Top;

// Declaration of function
struct StackNode *getnode();
void push();
void pop();
void peek();
void display();

// creating stack node
struct StackNode *getnode()
{
    struct StackNode *newnode;
    newnode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newnode->next = NULL;
    return newnode;
}

//push data into stack
void push()
{
    struct StackNode *newnode;
    newnode = getnode();
    printf("\n\tEnter the data => ");
    scanf("%d",&newnode->data);
    if( newnode == NULL )
    {
        printf("\n\n\t\t Stack Overflow..");
        return;
    }
    if ((*Stack) == NULL)
    {
        (*Stack) = newnode;
    }
    else
    {
        newnode->next = (*Stack);
        (*Stack) = newnode;
    }
    printf("\t\t\tData is pushed\n");
    printf("\t\t-----------**********-------------\n");
}

//pop data from stack
void pop()
{
    if ((*Stack) == NULL)
    {
        printf("\n\n\t\t\tStack is Empty\n");
    }
    else
    {
        struct StackNode *temp;
        temp = (*Stack);
        printf("\n\n\t\t\tPopped value is %d\n",temp->data);
        (*Stack) = (*Stack)->next;
        free(temp);
    }
    printf("\t\t-----------**********-------------\n");
}

//Peek function
void peek()
{
    if((*Stack) == NULL)
    {
        printf("\n\n\t\t\tStack is Empty\n");
    }
    else
    {
        printf("\n\n\t\t\tPeek value is %d\n",(*Stack)->data);
    }
    printf("\t\t-----------**********-------------\n");
    
}

//Display Stack

void display()
{
    struct StackNode *temp;
    if ((*Stack) == NULL)
    {
        printf("\n\n\t\t\tStack is Empty\n");
    }
    else
    {
        temp = (*Stack);
        printf("\n\n\t\t Elements in the stack:  ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\t\t-----------**********-------------\n");
}

void menu()
{
    printf("\n\tStack operations using pointers.. ");
    printf("\n--------------*********************************--------------\n");
    printf("\t1. push\n");
    printf("\t2.Pop\n");
    printf("\t3. Peek\n");
    printf("\t4. Display\n");
    printf("\t5. Exit\n");
    printf("--------------*********************************--------------\n");

}

int main()
{
    int ch;
    menu();
    while (1)
    {
        printf("\tEnter your choice => ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input\n");
                break;
        }
    }
    
    return 0;
}