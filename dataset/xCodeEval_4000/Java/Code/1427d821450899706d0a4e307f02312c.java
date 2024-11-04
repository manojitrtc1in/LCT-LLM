

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		
		ArrayList[] arr=new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			ArrayList<Integer> lit=new ArrayList<>();
			arr[i]=lit;
		}
		
		for(int i=0;i<n-2;i++) {
			
			int a=s.nextInt();
			int b=s.nextInt();
			int c=s.nextInt();
			
			arr[b].add(a);
			arr[b].add(c);
			arr[a].add(b);
			arr[a].add(c);
			arr[c].add(a);
			arr[c].add(b);
			
			
		}
		
		HashMap<Integer,Integer> map=new HashMap<>();
		
		int index=-1;
		for(int i=0;i<n+1;i++) {
			if(arr[i].size()==2) {
				index=i;
				break;
			}
		}
		int[] ans=new int[n];	
		ans[0]=index;
		map.put(index, 1);
		map.put((int)arr[index].get(1), 1);
		map.put((int)arr[index].get(0), 1);
		if(arr[(int)arr[index].get(0)].size()>arr[(int)arr[index].get(1)].size()) {
			ans[1]=(int)arr[index].get(1);
			ans[2]=(int)arr[index].get(0);
			
		}else {
			ans[1]=(int)arr[index].get(0);
			ans[2]=(int)arr[index].get(1);	
		}
		
		for(int i=1;i<n-1;i++) {
			for(int j=0;j<arr[ans[i]].size();j++) {
				if(!map.containsKey((int)arr[ans[i]].get(j))) {
					ans[i+2]=(int)arr[ans[i]].get(j);
					map.put((int)arr[ans[i]].get(j), 1);
					
				}
			}
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(ans[i]+" ");
		}
	 }
}