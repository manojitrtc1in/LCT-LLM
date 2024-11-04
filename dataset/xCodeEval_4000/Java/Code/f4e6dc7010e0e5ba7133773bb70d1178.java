

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
      
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			long a=s.nextLong();
			long b=s.nextLong();
			long c=s.nextLong();
			long d=s.nextLong();
			long x=s.nextLong();
			long y=s.nextLong();
			long x1=s.nextLong();
			long y1=s.nextLong();
			long x2=s.nextLong();
			long y2=s.nextLong();
			int flag=0;
			if(a!=0&&x-x1<1) {
				if(b==0) {
					flag=1;
					System.out.println("No");
				}else {
					if(x2-x<1) {
						flag=1;
						System.out.println("No");
					}
					
					
				}
			}else if(b!=0&&x2-x<1) {
				if(a==0) {
					flag=1;
					System.out.println("No");
				}else {
					
					if(x-x1<1) {
						flag=1;
						System.out.println("No");
					}
					
					
				}
			}
			if(flag==0) {
			if(c!=0&&y-y1<1) {
				if(d==0) {
					flag=1;
					System.out.println("No");
				}else {
					if(y2-y<1) {
						flag=1;
						System.out.println("No");
					}
					
					
				}
			}else if(d!=0&&y2-y<1) {
				if(c==0) {
					flag=1;
					System.out.println("No");
				}else {
					if(y-y1<1) {
						flag=1;
						System.out.println("No");
					}
					
					
				}
			}
			}
			if(flag==0){
	                   
			
			long h=Math.min(a,b);
			a=a-h;
			b=b-h;
			
			long g=Math.min(c,d);
			c=c-g;
			d=d-g;
			if(a>0) {
			  x=x-a;	
			}else if(b>0) {
				x=x+b;
			}
			
			if(c>0 ) {
				  y=y-c;	
				}else if(d>0) {
					y=y+d;
				}
			
			
			
			if(flag==0) {
			if(x<Math.min(x1, x2)||x>Math.max(x1, x2)||y>Math.max(y1, y2)||y<Math.min(y1, y2)) {
				System.out.println("No");
			}else {
				System.out.println("Yes");
			}
			}
			
			
			}
					
			
			
		}
	}
 }