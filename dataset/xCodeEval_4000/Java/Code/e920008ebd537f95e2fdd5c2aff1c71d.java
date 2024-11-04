

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
       int[] arr=new int[n];
       for(int i=0;i<n;i++) {
    	   arr[i]=s.nextInt();
       }
       int h=-1;
       int zero=0;
       for(int i=0;i<n;i++) {
    	   if(arr[i]==0) {
    		   zero=1;
    		   h=i;
    		   break;
    	   }
       }
       StringBuilder sb=new StringBuilder();
       
       if(zero==0) {
    	 int neg=0;
    	 int lar=Integer.MIN_VALUE;
    	 int in=-1;
    	 for(int i=0;i<n;i++) {
    		 if(arr[i]<0) {
    			 neg++;
    			 if(lar<arr[i]) {
    				 lar=arr[i];
    				 in=i;
    			 }else {
    				 
    			 }
    			 
    		 }
    	 }
    	 
    	 if(neg%2==0) {
    		 
    		 for(int i=1;i<n;i++) {
    			sb.append(1+" "+(i+1)+" "+1+"\n");
    		 }
    		 
    	 }else {
    		 
    		 if(in==0) {
    			 sb.append(2+" "+1+"\n");
    			 for(int i=2;i<n;i++) {
    				 if(in==i) {
    					 
    				 }else {
    					 sb.append(1+" "+(i+1)+" "+2+"\n");
    				 }
    			 }
    		 }else {
    			 sb.append(2+" "+(in+1)+"\n");
    			 for(int i=1;i<n;i++) {
    				 if(in==i) {
    					 
    				 }else {
    					 sb.append(1+" "+(i+1)+" "+1+"\n");
    				 }
    			 }
    			 
    			 
    		 }
    		 
    	 }
    	 System.out.println(sb);
       }else {
    	   
    	   
    	   int neg=0;
      	 int lar=Integer.MIN_VALUE;
      	 int in=-1;
      	 for(int i=0;i<n;i++) {
      		 if(arr[i]<0) {
      			 neg++;
      			 if(lar<arr[i]) {
      				 lar=arr[i];
      				 in=i;
      			 }else {
      				 
      			 }
      			 
      		 }
      	 }
      	 
      	 if(neg%2==0) {
      		 
      		for(int i=0;i<n;i++) {
      			if(arr[i]==0&&i!=h) {
      				sb.append(1+" "+(i+1)+" "+(h+1)+"\n");
      			}
      		}
      		int g=-1;
      		for(int i=0;i<n;i++) {
      			if(arr[i]!=0) {
      				g=i;
      				break;
      			}
      		}
      		
      		if(g!=-1) {
      			sb.append(2+" "+(h+1)+" \n");
      			
      			for(int i=0;i<n;i++) {
      				if(i!=g&&arr[i]!=0) {
      					sb.append(1+" "+(i+1)+" "+(g+1)+"\n");
      				}
      			}
      		}
      		 
      	 }else {
      		 
      		 
      		 
      		for(int i=0;i<n;i++) {
      			if(arr[i]==0&&i!=h) {
      				sb.append(1+" "+(i+1)+" "+(h+1)+"\n");
      			}
      		}
      		sb.append(1+" "+(in+1)+" "+(h+1)+"\n");
      		
      		int g=-1;
      		for(int i=0;i<n;i++) {
      			if(arr[i]!=0&&i!=in) {
      				g=i;
      				break;
      			}
      		}
      		
      		if(g!=-1) {
      			sb.append(2+" "+(h+1)+" \n");
      			
      			for(int i=0;i<n;i++) {
      				if(i!=g&&arr[i]!=0&&i!=in) {
      					sb.append(1+" "+(i+1)+" "+(g+1)+"\n");
      				}
      			}
      		}
      		
      		
      		
      		
      		 
      		 
      	 }
      	 
      	 
      	 
    	   
    	System.out.println(sb);   
    	   
    	   
       }
       
         
	}
}