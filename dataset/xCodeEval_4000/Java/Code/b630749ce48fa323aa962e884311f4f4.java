import java.util.*;
import java.util.logging.Level;
import java.io.*;

public class tr0 {
	static PrintWriter out;
	static StringBuilder sb;
	static final double EPS = 1e-9;
	static long mod = 1000000007;
	static int inf = (int) 1e9 + 2;
	static long[] fac;
	static int[] si;
	static ArrayList<Integer> primes;
	static ArrayList<qu>[] ad;
	static ArrayList<qu>[] d;
	static edge[] ed;
	static int[] l, ch;
	static int[] occ;
	static long[][] adjMatrix;
	static Queue<Integer>[] can;
	static String s;
	static int[][] memo, P;
	static int n, k;
	static int[] ans, p, aa, bb, qq;
	static boolean[] t;
	static HashMap<Integer, Integer> pri;
	static TreeMap<qu, Integer> map;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
		n = sc.nextInt();
		ad = new ArrayList[n];
		for (int i = 0; i < n; i++)
			ad[i] = new ArrayList<>();
		p = new int[n];
		map = new TreeMap<>();
		for (int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			ad[a].add(new qu(b, i, 0));
			ad[b].add(new qu(a, i, 0));
			map.put(new qu(a, b, 0), i);
			map.put(new qu(b, a, 0), i);
		}
		k = sc.nextInt();
		aa = new int[k];
		bb = new int[k];
		qq = new int[k];
		for (int i = 0; i < k; i++) {
			aa[i] = sc.nextInt()-1;
			bb[i] = sc.nextInt()-1;
			qq[i] = sc.nextInt();
		}
		ans = new int[n - 1];
		go(0);
		for (int i = 0; i < k; i++) {
			update(aa[i], bb[i], qq[i]);


	

		}
	

		for(int i=1;i<=n;i++)
			if(st.query(i, i)==0) {
		

				st.update_range(i, i, (int)1e6);
			}
		

	



		

	

