

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
	
		 int n=s.nextInt();
		 ArrayList[] arr=new ArrayList[n+1];
		 for(int i=0;i<n+1;i++) {
			 ArrayList<Integer> list=new ArrayList<>();
			 arr[i]=list;
		 }
		 
		 for(int i=0;i<n-1;i++) {
			 int a=s.nextInt();
			 int b=s.nextInt();
			 arr[a].add(b);
			 arr[b].add(a);
			 
		 }
		 HashMap<Integer,Integer> map=new HashMap<>();
		 int[] brr=new int[n];
		 for(int i=0;i<n;i++) {
			 brr[i]=s.nextInt();
			 map.put(brr[i], i+1);
			 
		 }
		
		 
		
		 System.out.println(bfs(arr,n,1,map,brr));
		 
		
		 
	 }
	 
	 
	 
	 public static String bfs(ArrayList[] arr,int n,int start,HashMap<Integer,Integer> map,int[] brr) {
		int count=0;
		int pre=0;
		int[] visited=new int[n+1];
		Queue<Integer> q=new LinkedList<>();
		q.add(start);
		int gmax=map.get(start);
		
		visited[start]=1;
		 if(gmax!=1) {
			 
			 return "No";	
			 }
		 
		 
		 while(!q.isEmpty()) {
			 
			 int curr=q.poll();
			

			
			 ArrayList<Integer> liste=new ArrayList<>();
			 for(int i=0;i<arr[curr].size();i++) {
				 int current=(int)arr[curr].get(i);
				 if(visited[current]==0) {
					
					 visited[current]=1;
					 liste.add(current);
					count++;
				 }
			 }
			
			 ArrayList<Integer> of =new ArrayList<>();
			 
			 for(int i=pre+1;i<=count;i++) {
				 of.add(brr[i]);
			 }
			 
			 Collections.sort(of);
			 Collections.sort(liste);
			 for(int i=0;i<of.size();i++) {
				 if(!of.get(i).equals(liste.get(i))) {
					
					 return "No";
				 }
			 }
			 
			 for(int i=pre+1;i<=count;i++) {
				 q.add(brr[i]);
			 }
			 pre=count;
			 
			 
			 
	 }
	 
	 return "Yes";
	 
	 
	 
	 
	 }
}