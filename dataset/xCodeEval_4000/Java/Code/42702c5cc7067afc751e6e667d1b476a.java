

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int[] arr=new int[n];
			
			ArrayList<Integer> list=new ArrayList<>();
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			int[] visited=new int[n];
			p1:while(true) {
				int g=0;
				for(int i=0;i<n-1;i++) {
					if(arr[i]<=arr[i+1]) {
						
					}else {
						g=1;
						break;
					}
				}
				
				if(g==0) {
					break p1;
				}
				
				
				int mex=0;
				HashMap<Integer,Integer> map=new HashMap<>();
				for(int i=0;i<n;i++) {
					map.put(arr[i], 1);
				}
				
				for(int i=0;i<=n;i++) {
					if(map.containsKey(mex)) {
						mex++;
					}
				}
				int in=-1;
				for (int i=0;i<n;i++) {
					if(visited[i]==0) {
						in=i;
						
					}
				}
				
				if(mex==n) {
					arr[in]=mex;
					visited[in]=1;
					list.add(in+1);
					
				}else {
					arr[mex]=mex;
					visited[mex]=1;
					list.add(mex+1);
				}
				
				
			}
			
			
			System.out.println(list.size());
			for(int i=0;i<list.size();i++) {
				System.out.print(list.get(i)+" ");
				 
			}
			System.out.println();
		
			
			
			
			
			
		}
		

	}
}