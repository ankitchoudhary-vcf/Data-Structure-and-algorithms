// Doubly Linked List

/***
 * - Doubly Linked List contains one extra pointer as compare to the node of single linked list.
 *
 ***/
#include <stdio.h>
#include <stdlib.h>

/***
 *  Creating Structer of Node Of Doubly Linked List
 ***/

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

/***
 * Creating Head/Stat Point of Doubly Linked List
***/

struct Node *Start = NULL;

/***
 * Declaration of Functions
 ***/

struct Node *getNode();          //To Create a new node.
void insert_beg();               //To insert a node at first.
void insert_end();               //To insert a node at last.
void insert_mid();               //To insert a node at a specified position.
void deleteFirstNode();          //To delete first node.
int CountNode(struct Node *ptr); //To find the length of Node.
void menu();                     //A menu card to use the Doubly linked list

/***
 * Doubly Linked List Creating Function
 ***/

struct Node *getNode()
{
    struct Node *newnode;
    newnode = malloc(sizeof(struct Node));
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

/***
 * countnode function it count the number of nodes in Doubly Linked List
***/

int countnode(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return (0);
    }
    else
    {
        int count = 0;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->right;
        }
        return (count);
    }
}

/***
 * insert_at_beg is a Function to insert a node at first in Doubly Linked List 
***/
void insert_beg()
{
    struct Node *newnode;
    newnode = getNode();
    printf("\nEnter the data => ");
    scanf("%d", &newnode->data);
    if (Start == NULL)
    {
        Start = newnode;
    }
    else
    {
        newnode->right = Start;
        Start->left = newnode;
        Start = newnode;
    }
}

/***
 * insert_at_end is a Function to insert a node at last in Doubly Linked List 
***/
void insert_end()
{
    struct Node *newnode, *temp;
    newnode = getNode();
    printf("\nEnter the data => ");
    scanf("%d", &newnode->data);
    if (Start == NULL)
    {
        Start = newnode;
    }
    else
    {
        temp = Start;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = newnode;
        newnode->left = temp;
    }
}

/***
 * insert_at_mid is a Function to insert a node at a specified position in Doubly Linked List 
***/
void insert_mid()
{
    struct Node *newnode, *temp;
    int pos, nodectr, ctr = 1;
    newnode = getNode();
    nodectr = countnode(Start);
    printf("\nEnter the specified position => ");
    scanf("%d", &pos);
    if (Start == NULL)
    {
        if (pos == 1)
        {
            insert_end();
        }
        else
        {
            printf("\nLinked List is Empty");
        }
    }
    else if (pos > 1 && pos < nodectr)
    {
        printf("\nEnter the data => ");
        scanf("%d", &newnode->data);
        temp = Start;
        while (ctr < pos)
        {
            temp = temp->right;
            ctr++;
        }
        newnode->left = temp;
        newnode->right = temp->right;
        temp->right->left = newnode;
        temp->right = newnode;
    }
    else if (pos == 1 && pos != nodectr)
    {
        insert_beg();
    }
    else if ((pos == 1 && pos == nodectr) || pos == nodectr)
    {
        insert_end();
    }
    else
    {
        printf("\nPosition %d is not a intremediate position, Please Enter the Valide position ", pos);
        insert_mid();
    }
}

/***
 * deleteFirstNode is a function to delete a node at first from Doubly Linked List
 ***/
void deleteFirstNode()
{
    struct Node *temp;
    int nodectr;
    nodectr = countnode(Start);
    if (Start == NULL)
    {
        printf("\nDoubly Linked List is Empty\n");
    }
    else
    {
        if (nodectr == 1)
        {
            struct Node *temp;
            temp = Start;
            free(temp);
            Start = NULL;
        }
        else
        {
            temp = Start;
            Start->right->left = NULL;
            Start = Start->right;
            free(temp);
        }
    }
}

/***
 * delete_at_end is a function to delete a node at end from Singly Linked List
 ***/

void delete_at_end()
{
    int nodectr;
    nodectr = countnode(Start);
    if (Start == NULL)
    {
        printf("Empty List\n");
    }
    else if (nodectr == 1)
    {
        deleteFirstNode();
    }
    else
    {
        struct Node *temp;
        temp = Start;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->left->right = NULL;
        free(temp);
    }
}

/***
 * delete_at_mid is a function to delete a node at intermedate from Doubly Linked List
 ***/

void delete_at_mid()
{
    if (Start == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct Node *temp;
        int pos, nodectr, ctr;
        nodectr = countnode(Start);
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
        }
        else if (pos == nodectr && pos != 1)
        {
            delete_at_end();
        }
        else if (pos == 1)
        {
            if (pos == nodectr)
            {
                delete_at_end();
            }
            else
            {
                deleteFirstNode();
            }
        }
        else
        {
            printf("position %d is not a intermediate position\n");
            delete_at_mid();
        }
    }
}

/***
 *  viewLinkedList is a function to print the Doubly Linked List from left to right
***/

void viewLinkedList()
{
    struct Node *temp;
    if (Start == NULL)
    {
        printf("NO Doubly Linked List is there\n");
    }
    else
    {
        temp = Start;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->right;
        }
        printf("\n");
    }
}

/***
 *  viewLinkedList is a function to print the Doubly Linked List from right to left
***/

void viewreversLinkedList()
{
    struct Node *temp;
    if (Start == NULL)
    {
        printf("NO Doubly Linked List is there\n");
    }
    else
    {
        temp = Start;
        while (temp -> right != NULL)
        {
            temp = temp->right;
        }
        while (temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> left;
        }
        
        printf("\n");
    }
}

/***
 * Menu function to take the users choice to do work in Doubly Linked List 
***/

void menu()
{
    printf("\n\n Menu of Operation\n");
    printf("--------------------------------------------------------\n");
    printf("\t\t 1. Insert Node at last in Doubly Linked List\n");
    printf("\t\t 2. Insert Node at first in Doubly Linked List\n");
    printf("\t\t 3. Insert Node at any specified position in Doubly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 4. View Doubly Linked List\n");
    printf("\t\t 5. View Doubly Linked List in Revese Order\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 6. Delect Node at first in Doubly Linked List\n");
    printf("\t\t 7. Delect Node at end in Doubly Linked List\n");
    printf("\t\t 8. Delect Node at any specified position in Doubly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 9. To Find the length of Doubly Linked List\n");
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
            viewLinkedList();
        }
        else if (men == 5)
        {
            viewreversLinkedList();
        }
        else if (men == 6)
        {
            deleteFirstNode();
        }
        else if (men == 7)
        {
            delete_at_end();
        }
        else if (men == 8)
        {
            delete_at_mid();
        }
        else if (men == 9)
        {
            int l = countnode(Start);
            printf("The length of Doubly Linked List is %d ", l);
        }
        else if (men == 10)
        {
            exit(0);
        }
        else
        {
            printf("Enter the valide choice of Operation");
        }
    }

    return 0;
}