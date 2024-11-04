

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
		int a[]=new int[n];
		for(int i=0;i<n;i++) a[i]=inp.nextInt();
		ArrayList<Pair> ggs[]=new ArrayList[n];
		int c=0;
		int times=0;
		loop:
		for(int i=0;i<n && times<n;i++) {
			int cur=a[i];
			for(int j=i+1;j<n;j++) {
				if(a[j]+1==a[i]) { 

					ArrayList<Pair> list=new ArrayList<>();
					list.add(new Pair(0,i-1));
					int k=i+1;
					for(;k<n;k++) {
						if(a[k]!=cur+(k-i)) {
							list.add(new Pair(i,k-1));
							break;
						}
					}
					list.add(new Pair(k,j));
					list.add(new Pair(j+1,n-1));
					int temp[]=new int[n],idx=0;
					for(k=3;k>=0;k--) {
						int left=list.get(k).start;
						int right=list.get(k).end;
						for(int p=left;p<=right;p++) {
							temp[idx++]=a[p];
						}
					}
					a=temp;




					ggs[c++]=list;
					i=-1;
					times++;
					continue loop;
				}
			}
		}
		out.println(c);
		ArrayList<Integer> gg[]=new ArrayList[c];
		for(int i=0;i<c;i++) {
			gg[i]=new ArrayList<>();
			for(Pair pair: ggs[i]) {
				

				if(pair.start<=pair.end) gg[i].add(pair.end-pair.start+1);
			}
			out.print(gg[i].size()+" ");
			for(int x: gg[i]) {
				out.print(x+" ");
			}
			out.println();
		}
	}
	
	class Pair {
		int start, end;
		Pair(int x, int y){
			start=x;
			end=y;
		}
	}
	
	class Segment implements Comparable<Segment> {
		int l, r, len;
		Segment () {}
		Segment (int l_, int r_, int d_) {
		    this.l = l_;
		    this.r = r_;
		    this.len = d_;
		}
		@Override
		public int compareTo(Segment o) {
		    return (int)((len - o.len) !=0 ? len-o.len : o.r - r);
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
	
	void id1(int a[]) {
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