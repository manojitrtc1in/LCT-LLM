

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
      
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			int n=s.nextInt();
			int[] arr=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			HashMap<Integer,Integer> map=new HashMap<>();
			int[] col=new int[n];
			
			map.put(2, 1);
			map.put(3, 2);
			map.put(5, 3);
			map.put(7, 4);
			map.put(11, 5);
			map.put(13, 6);
			map.put(17, 7);
			map.put(19, 8);
			map.put(23, 9);
			map.put(29, 10);
			map.put(31, 11);
			
			ArrayList<Integer> list=new ArrayList<>();
			for(int i=0;i<n;i++) {
				for(int j=1;j<=Math.sqrt(arr[i]);j++) {
					if(arr[i]%j==0) {
						if(map.containsKey(j)) {
							list.add(j);
							break;
									
						}
						
						if(map.containsKey(arr[i]/j)) {
							list.add(arr[i]/j);
							break;
						}
					}
				}
			}
			
			int count=1;
			


			HashMap<Integer,Integer> map2=new HashMap<>();
			for(int i=0;i<n;i++) {
				if(map2.containsKey(list.get(i))) {
					col[i]=map2.get(list.get(i));
				}else {
					col[i]=count;
					map2.put(list.get(i), count);
					count++;
				}
			}
			int max=-1;
			for(int i=0;i<n;i++) {
				if(col[i]>max) {
					max=col[i];
				}
			}
			
			System.out.println(max);
			for(int i=0;i<n;i++) {
				System.out.print(col[i]+" ");
			}
			System.out.println(); 
			
			
			
			
		}
	}
 }