

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		 int n=s.nextInt();
		 int m=s.nextInt();
		 int[] arr=new int[n];
		 int[] brr=new int[m];
		 for(int i=0;i<n;i++) {
			 arr[i]=s.nextInt();	
			 }
		 for(int i=0;i<m;i++) {
			 brr[i]=s.nextInt();
		 }
		 
		 int o=0;int p=0;
		 long ans=0;
		 long sum1=arr[0];long sum2=brr[0];
		 while(o<n&&p<m) {
			 if(sum1==sum2) {
				 ans++;
				 o++; p++;
				 if(o!=n&&p!=m) {
				 sum1=arr[o];sum2=brr[p];
				 }
			 }else {
				 if(sum1<sum2) {
					o++;
					if(o!=n) {
						 sum1=sum1+arr[o];
						 }
					
				 }else {
					 p++;
					 if(p!=m) {
						 sum2=sum2+brr[p];
						 }
					 
				 }
			 }
			 
		 }
		 
		 
		 System.out.println(ans);
		 
	 }
}