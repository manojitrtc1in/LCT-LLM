

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class b {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		
		char[] arr=s.next().toCharArray();
		StringBuilder sb=new StringBuilder();
		
		int ans=0;
		sb.append(arr[0]);
		for(int i=1;i<n;i=i+2) {
			if(arr[i]!=sb.charAt(sb.length()-1)) {
				sb.append(arr[i]);
				if(i!=n-1)
				sb.append(arr[i+1]);
			}else {
			   ans++;
			   i--;
			}
			
		}
		
		
		if(sb.length()%2==0) {
			
		}else {
			ans++;
			sb.deleteCharAt(sb.length()-1);
		}
		System.out.println(ans);
		System.out.println(sb);
		
		
	}
}