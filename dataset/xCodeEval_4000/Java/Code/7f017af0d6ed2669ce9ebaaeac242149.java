

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
 
		int n=s.nextInt();
		int p=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		
		
		ArrayList<Integer > ans=new ArrayList<>();
		
		Arrays.sort(arr);
		
		long[] small=new long[4001];
		for(int i=1;i<4001;i++) {
			long count=0;
			for(int j=0;j<n;j++) {
				if(arr[j]<=i) {
					count++;
				}
			}
			small[i]=count;
		}
		
		for(int i=1;i<2001;i++) {
			
			
			long val=0;
			long v=0;
			int curr=i;
			int flag=0;
			p1:while(true) {
				if(curr>4000||small[curr]-v==0) {
					
					break;
				}
				
				val=(small[curr]-v);
				if(val%p==0) {
					flag=1;
					break p1;
				}
				curr++;
				v++;
				
			
				
			}
			
			if(v==n&&flag==0) {
				if(val%p==0) {
					
				}else {
					ans.add(i);
				}
			}
			
		}
		
		System.out.println(ans.size());
		for(int i=0;i<ans.size();i++) {
			System.out.print(ans.get(i)+" ");
		}
		
	}
}