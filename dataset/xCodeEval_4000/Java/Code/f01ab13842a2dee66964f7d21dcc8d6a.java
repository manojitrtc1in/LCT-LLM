

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		 long[] arr=new long[30];
				 for(int i=0;i<30;i++) {
					 arr[i]=(long)Math.pow(3, i);
				 }
		 int t=s.nextInt();
		 for(int ie=0;ie<t;ie++) {
			 long n=s.nextLong();
			 ArrayList<Long> list=new ArrayList<>();
			 fun(n,0,list,arr,0);
			 Collections.sort(list);
					 System.out.println(list.get(0));
			
		 }
		
		
	 }
	 
	 
	 public static void fun(long n,long sum,ArrayList<Long> list,long[] arr,int curr) {
	
		 if(sum>=n) {
			list.add(sum);
			return;
		 }
		 if(curr>=arr.length) {
			 return;
		 }
		 
		 fun(n,sum,list,arr,curr+1);
		 fun(n,sum+arr[curr],list,arr,curr+1);
		 
	 }
	 
}