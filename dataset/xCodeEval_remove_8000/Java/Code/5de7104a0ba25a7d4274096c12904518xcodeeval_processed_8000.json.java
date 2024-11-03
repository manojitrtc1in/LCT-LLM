

import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
public class Main {

	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	
		Main g=new Main();
		g.main();
		out.close();
		
	}
	
	
	
	void main() {
		
		int t=inp.nextInt();
		while(t-->0) {
			long x=inp.nextLong();
			long y=inp.nextLong();
			long k=inp.nextLong();
			long gain=(x-1);
			long gg=0;
			long id2=y*k;
			long id1=k;
			long id0=(y+1)*k;
			long moves=(id0+gain-1-1)/gain;
			out.println(moves+k);
		}
		
	}
	
	
	
	static class FastReader { 
        BufferedReader br; 
        StringTokenizer st;
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        String next() { 
            while (st==null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        String nextLine() { 
            String s=""; 
            try { 
                s=br.readLine(); 
            } 
            catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return s; 
        } 
    } 
	
	
	

		
}
