

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int m=2*n-2;
		pair[] arr=new pair[m];
		for(int i=0;i<m;i++) {
			String str=s.next();
			pair ob=new pair(str,str.length(),'a',i);
			arr[i]=ob;
		}
		
		Arrays.sort(arr,new comp());
		
		String st=arr[m-2].str;
		
		for(int i=0;i<4;i++) {
			int g=0;
			String sta=st;
			
			
			if(i==0) {
				sta=sta+arr[0].str;
			}else if(i==1) {
				sta=sta+arr[1].str;
			}else if(i==2) {
				sta=arr[0].str+sta;
			}else {
				sta=arr[1].str+sta;	
			}
			
			HashMap<String,Integer> map=new HashMap<>();
			for(int j=0;j<m;j++) {
				if(map.containsKey(arr[j].str)) {
					map.put(arr[j].str, map.get(arr[j].str)+1);
				}else {
					map.put(arr[j].str, 1);
				}
			}
			
			String temp="";
			for(int j=0;j<n-1;j++) {
				temp=temp+sta.charAt(j);
				if(map.containsKey(temp)) {
					if(map.get(temp)==1) {
						map.remove(temp);
					}else {
						map.put(temp, map.get(temp)-1);
					}
				}else {
					g=1;
					break;
				}
			}
			StringBuilder sb6=new StringBuilder();
			for(int j=1;j<n;j++) {
				sb6.append(sta.charAt(j));
			}
			int hi=sb6.length();
			for(int j=0;j<hi;j++) {
				if(map.containsKey(sb6.toString())) {
					if(map.get(sb6.toString())==1) {
						map.remove(sb6.toString());
					}else {
						map.put(sb6.toString(), map.get(sb6.toString())-1);
					}
				}else {
					g=1;
					break;
				}
			
				sb6.deleteCharAt(0);
				
			}
			
			
			if(g==0) {
				st=sta;
				break;
			}
			
			
				
		}
		
		

		
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<st.length();i++) {
			sb.append(st.charAt(i));
			int flag=0;
			for(int j=0;j<m;j++) {
				if(arr[j].size==sb.length()) {
					
					if(arr[j].str.equals(sb.toString())&&flag==0){
						arr[j].ch='P';
						flag=1;
					}else if(flag==1||!arr[j].str.equals(sb.toString())){
						arr[j].ch='S';
					}
					
				}
			}
			
			
			
		}
		Arrays.sort(arr,new comp2());
		for(int i=0;i<m;i++) {
			System.out.print(arr[i].ch); 
			
		}
		
		
		
	}
}
class pair{
	String str;
	int size;
	char ch;
	int in;
	public pair(String str,int size,char ch,int in) {
		this.str=str;
		this.size=size;
		this.ch=ch;
		this.in=in;
	}
}


class comp implements Comparator<pair>{
	public int compare(pair h,pair j) {
		if(h.size<j.size) {
			return -1;
		}else if(h.size==j.size) {
			return 0;
		}else {
			return 1;
		}
	}
	
}
class comp2 implements Comparator<pair>{
	public int compare(pair h,pair j) {
		if(h.in<j.in) {
			return -1;
		}else if(h.size==j.size) {
			return 0;
		}else {
			return 1;
		}
	}
	
}