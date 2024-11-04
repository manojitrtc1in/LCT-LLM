

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static int flag=0;
	static HashMap<Integer,Integer> map;
	static HashMap<Integer,Integer> happ;
    public static void main(String[] args) {
 
    	Scanner s=new Scanner(System.in);
    	int t=s.nextInt();
    	for(int ie=0;ie<t;ie++) {
    	    flag=0;
    	   
    		int n=s.nextInt();
    		int m=s.nextInt();
    		int[] p=new int[n+1];
    		int[] h=new int[n+1];
    		for(int i=1;i<n+1;i++) {
    			p[i]=s.nextInt();
    		}
    		for(int i=1;i<n+1;i++) {
    			h[i]=s.nextInt();
    		}
    		ArrayList[] arr=new ArrayList[n+1];
    		for(int i=0;i<n+1;i++) {
    			ArrayList<Integer> list=new ArrayList<>();
    			arr[i]=list;
    		}
    		happ=new HashMap<>();
    		for(int i=0;i<n-1;i++) {
    			int a=s.nextInt();
    			int b=s.nextInt();
    			
    			arr[a].add(b);
    			arr[b].add(a);
    			
    		}
    		 map=new HashMap<>();
    		int[] visited=new int[n+1];
    		dfs2(arr,visited,1,p);
    		int[] visited2=new int[n+1];
    		dfs(arr,visited2,p,h,1);
    		int[] vis=new int[n+1];
    		dfs3(arr,vis,1);
    		
    		

    		if(flag==0){
    		System.out.println("YES");	
    		}else {
    			System.out.println("NO");
    		}
    		
    		
    	}
    }
    public static void dfs(ArrayList[] arr,int[] visited,int[] p,int[] h,int start) {
    	visited[start]=1;
    	
    	
    	for(int i=0;i<arr[start].size();i++) {
    		int curr=(int)arr[start].get(i);
    		if(visited[curr]==0) {
    			
    			dfs(arr,visited,p,h,curr);
    		}
    	}
    	
    	if(Math.abs((map.get(start)+h[start]))%2!=0){
    		flag=1;
    	}else {
    		happ.put(start,(map.get(start)+h[start])/2);
    	}
    	
    	
    	
    }
    public static int dfs2(ArrayList[] arr,int[] visited,int start,int[]p) {
    	visited[start]=1;
    	
    	int h=p[start];
    	for(int i=0;i<arr[start].size();i++) {
    		int curr=(int)arr[start].get(i);
    		if(visited[curr]==0) {
    			
    			h=h+dfs2(arr,visited,curr,p);
    			
    		}else {
    			
    		}
    		
    	}
    	map.put(start, h);
    	return h;
    
    }
    public static int dfs3(ArrayList[] arr,int[] visited,int start) {
    	visited[start]=1;
    	int h=0;
    	if(happ.containsKey(start))
    	 h=happ.get(start);
    	for(int i=0;i<arr[start].size();i++) {
    		int curr=(int)arr[start].get(i);
    		if(visited[curr]==0) {
    			
    			h=h+dfs3(arr,visited,curr);
    			
    		}
    		
    	}
    	if(happ.containsKey(start)) {
    	if(happ.get(start)<0||h-happ.get(start)>happ.get(start)||happ.get(start)>map.get(start)) {
    		flag=1;
    	

    		

    	}
    	}
    	if(happ.containsKey(start))
    	return happ.get(start);
    	else
    		return 0;
    
    }
}