

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b{
	
	public static void main(String[] args) throws Exception 
	{
		Scanner s=new Scanner(System.in);
	StringBuilder sb=new StringBuilder();
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
		
			
		int n=s.nextInt();
		char[] arr=new char[n];
		char[] brr=new char[n];
		String str1=s.next();
		String str2=s.next();
		for(int i=0;i<n;i++) {
			arr[i]=str1.charAt(i);
		}
		for(int i=0;i<n;i++) {
			brr[i]=str2.charAt(i);
		}
			
		int count[] =new int[26];
		
		
		for(int i=0;i<n;i++) {
			count[Integer.valueOf(arr[i])-97]++;
			count[Integer.valueOf(brr[i])-97]++;
			
		}
		
		
		int flag=0;
		
		for(int i=0;i<26;i++) {
			if(count[i]%2==0) {
				
			}else {
				flag=1;
				break;
			}
		}
		
		StringBuilder sb1=new StringBuilder();
		int countt=0;
		if(flag==0) {
			System.out.println("Yes");
			for(int i=0;i<n;i++) {
				if(arr[i]!=brr[i]) {
					
					int g=0;
					for(int j=i+1;j<n;j++) {
						if(arr[j]==arr[i]) {
							g=1;
							sb1.append((j+1)+" "+(i+1)+"\n");
							countt++;
							arr[j]=brr[i];
							break;
						}
					}
					
					if(g==0) {
						for(int j=i+1;j<n;j++) {
							if(brr[j]==arr[i])
							{countt=countt+2;
						sb1.append((n)+" "+(j+1)+"\n");
								sb1.append((n)+" "+(i+1)+"\n");
								brr[j]=arr[n-1];
								arr[n-1]=brr[i];
								break;
							}
						}
					}
					
					
				}else {
					continue;
				}
			

			}
			
			System.out.println(countt);
			System.out.println(sb1);
			
		}else {
			System.out.println("No");
		}
		
		
		}
	}
}