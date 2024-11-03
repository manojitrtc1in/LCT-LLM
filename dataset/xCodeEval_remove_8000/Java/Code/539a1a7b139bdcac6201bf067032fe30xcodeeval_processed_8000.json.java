import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;



public final class C {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int id34 = 1000000007;
	static int t = 1;
	static double epsilon = 0.00000001;
	static boolean[] isPrime;
	static int[] id25;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) throws Exception {
		t = fr.nextInt();
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			char[] s = fr.next().toCharArray();
			int n = s.length;
			
			int[] id32 = new int[n];
			if (s[0] == '1')
				id32[0] = 1;
			for (int i = 1; i < n; i++)
				id32[i] = id32[i - 1] + (s[i] == '1' ? 1 : 0);
			
			int[] id3 = new int[n];
			if (s[0] == '?')
				id3[0] = 1;
			for (int i = 1; i < n; i++)
				id3[i] = id3[i - 1] + (s[i] == '?' ? 1 : 0);
			
			int[] id17 = new int[n];
			for (int i = 0; i < n; i++)
				id17[i] = i + 1 - id32[i] - id3[i];
			
			

			

			

			

			

			

			

			
			int numPossible = 0;
			for (int idx = 0; idx < n; idx++) {
				
				

				

				
				int id40 = 0;
				if (idx > 0)
					id40 = id32[idx - 1];
				int id2 = id32[n - 1] - id40 - (s[idx] == '1' ? 1 : 0);
				
				int id36 = 0;
				if (idx > 0)
					id36 = id3[idx - 1];
				int id23 = id3[n - 1] - id36 - (s[idx] == '?' ? 1 : 0);
				
				int id38 = 0;
				if (idx > 0)
					id38 = id17[idx - 1];
				int id33 = id17[n - 1] - id38 - (s[idx] == '0' ? 1 : 0);
				
				
				if (id2 >= 1)
					continue;
				
				if (id38 >= 1)
					continue;
				
				numPossible++;
			}
			
			out.println(numPossible);
		}
		out.close();
	}
	
	static int diff(char[] s1, char[] s2) {
		int diff = 0;
		
		for (int i = 0; i < s1.length; i++)
			diff += Math.abs(s1[i] - s2[i]);
		
		return diff;
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
	    
	    public int id14(int node) {
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
	    	int[] id41 = new int[n];
	    	for (int i = 0; i < n; i++)
	    		id41[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> id24 = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int id37 = id41[i];
	    		Integer id8 = id24.get(id37);
	    		if (id8 == null)
	    			id8 = newCtr++;
	    		
	    		id24.put(id37, id8);
	    		id41[i] = id8;
	    	}
	    	
	    	return id41;
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
			int id39 = 0;
			for (int adjc : adj) {
				if (marked[adjc]) id39++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (id39 == adj.size())
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
			boolean[] id29 = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				id21(i, ug, marked, id29, -1);
			}
			return id29[0];
		}
		
		

		private static void id21(int current, UGraph ug, boolean[] marked, boolean[] id29, int parent) {
			if (marked[current]) return;
			if (id29[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id29[0] = true;
					return;
				}
				
				id21(adj, ug, marked, id29, current);
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
		
		public static int[] id18(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.id16(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					id20(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void id20(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) id20(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> id16(Digraph dg) {
			

			

			

			Stack<Integer> id6 = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					id1(dg, id6, marked, i);
			
			return id6;
		}
		
		static void id1(Digraph dg, Stack<Integer> id6, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					id1(dg, id6, marked, adjVertex);
			id6.add(source);
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

		int[] id15(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id42(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id47(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] id19(int n, int m) {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				char[] line = fr.next().toCharArray();
				for (int j = 0; j < m; j++)
					grid[i][j] = line[j] - 48;
			}
			return grid;
		}
	}
	
	static class LCA {
	    int[] height, first, id31;
	    ArrayList<Integer> euler;
	    boolean[] visited;
	    int n;

	    LCA(ArrayList<Point>[] outFrom, int root) {
	        n = outFrom.length;
	        height = new int[n];
	        first = new int[n];
	        euler = new ArrayList<>();
	        visited = new boolean[n];
	        dfs(outFrom, root, 0);
	        int m = euler.size();
	        id31 = new int[m * 4];
	        build(1, 0, m - 1);
	    }

	    void dfs(ArrayList<Point>[] outFrom, int node, int h) {
	        visited[node] = true;
	        height[node] = h;
	        first[node] = euler.size();
	        euler.add(node);
	        for (Point to : outFrom[node]) {
	            if (!visited[(int) to.x]) {
	                dfs(outFrom, (int) to.x, h + 1);
	                euler.add(node);
	            }
	        }
	    }

	    void build(int node, int b, int e) {
	        if (b == e) {
	            id31[node] = euler.get(b);
	        } else {
	            int mid = (b + e) / 2;
	            build(node << 1, b, mid);
	            build(node << 1 | 1, mid + 1, e);
	            int l = id31[node << 1], r = id31[node << 1 | 1];
	            id31[node] = (height[l] < height[r]) ? l : r;
	        }
	    }

	    int query(int node, int b, int e, int L, int R) {
	        if (b > R || e < L)
	            return -1;
	        if (b >= L && e <= R)
	            return id31[node];
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
	
	static class id43 {

	    long[] array; 


	    public id43(int size) {
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
	    private int[] array;
	    private int size;
	    
	    public SegmentTree(int[] array) {
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
	        } else {
	            

	            build(2 * v, from, size / 2);
	            build(2 * v + 1, from + size / 2, size - size / 2);

	            heap[v].sum = heap[2 * v].sum + heap[2 * v + 1].sum;
	            

	            heap[v].min = Math.min(heap[2 * v].min, heap[2 * v + 1].min);
	        }
	    }

	    public int rsq(int from, int to) {
	        return rsq(1, from, to);
	    }

	    private int rsq(int v, int from, int to) {
	        Node n = heap[v];

	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return (to - from + 1) * n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].sum;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            int leftSum = rsq(2 * v, from, to);
	            int rightSum = rsq(2 * v + 1, from, to);

	            return leftSum + rightSum;
	        }

	        return 0;
	    }

	    public int id11(int from, int to) {
	        return id11(1, from, to);
	    }

	    private int id11(int v, int from, int to) {
	        Node n = heap[v];


	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].min;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            int leftMin = id11(2 * v, from, to);
	            int rightMin = id11(2 * v + 1, from, to);

	            return Math.min(leftMin, rightMin);
	        }

	        return Integer.MAX_VALUE;
	    }

	    public void update(int from, int to, int value) {
	        update(1, from, to, value);
	    }

	    private void update(int v, int from, int to, int value) {

	        

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

	    

	    private void change(Node n, int value) {
	        n.pendingVal = value;
	        n.sum = n.size() * value;
	        n.min = value;
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
	        int sum;
	        int min;
	        

	        Integer pendingVal = null;
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
			if (super.containsKey(key)) {
				return super.put(key, super.get(key) + 1);
			} else {
				return super.put(key, 1);
			}
		}
		
		public Integer removeCM(T key) {
			Integer count = super.get(key);
			if (count == null) return -1;
			if (count == 1)
				return super.remove(key);
			else
				return super.put(key, super.get(key) - 1);
		}
		
		public Integer getCM(T key) {
			Integer count = super.get(key);
			if (count == null)
				return 0;
			return count;
		}
	
		public void putCM(T[] arr) {
			for (T l : arr)
				this.putCM(l);
		}
	}
	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		long id;
		
		Point() {
			x = y = id = 0;
		}
		
		Point(Point p) {
			this.x = p.x;
			this.y = p.y;
			this.id = p.id;
		}
		
		Point(long a, long b, long id) {
			this.x = a;
			this.y = b;
			this.id = id;
		}
		
		Point(long a, long b) {
			this.x = a;
			this.y = b;
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
		
		public boolean equals(Point that) {
			return this.compareTo(that) == 0;
		}
	}
	
	static int id45(char[] s) {
		int n = s.length;
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++)
			sb.append(s[i]);
		StringBuilder sb2 = new StringBuilder(sb);
		sb.append('^');
		sb.append(sb2.reverse());
		
		

		
		char[] newS = sb.toString().toCharArray();
		int m = newS.length;
		int[] pi = id26(newS);
		return pi[m - 1];
	}
	
	static int id44(char[] text, char[] pat) {
		int n = text.length;
		int m = pat.length;
		
		char[] id27 = new char[n + m + 1];
		for (int i = 0; i < m; i++)
			id27[i] = pat[i];
		id27[m] = '^'; 		

		for (int i = 0; i < n; i++)
			id27[m + i] = text[i];
		
		int[] fullPi = id26(id27);
		int answer = 0;
		for (int i = 0; i < n + m + 1; i++)
			if (fullPi[i] == m)
				answer++;
		return answer;
	}
	
	static int[] id26(char[] s) {
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
	
	static String id12(long num, int bits) {
		StringBuilder sb = new StringBuilder(Long.id12(num));
		sb.reverse();
		for (int i = sb.length(); i < bits; i++)
			sb.append('0');
		return sb.reverse().toString();
	}
	
	static long modDiv(long a, long b) {
		return mod(a * power(b, id34 - 2, id34));
	}
	
	static void id30(int m, int n, ArrayList<Point> id35, int limit, int id13) {
		
		if (m > limit) return;
		
		if (m <= limit && n <= limit)
			id35.add(new Point(m, n));
		
		if (id35.size() > id13) return;
		
		id30(2 * m - n, m, id35, limit, id13);
		id30(2 * m + n, m, id35, limit, id13);
		id30(m + 2 * n, n, id35, limit, id13);
	}
	
	static long hash(long i) {
		return (i * 2654435761L % id34);
	}

	static long hash2(long key) {
        long h = Long.hashCode(key);
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (id34-1);
    }
	
	static int id46(int row, int col, int n, int m) {
		

		

		return row * m + col;
	}
	
	static int[] id9(int idx, int n, int m) {
		

		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
	}
	
	static double distance(Point p1, Point p2) {
		return Math.sqrt(Math.pow(p2.y-p1.y, 2) + Math.pow(p2.x-p1.x, 2));
	}
	
	static HashMap<Integer, Integer> id22(int num) {
		
		if (id25 == null)
			primeGenerator(200001);
		
		CountMap<Integer> fnps = new CountMap<>();
		while (num != 1) {
			fnps.putCM(id25[num]);
			num /= id25[num];
		}
		return fnps;
	}
	
	static HashMap<Long, Integer> id10(long num) {
		

		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id7 = map.get(2L);
			map.put(2L, id7 != null ? id7 + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id7 = map.get(i);
				map.put(i, id7 != null ? id7 + 1 : 1);
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
			if (arr[mid] >= val) {
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
	
	static long id28(long a, long b) {
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
		long p = 998244353;
	    

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
		return id28(n, n - r);
	}
	
	static int logk(long n, long k) {
		return (int)(Math.log(n) / Math.log(k));
	}
	
	static boolean[] primeGenerator(int upto) {
		

		isPrime = new boolean[upto + 1];
		id25 = new int[upto + 1];
		Arrays.fill(id25, 1);
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i < upto + 1; i++)
			if (isPrime[(int) i]) {
				id25[(int) i] = (int) i;
				

				

				for (long j = i; j * i < upto + 1; j++) {
					if (isPrime[(int) j * (int) i]) {
						isPrime[(int) j * (int) i] = false;
						id25[(int) j * (int) i] = (int) i;
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
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static long mod(long a, long m) {
	    return (a%m + m) % m;
	}
	
	static long mod(long num) {
		return (num % id34 + id34) % id34;
	}
}












