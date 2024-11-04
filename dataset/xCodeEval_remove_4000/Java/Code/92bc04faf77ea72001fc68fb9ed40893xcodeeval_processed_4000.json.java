
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int m=s.nextInt();
		ArrayList[] arr=new ArrayList[n+1];
		for(int i=0;i<n+1;i++) {
			ArrayList<Integer> list=new ArrayList<>();
			arr[i]=list;
		}
		for(int i=0;i<m;i++) {
			int a=s.nextInt();
			int b=s.nextInt();
			arr[a].add(b);
			
		}
		
		HashMap<Integer,Integer> map=new HashMap<>();
		
	
		for(int i=1;i<n+1;i++) {
			int min=Integer.MAX_VALUE;
		for(int j=0;j<arr[i].size();j++) {
			int g=(int)arr[i].get(j)-i;
			if(g<0) {
				g=n+g;
			}
		min=Math.min(min,g);
			
		}
		map.put(i, min);
		}
		
		for(int k=1;k<n+1;k++) {
			int gmax=Integer.MIN_VALUE;
			
			
		for(int i=1;i<n+1;i++) {
			int ans=0;
			ans=ans+i-k;
			if(i-k<0) {
				ans=ans+n;
			}
			
			if(arr[i].size()!=0) {
			ans=ans+n*(arr[i].size()-1);
			
			ans=ans+map.get(i);
			

			gmax=Math.max(gmax, ans);
			}
		}
		System.out.print(gmax+" ");
		
			
	}
	}
}