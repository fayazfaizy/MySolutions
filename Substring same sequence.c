/*

Problem #8
Substring same sequence
Given a String and substring,
check whether the character in substring are present in the main string in the SAME SEQUENCE.
If yes, return true.
For example:

Input:
String: "Hello"
Substring: "elo"
Output: True

Input:
String: "Memory"
Substring: "my"
Output: False

*/

#include<stdio.h>
#include<string.h>

char * isSubString(char * string, char * subString )
{
    int n1 = strlen( string);
    int n2 = strlen( subString);
    int i, j;

    for( i = 0 ; i <= n1 - n2 ; i++ )
    {
        int count = 0;
        for( j = 0 ; j < n2 ; j++ )
        {
            if( string[ i+j ] != subString [j] )
            {
                break;
            }
            count++;
        }
        if( count == n2)
        {
            return "True";
        }
    }
    return "False" ;
}

int main()
{
    char string[50];
    char subString[20];

    printf("Enter the String : ");
    gets ( string );
    printf("Enter the subString : ");
    gets ( subString );

    printf("%s",isSubString( string, subString));
    return 0;
}
