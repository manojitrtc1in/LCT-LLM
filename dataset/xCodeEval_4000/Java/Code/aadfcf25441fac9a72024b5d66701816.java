

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
	{
		Scanner s=new Scanner(System.in);
	StringBuilder sb=new StringBuilder();
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
		
			
		int n=s.nextInt();
		char[] arr=new char[n];
		char[] brr=new char[n];
		String str1=s.next();
		String str2=s.next();
		for(int i=0;i<n;i++) {
			arr[i]=str1.charAt(i);
		}
		for(int i=0;i<n;i++) {
			brr[i]=str2.charAt(i);
		}
			int flag=0;
       int[] c1=new int[26];
       int[] c2=new int[26];
       
       p1:for(int i=0;i<n;i++) {
    	   if(arr[i]==brr[i]) {
    		   
    	   }else {
    		   if(flag==0) {
    			   int g=0;
    			   for(int j=i+1;j<n;j++) {
    				   
    				   if(arr[j]==arr[i]&&brr[j]==brr[i]) {
    					   if(flag==0) {
    						   arr[j]=brr[i];
    						   flag=1;
    						   g=1;
    						   break;
    					   }else {
    						   flag=2;
    						 
    						   break p1;
    					   }
    				   }
    			   }
    			   if(g==0) {
    				  flag=2;
    				  break;
    			   }
    			   
    			   
    		   }else {
    			   flag=2;
    			  
    			   break;
    		   }
    	   }
       }
       
       if(flag==2) {
    	   System.out.println("No"); 
    	   
       }else {
    	   System.out.println("Yes");
       }
       
       
       
		
		
		}
	}
}