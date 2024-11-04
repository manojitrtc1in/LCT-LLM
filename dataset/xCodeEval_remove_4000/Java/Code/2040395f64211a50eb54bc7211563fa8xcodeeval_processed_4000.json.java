

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
			int st=1;
			while(flag==0&&st<n) {
				if(h>=arr[st]) {
					ans1=ans1+2;
					h=h-arr[st];
					st=st+2;
				}else {
					break;
				}
			}
			
			
			int ans2=0;
			
			if(p>=arr[0]) {
				
				p=p-arr[0];
				ans2++;
				st=2;
				flag=0;
				while(flag==0&&st<n) {
					if(p>=arr[st]) {
						p=p-arr[st];
						ans2=ans2+2;
						st=st+2;
					}else{
						break;
					}
				}
				
			}else {
				
			}
			
			
			System.out.println(Math.max(ans1, ans2));
			
			
			
			
			
		}
		
		
	}
}