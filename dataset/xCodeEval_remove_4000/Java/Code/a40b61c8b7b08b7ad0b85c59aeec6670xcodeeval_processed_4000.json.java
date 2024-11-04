


import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class k {
	 

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			int n=s.nextInt();
			int[] arr=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			
			Arrays.sort(arr);
			int flag=0;
			for(int i=1;i<n;i++) {
				if(arr[i]-arr[i-1]==1) {
					flag=1;
					break;
				}
			}
			if(flag==1) {
				System.out.println(2);
			}else {
				System.out.println(1);
			}
			
		}
		
	}
}