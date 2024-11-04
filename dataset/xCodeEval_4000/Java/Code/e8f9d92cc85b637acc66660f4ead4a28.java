

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 public class k{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        for(int ie=0;ie<t;ie++) {
        	
        	int n=s.nextInt();
        	int [] arr=new int[n];
        	for(int i=0;i<n;i++) {
        		arr[i]=s.nextInt();
        		
        	}
        	
        	
        	int count=1;
        	int index=-1;
        	
        	int flag=0;
        	for(int i=0;i<n;i++) {
        		if(arr[i]==1) {
        			index=i;
        			break;
        		}
        	}
        	
        	if(index!=-1) {
        	
        	for(int i=index;i<n;i++) {
        		if(arr[i]==count) {
        			count++;
        		}else {
        			flag=1;
        			break;
        		}
        	}
        	
        	
        	if(flag==0) {
        		for(int i=0;i<index;i++) {
        			if(arr[i]==count) {
        				count++;
        			}else {
        				flag=2;
        				break;
        			}
        		}
        	}
        	
        	
        	
        	if(flag==0) {
        		System.out.println("YES");
        	}else {
        		int g=0;
        	   count=1;
        	   for(int i=index;i>=0;i--) {
        		   if(arr[i]==count) {
        			   count++;
        		   }else {
        			   g=1;
        			   break;
        		   }
        	   }
        	   
        	   
        	   if(g==0) {
        		   for(int i=n-1;i>index;i--) {
        			   if(arr[i]==count) {
        				   count++;
        			   }else {
        				   g=2;
        				   break;
        			   }
        		   }
        	   }
        	   
        	   
        	   
        	   if(g==0) {
        		   System.out.println("YES");
        	   }else {
        		   System.out.println("NO");
        	   }
        		
        		
        		
        	}
        		
        	}else {
        		System.out.println("NO");
        	}
        	
        	
        	
        	
        }
		
		
	}
 }
        	 
        	 