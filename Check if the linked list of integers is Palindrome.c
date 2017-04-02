
/*
Check if the linked list of integers is Palindrome
Given a singly linked list of integers, check if the values of the nodes are symmetrical(Palindrome).
For example:

Input: 1 ->23->45->6->45->23->1->null
Output: True

Input: 1 ->23->4->32->1->null
Output: False

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * insert(int n)                                    // Function to insert elements to linked list
{
    int i;
    struct node *head = NULL, *last;

    for( i = 0; i < n ; i++ )
    {
        struct node *new = ( struct node * )malloc( sizeof ( struct node ));            // Allocate new memory for a node ,assigning pointer and insert value
        new -> next = NULL;
        scanf( "%d", &new -> data );
        if( head == NULL )                                                              // If linked list is empty , assign new node as head of linked list
        {
            head = last = new;
        }
        else
        {
            last -> next = new;                                                         // Insert new node to last
            last = new;
        }
    }

    return head;                                                                        // Return created node
}

struct node *findLastPointer (struct node * head, struct node * prevLast )              // Find last pointer before the prevLast node ,initially prevLast will be null
{
    while( head->next != prevLast )
    {
        head = head->next;
    }
    return head;                                                                        // return the last pointer before prevLast node
}

int main(){

    struct node *head;
    int n, i;
    printf("Enter the number of element for link list  : ");
    scanf("%d", &n);                                                                    // Getting the limit of linked list
    printf("Enter the elements for link list \n");

    head = insert(n);                                                                   // newly created linked list assigned to head

    struct node  *front = head ,*last = NULL;

    last = findLastPointer(head, last);                                                 // finding last node

    for( i = 0 ; i < n/2 ; i++ )                                                        // While we reaches the middle node, Check it is palindrome
    {
        if( last->data  != front->data )                                                // Check it violates the Palindrome condition
        {
            printf("False");                                                            // If violates print "False"
            return 0;
        }
        front = front->next;                                                            // Traverse forward
        last = findLastPointer( head, last);                                            // Traverse backward
    }

    printf("True");                                                                    // If it is satisfies condition for the entire linked list print "True"
    return 0;
}