		for (int i = 0; i < k; i++) {
			if (query(aa[i], bb[i]) != qq[i]) {
		

				System.out.println(-1);
				return;
			}
		}
		for(int i=1;i<n;i++) {
			ans[map.get(new qu(i, P[i][0], 0))]= st.query(segIdx[i], segIdx[i]);
		}
		for(int i=0;i<n-1;i++)
			out.print(ans[i]+" ");
		out.flush();
	}
   
	static void update(int u, int v, int val) {
		int lca = lca_query(u, v);
		int lca1 = get(u, lca);
		int lca2 = get(v, lca);


		if(lca!=u)
		update_up(u, lca1, val);
		if(lca!=v)
		update_up(v, lca2, val);
	}

	static int get(int p, int anc) {
		int k = 20;
	



		for (int i = k; i >= 0; i--)
			if (i < P[p].length && P[p][i] != -1 && level[P[p][i]] > level[anc]) {
				p = P[p][i];
			}
	

		return p;
	}

	static void update_up(int v, int u, int val) {
		int uChain = chainIdx[u], vChain = chainIdx[v];
    

		while (uChain != vChain) {
			st.update_range(segIdx[chainHead[vChain]], segIdx[v], val);
		

			v = P[chainHead[vChain]][0];
			vChain = chainIdx[v];
		}
		

		st.update_range(segIdx[u], segIdx[v], val);

	}

	static int query(int u, int v) {
		int lca = lca_query(u, v);
		int lca1 = get(u, lca);
		int lca2 = get(v, lca);
		int ac=Integer.MAX_VALUE;
		int bc=Integer.MAX_VALUE;
		if(lca!=v)
		ac=query_up(v, lca2);
		if(lca!=u)
		bc=query_up(u, lca1);
		return Math.min(ac, bc);
	}

	static int query_up(int v, int u) {
		int uChain = chainIdx[u], vChain = chainIdx[v], ans = Integer.MAX_VALUE;

		while (uChain != vChain) {
			ans = Math.min(st.query(segIdx[chainHead[vChain]], segIdx[v]),ans);
			v = P[chainHead[vChain]][0];
			vChain = chainIdx[v];
		}

		ans = Math.min(st.query(segIdx[u], segIdx[v]),ans);
		return ans;
	}

	

	static SegmentTree st;

	

	static void go(int root) {
		

		int k = (int) (Math.floor(Math.log(n) / Math.log(2))) + 1;
		P = new int[n][k];
		for (int i = 0; i < n; i++)
			Arrays.fill(P[i], -1);

		

		subSize = new int[n];
		level = new int[n];
		P[root][0] = -1;
		dfs(root, -1, 0);

		

		for (int j = 1; j < k; j++)
			for (int i = 1; i < n; i++)
				if (P[i][j - 1] != -1)
					P[i][j] = P[P[i][j - 1]][j - 1];

		

		chainNo = 0;
		sIdx = 0;
		chainHead = new int[n];
		chainPos = new int[n];
		chainIdx = new int[n];
		chainSize = new int[n];
		segIdx = new int[n];
		Arrays.fill(chainHead, -1);
		hld(root);

		

		int N = (int) Math.pow(2, Math.ceil(Math.log(n) / Math.log(2)));
		int[] in = new int[N + 1];

		st = new SegmentTree(in);
	}

	static int[] subSize, level;

	static void dfs(int u, int parent, int depth) {
		level[u] = depth;
		subSize[u] = 1;
		for (qu v : ad[u])
			if (v.a != parent) {
				P[v.a][0] = u;
				dfs(v.a, u, depth + 1);
				subSize[u] += subSize[v.a];
			}
	}

	static int chainNo, sIdx;
	static int[] chainHead, chainPos, chainIdx, chainSize, segIdx;

	static void hld(int cur) {
		if (chainHead[chainNo] == -1)
			chainHead[chainNo] = cur;
		chainIdx[cur] = chainNo;
		chainPos[cur] = chainSize[chainNo]++;
		segIdx[cur] = ++sIdx;

		int nxt = -1, maxSize = -1;
		for (qu v : ad[cur])
			if (P[cur][0] != v.a && subSize[v.a] > maxSize) {
				maxSize = subSize[v.a];
				nxt = v.a;
			}
		if (nxt != -1)
			hld(nxt);
		for (qu v : ad[cur])
			if (P[cur][0] != v.a && v.a != nxt) {
				chainNo++;
				hld(v.a);
			}
	}

	static int lca_query(int p, int q) {
		int tmp, log, i;

		

		if (level[p] < level[q]) {
			tmp = p;
			p = q;
			q = tmp;
		}

		

		for (log = 1; 1 << log <= level[p]; log++)
			;
		log--;

		

		

		for (i = log; i >= 0; i--)
			if (level[p] - (1 << i) >= level[q])
				p = P[p][i];

		if (p == q)
			return p;

		

		for (i = log; i >= 0; i--)
			if (P[p][i] != -1 && P[p][i] != P[q][i]) {
				p = P[p][i];
				q = P[q][i];
			}

		return P[p][0];
	}

	static class SegmentTree {

		int N;
		int[] array, sTree, lazy;

		SegmentTree(int[] in) {
			array = in;
			N = in.length - 1;
			sTree = new int[N << 1];
			lazy = new int[N << 1];
	


		}

		void update_range(int i, int j, int val) 

		{
			update_range(1, 1, N, i, j, val);
		}

		void update_range(int node, int b, int e, int i, int j, int val) {
			if (i > e || j < b)
				return;
			if (b >= i && e <= j) {
			

				sTree[node] = Math.max(val, sTree[node]);
				

				lazy[node] = Math.max(lazy[node], val);
				

				

					

					

				

				
			} else {
				int mid = b + e >> 1;
				propagate(node, b, mid, e);
				update_range(node << 1, b, mid, i, j, val);
				update_range(node << 1 | 1, mid + 1, e, i, j, val);
				sTree[node] = Math.min(sTree[node << 1], sTree[node << 1 | 1]);
			}
		}
		void propagate(int node, int b, int mid, int e)		
		{
	

		

			

				

			lazy[node<<1] =Math.max(lazy[node], lazy[node<<1]);
			lazy[node<<1|1] =Math.max(lazy[node], lazy[node<<1|1]);
			sTree[node<<1] =Math.max(lazy[node], sTree[node<<1]);		
			sTree[node<<1|1] =Math.max(lazy[node], sTree[node<<1|1]);	
			lazy[node] = 0;
		}

		int query(int i, int j) {
			return query(1, 1, N, i, j);
		}

		int query(int node, int b, int e, int i, int j) {
			if (i > e || j < b)
				return (int) 1e6;
			if (b >= i && e <= j)
				return sTree[node];
			propagate(node, b, b+e >>1, e);
			return Math.min(query(node << 1, b, (b + e) / 2, i, j), query((node << 1) + 1, (b + e) / 2 + 1, e, i, j));
		}

	}

	static class qu implements Comparable<qu> {
		int a;
		int b;
		int w;

		qu(int aa, int bb, int cc) {
			a = aa;
			b = bb;
			w = cc;
		}

		public String toString() {
			return a + " " + b + " " + w;
		}

		public int compareTo(qu o) {
			if (a == o.a)
				return b - o.b;
			return a - o.a;
		}
	}

	static class seg implements Comparable<seg> {
		int a;
		int b;
		int l;
		int r;
		int bit;

		seg(int s, int e, int x, int y, int bi) {
			a = s;
			b = e;
			l = x;
			r = y;
			bit = bi;
		}

		public String toString() {
			return a + " " + b + " " + l + " " + r + " " + bit;
		}

		public int compareTo(seg o) {
			

			return bit - o.bit;
			

		}
	}

	static class pair implements Comparable<pair> {
		long to;
		long number;

		pair(long t, long n) {
			number = n;
			to = t;
		}

		public String toString() {
			return to + " " + number;
		}

		@Override
		public int compareTo(pair o) {
			if (o.to < to)
				return 1;
			return -1;
		}

	}

	static long modPow(long a, long e)

	{
		long res = 1;
		while (e > 0) {
			if ((e & 1) == 1)
				res = (res * a) % mod;
			a = (a * a) % mod;
			e >>= 1;
		}
		return res;
	}

	static long inver(long x) {
		long a = x;
		long e = (mod - 2);
		long res = 1;
		while (e > 0) {
			if ((e & 1) == 1) {
				res = ((1l * res * a) % mod);
			}
			a = ((1l * a * a) % mod);
			e >>= 1;
		}
		return res % mod;
	}

	static class edge implements Comparable<edge> {
		int from;
		int to;
		int number;

		edge(int f, int t, int n) {
			from = f;
			to = t;
			number = n;
		}

		public String toString() {
			return from + " " + to + " " + number;
		}

		public int compareTo(edge f) {
			return f.number - number;
		}
	}

	static void seive(int N) {
		si = new int[N];
		primes = new ArrayList<>();
		si[1] = 1;
		for (int i = 2; i < N; i++) {
			if (si[i] == 0) {
				si[i] = i;
				primes.add(i);
			}
			for (int j = 0; j < primes.size() && primes.get(j) <= si[i] && (i * primes.get(j)) < N; j++)
				si[primes.get(j) * i] = primes.get(j);
		}
	}

	static long fac(int n) {
		if (n == 0)
			return fac[n] = 1;
		if (n == 1)
			return fac[n] = 1;
		long ans = 1;
		for (int i = 1; i <= n; i++)
			fac[i] = ans = (i % mod * ans % mod) % mod;
		return ans % mod;
	}

	static long gcd(long a, long b) {

		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static class unionfind {
		int[] p;
		int[] size;
		int[] max;
		int num;

		unionfind(int n) {
			p = new int[n];
			size = new int[n];
			max = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = i;
				max[i] = i;
			}
			Arrays.fill(size, 1);
			num = n;
		}

		int findSet(int v) {
			if (v == p[v])
				return v;

			max[v] = Math.max(max[v], max[p[v]]);

			p[v] = findSet(p[v]);

			max[v] = Math.max(max[v], max[p[v]]);

			return p[v];
		}

		boolean sameSet(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return true;
			return false;
		}

		int max() {
			int max = 0;
			for (int i = 0; i < size.length; i++)
				if (size[i] > max)
					max = size[i];
			return max;
		}

		boolean combine(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return true;
			

			num--;
			if (size[a] > size[b]) {
				p[b] = a;
				max[a] = Math.max(max[a], max[b]);
				size[a] += size[b];

			} else {
				p[a] = b;
				max[b] = Math.max(max[a], max[b]);
				size[b] += size[a];
			}
			return false;
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