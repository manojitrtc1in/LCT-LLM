

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
	
	int n;
	
	

	void main() {
		
		n=inp.nextInt();
		String s=inp.next();
		String t=inp.next();
		int sum=0;
		for(int i=0;i<n;i++) {
			if(s.charAt(i)==t.charAt(i)) continue;
			else if(s.charAt(i)=='1') sum++;
			else sum--;
		}
		if(sum!=0) out.println(-1);
		else {
			int a[]=id1(s,t);
			n=a.length;
			int gg=0,cur=0,max=0,min=0;
			for(int i=0;i<n;i++) {
				cur+=a[i];
				if(cur<0) cur=0;
				max=Math.max(cur, max);
			}
			cur=0;
			for(int i=0;i<n;i++) {
				cur+=a[i];
				if(cur>0) cur=0;
				min=Math.min(cur, min);
			}
			gg=Math.max(max, -1*min);
			out.println(gg);
		}
	}
	
	int[] id1(String s, String t) {
		ArrayList<Integer> list=new ArrayList<>();
		for(int i=0;i<n;i++) {
			if(s.charAt(i)==t.charAt(i)) continue;
			if(s.charAt(i)=='1') list.add(1);
			else list.add(-1);
		}
		int len=list.size();
		int gg[]=new int[len];
		for(int i=0;i<len;i++) gg[i]=list.get(i);
		return gg;
	}
	
	
	static class Pair implements Comparable<Pair> {
		int f, s, tea;
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
