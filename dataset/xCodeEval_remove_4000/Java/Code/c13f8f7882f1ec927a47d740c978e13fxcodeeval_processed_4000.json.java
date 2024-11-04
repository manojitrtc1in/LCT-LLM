

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static int flag=0;
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int f=s.nextInt();
		int b=s.nextInt();
		
		ArrayList[] arr=new ArrayList[n+1];
		
		for(int i=0;i<n+1;i++){
		     ArrayList<Integer> list=new ArrayList<>();		
		     arr[i]=list;
		}
		
		for(int i=0;i<n-1;i++) {
			int a=s.nextInt();
			int bs=s.nextInt();
			arr[a].add(bs);
			arr[bs].add(a);
		}
		
		int[] visited=new int[n+1];
		ArrayList<Integer> list=new ArrayList<>();
		dfs(arr,visited,f,f,b,list);
		
		int x=list.get(1);
		int y=list.get(list.size()-2);
		
		int[] vis=new int[n+1];
		
		vis[x]=1;
		int g=dfs2(arr,vis,f);
		
		int[] vis2=new int[n+1];
		
		vis2[y]=1;
		int h=dfs2(arr,vis2,b);
		
		
		System.out.println(1l*n*(n-1)-1l*g*h);
		
		
			
	}
	
	public static void dfs(ArrayList[] arr,int[] visited,int start,int f,int b,ArrayList<Integer> list) {
	
		visited[start]=1;
		if(flag==0)
		list.add(start);
		
		if(start==b) {
			flag=1;
			return;
		}
		
		for(int i=0;i<arr[start].size();i++) {
			int curr=(int)arr[start].get(i);
			
			if(visited[curr]==0) {
				
				dfs(arr,visited,curr,f,b,list);
			}
		}
		if(flag==0)
		list.remove(list.size()-1);
		
		
	}
	public static int dfs2(ArrayList[] arr,int[] visited,int start) {
		
		
		
		visited[start]=1;
		int l=1;
		
		for(int i=0;i<arr[start].size();i++) {
			int curr=(int)arr[start].get(i);
			
			if(visited[curr]==0) {
				
				l=l+dfs2(arr,visited,curr);
			}
		}
		return l;
		
		
		
	}
	
	
}