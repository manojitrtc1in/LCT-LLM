

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
		
		

		String s=inp.next();
		int n=s.length();
		if(n>(26*99)) {
			for(int k=0;k<26;k++) {
				char x=toChar(k);
				int c=0;
				for(int i=0;i<n;i++) {
					if(s.charAt(i)==x) c++;
				}
				if(c>=100) {
					for(int i=0;i<100;i++) out.print(x);
					break;
				}
			}
		}else { 

			int dp[][]=new int[n+1][n+1];
			String t= new StringBuilder(s).reverse().toString();
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(s.charAt(i-1)==t.charAt(j-1)) dp[i][j]=dp[i-1][j-1]+1;
					else dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
				}
			}
			StringBuilder x=go(s,t,n,n,dp);
			if(x.length()>100) {
				n=x.length();
				for(int i=0;i<50;i++) out.print(x.charAt(i));
				for(int i=n-50;i<n;i++) out.print(x.charAt(i));
			}else {
				out.println(x);
			}
		}
		
	}
	
	StringBuilder go(String s, String t, int m, int n, int dp[][]) {
		if(m==0 || n==0) return new StringBuilder("");
		if(s.charAt(m-1)==t.charAt(n-1)) return go(s,t,m-1,n-1,dp).append(s.charAt(m-1));
		
		if(dp[m-1][n]>dp[m][n-1]) {
			return go(s,t,m-1,n,dp);
		}
		return go(s,t,m,n-1,dp);
	}
	
	char toChar(int x) {
		return (char)(x+97);
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
