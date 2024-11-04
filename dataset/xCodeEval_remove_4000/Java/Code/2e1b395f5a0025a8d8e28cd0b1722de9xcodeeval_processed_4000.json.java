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



public final class CFPS {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int id41 = 1000000007;
	static int t = 1;
	static double epsilon = 0.00000001;
	static boolean[] isPrime;
	static int[] id29;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) {
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int n = fr.nextInt();
			int[] arr = fr.id18(n);
			
			

			
			

			

			
			

			
			

			
			

			
			

			
			

			

			
			

			
			

			
			

			
			

			
			int[] id12 = new int[n];
			id12[0] = 1;
			for (int i = 1; i < n; i++)
				if (arr[i] > arr[i - 1])
					id12[i] = id12[i - 1] + 1;
				else
					id12[i] = 1;
			
			int[] id3 = new int[n];
			id3[n - 1] = 1;
			for (int i = n - 2; i > -1; i--)
				if (arr[i] > arr[i + 1])
					id3[i] = id3[i + 1] + 1;
				else
					id3[i] = 1;
			
			

			

			
			int id40 = Arrays.stream(id12).max().getAsInt();
			int id36 = Arrays.stream(id3).max().getAsInt();
			
			if (id40 != id36) {
				out.println(0);
				continue OUTER;
			}
			
			int cnt1 = (int) Arrays.stream(id12).filter(j -> j == id40).count();
			int cnt2 = (int) Arrays.stream(id3).filter(j -> j == id36).count();
			
			if (cnt1 > 1 || cnt2 > 1) {
				out.println(0);
				continue OUTER;
			}
			
			int id47 = -1, id50 = -1;
			for (int i = 0; i < n; i++)
				if (id12[i] == id40)
					id47 = i;
			for (int i = 0; i < n; i++)
				if (id3[i] == id36)
					id50 = i;
			
			if (id47 != id50) {
				out.println(0);
				continue OUTER;
			}
			
			if (id36 % 2 == 0) {
				out.println(0);
				continue OUTER;
			}
			
			out.println(1);
		}
		out.close();
	}
	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		long id;
		private int hashCode;
		
		Point() {
			x = y = id = 0;
			this.hashCode = Objects.hash(x, y, id);
		}
		
		Point(Point p) {
			this.x = p.x;
			this.y = p.y;
			this.id = p.id;
			this.hashCode = Objects.hash(x, y, id);
		}
		
		Point(long a, long b, long id) {
			this.x = a;
			this.y = b;
			this.id = id;
			this.hashCode = Objects.hash(x, y, id);
		}
		
		Point(long a, long b) {
			this.x = a;
			this.y = b;
			this.id = 0;
			this.hashCode = Objects.hash(a, b);
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
			return 0;
		}
		
		@Override
		public boolean equals(Object that) {
			return this.compareTo((Point) that) == 0;
		}
		
		
		@Override
		public int hashCode() {
			return this.hashCode;
		}
	}
	
	static class id31 {

	  

	  private final int n;

	  

	  

	  private Long[] t;

	  

	  

	  private Long[] lazy;

	  

	  private Long minFunction(Long a, Long b) {
	    if (a == null && b == null) return null;
	    if (a == null) return b;
	    if (b == null) return a;
	    return Math.min(a, b);
	  }

	  private Long sumFunction(Long a, Long b) {
	    if (a == null) a = 0L;
	    if (b == null) b = 0L;
	    return a + b;
	  }

	  private Long id6(long base, int tl, int tr, long x) {
	    return base + x;
	  }

	  public id31(long[] values) {
	    if (values == null) {
	      throw new IllegalArgumentException("Segment tree values cannot be null.");
	    }
	    n = values.length;

	    

	    

	    

	    

	    

	    int N = 4 * n;

	    t = new Long[N];
	    lazy = new Long[N];

	    id49(0, 0, n - 1, values);
	  }

	  
	  private void id49(int i, int tl, int tr, long[] values) {
	    if (tl == tr) {
	      t[i] = values[tl];
	      return;
	    }
	    int tm = (tl + tr) / 2;
	    id49(2 * i + 1, tl, tm, values);
	    id49(2 * i + 2, tm + 1, tr, values);

	    t[i] = Math.min(t[2 * i + 1], t[2 * i + 2]);
	  }

	  
	  public Long id13(int l, int r) {
	    return id13(0, 0, n - 1, l, r);
	  }

	  
	  private Long id13(int i, int tl, int tr, int l, int r) {
	    if (l > r) {
	      return null;
	    }
	    id32(i, tl, tr);
	    if (tl == l && tr == r) {
	      return t[i];
	    }
	    int tm = (tl + tr) / 2;
	    

	    

	    

	    return minFunction(
	        id13(2 * i + 1, tl, tm, l, Math.min(tm, r)),
	        id13(2 * i + 2, tm + 1, tr, Math.max(l, tm + 1), r));
	  }
	  
	  public void rangeAdd(int l, int r, long x) {
	    rangeAdd(0, 0, n - 1, l, r, x);
	  }

	  private void id21(int i, int tl, int tr, long delta) {
	    

	    if (tl == tr) return;
	    

	    lazy[2 * i + 1] = sumFunction(lazy[2 * i + 1], delta);
	    lazy[2 * i + 2] = sumFunction(lazy[2 * i + 2], delta);
	  }

	  private void id32(int i, int tl, int tr) {
	    

	    

	    if (lazy[i] != null) {
	      

	      t[i] = id6(t[i],  0,  0, lazy[i]);
	      

	      id21(i, tl, tr, lazy[i]);
	      lazy[i] = null;
	    }
	  }

	  private void rangeAdd(int i, int tl, int tr, int l, int r, long x) {
	    id32(i, tl, tr);
	    if (l > r) {
	      return;
	    }

	    if (tl == l && tr == r) {
	      t[i] = id6(t[i],  0,  0, x);
	      id21(i, tl, tr, x);
	    } else {
	      int tm = (tl + tr) / 2;
	      

	      

	      

	      rangeAdd(2 * i + 1, tl, tm, l, Math.min(tm, r), x);
	      rangeAdd(2 * i + 2, tm + 1, tr, Math.max(l, tm + 1), r, x);

	      t[i] = minFunction(t[2 * i + 1], t[2 * i + 2]);
	    }
	  }

	  public void id52() {
	    id52(0, 0, n - 1);
	    System.out.println();
	  }

	  private void id52(int i, int tl, int tr) {
	    System.out.printf("[%d, %d], t[i] = %d, lazy[i] = %d\n", tl, tr, t[i], lazy[i]);
	    if (tl == tr) {
	      return;
	    }
	    int tm = (tl + tr) / 2;
	    id52(2 * i + 1, tl, tm);
	    id52(2 * i + 2, tm + 1, tr);
	  }

	  

	  

	  

	}
	
	static class BinaryLift {
		int[] parentOf;
		int id17;
		int[][] id48;
		int n;
		int[] lvlOf;
		
		

		
		

		
		

		

		
		public BinaryLift(UGraph tree) {
			n = tree.V();
			id17 = logk(n, 2) + 1;
			parentOf = new int[n];
			id48 = new int[n][id17];
			lvlOf = new int[n];
			for (int i = 0; i < n; i++)
				Arrays.fill(id48[i], -1);
			parentConstruct(0, -1, tree, 0);
			binConstruct();
		}
		
		

		public BinaryLift(int[] parentOf) {
			this.parentOf = parentOf;
			n = parentOf.length;
			id17 = logk(n, 2) + 1;
			id48 = new int[n][id17];
			lvlOf = new int[n];
			for (int i = 0; i < n; i++)
				Arrays.fill(id48[i], -1);
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
				for (int lvl = 0; lvl < id17; lvl++)
					binConstruct(node, lvl);
		}
		
		private int binConstruct(int node, int lvl) {
			if (node < 0)
				return -1;
			if (lvl == 0)
				return id48[node][lvl] = parentOf[node];
			if (node == 0)
				return id48[node][lvl] = -1;
			
			if (id48[node][lvl] != -1)
				return id48[node][lvl];
			return id48[node][lvl] = binConstruct(binConstruct(node, lvl - 1), lvl - 1);
		}
		
		

		public int ancestor(int node, int k) {
			if (node < 0)
				return -1;
			if (node == 0)
				if (k == 0) return node;
				else return -1;
			if (k > (1 << id17) - 1)
				return -1;
			if (k == 0)
				return node;
			
			int ancestor = node;
			int highestBit = Integer.highestOneBit(k);
			
			while (k > 0 && ancestor != -1) {
				ancestor = id48[ancestor][logk(highestBit, 2)];
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
			
			

			for (int power = id17 - 1; power > -1; power--)
				if (id48[u][power] != id48[v][power]) {
					u = id48[u][power];
					v = id48[v][power];
				}
			
			return ancestor(u, 1);
		}
	}
	
	static class id30 {
		
		

		

		
		UGraph tree;
		UGraph backUG;
		int hasBridge;
		int n;
		
		
		id30(UGraph ug) {
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
	    
	    public int id16(int node) {
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
	    	int[] id45 = new int[n];
	    	for (int i = 0; i < n; i++)
	    		id45[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> id28 = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int id43 = id45[i];
	    		Integer id9 = id28.get(id43);
	    		if (id9 == null)
	    			id9 = newCtr++;
	    		
	    		id28.put(id43, id9);
	    		id45[i] = id9;
	    	}
	    	
	    	return id45;
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
			int id44 = 0;
			for (int adjc : adj) {
				if (marked[adjc]) id44++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (id44 == adj.size())
				endPoints.add(current);
		}
		
		public static void id4(int current, UGraph g) {
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
			boolean[] id37 = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				id25(i, ug, marked, id37, -1);
			}
			return id37[0];
		}
		
		

		private static void id25(int current, UGraph ug, boolean[] marked, boolean[] id37, int parent) {
			if (marked[current]) return;
			if (id37[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id37[0] = true;
					return;
				}
				
				id25(adj, ug, marked, id37, current);
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
		
		public static int[] id20(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.id19(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					id24(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void id24(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) id24(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> id19(Digraph dg) {
			

			

			

			Stack<Integer> id7 = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					id1(dg, id7, marked, i);
			
			return id7;
		}
		
		static void id1(Digraph dg, Stack<Integer> id7, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					id1(dg, id7, marked, adjVertex);
			id7.add(source);
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

		int[] id18(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id46(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id55(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] id23(int n, int m) {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					grid[i][j] = fr.nextInt();
			}
			return grid;
		}
	}
	
	static class LCA {
	    int[] height, first, id39;
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
	        id39 = new int[m * 4];
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
	            id39[node] = euler.get(b);
	        } else {
	            int mid = (b + e) / 2;
	            build(node << 1, b, mid);
	            build(node << 1 | 1, mid + 1, e);
	            int l = id39[node << 1], r = id39[node << 1 | 1];
	            id39[node] = (height[l] < height[r]) ? l : r;
	        }
	    }

	    int query(int node, int b, int e, int L, int R) {
	        if (b > R || e < L)
	            return -1;
	        if (b >= L && e <= R)
	            return id39[node];
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
	
	static class id51 {

	    long[] array; 


	    public id51(int size) {
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
	
	static final class id5 {
		

		

			

			private static final boolean RED = true;
			private static final boolean BLACK = false;

			

			private Node root;

			

			public id5() {
				root = null;
			}

			

			private class Node {
				long key;
				long value;
				Node left, right;
				boolean color;
				long size; 


				public Node(long key, long value, boolean color) {
					this.key = key;
					this.value = value;
					this.left = this.right = null;
					this.color = color;
					this.size = value;
				}
			}

			

			

			private Node flipColors(Node node) {
				node.left.color = node.right.color = BLACK;
				node.color = RED;
				return node;
			}

			

			private Node rotateLeft(Node node) {
				Node rn = node.right;
				node.right = rn.left;
				rn.left = node;
				rn.color = node.color;
				node.color = RED;
				return rn;
			}

			

			private Node rotateRight(Node node) {
				Node ln = node.left;
				node.left = ln.right;
				ln.right = node;
				ln.color = node.color;
				node.color = RED;
				return ln;
			}

			
			
			

			
			public void put(long key) {
				root = put(root, key);
				root.color = BLACK; 

			}

			private Node put(Node node, long key) {
				


				if (node == null)
					return new Node(key, 1, RED);

				

				int cmp = Long.compare(key, node.key);
				if (cmp < 0)
					node.left = put(node.left, key);
				else if (cmp > 0)
					node.right = put(node.right, key);
				else
					node.value++;

				

				if (node.left != null && node.right != null) {
					if (node.right.color = RED && node.left.color == BLACK)
						node = rotateLeft(node);
					if (node.left.color == RED && node.left.left.color == RED)
						node = rotateRight(node);
					if (node.left.color == RED && node.right.color == RED)
						node = flipColors(node);
				}

				

				node.size = node.value + size(node.left) + size(node.right);

				return node;
			}

			private long size(Node node) {
				if (node == null)
					return 0;
				else
					return node.size;
			}

			public long rank(long key) {
				return rank(root, key);
			}

			

			private long rank(Node node, long key) {
				if (node == null) return 0;
				int cmp = Long.compare(key, node.key);
				if (cmp < 0)
					return rank(node.left, key);
				else if (cmp > 0)
					return node.value + size(node.left) + rank(node.right, key);
				else
					return node.value + size(node.left);
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

	    public long id13(int from, int to) {
	        return id13(1, from, to);
	    }

	    private long id13(int v, int from, int to) {
	        Node n = heap[v];


	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].min;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            long leftMin = id13(2 * v, from, to);
	            long rightMin = id13(2 * v + 1, from, to);

	            return Math.min(leftMin, rightMin);
	        }

	        return Integer.MAX_VALUE;
	    }
	    
	    public long id2(int from, int to) {
	        return id2(1, from, to);
	    }

	    private long id2(int v, int from, int to) {
	        Node n = heap[v];


	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].max;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            long leftMax = id2(2 * v, from, to);
	            long rightMax = id2(2 * v + 1, from, to);

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
	static class CountMap<T> extends HashMap<T, Integer>{
		
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
	
	static long gcd(long a, long b, long[] x0, long[] y0) {
	    if (b == 0) {
	        x0[0] = 1;
	        y0[0] = 0;
	        return a;
	    }
	    long[] x1 = new long[1], y1 = new long[1];
	    long d = gcd(b, a % b, x1, y1);
	    x0[0] = y1[0];
	    y0[0] = x1[0] - y1[0] * (a / b);
	    return d;
	}

	static boolean id27(long a, long b, long c, long[] x0, long[] y0, long[] g) {
	    g[0] = gcd(Math.abs(a), Math.abs(b), x0, y0);
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
	
	static int id53(char[] s) {
		int n = s.length;
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++)
			sb.append(s[i]);
		StringBuilder sb2 = new StringBuilder(sb);
		sb.append('^');
		sb.append(sb2.reverse());
		
		

		
		char[] newS = sb.toString().toCharArray();
		int m = newS.length;
		int[] pi = id33(newS);
		return pi[m - 1];
	}
	
	static int id22(char[] text, char[] pat) {
		int n = text.length;
		int m = pat.length;
		
		char[] id34 = new char[n + m + 1];
		for (int i = 0; i < m; i++)
			id34[i] = pat[i];
		id34[m] = '^'; 		

		for (int i = 0; i < n; i++)
			id34[m + i] = text[i];
		
		int[] fullPi = id33(id34);
		int answer = 0;
		for (int i = 0; i < n + m + 1; i++)
			if (fullPi[i] == m)
				answer++;
		return answer;
	}
	
	static int[] id33(char[] s) {
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
	
	static String id14(long num, int bits) {
		StringBuilder sb = new StringBuilder(Long.id14(num));
		sb.reverse();
		for (int i = sb.length(); i < bits; i++)
			sb.append('0');
		return sb.reverse().toString();
	}
	
	static long modDiv(long a, long b) {
		return mod(a * power(b, id41 - 2, id41));
	}
	
	static void id38(int m, int n, ArrayList<Point> id42, int limit, int id15) {
		
		if (m > limit) return;
		
		if (m <= limit && n <= limit)
			id42.add(new Point(m, n));
		
		if (id42.size() > id15) return;
		
		id38(2 * m - n, m, id42, limit, id15);
		id38(2 * m + n, m, id42, limit, id15);
		id38(m + 2 * n, n, id42, limit, id15);
	}
	
	static long hash(long i) {
		return (i * 2654435761L % id41);
	}

	static long hash2(long key) {
        long h = Long.hashCode(key);
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (id41-1);
    }
	
	static int id54(int row, int col, int n, int m) {
		

		

		return row * m + col;
	}
	
	static int[] id10(int idx, int n, int m) {
		

		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
	}
	
	static double distance(Point p1, Point p2) {
		return Math.sqrt(Math.pow(p2.y-p1.y, 2) + Math.pow(p2.x-p1.x, 2));
	}
	
	static HashMap<Integer, Integer> id26(int num) {
		
		if (id29 == null)
			primeGenerator(1000001);
		
		HashMap<Integer, Integer> fnps = new HashMap<>();
		while (num != 1) {
			fnps.put(id29[num], fnps.getOrDefault(id29[num], 0) + 1);
			num /= id29[num];
		}
		return fnps;
	}
	
	static HashMap<Long, Integer> id11(long num) {
		

		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id8 = map.get(2L);
			map.put(2L, id8 != null ? id8 + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id8 = map.get(i);
				map.put(i, id8 != null ? id8 + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	static HashSet<Long> id0(long num) {
		HashSet<Long> id0 = new HashSet<Long>();
		id0.add(1L);
		id0.add(num);
		
		for (long i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				id0.add(num/i);
				id0.add(i);
			}
		}
		return id0;
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
		

		

		int idx = hi + 1;
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
	
	static long factorial(long n) {
		if (n <= 1)
			return 1;
		long factorial = 1;
		for (int i = 1; i <= n; i++)
			factorial = mod(factorial * i);
		return factorial;
	}
	
	static long id35(long a, long b) {
		if (a == b)
			return 1;
		if (b < a) {
			long temp = a;
			a = b;
			b = temp;
		}
		
		long factorial = 1;
		for (long i = a + 1; i <= b; i++)
			factorial = mod(factorial * i);
		return factorial;
	}
	
	static long nCr(long n, long r, long[] fac) {
		long p = id41;
	    

	    if (r == 0)
	        return 1;
	 
	    

	    

	    

	    
	 
	    return (fac[(int)n] * modInverse(fac[(int)r], p) % p
	                    * modInverse(fac[(int)n - (int)r], p) % p) % p;
	}
	
	static long modInverse(long n, long p) {
	    return power(n, p - 2, p);
	}
	
	static long power(long x, long y, long p) {
	    long res = 1; 

	 
	    x = x % p; 

	    

	 
	    while (y > 0) {
	        

	        if ((y & 1)==1)
	            res = (res * x) % p;
	 
	        

	        y = y >> 1; 

	        x = (x * x) % p;
	    }
	    return res;
	}
	
	static long nPr(long n, long r) {
		return id35(n, n - r);
	}
	
	static int logk(long n, long k) {
		return (int)(Math.log(n) / Math.log(k));
	}
	
	static boolean[] primeGenerator(int upto) {
		

		isPrime = new boolean[upto + 1];
		id29 = new int[upto + 1];
		Arrays.fill(id29, 1);
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i < upto + 1; i++)
			if (isPrime[(int) i]) {
				id29[(int) i] = (int) i;
				

				

				for (long j = i; j * i < upto + 1; j++) {
					if (isPrime[(int) j * (int) i]) {
						isPrime[(int) j * (int) i] = false;
						id29[(int) j * (int) i] = (int) i;
					}
				}
			}
		return isPrime;
	}
	
	static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static long gcd(long[] arr) {
		int n = arr.length;
		long gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static int gcd(int[] arr) {
		int n = arr.length;
		int gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long lcm(long[] arr) {
		long lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
	}
	
	static long lcm(long a, long b) {
		return (a * b)/gcd(a, b);
	}
	
	static boolean less(int a, int b) {
		return a < b ? true : false;
	}
	
	static boolean isSorted(int[] a) {
		for (int i = 1; i < a.length; i++) {
			if (less(a[i], a[i - 1]))
				return false;
		}
		return true;
	}
	
	static boolean isSorted(long[] a) {
		for (int i = 1; i < a.length; i++) {
			if (a[i] < a[i - 1])
				return false;
		}
		return true;
	}

	static void swap(int[] a, int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(long[] a, int i, int j) {
		long temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(double[] a, int i, int j) {
		double temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(char[] a, int i, int j) {
		char temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void sort(int[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(char[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(long[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(double[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void reverseSort(int[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(char[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverse(char[] arr) {
		int n = arr.length;
		for (int i = 0; i < n / 2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(long[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(double[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void shuffleArray(long[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			long tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static void shuffleArray(int[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			int tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static void shuffleArray(double[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			double tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static void shuffleArray(char[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			char tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static boolean isPrime(long n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (long i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	static String toString(int[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(boolean[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(long[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(char[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + "");
		return sb.toString();
	}
	
	static String toString(int[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(long[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(double[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(char[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + "");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static long mod(long a, long m) {
	    return (a%m + 1000000L * m) % m;
	}
	
	static long mod(long num) {
		return (num % id41 + id41) % id41;
	}
}












