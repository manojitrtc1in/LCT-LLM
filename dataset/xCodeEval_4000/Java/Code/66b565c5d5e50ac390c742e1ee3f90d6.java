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
static Scanner sc = new Scanner(System.in);
static PrintWriter out = new PrintWriter(System.out);
public static void main(String args[]) throws Exception {
		 n=sc.nextInt();
		 deleted=new boolean[n+1];
		deleted[0]=true;
		sieve((int) 1e5);
		 total=n;
		int cap=317;
		for(int x:primes) {
			if(x>cap||x>n) {
				break;
			}
			queryB(x);
			removemul(x);
		}
		int num=queryA(1);
		if(num==1) {
			queryC(1);
			return;
			
		}
		if(num!=total) {
			int ans=1;
			for(int x:primes) {
				if(x>n)
					break;
				if(x<cap) {
					queryB(x);
					removemul(x);
					int c=queryA(x);
					
					if(c!=0) {
						ans*=x;
						for (int i = x*x; i < deleted.length; i*=x) {
							queryB(i);
							int c1=queryA(i);
							if(c1==0) {
							break;	
							}
							ans*=x;	
						}	
					}
				}
				else {
					int c=queryB(x);
					int del=removemul(x);
					
					if(del!=c) {
						ans*=x;
					}
				}
				
			}
			queryC(ans);
			return;
			
		}
		else {
		ArrayList<ArrayList<Integer>> sqrt=new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> l=new ArrayList<>();
		
		for (int i = 0; i < primes.size(); i++) {
		l.add(primes.get(i));
		if(l.size()==100) {
			sqrt.add(l);
			l=new ArrayList<>();
		}
		}
		if(l.size()>0)
		sqrt.add(l);
       for(ArrayList<Integer> m:sqrt) {
			for(int x:m) {
				queryB(x);
				removemul(x);
			}
			int count=queryA(1);
			if(count!=total) {
				for(int x:m) {
					
				int c=queryA(x);
				if(c!=0) {
				queryC(x);
					return;
				}
				}
			}
		}
   	
		}
		queryC(1);
		return;
		
	}

static int queryA(int x) throws IOException {
	out.println("A "+x);
	out.flush();
	int xxx=sc.nextInt();
	return xxx;
	
}
static int queryB(int x) throws IOException {
	out.println("B "+x);
	out.flush();
	int xxx=sc.nextInt();
	return xxx;
}
static void queryC(int x) {
	out.println("C "+x);
	out.flush();
}
static int removemul(int x) {
	int removed=0;
	for (int i = x; i < deleted.length; i+=x) {
		if(!deleted[i]) {
		deleted[i]=true;
		total--;
		removed++;
		}
	}
	return removed;
}


     static boolean deleted[];
     
	static int centroid[];
	static void centdfs(int u,int e) {
		for(int v:adj[u]) {
			if(v==e) {
				centroid[u]=Math.max(n-countnodes[u],centroid[u]);
				
				continue;
			}
				else
			centroid[u]=Math.max(countnodes[v],centroid[u]);
			centdfs(v,u);
		}
	}
	  static void Nodesdfs(int u, int e) 
	    { 
	        countnodes[u] =1; 
	        for(int v: adj[u]) 
	        { 
	            if(v == e) 
	                continue; 
	              
	            Nodesdfs(v,u); 
	              
	            countnodes[u] += countnodes[v]; 
	        } 
	    } 
	static int countnodes[];
	static int max=0;
	static int node;
	static int tar;
	
	static void dfs1(int u,int count) {
	vis[u]=true;
	for(int v:adj[u]) {
		if(!vis[v]) {
			if(count>max) {
				max=count;
				node=v;
			}
			dfs1(v,count+1);
		}
	}
	}
	
	
	
	static  class FenwickTree { 


		int n;
		int[] ft;
		
		FenwickTree(int size) { n = size; ft = new int[n+1]; }
		
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
	

	static ArrayList<Integer> arr;

	
static int total;
static TreeMap<Integer,Integer> map1;

		static int zz;


























static HashMap<Integer,Integer> map;
static int maxa=0;
static int ff=123123;

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

		public boolean isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		public int chunion(int i,int j, int x2) {
			if (isSameSet(i, j))
				return 0;
			numSets--;
			int x = findSet(i), y = findSet(j);
			int z=findSet(x2);
			p[x]=z;;
			p[y]=z;
		return x;
		}

		public void unionSet(int i, int j) {
			if (isSameSet(i, j))
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
		public static int[] readarray(int n) throws IOException {
			int a[]=new int[n];
			for (int i = 0; i < a.length; i++) {
			a[i]=sc.nextInt();
			}
			return a;
		}
		public static long[] readlarray(int n) throws IOException {
			long a[]=new long[n];
			for (int i = 0; i < a.length; i++) {
			a[i]=sc.nextLong();
			}
			return a;
		}
}