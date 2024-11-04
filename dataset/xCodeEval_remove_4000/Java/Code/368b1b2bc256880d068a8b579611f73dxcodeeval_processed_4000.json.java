

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		 int max=Integer.MIN_VALUE;
       int n=s.nextInt();
       int m=s.nextInt();
   
       int[][] arr=new int[n][m];
		 for(int i=0;i<n;i++) {
			    int min=Integer.MAX_VALUE;
			 for(int j=0;j<m;j++) {
				 arr[i][j]=s.nextInt();
				 if(min>arr[i][j]) {
					 min=arr[i][j];
				 }
			 }
			 if(max<min) {
				 max=min;
			 }
		 }
		 System.out.println(max);
	 }
	 
}