

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
			String s[]=new String[2*n-2];
			input(s,2*n-2);
			StringBuilder s1=new StringBuilder("");
			StringBuilder s2=new StringBuilder("");
			boolean first=true;
			for(int i=0;i<2*n-2;i++) {
				if(s[i].length()==n-1) {
					if(first) {
						s1=new StringBuilder(s[i]);
						s2=new StringBuilder(s[i]);
						first=false;
					}else {
						s1.append(s[i].charAt(n-2));
						s2=new StringBuilder(s[i].charAt(0)+""+s2);
					}
				}
			}
			char ans[][]=new char[2*n-2][2];
			int gg=0;
			if(check(s,s1.toString(),ans,0,n)) {
				gg=0;
			}else if(check(s,s2.toString(),ans,1,n)) {
				gg=1;
			}
			for(int i=0;i<2*n-2;i++) {
				out.print(ans[i][gg]);
			}
		
	}
	
	boolean check(String s[], String original, char ans[][],int k, int n) {
		boolean prefix[]=new boolean[n-1];
		boolean suffix[]=new boolean[n-1];
		for(int i=0;i<2*n-2;i++) {
			int len=s[i].length();
			if(!prefix[len-1] && isPrefix(original,s[i])) {
				prefix[len-1]=true;
				ans[i][k]='P';
			}else if(!suffix[len-1] && isSuffix(original,s[i])) {
				suffix[len-1]=true;
				ans[i][k]='S';
			}
		}
		int pre=0,suf=0;
		for(int i=0;i<2*n-2;i++) {
			if(ans[i][k]=='P') {
				pre++;
			}
			else if(ans[i][k]=='S') {
				suf++;
			}
		}
		return pre==n-1 && suf==n-1;
	}
	
	boolean isPrefix(String original,String s) {
		for(int i=0;i<s.length();i++) {
			if(original.charAt(i)!=s.charAt(i)) {
				return false;
			}
		}
		return true;
	}
	
	boolean isSuffix(String original,String s) {
		int n=original.length();
		int l=s.length();
		for(int i=l-1;i>=0;i--) {
			if(original.charAt(i+(n-l))!=s.charAt(i)) {
				return false;
			}
		}
		return true;
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
