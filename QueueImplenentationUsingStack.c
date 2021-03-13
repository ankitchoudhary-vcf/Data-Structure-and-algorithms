// Implement of Queue using Stack

#include <stdio.h>
#include <stdlib.h>

/* structure of a stack node */
struct sNode
{
        int data;
        struct sNode *next;
};

/* Function to push an item to stack*/
void push(struct sNode **top_ref, int new_data);

/* Function to pop an item from stack*/
int pop(struct sNode **top_ref);

/* structure of queue having two stacks */
struct queue
{
        struct sNode *stack1;
        struct sNode *stack2;
};

/* Function to enqueue an item to queue */
void enQueue(struct queue *q, int x)
{
        push(&q->stack1, x);
}

/* Function to deQueue an item from queue */
int deQueue(struct queue *q)
{
        int x;

        /* If both stacks are empty then error */
        if (q->stack1 == NULL && q->stack2 == NULL)
        {
                printf("Q is empty");
                exit(0);
        }

        /* Move elements from stack1 to stack 2 only if 
       stack2 is empty */
        if (q->stack2 == NULL)
        {
                while (q->stack1 != NULL)
                {
                        x = pop(&q->stack1);
                        push(&q->stack2, x);
                }
        }

        x = pop(&q->stack2);
        return x;
}

/* Function to push an item to stack*/
void push(struct sNode **top_ref, int new_data)
{
        /* allocate node */
        struct sNode *new_node = (struct sNode *)malloc(sizeof(struct sNode));
        if (new_node == NULL)
        {
                printf("Stack overflow \n");
                exit(0);
        }

        /* put in the data */
        new_node->data = new_data;

        /* link the old list off the new node */
        new_node->next = (*top_ref);

        /* move the head to point to the new node */
        (*top_ref) = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode **top_ref)
{
        int res;
        struct sNode *top;

        /*If stack is empty then error */
        if (*top_ref == NULL)
        {
                printf("Stack underflow \n");
                exit(0);
        }
        else
        {
                top = *top_ref;
                res = top->data;
                *top_ref = top->next;
                free(top);
                return res;
        }
}

void view(struct queue *q)
{
        struct sNode *temp;
        int x;
        if (q->stack1 == NULL && q->stack2 == NULL)
        {
                printf("Q is empty");
                exit(0);
        }
        else
        {
                if (q->stack1 == NULL)
                {
                        temp = q->stack2;
                        printf("\n\n\t\t Elements in the Queue:  ");
                        while (temp != NULL)
                        {
                                printf("%d ", temp->data);
                                temp = temp->next;
                        }
                        printf("\n");
                }
                else
                {
                        while (q->stack1 != NULL)
                        {
                                x = pop(&q->stack1);
                                push(&q->stack2, x);
                        }
                        temp = q->stack2;
                        printf("\n\n\t\t Elements in the Queue:  ");
                        while (temp != NULL)
                        {
                                printf("%d ", temp->data);
                                temp = temp->next;
                        }
                        printf("\n");
                        while (q->stack2 != NULL)
                        {
                                x = pop(&q->stack2);
                                push(&q->stack1, x);
                        }
                }
        }
        printf("\t\t-----------**********-------------\n");
}

int main()
{
        /* Create a queue with items 1 2 3*/
        struct queue *q = (struct queue *)malloc(sizeof(struct queue));
        q->stack1 = NULL;
        q->stack2 = NULL;
        int created = 0, ch, n, i, item;
        //Operations list/Menu
        printf("\n\n Menu of Operation\n");
        printf("--------------------------------------------------------\n");
        printf("\t\t 1-> To add data in queue\n");
        printf("\t\t 2-> To delect data from queue\n");
        printf("\t\t 3-> To view the queue\n");
        printf("\t\t 4-> Exit\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("---------------------------------------------------------------------------------\n");

        while (1)
        {
                printf("Enter your choice => ");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                        printf("Enter the Data => ");
                        scanf("%d", &item);
                        enQueue(q, item);
                        printf("----------------------------Insertion of data in queue is done successfully----------------------------\n");
                        break;
                case 2:
                        item = deQueue(q);
                        printf("----------------------------Deletion of %d element in queue is done successfully----------------------------\n", item);
                        break;
                case 3:
                        view(q);
                        break;
                case 4:
                        exit(0);
                        break;
                default:
                        printf("Invalid input\n");
                }
        }

        return 0;
}