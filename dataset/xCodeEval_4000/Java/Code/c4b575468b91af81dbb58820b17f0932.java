

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) {

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			char[] arr=s.next().toCharArray();
			ArrayList<pair> list=new ArrayList<>();
			for(int i=0;i<n;i++) {
			StringBuilder sb=new StringBuilder();
			for(int j=i;j<n;j++) {
				sb.append(arr[j]);
			}
			
			
				if((n-i)%2==0) {
					for(int j=0;j<i;j++) {
						sb.append(arr[j]);
					}
				}else {
					for(int j=i-1;j>=0;j--) {
						sb.append(arr[j]);
					}
				}
			pair ob=new pair(sb.toString(),i+1);
			list.add(ob);	
			}
			
			Collections.sort(list,new comp());
			System.out.println(list.get(0).str);
			System.out.println(list.get(0).a);
			
			
			
			
		}
		
	}
}
class pair{
	String str;
	int a;
	public pair(String str,int a) {
		this.str=str;
		this.a=a;
	}
}
class comp implements Comparator<pair>{
	
	public int compare(pair h,pair j) {
		return h.str.compareTo(j.str);
	}
}