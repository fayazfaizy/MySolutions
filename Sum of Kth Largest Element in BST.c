/*

Check element in BST Given a binary search tree with positive integers,
 check if given element is present in the given tree.

For example:
Input:              14
                  /     \
                 3       17
                / \     /  \
               2   4   6    18

Input : 17
Output: True

Input : 9
Output: False

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
} ;

void buildTree ( struct tree ** root, int num)                                          // Insert a new element in BST
{
    struct tree * newNode = (struct tree *)malloc( sizeof( struct tree ));              // Create a new Node & Assign values
    newNode  -> data = num;
    newNode ->left = NULL;
    newNode -> right = NULL;

    if( *root == NULL )                                                                 // if tree is empty, return the new node as root node
    {
        *root = newNode;
        return;
    }
    else
    {                                                                                   // Insert element according to BSY rule
        if( ( *root) -> left == NULL && num < ( *root) -> data )
        {
            ( *root) -> left = newNode;
        }
        else
        if( ( *root) -> right == NULL && num >= ( *root) -> data )
        {
            ( *root) -> right = newNode;
        }
        else
        if( num < ( *root) ->data )
        {
            buildTree( &( *root) ->left, num);
        }
        else
        if( num >= ( *root) -> data )
        {
            buildTree( &( *root) -> right, num);
        }
    }
}

/*
Function to find sum of kth largest element

*/
void findLargest ( struct tree * root , int * k ,int * sum )
{
    if( root != NULL  )
    {
        findLargest( root->right, k, sum);

        if( *k <= 0 )           // If it exceeds the kth element return back to main function
            return;

        *k = *k - 1;
        * sum = *sum + root-> data;
        findLargest( root->left, k, sum);
    }
}

int main()
{
    struct tree *root = NULL;
    int n;
    printf("Enter the number of element for tree : ");
    scanf("%d", &n);
    printf("Enter the elements of the tree \n");

    int i, num;

    for( i = 0; i < n ; i++ )               // Insert elements to tree one by one
    {
        scanf("%d", &num);
        buildTree( &root, num);
    }

    int k,sum;
    printf("Enter the K value : ");
    scanf("%d", &k);

    sum = 0;
    findLargest(root, &k, &sum);           // Find largest sum
    printf("%d", sum);                     // Print sum
    return 0;
}
