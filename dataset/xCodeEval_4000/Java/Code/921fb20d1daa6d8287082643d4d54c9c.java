import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	static ArrayList<Character> adj[];
	static PrintWriter out = new PrintWriter(System.out);
	public static int mod = 1000000007;

	static int notmemo[][][][];
	static int k;
	static long a[];
	static int b[];
	static int m;
	static char c[];

	static int trace[];
	static int h;
	static int x;
	static int ans1;
	static int ans2;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
	int t=sc.nextInt();
	int x=0;
	boolean luck=false;
	label:while(t-->0) {
	x++;
		req=new boolean[62];	
	long n=sc.nextLong();
	int m=sc.nextInt();
	

	long a[]=new long[m];
	long count[]=new long[62];
	boolean vis[]=new boolean[62];
	long sum=0;
	for (int i = 0; i < a.length; i++) {
		a[i]=sc.nextLong();
		sum+=a[i];
	for (int j = 0; j <62; j++) {
		if((a[i]&((long)(1*1l<<j)))!=0) {
			
			count[j]++;
		break;
		}
	}
	
	}
	if(sum<n) {
		System.out.println(-1);
		continue label;
	}
	block(n);
	long total=0;
	
	for (int i = 0; i < vis.length-1; i++) {
		while(req[i]&&!vis[i]&&count[i]==0) {
			
	
			int idx=i+1;
			while(idx<61&&count[idx]==0) {
				idx++;
			}
			long c=2;
			while(idx>i&&idx>0) {
			count[idx-1]+=c;
			count[idx]--;
			total++;
			idx--;
			}
			if(count[i]>0) {
				vis[i]=true;
			}
		}
		if(req[i]) {
			count[i]--;
		}
		count[i+1]+=(count[i]/2);
	}
	


	System.out.println(total);
	



	

	
	
	
	}
	}
	static boolean req[];
		static void block(long x) 
		{ 
		    ArrayList<Long> v = new ArrayList<Long>(); 
		      
		    

		    

		 

		    while (x > 0)  
		    { 
		        v.add(x % 2); 
		        x = x / 2; 
		    } 
		  
		    

		    

		    

		    for (int i = 0; i < v.size(); i++)  
		    { 
		        if (v.get(i) == 1)  
		        { 
		        req[i]=true;
		

	

		

		        }
		        
		    } 
		

		} 
		
	static void dfs(char c) {
		if(vis[c-'a']) {
			return;
		}
		vis[c-'a']=true;
		for(char c2:adj[c-'a']) {
			if(!vis[c2-'a']) {
				dfs(c2);
			}

		}
		System.out.print(c);
				
	}
	
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

	static long dp(int i, int state) {
		if (i < 0) {
			return state;
		}
		if (memo[i][state] != -1)
			return memo[i][state];

		int x = Integer.parseInt(c[i] + "");
		x += state;
		int newc = x / 10;
		x = x % 10;

		return memo[i][state] = Math.min(dp(i - 1, newc) + x, x == 0 ? (long) 1e15 : dp(i - 1, newc + 1) + 10 - x);
	}

	static boolean isPal(String s) {
		int j = s.length() - 1;
		c = s.toCharArray();
		Arrays.sort(c);
		for (int i = 0; i < c.length; i++) {

		}
		return true;
	}

	static String s;

	static boolean isOn(int S, int j) {
		return (S & 1 << j) != 0;
	}

	static int y, d;

	static void extendedEuclid(int a, int b) {
		if (b == 0) {
			x = 1;
			y = 0;
			d = a;
			return;
		}
		extendedEuclid(b, a % b);
		int x1 = y;
		int y1 = x - a / b * y;
		x = x1;
		y = y1;
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

	static long memo[][];

	static long nCr1(int n, int k) {
		if (n < k)
			return 0;
		if (k == 0 || k == n)
			return 1;
		if (comb[n][k] != -1)
			return comb[n][k];
		if (n - k < k)
			return comb[n][k] = nCr1(n, n - k);
		return comb[n][k] = ((nCr1(n - 1, k - 1) % mod) + (nCr1(n - 1, k) % mod)) % mod;
	}

	static class UnionFind {
		int[] p, rank, setSize;
		int numSets;
		int max[];

		public UnionFind(int N) {
			max = new int[N];
			p = new int[numSets = N];
			rank = new int[N];
			setSize = new int[N];
			for (int i = 0; i < N; i++) {
				p[i] = i;
				setSize[i] = 1;
				max[i] = i;
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
				max[x] = Math.max(max[x], max[y]);

			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
				max[y] = Math.max(max[x], max[y]);

			}
		}

		private int getmax(int j) {
			return max[findSet(j)];
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

	static class Pair {
		int a, b;

		Pair(int x, int y) {
			a = x;
			b = y;
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
	static ArrayList<Integer> l;

	static void sieve(int N) 

	{
		isComposite = new int[N + 1];
		isComposite[0] = isComposite[1] = 1; 

		primes = new ArrayList<Integer>();
		l = new ArrayList<>();
		valid = new int[N + 1];
		for (int i = 2; i <= N; ++i) 

			if (isComposite[i] == 0) 

			{
				primes.add(i);
				l.add(i);
				valid[i] = 1;

				for (int j = i * 2; j <= N; j += i) { 

														

					isComposite[j] = 1;

				}
			}

		for (int i = 0; i < primes.size(); i++) {
			for (int j : primes) {
				if (primes.get(i) * j > N) {
					break;
				}
				valid[primes.get(i) * j] = 1;
			}
		}
	}

	public static int[] schuffle(int[] a2) {
		for (int i = 0; i < a2.length; i++) {
			int x = (int) (Math.random() * a2.length);
			int temp = a2[x];
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

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}