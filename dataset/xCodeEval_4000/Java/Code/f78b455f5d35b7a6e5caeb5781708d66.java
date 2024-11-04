

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		char[] arr=s.next().toCharArray();

		int flag=0;
		int z=0,o=0,t=0;
		StringBuilder sb=new StringBuilder();
	     int in=-1;
		for(int i=0;i<arr.length;i++) {
			if(flag==0) {
				if(arr[i]=='0') {
					z++;
				}
			}
			
			if(arr[i]=='2') {
				in=i;
				flag=1;
				break;
			}
		}
		for(int i=0;i<z;i++) {
			sb.append(0);
		}
		int n=arr.length;
		for(int i=0;i<n;i++) {
			if(arr[i]=='1') {
				sb.append(1);
			}
		}
		
		if(in!=-1) {
		for(int i=in;i<n;i++) {
			if(arr[i]=='2') {
				sb.append(2);
			}else if(arr[i]=='0') {
				sb.append(0);
			}
		}
		}
		System.out.println(sb);
		
		
		
		
		
	}
	
}