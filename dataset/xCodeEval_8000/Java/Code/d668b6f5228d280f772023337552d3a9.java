

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

	ArrayList<Edge> edges[];
	ArrayList<Long> sums = new ArrayList<Long>();
	int gg[];
	boolean vis[];
	
	

	void main() {
		
		

		int t=inp.nextInt();
		loop:
		while(t-->0) {
			int n=inp.nextInt();
			gg=new int[n];
			vis=new boolean[n];
			edges = new ArrayList[n];
			for(int i=0;i<n;i++) {
				edges[i]=new ArrayList<Edge>();
			}
			for(int i=0;i<n-1;i++) {
				int to=inp.nextInt()-1;
				int a=inp.nextInt();
				int b=inp.nextInt();
				edges[i+1].add(new Edge(to, a, b));
				edges[to].add(new Edge(i+1, a ,b));
			}
			vis[0]=true;
			dfs(0, 0, 0, 0);
			for(int i=1;i<n;i++) {
				out.print((gg[i]+1)+" ");
			}
			out.println();
		}
		
	}
	
	void dfs(int i, int depth, long sum1, long sum2) {
		for(Edge edge: edges[i]) {
			if (vis[edge.to]) continue;
			vis[edge.to]=true;
			sums.add(sum2+edge.b);
			gg[edge.to]=getIndex(sums, sum1+edge.a);
			dfs(edge.to, depth+1, sum1 + edge.a, sum2 +edge.b);
			sums.remove(depth);
		}
	}
	
	class Edge {
		int to;
		long a,b;
		Edge(int to, long a, long b){
			this.to=to;
			this.a=a;
			this.b=b;
		}
	}
	
	int getIndex( ArrayList<Long> list, long value )
	{
	    int top = 0;
	    int bot = list.size()-1;
	    int mid=0;
	    while ( top <= bot )
	    {
	        mid = top+bot>>1;
	        if ( value < list.get(mid) )
	        {
	            if ( mid == 0 )
	                return -1;  
	            else
	                bot = mid-1;
	        }
	        else
	        {
	            if ( mid == list.size()-1 )
	                break;
	            else if ( value >= list.get(mid+1) )
	                top = mid+1;
	            else
	                break;
	        }
	    }
	    return mid;
	}
	
	
	
	String god = "Sambhav";
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
	
	static long gcd(long a, long b) { 
		return b==0?a:gcd(b,a%b);
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
	long add(long a, long b) {
		return (a+b)%mod;
	}
	
	long mul(long a, long b) {
		return a*b%mod;
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
