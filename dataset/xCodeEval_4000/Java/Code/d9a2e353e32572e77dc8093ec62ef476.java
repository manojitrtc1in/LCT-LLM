

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		 String str=s.next();
		 int n=str.length();
		 int[] pre=new int [n];
		 int[] total=new int[n];
		 int count=0;
		 for(int i=0;i<n;i++) {
			 if(str.charAt(i)=='(') {
				 count++;
				 total[i]=count;
			 }else {
				 total[i]=count;
			 }
		 }
		 int sum=0;
		 for(int i=n-1;i>=0;i--) {
			 if(str.charAt(i)==')'){
				 sum++;
				 pre[i]=sum;
			 }else {
				 pre[i]=sum;
			 }
		 }
		 
		 int max=Integer.MIN_VALUE;
		 for(int i=0;i<n;i++){
			 if(Math.min(total[i], pre[i])>max&&total[i]!=0&&pre[i]!=0) {
				 max=Math.min(total[i], pre[i]);
			 }
		 }
		
		 if(max==Integer.MIN_VALUE) {
			 System.out.println(0);
		 }else {
			 int h=max;
			 System.out.println(1);
			 System.out.println(2*max);
			 for(int i=0;i<n;i++) {
				 if(max>0&&str.charAt(i)=='(') {
					 System.out.print(i+1+" ");
					 max--;
				 }
			 }
			 ArrayList<Integer> list=new ArrayList<>();
			 for(int i=n-1;i>=0;i--) {
				 if(h>0&&str.charAt(i)==')') {
					 list.add(i+1);
					 h--;
				 }
			 }
			 for(int i=list.size()-1;i>=0;i--) {
				 System.out.print(list.get(i)+" ");
			 }
			 
			 
		 }
		 
	 }
}