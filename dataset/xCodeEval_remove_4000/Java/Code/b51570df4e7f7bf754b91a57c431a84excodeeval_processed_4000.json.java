    import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

import javax.sound.sampled.ReverbType;

import java.util.*;
import java.io.*;

public class Main {
	static ArrayList<Integer> adj[];
	


	static int[][] notmemo;
	static int k;
	static int[] a;
	static int b[];
	static int m;

	static class Pair implements Comparable<Pair> {
		int d;
		int s;

		public Pair(int b, int l) {
			d = b;
			s = l;
		}

		@Override
		public int compareTo(Pair o) {
			if (o.d - o.s > this.d - this.s) {
				return 1;
			} else if (o.d - o.s < this.d - this.s) {
				return -1;
			} else
				return 0;

		}

	}

	static Pair s1[];
	static ArrayList<Pair> adjlist[];
	

	public static long mod = (long) (1e9 + 7);
	static int V;
	static long INF = (long) 1E16;
	static int n;
	static char c[];
	static int d[];
	static int z;
	static Pair p[];
static int R;
static int C;
static int K;
static long grid[][];
static String bus[];
static String troll[];
static int adjmat[][];
static int ta[][];
static int at[][];
public static void main(String args[]) throws Exception {





	Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t=sc.nextInt();
		while(t-->0) {
			n=sc.nextInt();
			args=new String[n];
			int temp=n-1;
			adj=new ArrayList[n];
			for (int i = 0; i < args.length; i++) {
				adj[i]=new ArrayList<>();
			}
			while(temp-->0) {
				int u=sc.nextInt()-1;
				int v=sc.nextInt()-1;
				adj[u].add(v);
				adj[v].add(u);
			}
			int m=sc.nextInt();
			PriorityQueue<Long> pq=new PriorityQueue<>(Collections.reverseOrder());
			for (int i = 0; i <m; i++) {
				pq.add((long) sc.nextInt());
			}           
			vis=new boolean[n];
			 w=new long[n];
			 ss=0;
			 dfs(0);
			sortarray(w);
			 if(m<n) {
				 long sum=0;
				 int i=n-1;
				 while(!pq.isEmpty()) {
				long z=(w[i--]*pq.poll());
				z%=mod;
				sum+=z;
				sum%=mod;
				 }
				 while(i>=0) {
				 sum+=w[i--];				
				 sum%=mod;
				 }
				 System.out.println(sum);
			 }
			 else {
				 long sum=0;
				 int i=n-1;
				 long product=1;
				 while(pq.size()>n-2) {
				long z=pq.poll();
				z%=mod;
				product*=z;
				product%=mod;
				 }
				 long xx=product*w[i];
				 xx%=mod;
				 sum+=xx;
				 sum%=mod;
				 i--; 
				 while(!pq.isEmpty()) {
						long z=(w[i--]*pq.poll());
						z%=mod;
						sum+=z;
						sum%=mod;
						 
				 }
				 System.out.println(sum);
						
				 
				 
			 }
		}
     out.flush();
	}
static long w[];
static int ss=0;
static long dfs(int u) {
	vis[u]=true;
	long c=1;
	for(int v:adj[u]) {
	if(!vis[v]) {
		c+=dfs(v);
	}
	}
	w[ss++]=c*1l*(1l*n-c*1l);
	return c;
	
	}

static  class id7 { 


		int n;
		int[] ft;
		
		id7(int size) { n = size; ft = new int[n+1]; }
		
		int rsq(int b) 

		{
			int sum = 0;
			while(b > 0) { sum += ft[b]; b -= b & -b;}		

			return sum;
		}
		
		int rsq(int a, int b) { return rsq(b) - rsq(a-1); }	
		
		void point_update(int k, int val)	

		{
			while(k <= n) { ft[k] += val; k += k & -k; }		

		}
	}
	static ArrayList<Integer> euler=new ArrayList<>();
		static int dp(int i,int left,int right) {
			if(i==n)
				return 0;
			
			if(memo[i][left][right]!=-1) {
			return memo[i][left][right];	
			}
			int ans=(int) 1e9;
			if((left==1&&right==0)||(right==1&&left==0)) {
			
				ans=Math.min(ans,dp(i+1,c[i]=='L'?0:1,c[(i+2)%n]=='L'?0:1));
				if(c[i]=='L') {
					if(i==0)
						c[0]='R';
				ans=Math.min(ans,1+dp(i+1,1,c[(i+2)%n]=='L'?0:1));
				}
				else  {
					if(i==0)
						c[0]='L';
				
					ans=Math.min(ans,1+dp(i+1,0,c[(i+2)%n]=='L'?0:1));
				}
				
			}
			else if(left==1&&right==1) {
			
				if(c[i]=='L') {
					ans=Math.min(ans,dp(i+1,0,c[(i+2)%n]=='L'?0:1));
					}
					else {
						if(i==0)
							c[0]='L';
					
						ans=Math.min(ans,1+dp(i+1,0,c[(i+2)%n]=='L'?0:1));
					}
			}
			else if(left==0&&right==0) {
			
				if(c[i]=='R') {
					ans=Math.min(ans,dp(i+1,1,c[(i+2)%n]=='L'?0:1));
					}
					else {
						if(i==0)
							c[0]='R';
					
						ans=Math.min(ans,1+dp(i+1,1,c[(i+2)%n]=='L'?0:1));
					}
			}
			
			
		return memo[i][left][right]=ans;
		}

	static ArrayList<Integer> arr;

	
static long total[];
static TreeMap<Integer,Integer> map1;

		static int zz;


























static HashMap<Integer,Integer> map;
static int maxa=0;
static int ff=123123;

static long dist[][];
static int[][][] memo;


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

		

		public int id8() {
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