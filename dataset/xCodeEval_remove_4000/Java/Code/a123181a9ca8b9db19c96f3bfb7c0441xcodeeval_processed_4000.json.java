

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
 public class b{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
      StringBuilder sb=new StringBuilder();
		int n=s.nextInt();
		int k=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		
		int st=0;
		int end=0;
		int count=0;
		int flag=0;
		int max=-1;
		if(arr[0]==0) {
			count++;
		}
		if(k>0) {
		int h=-1;int j=-1;
		while(end<n) {
			if(count<=k) {
				end++;
				flag=0;
			}else {
				if(end>st) {
					if(arr[st]==0) {
						count--;
					}
					st++;
					flag=1;
					
				}else {
					end++;
					st++;
				}
			}
			
			if(max<end-st) {
				max=end-st;
				h=st;
				j=end-1;
			}
			if(end==n&&arr[end-1]==1) {
				if(max<end-st) {
					max=end-st;
					h=st;
					j=end-1;
				}
			}
			
			if(end!=n&&arr[end]==0&&flag==0) {
				count++;
				flag=0;
			}
		}
	sb.append(max+"\n");
	
	
	for(int i=0;i<n;i++) {
		if(i>=h&&i<=j) {
			sb.append(1+" ");
		}else {
			sb.append(arr[i]+" ");
		}
	}
		}else {
			int m=-1;
			int cou=0;
			for(int i=0;i<n;i++) {
				if(arr[i]==1) {
					cou++;
				}else {
					if(m<cou) {
						m=cou;
					}
					
					cou=0;
					
				}
			}
			if(cou>m) {
				m=cou;
			}
			sb.append(m+"\n"); 
		
			
			for(int i=0;i<n;i++) {
				sb.append(arr[i]+" ");
			}
		}
		
		System.out.println(sb);
		
	}
 }