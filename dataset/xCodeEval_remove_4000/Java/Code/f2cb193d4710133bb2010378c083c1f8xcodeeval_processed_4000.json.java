

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	   
	    
	    	int n=s.nextInt();
	    	long x=s.nextLong();
	    	long[] arr=new long[2*n];
	    	for(int i=0;i<n;i++) {
	    		arr[i]=s.nextLong();
	    	}






	    	for(int i=n;i<2*n;i++) {
	    		arr[i]=arr[i-n];
	    	}
	    	
	    	
	    	long[] pre1=new long[2*n];
	    	long[] pre2=new long[2*n];
	    	pre1[1]=(arr[0]*(arr[0]+1))/2;
	    	for(int i=1;i<2*n;i++) {
	    		long val=(arr[i]*(arr[i]+1))/2;
	    		pre1[i]=pre1[i-1]+val;
	    	}
	    	pre2[0]=arr[0];
	    	for(int i=1;i<2*n;i++) {
	    		
	    		pre2[i]=pre2[i-1]+arr[i];
	    	}
	    	
	    	
	    	long gmax=Integer.MIN_VALUE;
	    	for(int i=0;i<2*n;i++) {
	    		int in=bs(arr,i,pre2,x);
	    		

	    		if(in!=-1) {
	    		long extra=-pre2[in]+pre2[i]-x;
	    		

	    		long val=(extra*(extra+1))/2;
	    		gmax=Math.max(gmax,pre1[i]-pre1[in]-val );
	    		}
	    	}
	    	System.out.println(gmax);
	    	
	    	}
	    	
	    	
	    	
	    	
	    
	
	public static int bs(long[] arr,int index,long[] pre2,long x) {
		int in=-1;
		int st=0;
		int end=index;
		
		while(st<=end) {
			int mid=(st+end)/2;
			
			if(pre2[index]-pre2[mid]>=x) {
				in=mid;
				st=mid+1;
			}else {
				end=mid-1;
			}
			
		}
		
		return in;
		
	}
}