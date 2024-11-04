

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class b {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		
		for(int ie=0;ie<t;ie++) {
			
			char[] arr=s.next().toCharArray();
			int ans=0;
			int n=arr.length;
			
			int[] pre=new int[n];
		
			
			for(int i=1;i<n;i++) {
				if(arr[i-1]=='0') {
					pre[i]=pre[i-1]+1;
				}else {
					pre[i]=0;
				}
			}
			
			for(int i=1;i<Math.min(arr.length+1,20);i++) {
				StringBuilder sb=new StringBuilder();
				for(int j=0;j<i;j++) {
					sb.append(arr[j]);
				}
				if(arr[0]=='1') {
				if(Long.parseLong(sb.toString(), 2)==i) {
					ans++;
					
				}
				}
			int st=1;
				int end=i;
				
				while(end<arr.length) {
					
					
					sb.deleteCharAt(0);
					sb.append(arr[end]);
					if(arr[st]=='1') {
					if(Long.parseLong(sb.toString(), 2)==i) {
						ans++;
						

					}else if(arr[st]=='1') {
						if(Long.parseLong(sb.toString(), 2)<=i+pre[st]) {
							ans++;
						}
					}
					st++;
					end++;
					
				}else {
					st++;
					end++;
				}
				}
				
			}
			System.out.println(ans);
			
			
		}
		
	}
}