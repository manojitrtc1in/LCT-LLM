    import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	static ArrayList<Integer> adj[];
	


	static int [][]notmemo;
	static int k;
	static long[] a;
	static int b[];
	static int m;


	static class Pair implements Comparable<Pair>  {
    	int node; 
    	long cost;
		public Pair(int b,long l) {
		node=b;
	   cost=l;
		}
		@Override
		public int compareTo(Pair o) {
		return Long.compare(this.cost,o.cost);
		}
	
		
    }
    static Pair s1[];
    static ArrayList<Edge> adjlist[];
	

	public static long mod= 1000000007;
static int V;
static long INF = (long) 1E16;
static int n;
static int s;
static char c[];
static int d[];
static int z;
static int p[];
static int h[];
static int count[][];
public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t=sc.nextInt();
		label:while(t-->0) {
			int n=sc.nextInt();
			char c[]=sc.nextLine().toCharArray();
			int sb0=0;
			int sb1=0;
			int maxgroup=1;
			int b[]=new int[c.length];
			for (int i = 0; i < c.length; i++) {
				if(i==0) {
					if(c[i]=='0') {
						sb0++;
					}
					else
						sb1++;
					b[i]=1;
					continue;
				}
				if(c[i]=='0'&&sb1==0) {
					maxgroup++;
					sb0++;
					b[i]=maxgroup;
				}
				else if(c[i]=='1'&&sb0==0) {
					maxgroup++;
					sb1++;
					b[i]=maxgroup;
				}
				else if(c[i]=='0'&&sb1>0) {
					b[i]=(maxgroup-sb1)+1;
					sb1--;
					sb0++;
				}
				else if(c[i]=='1'&&sb0>0) {
					b[i]=sb0;
					sb0--;
					sb1++;
				}
				
				
			}
		   out.println(maxgroup);
			for(int x:b) {
				out.print(x+" ");
			}
			out.println();
}
		
		
out.flush();
}

static ArrayList<Integer> inc=new ArrayList<>();
static Stack<Integer> dec=new Stack<>();
static long total;
static void dfs(int u) {
vis[u]=true;
for(int v:adj[u]) {
	if(!vis[v]) {
		dfs(v);
	}
}
total+=(a[u]*1l);
if(a[u]>0) {
	if(h[u]!=-2)
	a[h[u]]+=a[u];
	inc.add(u);
}
else {
	dec.add(u);
}

}
		static int zz;


























static HashMap<Integer,Integer> map;
static int maxa=0;
static int ff=123123;

static long dist[][];
static int[][][] memo;
static void dijkstra(int S)	

