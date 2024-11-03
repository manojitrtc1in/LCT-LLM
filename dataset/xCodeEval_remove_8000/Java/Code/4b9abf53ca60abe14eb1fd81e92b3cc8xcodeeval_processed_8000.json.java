

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
	
	

	void main() {
		
		int n=inp.nextInt();
		int a[]=new int[n*n];
		input(a,n*n);
		int freq[]=new int[1001];
		for(int i=0;i<n*n;i++) {
			freq[a[i]]++;
		}
		int ans[][]=new int[n][n];
		if(n%2==0) {
			for(int i=1;i<=n*n;i++) {
				if(freq[i]%4!=0) {
					out.println("NO");
					return;
				}
			}
			Arrays.sort(a);
			int c=0;
			for(int i=0;i<n/2;i++) {
				for(int j=0;j<n/2;j++) {
					int x=a[c++*4];
					ans[i][j]=x;
					ans[n-i-1][j]=x;
					ans[i][n-j-1]=x;
					ans[n-i-1][n-j-1]=x;
				}
			}
			out.println("YES");
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					out.print(ans[i][j]+" ");
				}
				out.println();
			}
		} 
		else {
			int odd=0,fours=0;
			for(int i=1;i<=1000;i++) {
				if(freq[i]%2==1) {
					odd++;
					ans[n/2][n/2]=i;
					freq[i]--;
				}
				fours+=freq[i]/4;
			}
			int req4=(n/2) * (n/2);
			

			if(req4>fours || odd!=1) {
				out.println("NO");
				return;
			}
			int x=0;
			for(int i=0;i<n/2;i++) {
				for(int j=0;j<n/2;j++) {
					while(freq[x]<4) {
						x++;
					}
					ans[i][j]=x;
					ans[n-i-1][j]=x;
					ans[i][n-j-1]=x;
					ans[n-i-1][n-j-1]=x;
					freq[x]-=4;
				}
			}
			x=0;
			for(int i=0;i<n/2;i++) {
				while(freq[x]<2) {
					x++;
				}
				ans[i][n/2]=x;
				ans[n-i-1][n/2]=x;
				freq[x]-=2;
			}
			for(int i=0;i<n/2;i++) {
				while(freq[x]<2) {
					x++;
				}
				ans[n/2][i]=x;
				ans[n/2][n-i-1]=x;
				freq[x]-=2;
			}
			out.println("YES");
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					out.print(ans[i][j]+" ");
				}
				out.println();
			}
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
	
	void reverse(long[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            long t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
    }
    void reverse(int[] A,int l,int r) {
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
