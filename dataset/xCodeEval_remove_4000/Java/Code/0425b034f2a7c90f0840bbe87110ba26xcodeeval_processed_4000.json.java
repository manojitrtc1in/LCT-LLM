

import java.util.Arrays;
import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		int flag=0;
		for(int i=k-1;i<n;i++) {
		
			if(arr[i]==arr[k-1]) {
				
			}else {
				flag=1;
				break;
			}
		}
		
		if(flag==1) {
			System.out.println(-1);
		}else {
			int in=-1;
			for(int i=0;i<k;i++) {
				if(arr[i]!=arr[k-1]) {
					in=i;
				}
			}
			
			System.out.println(in+1);
			
		}
				
 
	}
}