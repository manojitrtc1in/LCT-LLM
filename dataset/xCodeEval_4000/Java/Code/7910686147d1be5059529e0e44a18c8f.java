

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class b {

static int flag=0;	
static int count=0;
	public static void main(String[] args) throws Exception{

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int m=s.nextInt();
			
			ArrayList[] arr=new ArrayList[n+1];
			
			for(int i=0;i<n+1;i++) {
				ArrayList<Integer> list=new ArrayList<>();
				arr[i]=list;
			}
			
			
			int[][] in=new int [m][3];
			
			for(int i=0;i<m;i++) {
				int a=s.nextInt();
				int b=s.nextInt();
				int c=s.nextInt();
				in[i][0]=a;
				in[i][1]=b;
				in[i][2]=c;
				if(a==0) {
					
				}else {
					arr[b].add(c);
				}
				
			}
			
			int[] visited=new int[n+1];
			int[] instack=new int[n+1];
			flag=0;
			count=0;
			HashMap<Integer,Integer> map=new HashMap<>();
			for(int i=1;i<n+1;i++) {
				if(flag==1) {
					break;
				}else {
					
					if(visited[i]==0) {
						topo(arr,visited,instack,map,i);
					}
					
				}
			}
			
			
			if(flag==0) {
				System.out.println("YES");
				for(int i=0;i<m;i++) {
					if(in[i][0]==0) {
						if(map.get(in[i][1])>map.get(in[i][2])) {
							System.out.println(in[i][1]+" "+in[i][2]);
							
						}else {
							System.out.println(in[i][2]+" "+in[i][1]);
						}
					}else {
						System.out.println(in[i][1]+" "+in[i][2]);
					}
				}
				
			}else {
				System.out.println("NO");
			}
			
			
			
			
			
			
		}
		
		
	}
	public static void topo(ArrayList[] arr,int[] visited,int[] instack,HashMap<Integer,Integer> map,int start) {
		
		visited[start]=1;
		instack[start]=1;
		
		
		for(int i=0;i<arr[start].size();i++) {
			int curr=(int)arr[start].get(i);
			
			if(visited[curr]==0) {
				
				topo(arr,visited,instack,map,curr);
			}else {
				if(instack[curr]==1) {
					flag=1;
					return;
				}
			}
		}
		
		instack[start]=0;
		map.put(start,count);
		count++;
		
				
	}
	
}
