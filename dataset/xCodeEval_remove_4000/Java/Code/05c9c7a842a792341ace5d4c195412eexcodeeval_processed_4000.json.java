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
import java.util.TreeMap;



public final class Main {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int id19 = 1000000007;
	static int t = 1;
	static double epsilon = 0.00000001;
	static boolean[] isPrime;
	static int[] id14;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) {
		t = fr.nextInt();
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int n = fr.nextInt();
			long[] arr = fr.id25(n);
			
			

			
			

			

			
			sort(arr);
			
			long answer = 0;
			long id17 = arr[0];
			for (int i = 1; i < n; i++) {
				answer += arr[i] - arr[i - 1];
				answer -= (arr[i] * i - id17);
				id17 += arr[i];
			}
			
			out.println(answer);
		}
		out.close();
	}
	
	static int logk(long n, long k) {
		return (int)(Math.log(n) / Math.log(k));
	}
	
	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static HashMap<Integer, Integer> id12(int num) {
		
		if (id14 == null)
			primeGenerator(15000000);
		
		HashMap<Integer, Integer> fnps = new HashMap<>();
		while (num != 1) {
			fnps.put(id14[num], fnps.getOrDefault(id14[num], 0) + 1);
			num /= id14[num];
		}
		return fnps;
	}
	
	static HashMap<Long, Integer> id5(long num) {
		

		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id2 = map.get(2L);
			map.put(2L, id2 != null ? id2 + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id2 = map.get(i);
				map.put(i, id2 != null ? id2 + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	static boolean[] primeGenerator(int upto) {
		

		isPrime = new boolean[upto + 1];
		id14 = new int[upto + 1];
		Arrays.fill(id14, 1);
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i < upto + 1; i++)
			if (isPrime[(int) i]) {
				id14[(int) i] = (int) i;
				

				

				for (long j = i; j * i < upto + 1; j++) {
					if (isPrime[(int) j * (int) i]) {
						isPrime[(int) j * (int) i] = false;
						id14[(int) j * (int) i] = (int) i;
					}
				}
			}
		return isPrime;
	}
	
	static int id22(char[] text, char[] pat) {
		int n = text.length;
		int m = pat.length;
		
		char[] id16 = new char[n + m + 1];
		for (int i = 0; i < m; i++)
			id16[i] = pat[i];
		id16[m] = '^'; 		

		for (int i = 0; i < n; i++)
			id16[m + i] = text[i];
		
		int[] fullPi = id15(id16);
		int answer = 0;
		for (int i = 0; i < n + m + 1; i++)
			if (fullPi[i] == m)
				answer++;
		return answer;
	}
	
	static int[] id15(char[] s) {
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
	
	static void sort(long[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
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
	
	static class Point implements Comparable<Point> {
		long right;
		long idx;
		long id;
		
		Point() {
			right = idx = id = 0;
		}
		
		Point(Point p) {
			this.right = p.right;
			this.idx = p.idx;
			this.id = p.id;
		}
		
		Point(long a, long b, long id) {
			this.right = a;
			this.idx = b;
			this.id = id;
		}
		
		Point(long a, long b) {
			this.right = a;
			this.idx = b;
		}
		
		@Override
		public int compareTo(Point o) {
			if (this.right < o.right)
				return -1;
			if (this.right > o.right)
				return 1;
			if (this.idx < o.idx)
				return -1;
			if (this.idx > o.idx)
				return 1;
			return 0;
		}
		
		public boolean equals(Point that) {
			return this.compareTo(that) == 0;
		}
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
	
	static long[][] prod(long[][] mat1, long[][] mat2) {
		int n = mat1.length;
		long[][] prod = new long[n][n];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				

				

				for (int k = 0; k < n; k++)
					prod[i][j] = (prod[i][j] + mat1[i][k] * mat2[k][j]) % id19;
		return prod;
	}
	
	static class id23 {

		


	    long[] array; 


	    public id23(int size) {
	        array = new long[size + 1];
	    }
	    
	    public long rmq(int ind) {
	        assert ind > 0;
	        long max = 0;
	        while (ind > 0) {
	            max = Math.max(max, array[ind]);
	            

	            ind -= ind & (-ind);
	        }

	        return max;
	    }
	    
	    public void update(int ind, long value) {
	        assert ind > 0;
	        while (ind < array.length) {
	            array[ind] = Math.max(array[ind], value);
	            

	            ind += ind & (-ind);
	        }
	    }

	    public int size() {
	        return array.length - 1;
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
			int id20 = 0;
			for (int adjc : adj) {
				if (marked[adjc]) id20++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (id20 == adj.size())
				endPoints.add(current);
		}
		
		public static void id1(int current, UGraph g) {
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
			boolean[] id18 = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				id11(i, ug, marked, id18, -1);
			}
			return id18[0];
		}
		
		

		private static void id11(int current, UGraph ug, boolean[] marked, boolean[] id18, int parent) {
			if (marked[current]) return;
			if (id18[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id18[0] = true;
					return;
				}
				
				id11(adj, ug, marked, id18, current);
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
		
		public static int[] id8(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.id7(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					id10(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void id10(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) id10(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> id7(Digraph dg) {
			

			

			

			Stack<Integer> id3 = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					id0(dg, id3, marked, i);
			
			return id3;
		}
		
		static void id0(Digraph dg, Stack<Integer> id3, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					id0(dg, id3, marked, adjVertex);
			id3.add(source);
		}
	}
	
	static int id24(int row, int col, int n, int m) {
		

		

		return row * m + col;
	}
	
	static int[] id4(int idx, int n, int m) {
		

		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
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

		int[] id6(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id21(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id25(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] id9(int n, int m) {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					grid[i][j] = fr.nextInt();
			}
			return grid;
		}
		
		long[][] id13(int n, int m) {
			long[][] grid = new long[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					grid[i][j] = fr.nextInt();
			}
			return grid;
		}
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
}












