/*

Rearrange DLL by splitting it You have a DLL.
You need to pick the elements from the middle to last and swap them in exact same sequence with elements from first to middle.
For example:

Input: 1<->2<->3<->4<->5<->6<->7
Output: 5<->6<->7<->4<->1<->2<->3

Input: 1<->2<->3<->4
Output: 3<->4<->1<->2

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * insert(int n)
{
    int i;
    struct node *head = NULL, *last;

    for( i = 0; i < n ; i++ )
    {
        struct node *new = ( struct node * )malloc( sizeof ( struct node ));
        new -> next = NULL;
        scanf( "%d", &new -> data );
        if( head == NULL )
        {
            new -> prev = NULL;
            head = last = new;
        }
        else
        {
            last -> next = new;
            new -> prev = last;
            last = new;
        }
    }

    return head;
}

void print( struct node * head )
{
    while( head != NULL )
    {
        printf( "%d ",head -> data );
        head = head -> next;
    }
}
int main(){

    struct node *head , *t;
    int n;
    printf("Enter the number of element for link list : ");
    scanf("%d", &n);
    printf("Enter the elements for link list \n");

    head = insert(n);

    struct node *h1, *h2, *l1, *l2 ,*m;
    int i;

    if ( head -> next == NULL )
    {
        print( head );
        return 0;
    }

    for ( i = 0, t = head ; i < n ; i++, t = t->next )
    {
        if( i == 0 )
        {
            h1 = t;
        }
        if( i == (n/2) - 1 )
        {
            l1 = t;
        }
        if( n%2 == 1 && i == n/2 )
        {
            m = t;
        }
        else
        if(  i == n/2   || ( n % 2 == 1 && i == ( n/2 ) + 1 ) )
        {
            h2 = t;
        }
        if( i == n-1 )
        {
            l2 = t;
        }
    }

    if ( n % 2 == 1 )
    {
        l2 -> next = m;
        l2 = m;
    }

    struct node *newHead;

    newHead = h2;
    newHead -> prev = NULL;
    l2 -> next = h1;
    h1 -> prev = l2;
    l1 -> next =NULL;

    print( newHead );
    return 0;
}
