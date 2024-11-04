

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
    public static void main(String[] args) {
 
    	Scanner s=new Scanner(System.in);
 
    	int t=s.nextInt();
    	for(int ie=0;ie<t;ie++) {
    		long n=s.nextInt();
    		long k=s.nextInt();
    		long a=s.nextInt();
    		long b=s.nextInt();
    		long c=s.nextInt();
    		long d=s.nextInt();
    		long l1=0;
    		long l2=0;
    		long r1=0;
    		long r2=0;
    		if(a<=c) {
    			l1=a;
    			r1=b;
    			l2=c;
    			r2=d;
    		}else {
    			l1=c;
    			r1=d;
    			l2=a;
    			r2=b;
    		}
    			
    		long ans=0;
    		long inter=0;
    		
    		inter=Math.max(0,r1-l2)-Math.max(0, r1-r2);
    		long max=Math.max(r2, r1)-Math.min(l1, l2);
    		
    		if(k<=inter*n) {
    			System.out.println(0);
    		}else {
    		
    		long how=bs(k-n*inter,max-inter,n);
    		

    		ans=how*(l2-l1+Math.max(r2, r1)-Math.min(r1, r2));
    		
    		if(how==n) {
    			long diff=k-how*max;
    		ans=ans+2*diff;	
    		System.out.println(ans);
    		}else {
    		if((n-how)*inter+how*max==k) {
    			System.out.println(ans);
    		}else {
    			long diff=k-(how*max+(n-how)*inter);
    			long ans1=0;
    			
    			ans1=ans1+Math.max(0, l2-r1);
    			ans1=ans1+diff;
    			long ans2=Integer.MAX_VALUE;
    			if(how>=1)
    			ans2=2*diff;
    	        
    			ans=Math.min(ans2, ans1)+ans;
    		System.out.println(ans);	
    		}
    		
    		}
    		
    		
    	}
    	}
    }
    public static long bs(long k,long val,long n) {
    	long st=0;
    	long end=n;
    	long ans=0;
    	while(st<=end) {
    		long mid=(st+end)/2;
    		
    		if(mid*val<=k) {
    			ans=mid;
    			st=mid+1;
    		}else {
    			end=mid-1;
    		}
    	}
    	
    	return ans;
    }
}