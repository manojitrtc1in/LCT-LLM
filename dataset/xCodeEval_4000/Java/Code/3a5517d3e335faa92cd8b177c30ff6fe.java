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
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	static ArrayList<Integer> adj[];
	static PrintWriter out = new PrintWriter(System.out);
	public static long mod;

	static int[][][] notmemo;
	static int k;
	static int a[];
	static int b[];
	static int m;
	static char c[][];


	static int trace[];
	static int h;
	static int x;
	static int ans1;
	static int ans2;
    static char t[];
	static char l[];
	static char r[];
    static int w;
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(System.in);
		int t=sc.nextInt();
		label:while(t-->0) {
			int lx=(int) -1e5;
			int rx=(int) 1e5;
			int uy=(int) 1e5;
			int dy=(int) -1e5;
			int n=sc.nextInt();
			boolean enabled[]=new boolean[4];
			boolean f=false;
			while(n-->0) {
				int xi=sc.nextInt();
				int yi=sc.nextInt();
				for (int i = 0; i < enabled.length; i++) {
					enabled[i]=(sc.nextInt()==1 ? true:false);
				}
				if(!enabled[0]) {
					lx=Math.max(lx,xi);
				}	
				if(!enabled[2]) {
					rx=Math.min(rx, xi);
				}
				if(!enabled[1]) {
					uy=Math.min(uy, yi);
				}
				if(!enabled[3]) {
					dy=Math.max(dy, yi);
				}
			if(lx>rx||dy>uy) {
				f=true;
			}
			}
			if(!f)
			System.out.println(1+" "+lx+" "+uy);
			else
				System.out.println(0);
				
				
			
			
		}
    
    
    }
    public static int dpdp(int i,int j,int state) {
    	if(i+1==h&&j+1==w) {
    		return 0;
    	}
    	if(notmemo[i][j][state]!=-1) {
    		return notmemo[i][j][state];
    	}
    	int max=(int) 1e9;
    	if(i+1<h&&c[i+1][j]=='.') {
    		max=Math.min(dpdp(i+1,j,0),max);
    	}
    	if(j+1<w&&c[i][j+1]=='.') {
    		max=Math.min(dpdp(i,j+1,0),max);
    	}
    	if(i+1<h&&c[i+1][j]=='#'&&state==0) {
    		max=Math.min(dpdp(i+1,j,1)+1,max);	
    	}
    	if(j+1<w&&c[i][j+1]=='#'&&state==0) {		
    		max=Math.min(dpdp(i,j+1,1)+1,max);
        }
    	if(i+1<h&&c[i+1][j]=='#'&&state==1) {
    		max=Math.min(dpdp(i+1,j,1),max);	
    	}
    	if(j+1<w&&c[i][j+1]=='#'&&state==1) {		
    		max=Math.min(dpdp(i,j+1,1),max);
        }
    	return notmemo[i][j][state]=max;
    }
    static String y;
    static int changes(int i) {
		if(i<0) {
			return 0;
		}
		if(memo[i]!=-1) {
			return memo[i];
		}
		if(y.charAt(i)!=y.charAt(n-i)) {
	return -10;
		}
		else {
			memo[i]=changes(i-1);
				
		}
		return memo[i];
	}

	static int nomnom[];
	static long fac[];
	
	static class book implements Comparable<book> {
		int idx;
		long score;

		public book(int i, long s) {
			idx = i;
			score = s;
		}

		public int compareTo(book o) {
			return (int) (o.score - score);
		}
	}

	static class library implements Comparable<library> {
		int numofbooks;
		int signup;
		int shiprate;
		int idx;

		public library(int a, int b, int c, int idx) {
			numofbooks = a;
			signup = b;
			shiprate = c;
			this.idx = idx;
		}

		@Override
		public int compareTo(library o) {
		if(signup==o.signup) {
			  return o.numofbooks-numofbooks;
		}
		return signup - o.signup;
		
		}
	}




	static String s;

	static boolean isOn(int S, int j) {
		return (S & 1 << j) != 0;
	}


	static boolean f = true;

	static class SegmentTree { 


		int N; 

		int[] array, sTree, lazy;

		SegmentTree(int[] in) {
			array = in;
			N = in.length - 1;
			sTree = new int[N << 1]; 

			lazy = new int[N << 1];
			build(1, 1, N);
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
			sTree[index] += val;
			while (index > 1) {
				index >>= 1;
				sTree[index] = Math.max(sTree[index << 1], sTree[index << 1 | 1]);
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
			return Math.max(q1, q2);

		}
	}

	static int memo[];


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

	static class decpair implements Comparable<decpair> {
		int a;
		long b;
		int idx;

		decpair(int a, long dirg, int i) {
			this.a = a;
			b = dirg;
			idx = i;
		}

		public int compareTo(decpair e) {
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

	static class Edge implements Comparable<Edge> {
		int node;
		long cost;

		Edge(int a, long dirg) {
			node = a;
			cost = dirg;
		}

		public int compareTo(Edge e) {
			return (int) (cost - e.cost);
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

	static class Pair implements Comparable<Pair> {
		int a, b;

		Pair(int x, int y) {
			a = x;
			b = y;
		}

		@Override
		public int compareTo(Pair c) {
			return b-c.b;
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

	
	public static boolean FindAllElements(int n, int k) {
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

	static boolean vis2[][];

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

	static ArrayList<Pair> a1[];
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

	static long gcd(long ans, long b) {
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
	

	public static int[] schuffle(int[] p) {
		for (int i = 0; i < p.length; i++) {
			int x = (int) (Math.random() * p.length);
			int temp = p[x];
			p[x] = p[i];
			p[i] = temp;
		}
		return p;
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
}