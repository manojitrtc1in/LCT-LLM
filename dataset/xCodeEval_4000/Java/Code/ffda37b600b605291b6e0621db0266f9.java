

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		
		 int n=s.nextInt();
		 int[] arr=new int[n];
		 for(int i=0;i<n;i++) {
			 arr[i]=s.nextInt();
		 }
		 
		 ArrayList[] g=new ArrayList[n];
		 for(int i=0;i<n;i++) {
			 ArrayList<Integer> list=new ArrayList<>();
			 g[i]=list;
		 }
		 
		 
		 for(int i=0;i<n;i++) {
			 if(i-arr[i]>=0) {
				 g[i-arr[i]].add(i);
			 }
			 if(arr[i]+i<=n-1) {
				 g[i+arr[i]].add(i);
			 }
		 }
		 HashMap<Integer,Integer> map=new HashMap<>();
		 Queue<pair> q=new LinkedList<>();
		 int visited[]=new int[n];
		 for(int i=0;i<n;i++) {
			 if(arr[i]%2!=0) {
				 
				 pair ob=new pair(i,0);
				 q.add(ob);
				 visited[i]=1;
			 }
		 }
		
		 while(!q.isEmpty()) {
			 pair curr=q.poll();
			 for(int i=0;i<g[curr.a].size();i++) {
				pair k=new pair((int)g[curr.a].get(i),curr.dist+1);
				 if(visited[k.a]==0) {
					
					 visited[k.a]=1;
					if(arr[k.a]%2==0) {
						
						map.put(k.a, k.dist);
					}
					 q.add(k);
				 }
			 }
		 }
		 
		 
		 
		 
		 Queue<pair> q2=new LinkedList<>();
		 int visited2[]=new int[n];
		 for(int i=0;i<n;i++) {
			 if(arr[i]%2==0) {
				 
				 pair ob=new pair(i,0);
				 q2.add(ob);
				 visited2[i]=1;
			 }
		 }
		
		 while(!q2.isEmpty()) {
			 pair curr=q2.poll();
			 for(int i=0;i<g[curr.a].size();i++) {
				pair k=new pair((int)g[curr.a].get(i),curr.dist+1);
				 if(visited2[k.a]==0) {
					
					 visited2[k.a]=1;
					if(arr[k.a]%2!=0) {
						
						map.put(k.a, k.dist);
					}
					 q2.add(k);
				 }
			 }
		 }
		 
		

		 for(int i=0;i<n;i++) {
			 if(map.containsKey(i)) {
				 System.out.print(map.get(i)+" ");
			 }else {
				 System.out.print(-1+" ");
			 }
		 }
		 
	 }
	 
	
}


class pair{
	int a;
	int dist;
	public pair(int a,int dist) {
		this.a=a;
		this.dist=dist;
	}
}