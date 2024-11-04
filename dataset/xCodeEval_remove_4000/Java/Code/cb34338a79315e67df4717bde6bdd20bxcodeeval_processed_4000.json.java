

import java.util.*;
import java.io.*;
public class Main {

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static Scanner inp= new Scanner(System.in);
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
		Main g=new Main();
		g.main();
		out.close();
	}
	
	
	
	

	void main() {
		
		int n=inp.nextInt();
		int m=inp.nextInt();
		int a[]=new int[n];
		int b[]=new int[n];
		int c[]=new int[m];
		int d[]=new int[m];
		for(int i=0;i<n;i++) {
			a[i]=inp.nextInt();
			b[i]=inp.nextInt();
		}
		for(int i=0;i<m;i++) {
			c[i]=inp.nextInt();
			d[i]=inp.nextInt();
		}
		int atLeast[]=new int[1000001]; 

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int x=c[j]-a[i];
				int y=d[j]-b[i];
				if(x>=0 && y>=0) {
					atLeast[x]=Math.max(atLeast[x], y+1);
				}
			}
		}
		long gg=2*1000000;
		long dy=0;
		for(int dx=1000000;dx>=0;dx--) {  
			dy=Math.max(dy, atLeast[dx]);
			gg=Math.min(gg, dx+dy);
		}
		out.println(gg);
	}
	
	
	
	
	
	

	static void input(long a[], int n) {
		for(int i=0;i<n;i++) {
			a[i]=inp.nextLong();
		}
	}
	static void input(int a[], int n) {
		for(int i=0;i<n;i++) {
			a[i]=inp.nextInt();
		}
	}	
	static void input(String s[],int n) {
		for(int i=0;i<n;i++) {
			s[i]=inp.next();
		}
	}
	static void input(int a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextInt();
			}
		}
	}
	static void input(long a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextLong();
			}
		}
	}
		
}
