

import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class b {
	
	public static void main(String[] args) {

		Scanner s=new Scanner(System.in);
long[] dp=new long[1000000];
dp[0]=2;
for(int i=1;i<dp.length;i++) {
	dp[i]=dp[i-1]+2*(i+1)+i;
}

StringBuilder sb=new StringBuilder();
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			long n=s.nextLong();
			int in=-1;
			for(int i=0;i<dp.length;i++) {
				if(dp[i]>n) {
					break;
					
				}else {
					in=i;
				}
			}
			int ans=0;
			for(int i=in;i>=0;i--) {
				if(n>0) {
					if(dp[i]<=n) {
						
						ans=ans+(int)(n/dp[i]);
						n=n-((n/dp[i])*dp[i]);
					}
				}else {
					break;
				}
			}
			
			sb.append(ans);
			sb.append("\n");
		}
		System.out.println(sb);
	}
}