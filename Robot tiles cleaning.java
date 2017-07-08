/*
  Program for finding the tiles that can be cleaned by a robot in java

*/import java.util.*;

class GFG {
    static int count = 0;
	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int arr[][] = new int[n][n];
		boolean visited[][] = new boolean[n][n];
		int x = 0, y = 0;
		for( int i = 0; i < n; i++ )
		{
		    for( int j = 0; j < n; j++ )
		    {
		        arr[i][j] = in.nextInt();
		        if( arr[i][j] == 1 )
		        {
		            x = i;
		            y = j;
		        }
		    }
		}
        
        robot( arr, visited, x, y, n) ;
        System.out.println(count);
	}
	static void robot( int arr[][], boolean visited[][], int i, int j, int n )
	{
	    visited[i][j] = true;
	    
	    if( arr[i][j] == 2 )
	        count++;
	    
	    if( i != 0 && visited[i-1][j] == false && arr[i-1][j] != 3 )
	        robot( arr, visited, i-1, j, n);
	   
	    if( i != n-1 && visited[i+1][j] == false && arr[i+1][j] != 3 )
	        robot( arr, visited, i+1, j, n);
	   
	    if( j != 0 && visited[i][j-1] == false && arr[i][j-1] != 3 )
	        robot( arr, visited, i, j-1, n);
	        
	    if( j != n-1 && visited[i][j+1] == false && arr[i][j+1] != 3 )
	        robot( arr, visited, i, j+1, n);     
	}
}
