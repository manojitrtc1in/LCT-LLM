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
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.lang.Math.*;

import java.util.TreeSet;

public class Main {
	static ArrayList<Integer> adj[];
	static PrintWriter out = new PrintWriter(System.out);
	public static long mod;

	static int [][]notmemo;
	static int k;
	static int[] a;
	static int b[];
	static int m;
	static int c[];


	static class Pair  implements Comparable<Pair>{
    	int v,cost,energy;
		public Pair(int a1,int a2,int e ) {
		v=a1;
		cost=a2;
		energy=e;
    	}
		@Override
		public int compareTo(Pair o) {
		if(o.energy==this.energy)
			return this.cost-o.cost;
		return o.energy-this.energy;
		}
    }
    static Pair s1[];
    static long s[];
    static ArrayList<Pair> adjlist[];
	static int n1;
	static int n2;
	static int k1;
	static int k2;
	static int skip=0;
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(System.in);
			int n=sc.nextInt();
			int a[]=new int[n];
			
			int b[]=new int[n];
			HashMap<Integer,Integer> map=new HashMap<>();
			for (int i = 0; i < b.length; i++) {
				a[i]=sc.nextInt();
			}
			for (int i = 0; i < b.length; i++) {
				b[i]=sc.nextInt();
			map.put(b[i],i);
			}
			int left[]=new int[n];
			int right[]=new int[n];
			for (int i = 0; i < a.length; i++) {
				int idx1=map.get(a[i]);
				int r=idx1-i;
				int l=i-idx1;
						if(r<0) {
							r+=n;
						}
						if(l<0) {
							l+=n;
						}
				left[l]++;
				right[r]++;
			}
			sortarray(left);
			sortarray(right);
			int max=Math.max(left[n-1],right[n-1]);
			System.out.println(max);
			
			
	
	}
	static long cost[];
	static long total;
	static void id1(int u ,int p) {
		vis[u]=true;
		for(int v:adj[u]) {
			if(!vis[v]) {
				id1(v,u);
			}
		}
		long mixed=Math.min(b[u],c[u]);
		total+=(1l*mixed*1l*cost[u]*1l*2*1l);
		b[u]-=mixed;
		c[u]-=mixed;
		b[p]+=b[u];
		c[p]+=c[u];
	}
	static void id10(int u ,int p) {
		vis[u]=true;
		cost[u]=Math.min(cost[u],cost[p]);
		
		for(int v:adj[u]) {
			if(!vis[v]) {
				id10(v,u);
			}
		}
	}

	static int id12(int i,int id5,int state) {
		if(i==n) {
		if(state==0)
			return 0;
		return (32-id5);
		}
		if(memo[state][id5][i]!=-1) {
			return memo[state][id5][i];
		}
		int ans=0;
		if(state==0) {
			ans=id12(i+1,id5,state);
			ans=Math.max(ans,id12(i+1,Math.max(id5,a[i]+32),1)+a[i]);
		}
		else {
			ans-=(id5-32);
			ans=Math.max(ans,id12(i+1,Math.max(id5,a[i]+32),1)+a[i]);
		}
		return memo[state][id5][i]=ans;
	}
	static int reali,realj;
	 static int dx[]= {1,-1,0,0};
	 static int dy[]= {0,0,1,-1};
	 static char id13;
	
	



	private static int lcm(int a2, int b2) {
	return (a2*b2)/gcd(a2,b2);
	}
	static boolean visit[][];

	static Boolean zero[][];
	static int small[];
	
		
		
		
	
	static int idx=0;
	
	static long dpdp[][][][];
	static int modd=(int) 1e8;
	
		


	static class Edge implements Comparable<Edge>
	{
		int node;long cost;
		
		Edge(int a, long b) { node = a;	cost = b; }
		
		public int compareTo(Edge e){ return Long.compare(cost,e.cost);	}
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
    
    static String y;
    	static int nomnom[];
	static long fac[];
	



	static boolean f = true;

	static class SegmentTree { 


		int N; 

		int[] array, sTree, lazy;

		SegmentTree(int[] in) {
			array = in;
			N = in.length - 1;
			sTree = new int[N << 1]; 

			lazy = new int[N << 1];
			

		}

		void build(int node, int b, int e) 

		{
			if (b == e)
				sTree[node] = array[b];
			else {
				int mid = b + e >> 1;
				build(node << 1, b, mid);
				build(node << 1 | 1, mid + 1, e);
				sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];
			}
		}

		void update_point(int index, int val) 

		{
			index += N - 1;				
			sTree[index] = val;			
			while(index>1)				
			{
				index >>= 1;
				sTree[index] = Math.max(sTree[index<<1] ,sTree[index<<1|1]);		
			}
		}

		void update_range(int i, int j, int val) 

		{
			update_range(1, 1, N, i, j, val);
		}

		void update_range(int node, int b, int e, int i, int j, int val) {
			if (i > e || j < b)
				return;
			if (b >= i && e <= j) {
				sTree[node] += (e - b + 1) * val;
				lazy[node] += val;
			} else {
				int mid = b + e >> 1;
				propagate(node, b, mid, e);
				update_range(node << 1, b, mid, i, j, val);
				update_range(node << 1 | 1, mid + 1, e, i, j, val);
				sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];
			}

		}

		void propagate(int node, int b, int mid, int e) {
			lazy[node << 1] += lazy[node];
			lazy[node << 1 | 1] += lazy[node];
			sTree[node << 1] += (mid - b + 1) * lazy[node];
			sTree[node << 1 | 1] += (e - mid) * lazy[node];
			lazy[node] = 0;
		}

		int query(int i, int j) {
			return query(1, 1, N, i, j);
		}

		int query(int node, int b, int e, int i, int j) 

		{
			if (i > e || j < b)
				return 0;
			if (b >= i && e <= j)
				return sTree[node];
			int mid = b + e >> 1;
			

			int q1 = query(node << 1, b, mid, i, j);
			int q2 = query(node << 1 | 1, mid + 1, e, i, j);
			return Math.max(q1,q2);

		}
	}

	static int[][][] memo;


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

		public boolean id9(int i, int j) {
			return findSet(i) == findSet(j);
		}
		public int chunion(int i,int j, int x2) {
			if (id9(i, j))
				return 0;
			numSets--;
			int x = findSet(i), y = findSet(j);
			int z=findSet(x2);
			p[x]=z;;
			p[y]=z;
		return x;
		}

		public void unionSet(int i, int j) {
			if (id9(i, j))
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

		

		public int id14() {
			return numSets;
		}

		public int id4(int i) {
			return setSize[findSet(i)];
		}
	}

	

	static class incpair implements Comparable<incpair> {
		int a;
		long b;
		int idx;

		incpair(int a, long dirg, int i) {
			this.a = a;
			b = dirg;
			idx = i;
		}

		public int compareTo(incpair e) {
			return (int) (b - e.b);
		}
	}

	static class id0 implements Comparable<id0> {
		int a;
		long b;
		int idx;

		id0(int a, long dirg, int i) {
			this.a = a;
			b = dirg;
			idx = i;
		}

		public int compareTo(id0 e) {
			return (int) (e.b - b);
		}
	}

	static long allpowers[];

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

	static long dirg[][];
	static Edge[] driver;

	static int n;

	static long id2(long x, long x2, long y, long y2) {
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

		Point(long id11, long counts) {
			x = id11;
			y = counts;
		}

		@Override
		public int compareTo(Point p )
		{
			return Long.compare(p.y*1l*x, p.x*1l*y);
		}
		


	}

	static long[][] comb;

	static class Triple implements Comparable<Triple> {

		int l;
		int r;
		long cost;
		int idx;

		public Triple(int a, int b, long l1, int l2) {
			l = a;
			r = b;
			cost = l1;
			idx = l2;
		}

		public int compareTo(Triple x) {
			if (l != x.l || idx == x.idx)
				return l - x.l;
			return -idx;
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

	
	public static boolean id8(int n, int k) {
		int sum = k;
		int[] A = new int[k];
		Arrays.fill(A, 0, k, 1);

		for (int i = k - 1; i >= 0; --i) {

			while (sum + A[i] <= n) {

				sum += A[i];
				A[i] *= 2;
			}
		}
		if (sum == n) {
			return true;
		} else
			return false;
	}

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

	static int memo1[];

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

	static int gcd(int ans, int b) {
		if (b == 0) {
			return ans;
		}
		return gcd(b, ans % b);
	}

	static int[] isComposite;
	static int[] valid;

	static ArrayList<Integer> primes;
	static ArrayList<Integer> l1;

	
	static TreeSet<Integer> primus = new TreeSet<Integer>();
	
	static void id7(int N)
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

	static int V;
	static long INF = (long) 1E16;

	static class Edge2 {
		int node;
		long cost;
		long next;

		Edge2(int a, int c, Long long1) {
			node = a;
			cost = long1;
			next = c;
		}

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

		public void id3() throws InterruptedException {
			Thread.sleep(3000);
		}

		public int[] id6(int n) throws IOException {
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