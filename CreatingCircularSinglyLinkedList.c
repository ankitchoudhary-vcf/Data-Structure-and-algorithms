            // Circular Linked List

#include <stdio.h>
#include <stdlib.h>

/***
 *  Creating Structer of Node Of Circular Singly Linked List
 ***/
struct Node
{
    int data;
    struct Node *next;
};

/***
 * Creating Head/Stat Point of Circular Singly Linked List
***/
struct Node *Start = NULL;

/***
 * Declaration of Functions
 ***/

struct Node *CreatNode();                       //Create Circular Singly Linked List
void appendNode();                              //Insert at last
void deleteFirstNode();                         //Delete at first
void viewLinkedList();                          //To print Circular Singly Linked List
void menu();                                    //To create Menu
void insert_at_beg();                           // Insert at first
void insert_at_mid();                           // Insert at an intermediate position
void insert_after_data();                           // Insert after the particular data
void delete_at_end();                           // Delete at last
void delete_at_mid();                           // Delete at an in termediate position
int countnode(struct Node *ptr);                //To find the length of the Circular Singly Linked List
void CreatingCircularSinglyLinkedList();

/***
 * Circular Singly Linked List Creating Function
 ***/

struct Node *CreatNode()
{
    struct Node *n;
    n = malloc(sizeof(struct Node));
    n->next = NULL;
    return (n);
};

/***
 * countnode function it count the number of nodes in Circular Singly Linked List
***/

int countnode(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return (0);
    }
    else
    {
        int count = 1;
        while (ptr->next != Start)
        {
            count++;
            ptr = ptr->next;
        }
        return (count);
    }
}

/***
 * appendNode is a Function to insert a node at last from Circular Singly Linked List 
***/

void appendNode()
{
    struct Node *newnode, *t;
    newnode = CreatNode();
    printf("Enter the data in Node => ");
    scanf("%d", &newnode->data);
    if (Start == NULL)
    {
        Start = newnode;
        newnode ->next = Start;
    }
    else
    {
        t = Start;
        while(t -> next != Start)
        {
            t = t -> next;
        }
        t -> next = newnode;
        newnode -> next = Start;
    }
    printf("-------------------------------Node inserted at end susscessfully-------------------------------\n");

}

/***
 * insert_at_beg is a Function to insert a node at first from Circular Singly Linked List 
***/

void insert_at_beg()
{
    struct Node *newnode, *last;
    newnode = CreatNode();
    printf("Enter the data in Node => ");
    scanf("%d", &newnode->data);
    if (Start == NULL)
    {
        Start = newnode;
        newnode -> next = Start;
    }
    else
    {
        last = Start;
        while(last -> next != Start)
        {
            last = last -> next;
        }
        newnode -> next = Start;
        Start = newnode;
        last -> next = Start;
    }
    printf("-------------------------------Node inserted at beginning susscessfully-------------------------------\n");

}

/***
 * insert_at_mid is a Function to insert a node at intermediate position from Circular Singly Linked List 
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
        printf("List is Empty\n");
        if(pos == 1)
        {
            appendNode();
            printf("-------------------------------Node inserted at %d position susscessfully-------------------------------\n", pos); 
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
        printf("-------------------------------Node inserted at %d position susscessfully-------------------------------\n", pos); 

    }
    else if (pos == 1 && pos != nodectr)
    {
        insert_at_beg();
        printf("-------------------------------Node inserted at %d position susscessfully-------------------------------\n", pos); 

    }
    else if (pos == nodectr)
    {
        appendNode();
        printf("-------------------------------Node inserted at %d position susscessfully-------------------------------\n", pos); 

    }
    else
    {
        printf("position %d is not a middle position\n", pos);
        insert_at_mid();
    }
}


/***
 * insert_after_data is a Function to insert a node after a particular data from Circular Singly Linked List 
***/

void insert_after_data()
{
    struct Node *newnode, *temp, *Last;
    int item,found = 0;
    newnode = CreatNode();
    printf("Enter the data after which you want to insert: ");
    scanf("%d", &item);
    if (Start == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp = Start;
        Last = Start;
        while(Last -> next != Start)
        {
            Last = Last -> next;
        }

        do
        {
            if (temp->data == item && temp->next == Last)
            {
                found++;
                appendNode();
                break;
            }
            else if (temp->data == item && temp->next != Last)
            {
                found++;
                printf("Enter the data in Node => ");
                scanf("%d", &newnode->data);
                newnode -> next = temp -> next;
                temp -> next = newnode;
            }
            temp = temp->next;
            
        }while (temp != Start);

        if (found == 0)
        {
            printf("data %d is not a found in Circular Singly Linked List\n", item);
            insert_after_data();
        }
        else
        {
            printf("-------------------------Insertion after data %d is susscessfully done in Circular Singly Linked List-------------------------\n", item);
        }
        
        
    }
}


