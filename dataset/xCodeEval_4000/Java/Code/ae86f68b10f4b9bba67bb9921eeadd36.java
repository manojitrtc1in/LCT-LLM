

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	    int n=s.nextInt();
	    double k=s.nextDouble();
	    double m=s.nextDouble();
	    Double[] arr=new Double[n];
	    for(int i=0;i<n;i++) {
	    	arr[i]=s.nextDouble();
	    }
	    
	   
	    Arrays.sort(arr);
	    double pre[]=new double[n];
	    pre[0]=arr[0];
	    for(int i=1;i<n;i++) {
	     
	    	pre[i]=pre[i-1]+arr[i];
	    }
	    
	    
	    
	    
	    
	    double max=Long.MIN_VALUE;
	
	    double ans=0;
	    for(int i=-1;i<n-1;i++) {
	    	

	    	ans=0;
	    	if(m>=i+1) {
	    		
	    		if(i!=-1)
	    		ans=pre[n-1]-pre[i];
	    		else
	    			ans=pre[n-1];
	    		
	    		ans=(ans+(double)Math.min(k*((double)n-(double)i-1d), m-(double)i-1d))/(double)((double)n-(double)i-1d);
	    		max=Math.max(ans, max);
	    		
	    	}else {
	    		break;
	    	}
	    }
	    
	    
	   System.out.println(max);
	    
	   
	}
}