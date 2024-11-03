

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
		
		int t=inp.nextInt();
		while(t-->0) {
			int n=inp.nextInt();
			int k=inp.nextInt();
			int z=inp.nextInt();
			int a[]=new int[n];
			int pre[]=new int[n];
			input(a,n);
			int gg=0;
			pre[0]=a[0];
			for(int i=1;i<n;i++) {
				pre[i]=a[i]+pre[i-1];
			}
			for(int j=0;j<=z;j++) {
				int forward=k-j,rev=j;
				if(forward>=rev) {
					int max=0;
					for(int i=0;i<=k-2*j;i++) {
						if(i<n-1) {
							max=Math.max(max, a[i]+a[i+1]);
						}
					}
					gg=Math.max(gg, pre[k-2*j]+max*j);
					

				}
			}
			out.println(gg);
		}
		
	}

	
	
	
	
	
	

	static class Edge implements Comparable<Edge>{
		int l,r;
		Edge(){}
		Edge(int l,int r){
			this.l=l;
			this.r=r;
		}
		@Override
		public int compareTo(Edge e) {
			return (l-e.l)!=0?l-e.l:r-e.r;
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
	
	static void reverse(long[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            long t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
    }
    static void reverse(int[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
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
