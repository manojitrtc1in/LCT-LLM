

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			long x=s.nextLong();
			long y=s.nextLong();
			
			
			if(x>=y) {
				System.out.println("YES");
				
			}else {
				if(x%2!=0) {
					x--;
				}
				if(x/2==1) {
					if(x+1>=y) {
						System.out.println("YES");
					}else {
						System.out.println("NO");
					}
				}else if(x/2==0){
					if(x==y) {
						System.out.println("YES");
					}else {
						System.out.println("NO");
					}
					
				}else {
					System.out.println("YES");
				}
			}
			
		}
		
	 }
}