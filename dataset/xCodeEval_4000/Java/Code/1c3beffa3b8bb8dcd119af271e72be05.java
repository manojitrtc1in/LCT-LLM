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
import java.util.TreeSet;

import javax.swing.text.StyledEditorKit.ForegroundAction;

public class Main {
	static ArrayList<Edge> adj[];
	static PrintWriter out = new PrintWriter(System.out);
	public static long mod;

	static int [][]notmemo;
	static int k;
	static long a[];
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
	
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			long l=sc.nextLong();
			long r=sc.nextLong();
			long start=n*2;
			long counter=(n*2)-2;
			long last=n*1l*(n-1);
			last++;
		Queue<Long> q=new LinkedList<>();
		boolean f=true;
		boolean f2=true;
		for (int i = 1; i <=n; i++) {
				if(start>=l&&f) {
					f=false;
					long cur=i;
					long max=i+1;
					if(start!=l) {
						long st=start-(counter);
						while(st<l) {
							if(st%2!=0) {
							

							}
							else {
								

								max++;
							}
							st++;
						}
					}
					while(l<=r) {
						if(l%2!=0) {
							q.add(cur);
						}
						else {
							q.add(max);
							max++;
						}
						if(max>n) {
							cur++;
							max=cur+1;
						}
						
						l++;
					}
				break;	
				}
				
			counter-=2;
			
			start+=counter;
			}
			while(!q.isEmpty()) {
				if(r==last&&q.size()==2) {
					q.poll();
					q.poll();
					out.print(n+" ");
					
					out.print(1);
				}
				else if(r==last&&q.size()==1) {
					q.poll();
					out.print(1);
				}
				else
				out.print(q.poll()+" ");
			}
			out.println();
			
		}
		out.flush();
	}
	static int idx=0;
	static long smalldp(int i) {
		if(i==n) {
			i=0;
		}
		if(i==idx) {
			return 0;
		}
		
		int prev=i-1;
		if(i==0) {
			prev=n-1;
		}
		long ans=0;
		

		if(a[i]-b[prev]>0&&s[i]!=-1)
		return s[i];
			else if(a[i]-b[prev]>0&&s[i]==-1)
			 ans+=smalldp(i+1)+(a[i]-b[prev]);
			
		else
			ans+=smalldp(i+1);
		return s[i]=ans;
	}
	static long dpdp[][][][];
	static int modd=(int) 1e8;
	static long dp(int i,int j,int counth,int countf) {
		
		if(k1<countf) {
			return 0;
		}
		if(k2<counth) {
			return 0;	
		}
		if(i+j==n) {
			return 1;
		}
		if(dpdp[i][j][counth][countf]!=-1) {
			return dpdp[i][j][counth][countf];
		}
		long take1=0;
		long take2=0;
		if(i<n2)
		 take1=dp(i+1,j,counth+1,0)%modd;
		if(j<n1) 
		take2=dp(i,j+1,0,countf+1)%modd;
		return  dpdp[i][j][counth][countf]=(take1%modd+take2%modd)%modd;
		
	}
    

    static int findSubarraySum(int arr[], int n, int sum)  
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
	public static int countvowels() {
		int count=0;
		for (int i = 0; i < c.length; i++) {
			if(c[i]=='o'||c[i]=='e'||c[i]=='a'||c[i]=='i'||c[i]=='u') {
				count++;
			}
		}
		return count;
	}
	public static  char lastvowel() {
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
		int numofvow;
		char lastchar;
	public	Tri(String m,int a,char c1){
			s=m;
			numofvow=a;
			lastchar=c1;
			
		}
	public int compareTo(Tri t) {
		if (numofvow == t.numofvow)
			return lastchar - t.lastchar;
		return numofvow - t.numofvow;
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
	
    static int dp(int idx,int state) {
      if(idx==n) {
    	  return 0;
      }
      if(notmemo[idx][state]!=-1) {
    	  return notmemo[idx][state];
      }
     int take=0; int leave=0;int leaveall=0;
      if(a[idx]==1&&(state==1||state==0)) {
    	take=1+dp(idx+1,1);  
      }
      if(a[idx]==0&&state==0) {
    	 leave=1+dp(idx+1,state); 
      }
      leaveall=dp(idx+1,state);
      
      return notmemo[idx][state]=Math.max(take,Math.max(leaveall,leave));
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