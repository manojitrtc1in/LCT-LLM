

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
			
		}
		
		ArrayList<Integer> list=new ArrayList<>();
		ArrayList<Integer> list2=new ArrayList<>();
		HashMap<Integer,Integer> map=new HashMap<>();
		
		int st=0; int end=0;
		if(n>1) {
		
		int g=0;
		while(end<n) {
			if(g==0) {
			if(map.containsKey(arr[end])) {
			map.put(arr[end], map.get(arr[end])+1);	
			}else {
			map.put(arr[end], 1);
			}
			
			}
			if(map.size()<=k) {
				
			
				end++;
				g=0;
			}else {
				list.add(end-st);
				list2.add(end);
				if(map.get(arr[st]).equals(1)) {
					map.remove(arr[st]);
				}else {
					map.put(arr[st], map.get(arr[st])-1);
				}
				st++;
                g=1;				
			}
			

		}
		list.add(end-st);
		list2.add(n);
		

		int max=-1,index=-1;
		for(int i=0;i<list.size();i++) {
			if(max<list.get(i)) {
				max=list.get(i);
				index=i;
			}
		}
		
		System.out.println(list2.get(index)-max+1+" "+list2.get(index));
		
		}else {
			System.out.println(1+" "+1);
		}
	 }
}