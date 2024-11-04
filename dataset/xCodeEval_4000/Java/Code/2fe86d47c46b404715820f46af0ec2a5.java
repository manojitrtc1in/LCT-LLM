

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int p=s.nextInt();
			int k=s.nextInt();
			
			Integer[] arr=new Integer[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			int h=p;
			int ans1=0;
			Arrays.sort(arr);
			int flag=0;
			int st=k-1;
			while(flag==0&&st<n) {
				if(h>=arr[st]) {
					ans1=ans1+k;
					h=h-arr[st];
					st=st+k;
				}else {
					break;
				}
			}
			
			
			
			
			int sum=0;
			
		
		for(int i=0;i<k-1;i++) {
		sum=sum+arr[i];
		int he=p;
		int ans2=0;
			if(sum<=he) {
				ans2=ans2+i+1;
				he=he-sum;
			}
			
			st=k+i;
			while(flag==0&&st<n) {
					if(he>=arr[st]) {
						he=he-arr[st];
						ans2=ans2+k;
						st=st+k;
					}else{
						break;
					}
				}
			
			ans1=Math.max(ans1, ans2);
		}
				
			
			
			
			System.out.println(ans1);
			
			
			
			
			
		}
		
		
	}
}