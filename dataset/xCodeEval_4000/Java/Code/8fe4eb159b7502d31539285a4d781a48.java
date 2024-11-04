

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		

			int n=s.nextInt();
			long ans=0;
			long[] arr=new long[n];
			
			for(int i=0;i<n;i++) {
				arr[i]=s.nextLong();
			}
			
			
			for(int i=0;i<n;i++) {
				for(int j=i;j<n;j++) {
					for(int k=j;k<n;k++) {
						ans=Math.max(ans, arr[i]|arr[j]|arr[k]);
					}
				}
			}
			
			System.out.println(ans);
			
		}
	}
