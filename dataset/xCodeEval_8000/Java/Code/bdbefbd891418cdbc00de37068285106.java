import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Objects;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public final class CFPS {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int gigamod = 1000000007;
	static int t = 1;
	static double epsilon = 0.00000001;
	static boolean[] isPrime;
	static int[] smallestFactorOf;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) throws Exception {
		t = fr.nextInt();
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int n = fr.nextInt(), c = fr.nextInt();
			int[] arr = fr.nextIntArray(n);
			
			

			
			

			
			

			
			TreeSet<Integer> missing = new TreeSet<>();
			TreeSet<Integer> present = new TreeSet<>();
			for (int i : arr) present.add(i);
			for (int i = 1; i < c + 1; i++)
				if (!present.contains(i))
					missing.add(i);
			
			if (missing.contains(1)) {
				out.println("No");
				continue OUTER;
			}
			
			present.remove(1);
			
			
			
			int[] is = new int[c + 1];
			for (int i : present)
				is[i] = 1;
			for (int i = 1; i < c + 1; i++)
				is[i] += is[i - 1];
			
			

			
			MISSING: 
			for (int x : missing) {
				for (int y : present) {
					if ((long) x * y > c) continue MISSING;
					
					int lo = x * y;
					int hi = Math.min((x + 1) * y - 1, c);
					
					int chg = is[hi];
					if (lo > 0)
						chg -= is[lo - 1];
					
					if (chg > 0) {
						out.println("No");
						

						continue OUTER;
					}
				}
			}
			
			out.println("Yes");
		}
		out.close();
	}
	
	static class Pos {
		long x, y;
	}
	
	static class Edge implements Comparable<Edge> {
		int from, to;
		long weight;
		int hash;
		
		Edge(int fro, int t, long weigh) {
			from = fro;
			to = t;
			weight = weigh;
			hash = Objects.hash(from, to, weight);
		}
		
		public int hashCode() {
			return hash;
		}
		
		public int compareTo(Edge that) {
			return Long.compare(weight, that.weight);
		}
	}
	
	static class MinSegTree {
		int n;
		long[] seg, lazy;
		
		MinSegTree(int n) {
			this.n = n;
			seg = new long[4*n];
			lazy = new long[4*n];
			Arrays.fill(seg, Long.MAX_VALUE/10);
			for (int i = 0; i < n; i++)
				rngAdd(0, 0, n - 1, i, i, -Long.MAX_VALUE);
		}
		
		MinSegTree(long[] arr) {
			n = arr.length;
			seg = new long[4*n];
			lazy = new long[4*n];
			Arrays.fill(seg, Long.MAX_VALUE/10);
			for (int i = 0; i < n; i++)
				rngAdd(0, 0, n - 1, i, i, arr[i] - Long.MAX_VALUE);
		}
		
		long rangeMin(int l, int r) {
			return rngMin(0, 0, n-1, l, r);
		}
		
		long rngMin(int n, int l, int r, int i, int j) {
			if (l!=r) propagate(n);
			if (l>j||r<i) return Long.MAX_VALUE/10;
			if (i==l&&j==r) {
				seg[n] = seg[2*n+1];
				if (seg[n] > seg[2*n+2])
					seg[n] = seg[2*n+2];
				return seg[n];
			}
			int m=l+(r-l)/2;
			long answer=Long.MAX_VALUE/10;
			if (i<=m)answer=rngMin(2*n+1, l, m, i, m);
			if (m+1<=j)answer=Math.min(answer, rngMin(2*n+2, m+1, r, m+1, j));
			seg[n] = seg[2*n+1];
			if (seg[n] > seg[2*n+2])
				seg[n] = seg[2*n+2];
			return answer;
		}
		
		void pointUpdate(int idx, long newVal) {
			long oldVal = rangeMin(idx, idx);
			this.rangeAdd(idx, idx, newVal - oldVal);
		}
		
		void rangeAdd(int l, int r, long val) {
			rngAdd(0, 0, n-1, l, r, val);
		}
		
		void rngAdd(int n, int l, int r, int i, int j, long val) {
			if (l!=r)propagate(n);
			if (l>j||r<i) return;
			if (i<=l && r<=j) {seg[n]+=val;lazy[n]+=val;return;}
			
			int m = l+(r-l)/2;
			rngAdd(2*n+1, l, m, i, j, val);
			rngAdd(2*n+2, m+1, r, i, j, val);
			
			

			seg[n] = seg[2*n+1];
			if (seg[n] > seg[2*n+2])
				seg[n] = seg[2*n+2];
		}
		
		void propagate(int n) {
			seg[2*n+1] += lazy[n];
			seg[2*n+2] += lazy[n];
			lazy[2*n+1] += lazy[n];
			lazy[2*n+2] += lazy[n];
			lazy[n] = 0;
		}
	}
	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		long z;
		long id;
		

		
		Point() {
			x = z = y = 0;
			

		}
		
		Point(Point p) {
			this.x = p.x;
			this.y = p.y;
			this.z = p.z;
			this.id = p.id;
			

		}
		
		Point(long x, long y, long z, long id) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.id = id;
			

		}
		
		Point(long a, long b) {
			this.x = a;
			this.y = b;
			this.z = 0;
			

		}
		
		Point(long x, long y, long id) {
			this.x = x;
			this.y = y;
			this.id = id;
		}
		
		@Override
		public int compareTo(Point o) {
			if (this.x < o.x)
				return -1;
			if (this.x > o.x)
				return 1;
			if (this.y < o.y)
				return -1;
			if (this.y > o.y)
				return 1;
			if (this.z < o.z)
				return -1;
			if (this.z > o.z)
				return 1;
			return 0;
		}
		
		@Override
		public boolean equals(Object that) {
			return this.compareTo((Point) that) == 0;
		}
		
		
	}
	
	static class BinaryLift {
		
		

		
		int[] parentOf;
		int maxJmpPow;
		int[][] binAncestorOf;
		int n;
		int[] lvlOf;
		
		

		
		

		
		

		

		
		public BinaryLift(UGraph tree) {
			n = tree.V();
			maxJmpPow = logk(n, 2) + 1;
			parentOf = new int[n];
			binAncestorOf = new int[n][maxJmpPow];
			lvlOf = new int[n];
			for (int i = 0; i < n; i++)
				Arrays.fill(binAncestorOf[i], -1);
			parentConstruct(0, -1, tree, 0);
			binConstruct();
		}
		
		

		public BinaryLift(int[] parentOf) {
			this.parentOf = parentOf;
			n = parentOf.length;
			maxJmpPow = logk(n, 2) + 1;
			binAncestorOf = new int[n][maxJmpPow];
			lvlOf = new int[n];
			for (int i = 0; i < n; i++)
				Arrays.fill(binAncestorOf[i], -1);
			UGraph tree = new UGraph(n);
			for (int i = 1; i < n; i++)
				tree.addEdge(i, parentOf[i]);
			binConstruct();
			parentConstruct(0, -1, tree, 0);
		}
		
		private void parentConstruct(int current, int from, UGraph tree, int depth) {
			parentOf[current] = from;
			lvlOf[current] = depth;
			for (int adj : tree.adj(current))
				if (adj != from)
					parentConstruct(adj, current, tree, depth + 1);
		}
		
		private void binConstruct() {
			for (int node = 0; node < n; node++)
				for (int lvl = 0; lvl < maxJmpPow; lvl++)
					binConstruct(node, lvl);
		}
		
		private int binConstruct(int node, int lvl) {
			if (node < 0)
				return -1;
			if (lvl == 0)
				return binAncestorOf[node][lvl] = parentOf[node];
			if (node == 0)
				return binAncestorOf[node][lvl] = -1;
			
			if (binAncestorOf[node][lvl] != -1)
				return binAncestorOf[node][lvl];
			return binAncestorOf[node][lvl] = binConstruct(binConstruct(node, lvl - 1), lvl - 1);
		}
		
		

		public int ancestor(int node, int k) {
			if (node < 0)
				return -1;
			if (node == 0)
				if (k == 0) return node;
				else return -1;
			if (k > (1 << maxJmpPow) - 1)
				return -1;
			if (k == 0)
				return node;
			
			int ancestor = node;
			int highestBit = Integer.highestOneBit(k);
			
			while (k > 0 && ancestor != -1) {
				ancestor = binAncestorOf[ancestor][logk(highestBit, 2)];
				k -= highestBit;
				highestBit = Integer.highestOneBit(k);
			}
			
			return ancestor;
		}
	
		public int lca(int u, int v) {
			
			if (u == v)
				return u;
			
			

			if (lvlOf[u] < lvlOf[v]) {
				int temp = u;
				u = v;
				v = temp;
			}
			
			

			u = ancestor(u, lvlOf[u] - lvlOf[v]);
			
			if (u == v)
				return u;
			
			

			for (int power = maxJmpPow - 1; power > -1; power--)
				if (binAncestorOf[u][power] != binAncestorOf[v][power]) {
					u = binAncestorOf[u][power];
					v = binAncestorOf[v][power];
				}
			
			return ancestor(u, 1);
		}
	}
	
	static class DFSTree {
		
		

		

		
		UGraph tree;
		UGraph backUG;
		int hasBridge;
		int n;
		
		
		DFSTree(UGraph ug) {
			this.n = ug.V();
			tree = new UGraph(n);
			hasBridge = -1;
			backUG = new UGraph(n);
			treeCalc(0, -1, new boolean[n], ug);
		}
		
		private void treeCalc(int current, int from, boolean[] marked, UGraph ug) {
			if (marked[current]) {
				

				backUG.addEdge(from, current);
				return;
			}
			
			if (from != -1)
				tree.addEdge(from, current);
			marked[current] = true;
			
			for (int adj : ug.adj(current))
				if (adj != from)
					treeCalc(adj, current, marked, ug);
		}
		
		public boolean hasBridge() {
			if (hasBridge != -1)
				return (hasBridge == 1);
			
			

			bridgeFinder();
			return (hasBridge == 1);
		}
		
		int[] levelOf; 
		int[] dp;
		
		private void bridgeFinder() {
			
			

			levelOf = new int[n];
			
			

			

			

			dp = new int[n];
			Arrays.fill(dp, Integer.MAX_VALUE / 100);
			dpDFS(0, -1, 0);
			
			

			

			
			for (int i = 0; i < n; i++)
				for (int adj : tree.adj(i)) {
					
					

					
					if (dp[adj] > levelOf[i])
						hasBridge = 1;
				}
			
			if (hasBridge != 1)
				hasBridge = 0;
		}
		
		private int dpDFS(int current, int from, int lvl) {
			levelOf[current] = lvl;
			dp[current] = levelOf[current];
			for (int back : backUG.adj(current))
				dp[current] = Math.min(dp[current], levelOf[back]);
			
			for (int adj : tree.adj(current))
				if (adj != from)
					dp[current] = Math.min(dp[current], dpDFS(adj, current, lvl + 1));
			
			return dp[current];
		}
	}
	
	static class UnionFind {
		

	    private int[] parent;  

	    private int[] size;    

	                           

	    private int count;     


	    public UnionFind(int n) {
	        count = n;
	        parent = new int[n];
	        size = new int[n];
	        for (int i = 0; i < n; i++) {
	            parent[i] = i;
	            size[i] = 1;
	        }
	    }

	    

	    public int count() {
	        return count;
	    }
	  
	    

	    public int find(int p) {
	    	while (p != parent[p])
	            p = parent[p];
	        return p;
	    }

	    public boolean connected(int p, int q) {
	        return find(p) == find(q);
	    }
	    
	    public int numConnectedTo(int node) {
	    	return size[find(node)];
	    }
	    
	    

	    public void union(int p, int q) {
	        int rootP = find(p);
	        int rootQ = find(q);
	        
	        if (rootP == rootQ) return;

	        

	        if (size[rootP] < size[rootQ]) {
	            parent[rootP] = rootQ;
	            size[rootQ] += size[rootP];
	        }
	        else {
	            parent[rootQ] = rootP;
	            size[rootP] += size[rootQ];
	        }
	        count--;
	    }
	    
	    public static int[] connectedComponents(UnionFind uf) {
	    	

	    	
	    	int n = uf.size.length;
	    	int[] compoColors = new int[n];
	    	for (int i = 0; i < n; i++)
	    		compoColors[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> oldToNew = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int thisOldColor = compoColors[i];
	    		Integer thisNewColor = oldToNew.get(thisOldColor);
	    		if (thisNewColor == null)
	    			thisNewColor = newCtr++;
	    		
	    		oldToNew.put(thisOldColor, thisNewColor);
	    		compoColors[i] = thisNewColor;
	    	}
	    	
	    	return compoColors;
	    }
	}
	
	static class UGraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		@SuppressWarnings("unchecked")
		public UGraph(int V) {
			adj = (HashSet<Integer>[]) new HashSet[V];
			E = 0;
			for (int i = 0; i < V; i++)
				adj[i] = new HashSet<Integer>();
		}
		
		public void addEdge(int from, int to) {
			if (adj[from].contains(to)) return;
			E++;
			adj[from].add(to);
			adj[to].add(from);
		}
		
		public HashSet<Integer> adj(int from) {
			return adj[from];
		}
		
		public int degree(int v) {
			return adj[v].size();
		}
		
		public int V() {
			return adj.length;
		}
		
		public int E() {
			return E;
		}
		
		public String toString() {
			StringBuilder s = new StringBuilder();
			s.append(V() + " vertices, " + E() + " edges " + NEWLINE);
			for (int v = 0; v < V(); v++) {
				s.append(v + ": ");
				for (int w : adj[v]) {
					s.append(w + " ");
				}
				s.append(NEWLINE);
			}
			return s.toString();
		}
		
		public static void dfsMark(int current, boolean[] marked, UGraph g) {
			if (marked[current]) return;
			
			marked[current] = true;
			Iterable<Integer> adj = g.adj(current);
			for (int adjc : adj)
				dfsMark(adjc, marked, g);
		}
		
		public static void dfsMark(int current, int from, long[] distTo, boolean[] marked, UGraph g, ArrayList<Integer> endPoints) {
			if (marked[current]) return;
			
			marked[current] = true;
			if (from != -1)
				distTo[current] = distTo[from] + 1;
			HashSet<Integer> adj = g.adj(current);
			int alreadyMarkedCtr = 0;
			for (int adjc : adj) {
				if (marked[adjc]) alreadyMarkedCtr++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (alreadyMarkedCtr == adj.size())
				endPoints.add(current);
		}
		
		public static void bfsOrder(int current, UGraph g) {
		}
		
		public static void dfsMark(int current, int[] colorIds, int color, UGraph g) {
			if (colorIds[current] != -1) return;
			
			colorIds[current] = color;
			Iterable<Integer> adj = g.adj(current);
			for (int adjc : adj)
				dfsMark(adjc, colorIds, color, g);
		}
		
		public static int[] connectedComponents(UGraph g) {
			int n = g.V();
			int[] componentId = new int[n];
			Arrays.fill(componentId, -1);
			int colorCtr = 0;
			for (int i = 0; i < n; i++) {
				if (componentId[i] != -1) continue;
				dfsMark(i, componentId, colorCtr, g);
				colorCtr++;
			}
			
			return componentId;
		}
		
		public static boolean hasCycle(UGraph ug) {
			int n = ug.V();
			boolean[] marked = new boolean[n];
			boolean[] hasCycleFirst = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				hcDfsMark(i, ug, marked, hasCycleFirst, -1);
			}
			return hasCycleFirst[0];
		}
		
		

		private static void hcDfsMark(int current, UGraph ug, boolean[] marked, boolean[] hasCycleFirst, int parent) {
			if (marked[current]) return;
			if (hasCycleFirst[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					hasCycleFirst[0] = true;
					return;
				}
				
				hcDfsMark(adj, ug, marked, hasCycleFirst, current);
			}
		}
	}
	
	static class Digraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		@SuppressWarnings("unchecked")
		public Digraph(int V) {
			adj = (HashSet<Integer>[]) new HashSet[V];
			E = 0;
			for (int i = 0; i < V; i++)
				adj[i] = new HashSet<Integer>();
		}
		
		public void addEdge(int from, int to) {
			if (adj[from].contains(to)) return;
			E++;
			adj[from].add(to);
		}
		
		public HashSet<Integer> adj(int from) {
			return adj[from];
		}
		
		public int V() {
			return adj.length;
		}
		
		public int E() {
			return E;
		}
		
		public Digraph reversed() {
			Digraph dg = new Digraph(V());
			for (int i = 0; i < V(); i++)
				for (int adjVert : adj(i)) dg.addEdge(adjVert, i);
			return dg;
		}
		
		public String toString() {
			StringBuilder s = new StringBuilder();
			s.append(V() + " vertices, " + E() + " edges " + NEWLINE);
			for (int v = 0; v < V(); v++) {
				s.append(v + ": ");
				for (int w : adj[v]) {
					s.append(w + " ");
				}
				s.append(NEWLINE);
			}
			return s.toString();
		}
		
		public static int[] KosarajuSharirSCC(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.topologicalSort(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					sccDFS(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void sccDFS(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) sccDFS(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> topologicalSort(Digraph dg) {
			

			

			

			Stack<Integer> topologicalStack = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					runDfs(dg, topologicalStack, marked, i);
			
			return topologicalStack;
		}
		
		static void runDfs(Digraph dg, Stack<Integer> topologicalStack, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					runDfs(dg, topologicalStack, marked, adjVertex);
			topologicalStack.add(source);
		}
	}
	
	static class FastReader {
		private BufferedReader bfr;
		private StringTokenizer st;
		public FastReader() {
			bfr = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			if (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(bfr.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		char nextChar() {
			return next().toCharArray()[0];
		}

		String nextString() {
			return next();
		}

		int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] nextDoubleArray(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] nextLongArray(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] nextIntGrid(int n, int m) {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					grid[i][j] = fr.nextInt();
			}
			return grid;
		}
	}
	
	static class LCA {
	    int[] height, first, segtree;
	    ArrayList<Integer> euler;
	    boolean[] visited;
	    int n;

	    LCA(UGraph ug, int root) {
	        n = ug.V();
	        height = new int[n];
	        first = new int[n];
	        euler = new ArrayList<>();
	        visited = new boolean[n];
	        dfs(ug, root, 0);
	        int m = euler.size();
	        segtree = new int[m * 4];
	        build(1, 0, m - 1);
	    }

	    void dfs(UGraph ug, int node, int h) {
	        visited[node] = true;
	        height[node] = h;
	        first[node] = euler.size();
	        euler.add(node);
	        for (int adj : ug.adj(node)) {
	            if (!visited[adj]) {
	                dfs(ug, adj, h + 1);
	                euler.add(node);
	            }
	        }
	    }

	    void build(int node, int b, int e) {
	        if (b == e) {
	            segtree[node] = euler.get(b);
	        } else {
	            int mid = (b + e) / 2;
	            build(node << 1, b, mid);
	            build(node << 1 | 1, mid + 1, e);
	            int l = segtree[node << 1], r = segtree[node << 1 | 1];
	            segtree[node] = (height[l] < height[r]) ? l : r;
	        }
	    }

	    int query(int node, int b, int e, int L, int R) {
	        if (b > R || e < L)
	            return -1;
	        if (b >= L && e <= R)
	            return segtree[node];
	        int mid = (b + e) >> 1;

	        int left = query(node << 1, b, mid, L, R);
	        int right = query(node << 1 | 1, mid + 1, e, L, R);
	        if (left == -1) return right;
	        if (right == -1) return left;
	        return height[left] < height[right] ? left : right;
	    }

	    int lca(int u, int v) {
	        int left = first[u], right = first[v];
	        if (left > right) {
	        	int temp = left;
	        	left = right;
	        	right = temp;
	        }
	        return query(1, 0, euler.size() - 1, left, right);
	    }
	}
	
	static class FenwickTree {

	    long[] array; 


	    public FenwickTree(int size) {
	        array = new long[size + 1];
	    }
	    
	    public long rsq(int ind) {
	        assert ind > 0;
	        long sum = 0;
	        while (ind > 0) {
	            sum += array[ind];
	            

	            ind -= ind & (-ind);
	        }

	        return sum;
	    }
	    
	    public long rsq(int a, int b) {
	        assert b >= a && a > 0 && b > 0;

	        return rsq(b) - rsq(a - 1);
	    }
	    
	    public void update(int ind, long value) {
	        assert ind > 0;
	        while (ind < array.length) {
	            array[ind] += value;
	            

	            ind += ind & (-ind);
	        }
	    }

	    public int size() {
	        return array.length - 1;
	    }
	}
	
	static class SegmentTree {

	    private Node[] heap;
	    private long[] array;
	    private int size;
	    
	    public SegmentTree(long[] array) {
	        this.array = Arrays.copyOf(array, array.length);
	        

	        size = (int) (2 * Math.pow(2.0, Math.floor((Math.log((double) array.length) / Math.log(2.0)) + 1)));
	        heap = new Node[size];
	        build(1, 0, array.length);
	    }

	    public int size() {
	        return array.length;
	    }

	    

	    private void build(int v, int from, int size) {
	        heap[v] = new Node();
	        heap[v].from = from;
	        heap[v].to = from + size - 1;

	        if (size == 1) {
	            heap[v].sum = array[from];
	            heap[v].min = array[from];
	            heap[v].max = array[from];
	        } else {
	            

	            build(2 * v, from, size / 2);
	            build(2 * v + 1, from + size / 2, size - size / 2);

	            heap[v].sum = heap[2 * v].sum + heap[2 * v + 1].sum;
	            

	            heap[v].min = Math.min(heap[2 * v].min, heap[2 * v + 1].min);
	            heap[v].max = Math.max(heap[2 * v].max, heap[2 * v + 1].max);
	        }
	    }

	    public long rsq(int from, int to) {
	        return rsq(1, from, to);
	    }

	    private long rsq(int v, int from, int to) {
	        Node n = heap[v];

	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return (to - from + 1) * n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].sum;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            long leftSum = rsq(2 * v, from, to);
	            long rightSum = rsq(2 * v + 1, from, to);

	            return leftSum + rightSum;
	        }

	        return 0;
	    }

	    public long rMinQ(int from, int to) {
	        return rMinQ(1, from, to);
	    }

	    private long rMinQ(int v, int from, int to) {
	        Node n = heap[v];


	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].min;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            long leftMin = rMinQ(2 * v, from, to);
	            long rightMin = rMinQ(2 * v + 1, from, to);

	            return Math.min(leftMin, rightMin);
	        }

	        return Integer.MAX_VALUE;
	    }
	    
	    public long rMaxQ(int from, int to) {
	        return rMaxQ(1, from, to);
	    }

	    private long rMaxQ(int v, int from, int to) {
	        Node n = heap[v];


	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].max;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            long leftMax = rMaxQ(2 * v, from, to);
	            long rightMax = rMaxQ(2 * v + 1, from, to);

	            return Math.max(leftMax, rightMax);
	        }

	        return Integer.MIN_VALUE;
	    }

	    public void update(int from, int to, long value) {
	        update(1, from, to, value);
	    }

	    private void update(int v, int from, int to, long value) {

	        

	        Node n = heap[v];

	        if (contains(from, to, n.from, n.to)) {
	            change(n, value);
	        }

	        if (n.size() == 1) return;

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);

	            update(2 * v, from, to, value);
	            update(2 * v + 1, from, to, value);

	            n.sum = heap[2 * v].sum + heap[2 * v + 1].sum;
	            n.min = Math.min(heap[2 * v].min, heap[2 * v + 1].min);
	            n.max = Math.max(heap[2 * v].max, heap[2 * v + 1].max);
	        }
	    }

	    

	    private void propagate(int v) {
	        Node n = heap[v];

	        if (n.pendingVal != null) {
	            change(heap[2 * v], n.pendingVal);
	            change(heap[2 * v + 1], n.pendingVal);
	            n.pendingVal = null; 

	        }
	    }

	    

	    private void change(Node n, long value) {
	        n.pendingVal = value;
	        n.sum = n.size() * value;
	        n.min = value;
	        n.max = value;
	        array[n.from] = value;
	    }

	    

	    private boolean contains(int from1, int to1, int from2, int to2) {
	        return from2 >= from1 && to2 <= to1;
	    }

	    

	    private boolean intersects(int from1, int to1, int from2, int to2) {
	        return from1 <= from2 && to1 >= from2   

	                || from1 >= from2 && from1 <= to2; 

	    }

	    

	    static class Node {
	        long sum;
	        long min;
	        long max;
	        

	        Long pendingVal = null;
	        int from;
	        int to;

	        int size() {
	            return to - from + 1;
	        }
	    }
	}
		
	@SuppressWarnings("serial")
	static class CountMap<T> extends TreeMap<T, Integer>{
		
		CountMap() {
		}
		
		CountMap(T[] arr) {
			this.putCM(arr);
		}
		
		public Integer putCM(T key) {
			return super.put(key, super.getOrDefault(key, 0) + 1);
		}
		
		public Integer removeCM(T key) {
			int count = super.getOrDefault(key, -1);
			if (count == -1) return -1;
			if (count == 1)
				return super.remove(key);
			else
				return super.put(key, count - 1);
		}
		
		public Integer getCM(T key) {
			return super.getOrDefault(key, 0);
		}
	
		public void putCM(T[] arr) {
			for (T l : arr)
				this.putCM(l);
		}
	}
	
	static long dioGCD(long a, long b, long[] x0, long[] y0) {
	    if (b == 0) {
	        x0[0] = 1;
	        y0[0] = 0;
	        return a;
	    }
	    long[] x1 = new long[1], y1 = new long[1];
	    long d = dioGCD(b, a % b, x1, y1);
	    x0[0] = y1[0];
	    y0[0] = x1[0] - y1[0] * (a / b);
	    return d;
	}

	static boolean diophantine(long a, long b, long c, long[] x0, long[] y0, long[] g) {
	    g[0] = dioGCD(Math.abs(a), Math.abs(b), x0, y0);
	    if (c % g[0] > 0) {
	        return false;
	    }

	    x0[0] *= c / g[0];
	    y0[0] *= c / g[0];
	    if (a < 0) x0[0] = -x0[0];
	    if (b < 0) y0[0] = -y0[0];
	    return true;
	}
	
	static long[][] prod(long[][] mat1, long[][] mat2) {
		int n = mat1.length;
		long[][] prod = new long[n][n];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				

				

				for (int k = 0; k < n; k++)
					prod[i][j] += mat1[i][k] * mat2[k][j];
		return prod;
	}
	static long[][] matExpo(long[][] mat, long power) {
		int n = mat.length;
		long[][] ans = new long[n][n];
		
		if (power == 0)
			return null;
		
		if (power == 1)
			return mat;
		
		long[][] half = matExpo(mat, power / 2);
		ans = prod(half, half);
		
		if (power % 2 == 1) {
			ans = prod(ans, mat);
		}
		
		return ans;
	}
	
	static int KMPNumOcc(char[] text, char[] pat) {
		int n = text.length;
		int m = pat.length;
		
		char[] patPlusText = new char[n + m + 1];
		for (int i = 0; i < m; i++)
			patPlusText[i] = pat[i];
		patPlusText[m] = '^'; 		

		for (int i = 0; i < n; i++)
			patPlusText[m + i] = text[i];
		
		int[] fullPi = piCalcKMP(patPlusText);
		int answer = 0;
		for (int i = 0; i < n + m + 1; i++)
			if (fullPi[i] == m)
				answer++;
		return answer;
	}
	static int[] piCalcKMP(char[] s) {
		int n = s.length;
		int[] pi = new int[n];
		for (int i = 1; i < n; i++) {
			int j = pi[i - 1];
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j])
				j++;
			pi[i] = j;
		}
		return pi;
	}
	static long hash(long key) {
        long h = Long.hashCode(key);
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (gigamod-1);
    }
	
	static int mapTo1D(int row, int col, int n, int m) {
		

		

		return row * m + col;
	}
	static int[] mapTo2D(int idx, int n, int m) {
		

		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
	}
	
	static boolean[] primeGenerator(int upto) {
		

		isPrime = new boolean[upto + 1];
		smallestFactorOf = new int[upto + 1];
		Arrays.fill(smallestFactorOf, 1);
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i < upto + 1; i++)
			if (isPrime[(int) i]) {
				smallestFactorOf[(int) i] = (int) i;
				

				

				for (long j = i; j * i < upto + 1; j++) {
					if (isPrime[(int) j * (int) i]) {
						isPrime[(int) j * (int) i] = false;
						smallestFactorOf[(int) j * (int) i] = (int) i;
					}
				}
			}
		return isPrime;
	}
	static HashMap<Integer, Integer> smolNumPrimeFactorization(int num) {
		if (smallestFactorOf == null)
			primeGenerator(num + 1);
		HashMap<Integer, Integer> fnps = new HashMap<>();
		while (num != 1) {
			fnps.put(smallestFactorOf[num], fnps.getOrDefault(smallestFactorOf[num], 0) + 1);
			num /= smallestFactorOf[num];
		}
		return fnps;
	}
	static HashMap<Long, Integer> primeFactorization(long num) {
		

		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer pwrCnt = map.get(2L);
			map.put(2L, pwrCnt != null ? pwrCnt + 1 : 1);
		}
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer pwrCnt = map.get(i);
				map.put(i, pwrCnt != null ? pwrCnt + 1 : 1);
			}
		}
		

		

		if (num != 1)
			map.put(num, 1);
		return map;
	}
	static HashSet<Long> divisors(long num) {
		HashSet<Long> divisors = new HashSet<Long>();
		divisors.add(1L);
		divisors.add(num);
		for (long i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				divisors.add(num/i);
				divisors.add(i);
			}
		}
		return divisors;
	}
	static void coprimeGenerator(int m, int n, ArrayList<Point> coprimes, int limit, int numCoprimes) {
		if (m > limit) return;
		if (m <= limit && n <= limit)
			coprimes.add(new Point(m, n));
		if (coprimes.size() > numCoprimes) return;
		coprimeGenerator(2 * m - n, m, coprimes, limit, numCoprimes);
		coprimeGenerator(2 * m + n, m, coprimes, limit, numCoprimes);
		coprimeGenerator(m + 2 * n, n, coprimes, limit, numCoprimes);
	}
	
	static int bsearch(int[] arr, int val, int lo, int hi) {
		

		

		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] >= val) {
				idx = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		return idx;
	}
	static int bsearch(long[] arr, long val, int lo, int hi) {
		

		

		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] >= val) {
				idx = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		return idx;
	}
	static int bsearch(long[] arr, long val, int lo, int hi, boolean sMode) {
		

		

		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] > val) {
				hi = mid - 1;
			} else {
				idx = mid;
				lo = mid + 1;
			}
		}
		return idx;
	}
	static int bsearch(int[] arr, long val, int lo, int hi, boolean sMode) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] > val) {
				hi = mid - 1;
			} else {
				idx = mid;
				lo = mid + 1;
			}
		}
		return idx;
	}
	
	static long nCr(long n, long r, long[] fac) { long p = gigamod; if (r == 0) return 1; return (fac[(int)n] * modInverse(fac[(int)r], p) % p * modInverse(fac[(int)n - (int)r], p) % p) % p; } 
	static long modInverse(long n, long p) { return power(n, p - 2, p); } 
	static long modDiv(long a, long b){return mod(a * power(b, gigamod - 2, gigamod));}
	static long power(long x, long y, long p) { long res = 1; x = x % p; while (y > 0) { if ((y & 1)==1) res = (res * x) % p; y = y >> 1; x = (x * x) % p; } return res; } 
	static int logk(long n, long k) { return (int)(Math.log(n) / Math.log(k)); }
	static long gcd(long a, long b) { if (b == 0) { return a; } else { return gcd(b, a % b); } } static int gcd(int a, int b) { if (b == 0) { return a; } else { return gcd(b, a % b); } } static long gcd(long[] arr) { int n = arr.length; long gcd = arr[0]; for (int i = 1; i < n; i++) { gcd = gcd(gcd, arr[i]); } return gcd; } static int gcd(int[] arr) { int n = arr.length; int gcd = arr[0]; for (int i = 1; i < n; i++) { gcd = gcd(gcd, arr[i]); } return gcd; } static long lcm(long[] arr) { long lcm = arr[0]; int n = arr.length; for (int i = 1; i < n; i++) { lcm = (lcm * arr[i]) / gcd(lcm, arr[i]); } return lcm; } static long lcm(long a, long b) { return (a * b)/gcd(a, b); } static boolean less(int a, int b) { return a < b ? true : false; } static boolean isSorted(int[] a) { for (int i = 1; i < a.length; i++) { if (less(a[i], a[i - 1])) return false; } return true; } static boolean isSorted(long[] a) { for (int i = 1; i < a.length; i++) { if (a[i] < a[i - 1]) return false; } return true; } static void swap(int[] a, int i, int j) { int temp = a[i]; a[i] = a[j]; a[j] = temp; } static void swap(long[] a, int i, int j) { long temp = a[i]; a[i] = a[j]; a[j] = temp; } static void swap(double[] a, int i, int j) { double temp = a[i]; a[i] = a[j]; a[j] = temp; } static void swap(char[] a, int i, int j) { char temp = a[i]; a[i] = a[j]; a[j] = temp; }
	static void sort(int[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void sort(char[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void sort(long[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void sort(double[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void reverseSort(int[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); } static void reverseSort(char[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); } static void reverse(char[] arr) { int n = arr.length; for (int i = 0; i < n / 2; i++) swap(arr, i, n - 1 - i); } static void reverseSort(long[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); } static void reverseSort(double[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); }
	static void shuffleArray(long[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { long tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } } static void shuffleArray(int[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { int tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } }
	static void shuffleArray(double[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { double tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } }
	static void shuffleArray(char[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { char tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } }
	static boolean isPrime(long n) {if (n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(long i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
	static String toString(int[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+" ");return sb.toString();}
	static String toString(boolean[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+" ");return sb.toString();}
	static String toString(long[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+" ");return sb.toString();}
	static String toString(char[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+"");return sb.toString();}
	static String toString(int[][] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++){for(int j=0;j<dp[i].length;j++){sb.append(dp[i][j]+" ");}sb.append('\n');}return sb.toString();}
	static String toString(long[][] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++){for(int j=0;j<dp[i].length;j++) {sb.append(dp[i][j]+" ");}sb.append('\n');}return sb.toString();}
	static String toString(double[][] dp){StringBuilder sb=new StringBuilder();for(int i = 0;i<dp.length;i++){for(int j = 0;j<dp[i].length;j++){sb.append(dp[i][j]+" ");}sb.append('\n');}return sb.toString();}
	static String toString(char[][] dp){StringBuilder sb = new StringBuilder();for(int i = 0;i<dp.length;i++){for(int j = 0;j<dp[i].length;j++){sb.append(dp[i][j]+"");}sb.append('\n');}return sb.toString();}
	static long mod(long a, long m){return(a%m+1000000L*m)%m;}
	static long mod(long num){return(num%gigamod+gigamod)%gigamod;}
}












