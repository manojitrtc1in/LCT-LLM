

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
		while(t-->0) {
			long x=inp.nextLong();
			long y=inp.nextLong();
			long c[]=new long[7];
			for(int i=1;i<=6;i++) c[i]=inp.nextLong();
			long gg;
			if(x>=0 && y>=0) {
				if(y>=x) {
					gg=Math.min(c[1]*y+c[3]*(y-x), Math.min(c[2]*y+c[6]*x,c[1]*x+c[2]*(y-x)));
				}else { 

					gg=Math.min(c[1]*x+c[5]*(x-y), Math.min(c[6]*x+c[2]*y, c[1]*y+c[6]*(x-y)));
				}
			}else if(x>=0) {
				gg=Math.min(c[1]*x+c[5]*(x-y), Math.min(c[5]*(0-y)+c[6]*x,c[4]*(0-y)+c[6]*(x-y)));
			}else if(y>=0) {
				gg=Math.min(c[1]*y+c[3]*(y-x), Math.min(c[3]*(0-x)+c[2]*y,c[4]*(0-x)+c[2]*(y-x)));
			}else {
				if(x<=y) {
					gg=Math.min(c[4]*(0-y)+c[3]*(y-x), Math.min(c[3]*(0-x)+c[5]*(0-y),c[4]*(0-x)+c[2]*(y-x)));
				}else { 

					gg=Math.min(c[4]*(0-x)+c[5]*(x-y), Math.min(c[3]*(0-x)+c[5]*(0-y),c[4]*(0-y)+c[6]*(x-y)));
				}
			}
			out.println(gg);
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
