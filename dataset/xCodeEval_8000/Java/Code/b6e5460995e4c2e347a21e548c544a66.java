

import java.util.*;
import java.io.*;
public class InVoker {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	InVoker g=new InVoker();
	   	g.main();
	   	out.close();
	}
	
	
	
	

	void main() {

		int t=1;
		while(t-->0) {
			int n=inp.nextInt();
			int N=1000001;
			boolean hasAcc[]=new boolean[n];
			int s[][]=new int[n][];
			for(int i=0;i<n;i++) {
				int l=inp.nextInt();
				s[i]=new int[l];
				for(int j=0;j<l;j++) {
					s[i][j]=inp.nextInt();
				}
			}
			long haCount=0,allSameCount=0,gg=0;
			for(int i=0;i<n;i++) {
				for(int j=1;j<s[i].length;j++) {
					if(s[i][j]>s[i][j-1]) {
						hasAcc[i]=true;
						haCount++;
						break;
					}
				}
			}
			gg+=haCount*n;
			gg+=(n-haCount)*haCount;
			

			int startWithIorMore[]=new int[N];
			int endWithIorLess[]=new int[N];
			for(int i=0;i<n;i++) {
				if(hasAcc[i])continue;
				int l=s[i].length;
				startWithIorMore[s[i][0]]++;
				endWithIorLess[s[i][l-1]]++;
				if(s[i][0]==s[i][l-1])allSameCount++;
			}
			for(int i=1;i<N;i++) {
				endWithIorLess[i]+=endWithIorLess[i-1];
			}
			for(int i=N-2;i>=0;i--) {
				startWithIorMore[i]+=startWithIorMore[i+1];
			}
			long wew=0;
			for(int i=0;i<n;i++) {
				if(!hasAcc[i]) {
					int x=s[i][0];
					

					if(x>0)wew+=endWithIorLess[x-1];
					

					

				}
			}
			gg+=wew;
			out.println(gg);
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
