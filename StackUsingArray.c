// Stack and various operations on it
#include <stdio.h>
#include <stdlib.h>

//Creating Structer of stack
struct stackUsingArray
{
    int *arr;
    int top;
    int Capacity;
};

//Declaration of function
struct stackUsingArray *Createstack();
void push(struct stackUsingArray *);
void pop(struct stackUsingArray *, int created);
void display(struct stackUsingArray *, int created);
void peek(struct stackUsingArray*, int created);

//Creating stack
struct stackUsingArray *Createstack()
{
    struct stackUsingArray *stack;
    stack = (struct stackUsingArray *)malloc(sizeof(struct stackUsingArray));
    printf("Enter the value of Capacity of stack => ");
    scanf("%d", &stack->Capacity);
    stack->arr = malloc(sizeof(int) * stack->Capacity);
    stack->top = -1;
    return stack;
}

//push function is used to push or insert data at top of the stack
void push(struct stackUsingArray *stack)
{

    if (stack->top == stack->Capacity - 1)
    {
        printf("stack is full, you can't push any more data !! \n");
    }
    else
    {
        stack->top++;
        printf("Enter the data => ");
        scanf("%d", &stack->arr[stack->top]);
        printf("***********************************--Data has been susscessfully pushed--***********************************\n");
    }
}

//pop function is used to pop out or delect data from top of the stack

void pop(struct stackUsingArray *stack, int created)
{
    int popValue;
    if (created == 0)
    {
        printf("Stack is not created yet !! \n");
    }
    else
    {
        if (stack->top == -1)
        {
            printf("Stack is Empty !! \n");
        }
        else
        {
            popValue = stack->arr[stack->top];
            stack->top -= 1;
            printf("The popped value is %d \n", popValue);
            printf("***********************************--Data has been susscessfully popped out--***********************************\n");
        }
    }
}

//Display function is used to view or display the data into the stack
void display(struct stackUsingArray *stack, int created)
{
    int len;
    if (stack->top == -1)
    {
        printf("Stack is Empty !! \n");
    }
    else
    {

        printf("The contantes of stack are:- ");
        len = stack->top;
        while (len != -1)
        {
            printf(" %d ", stack->arr[len]);
            len -= 1;
        }
        printf("\n***********************************--Data has been susscessfully displayed--***********************************\n");
    }
}

//Function to display peek value

void peek(struct stackUsingArray *stack, int created)
{
    if (created == 0)
    {
        printf("Stack is not created yet !! \n");
    }
    else
    {
        if (stack->top == -1)
        {
            printf("Stack is Empty !! \n");
        }
        else
        {
            printf("The peek value is:- %d\n ", stack->arr[stack->top] );
        }   
    }
    
}

int main()
{
    int created = 0, ch, n, i;
    struct stackUsingArray *stack;
    printf("\n\n Menu of Operation\n");
    printf("--------------------------------------------------------\n");
    printf("\t\t 1-> Creating Stack\n");
    printf("\t\t 2-> To push data in stack\n");
    printf("\t\t 3-> To pop out data from stack\n");
    printf("\t\t 4-> To view the stack\n");
    printf("\t\t 5-> To view the peek value of stack\n");
    printf("\t\t 6-> Exit\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------\n");

    while (1)
    {
        printf("Enter your choice => ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (created == 0)
            {
                stack = Createstack();
                created++;
                printf("Enter the number of data you want to enter in stack => ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    push(stack);
                }
                printf("\n***********************************--Stack has been Created susscessfully--***********************************\n");
            }
            else
            {
                printf("Stack has already been created \n");
            }
            break;
        case 2:
            if (created == 0)
            {
                stack = Createstack();
                created++;
                push(stack);
            }
            else
            {
                push(stack);
            }
            break;
        case 3:
            pop(stack, created);
            break;
        case 4:
            display(stack, created);
            break;
        case 5:
            peek(stack, created);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Input \n");
            break;
        }
    }

    return 0;
}