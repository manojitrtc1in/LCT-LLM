

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	    int t=s.nextInt();
	    for(int ie=0;ie<t;ie++) {
	    	int n=s.nextInt();
	    	int k=s.nextInt();
	    	
	    	char[] arr=s.next().toCharArray();
	    	
	    	int[] pre=new int[n];
	    	if(arr[0]=='1') {
	    		pre[0]=1;
	    	}
	    	for(int i=1;i<n;i++) {
	    		if(arr[i]=='1') {
	    			pre[i]=pre[i-1]+1;
	    		}else {
	    			pre[i]=pre[i-1];
	    		}
	    	}
	    	
	    	
	    	int[] dp=new int[n];
	    	
	    	for(int i=1;i<n;i++) {
	    		if(arr[i]=='1') {
	    			if(i>=k) {
	    				int a=dp[i-k]+pre[i]-pre[i-k]-1;
	    				int b=pre[i];
	    				dp[i]=Math.min(a, b);
	    			}else {
	    				int a=pre[i];
	    				int b=pre[i]-1;
	    				dp[i]=Math.min(a, b);
	    			}
	    			
	    			
	    		}else {
	    			if(i>=k) {
	    				int a=dp[i-k]+pre[i]-pre[i-k]+1;
	    				int b=pre[i];
	    				dp[i]=Math.min(a, b);
	    			}else {
	    				int a=pre[i];
	    				int b=pre[i]+1;
	    				dp[i]=Math.min(a, b);
	    			
	    		}
	    	}
	    	
	    	
	    	
	    }
	   int h=dp[n-1];
	    for(int i=0;i<n-1;i++) {
	    	dp[i]=dp[i]+pre[n-1]-pre[i];
	    	h=Math.min(h, dp[i]);
	    }
	    System.out.println(h);
	}
}
}