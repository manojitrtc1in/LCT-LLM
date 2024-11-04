

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int m=s.nextInt();
		int[] arr=new int[n];
		int[] brr=new int[m];
		
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
			
		}
		for(int i=0;i<m;i++) {
			brr[i]=s.nextInt();
			
		}
		
		
		int st=0;
		int end=0;
		int curr=brr[0];
		int ans=0;
		while(st<n&&end<m) {
			if(arr[st]<=curr) {
				ans++;
				end++;
				st++;
				if(end<m)
				curr=brr[end];
			}else {
				
				st++;
			}
		}
		System.out.println(ans);
		
		
	}
}