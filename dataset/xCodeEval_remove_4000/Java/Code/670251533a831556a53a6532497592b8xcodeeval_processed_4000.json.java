

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		HashMap<Long,Integer> map=new HashMap<>();
		 int n=s.nextInt();
		 long[] arr=new long[n];
		 for(int i=0;i<n;i++) {
		
			 arr[i]=s.nextLong();
			 if(map.containsKey(arr[i])) {
				 map.put(arr[i], i);
			 }else {
				 map.put(arr[i], i);
			 }
		 }
		 
		 
		 ArrayList[] graph=new ArrayList[n];
		 for(int i=0;i<n;i++) {
			 ArrayList<Long> list=new ArrayList<>();
			 graph[i]=list;
		 }
		 
		 for(int i=0;i<n;i++) {
			 if(map.containsKey(2*arr[i])) {
				 graph[i].add(map.get(2*arr[i]));
				
				
			 }
			 if(map.containsKey(arr[i]/2)&&arr[i]%2==0) {
				 graph[i].add(map.get(arr[i]/2));
				
				
			 }
			 if(map.containsKey(3*arr[i])) {
				 graph[i].add(map.get(3*arr[i]));
				
			 }
			 
			 if(map.containsKey(arr[i]/3)&&arr[i]%3==0) {
				 graph[i].add(map.get(arr[i]/3));
				 
			 }
		 }
		 int in=-1; int min=101;
		 for(int i=0;i<n;i++) {
			 if(min>graph[i].size()) {
				 min=graph[i].size();
				 in=i;
			 }
				 
		 }
		ArrayList<Long> ans=new ArrayList<>();
				
		 int[] visited=new int[n];
		dfs(graph,in,visited,arr,ans);
		int flag=0;
		if((ans.get(0).equals(ans.get(1)/2)&&ans.get(1)%2==0)||ans.get(0).equals(ans.get(1)*3)) {
			flag=0;
		}else {
			flag=1;
			

		}
		
		
		if(flag==0) {
			for(int i=0;i<ans.size();i++) {
				System.out.print(ans.get(i)+" ");
				 
			}
		}else {
			for(int i=ans.size()-1;i>=0;i--) {
				System.out.print(ans.get(i)+" ");
			}
		}
		

		 
}
	 public static void dfs(ArrayList[] graph,int st,int[] visited,long[] arr,ArrayList<Long> ans) {
		 visited[st]=1;
		 ans.add(arr[st]);
		 for(int i=0;i<graph[st].size();i++) {
			 int curr=(int)graph[st].get(i);
			 if(visited[curr]==0) {
				 
				 dfs(graph,curr,visited,arr,ans);
				 
				 
			 }
			
		 }
		 
		
		 
		 
	 }
	 
}