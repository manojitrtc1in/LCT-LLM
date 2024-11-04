

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){

		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		Integer[] arr=new Integer[n];
		int[] ans=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		
		Arrays.sort(arr);
		int st=0;
		if(n%2==0) {
			st=n/2-1;
			System.out.println(n/2-1);
		}else {
			st=n/2;
			System.out.println(n/2);
		}
		st--;
		int g=st+1;
		int curr=1;
		for(int i=0;i<g;i++) {
			
			ans[curr]=arr[st];
			curr=curr+2;
			st--;
		}
		g=n-1;
		for(int i=0;i<n;i++) {
			if(ans[i]==0) {
				ans[i]=arr[g];
				g--;
			}
		}
		
		
		
		for(int i=0;i<n;i++) {
			System.out.print(ans[i]+" ");
		}
	
	}
}