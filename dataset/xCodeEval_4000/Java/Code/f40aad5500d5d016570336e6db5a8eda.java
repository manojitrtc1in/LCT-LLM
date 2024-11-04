

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
	      
	      int a=0;
	      int b=0;
	      for(int i=0;i<n;i++) {
	    	  if(arr[i]=='a') {
	    		  a++;
	    	  }else {
	    		  b++;
	    	  }
	      }
	      
	      char ch;
	      int g=0;
	      if(a>b) {
	    	  ch='b';
	      }else if(b>a) {
	    	  ch='a';
	      }else {
	    	  g=1;
	    	  ch='a';
	      }
	      
	      
	      
	      int st=0;
	      int end=n;
	      int ans=0;
	      while(st<=end) {
	    	  int mid=(st+end)/2;
	    	  
	    	  int l=0;
	    	  int r=mid-1;
	    	 int count=0;
	    	  for(int i=0;i<mid;i++) {
	    		  if(arr[i]==ch) {
	    			  count++;
	    		  }
	    	  }
	    	  
	    	  int flag=0;
	    	  if(count<=k) {
	    		  flag=1;
	    	  }
	    	  while(r<n-1) {
	    		  
	    		  if(arr[l]==ch) {
	    			  count--;
	    		  }
	    		  l++;
	    		  r++;
	    		  if(arr[r]==ch) {
	    			  count++;
	    		  }
	    		  
	    		  
	    		  if(count<=k) {
	    			  flag=1;
	    		  }
	    		  
	    		  
	    	  }
	    	 
	    	  

    		  if(flag==1) {
    			  ans=mid;
    			  st=mid+1;
    		  }else {
    			  end=mid-1;
    		  }
	    	  
	      }
	      
	      if(g==1) {
	    	  ch='b';
	    	  
	    	  
		      st=0;
		       end=n;
		     
		      while(st<=end) {
		    	  int mid=(st+end)/2;
		    	  
		    	  int l=0;
		    	  int r=mid-1;
		    	 int count=0;
		    	  for(int i=0;i<mid;i++) {
		    		  if(arr[i]==ch) {
		    			  count++;
		    		  }
		    	  }
		    	  
		    	  int flag=0;
		    	  if(count<=k) {
		    		  flag=1;
		    	  }
		    	  while(r<n-1) {
		    		  
		    		  if(arr[l]==ch) {
		    			  count--;
		    		  }
		    		  l++;
		    		  r++;
		    		  if(arr[r]==ch) {
		    			  count++;
		    		  }
		    		  
		    		  
		    		  if(count<=k) {
		    			  flag=1;
		    		  }
		    		  
		    		  
		    	  }
		    	 
		    	  

	    		  if(flag==1) {
	    			  ans=Math.max(mid,ans);
	    			  st=mid+1;
	    		  }else {
	    			  end=mid-1;
	    		  }
		    	  
		      }
	    	  
	    	  
	    	  
	      }
	      
	      System.out.println(ans);
	      
	      
	}
}