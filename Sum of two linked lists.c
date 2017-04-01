#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
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
            head = last = new;
        }
        else
        {
            last -> next = new;
            last = new;
        }
    }

    return head;
}
int main(){

    struct node *head1, *head2;
    int n1, n2;
    printf("Enter the number of element for link list 1 : ");
    scanf("%d", &n1);
    printf("Enter the elements for link list 1\n");

    head1 = insert(n1);

    printf("Enter the number of element for link list 2 : ");
    scanf("%d", &n2);
    printf("Enter the elements for link list 2\n");

    head2 = insert(n2);

    struct node *t1 = head1 , *t2 = head2 ,*sum;

    if ( n1 > n2 )
    {
        sum = head1;
    }
    else
    {
        sum = head2;
    }

    struct node *ts = sum;

    while ( t1 != NULL && t2 != NULL )
    {
        ts->data = t1->data + t2->data;
        t1 = t1 -> next;
        t2 = t2 -> next;
        ts = ts -> next;
    }

    printf("The Sum of 2 linked list is :-\n");
    for( ts = sum ; ts != NULL ;ts = ts->next )
    {
        printf("%d   ", ts->data );
    }
    return 0;
}
