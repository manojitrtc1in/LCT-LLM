

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	      Scanner s=new Scanner(System.in);
	      
	      int n=s.nextInt();
	      int k=s.nextInt();
	      int[] arr=new int[n];
	      for(int i=0;i<n;i++) {
	    	  arr[i]=s.nextInt();
	      }

	      int[] ans=new int[n];
	      int[] t=new int[101];
	      
	      for(int i=0;i<n;i++) {
	    	  int sum=k-arr[i];
	    	 
	    	  int count=0;
	    	  for(int j=1;j<101;j++) {
	    		  if(sum>0) {
	    			if(t[j]!=0) {
	    				int g=sum/j;
	    				if(t[j]>g) {
	    					sum=sum-g*j;
	    					count=count+g;
	    					
	    					
	    				}else {
	    					sum=sum-j*t[j];
	    					count=count+t[j];
	    					
	    					
	    				}
	    				
	    				
	    			}
	    		  }else {
	    			  break;
	    		  }
	    	  }
	    	  
	    	  
    			  ans[i]=i-count;
    		 t[arr[i]]++;
	    	  
	      }
	     
	      for(int i=0;i<n;i++) {
	    	  System.out.print(ans[i]+" ");
	    	  
	      }
	      
	      
	}
}