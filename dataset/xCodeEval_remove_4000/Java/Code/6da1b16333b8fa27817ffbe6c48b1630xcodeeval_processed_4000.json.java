

import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
 
		int n=s.nextInt();
		long[] arr=new long[n];
		long[] brr=new long[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextLong();
		}
		for(int i=0;i<n;i++) {
			brr[i]=s.nextLong();
		}
		
		long[][] dp=new long[2][n];
		dp[0][0]=brr[0];
		dp[1][0]=arr[0];
		
		for(int i=1;i<n;i++) {
		
			dp[0][i]=Math.max(brr[i]+dp[1][i-1],dp[0][i-1]);
			dp[1][i]=Math.max(arr[i]+dp[0][i-1],dp[1][i-1]);
			
		}
		
		System.out.println(Math.max(dp[0][n-1], dp[1][n-1]));
		
		
	
	}
}