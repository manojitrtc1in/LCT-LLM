

import java.util.Arrays;
import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		
		int gmax=-1;
		int in=Integer.MAX_VALUE;
		
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		
		int sl=s.nextInt();
		int f=s.nextInt();
				
		int st=0;
		int end=f-sl-1;
		int ans=0;
		for(int i=0;i<end;i++) {
			ans=ans+arr[i];
		}
		if(gmax<ans) {
			gmax=ans;
			in=1;
		}
		while(st<n-1) {
			ans=ans-arr[st];
			st++;
			end++;
			if(end>=n) {
				end=0;
			}
			ans=ans+arr[end];
			if(gmax<ans) {
				gmax=ans;
				in=((sl-st+n)%n);
				if(in==0) {
					in=n;
				}
			}
			if(gmax==ans) {
				if(in>((sl-st+n)%n)){
					in=((sl-st+n)%n);
					if(in==0) {
						in=n;
					}
				}
			}
			
		}
		System.out.println(in);
		
		
		
		
	}
}