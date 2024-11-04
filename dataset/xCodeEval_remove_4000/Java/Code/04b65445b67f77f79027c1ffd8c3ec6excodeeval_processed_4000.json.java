

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
			int n=inp.nextInt();
			int a[]=new int[n];
			for(int i=0;i<n;i++) a[i]=inp.nextInt();
			int gg=0;
			boolean frnd=true;
			for(int i=0;i<n;i++) {
				if(frnd) {
					if(i<n-2) {
						if(a[i]==1 && a[i+1]==1) {
							gg++;
						}else if(a[i]==1) { 

							gg++;
							if(a[i+2]==1) {
								i++;
							}
						}else { 

							if(a[i+1]==1) { 

								
							}else if(a[i+2]==1) { 

								i++;
							}else {

								
							}
						}
					}else if(i<n-1) {
						if(a[i]==1) {
							gg++;
						}
					}else {
						if(a[i]==1) gg++;
					}
				}else {
					if(i<n-1) {
						if(a[i+1]==0) {
							
						}else if(a[i+1]==1) {
							i++;
						}
					}else {
						

					}
				}
				frnd=!frnd;
			}
			out.println(gg);
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
