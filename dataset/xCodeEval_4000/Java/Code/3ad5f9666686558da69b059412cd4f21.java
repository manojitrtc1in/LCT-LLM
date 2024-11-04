

import java.util.Arrays;
import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
 
		int n=s.nextInt();
		int k=s.nextInt();
		int l=s.nextInt();
		int m=n*k;
		Long[] arr=new Long[m];
		
		for(int i=0;i<m;i++) {
			arr[i]=s.nextLong();
			
		}
		
		long ans=0;
		
		Arrays.sort(arr);
			int how=n;
		int end=m-1;
		int count=0;
		while(how>1&&end>0) {
			if(arr[end]-arr[0]<=l) {
				if(count>=k-1) {
					count=count-k+1;
					count=Math.max(count, 0);
					
					ans=ans+arr[end];
					end--;
					how--;
				}else {
					end--;
					count++;
				}
			}else {
				end--;
				count++;
			}
				
		}
		
		how--;
		if(how==0)
		System.out.println(ans+arr[0]);
		else {
			System.out.println(0);
		}
				
	}
}