

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b{
	
	public static void main(String[] args) throws Exception 
	{ StringBuilder sb=new StringBuilder();
		Scanner s=new Scanner(System.in);
         int t=s.nextInt();
         
         for(int ie=0;ie<t;ie++) {
           int n=s.nextInt();
            int[] arr=new int[n];
            for(int i=0;i<n;i++) {
            	arr[i]=s.nextInt();
            }
            int g=0;
            int foo=0;
            for(int i=0;i<n-1;i++) {
            	if(arr[i]==arr[i+1]) {
            		
            	}else {
            		foo=1;
            		break;
            	}
            }
            if(foo==1) {
           int[] col=new int[n];
           
           for(int i=0;i<n;i++) {
        	   if(i%2==0) {
        		   col[i]=1;
        	   }else {
        		   col[i]=2;
        	   }
           }
           
           int index=-1;
           if(arr[n-1]!=arr[0]) {
        	   if(col[n-1]==col[0]) {
        		   int flag=0;
        		   for(int i=0;i<n-1;i++) {
        			  
        			   if(arr[i]==arr[i+1]) {
        				   flag=1;
        				  
        				  col[i+1]=col[i];
        				  index=i+1;
        				  break;
        			   }
        			   
        		   }
        		   
        		   if(flag==0) {
        			g=1;
        			   col[n-1]=3;
        		   }else {
        			   for(int i=index+1;i<n;i++) {
        				   if(col[i-1]==2) {
        					   col[i]=1;
        				   }else {
        					   col[i]=2;
        				   }
        			   }
        		   }
        		   
        	   }
           }
           
           
           if(g==0) {
        	   System.out.println(2);
           }else {
        	   System.out.println(3);
           }
            for(int i=0;i<n;i++) {
            	System.out.print(col[i]+" ");
            }
            System.out.println();
            }else {
            	System.out.println(1);
            	for(int i=0;i<n;i++) {
            		System.out.print(1+" ");
            	}
            	System.out.println();
            }
         }
            
	}
}