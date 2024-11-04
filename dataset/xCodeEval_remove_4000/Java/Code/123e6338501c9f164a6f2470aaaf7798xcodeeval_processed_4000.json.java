
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
			if(arr.length<=2) {
				System.out.println(0);
			}else {
				int min=Integer.MAX_VALUE;
				int st=0;
				int end=1;
				HashMap<Character,Integer> map=new HashMap<>();
				
				map.put(arr[0], 1);
				if(map.containsKey(arr[1])) {
					map.put(arr[1], map.get(arr[1])+1);
				}else {
					map.put(arr[1], 1);
				}
				
				while(end<arr.length) {
				
					if(map.size()<3&&end<arr.length-1) {
						end++;
						if(map.containsKey(arr[end])) {
							map.put(arr[end], map.get(arr[end])+1);
						}else {
							map.put(arr[end], 1);
						}
					}else {
						if(map.size()==3) {
						min=Math.min(min, end-st+1);
						
						if(map.get(arr[st])!=1) {
							map.put(arr[st], map.get(arr[st])-1);
						}else {
							map.remove(arr[st]);
						}
						st++;
						}else {
							break;
						}
					}
					
					
					
				}
				
				if(min!=Integer.MAX_VALUE)
				System.out.println(min);
				else
					System.out.println(0);
				
				
			}
					
		}
	}
}