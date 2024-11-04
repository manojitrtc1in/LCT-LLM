

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		 int n=s.nextInt();
		 long[] arr=new long[n];
		 long[] brr=new long[n];
		 for(int i=0;i<n;i++) {
			 arr[i]=s.nextLong();
			 
		 }
		 for(int i=0;i<n;i++) {
			 brr[i]=s.nextLong();
			 
		 }
		 
		 
		 ArrayList<Long> list=new ArrayList<>();
		 
		 for(int i=0;i<n;i++) {
			 list.add(arr[i]-brr[i]);
		 }
		 
		 Collections.sort(list);
		 
		 int index=-1;
		 for(int i=0;i<list.size();i++) {
			 if(list.get(i)<=0) {
				 index=i;
			 }
		 }
		long v=0;
		 for(int i=0;i<list.size();i++) {
			 if(list.get(i)>0) {
				 v++;
			 }
		 }
		

		 long ans=0;
		 ans=ans+(((v-1)*(v))/2);
		 
		 if(index==-1) {
			
			 System.out.println(ans);
		 }else {
			 int st=index;
			 int end=index+1;
			
				
				 while(st>=0&&end<n) {
					 if(list.get(st)+list.get(end)>0) {
						ans=ans+(n-end);
						st--;
					 }else {
						 end++;
					 }
				 }
				 System.out.println(ans);
				 
			 }
			 
			 
		 
		 
		
		
	 }
}