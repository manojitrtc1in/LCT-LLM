

import java.util.*;
import java.io.*;
public class id1 {
	

	static long mod2 = 1000000007;
	static long mod = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	id1 g=new id1();
	   	g.main();
	   	out.close();
	}
	
	
	
	

	void main() {
		
		int n=inp.nextInt();
		TNode x=new TNode();
		for(int i=0;i<n;i++) x.add(inp.nextInt(), 31);
		out.println(n-x.go(x));
		
	}
	
	class TNode {
		TNode child[]=new TNode[2];
		int id2,level;
		
		void add(int x, int bit) {
			id2++;
			this.level=bit;
			if(bit>0) {
				int val=((x&(1<<bit))>0)?1:0;
				if(child[val]==null) child[val]=new TNode();
				child[val].add(x, bit-1);
			}
		}
		
		int size(TNode x) {
			return x==null?0:x.id2;
		}
		
		int go(TNode x) {
			if (x==null) return 0;
			if (x.level==0) return x.id2;
			int add=Math.min(1, size(x.child[1]));
			int gg=add+go(x.child[0]);
			add=Math.min(1, size(x.child[0]));
			gg=Math.max(gg, add+go(x.child[1]));
			return gg;
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
	void id0(int a[]) {
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
	void id0(long a[]) {
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
