

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)	{
		
		Scanner s=new Scanner(System.in);
 
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {

			
			int n=s.nextInt();
			int[] arr=new int[n];
			long ans=0;
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
				if(i%2==0) {
					ans=ans+arr[i];
				}
			}
			
		
				ArrayList<Integer> right=new ArrayList<>();
				for(int i=0;i<n-1;i=i+2) {
					right.add(arr[i+1]-arr[i]);
				}
				ArrayList<Integer> left=new ArrayList<>();
				for(int i=0;i<n;i=i+2) {
				     if(i==0) {
				    	
				     }else {
				    	 left.add(arr[i-1]-arr[i]);
				     }
					
				}
				
				
				long ans1=kd(right);
				long ans2=kd(left);
				
				long h=Math.max(ans1, ans2);
				if(h>0) {
					ans=ans+h;
				}
				System.out.println(ans);
			
	
		}
	}
	public static long kd(ArrayList<Integer> list) {
		
		long max=Integer.MIN_VALUE;
		long sum=0;
		for(int i=0;i<list.size();i++) {
			if(sum+list.get(i)>=list.get(i)) {
				sum=sum+list.get(i);
			}else {
				sum=list.get(i);
			}
			max=Math.max(sum, max);
		}
		return max;
		
		
		
	}
}
		