/*

Chocolate distribution problem Given an array of n integers where each value represents number of chocolates in a packet.
Each packet can have variable number of chocolates.
There are m students, the task is to distribute chocolate packets such that :
-> Each student gets one packet.
-> The difference between the number of chocolates in packet with
maximum chocolates and packet with minimum chocolates given to the students is minimum.
For example:

Input: arr[] = {7, 3, 2, 4, 9, 12, 56}, m = 3
Output: Minimum Difference is 2

*/

#include<stdio.h>
#include<stdlib.h>

int findMin( int *choc,int i, int m )                           // Returns the minimum cost
{
    return ( choc[i + m - 1] - choc[i] ) ;
}
int main()
{

int i, j, n, m;
scanf( " %d ", &n);
int choc[ n ];

for( i = 0 ; i < n ; i++ )
{
    scanf( "%d", &choc[i]);
}

scanf( "%d", &m );
for( i = 0 ; i < n ; i++ )
{
    for(j=i+1;j<n;j++)
    {
        if( choc[i] > choc[j] )
        {
            int t = choc[i];            //sorting
            choc[i] = choc[j];
            choc[j] = t;
        }
    }
}

int min=findMin( choc, 0, m);

for( i = 1 ; i < n - m ; i++ )
{
    int t = findMin( choc, i, m);
    if( min > t )
    {
        min = t;                           //finding min
    }
}

printf("Minimum Difference is %d", min);
return 0;
}
