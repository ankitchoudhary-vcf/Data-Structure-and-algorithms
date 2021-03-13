                    // Creating Circular Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

/***
 * Creating Circular Doubly Linked List
 ***/

struct CreatingCircularDoublyLinkedList
{
    struct CreatingCircularDoublyLinkedList *left;
    int data;
    struct CreatingCircularDoublyLinkedList *right;
};
typedef struct CreatingCircularDoublyLinkedList Node;

Node *Start = NULL;

/***
 * Creating a new node
 ***/
Node * getNode()
{
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    return(newnode); 
}

/***
 * Counting number of node in circular linked list
 ***/
int CountNode()
{
    Node *temp;
    temp = Start;
    int count = 0;
    if(temp == NULL)
    {
        return 0;
    }
    else
    {
        do
        {
            count++;
            temp = temp -> right;
        }while (temp != Start);
        return (count);
    }
}

/***
 * Inserting a new node at the beginning of the Circular Linked List
 ***/
void insert_beg()
{
    Node *newnode;
    newnode = getNode();
    printf("Enter the data in Node => " );
    scanf("%d",&newnode->data);
    if(Start == NULL)
    {
        Start = newnode;
        newnode -> left = Start;
        newnode -> right = Start;
    }
    else
    {
        newnode -> right = Start;
        newnode -> left = Start -> left;
        Start -> left ->right = newnode;
        Start -> left = newnode;
        Start = newnode;
    }
    printf("-------------------------------Node inserted at beginning susscessfully-------------------------------\n");
}

/***
 * Inserting a new node at end of the Circular Linked List
 ***/
void insert_end()
{
    Node *newnode;
    newnode = getNode();
    printf("Enter the data in Node => ");
    scanf("%d", &newnode->data);
    if (Start == NULL)
    {
        Start = newnode;
        newnode -> left = Start;
        newnode -> right = Start;
    }
    else
    {
        newnode -> left = Start -> left;
        newnode -> right  = Start;
        Start -> left -> right = newnode;
        Start -> left =  newnode;
    }
    printf("-------------------------------Node inserted at end susscessfully-------------------------------\n");
}

/***
 * Inserting new node at any specfied position in Circular Linked List
 ***/
void insert_mid()
{
    Node *newnode, *temp;
    int nodectr, pos, ctr;
    nodectr = CountNode();
    printf("Enter the position: ");
    scanf("%d", &pos);
    if(pos > 1 && pos < nodectr)
    {
        newnode = getNode();
        printf("Enter the data in Node => ");
        scanf("%d", &newnode->data);
        temp = Start;
        ctr = 1;
        while (ctr<pos)
        {
            temp = temp -> right;
            ctr++;
        }
        newnode->left = temp;
        newnode->right = temp->right;
        temp->right->left = newnode;
        temp->right = newnode;
        printf("-------------------------------Node inserted at %d position susscessfully-------------------------------\n", pos); 
    }
    else if (pos == 1 && pos <= nodectr)
    {
        insert_beg();
        printf("-------------------------------Node inserted at %d position susscessfully-------------------------------\n", pos); 

    }
    else if (pos == nodectr && pos != 1)
    {
        insert_end();
        printf("-------------------------------Node inserted at %d position susscessfully-------------------------------\n", pos); 

    }
    
    else
    {
        printf("\nPosition %d is not a intremediate position, Please Enter the Valide position \n", pos);
        insert_mid();
    }
}

/***
 * Deleting the first node from beginning of Circular Doubly Linked List
 ***/
void delete_beg()
{
    Node *temp;
    int nodectr;
    nodectr = CountNode(); 
    if(Start == NULL)
    {
        printf("\nCircular Doubly Linked list is Empty\n");
    }
    else if (nodectr == 1)
    {
        temp = Start;
        Start = NULL;
        free(temp);
        printf("-------------------------------Node at beginning deleted susscessfully-------------------------------\n");
    }
    else
    {
        temp = Start;
        Start -> right -> left = Start -> left;
        Start -> left -> right = Start -> right;
        Start = Start -> right;
        free(temp);
        printf("-------------------------------Node at beginning deleted susscessfully-------------------------------\n");
    }
    
}

/***
 * Deleting the last node of Circular Doubly Linked List
 ***/
