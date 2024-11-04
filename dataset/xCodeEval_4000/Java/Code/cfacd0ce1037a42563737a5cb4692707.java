

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		pair[] arr=new pair[n];
		for(int i=0;i<n;i++) {
			pair p=new pair(0,0);
			arr[i]=p;
		}
		for(int i=0;i<n;i++) {
			arr[i].a=s.nextInt();
			arr[i].b=s.nextInt();
		}
		
		Arrays.sort(arr,new comp());
		
		int count=0;
		pair ans=new pair(0,0);
		ans.a=arr[k-1].a;
		ans.b=arr[k-1].b;
		
		for(int i=0;i<arr.length;i++) {
			if(arr[i].a==ans.a&&arr[i].b==ans.b) {
				count++;
			}
		}
		
		
		System.out.println(count);
		
	 }
}

class pair{
	int a;
	int b;
	public pair(int a, int b) {
		this.a=a;
		this.b=b;
		
	}
}

class comp implements Comparator<pair>{
	public int compare(pair c,pair d) {
		if(c.a>d.a) {
			return -1;
		}else if(c.a<d.a) {
			return 1;
		}else {
			if(c.b>d.b) {
				return 1;
			}else  if(c.b<d.b){
				return -1;
			}else {
				return 0;
			}
		}
	}
	
}