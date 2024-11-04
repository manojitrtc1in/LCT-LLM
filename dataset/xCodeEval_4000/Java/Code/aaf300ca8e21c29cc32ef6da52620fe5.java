

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

 public class d {
	
	 public static void main(String[] args) {
		 Scanner s=new Scanner(System.in);
	
		 int n=s.nextInt();
		 int k=s.nextInt();
		 int[] arr=new int[n];
		 for(int i=0;i<n;i++) {
			 arr[i]=s.nextInt();
		 }
		 pair[] brr=new pair[n];
		 
		 for(int i=0;i<n;i++) {
			 pair ob=new pair(arr[i],i);
			 brr[i]=ob;
		 }
		 
		 
		 Arrays.sort(brr,new comp());
		 
		 
		 ArrayList<Integer> list=new ArrayList<>();
		 int ans=0;
		 for(int i=n-k;i<n;i++) {
			 list.add(brr[i].in);
			 ans=ans+brr[i].a;
		 }
		 
		 System.out.println(ans);
		

		 Collections.sort(list);
		 for(int i=0;i<list.size()-1;i++)
		 {
			 if(i==0) {
				 System.out.print(list.get(i)+1+" ");
			 
			 }else {
				 System.out.print(-list.get(i-1)+list.get(i)+" ");
			 }
		 }
		 if(list.size()>1)
		 System.out.println(n-list.get(list.size()-2)-1);
		 else
			 System.out.println(n);
		 
	 }
 }
 
 class pair{
	 int a;
	 int in;
	 public pair(int a,int in) {
		 this.a=a;
		 this.in=in;
	 }
	 
 }
 
 class comp implements Comparator<pair>{
	 public int compare(pair h,pair j) {
		 if(h.a<j.a) {
			 return -1;
		 }else if(h.a==j.a) {
			 return 0;
		 }else {
			 return 1;
		 }
	 }
 }