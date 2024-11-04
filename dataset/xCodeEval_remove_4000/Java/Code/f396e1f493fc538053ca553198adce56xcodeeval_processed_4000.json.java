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
import java.util.TreeSet;

public class Main {
	static ArrayList<Edge> adj[];
	static PrintWriter out = new PrintWriter(System.out);
	public static long mod;

	static int [][]notmemo;
	static int k;
	static int a[];
	static long b[];
	static int m;
	static char c[];


	static class Pair {
    	int a;
    	int b;
    	public Pair(int a1,int b1) {
		a=a1;
		b=b1;
		
    	}
		
    	
    }
    static Pair s1[];
    static long s[];
    static ArrayList<Pair> adjlist[];
	private static HashSet<Integer> set1[];
	static int n1;
	static int n2;
	static int k1;
	static int k2;
	static int skip=0;
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			int a[]=new int[n];
			int count[]=new int[201];
			TreeSet<Integer> set[]=new TreeSet[201];
			for (int i = 0; i < set.length; i++) {
				set[i]=new TreeSet<>();
			}
			int sum[][]=new int[201][n];
			
			for (int i = 0; i < a.length; i++) {
				a[i]=sc.nextInt();
				count[a[i]]++;
			set[a[i]].add(i);
			for (int j = 1; j < sum.length; j++) {
			if(j==a[i]) {
				sum[j][i]=sum[j][i == 0 ? 0:i - 1]+1;
			}
			else {
				sum[j][i]=sum[j][i == 0 ? 0:i - 1];
			}
			}
			}
			int pos[][]=new int[201][];
			for (int i = 1; i <201; i++) {
				pos[i]=new int[count[i]+1];
			}
			Arrays.fill(count,0);
			int c=0;
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < pos.length; j++) {
					if(a[i]==j) {
						pos[a[i]][count[a[i]]++]=i;
					}
				}
			}
			int ans=0;
			for (int i = 1; i <201; i++) {
				ans=Math.max(ans,set[i].size());
			for (int j = 0; j <set[i].size()/2; j++) {
				int l=pos[i][j];
				int r=pos[i][set[i].size()-1-j]-1;
			for (int k = 1; k < pos.length; k++) {
				
				int total=sum[k][r]-sum[k][l];
				if(total!=0)
				

				
				ans=Math.max(ans, (j+1)*2+total);
			}
			}
			}
			System.out.println(ans);
			
			
			
		
			
		}
		out.flush();
	}
	static int start=0;
	static int dp(int i,int last,int state,int curc) {
		if(i==n) {
			return 0;
		}
		int take=0;
		if(last==a[i]) {
			take=(int) (1+dp(i+1,last,state,curc+1));
		}
		else if(a[i]==start) {
			take=1+dp(i+1,last,state,curc+1);	
		}
		else if(last!=a[i]&&state==0) {
			take=1+dp(i+1,last,1,curc+1);
		}
		int leave=dp(i+1,last,state,curc);
		return Math.max(take,leave);
	}
	
		
		
		
	
	static int idx=0;
	
	static long dpdp[][][][];
	static int modd=(int) 1e8;
		
	

    static int id6(int arr[], int n, int sum)  
    {  
        

        

        

        HashMap <Integer, Integer> prevSum = new HashMap<>();  
        
        int res = 0;  
        
        

        int currsum = 0;  
        
        for (int i = 0; i < n; i++) {  
        
            

            currsum += arr[i];  
        
            

            

            

            if (currsum != 0)   
                res++;          
        
            

            

            

            

            

            if (prevSum.containsKey(currsum - arr[i]))   
                res += prevSum.get(currsum - arr[i]);  
                
        
            

            

            Integer count = prevSum.get(currsum); 
            if (count == null) 
                prevSum.put(currsum, 1); 
            else
                prevSum.put(currsum, count+1);  
        }  
        
        return res;  
    } 
	public static int id9() {
		int count=0;
		for (int i = 0; i < c.length; i++) {
			if(c[i]=='o'||c[i]=='e'||c[i]=='a'||c[i]=='i'||c[i]=='u') {
				count++;
			}
		}
		return count;
	}
	public static  char id12() {
		for (int i = c.length-1; i>=0; i--) {
			if(c[i]=='o'||c[i]=='e'||c[i]=='a'||c[i]=='i'||c[i]=='u') {
		return c[i];
			}
		}
		return 'a';
	}
	static class pp{
		String ss;
		String mm;
		public pp(String a,String b) {
		ss=a;
		mm=b;
		}
	}
	static class Tri implements Comparable<Tri>{
		String s;
		int id4;
		char lastchar;
	public	Tri(String m,int a,char c1){
			s=m;
			id4=a;
			lastchar=c1;
			
		}
	public int compareTo(Tri t) {
		if (id4 == t.id4)
			return lastchar - t.lastchar;
		return id4 - t.id4;
	}
	
	}
	static boolean dfs(int u, int cost) {
		boolean f=false;
		vis[u]=true;
		for(Edge p:adj[u]) {
			if(!vis[p.node]) {
				f|=dfs(p.node,(int) p.cost);
			}
		}
		if (cost == 2&&!f) {
				set.add(u + 1);
				return true;
		}
			return f;
		
	}
	
		
	private static boolean check(String s) {
		char c1[]=s.toCharArray();
		for (int i = 0; i < c1.length; i++) {
			if(c[i]>c1[i]) {
				return true;
			}
			 if(c[i]<c1[i])
				return false;
		}
		return true;
	}

	static long dijkstra(int S, int T)	

	{
		long[] dist = new long[V];
		Arrays.fill(dist, (int) 1e9);
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
		dist[S] = 0;
		pq.add(new Edge(S, 0));						

		while(!pq.isEmpty())
		{
			Edge cur = pq.remove();
			if(cur.node == T)						

				return dist[T];
			if(cur.cost > dist[cur.node])			

				continue;
			for(Edge nxt: adj[cur.node])
				if(cur.cost + nxt.cost < dist[nxt.node])
					pq.add(new Edge(nxt.node, dist[nxt.node] = cur.cost + nxt.cost ));
		}
		return -1;
	}
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
		int id13;
		int signup;
		int shiprate;
		int idx;

		public library(int a, int b, int c, int idx) {
			id13 = a;
			signup = b;
			shiprate = c;
			this.idx = idx;
		}

		@Override
		public int compareTo(library o) {
		if(signup==o.signup) {
			  return o.id13-id13;
		}
		return signup - o.signup;
		
		}
	}





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

	static long[][] memo;


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

		public boolean id10(int i, int j) {
			return findSet(i) == findSet(j);
		}

		public void unionSet(int i, int j) {
			if (id10(i, j))
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

		public int id3(int i) {
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

	static long id1(long x, long x2, long y, long y2) {
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

		public void id2() throws InterruptedException {
			Thread.sleep(3000);
		}

		public int[] id5(int n) throws IOException {
			int[] ans = new int[n];
			for (int i = 0; i < n; i++)
				ans[i] = nextInt();
			return ans;
		}
	}
}