{
	
	 dist = new long[n][maxa+1];
	for(long x[]:dist)
	Arrays.fill(x, (long) 1e17);
	
	PriorityQueue<Edge> pq = new PriorityQueue<>();
	dist[0][S] = 0;	
	pq.add(new Edge(0,S,0));						

	while(!pq.isEmpty())
	{
	Edge cur=pq.poll();
	int mincoins=(int) Math.min(maxa,cur.cost+c[cur.node]);
	if(cur.time+d[cur.node]<dist[cur.node][mincoins]) {
		pq.add(new Edge(cur.node,mincoins,dist[cur.node][mincoins]=cur.time+d[cur.node]));
	}

	for(Edge e:adjlist[cur.node]) {
	if(cur.cost<e.cost)
		continue;
	if(cur.time+e.time<dist[(int) e.node][(int) (cur.cost-e.cost)]) {
		pq.add(new Edge(e.node,cur.cost-e.cost,dist[e.node][(int) (cur.cost-e.cost)]=cur.time+e.time));	
	}
	}
	}
}


	static long modmod=998244353;
	static int dx[]= {1,-1,0,0};
	 static int dy[]= {0,0,1,-1};	
	static class BBOOK implements Comparable<BBOOK>{
		int t;
		int alice;
		int bob;
		public BBOOK(int x,int y,int z) {
		t=x;
		alice=y;
		bob=z;
		}
		@Override
		public int compareTo(BBOOK o) {
			return this.t-o.t;
		}
	}
	private static long lcm(long a2, long b2) {
	return (a2*b2)/gcd(a2,b2);
	}
	static class Edge implements Comparable<Edge>
	{
		int node;long cost ; long time; 
		
		Edge(int a, long b,long c) { node = a;	cost = b; time=c; }
		
		public int compareTo(Edge e){ return Long.compare(time,e.time);	}
	}
	
        static void sieve(int N)	

	{
		isComposite = new int[N+1];					
		isComposite[0] = isComposite[1] = 1;			

		primes = new ArrayList<Integer>();
 
		for (int i = 2; i <= N; ++i) 					

			if (isComposite[i] == 0) 					

			{
				primes.add(i);
				if(1l * i * i <= N)
					for (int j = i * i; j <= N; j += i)	

						isComposite[j] = 1;
			}   
	}
    static TreeSet<Integer> factors;
    static ArrayList<Integer> primeFactors(int N)		

	{
		ArrayList<Integer> factors = new ArrayList<Integer>();		

		int idx = 0, p = primes.get(idx);

		while(1l*p * p <= N)
		{
			while(N % p == 0) { factors.add(p); N /= p; }
			p = primes.get(++idx);
		}

		if(N != 1)						

			factors.add(N);				

		return factors;
	}
	static class SegmentTree { 


		int N; 			

		int[] array, sTree, lazy;
		
		SegmentTree(int[] in)		
		{
			array = in; N = in.length - 1;
			sTree = new int[N<<1];		

			lazy = new int[N<<1];
			Arrays.fill(sTree, (int) 1e9);
			build(1,1,N);
		}
		
		void build(int node, int b, int e)	

		{
			if(b == e)					
				sTree[node] = array[b];
			else						
			{
				int mid = b + e >> 1;
				build(node<<1,b,mid);
				build(node<<1|1,mid+1,e);
				sTree[node] = Math.min(sTree[node<<1],sTree[node<<1|1]);
			}
		}
		
		
		void update_point(int index, int val)			

		{
			index += N - 1;				
			sTree[index] = val;			
			while(index>1)				
			{
				index >>= 1;
				sTree[index] = Math.min(sTree[index<<1],sTree[index<<1|1]);		
			}
		}
		
		
		void update_range(int i, int j, int val)		

		{
			update_range(1,1,N,i,j,val);
		}
		
		void update_range(int node, int b, int e, int i, int j, int val)
		{
			if(i > e || j < b)		
				return;
			if(b >= i && e <= j)		
			{
				sTree[node] += (e-b+1)*val;			
				lazy[node] += val;				
			}							
			else		
			{
				int mid = b + e >> 1;
				propagate(node, b, mid, e);
				update_range(node<<1,b,mid,i,j,val);
				update_range(node<<1|1,mid+1,e,i,j,val);
				sTree[node] = sTree[node<<1] + sTree[node<<1|1];		
			}
			
		}
		void propagate(int node, int b, int mid, int e)		
		{
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
			sTree[node<<1] += (mid-b+1)*lazy[node];		
			sTree[node<<1|1] += (e-mid)*lazy[node];		
			lazy[node] = 0;
		}
		
		int query(int i, int j)
		{
			return query(1,1,N,i,j);
		}
		
		int query(int node, int b, int e, int i, int j)	

		{
			if(i>e || j <b)
				return 0;		
			if(b>= i && e <= j)
				return sTree[node];
			int mid = b + e >> 1;
			propagate(node, b, mid, e);
			int q1 = query(node<<1,b,mid,i,j);
			int q2 = query(node<<1|1,mid+1,e,i,j);
			return Math.min(q1,q2);	
					
		}
		
		
	}
	static class UnionFind {
		int[] p, rank, setSize;
		int numSets;
		int max[];

		public UnionFind(int N) {
			p = new int[numSets = N];
			rank = new int[N];
			setSize = new int[N];
			for (int i = 0; i < N; i++) {
				p[i] = i;
				setSize[i] = 1;
			}
		}

		public int findSet(int i) {
			return p[i] == i ? i : (p[i] = findSet(p[i]));
		}

		public boolean id5(int i, int j) {
			return findSet(i) == findSet(j);
		}
		public int chunion(int i,int j, int x2) {
			if (id5(i, j))
				return 0;
			numSets--;
			int x = findSet(i), y = findSet(j);
			int z=findSet(x2);
			p[x]=z;;
			p[y]=z;
		return x;
		}

		public void unionSet(int i, int j) {
			if (id5(i, j))
				return;
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];


			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;


			}
		}

		

		public int id7() {
			return numSets;
		}

		public int id2(int i) {
			return setSize[findSet(i)];
		}
	}


	static class Quad implements Comparable<Quad> {
		int u;
		int v;
		char state;
		int turns;

		public Quad(int i, int j, char c, int k) {
			u = i;
			v = j;
			state = c;
			turns = k;
		}

		public int compareTo(Quad e) {
			return (int) (turns - e.turns);
		}

	}

	static long id0(long x, long x2, long y, long y2) {
		return Math.abs(x - x2) + Math.abs(y - y2);
	}

	static long fib[];

	static long fib(int n) {
		if (n == 1 || n == 0) {
			return 1;
		}
		if (fib[n] != -1) {
			return fib[n];
		} else
			return fib[n] = ((fib(n - 2) % mod + fib(n - 1) % mod) % mod);
	}

	static class Point  implements Comparable<Point>{
		long x, y;

		Point(long id6, long counts) {
			x = id6;
			y = counts;
		}

		@Override
		public int compareTo(Point p )
		{
			return Long.compare(p.y*1l*x, p.x*1l*y);
		}
	}

	static TreeSet<Long> primeFactors(long N) 

	{
		TreeSet<Long> factors = new TreeSet<Long>(); 

		int idx = 0, p = primes.get(idx);

		while (p * p <= N) {
			while (N % p == 0) {
				factors.add((long) p);
				N /= p;
			}
			if (primes.size() > idx + 1)
				p = primes.get(++idx);
			else
				break;
		}

		if (N != 1) 

			factors.add(N); 

		return factors;
	}

	static boolean visited[];

	

	static boolean[] vis2;

	static boolean f2 = false;

	static long[][] matMul(long[][] a2, long[][] b, int p, int q, int r) 

																			

	{
		long[][] C = new long[p][r];
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < q; ++k) {
					C[i][j] = (C[i][j] + (a2[i][k] % mod * b[k][j] % mod)) % mod;
					C[i][j] %= mod;
				}

			}
		}
		return C;
	}
	public static int[] schuffle(int[] a2) {
		for (int i = 0; i < a2.length; i++) {
			int x =  (int) (Math.random() * a2.length);
			int temp = a2[x];
			a2[x] = a2[i];
			a2[i] = temp;
		}
		return a2;
	}


	static boolean vis[];
	static TreeSet<Integer> set = new TreeSet<Integer>();

	static long modPow(long ways, long count, long mod) 

	{
		ways %= mod;
		long res = 1;
		while (count > 0) {
			if ((count & 1) == 1)
				res = (res * ways) % mod;
			ways = (ways * ways) % mod;
			count >>= 1;
		}
		return res % mod;
	}

	static long gcd(long l, long o) {
		if (o == 0) {
			return l;
		}
		return gcd(o, l % o);
	}

	static int[] isComposite;
	static int[] valid;

	static ArrayList<Integer> primes;
	static ArrayList<Integer> l1;

	
	static TreeSet<Integer> primus = new TreeSet<Integer>();
	
	static void id4(int N)
	{
		int[] lp = new int[N + 1];								

		for(int i = 2; i <= N; ++i)
		{
			if(lp[i] == 0)
			{
				primus.add(i);
				lp[i] = i;
			}
			int curLP = lp[i];
			for(int p: primus)
				if(p > curLP || p * i > N)
					break;
				else
					lp[p * i] = i;
		}
	}
	

	public static long[] schuffle(long[] a2) {
		for (int i = 0; i < a2.length; i++) {
			int x =  (int) (Math.random() * a2.length);
			long temp = a2[x];
			a2[x] = a2[i];
			a2[i] = temp;
		}
		return a2;
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void id1() throws InterruptedException {
			Thread.sleep(3000);
		}

		public int[] id3(int n) throws IOException {
			int[] ans = new int[n];
			for (int i = 0; i < n; i++)
				ans[i] = nextInt();
			return ans;
		}
		
	}
	public static int[] sortarray(int a[]) {
		schuffle(a);
		Arrays.sort(a);
		return a;
		}
		public static long[] sortarray(long a[]) {
			schuffle(a);
			Arrays.sort(a);
			return a;
		}
}