                    //Singly Linked List

#include <stdio.h>
#include <stdlib.h>

/***
 *  Creating Structer of Node Of Singly Linked List
 ***/
struct Node
{
    int data;
    struct Node *next;
};

/***
 * Creating Head/Stat Point of Singly Linked List
***/
struct Node *Start = NULL;

/***
 * Declaration of Functions
 ***/

struct Node *CreatNode();                       //Create Singly Linked List
void appendNode();                              //Insert at last
void deleteFirstNode();                         //Delete at first
void viewLinkedList();                          //To print Singly Linked List
void menu();                                    //To create Menu
void insert_at_beg();                           // Insert at first
void insert_at_mid();                           // Insert at an intermediate position
void delete_at_end();                           // Delete at last
void delete_at_mid();                           // Delete at an in termediate position
void reverseViewLinkedList(struct Node *Start); //To print a Singly Linked List in reverse order
int countnode(struct Node *ptr);    //To find the length of the Singly Linked List


/***
 * Singly Linked List Creating Function
 ***/

struct Node *CreatNode()
{
    struct Node *n;
    n = malloc(sizeof(struct Node));
    return (n);
};

/***
 * countnode function it count the number of nodes in Singly Linked List
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
            ptr = ptr->next;
        }
        return (count);
    }
}

/***
 * appendNode is a Function to insert a node at last from Singly Linked List 
***/

void appendNode()
{
    struct Node *temp, *t;
    temp = CreatNode();
    printf("Enter the data in Node => ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (Start == NULL)
    {
        Start = temp;
    }
    else
    {
        t = Start;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

/***
 * insert_at_beg is a Function to insert a node at first from Singly Linked List 
***/

void insert_at_beg()
{
    struct Node *newnode;
    newnode = CreatNode();
    printf("Enter the data in Node => ");
    scanf("%d", &newnode->data);
    if (Start == NULL)
    {
        Start = newnode;
    }
    else
    {
        newnode->next = Start;
        Start = newnode;
    }
}

/***
 * insert_at_mid is a Function to insert a node at intermediate position from Singly Linked List 
***/

void insert_at_mid()
{
    struct Node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = CreatNode();
    printf("Enter the position: ");
    scanf("%d", &pos);
    nodectr = countnode(Start);
    if (Start == NULL)
    {
        if(pos == 1)
        {
            appendNode();
        }
        else
        {
            printf("List is Empty\n");
        }
    }
    else if (pos > 1 && pos < nodectr)
    {
        printf("Enter the data in Node => ");
        scanf("%d", &newnode->data);
        temp = prev = Start;
        while (ctr < pos)
        {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
    else if (pos == 1 && pos != nodectr)
    {
        insert_at_beg();
    }
    else if (pos == nodectr)
    {
        appendNode();
    }
    else
    {
        printf("position %d is not a middle position\n", pos);
        insert_at_mid();
    }
}

/***
 * deleteFirstNode is a function to delete a node at first from Singly Linked List
 ***/

void deleteFirstNode()
{
    if (Start == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct Node *temp;
        temp = Start;
        Start = Start->next;
        free(temp);
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
        struct Node *temp, *prev;
        temp = prev = Start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

/***
 * delete_at_mid is a function to delete a node at intermedate from Singly Linked List
 ***/

void delete_at_mid()
{
    if (Start == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct Node *temp, *prev;
        int pos, nodectr, ctr;
        nodectr = countnode(Start);
        printf("Enter the position: ");
        scanf("%d", &pos);
        if (pos > 1 && pos < nodectr)
        {
            temp = prev = Start;
            ctr = 1;
            while (ctr < pos)
            {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            free(temp);
        }
        else if (pos == nodectr && pos != 1)
        {
            delete_at_end();
        }
        else if (pos == 1)
        {
            deleteFirstNode();
        }
        else
        {
            printf("position %d is not a intermediate position\n");
            delete_at_mid();
        }
    }
}

/***
 *  viewLinkedList is a function to print the Singly Linked List
***/

void viewLinkedList()
{
    struct Node *temp;
    if (Start == NULL)
    {
        printf("NO Singly Linked List is there\n");
    }
    else
    {
        temp = Start;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/***
 *  reverseViewLinkedList is a function to print the Singly Linked List in reverse order
***/

void reverseViewLinkedList(struct Node *Start)
{
    if (Start == NULL)
    {
        return;
    }
    else
    {
        reverseViewLinkedList(Start->next);
        printf("%d ", Start->data);
    }
}

/***
 * Menu function to take the users choice to do work in Singly Linked List 
***/

void menu()
{
    printf("\n\n Menu of Operation\n");
    printf("--------------------------------------------------------\n");
    printf("\t\t 1. Insert Node at last in Singly Linked List\n");
    printf("\t\t 2. Insert Node at first in Singly Linked List\n");
    printf("\t\t 3. Insert Node at any specified position in Singly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 4. View Singly Linked List\n");
    printf("\t\t 5. View Singly Linked List in Revese Order\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 6. Delect Node at first in Singly Linked List\n");
    printf("\t\t 7. Delect Node at end in Singly Linked List\n");
    printf("\t\t 8. Delect Node at any specified position in Singly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 9. To Find the length of Singly Linked List\n");
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
            appendNode();
        }
        else if (men == 2)
        {
            insert_at_beg();
        }
        else if (men == 3)
        {
            insert_at_mid();
        }
        else if (men == 4)
        {
            viewLinkedList();
        }
        else if (men == 5)
        {
            reverseViewLinkedList(Start);
            printf("\n");
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
            printf("The length of Singly Linked List is %d ", l);
        }
        else if (men == 10)
        {
            exit(0);
        }
        else
        {
            printf("Enter the valide choice of Operation");
        }

        /**
        * using switch case
        * 
        switch(menu())
        {
            case 1:
                appendNode();
                break;
            case 2:
                insert_at_beg();
                break;
            case 3:
                insert_at_mid();
                break;
            case 4:
                viewLinkedList();
                break;
            case 5:
                deleteFirstNode();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Enter the valide choice of Operation");
        }
        **/
    }

    return 0;
}