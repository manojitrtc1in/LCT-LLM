    import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {
	static ArrayList<Integer> adj[];
	


	static int[][] notmemo;
	static int k;
	static int[] a;
	static int b[];
	static int m;

	static class Pair implements Comparable<Pair> {
		int c;
		int d;
		public Pair(int b, int l) {
			c = b;
			d = l;
		}
		@Override
		public int compareTo(Pair o) {
		return o.d-this.d;
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
static int x[];
static int y[];
static PrintWriter out = new PrintWriter(System.out);
public static void main(String args[]) throws Exception {
 n=sc.nextInt();
adjlist=new ArrayList[n];
for (int i = 0; i < adjlist.length; i++) {
	adjlist[i]=new ArrayList<>();
}
for (int i = 0; i <n; i++) {
	int k=sc.nextInt();
	PriorityQueue<Integer> ones=new PriorityQueue<>();
	int twos=-1;
	int threes=-1;
	while(k-->0) {
		int c=sc.nextInt();
		int d=sc.nextInt();
		if(c==1) {
			ones.add(d);
			if(ones.size()>3)
				ones.poll();
		}
		else if(c==2) {
		twos=Math.max(twos,d);
		}
		else
			threes=Math.max(threes,d);
	}
	if(!ones.isEmpty())
	adjlist[i].add(new Pair(1,ones.remove()));
	if(!ones.isEmpty())
	adjlist[i].add(new Pair(1,ones.remove()));
	if(!ones.isEmpty())
	adjlist[i].add(new Pair(1,ones.remove()));
	if(twos!=-1)
	adjlist[i].add(new Pair(2,twos));
	if(threes!=-1)
	adjlist[i].add(new Pair(3,threes));
}
memo=new long[10][n];
for(long x[]:memo) {
	Arrays.fill(x,-1);
}
out.println(dp(0,0));
out.flush();
}

static long dp(int i,int cards) {
	if(i==n)
		return 0;
	if(memo[cards][i]!=-1)
		return memo[cards][i];
	long ans=dp(i+1,cards);
	for(int mask=0;mask<(1<<adjlist[i].size());mask++) {
		int total=cards;
		long damage=0;
		int pp=0;
		int maxdamage=0;
		for (int j = 0; j <adjlist[i].size(); j++) {
			
			int cc=0;
			if((mask&(1<<j))!=0) {
			if(adjlist[i].get(j).c==1)
				cc=1;
			else if(adjlist[i].get(j).c==2)
				cc=2;
			else
				cc=3;
			}
			pp+=cc;
		}
		if(pp>3)
			continue;
		for (int j = 0; j <adjlist[i].size(); j++) {
			if((mask&(1<<j))!=0){
				total++;
				damage+=(adjlist[i].get(j).d*1l);
			maxdamage=Math.max(maxdamage,adjlist[i].get(j).d*1);
			}
		}
		if(total>=10) {
			damage+=maxdamage;
		}	
		
		ans=Math.max(ans, 1l*damage+dp(i+1,total%10));
	}
	return  memo[cards][i]=ans;
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
	
	
	
	static  class id8 { 


		int n;
		int[] ft;
		
		id8(int size) { n = size; ft = new int[n+1]; }
		
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

	
static int[] total;
static TreeMap<Integer,Integer> map1;

		static int zz;


























static HashMap<Integer,Integer> map;
static int maxa=0;
static int ff=123123;

static long[][] memo;


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

		public boolean id6(int i, int j) {
			return findSet(i) == findSet(j);
		}
		public int chunion(int i,int j, int x2) {
			if (id6(i, j))
				return 0;
			numSets--;
			int x = findSet(i), y = findSet(j);
			int z=findSet(x2);
			p[x]=z;;
			p[y]=z;
		return x;
		}

		public void unionSet(int i, int j) {
			if (id6(i, j))
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

		

		public int id9() {
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

		Point(long id7, long counts) {
			x = id7;
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
		public static int[] readarray(int n) throws IOException {
			int a[]=new int[n];
			for (int i = 0; i < a.length; i++) {
			a[i]=sc.nextInt();
			}
			return a;
		}
		public static long[] id5(int n) throws IOException {
			long a[]=new long[n];
			for (int i = 0; i < a.length; i++) {
			a[i]=sc.nextLong();
			}
			return a;
		}
}