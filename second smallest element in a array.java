/* 
  Input 1:-
  
  input :-
  5
  1 2 3 4 5
  Output :-
  2
  
  Input 2:-
  
  input1 :- 
  6
  3 2 5 4 9 1
  output :-
  2
  
  Input3 :-
  
  input:-
  2
  1 2
  output :-
  2
  
  Input 4 :-
  input :-
  1
  1
  output :-
  Invalid Input
*/
import java.util.*;

class GFG {
	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
    if( n <= 1 )
    {
      System.out.println("Invalid Input");
      return;
    }
		int arr[] = new int[n];
		for( int i = 0; i < n; i++ )
		    arr[i] = in.nextInt();
        
        int minf, mins;
        if( arr[0] > arr[1] )
        {
            minf = arr[1];
            mins = arr[0];
        }
        else
        {
            minf = arr[0];
            mins = arr[1];
        }
        
        for( int i = 2; i < n; i++ )
        {
            if( arr[i] < minf )
            {
                mins = minf;
                minf = arr[i];
            }
            else
            if( arr[i] < mins )
            {
                mins = arr[i];
            }
        }
        System.out.println( mins);
	}
}
