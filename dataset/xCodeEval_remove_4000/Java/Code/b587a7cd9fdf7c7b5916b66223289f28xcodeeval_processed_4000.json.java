

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
		 long n=s.nextInt();
		 long k=s.nextInt();
		 long m=s.nextInt();
		 
		 long l=-1;
		 long r=-1;
		 
		 long ans=1;
		 for(int i=0;i<m;i++) {
			 int a=s.nextInt();
			 int b=s.nextInt();
			 
			 if(l==-1) {
			 
			 if(k>=a&&k<=b) {
				ans=ans+b-a; 
				l=a;
				r=b;
			 }
			 
			 }else {
				 
				 if(b<l||a>r) {
					 
				 }else {
					 if(a>=l&&b<=r) {
						 
					 }else if(a<l&&b<=r) {
						 ans=ans+l-a;
						 l=a;
					 }else if(b>r&&a>=l) {
						 ans=ans+b-r;
						 r=b;
					 }else if(b>r&&a<l) {
						 
						 ans=ans+l-a+b-r;
						 l=a;
						 r=b;
					 }
					 
					 
				 }
				 
			 }
			 
			 
		 }
			
			System.out.println(ans);
		}
	}
}