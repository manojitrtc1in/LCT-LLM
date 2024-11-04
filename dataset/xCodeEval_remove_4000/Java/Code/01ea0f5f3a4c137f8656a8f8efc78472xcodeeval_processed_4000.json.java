

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int k=s.nextInt();
			HashMap<Integer,Integer> map=new HashMap<>();
			Integer[] arr=new Integer[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
				map.put(arr[i], 1);
			}
	
			
			if(map.size()==1) {
				if(arr[0]==k) {
					System.out.println(0);
				}else {
					System.out.println(2);
				}
			}else {
				
				int d=0;
				for(int i=0;i<n;i++) {
					d=d+k-arr[i];
				}
				
				
				if(d==0) {
					System.out.println(1);
				}else if(map.containsKey(k)){
					System.out.println(1);
				}else {
					System.out.println(2);
				}
				
				
			}
			
			
			
			
		
		}
	}
}
	