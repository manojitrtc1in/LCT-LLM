

import java.util.*;
import java.io.*;
public class Main {

	static Scanner inp= new Scanner(System.in);
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		
		Main g=new Main();
		g.main();
		out.close();
	}
	
	
	
	

	void main() {
		
		int t=inp.nextInt();
		while(t-->0){
			int n=inp.nextInt();
			int m=inp.nextInt();
			long a[]=new long[n];
			input(a,n);
			long x[]=new long[m];
			input(x,m);
			long bestPref[]=new long[n+1];
			long sum=0;
			for(int i=0;i<n;i++) {
				sum+=a[i];
				bestPref[i+1]=Math.max(bestPref[i], sum);
			}
			for(long cur: x) {
				if(sum<=0 && bestPref[n]<cur) {
					out.print("-1 ");
					continue;
				}
				if(bestPref[n]>=cur) {
					out.print((go(bestPref,n,cur)-1)+" ");
					continue;
				}
				long cycles=((cur-bestPref[n])+(sum-1))/sum;
				long gg=cycles*n;
				long rem=cur-cycles*sum;
				out.print((gg+go(bestPref,n,rem)-1)+" ");
			}
			out.println();
		}
		
	}
	
	long go(long bestPref[], int n, long cur) {
		int left=1,right=n,ans=n;
		while(left<=right) {
			int mid=left+right>>1;
			if(bestPref[mid]>=cur) {
				ans=mid;
				right=mid-1;
			}else {
				left=mid+1;
			}
		}
		return ans;
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


