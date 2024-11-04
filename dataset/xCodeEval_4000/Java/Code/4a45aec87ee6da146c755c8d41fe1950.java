

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class d {
	static int v=0;
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		
		int n=s.nextInt();
		int m=s.nextInt();
		ArrayList[] arr=new ArrayList[n+1];
		for(int i=0;i<n+1;i++) {
			ArrayList<Integer> list=new ArrayList<>();
			arr[i]=list;
		}
		
		for(int i=0;i<m;i++) {
			int a=s.nextInt();
			int b=s.nextInt();
			arr[a].add(b);
			arr[b].add(a);
		}
		
		fun(arr,n);
		
		
		 
	 }
	 
	 public static void fun(ArrayList[] arr,int n) {
		 int[] visited=new int[n+1];
		 int g=0;int k=0;
		 for(int i=1;i<n+1;i++) {
			 if(visited[i]==0) {
				 v=0;
				k= dfs(arr,n,i,visited,0,0);
				if(k==1) {
					   g=g+1;
					 }
			 }
		 }
		 
		 
		 
		 System.out.println(g);
	 }
	 
	 public static int dfs(ArrayList[] arr,int n,int st,int[] visited,int p,int count) {
		int flag=0;
	

		 visited[st]=1;
		 for(int i=0;i<arr[st].size();i++) {
			 int curr=(int)arr[st].get(i);
			 if(arr[st].size()==2) {
				 flag=1;
			 }else {
				 v=1;
			 }
			 if(visited[curr]==1&&flag==1&&curr!=p&&v==0) {
				
			

				 count=1;
				 return count;
				

			 }
			
			 if(visited[curr]==0) {
				 visited[curr]=1;
				  p=st;
				 dfs(arr,n,curr,visited,p,count);
			 }
			 
			 
		 }
		

		 return count;
	 }
	 
	 
	 
}