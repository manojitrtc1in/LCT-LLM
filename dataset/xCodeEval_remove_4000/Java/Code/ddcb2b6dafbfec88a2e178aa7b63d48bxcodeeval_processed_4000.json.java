

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		
		 int n=s.nextInt();
		 int ans=0;
		 long[] arr=new long[n];
		 for(int i=0;i<n;i++) {
			 arr[i]=s.nextLong();
		 }
		 long count=1;
		 ArrayList<Long> list=new ArrayList<>();
		 ArrayList<Long> list2=new ArrayList<>();
		 for(int i=0;i<n-1;i++) {
			 if(arr[i]<arr[i+1]) {
				 count++;
			 }else {
				list.add((long)i);
				list2.add(count);
				count=1;
			 }
		 }
		

		
			 list.add((long)(n-1));
			 list2.add(count);
		
		

		 

		 
		
		 ArrayList<Long> list3=new ArrayList<>();
		 for(int i=0;i<list.size()-1;i++) {
			 if(list.get(i)==0||list.get(i)==n-2||list.get(i)==n-1) {
				list3.add(list2.get(i));
			 }else {
				 if(arr[(int)(list.get(i)-1)]<arr[(int)(list.get(i)+1)]||(arr[(int)(list.get(i)+0)]<arr[(int)(list.get(i)+2)])) {
					 list3.add(list2.get(i)+list2.get(i+1)-1);
				 }else {
					 list3.add(list2.get(i));
				 }
			 }
		 }
		 list3.add(list2.get(list2.size()-1));
		 

		 Collections.sort(list3);
		 if(list3.size()!=0) {
		 System.out.println(list3.get(list3.size()-1));
		 }else {
			 System.out.println(n);
	 }
	 }
}