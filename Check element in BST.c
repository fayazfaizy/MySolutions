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

char * find (struct tree * root, int key )                                  // Fuction to find the Key element, If not present return false
{
    if( root == NULL )
        return "False";
    else
    {
        if( root-> data == key )
        return "True";
        else
        if( root-> data <= key )
        return find( root-> right, key);
        else
        return find( root-> left, key);
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

    for( i = 0; i < n ; i++ )
    {
        scanf("%d", &num);
        buildTree( &root, num);
    }

    print( root);
    printf("\n");
    int key;
    printf("Enter the element for search : ");
    scanf("%d", &key);

    printf("%s", find( root, key));
    return 0;
}
