

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] arr=new int[n];
		int[] brr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		for(int i=0;i<n;i++) {
			brr[i]=s.nextInt();
		}
		 HashMap<Integer,Integer> map=new HashMap<>();
		int st=0;
		int end=0;
		while(st<n&&end<n) {
			if(brr[end]==arr[st]) {
				st++;
				end++;
			}else {
				
				if(!map.containsKey(arr[st])) {
					map.put(brr[end], 1);
				end++;
				}else {
					st++;
				}
			}
			

		}
		System.out.println(map.size());
		
		
		
	 }
}