

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b {
	
	static int g=0;
	static int v=0;
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	    int n=s.nextInt();
	    int m=s.nextInt();
	    ArrayList[] arr=new ArrayList[n+1];
	    for(int i=0;i<1+n;i++) {
	    	ArrayList<Integer> list=new ArrayList<>();
	    	arr[i]=list;
	    }
	    
	   

	    for(int i=0;i<m;i++) {
	    	int a=s.nextInt();
	    	int b=s.nextInt();
	    	arr[a].add(b);
	    	arr[b].add(a);
	    

	    	

	    	
	    }
	    int ans=0;
	    int[] visited=new int[n+1];
	    for(int ie=1;ie<n+1;ie++) {
	    	if(visited[ie]==0) {
	    		g=0;
	    		v=0;
	    		dfs(arr,ie,visited,0);
	    		ans=ans+g-1;
	    	
	    	}
	    }
	    
	    
	   
	    System.out.println(m-ans);
	    
	   
	    
	}
	public static void dfs(ArrayList[] arr,int start,int[] visited,int p) {
		
		visited[start]=1;
		g++;
		for(int i=0;i<arr[start].size();i++) {
			int curr=(int)arr[start].get(i);
			
			if(visited[curr]==0) {
				
				dfs(arr,curr,visited,start);
			}else if(curr!=p){
				
				v=1;
			}
		}
		
	}
}