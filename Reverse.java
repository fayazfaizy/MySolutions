import java.util.*;
class Reverse{
    public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        String str = in.nextLine();								// Getting input
        String[] reverse = str.split(" ");						//	Splitting the string
        
		int n=reverse.length;
		
        for(int i = n - 1 ; i >= 0 ; i-- ){
            System.out.print(reverse[i]+ " ");				// Print the splitted string in reverse order
		}
	}                
}                        