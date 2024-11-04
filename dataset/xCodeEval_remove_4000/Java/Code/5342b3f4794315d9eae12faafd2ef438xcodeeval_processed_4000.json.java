

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class k{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
StringBuilder sb=new StringBuilder();
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {

			int n=s.nextInt();
			pair[] arr=new pair[n];
			for(int i=0;i<n;i++) {
				int a=s.nextInt();
				int b=s.nextInt();
				if(b>a) {
					int tt=b;
					b=a;
					a=tt;
				}
				arr[i]=new pair(a,b,i);
				
			}
			
			Arrays.sort(arr,new comp());
			
			pair[] dp=new pair[n];
			
			int[] ans=new int[n];
			Arrays.fill(ans, -1);
			dp[0]=new pair(arr[0].w,0,arr[0].in);
			
			for(int i=1;i<n;i++) {
				
				int in=bs(arr,arr[i].h);
				if(in==-1) {
					ans[i]=-1;
				}else{
					if(dp[in].h<arr[i].w) {
						ans[arr[i].in]=dp[in].in+1;
					}
					
					
				}
				
				if(dp[i-1].h<arr[i].w) {
					dp[i]=new pair(dp[i-1].h,dp[i-1].w,dp[i-1].in);
				}else {
					dp[i]=new pair(arr[i].w,i,arr[i].in);
				}
				
			}
			
			
			for(int i=0;i<n;i++) {
				sb.append(ans[i]+" ");
			}
			sb.append("\n");
			
			
			
		}
		System.out.println(sb);
	}
	public static int bs(pair[] arr,int val) {
		int ans=-1;
		int st=0;
		int end=arr.length-1;
		while(st<=end) {
			int mid=(st+end)/2;
			
			if(arr[mid].h<val) {
				ans=mid;
				st=mid+1;
			}else {
				end=mid-1;
			}
			
		}
		
		return ans;
		
	}
}
class pair{
	int h;
	int w;
	int in;
	
	public pair(int a,int b,int in) {
		this.h=a;
		this.w=b;
		this.in=in;
		
	}
}
class comp implements Comparator<pair>{
	public int compare(pair h,pair k) {
		return h.h-k.h;
		
		
	}
}