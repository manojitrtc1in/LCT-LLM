

import java.util.*;
import javafx.util.*;
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
		int m=inp.nextInt();
		ArrayList<Integer> list[]= new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			list[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int a=inp.nextInt();
			int b=inp.nextInt();
			list[a].add(b);
			list[b].add(a);
		}
		int topic[]=new int[n+1];
		TreeSet<Integer> id1[]= new TreeSet[n+1];
		for(int i=0;i<=n;i++) {
			id1[i]=new TreeSet<Integer>();
		}
		for(int i=1;i<=n;i++) {
			topic[i]= inp.nextInt();
			id1[topic[i]].add(i);
		}
		boolean can=true;
		int ans[]=new int[n],c=0;
		for(int i=1;i<=n && can;i++) {
			for(int curBlog:id1[i]) {
				boolean same=false;
				if(i!=1) {
					boolean pres[]=new boolean[i];
					for(int x: list[curBlog]) { 

						if(topic[x]==i) {
							can=false;
						}else {
							if(topic[x]<i) {
								pres[topic[x]]=true;
							}	
						}	
					}
					for(int k=1;k<i;k++) {
						if(!pres[k]) {
							can=false;
							break;
						}
					}
				}else {
					for(int x: list[curBlog]) {
						if(topic[x]==i) {
							same=true;
						}
					}
					if(same) {
						can=false;
						break;
					}
				}
				ans[c++]=curBlog;
			}
		}
		if(can) {
			for(int i=0;i<n;i++) {
				out.print(ans[i]+" ");
			}
		}else {
			out.println(-1);
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
