

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)	{
		
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int m=s.nextInt();
		
		ArrayList[] rarr=new ArrayList[n+1];
		ArrayList[] arr=new ArrayList[n+1];
		for(int i=0;i<n+1;i++) {
			ArrayList<Integer> list=new ArrayList<>();
			rarr[i]=list;
			ArrayList<Integer> list2=new ArrayList<>();
			arr[i]=list2;
		}
		
		for(int i=0;i<m;i++) {
			int a=s.nextInt();
			int b=s.nextInt();
			arr[a].add(b);
			rarr[b].add(a);
		}
		int h=s.nextInt();
		int[] path=new int[h];
		for(int i=0;i<h;i++) {
			path[i]=s.nextInt();
		}
		HashMap<Integer,Integer> map=new HashMap<>();
		int[] visited=new int[n+1];
		bfs(rarr,visited,path[h-1],map);
		
		int min=0;
		int max=0;
		
		for(int i=0;i<h-1;i++) {
			int count=0;
			if(map.get(path[i])==map.get(path[i+1])+1) {
				for(int j=0;j<arr[path[i]].size();j++) {
					int curr=(int)arr[path[i]].get(j);
					if(map.get(curr)==map.get(path[i])-1) {
						count++;
					}
				}
				
				if(count>1) {
					max++;
				}
				
			}else {
				min++;
				max++;
			}
			
			
		}
		System.out.println(min+" "+max);
	

		
	
	
	}
	public static void bfs(ArrayList[] arr,int[] visited,int start,HashMap<Integer,Integer> map) {
		Queue<pair> q=new LinkedList<>();
		q.add(new pair(start,0));
		map.put(start, 0);
		visited[start]=1;
		while(!q.isEmpty()) {
			pair ob=q.poll();
			
			for(int i=0;i<arr[ob.val].size();i++) {
				int curr=(int)arr[ob.val].get(i);
				if(visited[curr]==0) {
					visited[curr]=1;
					q.add(new pair(curr,ob.dist+1));
					map.put(curr, ob.dist+1);
				}
			}
		}
		
	}
}
class pair{
	int val;
	int dist;
	public pair(int val,int dist) {
		this.val=val;
		this.dist=dist;
	}
	
}