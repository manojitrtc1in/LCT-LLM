

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
			int x=s.nextInt();
			int[] arr=new int[n];
			
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			int[][] dp=new int[n][501];
			int a=fun(arr,x,dp,0,0);
				
			if(a==Integer.MAX_VALUE) {
				System.out.println(-1);
			}else {
				System.out.println(a);
				
			}

		}
		
	}
	
	public static int fun(int[] arr,int x,int[][] dp,int p,int curr) {
		
		if(p==1) {
			return Integer.MAX_VALUE;
		}
		
		if(curr>arr.length-1) {
			
			
			
			return 0;
		}
		
		
		int ans=Integer.MAX_VALUE;
		if(x<arr[curr]) {
			int tt=arr[curr];
			arr[curr]=x;
			x=tt;
			int g=0;
			if(curr!=0 && arr[curr]<arr[curr-1]) {
				g=1;
			}
			int zz=fun(arr,x,dp,g,curr+1);
			if(zz!=Integer.MAX_VALUE) {
				ans=Math.min(ans, 1+zz);
			}
			 tt=arr[curr];
			arr[curr]=x;
			x=tt;
		     g=0;
			if(curr!=0 && arr[curr]<arr[curr-1]) {
				g=1;
			}
			
			ans=Math.min(ans, fun(arr,x,dp,g,curr+1));
		}else {
			int g=0;
				if(curr!=0 && arr[curr]<arr[curr-1]) {
					g=1;
				}
			ans=Math.min(ans, fun(arr,x,dp,g,curr+1));
			
		}
		
		dp[curr][x]=ans;
		return ans;
		
	}
}