void delete_end()
{
    Node *temp;
    int nodectr;
    nodectr = CountNode(); 
    if(Start == NULL)
    {
        printf("\nCircular Doubly Linked list is Empty\n");
    }
    else if (nodectr == 1)
    {
        temp = Start;
        Start = NULL;
        free(temp);
        printf("-------------------------------Node at last deleted susscessfully-------------------------------\n");
    }
    else
    {
        temp = Start->left;
        Start -> left = Start -> left -> left;
        Start -> left -> right = Start;
        free(temp);
        printf("-------------------------------Node at last deleted susscessfully-------------------------------\n");
    }
    
}


/***
 * Deleting node of Circular Doubly Linked List from intermedate position
 ***/

void delete_mid()
{
    if (Start == NULL)
    {
        printf("\nCircular Doubly Linked list is Empty\n");
    }
    else
    {
        Node *temp;
        int pos, nodectr, ctr;
        nodectr = CountNode();
        printf("Enter the position: ");
        scanf("%d", &pos);
        if (pos > 1 && pos < nodectr)
        {
            temp = Start;
            ctr = 1;
            while (ctr < pos)
            {
                temp = temp->right;
                ctr++;
            }
            temp->left->right = temp->right;
            free(temp);
            printf("-------------------------------Node deleted from %d position susscessfully-------------------------------\n", pos); 
        }
        else if (pos == nodectr && pos != 1)
        {
            delete_end();
            printf("-------------------------------Node deleted from %d position susscessfully-------------------------------\n", pos); 
        }
        else if (pos == 1)
        {
            if (pos == nodectr)
            {
                delete_end();
                printf("-------------------------------Node deleted from %d position susscessfully-------------------------------\n", pos); 
            }
            else
            {
                delete_beg();
                printf("-------------------------------Node deleted from %d position susscessfully-------------------------------\n", pos); 
            }
        }
        else
        {
            printf("\nPosition %d is not a intremediate position, Please Enter the Valide position \n", pos);
            delete_mid();
        }
    }
}



/***
 * Displaying the Circular Doubly Linked List from left to right
 ***/
void Display_left_right()
{
    Node *temp;
    if(Start == NULL)
    {
        printf("\nCircular Doubly Linked list is Empty\n");
    }
    else
    {
        temp = Start;
        printf("\n The contents of List: ");
        do
        {
            printf(" %d ", temp -> data);
            temp = temp -> right;
        }while(temp != Start);
        printf("\n");
    }
    
}


/***
 * Displaying the Circular Doubly Linked List from right to left
 ***/
void Display_right_left()
{
    Node *temp;
    if(Start == NULL)
    {
        printf("\nCircular Doubly Linked list is Empty\n");
    }
    else
    {
        temp = Start;
        printf("\n The contents of List: ");
        do
        {
            temp = temp -> left;
            printf(" %d ", temp -> data);
        }while(temp != Start);
        printf("\n");
    }
    
}


/***
 * Menu to perform the Opeeration on the Circular Linked List
 ***/
void menu()
{
    printf("\n\n Menu of Operation\n");
    printf("--------------------------------------------------------\n");
    printf("\t\t 1. Insert Node at last in Circular Doubly Linked List\n");
    printf("\t\t 2. Insert Node at first in Circular Doubly Linked List\n");
    printf("\t\t 3. Insert Node at any specified position in Circular Doubly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 4. View Circular Doubly Linked List\n");
    printf("\t\t 5. View Circular Doubly Linked List in Revese Order\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 6. Delect Node at first in Circular Doubly Linked List\n");
    printf("\t\t 7. Delect Node at end in Circular Doubly Linked List\n");
    printf("\t\t 8. Delect Node at any specified position in Circular Doubly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 9. To Find the length of Circular Doubly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 10. Exit\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t ----------------------------------------------------\n");
}

/***
 * Main function to make all the program to execute
***/

int main()
{
    char men;
    int count;
    menu();
    while (1)
    {
        // using if-else statements
        printf("Enter the choice\n");
        scanf("%d", &men);
        if (men == 1)
        {
            insert_end();   
        }
        else if (men == 2)
        {
            insert_beg();
        }
        else if (men == 3)
        {
            insert_mid();
        }
        else if (men == 4)
        {
           Display_left_right();
        }
        else if (men == 5)
        {
            Display_right_left();
        }
        else if (men == 6)
        {
            delete_beg();
        }
        else if (men == 7)
        {
            delete_end();
        }
        else if (men == 8)
        {
            delete_mid();
        }
        else if (men == 9)
        {
           count = CountNode();
           printf("The length of Circular Doubly Linked List is %d \n", count);
        }
        else if (men == 10)
        {
            exit(0);
        }
        else
        {
            printf("Enter the valide choice of Operation\n");
        }
    }

    return 0;
}