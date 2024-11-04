

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class k{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
		
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int[] arr=new int[n];
			
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			HashMap<Integer,ArrayList<Integer>> map=new HashMap<>();
			
			for(int i=0;i<n;i++) {
				if(map.containsKey(arr[i])) {
					ArrayList<Integer> p=map.get(arr[i]);
					p.add(i);
				}else {
					ArrayList<Integer > listy=new ArrayList<>();
					listy.add(i);
					listy.add(-1);
					listy.add(n);
					map.put(arr[i], listy);
				}
			}
			
			
			int ans=Integer.MAX_VALUE;
			for(Map.Entry<Integer, ArrayList<Integer> >entry: map.entrySet()) {
				
				Collections.sort(entry.getValue());
				int max=0;
				for(int i=0;i<entry.getValue().size()-1;i++) {
					if( entry.getValue().get(i+1)-entry.getValue().get(i)>1) {
						max++;
					}
				}
				ans=Math.min(ans, max);
				
			}
			
			System.out.println(ans);
			
			
		}
		
	}
}