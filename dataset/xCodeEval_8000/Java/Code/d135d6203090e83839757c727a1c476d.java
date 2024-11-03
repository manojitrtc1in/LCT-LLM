import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		InputReader in = new InputReader(inputStream);





		

		







		

		


		for (int i = 1; i <= 20000; i++) {
			

		}
		Task t = new Task();
		t.solve(in, out);
		out.close();
	}

	static class Task {
		public void solve1(InputReader in, PrintWriter out) throws IOException {
			int n = in.nextInt();			
			int arr[] = new int[n];
			int brr[] = new int[n];
			
			int[] inc = new int[n+1];
			
			for(int i=0;i<n;i++) {
				int a = in.nextInt();
				arr[i] = a;
				brr[a] = i;
			}

			long sum = 0;
			for(int i=0;i<n;i++) {
				int idx = brr[i];
				if(idx>=i) {
					if(idx-i>=n/2) {
						inc[0]--;
						sum+=n-idx+i;
						inc[n-idx+i]+=2;
						inc[n-idx+i+n/2]-=2;
					}else {
						inc[0]++;
						sum+=idx-i;
						inc[n/2-idx+i]-=2;
						inc[n-idx+i]+=2;
					}
				}else {
					if(i-idx>=n/2){
						inc[0]++;
						sum+=n-i+idx;
						inc[n-i+idx]-=2;
						inc[n-i+idx+n/2]+=2;
					}else {
						inc[0]--;
						sum+=i-idx;
						inc[i-idx]+=2;
						inc[i-idx+n/2]-=2;
					}
				}
			}
			
			long ret = sum;
			for(int i=0;i<n-1;i++) {
				sum+=inc[i];
				ret = Math.min(ret, sum);
			}
			out.println(ret);
		}

		class edge1 implements Comparable<edge1>{
			int f,t,len;
			public edge1(int a, int b, int c) {
				f=a;t=b;len=c;
			}
			@Override
			public int compareTo(edge1 o) {
				

				return 0;
			}		
		}
	

		public void solve(InputReader in, PrintWriter out) throws IOException {
			int c = in.nextInt();
			int o = 0;
			while(c-->0) {
				o++;
				int n = in.nextInt();
				ArrayList<item> all = new ArrayList<item>();
				ArrayList<item>[] g = new ArrayList[n+1];
				for(int i=0;i<=n;i++) g[i] = new ArrayList<item>();
				for(int i=0;i<n;i++) {
					int f = in.nextInt();
					int t = in.nextInt();
					int x = in.nextInt();
					if(o==11) {
						

					}
					all.add(new item(f,t,x,i));
					g[x].add(new item(f,t,x,i));
				}
				Collections.sort(all);

				
				int ret[] = new int[n];
				int f = Integer.MAX_VALUE;
				int x[] = new int[n];

				int y[] = new int[n];

				int idx[] = new int[n];

				Arrays.fill(ret, f);
				for(int i=0;i<n;i++) {
					x[i] = all.get(i).f;
					y[i] = all.get(i).t;
					idx[all.get(i).id] = i; 
				}
						
				sgt s = new sgt(0,n,x);
				sgt sy = new sgt(0,n,y);
				for(int i=1;i<=n;i++) {
					for(item xx:g[i]) {
						int index = idx[xx.id];
						s.change(index, index+1, f-xx.f);

						sy.change(index, index+1, -xx.t);

					}
					for(item xx:g[i]) {
						int p = bsearch(all, xx);

						if(p!=-1) {
							int min = s.query_min(p, n);

							if(min<=xx.t) {
								ret[xx.id] = 0;  
							}else if(min!=f){
								ret[xx.id] = Math.min(ret[xx.id], min-xx.t);
							}
						}
						if(ret[xx.id]!=0) {
							int max = sy.query_max(0, idx[xx.id]);
							if(max>0) ret[xx.id] = Math.min(ret[xx.id], xx.f-max); 
						}
					}
					for(item xx:g[i]) {
						int index = idx[xx.id];
						s.change(index, index+1, xx.f-f);
						sy.change(index, index+1, xx.t);
					}					
				}
				for(int i:ret) out.print(i+" ");
				out.println();
			}	
		}	
		public int bsearch(ArrayList<item> arr, item t) {
			int l = 0; int r = arr.size()-1;
			while(l<r-1) {
				int mid = l+(r-l)/2;
				if(arr.get(mid).t>=t.f) {
					r =  mid;
				}
				else {
					l = mid;
				}			
			}
			if(l<arr.size()&&arr.get(l).t>=t.f) return l;
			else if(r>l&&arr.get(r).t>=t.f) return r;
			return -1;
		}		
		
		public class item implements Comparable<item>{
			int f, t;
			int c;int id;
			public item(int a, int b, int x, int d) {
				f=a;t=b;c=x;id = d;
			}
			@Override
			public int compareTo(Main.Task.item o) {
				if(this.t==o.t) return this.f-o.f;
				else return this.t-o.t;
			}			
		}


		public class edge implements Comparable<edge> {
			int f, t;
			long len;
			int id;

			public edge(int a, int b, long c, int d) {
				f = a;
				t = b;
				len = c;
				id = d;
			}

			@Override
			public int compareTo(Main.Task.edge o) {
				if (this.len - o.len < 0)
					return -1;
				else if (this.len == o.len)
					return 0;
				else
					return 1;
			}
		}

		public Set<Integer> get_factor(int number) {
			int n = number;
			Set<Integer> primeFactors = new HashSet<Integer>();
			for (int i = 2; i <= n / i; i++) {
				while (n % i == 0) {
					primeFactors.add(i);
					n /= i;
				}
			}
			if (n > 1)
				primeFactors.add(n);
			return primeFactors;
		}

		private static long cnr(int n, int m, long mod, long fac[], long inv[]) {
			if (n < m)
				return 0;
			return fac[n] * inv[n - m] % mod * inv[m] % mod;
		}

		private static int combx(int n, int k, int mod) {
			if (n < k)
				return 0;
			int comb[][] = new int[n + 1][n + 1];
			for (int i = 0; i <= n; i++) {
				comb[i][0] = comb[i][i] = 1;
				for (int j = 1; j < i; j++) {
					comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
					comb[i][j] %= mod;
				}
			}
			return comb[n][k];
		}

		private static long qpow(long a, long p, long MOD) {
			long m = Long.highestOneBit(p);
			long ans = 1;
			for (; m > 0; m >>>= 1) {
				ans = ans * ans % MOD;
				if ((p & m) > 0)
					ans = ans * a % MOD;
			}
			return (int) ans;
		}

		class trie_node {
			boolean end;
			int val;
			int lvl;
			trie_node zero;
			trie_node one;

			public trie_node() {
				zero = null;
				one = null;
				end = false;
				val = -1;
				lvl = -1;
			}
		}

		class trie {
			trie_node root = new trie_node();

			public void build(int x, int sz) {
				trie_node cur = root;
				for (int i = sz; i >= 0; i--) {
					int v = (x & (1 << i)) == 0 ? 0 : 1;
					if (v == 0 && cur.zero == null) {
						cur.zero = new trie_node();
					}
					if (v == 1 && cur.one == null) {
						cur.one = new trie_node();
					}
					cur.lvl = i;
					if (i == 0) {
						cur.end = true;
						cur.val = x;
					} else {

						if (v == 0)
							cur = cur.zero;
						else
							cur = cur.one;
						cur.val = v;
						cur.lvl = i;
					}
				}
			}

			int search(int num, int limit, trie_node r, int lvl) {
				if (r == null)
					return -1;
				if (r.end)
					return r.val;
				int f = -1;
				int num_val = (num & 1 << lvl) == 0 ? 0 : 1;
				int limit_val = (limit & 1 << lvl) == 0 ? 0 : 1;

				if (limit_val == 1) {
					if (num_val == 0) {
						int t = search(num, limit, r.one, lvl - 1);
						if (t > f)
							return t;
						t = search(num, limit, r.zero, lvl - 1);
						if (t > f)
							return t;
					} else {
						int t = search(num, limit, r.zero, lvl - 1);
						if (t > f)
							return t;
						t = search(num, limit, r.one, lvl - 1);
						if (t > f)
							return t;
					}
				} else {
					int t = search(num, limit, r.zero, lvl - 1);
					if (t > f)
						return t;
				}
				return f;
			}
		}

		public int[] maximizeXor(int[] nums, int[][] queries) {
			int m = queries.length;
			int ret[] = new int[m];
			trie t = new trie();
			int sz = 5;
			for (int i : nums)
				t.build(i, sz);
			int p = 0;
			for (int x[] : queries) {
				if (p == 1) {
					Dumper.print("here");
				}
				ret[p++] = t.search(x[0], x[1], t.root, sz);
			}
			return ret;
		}

		

		static class lca_naive {
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int pare[];
			int dist[];

			public lca_naive(int t, ArrayList<edge>[] x) {
				n = t;
				g = x;
				lvl = new int[n];
				pare = new int[n];
				dist = new int[n];
			}

			void pre_process() {
				dfs(0, -1, g, lvl, pare, dist);
			}

			void dfs(int cur, int pre, ArrayList<edge>[] g, int lvl[], int pare[], int dist[]) {
				for (edge nxt_edge : g[cur]) {
					if (nxt_edge.t != pre) {
						lvl[nxt_edge.t] = lvl[cur] + 1;
						dist[nxt_edge.t] = (int) (dist[cur] + nxt_edge.len);
						pare[nxt_edge.t] = cur;
						dfs(nxt_edge.t, cur, g, lvl, pare, dist);
					}
				}
			}

			public int work(int p, int q) {
				int a = p;
				int b = q;
				while (lvl[p] < lvl[q])
					q = pare[q];
				while (lvl[p] > lvl[q])
					p = pare[p];
				while (p != q) {
					p = pare[p];
					q = pare[q];
				}
				int c = p;
				return dist[a] + dist[b] - dist[c] * 2;
			}
		}

		static class lca_binary_lifting {
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int pare[];
			int dist[];
			int table[][];

			public lca_binary_lifting(int a, ArrayList<edge>[] t) {
				n = a;
				g = t;
				lvl = new int[n];
				pare = new int[n];
				dist = new int[n];
				table = new int[20][n];
			}

			void pre_process() {
				dfs(0, -1, g, lvl, pare, dist);
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < n; j++) {
						if (i == 0)
							table[0][j] = pare[j];
						else
							table[i][j] = table[i - 1][table[i - 1][j]];
					}
				}
			}

			void dfs(int cur, int pre, ArrayList<edge>[] g, int lvl[], int pare[], int dist[]) {
				for (edge nxt_edge : g[cur]) {
					if (nxt_edge.t != pre) {
						lvl[nxt_edge.t] = lvl[cur] + 1;
						dist[nxt_edge.t] = (int) (dist[cur] + nxt_edge.len);
						pare[nxt_edge.t] = cur;
						dfs(nxt_edge.t, cur, g, lvl, pare, dist);
					}
				}
			}

			public int work(int p, int q) {
				int a = p;
				int b = q;
				if (lvl[p] > lvl[q]) {
					int tmp = p;
					p = q;
					q = tmp;
				}
				for (int i = 19; i >= 0; i--) {
					if (lvl[table[i][q]] >= lvl[p])
						q = table[i][q];
				}
				if (p == q)
					return p;

				for (int i = 19; i >= 0; i--) {
					if (table[i][p] != table[i][q]) {
						p = table[i][p];
						q = table[i][q];
					}
				}
				return table[0][p];
				

			}
		}

		static class lca_sqrt_root {
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int pare[];
			int dist[];
			int jump[];
			int sz;

			public lca_sqrt_root(int a, ArrayList<edge>[] b) {
				n = a;
				g = b;
				lvl = new int[n];
				pare = new int[n];
				dist = new int[n];
				jump = new int[n];
				sz = (int) Math.sqrt(n);
			}

			void pre_process() {
				dfs(0, -1, g, lvl, pare, dist, jump);
			}

			void dfs(int cur, int pre, ArrayList<edge>[] g, int lvl[], int pare[], int dist[], int[] jump) {
				for (edge nxt_edge : g[cur]) {
					if (nxt_edge.t != pre) {
						lvl[nxt_edge.t] = lvl[cur] + 1;
						dist[nxt_edge.t] = (int) (dist[cur] + nxt_edge.len);
						pare[nxt_edge.t] = cur;
						if (lvl[nxt_edge.t] % sz == 0) {
							jump[nxt_edge.t] = cur;
						} else {
							jump[nxt_edge.t] = jump[cur];
						}
						dfs(nxt_edge.t, cur, g, lvl, pare, dist, jump);
					}
				}
			}

			int work(int p, int q) {
				int a = p;
				int b = q;
				if (lvl[p] > lvl[q]) {
					int tmp = p;
					p = q;
					q = tmp;
				}
				while (jump[p] != jump[q]) {
					if (lvl[p] > lvl[q])
						p = jump[p];
					else
						q = jump[q];
				}
				while (p != q) {
					if (lvl[p] > lvl[q])
						p = pare[p];
					else
						q = pare[q];
				}
				return dist[a] + dist[b] - dist[p] * 2;
			}
		}






















		class pair implements Comparable<pair> {
			int idx, lvl;

			public pair(int a, int b) {
				idx = a;
				lvl = b;
			}

			@Override
			public int compareTo(pair t) {
				return t.lvl - this.lvl;
			}
		}

		static class lca_RMQ {
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int dist[];
			int tour[];
			int tour_rank[];
			int first_occ[];
			int c;
			sgt s;

			public lca_RMQ(int a, ArrayList<edge>[] b) {
				n = a;
				g = b;
				c = 0;
				lvl = new int[n];
				dist = new int[n];
				tour = new int[2 * n];
				tour_rank = new int[2 * n];
				first_occ = new int[n];
				Arrays.fill(first_occ, -1);
			}

			void pre_process() {
				tour[c++] = 0;
				dfs(0, -1);
				for (int i = 0; i < 2 * n; i++) {
					tour_rank[i] = lvl[tour[i]];
					if (first_occ[tour[i]] == -1)
						first_occ[tour[i]] = i;
				}
				s = new sgt(0, 2 * n, tour_rank);
			}

			void dfs(int cur, int pre) {
				for (edge nxt_edge : g[cur]) {
					if (nxt_edge.t != pre) {
						lvl[nxt_edge.t] = lvl[cur] + 1;
						dist[nxt_edge.t] = (int) (dist[cur] + nxt_edge.len);
						tour[c++] = nxt_edge.t;
						dfs(nxt_edge.t, cur);
						tour[c++] = cur;
					}
				}
			}

			int work(int p, int q) {
				int a = Math.max(first_occ[p], first_occ[q]);
				int b = Math.min(first_occ[p], first_occ[q]);
				int idx = s.query_min_idx(b, a + 1);
				

				int c = tour[idx];
				return dist[p] + dist[q] - dist[c] * 2;
			}
		}

		static class sgt {
			sgt lt;
			sgt rt;
			int l, r;
			int sum, max, min, lazy;
			int min_idx;

			public sgt(int L, int R, int arr[]) {
				l = L;
				r = R;
				if (l == r - 1) {
					sum = max = min = arr[l];
					lazy = 0;
					min_idx = l;
					return;
				}
				lt = new sgt(l, l + r >> 1, arr);
				rt = new sgt(l + r >> 1, r, arr);
				pop_up();
			}

			void pop_up() {
				this.sum = lt.sum + rt.sum;
				this.max = Math.max(lt.max, rt.max);
				this.min = Math.min(lt.min, rt.min);
				if (lt.min < rt.min)
					this.min_idx = lt.min_idx;
				else if (lt.min > rt.min)
					this.min_idx = rt.min_idx;
				else
					this.min_idx = Math.min(lt.min_idx, rt.min_idx);
			}

			void push_down() {
				if (this.lazy != 0) {
					lt.sum += lazy;
					rt.sum += lazy;
					lt.max += lazy;
					lt.min += lazy;
					rt.max += lazy;
					rt.min += lazy;
					lt.lazy += this.lazy;
					rt.lazy += this.lazy;
					this.lazy = 0;
				}
			}

			void change(int L, int R, int v) {
				if (R <= l || r <= L)
					return;
				if (L <= l && r <= R) {
					this.max += v;
					this.min += v;
					this.sum += v * (r - l);
					this.lazy += v;
					return;
				}
				push_down();
				lt.change(L, R, v);
				rt.change(L, R, v);
				pop_up();
			}

			int query_max(int L, int R) {
				if (L <= l && r <= R)
					return this.max;
				if (r <= L || R <= l)
					return Integer.MIN_VALUE;
				push_down();
				return Math.max(lt.query_max(L, R), rt.query_max(L, R));
			}

			int query_min(int L, int R) {
				if (L <= l && r <= R)
					return this.min;
				if (r <= L || R <= l)
					return Integer.MAX_VALUE;
				push_down();
				return Math.min(lt.query_min(L, R), rt.query_min(L, R));
			}

			int query_sum(int L, int R) {
				if (L <= l && r <= R)
					return this.sum;
				if (r <= L || R <= l)
					return 0;
				push_down();
				return lt.query_sum(L, R) + rt.query_sum(L, R);
			}

			int query_min_idx(int L, int R) {
				if (L <= l && r <= R)
					return this.min_idx;
				if (r <= L || R <= l)
					return Integer.MAX_VALUE;
				int a = lt.query_min_idx(L, R);
				int b = rt.query_min_idx(L, R);
				int aa = lt.query_min(L, R);
				int bb = rt.query_min(L, R);
				if (aa < bb)
					return a;
				else if (aa > bb)
					return b;
				return Math.min(a, b);
			}
		}

		List<List<Integer>> convert(int arr[][]) {
			int n = arr.length;
			List<List<Integer>> ret = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				ArrayList<Integer> tmp = new ArrayList<Integer>();
				for (int j = 0; j < arr[i].length; j++)
					tmp.add(arr[i][j]);
				ret.add(tmp);
			}
			return ret;
		}

		public class TreeNode {
			int val;
			TreeNode left;
			TreeNode right;

			TreeNode(int x) {
				val = x;
			}
		}

		public int GCD(int a, int b) {
			if (b == 0)
				return a;
			return GCD(b, a % b);
		}

		public long GCD(long a, long b) {
			if (b == 0)
				return a;
			return GCD(b, a % b);
		}
	}

	static class ArrayUtils {
		static final long seed = System.nanoTime();
		static final Random rand = new Random(seed);

		public static void sort(int[] a) {
			shuffle(a);
			Arrays.sort(a);
		}

		public static void shuffle(int[] a) {
			for (int i = 0; i < a.length; i++) {
				int j = rand.nextInt(i + 1);
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}

		public static void sort(long[] a) {
			shuffle(a);
			Arrays.sort(a);
		}

		public static void shuffle(long[] a) {
			for (int i = 0; i < a.length; i++) {
				int j = rand.nextInt(i + 1);
				long t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	static class BIT {
		long arr[];
		int n;

		public BIT(int a) {
			n = a;
			arr = new long[n];
		}

		long sum(int p) {
			long s = 0;
			while (p > 0) {
				s += arr[p];
				p -= p & (-p);
			}
			return s;
		}

		void add(int p, long v) {
			while (p < n) {
				arr[p] += v;
				p += p & (-p);
			}
		}
	}

	static class DSU {
		int[] arr;
		int[] sz;

		public DSU(int n) {
			arr = new int[n];
			sz = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = i;
			Arrays.fill(sz, 1);
		}

		public int find(int a) {
			if (arr[a] != a)
				arr[a] = find(arr[a]);
			return arr[a];
		}

		public void union(int a, int b) {
			int x = find(a);
			int y = find(b);
			if (x == y)
				return;
			arr[y] = x;
			sz[x] += sz[y];
		}

		public int size(int x) {
			return sz[find(x)];
		}
	}

	static class MinHeap<Key> implements Iterable<Key> {
		private int maxN;
		private int n;
		private int[] pq;
		private int[] qp;
		private Key[] keys;
		private Comparator<Key> comparator;

		public MinHeap(int capacity) {
			if (capacity < 0)
				throw new IllegalArgumentException();
			this.maxN = capacity;
			n = 0;
			pq = new int[maxN + 1];
			qp = new int[maxN + 1];
			keys = (Key[]) new Object[capacity + 1];
			Arrays.fill(qp, -1);
		}

		public MinHeap(int capacity, Comparator<Key> c) {
			if (capacity < 0)
				throw new IllegalArgumentException();
			this.maxN = capacity;
			n = 0;
			pq = new int[maxN + 1];
			qp = new int[maxN + 1];
			keys = (Key[]) new Object[capacity + 1];
			Arrays.fill(qp, -1);
			comparator = c;
		}

		public boolean isEmpty() {
			return n == 0;
		}

		public int size() {
			return n;
		}

		public boolean contains(int i) {
			if (i < 0 || i >= maxN)
				throw new IllegalArgumentException();
			return qp[i] != -1;
		}

		public int peekIdx() {
			if (n == 0)
				throw new NoSuchElementException("Priority queue underflow");
			return pq[1];
		}

		public Key peek() {
			if (isEmpty())
				throw new NoSuchElementException("Priority queue underflow");
			return keys[pq[1]];
		}

		public int poll() {
			if (isEmpty())
				throw new NoSuchElementException("Priority queue underflow");
			int min = pq[1];
			exch(1, n--);
			down(1);
			assert min == pq[n + 1];
			qp[min] = -1;
			keys[min] = null;
			pq[n + 1] = -1;
			return min;
		}

		public void update(int i, Key key) {
			if (i < 0 || i >= maxN)
				throw new IllegalArgumentException();
			if (!contains(i)) {
				this.add(i, key);
			} else {
				keys[i] = key;
				up(qp[i]);
				down(qp[i]);
			}
		}

		private void add(int i, Key x) {
			if (i < 0 || i >= maxN)
				throw new IllegalArgumentException();
			if (contains(i))
				throw new IllegalArgumentException("index is already in the priority queue");
			n++;
			qp[i] = n;
			pq[n] = i;
			keys[i] = x;
			up(n);
		}

		private void up(int k) {
			while (k > 1 && less(k, k / 2)) {
				exch(k, k / 2);
				k /= 2;
			}
		}

		private void down(int k) {
			while (2 * k <= n) {
				int j = 2 * k;
				if (j < n && less(j + 1, j))
					j++;
				if (less(k, j))
					break;
				exch(k, j);
				k = j;
			}
		}

		public boolean less(int i, int j) {
			if (comparator == null) {
				return ((Comparable<Key>) keys[pq[i]]).compareTo(keys[pq[j]]) < 0;
			} else {
				return comparator.compare(keys[pq[i]], keys[pq[j]]) < 0;
			}
		}

		public void exch(int i, int j) {
			int swap = pq[i];
			pq[i] = pq[j];
			pq[j] = swap;
			qp[pq[i]] = i;
			qp[pq[j]] = j;
		}

		@Override
		public Iterator<Key> iterator() {
			

			return null;
		}
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int zcurChar;
		private int znumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (znumChars == -1)
				throw new InputMismatchException();
			if (zcurChar >= znumChars) {
				zcurChar = 0;
				try {
					znumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (znumChars <= 0)
					return -1;
			}
			return buf[zcurChar++];
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String nextString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public double nextDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return nextString();
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}

		public int[] readIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}
	}

	static class Dumper {
		static void print_int_arr(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void print_char_arr(char[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void print_double_arr(double[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void print_2d_arr(int[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void print_2d_arr(boolean[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void print(Object o) {
			System.out.println(o.toString());
		}

		static void getc() {
			System.out.println("here");
		}
	}
}