/***
 * deleteFirstNode is a function to delete a node at first from Circular Singly Linked List
 ***/

void deleteFirstNode()
{
    int nodectr;
    nodectr = countnode(Start);
    if (Start == NULL)
    {
        printf("List is Empty\n");
    }
    else if (nodectr == 1)
    {
        struct Node *temp;
        temp = Start;
        Start = NULL;
        free(temp);
        printf("-------------------------------Node at beginning deleted susscessfully-------------------------------\n");
    }
    else
    {
        struct Node *temp, *last;
        int nodectr;
        last = Start->next;
        while(last -> next != Start)
        {
            last = last->next;
        }
        temp = Start;
        Start = Start->next;
        last->next = Start;
        free(temp);
        printf("-------------------------------Node at beginning deleted susscessfully-------------------------------\n");
    }
}

/***
 * delete_at_end is a function to delete a node at end from Circular Singly Linked List
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
        struct Node *temp;
        temp = Start;
        Start = NULL;
        free(temp);
        printf("-------------------------------Node at last deleted susscessfully-------------------------------\n");
    }
    else
    {
        struct Node *temp, *prev;
        temp = prev = Start;
        while (temp->next != Start)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = Start;
        free(temp);
        printf("-------------------------------Node at last deleted susscessfully-------------------------------\n");
    }
}

/***
 * delete_at_mid is a function to delete a node at intermedate from Circular Singly Linked List
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
            printf("-------------------------------Node deleted from %d position susscessfully-------------------------------\n", pos);
        }
        else if (pos == nodectr && pos != 1)
        {
            delete_at_end();
            printf("-------------------------------Node deleted from %d position susscessfully-------------------------------\n", pos);
        }
        else if (pos == 1)
        {
            deleteFirstNode();
            printf("-------------------------------Node deleted from %d position susscessfully-------------------------------\n", pos);
        }
        else
        {
            printf("position %d is not a intermediate position\n");
            delete_at_mid();
        }
    }
}


/***
 * Creating a Circular Singly Linked List having n number of data.
 ***/

void CreatingCircularSinglyLinkedList()
{
    int n;
    printf("\nEnter the number of data you want to add into Circular Linked List => ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        appendNode();
    }
    printf("--------------------Circular Linked List is Created Susscessfully--------------------");
}

/***
 *  viewLinkedList is a function to print the Circular Singly Linked List
***/

void viewLinkedList()
{
    struct Node *temp;
    if (Start == NULL)
    {
        printf("NO Circular Singly Linked List is there\n");
    }
    else
    {
        temp = Start;
        printf("\n The contents of List: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }while (temp != Start);
        printf("\n");
    }
}


/***
 * Menu function to take the users choice to do work in Circular Singly Linked List 
***/

void menu()
{
    printf("\n\n Menu of Operation\n");
    printf("--------------------------------------------------------\n");
    printf("\t\t 1. Creating Circular Singly Linked List of having n number of data\n");
    printf("--------------------------------------------------------\n");
    printf("\t\t 2. Insert Node at last in Circular Singly Linked List\n");
    printf("\t\t 3. Insert Node at first in Circular Singly Linked List\n");
    printf("\t\t 4. Insert Node at any specified position in Circular Singly Linked List\n");
    printf("\t\t 5. Insert Node after any specified data in Circular Singly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 6. View Circular Singly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 7. Delect Node at first in Circular Singly Linked List\n");
    printf("\t\t 8. Delect Node at end in Circular Singly Linked List\n");
    printf("\t\t 9. Delect Node at any specified position in Circular Singly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 10. To Find the length of Circular Singly Linked List\n");
    printf("\t\t ----------------------------------------------------\n");
    printf("\t\t 11. Exit\n");
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
            if (Start == NULL)
            {
                CreatingCircularSinglyLinkedList();
            }
            else
            {
                printf("-------Circular Linked List Has been already created-------\n");
            }
        }
        else if (men == 2)
        {
            appendNode();
        }
        else if (men == 3)
        {
            insert_at_beg();
        }
        else if (men == 4)
        {
            insert_at_mid();
        }
        else if (men == 5)
        {
            insert_after_data();
        }
        else if (men == 6)
        {
            viewLinkedList();
        }
        else if (men == 7)
        {
            deleteFirstNode();
        }
        else if (men == 8)
        {
            delete_at_end();
        }
        else if (men == 9)
        {
            delete_at_mid();
        }
        else if (men == 10)
        {
            int l = countnode(Start);
            printf("The length of Circular Singly Linked List is %d\n ", l);
        }
        else if (men == 11)
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