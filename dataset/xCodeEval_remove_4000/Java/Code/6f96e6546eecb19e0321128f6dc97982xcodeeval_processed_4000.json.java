

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	
	public static void main(String[] args)	{
		
		Scanner s=new Scanner(System.in);
 
		int n=s.nextInt();
		
		char[] arr=s.next().toCharArray();
		
	
		if(arr[0]==')'||arr[n-1]=='(') {
			System.out.println(":(");
			
		}else if((n-2)%2!=0) {
			
			System.out.println(":(");
		}else {
			int flag=0;

			int p=0;
			int w=0;
			int ne=0;
			
			for(int i=1;i<n-1;i++) {
				if(arr[i]=='(') {
					p++;
				}else if(arr[i]==')') {
					ne++;
				}else {
					w++;
				}
			}
			
			if(ne>p) {
				if(w<ne-p) {
					flag=1;
				}else {
					int count=0;
					int st=1;
					while(count<ne-p) {
						if(arr[st]=='?') {
							count++;
							arr[st]='(';
						}
						st++;
					}
					
					count=0;
					st=1;
					w=w-ne+p;
					while(count<w/2) {
						if(arr[st]=='?') {
							count++;
							arr[st]='(';
						}
						st++;
					}
					count=0;
					while(count<w/2) {
						if(arr[st]=='?') {
							count++;
							arr[st]=')';
						}
						st++;
					}
						
					
				}
			}else{
				
				
				
				
				if(w<p-ne) {
					flag=1;
				}else {
					int count=0;
					int st=n-2;
					
					while(count<p-ne) {
						if(arr[st]=='?') {
							count++;
							arr[st]=')';
						}
						st--;
					}
					
					count=0;
					st=n-2;
					w=w-p+ne;
					
					while(count<w/2) {
						if(arr[st]=='?') {
							count++;
							
							arr[st]=')';
						}
						st--;
					}
					
					count=0;
					
					while(count<w/2) {
						if(arr[st]=='?') {
							count++;
							arr[st]='(';
							
						}
						st--;
						
						
					}
						
					
				}
				
				
				
				
				
				
				
				
				
			}
			
			
			arr[0]='('; arr[n-1]=')';
			
			int g=0;
			
			for(int i=1;i<n-2;i++) {
				if(arr[i]==')') {
					g--;
				}else {
					g++;
				}
				
				if(g<0) {
					flag=1;
					break;
				}
			}
			StringBuilder sb=new StringBuilder();
			if(flag==0) {
			for(int i=0;i<n;i++) {
				sb.append(arr[i]);
			}
			System.out.println(sb);
			}else {
				System.out.println(":(");
			}
			
			
		}
	
	}
}
