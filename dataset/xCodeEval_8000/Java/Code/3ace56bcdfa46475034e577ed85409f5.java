

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
		
		
		int t=inp.nextInt();
		while(t-->0) {
			long n=inp.nextLong();
			long gg=0;
			boolean bad=false;
			if(n%2==1) {
				bad=true;
				gg++;
				n--;
			}
			long rem=0,tot=n;
			while(n>0) {
				if(n==4) {
					n-=4;
					rem+=3;
				}
				else if(n%4==0) {
					n-=2;
					rem++;
				}else {
					n/=2;
					rem+=n;
					n--;
				}
			}
			gg+=bad?tot-rem:rem;
			out.println(gg);
		}
		
	}
	
	
	
	
	
	

		
}
