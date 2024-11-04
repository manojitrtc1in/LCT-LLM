

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
 
		int n=s.nextInt();
		pair[] arr=new pair[n];
		for(int i=0;i<n;i++) {
			String str=s.next();
			int ss=0;
			int hh=0;
			
			for(int j=0;j<str.length();j++) {
				if(str.charAt(j)=='s') {
					ss++;
				}else {
					hh++;
				}
			}
			
			pair ob=new pair(ss,hh,str);
			arr[i]=ob;
			
			
		}
		StringBuilder ans1=new StringBuilder();
		
		Arrays.sort(arr,new comp());
		
		for(int i=0;i<n;i++) {
			if(arr[i].hc==0)
			ans1.append(arr[i].str);
		}
		for(int i=0;i<n;i++) {
			if(arr[i].hc!=0&&arr[i].sc!=0)
			ans1.append(arr[i].str);
		}
		for(int i=0;i<n;i++) {
			if(arr[i].sc==0)
			ans1.append(arr[i].str);
		}
		
	
		int[] pre1=new int[ans1.length()];
		
		
		if(ans1.charAt(ans1.length()-1)=='h')
		pre1[ans1.length()-1]=1;
		
		for(int i=ans1.length()-2;i>=0;i--) {
			if(ans1.charAt(i)=='h') {
				pre1[i]=pre1[i+1]+1;
			}else {
				pre1[i]=pre1[i+1];
			}
		}
		
		
			
			
			
			long anss=0;
			
			
			for(int i=0;i<ans1.length();i++) {
				if(ans1.charAt(i)=='s') {
					anss=anss+pre1[i];
				}
			}
			
			
			System.out.println(Math.max(anss,-1));
			
			
		
		
		
		
		
		
		
		
	}
}

class pair{
	int sc;
	int hc;
	String str;
	public pair(int sc,int hc,String str) {
		this.sc=sc;
		this.hc=hc;
		this.str=str;
	}
}
class comp implements Comparator<pair>{
	public int compare(pair h,pair j) {
		if(h.sc*j.hc>j.sc*h.hc) {
			return -1;
		}else if(h.sc*j.hc==j.sc*h.hc) {
			return 0;
		}else {
			return 1;
		}
	}
}
