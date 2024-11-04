

import java.util.Scanner;
import java.util.Stack;

 public class Main{
	 
	
	  public static void main (String[] args) {
		 
		  Scanner s=new Scanner(System.in);
		  long m=1000000007;
		  long[] dp=new long[100001];
		  
		  for(int i=0;i<100001;i++) {
			  dp[i]=pow(10,i,m);
		  }
		  
		  
		  char[] arr=s.next().toCharArray();
		  
		  long ans=0;
		  int n=arr.length;

		  long res=0;
		  for(int i=n-2;i>=0;i--) {
			
			  res=(res%m+(1l*dp[n-2-i]%m*(n-1-i)%m)%m)%m;
			  
			  ans=(ans%m+(res%m*Long.valueOf(arr[i]+"")%m)%m)%m;
		  }
		

		  for(int i=1;i<n;i++) {
			  long g=(1l*i%m*(i+1)%m)%m;
			  g=(g%m*pow(2,m-2,m)%m)%m;
			  ans=(ans%m+(Long.valueOf(arr[i]+"")%m*(dp[n-1-i]%m*g%m)%m)%m)%m;
		  }
		  System.out.println(ans);
				  
		  
		  
		  
		 
	  }
	  public static long pow(long a,long b,long m) {
		  
		  long res=1;
		  while(b>0) {
			  
			  if(b%2!=0) {
				  res=(res%m*a%m)%m;
			  }
			  
			  a=(a%m*a%m)%m;
			  b=b/2;
			  
		  }
		  
		  return res;
		  
	  }
	  
 }