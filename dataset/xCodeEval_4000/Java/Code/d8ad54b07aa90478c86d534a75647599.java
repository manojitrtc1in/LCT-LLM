

import java.util.*;
import javafx.util.*;
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
	
	static int n=inp.nextInt();
	static int m=inp.nextInt();
	static boolean vis[][]=new boolean[n][m];
	static char s[][]=new char[n][m];
	
	

	void main() {
			
		for(int i=0;i<n;i++) {
			s[i]=inp.next().toCharArray();
		}
		boolean multipleSegments=false;
		int allWhiteRows=0,allWhiteCols=0;
		for(int i=0;i<n;i++) {
			int leftBlack=0,rightBlack=m-1;
				while(leftBlack<m && s[i][leftBlack]=='.') {
					leftBlack++;
				}
				while(rightBlack>=0 && s[i][rightBlack]=='.') {
					rightBlack--;
				}
				if(leftBlack>rightBlack) {
					allWhiteRows++;
				}else {
					for(int x=leftBlack;x<rightBlack;x++) {
						if(s[i][x]!=s[i][x+1]) {
							multipleSegments=true;
							break;
						}
					}
				}
		}
		
		for(int i=0;i<m;i++) {
			int leftBlack=0,rightBlack=n-1;
				while(leftBlack<n && s[leftBlack][i]=='.') {
					leftBlack++;
				}
				while(rightBlack>=0 && s[rightBlack][i]=='.') {
					rightBlack--;
				}
				if(leftBlack>rightBlack) {
					allWhiteCols++;
				}else {
					for(int x=leftBlack;x<rightBlack;x++) {
						if(s[x][i]!=s[x+1][i]) {
							multipleSegments=true;
							

							break;
						}
					}
				}
		}
		

		if(multipleSegments || (allWhiteRows>0 && allWhiteCols==0) || (allWhiteCols>0 && allWhiteRows==0) ) {
			out.println(-1);
			return;
		}
		int gg=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(vis[i][j] || s[i][j]=='.') {
					continue;
				}
				dfs(i,j);
				gg++;
			}
		}
		out.println(gg);
	}
	
	static int x[][]= {{0,1},{1,0},{0,-1},{-1,0}};
	static void dfs(int i, int j) {
		if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || s[i][j]=='.') {
			return;
		}
		vis[i][j]=true;
		for(int p=0;p<4;p++) {
			dfs(i+x[p][0],j+x[p][1]);
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
