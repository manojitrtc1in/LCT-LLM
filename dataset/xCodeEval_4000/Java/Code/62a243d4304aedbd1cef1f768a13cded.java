

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		StringBuilder sb=new StringBuilder();
		for(int ie=0;ie<t;ie++) {
			long n=s.nextLong();
			ArrayList<Long> list=new ArrayList<>();
			list.add(0l);
			HashMap<Long,Integer> map=new HashMap<>();
			for(long i=1;i<=Math.sqrt(n);i++) {
				if(!map.containsKey(i)) {
					map.put(i, 1);
					list.add(i);
					
				}
				if(!map.containsKey(n/i)) {
					map.put(n/i, 1);
					list.add(n/i);
				}
				
			}
			
			Collections.sort(list);
			sb.append(list.size()+"\n");
			for(int i=0;i<list.size();i++) {
				sb.append(list.get(i)+" ");
			}
			sb.append("\n");
		
			
			
			
		}
		
		System.out.println(sb);
		
	 }
}