

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
		
		int t=inp.nextInt();
		loop:
		while(t-->0) {
			int n=inp.nextInt();
			long a[]=new long[n];
			input(a,n);
			SegTree st=new SegTree(n);
			st.build(1, 0, n-1, a);
			long suff[]=new long[n];
			long pref[]=new long[n];
			pref[0]=a[0];
			suff[n-1]=a[n-1];
			for(int i=1;i<n;i++) pref[i]=Math.max(pref[i-1], a[i]);
			for(int i=n-2;i>=0;i--) suff[i]=Math.max(suff[i+1], a[i]);
			HashMap<Long,Integer> id2=new HashMap<>();
			HashMap<Long,Integer> id3=new HashMap<>();
			for(int i=0;i<n;i++) id3.put(suff[i], i);
			for(int i=n-1;i>=0;i--) id2.put(suff[i], i);
			for(int x=0;x+2<n;x++) {
				long cur=pref[x];
				int left=Math.max(x+2, id2.getOrDefault(cur, n));
				int right=id3.getOrDefault(cur, -1);
				while(left<=right) {
					int mid=left+right>>1;
					long min=st.query(x+1, mid-1).min;
					if(min==cur) {
						out.println("YES");
						out.println((x+1)+" "+(mid-x-1)+" "+(n-mid));
						continue loop;
					}else if(min<cur) {
						right=mid-1;
					}else {
						left=mid+1;
					}
				}
			}
			out.println("NO");
		}
		
	}
	
	Item neutral=new Item(Long.MIN_VALUE,Long.MAX_VALUE);
	
	class SegTree {
		int n;
		Item seg[];
		SegTree(int n){
			this.n=n;
			seg=new Item[4*n];
		}
		void build(int x,int lx, int rx, long a[]) {
			if(lx==rx) {
				seg[x]=new Item(a[lx],a[lx]);
				return;
			}
			int mid=lx+rx>>1;
			build(2*x,lx,mid,a);
			build(2*x+1,mid+1,rx,a);
			seg[x]=merge(seg[2*x],seg[2*x+1]);
		}
		Item merge(Item x, Item y) {
			return new Item(Math.max(x.max,y.max), Math.min(x.min, y.min));
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
	
	class Item {
		long max, min;
		Item(long x, long y){
			max=x;
			min=y;
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
	void id1(long a[]) {
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
	}
	
	void print(long a[]) {
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
