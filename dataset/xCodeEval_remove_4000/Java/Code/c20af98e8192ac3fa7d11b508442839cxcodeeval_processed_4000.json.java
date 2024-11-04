

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
 public class d {
	
	
	public static void main(String[] args)  {
	   Scanner s = new Scanner( System.in);
	
	  long ans=0;

	   int n=s.nextInt();
	   char[] arr=s.next().toCharArray();
	   
	   StringBuilder sb=new StringBuilder();
	   if(n==1) {
		   System.out.println(0);
		   System.out.println(arr[0]);
	   }else {
	   for(int i=1;i<n-1;i++) {
		   if(arr[i-1]==arr[i]) {
			   ans++;
			   if(arr[i-1]==arr[i+1]) {
				   if(arr[i-1]=='R') {
					   arr[i]='G';
				   }else if(arr[i-1]=='G') {
					   arr[i]='R';
				   }else {
					   arr[i]='R';
				   }
			   }else {
				   if(arr[i-1]=='R'&&arr[i+1]=='B') {
					   arr[i]='G';
				   }else if(arr[i-1]=='R'&&arr[i+1]=='G') {
					   arr[i]='B';
				   }else if(arr[i-1]=='G'&&arr[i+1]=='R') {
					   arr[i]='B';
				   }else if(arr[i-1]=='G'&&arr[i+1]=='B') {
					   arr[i]='R';
				   }else if(arr[i-1]=='B'&&arr[i+1]=='R') {
					   arr[i]='G';
				   }else if(arr[i-1]=='B'&&arr[i+1]=='G') {
					   arr[i]='R';
				   }
			   }
		   }else {
			   
		   }
	   }
	   if(arr[n-1]==arr[n-2]) {
		   ans++;
		   if(arr[n-2]=='R') {
			   arr[n-1]='G';
		   }else if(arr[n-2]=='B') {
			   arr[n-1]='G';
		   }else {
			   arr[n-1]='B';
		   }
	   }else {
		   
	   }
	   
	   System.out.println(ans);
	   for(int i=0;i<n;i++) {
		   System.out.print(arr[i]);
	   }
	   
	}
	}
 }