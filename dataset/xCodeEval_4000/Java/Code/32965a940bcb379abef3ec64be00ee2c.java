

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
         Scanner s=new Scanner(System.in);

         int n=s.nextInt();
         StringBuilder sb=new StringBuilder();
        
         int count=0;
         int curr=0;
        
        	 count=1;
        	 curr=-2;
        	 sb.append(-1+" "+0+"\n");
         for(int i=0;i<n;i++) {
        	 curr=curr+2;
        	 sb.append((curr)+" "+(0)+"\n");
        	 sb.append((curr+1)+" "+(0)+" \n");
        	

        	 count=count+4;
        	 

        	

        	 sb.append((curr)+" "+1+"\n");
        	 sb.append((curr)+" "+(-1)+"\n");
        
        	
         }
         if(n%2!=0) {
         sb.append((-1)+" "+(-1)+"\n");
    	 sb.append((curr+1)+" "+(1)+" \n");
    	 count=count+2;
    	int h=0;
    	for(int i=0;i<n-1;i++) {
    		sb.append(h+" "+2+"\n");
    		count++;
    		h=h+2;
    	}
    	h=1;
    	for(int i=0;i<n/2;i++) {
    		count++;
    		sb.append(h+" "+2+"\n");
    		h=h+4;
    	}
    	h=curr;
    	for(int i=0;i<n-1;i++) {
    		sb.append(h+" "+(-2)+"\n");
    		h=h-2;
    		count++;
    	}
    	h=curr-1;
    	for(int i=0;i<n/2;i++) {
    		sb.append(h+" "+(-2)+"\n");
    		h=h-4;
    		count++;
    	}
    	
         }else {
        	 
        	 sb.append((-1)+" "+(-1)+"\n");
        	 sb.append((curr+1)+" "+(-1)+" \n");
        	 count=count+2; 
        	 
        	 
        	 
        	 
        	 int h=0;
         	for(int i=0;i<n;i++) {
         		sb.append(h+" "+2+"\n");
         		count++;
         		h=h+2;
         	}
         	h=1;
         	for(int i=0;i<n/2;i++) {
         		count++;
         		sb.append(h+" "+2+"\n");
         		h=h+4;
         	}
         	h=curr-2;
         	for(int i=0;i<n-2;i++) {
         		sb.append(h+" "+(-2)+"\n");
         		h=h-2;
         		count++;
         	}
         	h=curr-3;
         	for(int i=0;i<((n-2)/2);i++) {
         		sb.append(h+" "+(-2)+"\n");
         		h=h-4;
         		count++;
         	}
        	 
        	 
        	 
        	 
        	 
         }
    	System.out.println(count);
    	System.out.println(sb);
    	
         
         }
         
         
     
	
}