

import java.util.*;
import java.io.*;
public class id0 {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	id0 g=new id0();
	   	g.main();
	   	out.close();
	}
	
	int x[]= {35,23,18,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	
	

	void main() {
		
		int n=inp.nextInt();
		long a[]=new long[n];
		input(a,n);
		if(n==1 || n==2) {
			out.println(a[0]-1l);
			return;
		}
		Arrays.sort(a);
		long gg=Long.MAX_VALUE;
		loop:
		for(int i=1;i<=100000;i++) {
			long cur=1,ans=0;
			for(int j=0;j<n;j++) {
				ans+= Math.abs(cur-a[j]);
				cur*=(long)i;
				if(cur>=100000000000000l) {
					continue loop;
				}
			}
			gg=Math.min(gg, ans);
		}
		out.println(gg);
	}
	
	static long power(long x, long y) {
		if(y==0) return 1;
		if(y==1) return x;
		long gg=power(x,y/2);
		return gg*gg*power(x,y%2);
	}
	
	static class Pair implements Comparable<Pair> {
		long f, s;
		Pair () {}
		Pair (long l_, long r_) {
		    this.f = l_;
		    this.s = r_;
		}
		@Override
        public int compareTo(Pair other) {
        	if(this.f==other.f) {
        		return Long.compare(this.s,other.s);
        	}
			return Long.compare(this.f, other.f);
		}
    }
	
	static class Segment implements Comparable<Segment> {
		long l, r, initialIndex;
		Segment () {}
		Segment (long l_, long r_, long d_) {
		    this.l = l_;
		    this.r = r_;
		    this.initialIndex = d_;
		}
		@Override
		public int compareTo(Segment o) {
		    return (int)((l - o.l) !=0 ? l-o.l : initialIndex - o.initialIndex);
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
    
    

	static long gcd(long a, long b) { 
		return b==0?a:gcd(b,a%b);
	}
	static int gcd(int a, int b) { 
		return b==0?a:gcd(b,a%b);
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
