

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){

		Scanner s=new Scanner(System.in);
		
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int k=s.nextInt();
			
			Integer[] arr=new Integer[n];
			
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			for(int i=0;i<n;i++) {
				   s.nextInt();
			}
			Arrays.sort(arr);
			int[] pre=new int[n];
			int st=0;
			pre[0]=1;
			int anss=1;
			for(int i=1;i<n;i++) {
				
				if(arr[st]+k>=arr[i]) {
					anss++;
					pre[i]=Math.max(anss, pre[i-1]);
					
				}else {
					
					while(arr[st]+k<arr[i]) {
						st++;
						anss--;
					}
					anss++;
					pre[i]=Math.max(pre[i-1], anss);
					
				}
				
			}
			
			int[] suff=new int[n];
			suff[n-1]=1;
			anss=1;
			st=n-1;
			for(int i=n-2;i>=0;i--) {
				
				if(arr[st]-k<=arr[i]) {
					anss++;
					suff[i]=Math.max(anss, suff[i+1]);
					
				}else {
					
					while(arr[st]-k>arr[i]) {
						st--;
						anss--;
					}
					anss++;
					suff[i]=Math.max(suff[i+1], anss);
					
				}
				
			}
			
			


















			int ans=0;
			for(int i=0;i<n-1;i++) {
				ans=Math.max(ans, pre[i]+suff[i+1]);
			}
			
			if(n!=1)
			System.out.println(ans);
			else
				System.out.println(1);
			
			
			
			
			
		}
		
	}
}