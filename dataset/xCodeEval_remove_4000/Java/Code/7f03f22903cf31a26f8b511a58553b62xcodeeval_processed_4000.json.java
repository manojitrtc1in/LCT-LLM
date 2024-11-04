

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			int n=s.nextInt();
			int[] arr=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			int min=Integer.MAX_VALUE;
			
			int st=0;
			int end=1;
			HashMap<Integer,Integer> map=new HashMap<>();
			map.put(arr[0], 1);
			if(arr.length<2) {
				System.out.println(-1);
			}else {
				while(end<n) {
					if(map.containsKey(arr[end])){
						if(min>end-st) {
							min=end-st;	
							}
						if(map.get(arr[st])==1) {
							map.remove(arr[st]);
						}else {
							map.put(arr[st], map.get(arr[st])-1);
						}
						st++;
					}else {
						map.put(arr[end], 1);
						end++;
					}
					

				}
				if(min!=Integer.MAX_VALUE)
				System.out.println(min+1);
				else
					System.out.println(-1);
			}
			
			
			
		}
		
	 }
}