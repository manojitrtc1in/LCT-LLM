

import java.util.Scanner;
import java.util.Stack;

public class Main {
	
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);
		int count=0;
		int n=s.nextInt();
		char[] arr=s.next().toCharArray();
		int flag=0;
		int g=0;
		for(int i=0;i<arr.length;i++) {
			if(arr[i]=='(') {
				count++;
			}else {
				count--;
				
			}
			if(count<0) {
			if(flag==0) {
				count++;
			flag=1;	
			}else {
				g=1;
				break;
			}
			}
		}
		if(flag==1) {
			count--;
		}
		if(count!=0) {
			g=1;
		}
		if(g==0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		
		

		
        
	}
}
	
	