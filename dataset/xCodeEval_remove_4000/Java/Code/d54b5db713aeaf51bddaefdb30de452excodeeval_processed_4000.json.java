

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
			long a=inp.nextLong();
			long b=inp.nextLong();
			long c=inp.nextLong();
			long d=inp.nextLong();
			boolean neg=(a+b)%2==1;
			boolean gg[]=new boolean[4];
			if(neg) {
				if(b>0 || c>0) gg[1]=true;
				if(a>0 || d>0) gg[0]=true;
			}else {
				if(b>0 || c>0) gg[2]=true;
				if(a>0 || d>0) gg[3]=true;
			}
			for(int i=0;i<4;i++) out.print(gg[i]?"Ya ":"Tidak ");
			out.println();
		}
		
		
	}
	
	
	
	
	
	

		
}
