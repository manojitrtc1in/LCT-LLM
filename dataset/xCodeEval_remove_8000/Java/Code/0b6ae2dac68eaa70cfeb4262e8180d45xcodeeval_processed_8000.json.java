

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
	
	StringBuilder first=new StringBuilder("");
	StringBuilder second=new StringBuilder("");
	int dp[][];
	String s;
	
	

	void main() {
		
		s=inp.next();
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

			dp=new int[n][n];
			for(int i=0;i<n;i++) Arrays.fill(dp[i], -1);
			id0(0,n-1);
			go(0,n-1);
			second=second.reverse();
			if(first.length()+second.length()>100) {
				for(int i=0;i<50;i++) out.print(first.charAt(i));
				for(int i=second.length()-50;i<second.length();i++) out.print(second.charAt(i));
			}else {
				out.print(first);
				out.print(second);
			}
		}
		
	}
	
	int id0(int i, int j) {
		if(i>j) return 0;
		if(i==j) return 1;
		if(dp[i][j]!=-1) return dp[i][j];
		if(s.charAt(i)==s.charAt(j)) return dp[i][j]=2+id0(i+1,j-1);
		else return dp[i][j]=Math.max(id0(i+1,j), id0(i,j-1));
	}
	
	void go(int i, int j) {
		if(i>j) return;
		else if(i==j) {
			first.append(s.charAt(i));
		}
		else if(s.charAt(i)==s.charAt(j)) {
			first.append(s.charAt(i));
			second.append(s.charAt(i));
			go(i+1,j-1);
		}else {
			if(dp[i+1][j]>dp[i][j-1]) go(i+1,j);
			else go(i,j-1);
		}
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
