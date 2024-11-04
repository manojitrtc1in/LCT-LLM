

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		
		for(int ie=0;ie<t;ie++) {
			int n=s.nextInt();

			HashMap<Integer,Integer> map=new HashMap<>();
			
			int[] arr=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
				if(map.containsKey(arr[i])) {
					map.put(arr[i], map.get(arr[i])+1);
				}else {
					map.put(arr[i], 1);
				}
			}
			Arrays.sort(arr);
			
			for(int i=0;i<map.get(arr[n-1]);i++) {
				System.out.print(arr[n-1]+" ");
				
			}
			
			map.remove(arr[n-1]);
			int curr=arr[n-1];
			while(map.size()>0){
				
				int max=-1;
				int val=-1;
				for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
					
					if(gcd(entry.getKey(),curr)>max) {
						max=gcd(entry.getKey(),curr);
						val=entry.getKey();
					}
					
					
				}
				
				for(int i=0;i<map.get(val);i++) {
					System.out.print(val+" ");
				}
				curr=gcd(val,curr);
				map.remove(val);
			
				
			}
			
			System.out.println();
			
			
		}
	}
	public static int gcd(int a,int b) {
		if(b==0) {
			return a;
		}
		return gcd(b,a%b);
	}
}