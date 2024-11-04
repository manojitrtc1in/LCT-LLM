

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
	
	static HashSet<Long> list[];
	static long dp[];  

	static boolean vis[];
	
	

	void main() {
		
		int t=inp.nextInt();
		loop:
		while(t-->0) {
			int n=inp.nextInt();
			list=new HashSet[n];
			vis=new boolean[n];
			dp=new long[n];
			for(int i=0;i<n;i++) {
				list[i]=new HashSet<>();
			}
			for(int i=0;i<n-1;i++) {
				int x=inp.nextInt()-1;
				int y=inp.nextInt()-1;
				list[x].add((long)y);
				list[y].add((long)x);
			}
			int m=inp.nextInt();
			long p[]=new long[m];
			input(p,m);
			Arrays.sort(p);
			long w[]=new long[n-1];
			int c=m-1;
			if(m>=n) {
				for(int i=n-1;i<m;i++) {
					p[n-2]*=p[i];
					p[n-2]%=mod;
				}
				c=n-2;
			}
			for(int i=n-2;i>=0;i--) {
				if(c>=0) {
					w[i]=p[c];
					c--;
				}else {
					w[i]=1;
				}
			}
			int i=0;
			for(;i<n;i++) {
				if(list[i].size()==1) {
					

					direct(i);
					break;
				}
			}
			dfs(i);
			for(int j=0;j<n;j++) {
				

			}
			c=0;
			long times[]=new long[n-1];
			for(int j=0;j<n;j++) {
				if(j==i)continue;
				times[c++]=dp[j]*(n-dp[j]);
			}
			Arrays.sort(times);
			long gg=0;
			for(int j=0;j<n-1;j++) {
				

				gg+=((times[j]%mod)*w[j]);
				gg%=mod;
			}
			out.println(gg);
			
		}
		
	}
	
	static long dfs(long i) {
		if(list[(int)i].size()==0) {
			dp[(int)i]=1;
			return 1;
		}
		long gg=0;
		for(long x:list[(int)i]) {
			gg+=dfs(x);
		}
		dp[(int)i]=gg+1;
		return gg+1;
	}
	
	static void direct(long i) {
		for(long x: list[(int)i]) {
			list[(int)x].remove(i);
		}
		for(long x: list[(int)i]) {
			direct(x);
		}
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
