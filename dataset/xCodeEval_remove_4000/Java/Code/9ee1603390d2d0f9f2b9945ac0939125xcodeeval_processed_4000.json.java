

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
 public class b{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
       int n=s.nextInt();
       int k=s.nextInt();
       ArrayList[] arr=new ArrayList[n+1];
       
       for(int i=0;i<n+1;i++) {
    	   ArrayList<Integer>list=new ArrayList<>();
    	   arr[i]=list;
       }
       
       for(int i=0;i<n-1;i++) {
    	   int a=s.nextInt();
    	   int b=s.nextInt();
    	   int c=s.nextInt();
    	   
    	   if(c==0) {
    		   arr[a].add(b);
    		   arr[b].add(a);
    	   }
    			   
    			  
    			   
       }
       long m=1000000007;
       
       long ans=power((long)n,(long)k,m)-n;
       
       int[] visited=new int[n+1];
       
       for(int i=1;i<n+1;i++) {
    	   if(visited[i]==0) {
    		   long minus=dfs(arr,visited,i,m)%m;
    		   ans=(ans%m+m+minus%m-power(minus,(long)k,m)%m)%m;
    	   }
       }
       
       System.out.println(ans);
    		   
		
		
		
	}
	
	public static long power(long x,long y,long m) {
		long res=1;
		
		while(y>0) {
		
			if(y%2!=0) {
				res=(res%m*x%m)%m;
			}
			y=y/2;
			x=(x%m*x%m)%m;
		
		}
		
		return res;
	
	}
	
	
	public static long dfs(ArrayList[] arr,int[] visited,int curr,long m) {
		visited[curr]=1;
		long l=0;
		for(int i=0;i<arr[curr].size();i++) {
			int now=(int)arr[curr].get(i);
			if(visited[now]==0) {
				
				l=(l%m+dfs(arr,visited,now,m)%m)%m;
			}
			
			
		}
		
		return l+1;
		
		
	}
	
 }