

import java.util.*;

import javax.sound.sampled.Line;

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
		long a[]=new long[n];
		for(int i=0;i<n;i++) a[i]=inp.nextLong();
		HashMap<Long,Integer> map=new HashMap<>();
		map.put(0l, -1);
		long sum=0;
		int cur=-1,gg=0;
		for(int i=0;i<n;i++) {
			sum+=a[i];
			if(map.containsKey(sum)) {
				map=new HashMap<>();
				map.put(0l, -1);
				sum=a[i];
				gg++;
			}
			map.put(sum, i);
		}
		out.println(gg);
	}
	
	
	
	
	
	void print(int a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
	}
	
	
	
	
	
	

	
	static class Pair implements Comparable<Pair> {
		int f, s;
		Pair () {}
		Pair (int l_, int r_) {
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
	
	static class Str implements Comparable<Str> {
		String s;
		Str(String s){
			this.s=s;
		}
		@Override
		public int compareTo(Str other) {
			return (s+other.s).compareTo(other.s+s);
		}
	}
	
	class TNode {
		TNode c0,c1;
		int n1,n0,val,level;
		TNode(int level){
			this.level=level;
			val=n0=n1=0;
		}
		
		void add(int x) {
			if(level>=0) {
				if((x& 1<<level)==0) {
					if(n0==0) c0=new TNode(level-1);
					c0.add(x);
					n0++;
				}else {
					if(n1==0) c1=new TNode(level-1);
					c1.add(x);
					n1++;
				}
			}else 
				val=x;
		}
		
		void remove(int x) {
			if(level>=0) {
				if((x&1<<level)==0) {
					c0.remove(x);
					if(--n0==0) c0=null;
				}else {
					c1.remove(x);
					if(--n1==0) c1=null;
				}
			}
		}
		
		int find(int x) {
			if(level>=0) {
				if((x&1<<level)==0 && c1!=null){
					return c1.find(x);
				}else if((x&1<<level)!=0 && c0!=null) {
					return c0.find(x);
				}
				return c0!=null?c0.find(x):c1.find(x);
			}else 
				return val;
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
