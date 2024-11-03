

import java.util.*;
import java.io.*;
public class _InVoker_ {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	_InVoker_ g=new _InVoker_();
	   	g.main();
	   	out.close();
	}
	
	
	
	

	void main() {
		
		int t=inp.nextInt();
		while(t-->0) {
			int n=inp.nextInt();
			int m=inp.nextInt();
			String s=inp.next();
			int pref[]=new int[n+1];
			int min[]=new int[n+1];
			int max[]=new int[n+1];
			int cur=0;
			for(int i=0;i<n;i++) {
				if(s.charAt(i)=='+') cur++;
				else cur--;
				min[i+1]=Math.min(min[i], cur);
				max[i+1]=Math.max(cur, max[i]);
				pref[i+1]=cur;
			}
			SegTree st=new SegTree(n+1);
			st.build(pref, 1, 0, n);
			while(m-->0) {
				int l=inp.nextInt()-1;
				int r=inp.nextInt();
				int x1=min[l];
				int y1=max[l];
				if(r!=n) {
					int pos=pref[l];
					x1=Math.min(x1, pos-(pref[r]-st.query(r,n).min));
					y1=Math.max(y1, pos+(st.query(r, n).max-pref[r]));
				}
				out.println(y1-x1+1);
			}
		}
		
	}
	
	class SegTree {
		int n;
		Item seg[];
		SegTree(int n){
			this.n=n;
			seg=new Item[4*n];
		}
		void build(int a[], int x,int lx, int rx) {
			if(lx==rx) {
				seg[x]=new Item(a[lx],a[lx]);
				return;
			}
			int mid=lx+rx>>1;
			build(a,2*x,lx,mid);
			build(a,2*x+1,mid+1,rx);
			seg[x]=merge(seg[2*x],seg[2*x+1]);
		}
		Item merge(Item x, Item y) {
			return new Item(Math.min(x.min,y.min),Math.max(x.max, y.max));
		}
		Item query(int l, int r) {
			return query(l,r,1,0,n-1);
		}
		Item query(int l, int r, int x, int lx, int rx) {
			if(l<=lx && r>=rx) return seg[x];
			if(l>rx || r<lx) return neutral;
			int mid=lx+rx>>1;
			return merge(query(l,r,2*x,lx,mid),query(l,r,2*x+1,mid+1,rx));
		}
		
	}
	Item neutral=new Item(Integer.MAX_VALUE,Integer.MIN_VALUE);
	class Item {
		int min,max;
		Item(int min, int max){
			this.min=min;
			this.max=max;
		}
	}
	
	
	

	void sort(int a[]) {
		ArrayList<Integer> list=new ArrayList<>();
		for(int x: a) list.add(x);
		Collections.sort(list);
		for(int i=0;i<a.length;i++) a[i]=list.get(i);
	}
	void sort(long a[]) {
		ArrayList<Long> list=new ArrayList<>();
		for(long x: a) list.add(x);
		Collections.sort(list);
		for(int i=0;i<a.length;i++) a[i]=list.get(i);
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
	void ruffleSort(long a[]) {
		Random rand=new Random();
		int n=a.length;
		for(int i=0;i<n;i++) {
			int j=rand.nextInt(n);
			long temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		Arrays.sort(a);
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
	long modInv(long x) {
		return power(x,mod-2);
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
	
	void print(int a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
		out.println();
	}
	
	void print(long a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
		out.println();
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
