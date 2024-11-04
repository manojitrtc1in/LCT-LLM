

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
			
			int ans=1;
			
			
			long sum=0;
			while(true) {
				
				if(sum>=n) {
					break;
				}else {
					
					sum=sum+ans;
					
				}
				ans++;
				
			}
			
			
			if(sum==n) {
				System.out.println(ans-1);
			}else if(sum-n==1) {
				System.out.println(ans);
			}else {
				System.out.println(ans-1);
			}
			
			
		}
	}
}