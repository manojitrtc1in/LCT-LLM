

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
	StringBuilder sb=new StringBuilder();
	   int n=s.nextInt();
	   int m=s.nextInt();
	   
	   int[] crr=new int[n];
	   for(int i=0;i<n;i++) {
		   crr[i]=s.nextInt();
		   
	   }
	   
	   int[][] q=new int[m][2];
	   for(int i=0;i<m;i++) {
		   q[i][0]=s.nextInt()-1;
		   q[i][1]=s.nextInt()-1;
		   
	   }
	   
	  
	   int ans=Integer.MIN_VALUE;
	   int in=-1;
	   for(int i=0;i<n;i++) {
		   int[] arr=new int[n];
		   for(int j=0;j<n;j++) {
			   arr[j]=crr[j];
		   }
		   for(int j=0;j<m;j++) {
			   
			   if(i<q[j][0]||i>q[j][1]) {
				   for(int k=q[j][0];k<=q[j][1];k++) {
					   arr[k]--;
				   }
			   }
			   
		   }
		   
		   int min=Integer.MAX_VALUE;
		   int max=Integer.MIN_VALUE;
		   for(int k=0;k<n;k++) {
			   
				   if(min>arr[k]) {
					   min=arr[k];
				   }
				   if(max<arr[i]) {
					   max=arr[i];
				   }
			   
		   }
		
		   
		   if(ans<max-min) {
			   ans=max-min;
			   in=i;
		   }
	   }
	   ArrayList<Integer> list=new ArrayList<>();
	   sb.append(ans+"\n");
	   int count=0;
	   for(int i=0;i<m;i++) {
		   if(in<q[i][0]||in>q[i][1]) {
			   count++;
			   list.add(i+1);
		   }
	   }
	   sb.append(count+"\n");
	   for(int i=0;i<list.size();i++) {
		   sb.append(list.get(i)+" ");
		   
	   }
	   
	   
	   System.out.println(sb);
	}
 }