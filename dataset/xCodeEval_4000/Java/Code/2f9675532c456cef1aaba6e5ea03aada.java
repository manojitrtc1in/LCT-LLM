

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
		
			char[] arr=s.next().toCharArray();
			int x=0;
			int y=0;
			long ans=0;
			int g=0;int h=0;
			
			HashMap<String,ArrayList<String>> map=new HashMap<>();
			ArrayList<String> listt=new ArrayList<>();
			map.put(0+" "+0, listt);
			for(int i=0;i<arr.length;i++) {
				
				if(arr[i]=='N') {
					y++;
				}else if(arr[i]=='S') {
					y--;
				}else if(arr[i]=='E') {
					x++;
				}else if(arr[i]=='W') {
					x--;
				}
				
				if(map.containsKey(x+" "+y)) {
					int flag=0;
					for(int j=0;j<map.get(x+" "+y).size();j++) {
						if(map.get(x+" "+y).get(j).equals(g+" "+h)) {
							flag=1;
						}
					}
					
					if(flag==1) {
						ans++;
					}else {
						ans=ans+5;
						ArrayList<String > p=map.get(x+" "+y);
						p.add(g+" "+h);
						map.put(x+" "+y, p);
						ArrayList<String> ff=map.get(g+" "+h);
						ff.add(x+" "+y);
						map.put(g+" "+h, ff);
					}
					
				}else {
					ans=ans+5;
					ArrayList<String> list=new ArrayList<>();
					list.add(g+" "+h);
					map.put(x+" "+y, list);
					ArrayList<String> listtt=map.get(g+" "+h);
					listtt.add(x+" "+y);
					map.put(g+" "+h, listtt);
				}
				g=x;
				h=y;
				

			}
			
			System.out.println(ans);
			
			
		}
	}
}