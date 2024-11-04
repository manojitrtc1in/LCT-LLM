import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;



public final class CFPS {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int id15 = 1000000007;
	static int t = 1;
	public static void main(String[] args) {
		t= fr.nextInt();
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int n = fr.nextInt();
			Integer[] mines = new Integer[n];
			Integer[] miners = new Integer[n];
			int id13 = 0, minersCtr = 0;
			
			for (int i = 0; i < 2*n; i++) {
				int xi = fr.nextInt(), yi = fr.nextInt();
				if (xi == 0) {
					

					miners[minersCtr++] = yi;
				} else {
					mines[id13++] = xi;
				}
			}
			
			Arrays.sort(mines, new CoordComparator());
			Arrays.sort(miners, new CoordComparator());
			
			double cost = 0;
			for (int i = 0; i < n; i++) {
				cost += Math.sqrt(Math.pow((mines[i]) , 2) + Math.pow(miners[i] , 2));
			}
			
			out.println(cost);
		}
		out.close();
	}
	
	static double id8(int coord) {
		return Math.abs(coord);
	}
	
	static class CoordComparator implements Comparator<Integer> {
		@Override
		public int compare(Integer o1, Integer o2) {
			double id10 = id8(o1);
			double id4 = id8(o2);
			if (id10 > id4)
				return 1;
			if (id10 < id4)
				return -1;
			return 0;
		}
	}
	
	static String id7(int set) {
		

		

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 30; i++) {
			if (((set >> i) & 1) == 1) {
				

				

				sb.append((i + 1) + " ");
			}
		}
		sb.append("\n");
		return sb.toString();
	}
	
	static String id11(long set) {
		

		

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 60; i++) {
			if (((set >> i) & 1) == 1) {
				

				

				sb.append((i + 1) + " ");
			}
		}
		sb.append("\n");
		return sb.toString();
	}
	
	static int id2(int set, int element) {
		set = (set) | (1 << (element - 1));
		return set;
	}
	
	static int id5(int set, int element) {
		

		if ((set & (1 << (element - 1))) == 0) return set;
		set = set ^ (1 << (element - 1));
		return set;
	}
	
	

	static TreeMap<Long, Integer> id3(long num) {
		TreeMap<Long, Integer> map = new TreeMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id1 = map.get(2L);
			map.put(2L, id1 != null ? id1 + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id1 = map.get(i);
				map.put(i, id1 != null ? id1 + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	

	static TreeMap<Integer, Integer> id3(int num) {
		TreeMap<Integer, Integer> map = new TreeMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id1 = map.get(2);
			map.put(2, id1 != null ? id1 + 1 : 1);
		}
		
		for (int i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id1 = map.get(i);
				map.put(i, id1 != null ? id1 + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	
	static void dfs(int node, boolean[] marked, ArrayList<Integer>[] adj) {
		if (marked[node]) return;

		marked[node] = true;
		for (int adjc : adj[node])
			dfs(adjc, marked, adj);
	}

	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		int id;
		
		Point() {
			x = y = id = 0;
		}
		
		Point(long a, long b, int id) {
			this.x = a;
			this.y = b;
			this.id = id;
		}
		
		@Override
		public int compareTo(Point o) {
			if (this.x > o.x)
				return 1;
			if (this.x < o.x)
				return -1;
			if (this.y > o.y)
				return 1;
			if (this.y < o.y)
				return -1;
			return 0;
		}
	}
	
	static class PointComparator implements Comparator<Point> {
		@Override
		public int compare(Point o1, Point o2) {
			if (o1.y > o2.y)
				return 1;
			if (o1.y < o2.y)
				return -1;
			if (o1.x > o2.x)
				return 1;
			if (o1.x < o2.x)
				return -1;
			return 0;
		}
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
	
	static int factorial(int n) {
		if (n <= 1)
			return 1;
		return n * factorial(n - 1);
	}
	
	static long factorial(long n) {
		if (n <= 1)
			return 1;
		return n * factorial(n - 1);
	}
	
	static long id14(long a, long b) {
		if (a == b)
			return 1;
		return a * id14(a - 1, b);
	}
	
	static BigInteger id14(BigInteger a, BigInteger b) {
		if (a.equals(b))
			return BigInteger.ONE;
		return a.multiply(id14(a.subtract(BigInteger.ONE), b));
	}
	
	static long nCr(long n, long r) {
		return nPr(n, r) / factorial(r);
	}
	
	static long nPr(long n, long r) {
		return id14(n, n - r);
	}
	
	static int log2(long n) {
		return (int)(Math.log(n) / Math.log(2));
	}
	
	

	static boolean[] primeGenerator(int upto) {
		boolean[] isPrime = new boolean[upto + 1];
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i * i < upto + 1; i++)
			if (isPrime[(int) i])
				

				

				for (long j = i; j * i < upto + 1; j++)
					isPrime[(int) j * (int) i] = false;
		return isPrime;
	}

	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static int gcd(int[] arr) {
		int n = arr.length;
		int gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long gcd(long[] arr) {
		int n = arr.length;
		long gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long lcm(int[] arr) {
		int lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
	}
	
	static long lcm(long[] arr) {
		long lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
	}
	
	static long lcm(int a, int b) {
		return (a * b)/gcd(a, b);
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

	static void swap(int a, int b) {
		int temp = a;
		a = b;
		b = temp;
	}
	
	static void swap(long a, long b) {
		long temp = a;
		a = b;
		b = temp;
	}
	
	static void swap(double a, double b) {
		double temp = a;
		a = b;
		b = temp;
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

	
	private static void shuffleArray(char[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			char tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	

	static boolean isPrime(int n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i = i + 6)
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
	
	static char toChar(int i) {
		return (char) (i + 48);
	}
	
	static long mod (long a, long m) {
	    return (a%m + m) % m;
	}
	
	static long mod (long num) {
		return (num % id15 + id15) % id15;
	}
	
	

	static int hash(String s, int arrayLen) {
		return (s.hashCode() & 0x7fffffff) % arrayLen;
	}
	
	static int hash(Integer s, int arrayLen) {
		return (s.hashCode() & 0x7fffffff) % arrayLen;
	}
	
	static int hash(Long s, int arrayLen) {
		return (s.hashCode() & 0x7fffffff) % arrayLen;
	}
	
	static int hash(Double s, int arrayLen) {
		return (s.hashCode() & 0x7fffffff) % arrayLen;
	}
	
	

	static class UnionFind {
	    private static int[] parent;  

	    private static int[] size;    

	                           

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
	        int root = p;
	        while (root != parent[root])
	            root = parent[root];
	        while (p != root) {
	            int newp = parent[p];
	            parent[p] = root;
	            p = newp;
	        }
	        return root;
	    }

	    public boolean connected(int p, int q) {
	        return find(p) == find(q);
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
	}
	
	static class UGraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
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
		
		public Iterable<Integer> adj(int from) {
			return adj[from];
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
		
		public static void dfsMark(int source, boolean[] marked, UGraph g) {
			if (marked[source]) return;
			
			marked[source] = true;
			Iterable<Integer> adj = g.adj(source);
			for (int adjc : adj)
				dfsMark(adjc, marked, g);
		}
		
		public static void id0(int source, UGraph g) {
		}
		
		private static void dfsMark(int source, int[] colorIds, int color, UGraph g) {
			if (colorIds[source] != -1) return;
			
			colorIds[source] = color;
			Iterable<Integer> adj = g.adj(source);
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
	}
	
	static class Multiset{
		TreeMap<Long, Integer> ms;
		
		public Multiset() {
			ms = new TreeMap<>();
		}
		
		public void add(long x) {
			if(ms.containsKey(x)) ms.put(x, ms.get(x)+1);
			else ms.put(x, 1);
		}
		
		public void remove(long x) {
			ms.put(x, ms.get(x)-1);
			if(ms.get(x) == 0) ms.remove(x);
		}
		
		public int size() {
			return ms.size();
		}

		public boolean isEmpty() {
			return ms.isEmpty();
		}

		public boolean contains(long key) {
			return ms.containsKey(key);
		}

		public Object getCount(long key) {
			return ms.get(key);
		}

		public Iterable<Long> keySet() {
			return ms.keySet();
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

		int[] id6(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}
		
		int[] id12(int n) {
			int[] arr = new int[n + 1];
			for (int i = 1; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id16(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id17(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}

		public char[] id9(int n) {
			char[] chars = new char[n];
			for (int i = 0; i < n; i++)
				chars[i] = fr.nextChar();
			return chars;
		}
	}

}










