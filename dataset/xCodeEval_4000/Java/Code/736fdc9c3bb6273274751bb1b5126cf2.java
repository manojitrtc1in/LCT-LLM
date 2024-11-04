

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
			
		}
		if(n==1) {
			System.out.println(0);
		}else {
		
		int gmax=Integer.MIN_VALUE;
		
		for(int i=-30;i<=30;i++) {
			int[] brr=new int[n];
			for(int j=0;j<n;j++) {
				brr[j]=arr[j];
			}
			
			for(int j=0;j<n;j++) {
				if(brr[j]>i) {
					brr[j]=-1000000;
				}
			}
			
			int max=-1000000;
			int sum=brr[0];
			for(int j=1;j<n;j++) {
				if(sum+brr[j]<brr[j]) {
					sum=brr[j];
				}else {
					sum=sum+brr[j];
				}
				
				max=Math.max(max, sum);
				
			}
			
			gmax=Math.max(gmax, max-i);
			
			
			
			
		}
		
		System.out.println(gmax);
		}
	}
}