

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)	{
		
		Scanner s=new Scanner(System.in);
 
		StringBuilder sb=new StringBuilder();
		int n=s.nextInt();
		HashMap<Integer,ArrayList<String>> map=new HashMap<>();
		String vo="aeiou";
		for(int ie=0;ie<n;ie++) {
		String str=s.next();
		int v=0;
		for(int i=0;i<str.length();i++) {
			for(int j=0;j<vo.length();j++) {
				if(str.charAt(i)==vo.charAt(j)) {
					v++;
				}
			}
		}
		
		if(map.containsKey(v)) {
			ArrayList<String> p=map.get(v);
			p.add(str);
			map.put(v, p);
			
		}else {

			ArrayList<String> list=new ArrayList<>();
			list.add(str);
			map.put(v, list);
		}
		
	
		}
	
		int ans=0;
		ArrayList<String> te=new ArrayList<>();
		ArrayList<String> fu=new ArrayList<>();
		for(Map.Entry<Integer,ArrayList<String>> entry:map.entrySet()) {
			HashMap<Character,ArrayList<String>> map2=new HashMap<>();
            
			for(int i=0;i<entry.getValue().size();i++) {
				char v='z';
				for(int j=0;j<entry.getValue().get(i).length();j++) {
					for(int k=0;k<vo.length();k++) {
						if(entry.getValue().get(i).charAt(j)==vo.charAt(k)) {
							v=vo.charAt(k);
						}
					}
				}
				
				if(map2.containsKey(v)) {
					ArrayList<String> x=map2.get(v);
					x.add(entry.getValue().get(i));
					map2.put(v, x);
				}else{
					ArrayList<String >kl=new ArrayList<>();
					kl.add(entry.getValue().get(i));
					map2.put(v, kl);
				}
				
				
			}
			
			ArrayList<String> t=new ArrayList<>();
			ArrayList<String> f=new ArrayList<>();
			

			
			for(Map.Entry<Character,ArrayList<String>> e:map2.entrySet()) {
				
				for(int i=0;i<e.getValue().size()-e.getValue().size()%2;i++) {
					f.add(e.getValue().get(i));
				}
				if(e.getValue().size()%2==1) {
				t.add(e.getValue().get(e.getValue().size()-1));
				}
				
			}
			
			
			for(int i=0;i<f.size();i++) {
				fu.add(f.get(i));
			}
			for(int i=0;i<t.size()-t.size()%2;i++) {
				te.add(t.get(i));
			}
			
			
		}
		
		
		int st=0;
		while(st<te.size()&&st<fu.size()) {
			ans++;
			sb.append(te.get(st)+" "+fu.get(st)).append("\n");
			st++;
		}
		ans=ans/2;
		for(int i=0;i<(fu.size()-te.size())/4;i++) {
			sb.append(fu.get(st)+" "+fu.get(st+2)).append("\n");
			st++;
			
			sb.append(fu.get(st)+" "+fu.get(st+2)).append("\n");
			st=st+3;
			ans++;
		}
		System.out.println(ans);
		System.out.println(sb);
		
		
		
		
	}
}