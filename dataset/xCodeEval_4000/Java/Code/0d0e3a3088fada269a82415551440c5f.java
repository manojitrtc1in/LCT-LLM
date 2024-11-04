
import java.awt.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			char[] arr=s.next().toCharArray();
			StringBuilder sb=new StringBuilder();
			HashMap<Integer,Integer> map=new HashMap<>();
			HashMap<Character,Integer> map2=new HashMap<>();
			int count=1;
			int in=0;
			for(int i=0;i<arr.length-1;i++) {
				if(arr[i]==arr[i+1]) {
					count++;
				}else {
					
					sb.append(arr[i]);
					map.put(in, count);
					in++;
					count=1;
				}
				
				
			}
			
			map.put(in, count);
			sb.append(arr[arr.length-1]);
		

			

			int min=10000000;
			int st=0;
			

			int end=2;
			if(sb.length()<3) {
				System.out.println(0);
			}else {
				int ans=10000000;
				map2.put(sb.charAt(0), 1);
				map2.put(sb.charAt(1), 1);
				map2.put(sb.charAt(2), 1);
				if(map2.size()==3) {
				ans=1+map.get(1)+1;
				}
				ArrayList<Integer> k=new ArrayList<>();
			
			k.add(ans);
			

				while(end<sb.length()-1) {
				
			map2.remove(sb.charAt(st));
			
				st++;
				map2.put(sb.charAt(st), 1);
				map2.put(sb.charAt(st+1), 1);
				end++;
				map2.put(sb.charAt(end), 1);
				if(map2.size()==3) {
					
					ans=2+map.get(st+1);
					k.add(ans);
					
					
				}
				
				
				
				
			}
				Collections.sort(k);
				if(k.get(0)!=10000000) {
					System.out.println(k.get(0));
				}else {
					System.out.println(0);
				}
			
			
			}
			
			
					
		}
	}
}