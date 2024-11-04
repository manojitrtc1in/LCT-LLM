

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
		int m=inp.nextInt();
		int k=inp.nextInt();
		ArrayList<Edge> list[]=new ArrayList[n];
		for(int i=0;i<n;i++) list[i]=new ArrayList<Edge>();
		Pair[] edges=new Pair[m];
		for(int i=0;i<m;i++) {
			int x=inp.nextInt()-1;
			int y=inp.nextInt()-1;
			int w=inp.nextInt();
			list[x].add(new Edge(y,w));
			list[y].add(new Edge(x,w));
			edges[i]=new Pair(x,y);
		}
		int dist[][]=new int[n][n];
		for(int i=0;i<n;i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
		int dp[]=new int[m];
		for(int i=0;i<n;i++) {
			dist[i][i]=0;
			PriorityQueue<Vertex> pq=new PriorityQueue<>();
			pq.add(new Vertex(i,0));
			while(!pq.isEmpty()) {
				Vertex u=pq.poll();
				for(Edge x: list[u.idx]) {
					int v=x.to;
					int w=x.weight;
					if(dist[i][v]>dist[i][u.idx]+w) {
						dist[i][v]=dist[i][u.idx]+w;
						pq.add(new Vertex(v,dist[i][v]));
					}
				}
			}
		}
		int gg=0;
		int r1[]=new int[k];
		int r2[]=new int[k];
		for(int i=0;i<k;i++) {
			r1[i]=inp.nextInt()-1;
			r2[i]=inp.nextInt()-1;
			gg+=dist[r1[i]][r2[i]];
		}
		int wp=0;
		for(int i=0;i<m;i++) {
			for(int j=0;j<k;j++) {
				dp[i]+=Math.max(0, dist[r1[j]][r2[j]]- 
						Math.min( dist[r1[j]][edges[i].from]+ dist[r2[j]][edges[i].to],
									dist[r2[j]][edges[i].from]+dist[r1[j]][edges[i].to]));
			}
			wp=Math.max(wp, dp[i]);
		}
		out.println(gg-wp);
	}
	
	class Pair {
		int from,to;
		Pair(int x, int y){
			from=x;
			to=y;
		}
	}
	
	class Vertex implements Comparable<Vertex> {
		int idx, dist;
		Vertex(int to, int w){
			this.idx=to;
			dist=w;
		}
		public int compareTo(Vertex o) {
			return Integer.compare(dist, o.dist);
		}
	}
	
	class Edge implements Comparable<Edge>{
		int to, weight;
		Edge(int to, int w){
			this.to=to;
			weight=w;
		}
		public int compareTo(Edge o) {
			return Integer.compare(weight, o.weight);
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
