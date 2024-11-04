import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {
	static ArrayList<Integer> adj[];

	static int k;
	static int[] a;
	static int b[];
	static int m;

	static class Pair implements Comparable<Pair> {
		int a;
		int  b;
		public Pair(int c,int l) {
			a = c;
			b = l;
		}
		@Override
		public int compareTo(Pair o) {
		if(o.a==this.a)
			return this.b-o.b;
		return this.a-o.a;
	}
}

	static ArrayList<Pair> adjlist[];
	

	static long mod = (long) (1e9+7);
	static int V;
	static long INF = (long) 1E16;
	static int n;
	static char c[];
	static Pair p[];
static int grid[][];
static Scanner sc = new Scanner(System.in);
static PrintWriter out = new PrintWriter(System.out);
static long div[];
public static void main(String args[]) throws Exception {
	int maxN=(int)(1e6);
	div=new long [maxN+1];
	for(int i=1;i<=maxN;i++)
		for(int j=i;j<=maxN;j+=i)
			div[j]++;
	int n=sc.nextInt();
	int N=1;
	while(N<n)
		N<<=1;
	long a[]=new long[N+1];
	int q=sc.nextInt();
	for (int i =1; i<=n; i++) {
		a[i]=sc.nextInt();
	}
	SegmentTree st=new SegmentTree(a);
    while(q-->0) {
	int t=sc.nextInt();
    int l=sc.nextInt();
	int r=sc.nextInt();
	if(t==1) {
		st.update_range(l,r,0);
	}
	else if(t==2) {
	out.println(st.query(l,r));	
	}
	}
	
	out.flush();
}
static int s;

	static class Query implements Comparable<Query>
	{
						

		int left, right, idx;
		int block;
		Query(int a, int b, int c)
		{
			left = a; right = b; idx = c;
			block=left/s;
		}
		
		public int compareTo(Query q)
		{
		if(q.block==this.block)
			return right-q.right;
		return block-q.block;
		}	
	}

static void dfs(int u) {
	vis[u]=true;
	for(int v:adj[u]) {
		if(!vis[v]) {
			dfs(v);
		}
	}
}

static int[] compreessarray(int c[]) {
	int b[]=new int[c.length];
	
	for (int i = 0; i < b.length; i++) {
		b[i]=c[i];
	}
	sortarray(c);
	TreeMap<Integer,Integer> map=new TreeMap<>();
	int id=0;
	for (int i = 0; i < c.length; i++) {
		if(!map.containsKey(c[i]))
			id++;
		map.put(c[i],map.getOrDefault(c[i],id));
	
	}
	int idx=0;
	for (int i = 0; i < c.length; i++) {
		joke.put(b[i],map.get(b[i]));
		b[i]=map.get(b[i]);
	}
	
	return b;
}
static TreeMap<Integer,Integer> joke=new TreeMap<>();
static int div4[];
static long [] reversearray(long a[]) {
	for (int i = 0; i <a.length/2; i++) {
		long temp=a[i];
		a[i]=a[a.length-i-1];
		a[a.length-i-1]=temp;
	}
	return a;
}
static int [] reversearray(int a[]) {
	for (int i = 0; i <=a.length/2; i++) {
		int temp=a[i];
		a[i]=a[a.length-i-1];
		a[a.length-i-1]=temp;
	}
	return a;
}
static class SegmentTree {		

	
	int N; 			

	long[] array, sTree, lazy;
	long max[];
	SegmentTree(long[] in)		
	{
		array = in; N = in.length - 1;
		sTree = new long[N<<1];		

		lazy = new long[N<<1];
		max=new long[N<<1];
		build(1,1,N);
	}
	
	void build(int node, int b, int e)	

	{
		if(b == e)	{				
			sTree[node] = array[b];
			max[node]=array[b];
		}
		else						
		{
			int mid = b + e >> 1;
			build(node<<1,b,mid);
			build(node<<1|1,mid+1,e);
			sTree[node] = sTree[node<<1]+sTree[node<<1|1];
			max[node]=Math.max(max[node<<1],max[node<<1|1]);
		}
	}
	
	
	void update_point(int index, int val)			

	{
		index += N - 1;				
		sTree[index] += val;			
		while(index>1)				
		{
			index >>= 1;
			sTree[index] = sTree[index<<1] + sTree[index<<1|1];		
		}
	}
	
	
	void update_range(int i, int j, int val)		

	{
		update_range(1,1,N,i,j,val);
	}
	
	void update_range(int node, int b, int e, int i, int j, int val)
	{
		if(i > e || j < b||max[node]==1||max[node]==2)		
			return;	
		if(b==e)		
		{
		sTree[node]=div[(int) sTree[node]];
		max[node]=sTree[node];
		}							
		else		
		{
			int mid = b + e >> 1;
		

			update_range(node<<1,b,mid,i,j,val);
			update_range(node<<1|1,mid+1,e,i,j,val);
			sTree[node] = sTree[node<<1] + sTree[node<<1|1];		
			max[node]=Math.max(max[node<<1],max[node<<1|1]);
		}
		
	}
















	
	long query(int i, int j)
	{
		return query(1,1,N,i,j);
	}
	
	long query(int node, int b, int e, int i, int j)	

	{
		if(i>e || j <b)
			return 0;		
		if(b>= i && e <= j)
			return sTree[node];
		int mid = b + e >> 1;
	

		long q1 = query(node<<1,b,mid,i,j);
		long q2 = query(node<<1|1,mid+1,e,i,j);
		return q1+q2;	
				
	}
}

static  TreeSet<Integer> ts=new TreeSet();
static HashMap<Integer, Integer> compress(int a[]) {
		 ts = new TreeSet<>();
		HashMap<Integer, Integer> hm = new HashMap<>();
		for (int x : a)
			ts.add(x);
		for (int x : ts) {
			hm.put(x, hm.size() + 1);
		}
		return hm;
	}	

	static  class FenwickTree { 


		int n;
		long[] ft;
		
		FenwickTree(int size) { n = size; ft = new long[n+1]; }
		
		long rsq(int b) 

		{
			long sum = 0;
			while(b<=n) { sum += ft[b]; b += b & -b;}		

			return sum;
		}
		
		long rsq(int a, int b) { return rsq(b) - rsq(a-1); }	
		
		
		void point_update(int k, long l)	

		{
			while(k>0) { ft[k] += l; k -= k & -k;
		}
		}
	}
	static ArrayList<Integer> euler=new ArrayList<>();
	


	
static long total;
static TreeMap<Integer,Integer> map1;

		static int zz;


























static HashMap<Integer,Integer> map;
static int maxa=0;
static int ff=123123;

static int[][] memo;


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
    static TreeSet<Integer> primeFactors(int N)		

	{
		 factors = new TreeSet<Integer>();		

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

	static class UnionFind {
		int[] p, rank, setSize;
		int numSets;
		long max[];
		long largest=0;

		public UnionFind(int N) {
			p = new int[numSets = N];
			rank = new int[N];
			setSize = new int[N];
			max=new long[N];
			for (int i = 0; i < N; i++) {
				p[i] = i;
				setSize[i] = 1;
			}
			largest=0;
		}

		public int findSet(int i) {
			return p[i] == i ? i : (p[i] = findSet(p[i]));
		}
		public void addmax(int i,int val) {
			max[i]=val;
			largest=Math.max(largest,max[i]);
		}
		public boolean isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		

		public void unionSet(int i, int j) {
			if (isSameSet(i, j))
				return;
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
				max[x]+=max[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
				max[y]+=max[x];
			}
			largest=Math.max(max[x],largest);
			largest=Math.max(max[y],largest);
			
		}

		

		public int numDisjointSets() {
			return numSets;
		}

		public int sizeOfSet(int i) {
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

	static long manhatandistance(long x, long x2, long y, long y2) {
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

		Point(long counth, long counts) {
			x = counth;
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
	static HashSet<Integer> set = new HashSet<Integer>();

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
	
	static void sieveLinear(int N)
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

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}

		public int[] nxtArr(int n) throws IOException {
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