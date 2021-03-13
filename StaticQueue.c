//Queue in Static

#include <stdio.h>
#include <stdlib.h>

//Creating structer of Queue
struct queue
{
        int capacity, front, rear;
        int *arr;
};

//Declaration of functions
struct queue *CreateQueue();
void AddQ(struct queue *);
void DelQ(struct queue *);
void view(struct queue *);

// Creating Queue
struct queue *CreateQueue()
{
        struct queue *q;
        q = (struct queue *)malloc(sizeof(struct queue));
        printf("Enter the capacity of queue => ");
        scanf("%d", &q->capacity);
        q->front = -1;
        q->rear = -1;
        q->arr = (int *)malloc(sizeof(int) * q->capacity);
        return q;
}

//Adding data into queue
void AddQ(struct queue *q)
{
        if (q->rear == q->capacity - 1)
        {
                printf("Queue is full\n");
                return;
        }
        else
        {
                q->rear++;
                printf("Enter the data => ");
                scanf("%d", &q->arr[q->rear]);
                if (q->front == -1)
                {
                        q->front = 0;
                }
        }
        printf("----------------------------Insertion of data in queue is done successfully----------------------------\n");
}

//Delecting data from queue
void DelQ(struct queue *q)
{
        int item, i;
        if (q->front == q->rear)
        {
                printf("Queue is Empty\n");
        }
        else
        {
                item = q->arr[q->front];
                /***
                 * For Normal Queue
                 * q->arr[q->front] = 0;
                 * q->front++;
                 ***/

                /***
                 * For Circular Queue
                 ***/
                if (q->rear == 0)
                {
                        q->front, q->rear = -1;
                }
                else
                {

                        for (i = 0; i < q->rear; i++)
                        {
                                q->arr[i] = q->arr[i + 1];
                        }
                        q->rear--;
                }
        }
        printf("----------------------------Deletion of %d element in queue is done successfully----------------------------\n", item);
}

//Displaying the content of queue
void view(struct queue *q)
{
        int i;
        if (q->front == q->rear)
        {
                printf("Queue is Empty\n");
        }
        else
        {
                printf("The content of queue is:- \n\t");
                for (i = q->front; i <= q->rear; i++)
                {
                        printf("%d ", q->arr[i]);
                }
                printf("\n");
        }
}

//main function of the program
int main()
{
        int created = 0, ch, n, i;
        struct queue *q;

        //Operations list/Menu
        printf("\n\n Menu of Operation\n");
        printf("--------------------------------------------------------\n");
        printf("\t\t 1-> Creating Queue\n");
        printf("\t\t 2-> To add data in queue\n");
        printf("\t\t 3-> To delect data from queue\n");
        printf("\t\t 4-> To view the queue\n");
        printf("\t\t 5-> Exit\n");
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
                                q = CreateQueue();
                                created++;
                                printf("Enter the number of data you want to enter in queue => ");
                                scanf("%d", &n);
                                for (i = 0; i < n; i++)
                                {
                                        AddQ(q);
                                }
                                printf("\n***********************************--Queue has been Created susscessfully--***********************************\n");
                        }
                        else
                        {
                                printf("Queue has already been created \n");
                        }
                        break;
                case 2:
                        if (created == 0)
                        {
                                q = CreateQueue();
                                created++;
                                AddQ(q);
                        }
                        else
                        {
                                AddQ(q);
                        }
                        break;
                case 3:
                        DelQ(q);
                        break;
                case 4:
                        view(q);
                        break;
                case 5:
                        exit(0);
                        break;
                default:
                        printf("Invalid input\n");
                }
        }

        return 0;
}