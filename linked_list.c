/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Implementation of double ended, doubly-linked list
**        Date: 16/10/22
**  ==============================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linked_list.h"

/*  -----------------------------------------------------------------------
**    Function: createLinkedList()
**      Import: none
**      Export: list (LinkedList*)
**   Assertion: Creates a pointer to a linked list, allocates memory, sets 
**                  head and tail fields to null and sets count to zero
*/
LinkedList* createLinkedList()
{
    LinkedList* list = (LinkedList*)malloc( sizeof(LinkedList) );
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list;
}

/*  -----------------------------------------------------------------------
**    Function: insertFirst()

**      Export: none
**   Assertion: Inserts a new node at the start of the list with the given
**                  value
*/
void insertFirst( LinkedList* list, loc inValue )
{
    ListNode* newNode = (ListNode*)malloc( sizeof(ListNode) );
    ListNode* prevHead;

    /* Initialise node fields */
    newNode->value = inValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if( list->head == NULL )
    {
        /* If the list is empty, the new node will be the head and the tail */
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        /* If the list has atleast one node in it already */
        newNode->next = list->head;
        prevHead = newNode->next;
        prevHead->prev = newNode;
            /* Update prev of the previous head node */
        list->head = newNode;
            /* Update the head of the list */
    }

    list->count += 1;
}

/*  -----------------------------------------------------------------------
**    Function: insertLast()
**      Import: list (LinkedList*), inValue (void*)
**      Export: none
**   Assertion: Inserts a new node at the end of the list with the given
**                  value
*/
void insertLast( LinkedList* list, loc inValue )
{
    ListNode* newNode = (ListNode*)malloc( sizeof(ListNode) );
    ListNode* prevTail;

    /* Initialise node fields */
    newNode->value = inValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if( list->head == NULL )
    {
        /* If the list is empty, the new node will be the head and the tail */
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        /* If the list has atleast one node in it already */
        newNode->prev = list->tail;
        prevTail = newNode->prev;
        prevTail->next = newNode;
            /* Update next of the previous head node */
        list->tail = newNode;
            /* Update the tail of the list */
    }

    list->count += 1;
}


loc removeFirst( LinkedList* list )
{
    loc nodeValue;
        /* Value to return */
    ListNode* prevHead;
        /* Temp copy of previous head to free */

    if( list->count == 0 )
    {
        /* List is empty */
        nodeValue.X1 = 0;
        nodeValue.X2 = 0;
        nodeValue.P1 = 0;
        nodeValue.P2 = 0;
    }
    else if( list->count == 1 )
    {
        /* List has one element */
        nodeValue = ( list->head )->value;
        prevHead = list->head;

        list->head = NULL;
        list->tail = NULL;
        free( prevHead );
    }
    else
    {
        /* List has > 1 elements */
        nodeValue = ( list->head )->value;
        prevHead = list->head;

        list->head = ( list->head )->next;
        list->head->prev = NULL;
        free( prevHead );
    }

    list->count -= 1;

    return nodeValue;
}

/*  -----------------------------------------------------------------------
**    Function: removelast()
**      Import: list (LinkedList*)
**      Export: nodeValue (void*)
**   Assertion: Removes the last node from the list and returns it's value
*/
loc removeLast( LinkedList* list )
{
    loc nodeValue;
        /* Value to return */
    ListNode* prevTail;
        /* Temp copy of previous tail to free */

    if( list->count == 0 )
    {
        /* List is empty */
        nodeValue.X1 = 0;
        nodeValue.X2 = 0;
        nodeValue.P1 = 0;
        nodeValue.P2 = 0;
    }
    else if( list->count == 1 )
    {
        /* List has one element */
        nodeValue = ( list->tail )->value;
        prevTail = list->tail;

        list->head = NULL;
        list->tail = NULL;
        free( prevTail );
    }
    else
    {
        /* List has > 1 elements */
        nodeValue = ( list->tail )->value;
        prevTail = list->tail;

        list->tail = ( list->tail )->prev;
        list->tail->next = NULL;
        free( prevTail );
    }

    list->count -= 1;

    return nodeValue;
}


