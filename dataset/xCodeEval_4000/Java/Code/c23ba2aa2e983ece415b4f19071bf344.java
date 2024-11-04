
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b{
	
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int a=s.nextInt();
			int b=s.nextInt();
			int c=s.nextInt();
			
			int ans=0;
			int[] arr=new int[3];
			arr[0]=a;arr[1]=b;arr[2]=c;
			Arrays.sort(arr);
			if(arr[0]>0) {
				ans=ans+1;
				arr[0]=arr[0]-1;
				
			}
			if(arr[1]>0) {
				ans=ans+1;
				arr[1]=arr[1]-1;
				
			}
			if(arr[2]>0) {
				ans=ans+1;
				arr[2]=arr[2]-1;
				
			}
			
			if(arr[0]>0) {
				ans=ans+1;
				arr[0]=arr[0]-1;
			
				arr[2]=arr[2]-1;
			}
			
			if(arr[0]>0) {
				ans=ans+1;
				arr[0]=arr[0]-1;
			
				arr[1]=arr[1]-1;
			}
			
			if(arr[1]>0&&arr[2]>0) {
				ans=ans+1;
				arr[1]=arr[1]-1;
			
				arr[2]=arr[2]-1;
			}
			if(arr[0]>0) {
				ans=ans+1;
				
			}
			
			System.out.println(ans);
			
			
			
			
			
		}
		
		
		
	}
}