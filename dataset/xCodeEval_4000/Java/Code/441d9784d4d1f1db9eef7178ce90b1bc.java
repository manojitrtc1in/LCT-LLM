

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
		
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			int n=s.nextInt();
			int[] arr=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}

		int flag=0;
		int c=1;
		for(int i=0;i<n;i++) {
			if(arr[i]==c) {
				c++;
			}else {
				flag=1;
				break;
			}
		}
		
		if(flag==0) {
			System.out.println(0);
		}else{
			int count=0;
			int g=0;
			for(int i=0;i<n;i++) {
				if(g==0) {
				if(arr[i]!=i+1) {
					g=1;
					
				}
				}else if(g==1){
					if(arr[i]==i+1) {
						g=2;
						
					}
				}else {
					if(arr[i]!=i+1) {
						g=3;
						break;
					}
				}
			}
			
			
			
			if(g!=3) {
				System.out.println(1);
			}else {
				System.out.println(2);
			}
			
			
			
		}
		
		
		
		
		}
		
		
		
		

	}
}

	