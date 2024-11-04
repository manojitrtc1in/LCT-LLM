

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){

		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		
		int[] ans=new int[n+1];
		int st=1;
		
		for(int i=2;i<=n;i++) {
			System.out.println("?"+" "+st+" "+i);
			int a=s.nextInt();
			System.out.println("?"+" "+i+" "+st);
			int b=s.nextInt();
			
			
			if(a>=b) {
				ans[st]=a;
				st=i;
				
			}else {
				ans[i]=b;
			}
			
		}
		
		ans[st]=n;
		
		System.out.print("! ");
		for(int i=1;i<n+1;i++) {
			System.out.print(ans[i]+" ");
		}
		
		
		
		System.out.flush();
	}
}