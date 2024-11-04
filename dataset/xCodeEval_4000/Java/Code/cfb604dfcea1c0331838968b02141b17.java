

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
 public class b {
	
	
	public static void main(String[] args)  {
	   Scanner s = new Scanner( System.in);
	
	   int t=s.nextInt();
	
	   for(int ie=0;ie<t;ie++) {
	
		   int n=s.nextInt();
		   int[] arr=new int[n];
		   
		   for(int i=0;i<n;i++) {
			   arr[i]=s.nextInt();
		   }
		   
		   if(n==1) {
			   System.out.println(1);
		   }else if(n==2) {
			   if(arr[0]==arr[1]) {
				   System.out.println(2);
			   }else {
				   System.out.println(1);
			   }
		   }else {
	
			   int[][]dp=new int[26][n];
			   dp[arr[0]-1][0]++;
			   for(int i=1;i<n;i++) {
				   for(int j=0;j<26;j++) {
					   if(j==arr[i]-1)
					   dp[arr[i]-1][i]=dp[arr[i]-1][i-1]+1;
					   else
						   dp[j][i]=dp[j][i-1];
				   }
			   }












			   
			   int ans=0;
			   
			   for(int i=0;i<n;i++) {
				   for(int j=i+1;j<n;j++) {
					   
					   int m=0;
					   
					   if(arr[i]==arr[j]) {
					   
						   m=2*Math.min(dp[arr[i]-1][i], dp[arr[i]-1][n-1]-dp[arr[i]-1][j-1]);
					   
					   }
					   int h=0;
					   for(int k=0;k<26;k++) {
						    h=Math.max(h, dp[k][j-1]-dp[k][i]);
					   }
					   m=m+h;
					   if(ans<m) {
						   ans=m;
					   }
				   }
			   }
			   System.out.println(ans);
			   
			   
			   
			   
			   
			   
			   
			   
			   
		   }
	   }
	}
 }