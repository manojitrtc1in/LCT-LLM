

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
	
	int dps[][]=new int[1001][1001];
	int r,n,m;
	
	int numSnakes(int x1, int y1, int x2, int y2) {
		x1=Math.max(x1,1);
		x2=Math.min(x2,1000);
		y1=Math.max(y1,1);
		y2=Math.min(y2,1000);
		if(x1>x2 || y1>y2) return 0;
		return dps[x2][y2]-dps[x2][y1-1]-dps[x1-1][y2]+dps[x1-1][y1-1];
	}
	
	int snakesInContact(int x, int y) {
		return numSnakes(x-r, y-r, x+r, y+r);
	}
	
	

	void main() {
		
		n=inp.nextInt();
		m=inp.nextInt();
		r=inp.nextInt();
		int x[]=new int[n];
		int y[]=new int[n];
		long danger[]=new long[n];
		for(int i=0;i<n;i++) {
			x[i]=inp.nextInt();
			y[i]=inp.nextInt();
			danger[i]=inp.nextLong();
			dps[x[i]][y[i]]++;
		}
		

		for(int i=1;i<=1000;i++) {
			for(int j=1;j<=1000;j++) {
				dps[i][j]+= dps[i][j-1]+dps[i-1][j] -dps[i-1][j-1];  

			}
		}
		

		long gg=0;
		init(2000); 

		for(int i=0;i<n;i++) {
			for(int j=i;j<n;j++) {
				int x1=x[i],y1=y[i],x2=x[j],y2=y[j];
				
				int minx=Math.max(x1,x2)-r;
				int miny=Math.max(y1,y2)-r;
				int maxx=Math.min(x1,x2)+r;
				int maxy=Math.min(y1,y2)+r;
				int w=numSnakes(minx,miny,maxx,maxy); 

				long count= nCr(n,m)-nCr(n-w,m);
				if(count<0) count+=mod;
				
				int u=snakesInContact(x1,y1)-w;
				int v=snakesInContact(x2,y2)-w;
				count+= nCr(n-w,m) -nCr(n-u-w,m) - nCr(n-v-w,m) + nCr(n-w-u-v,m);
				count%=mod;
				if(count<0) count+=mod;
				gg+=mul(mul(count,danger[i]),(i==j?danger[i]:mul(2,danger[j])));
				gg%=mod;
			}
		}
		out.println(gg);
	}
	
	void print(int dp[][], int n) {
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=n;j++) out.print(dp[i][j]+" ");
			out.println();
		}
		out.println();
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
	
	class Event implements Comparable<Event>{
		long x;
		boolean start;
		Event(long x, boolean boo){
			this.x=x;
			start=boo;
		}
		@Override
		public int compareTo(Event other) {
			if(this.x==other.x) {
				if(this.start==other.start) return 0;
				else if(this.start==false) return -1;
				else return -1;
			}
			return Long.compare(this.x,other.x);
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
    
	long fact[];
	long invFact[];
	void init(int n) {
		fact=new long[n+1];
		invFact=new long[n+1];
		fact[0]=1;
		for(int i=1;i<=n;i++) {
			fact[i]=mul(i,fact[i-1]);
		}
		invFact[n]=power(fact[n],mod-2);
		for(int i=n-1;i>=0;i--) {
			invFact[i]=mul(invFact[i+1],i+1);
		}
	}
	
	long nCr(int n, int r) {
		if(n<r || r<0) return 0;
		return mul(fact[n],mul(invFact[r],invFact[n-r]));
	}
	
	long mul(long a, long b) {
		return a*b%mod;
	}
	long add(long a, long b) {
		return (a+b)%mod;
	}
	
	long power(long x, long y) {
		long gg=1;
		while(y>0) {
			if(y%2==1) gg=mul(gg,x);
			x=mul(x,x);
			y/=2;
		}
		return gg;
	}
    
    

	static long gcd(long a, long b) { 
		return b==0?a:gcd(b,a%b);
	}
	static int gcd(int a, int b) { 
		return b==0?a:gcd(b,a%b);
	}
	
	void ruffleSort(int a[]) {
		Random rand=new Random();
		int n=a.length;
		for(int i=0;i<n;i++) {
			int j=rand.nextInt(n);
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		Arrays.sort(a);
	}
	
	void print(int a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
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
