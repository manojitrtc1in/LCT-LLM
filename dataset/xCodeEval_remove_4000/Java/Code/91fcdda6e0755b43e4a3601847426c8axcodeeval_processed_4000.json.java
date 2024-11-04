import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	static  ArrayList<Edge>adj[];
	static PrintWriter out=new PrintWriter(System.out);
	 public static int mod = 1000000007;

	 static char s[];
	 static char u[]; 
	static int notmemo[][][];
	static  ArrayList<Edge> drivers[];
	public static void main(String[] args) throws Exception {
	Scanner sc=new Scanner(System.in);
	  n=sc.nextInt();
	 int m=sc.nextInt();
	 adj=new ArrayList[n];
	 int  s=sc.nextInt();
	 int t=sc.nextInt();
	 

	 for (int i = 0; i < n; i++) {
		adj[i]=new ArrayList<>();
		

	 }
	 int temp=m;
	 while(m-->0) {
		 int u=sc.nextInt()-1;
		 int v=sc.nextInt()-1;
		 long w=sc.nextLong();
		 adj[u].add(new Edge(v, w));
		 adj[v].add(new Edge(u, w));
	 }
	 dirg=new long[n][n];
	 for (int i = 0; i < dirg.length; i++) {
		Arrays.fill(dirg[i], INF);
	}
	 driver=new Edge[n];
	 for (int i = 0; i < dirg.length; i++) {
	driver[i]=new Edge(sc.nextInt(), sc.nextInt());
	 }
	 
	 for (int i = 0; i < dirg.length; i++) {
	 id7(i);
	 }
	 
	 for (int i = 0; i <n; i++) {
	adj[i].clear();	
	}
	 for (int i = 0; i <n; i++) {
		for (int j = 0; j <n; j++) {
		if(dirg[i][j]!=INF) {
			adj[i].add(new Edge(j, dirg[i][j]));
		

		}			
		}
	}
	 System.out.println(dijkstra(s-1,t-1));
	 }
	static long dirg[][];
	static Edge[] driver;
	static long dijkstra(int S, int T)	

	{
		long[] dist = new long[n];
		Arrays.fill(dist, INF);
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
	static int n;
	private static void id7(int i) {
	long[] dist = new long[n];
	Arrays.fill(dist, INF);
	PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
	dist[i] = 0;
	pq.add(new Edge(i, 0));						

	while(!pq.isEmpty())
	{
		Edge cur = pq.remove();
		if(cur.cost > dist[cur.node])
            continue;
		for(Edge nxt: adj[cur.node])
		{	if(cur.cost + nxt.cost < dist[nxt.node]) {
				pq.add(new Edge(nxt.node, dist[nxt.node] = cur.cost + nxt.cost ));
			}
		if(cur.cost+nxt.cost<=driver[i].node)
			dirg[i][nxt.node]=Math.min(dirg[i][nxt.node], driver[i].cost);
		}
	}
}
	static class Edge implements Comparable<Edge>
	{
		int node; long cost;
		
		Edge(int a, long dirg) { node = a;	cost = dirg; }
		
		public int compareTo(Edge e){ return (int) (cost - e.cost);	}
	}

	

public static int dp(int i, int j,int found) {
if(i==s.length||j==u.length) {
	return 0;
}
int max=0;

if(notmemo[i][j][found]!=-1) {
	return notmemo[i][j][found];
}
if(s[i]==u[j]&&found==1) {
	
	max=Math.max(dp(i+1,j+1,1)+1,max);
}
else if(found==1) {
max=Math.max(dp(i+1,j+1,1),max);

}
else if(s[i]==u[j]&&found==0)
	max=Math.max(dp(i+1,j+1,1)+1,max);
if(found==0) {
	max=Math.max(dp(i,j+1,0),max);
max=Math.max(dp(i+1,j,0),max);
}
return notmemo[i][j][found]=max;
}


	  static long id0(long x,long x2,long y,long y2) {
		  return  Math.abs(x-x2)+Math.abs(y-y2);
	  }
	  static long fib[];
	  static long fib(int n) {
		  if(n==1||n==0) {
			  return 1;
		  }
		  if(fib[n]!=-1) {
			  return fib[n];
		  }
		  else 
			  return  fib[n]=  ((fib(n-2)%mod+fib(n-1)%mod)%mod);
	  }
	  static class Pair implements Comparable<Pair>{
		  int skill;
		  int idx;
		  Pair(int a, int b){
			  skill=a;
			  idx=b;
		  }
		public int compareTo(Pair p) {
		
			return p.skill-this.skill;
		}
		  
		  
	
		
		
	}
	static long[][] comb;		
	static long id4(int n , int k)
	{
		if(n < k)
			return 0;
		if(k == 0 || k == n)
			return 1;
		if(comb[n][k] != -1)
			return comb[n][k];
		if(n - k < k)
			return comb[n][k] = id4(n, n - k);
		return comb[n][k] = (id4(n - 1, k - 1) + id4(n - 1, k))%mod;
	}
	
	
static  class Triple implements Comparable<Triple>{

int u;
int v;
		long totalcost;
		public Triple(int a,int b,long l) {
			u=a;
			v=b;
			totalcost=l;
		}
		@Override
		public int compareTo(Triple o) {
			return Long.compare( totalcost,o.totalcost);	
		}
		
	}
	
	static TreeSet<Long> primeFactors(long N)		

	{
		TreeSet<Long> factors = new TreeSet<Long>();		

		int idx = 0, p = primes.get(idx);

		while(p * p <= N)
		{
			while(N % p == 0) { factors.add((long) p); N /= p; }
			if(primes.size()>idx+1)
			p = primes.get(++idx);
			else
				break;
		}

		if(N != 1)						

			factors.add(N);				

		return factors;
	}
	
	static boolean visited[];
	
	public static boolean id3(int n, int k) {
	 int sum = k;  
     int[] A = new int[k];  
      Arrays.fill(A, 0, k, 1);  
        
      for (int i = k - 1; i >= 0; --i) {  
      
           while (sum + A[i] <= n) {  
      
              sum += A[i];  
              A[i] *= 2;  
          }  
      }  
      if(sum==n) {
      	return true;
      }
      else
    	return false; 
	}
	
	static long[][] memo;

	
	static boolean vis2[][];
	
	static class SegmentTree {		

		
		int N; 			

		int[] array, sTree, lazy;
		
		SegmentTree(int[] in)		
		{
			array = in; N = in.length - 1;
			sTree = new int[N<<1];		

			lazy = new int[N<<1];
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
				sTree[node] = sTree[node<<1]+sTree[node<<1|1];
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
			return q1 + q2;	
					
		}
	
	}
	static boolean f2=false;
	static long[][] matMul(long[][] a2, long[][] b, int p, int q, int r)	

	{
		long[][] C = new long[p][r];
		for(int i = 0; i < p; ++i) {
			for(int j = 0; j < r; ++j) {
				for(int k = 0; k < q; ++k) {
					C[i][j] = (C[i][j]+(a2[i][k]%mod * b[k][j]%mod))%mod;
		 C[i][j]%=mod;
				}
		
			}
		}
		return C;
	}
		
	
	
		
		
		
		

		
	
	static ArrayList<Pair> a1[];
	static int memo1[];
	
	static boolean vis[];
	static TreeSet<Integer> set=new TreeSet<Integer>();
	
	static long modPow(long ways, long count, long mod)	

	{
		ways %= mod;
		long res = 1;
		while(count > 0)
		{
			if((count & 1) == 1)
				res = (res * ways) % mod;
			ways = (ways * ways) % mod;
			count >>= 1;
		}
		return res%mod;
	}
	
	
	

	static long gcd(long ans,long b) {
		if(b==0) {
			return ans;
		}
		return gcd(b,ans%b);
	}
	static int[] isComposite;
	static int[] valid;
	
	static ArrayList<Integer> primes;
	static ArrayList<Integer> l;
	static void sieve(int N)	

	{
		isComposite = new int[N+1];					
		isComposite[0] = isComposite[1] = 1;			

		primes = new ArrayList<Integer>();
		l=new ArrayList<>();
		valid=new int[N+1];
		for (int i = 2; i <= N; ++i) 					

			if (isComposite[i] == 0) 					

			{
				primes.add(i);
				l.add(i);
				valid[i]=1;
				
				for (int j = i*2; j <=N; j +=i) {	

						isComposite[j] = 1;
						
						
						
				      
					}
			}
		
		for(int i=0 ; i<primes.size() ; i++) {
			for(int j:primes) {
				if(primes.get(i)*j>N) {
					break;
				}
				valid[primes.get(i)*j]=1;
			}
		}
	}
	static class UnionFind {                                              
		int[] p, rank, setSize;
		int numSets;

		public UnionFind(int N) 
		{
			p = new int[numSets = N];
			rank = new int[N];
			setSize = new int[N];
			for (int i = 0; i < N; i++) {  p[i] = i; setSize[i] = 1; }
		}

		public int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }

		public boolean id5(int i, int j) { return findSet(i) == findSet(j); }

		public boolean unionSet(int i, int j) 
		{ 
			if (id5(i, j)) 
				return false;;
			numSets--; 
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else
			{	p[x] = y; setSize[y] += setSize[x];
				if(rank[x] == rank[y]) rank[y]++; 
			} 
			return true;
		}

		public int id6() { return numSets; }

		public int id2(int i) { return setSize[findSet(i)]; }
	}
	public static int[] schuffle(int[] a2) {
		for (int i = 0; i < a2.length; i++) {
			int x=(int)(Math.random()*a2.length);
		int temp=a2[x];
		a2[x]=a2[i];
		a2[i]=temp;
		}
		return a2;
	}
		static int V;
	static long INF=(long) 1E18;
		
		static class Edge2 
		{
			int node;
		long cost;
			long next;
			Edge2(int a, int c,Long long1) { node = a;	cost = long1; next=c;}
			
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
	}	
}