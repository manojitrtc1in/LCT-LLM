

import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
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
		int gg[]=new int[n];
		query(1,3);
		int sum=inp.nextInt();
		query(1,2);
		gg[2]=sum-inp.nextInt();
		query(2,3);
		gg[0]=sum-inp.nextInt();
		gg[1]=sum-gg[2]-gg[0];
		for(int i=3;i<n;i++) {
			query(i,i+1);
			gg[i]=inp.nextInt()-gg[i-1];
		}
		out.print("! ");
		print(gg);
		
		
	}
	
	void print(int a[]) {
		for(int i=0;i<a.length;i++) out.print(a[i]+" ");
	}
	
	void query(int l, int r) {
		System.out.println("? "+l+" "+r);
	}
	
	
	
	

		
}
