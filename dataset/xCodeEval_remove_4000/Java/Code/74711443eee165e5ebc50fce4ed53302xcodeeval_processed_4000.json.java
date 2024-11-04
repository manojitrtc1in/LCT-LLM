

import java.util.*;
import java.io.*;
public class id2 {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	id2 g=new id2();
	   	g.main();
	   	out.close();
	}
	
	
	
	

	void main() {
		
		int n=inp.nextInt();
		int xandy=query("AND",1,2);
		int xory=query("OR",1,2);
		int id1=query("AND",2,3);
		int yorz=query("OR",2,3);
		int id3=query("AND",1,3);
		int x=0,y=0,z=0;
		for(int i=0;i<16;i++) {
			int a=bit(xandy,i);
			int b=bit(xory,i);
			int c=bit(id1,i);
			int d=bit(yorz,i);
			int e=bit(id3,i);
			if(b==0 && d==0) {
				;
			}else if(b==0 && d==1) {
				z|= 1<<i;
			}else if(a==1 && c==0) {
				x|=1<<i;
				y|=1<<i;
			}else if(a==1 && c==1) {
				x|=1<<i;
				y|=1<<i;
				z|=1<<i;
			}else if(d==0 && b==1) {
				x|=1<<i;
			}else if(a==0 && c==1) {
				y|=1<<i;
				z|=1<<i;
			}else if(e==0) {
				y|=1<<i;
			}else {
				x|=1<<i;
				z|=1<<i;
			}
		}
		int gg[]=new int[n];
		gg[0]=x;
		gg[1]=y;
		gg[2]=z;
		for(int i=4;i<=n;i++) {
			gg[i-1]=x^query("XOR",1,i);
		}
		System.out.print("!");
		for(int i=0;i<n;i++) System.out.print(" "+gg[i]);
		System.out.println();
	}
	
	
	
	int query(String s, int x, int y) {
		System.out.println(s+" "+x+" "+y);
		return inp.nextInt();
	}
	
	int bit(int x, int i) {
		return (x>>i)&1;
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
