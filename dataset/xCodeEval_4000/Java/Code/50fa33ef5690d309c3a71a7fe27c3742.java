

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
			
			int p=s.nextInt();
			int k=s.nextInt();
			char[] arr=s.next().toCharArray();
			
			int x=s.nextInt();
			int y=s.nextInt();
			
			long[] suf=new long[n];
				
			for(int i=n-1;i>=0;i--) {
				if(arr[i]=='0') {
					suf[i]=x;
					if(i+k<n) {
						suf[i]=suf[i]+suf[i+k];
					}
				}else {
					if(i+k<n) {
						suf[i]=suf[i]+suf[i+k];
					}
				}
			}
			
			long ans=Integer.MAX_VALUE;
			for(int i=p-1;i<n;i++) {
				long h=Integer.MAX_VALUE;
				
				h=y*Math.max(0, i+1-p);
				h=h+suf[i];
				ans=Math.min(ans, h);
				
				
			}
			
			System.out.println(ans);
			
			
		}
	}
}