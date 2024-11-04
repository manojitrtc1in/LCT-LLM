

import java.util.PriorityQueue;
import java.util.Scanner;


public class b {
	
	
	public static void main(String[] args) {

		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		long k=s.nextLong();
		
		long[] arr=new long[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextLong();
			
		}
		
		long how=s.nextLong();
		long[] brr=new long[n];
		for(int i=0;i<n;i++) {
			brr[i]=s.nextLong();
		}
		
		
		PriorityQueue<Long> q=new PriorityQueue<>();
		long ans=0;
		int flag=0;
		for(int i=0;i<n;i++) {
			if(arr[i]<=k) {
				q.add(brr[i]);
			}else {
				q.add(brr[i]);
				long b=arr[i]-k;
		        long h=b/how;
		        k=k+h*how;
				if(b%how!=0) {
					h++;
					k=k+how;
				}
				
				if(q.size()<h) {
					flag=1;
					break;
				}
				int count=0;
				while(count<h) {
					
					ans=ans+q.poll();
					count++;
				}
				
				
				
			}
		}
		
		if(flag==0) {
		System.out.println(ans);
		}else {
			System.out.println(-1);
		}
	}
}