#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct {
    int X1;
    int X2;
    int P1;
    int P2;
} loc;
/* Linked List Node */
typedef struct ListNode
{
    loc value;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

/* Linked List */
typedef struct
{
    ListNode* head;
    ListNode* tail;
    int count;
} LinkedList;

/* Function pointer for use in printLinkedList() */
typedef char* (*toStringFunc)( void* );

/* Function pointer for use in freeLinkedList() */
typedef void (*freeFunc)( void* );

/* Function forward declarations */
LinkedList* createLinkedList();

void insertFirst( LinkedList*, loc );
void insertLast( LinkedList*, loc );

loc removeFirst( LinkedList* );
loc removeLast( LinkedList* );

void printLinkedList( LinkedList*, toStringFunc* );
void freeLinkedList( LinkedList*, freeFunc* );

#endif