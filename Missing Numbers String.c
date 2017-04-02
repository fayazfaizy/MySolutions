/*
Missing Numbers String You are given a sorted array of distinct integers which ranges from 0-99.
You need to create an output string which denotes all the missing integers.
For example:
Input:  [0, 1, 2, 50, 52, 75]
Output: "3-49,51,53-74,76-99"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * missingString(int *input, int n)
{
    char * output = ( char * ) calloc( 100, sizeof(char) );         // Output String
    int i;
    char temp[3];                                                   // Temporary String to convert Integer into String

    if( input[0] > 0 )                                              // Check the starting value is greater than 0
        {
            itoa( ( 0 ), temp, 10 );                                //Converting Lower Bound ( integer ) to String & Add it to Output String
            strcat( output, temp);

            output[ strlen(output) ] = '-';                         // Add - ( hyphen )into Output String

            itoa( ( input[0] - 1 ), temp, 10 );                     //Converting Upper Bound ( integer ) to String & Add it to Output String
            strcat( output, temp);

            output[ strlen(output) ] = ',';                         // Add , ( Comma ) into Output String

        }


    for( i = 0; i < n-1 ; i++ )
    {
        if( ( input[i+1] - input[i] ) != 1 )                       // Checking the value is continuous or not
        {
            itoa( ( input[i] + 1 ), temp, 10 );
            strcat( output, temp);

            output[ strlen(output) ] = '-';

            itoa( ( input[i+1] - 1 ), temp, 10 );
            strcat( output, temp);

            output[ strlen(output) ] = ',';

        }
    }

    if( input[n-1] < 99 )                                          // Checking the last value is less than 99
        {
            itoa( ( input[n-1] + 1 ), temp, 10 );
            strcat( output, temp);

            output[ strlen(output) ] = '-';

            itoa( ( 99 ), temp, 10 );
            strcat( output, temp);

            output[ strlen(output) ] = ',';

        }

    output[ strlen(output) - 1 ] = '\0';                           // Neglecting the last , ( Comma )

    return output;
}

int main()
{
    int n, i;
    printf("Enter the limit : ");
    scanf("%d", &n);                                              //  Input limit

    printf("Enter the inputs\n");
    int a[n];

    for( i = 0; i < n; i++ )
    {
        scanf("%d", &a[i]);                                      // Input array
    }

    printf("%s", missingString(a, n));                           // Output String
    return 0;
}
