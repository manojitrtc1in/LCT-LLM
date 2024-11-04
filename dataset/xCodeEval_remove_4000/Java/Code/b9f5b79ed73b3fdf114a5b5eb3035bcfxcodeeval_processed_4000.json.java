

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	      int n=s.nextInt();
	      int k=s.nextInt();
	      char[] arr=s.next().toCharArray();

	      char ch='b';
	      
	      int ans=0;
	      if(k!=0) {
	     for(int i=0;i<2;i++) {
	    	 int st=0;
		      int end=0;
		      int count=0;
		     
	    	 if(i==1) {
	    		 ch='a';
	    	 }
	    	 if(arr[0]==ch) {
		    	  count++;
		      }
	    	 
	      while(end<n) {
	    	

	    	  if(count<=k) { 
	    		  ans=Math.max(ans, end-st+1);
	    		  end++;
	    		  if(end<n) {
	    		  if(arr[end]==ch) {
	    			  count++;
	    		  }
	    		  }else {
	    			  break;
	    		  }
	    	  }else {
	    		
	    		  if(st==end) {
	    			  if(arr[st]==ch) {
	    				  count--;
	    			  }
	    			  st++;
	    			  end++;
	    			  if(end<n) {
	    			  if(arr[end]==ch) {
	    				  count++;
	    			  
	    			  }else {
	    				  break;
	    			  }
	    			  }
	    		  }else {
	    			  
	    			  if(arr[st]==ch) {
	    				  count--;
	    				  
	    			  }
	    			  st++;
	    		  }
	    			  
	    	  }
	      }
	     }
	     System.out.println(ans);
	     }else {
	    	 int c=1;
	    	 for(int i=0;i<n-1;i++) {
	    		 if(arr[i]==arr[i+1]) {
	    			 c++;
	    		 }else {
	    			 ans=Math.max(ans, c);
	    			 c=1;
	    		 }
	    	 }
	    	 ans=Math.max(ans, c);
	    	 System.out.println(ans);
	     }
	     
	      
	}
}
