

import java.util.Scanner;
import java.util.Stack;

public class Main {
	
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		char[] arr=s.next().toCharArray();
		
		StringBuilder sb=new StringBuilder();
		StringBuilder sb1=new StringBuilder();
		StringBuilder sb2=new StringBuilder();
		
		if(arr.length%n!=0) {
			
			for(int i=0;i<1+(arr.length/n);i++) {
				for(int j=0;j<n;j++) {
					if(j==0) {
						sb.append(1);
					}else {
						sb.append(0);
					}
				}
			}
			
			System.out.println(sb);
			
		}else {
			for(int i=0;i<1+(arr.length/n);i++) {
				for(int j=0;j<n;j++) {
					if(j==0) {
						sb2.append(1);
					}else {
						sb2.append(0);
					}
				}
			}
			
			
			for(int i=0;i<n;i++) {
				if(i==n-1) {
					if(arr[i]-'0'+1==10) {
						int c=1;
						int count=sb.length();
						sb.append(0);
						while(c!=0) {
							count--;
							if(count>=0) {
							if(sb.charAt(count)-'0'+1==10) {
								c=1;
								sb.setCharAt(count, '0');
							}else {
								sb.setCharAt(count, (char)((sb.charAt(count)-'0'+1)+'0'));
								c=0;
							}
							}else {
								sb.insert(0, '1');
								c=0;
							}
						}
					}else {
						sb.append(arr[i]-'0'+1);
					}
					sb1.append(arr[i]);
				}else {
					sb.append(arr[i]);
					sb1.append(arr[i]);
				}
			}
			
			if(sb.length()==n) {
			int h=sb1.length();
			for(int i=0;i<(arr.length/n)-1;i++) {
				
				for(int j=0;j<h;j++) {
					sb.append(sb.charAt(j));
				}
				for(int j=0;j<h;j++) {
					sb1.append(sb1.charAt(j));
				}
				
			}
			int flag=0;
			for(int i=0;i<arr.length;i++) {
				if(sb1.charAt(i)-'0'>arr[i]-'0'){
					flag=2;
					break;
				}else if(sb1.charAt(i)-'0'==arr[i]-'0') {
					flag=1;
				}else {
					break;
				}
			
		}
			

			if(flag==2) {
				System.out.println(sb1);
			}else {
				System.out.println(sb);
			}
			}else {
				
				
				
				int h=sb1.length();
				for(int i=0;i<(arr.length/n)-1;i++) {
					
					
					for(int j=0;j<h;j++) {
						sb1.append(sb1.charAt(j));
					}
					
				}
				int flag=0;
				for(int i=0;i<arr.length;i++) {
					if(sb1.charAt(i)-'0'>arr[i]-'0'){
						flag=2;
						break;
					}else if(sb1.charAt(i)-'0'==arr[i]-'0') {
						flag=1;
					}else {
						break;
					}
				
			}
				

				if(flag==2) {
					System.out.println(sb1);
				}else {
					System.out.println(sb2);
				}
				
				
			}
		
	}
}
}