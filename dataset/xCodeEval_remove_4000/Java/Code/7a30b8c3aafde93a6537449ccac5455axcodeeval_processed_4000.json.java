

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] arr=new int[n];
		int[] brr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
			
		}
		for(int i=0;i<n;i++) {
			brr[i]=s.nextInt();
			
		}
		
		Integer[] crr=new Integer[n];
		for(int i=0;i<n;i++) {
			crr[i]=arr[i]-brr[i];
		}
		
		Arrays.sort(crr);
		long h=0;
		for(int i=0;i<n;i++) {
			long k=bs(crr,i);
			if(k!=-1) {
				h=h+n-k;
			}
			
		}
		System.out.println(h);
		
	 }
	 public static long bs(Integer[] crr,int ele) {
		 long ans=-1;
		 int start=ele+1;
		 int end=crr.length-1;
		 while(start<=end) {
			 int mid=(start+end)/2;
			 
			 if(crr[mid]+crr[ele]>0) {
				 ans=mid;
				 end=mid-1;
			 }else {
				 start=mid+1;
			 }
			 
		 }
		 

		 return ans;
		 
		 
	 }
	 
	 
	 
}