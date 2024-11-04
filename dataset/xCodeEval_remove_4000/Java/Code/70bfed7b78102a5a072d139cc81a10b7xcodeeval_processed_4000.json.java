

import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
       int zero=s.nextInt();
       int one=s.nextInt();
       int t=zero;
       StringBuilder sb=new StringBuilder();
       if(2*(zero+1)>=one&&one>=zero-1) {
    	   if(zero<one) {
    		   while(zero>0) {
    			   if(zero==one) {
    				   break;
    			   }
    		  sb.append("110");
    		  zero--;
    		  one=one-2;
    		   }
    		  

    		   while(zero>0) {
    			   sb.append("10");
    			   zero--;
    			   one--;
    		   }
    		   while(one>0) {
    			   sb.append("1");
    			   one--;
    		   }
    		  
    		  
    	   }
    	   
    	   else if(zero==one) {
    		   while(zero>0) {
    		  sb.append("10");
    		  zero--;
    		   }
    	   }else {
    		   while(one>0) {
    			   sb.append("01");
    			   one--;
    		   }
    		   sb.append("0");
    	   }
    	   System.out.println(sb);
       }else {
    	   System.out.println(-1);
       }
       
	 }
	 
}