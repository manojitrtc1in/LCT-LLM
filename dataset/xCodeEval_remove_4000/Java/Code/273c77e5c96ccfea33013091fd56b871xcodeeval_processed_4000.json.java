

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class k{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
		
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {

			int n=s.nextInt();
			int[] arr=new int[n];
			int k=s.nextInt();
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			
			int ans=Integer.MAX_VALUE;
			
			
			
			for(int i=1;i<=100;i++) {
			int st=0;
			int h=0;
			while(st<n) {
				if(arr[st]==i) {
					st++;
				}else {
					h++;
					st=st+k;
				}
				
				
			}
			
			ans=Math.min(h, ans);
			}
			System.out.println(ans);
			
			
			
		}
	}
}