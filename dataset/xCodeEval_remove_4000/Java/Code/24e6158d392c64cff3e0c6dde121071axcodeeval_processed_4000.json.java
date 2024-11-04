


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.*;
public class ted {
	public static void main(String[]arsStrings) {
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t=scanner.nextInt();
		for(int i1=0;i1<t;i1++) {
			int n=scanner.nextInt();
			List<Integer> l3=new java.util.ArrayList<>();
			List<Integer> l5=new java.util.ArrayList<>();
			List<Integer> l7=new java.util.ArrayList<>();
			int a3=0,a5=0,a7=0;int fl=0;
			for(int i=1;true;i++) {
				a3=i*3;
				a5=i*5;
				a7=i*7;
				if(a3==n) {
					System.out.println(i+" 0 0");fl=1;
					break;
				}
				else if(a5==n) {
					System.out.println("0 "+i+" 0");fl=1;
					break;
				}
				else if(a7==n) {
					System.out.println("0 0 "+i);fl=1;
					break;
				}
				if(a3>n)break;
				l3.add(a3);l5.add(a5);l7.add(a7);
			}
			

			boolean con=true;
			if(fl!=1)
			for(int i=0;i<l3.size() &&con;i++) {
				for(int j=0;j<l5.size() &&con;j++) {
					for(int k=0;k<l7.size() &&con;k++) {
						

						if(l3.get(i)+l5.get(j)+l7.get(k)==n) {
						fl=1;
						System.out.println((i+1)+" "+(j+1)+" "+(k+1));con=false;	
						break;
						}
						else if(l3.get(i)+l5.get(j)+0==n) {
							fl=1;
							System.out.println((i+1)+" "+(j+1)+" "+(0));con=false;	
							break;
						}
						else if(l3.get(i)+l7.get(k)==n) {
							fl=1;
							System.out.println((i+1)+" "+(0)+" "+(k+1));con=false;	
							break;
						}
						if(l5.get(j)+l7.get(k)==n) {
							fl=1;
							System.out.println((0)+" "+(j+1)+" "+(k+1));con=false;	
							break;
						}
					}
				}
			}
			if(fl!=1)System.out.println(-1);
			
		}
		
		
	}		
}

