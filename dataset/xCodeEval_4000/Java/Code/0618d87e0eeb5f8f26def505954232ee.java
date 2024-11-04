import java.io.*;
import java.math.*;
import java.util.*;



public class Main {

	private static int dx[] = { -2, -3, -2, -1, -1, 1};
	private static int dy[] = { 1, -1, -1, -2, -3, -2};

	private static final long INF = (long) (1e15);
	private static final int INT_INF = Integer.MAX_VALUE;
	private static final long NEG_INF = Long.MIN_VALUE;
	private static final double EPSILON = 1e-10;

	private static final int MAX = 1007;
	private static final int MOD = 10007;
	
	private static final int MAXN = 100007;
	private static final int MAXA = 10000009;
	private static final int MAXLOG = 22;

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		


		int n = in.nextInt();
		
		List<Integer> adj[] = new ArrayList[n];
		for(int i = 0; i < n; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < n - 1; i++) {
			int u = in.nextInt();
			int v = in.nextInt();
			u--;
			v--;
			adj[u].add(v);
			adj[v].add(u);
		}

		
		boolean visited[] = new boolean[n];
		Arrays.fill(visited, false);
		int arr[] = bfs(1, n, adj, visited);
		


		
		Arrays.fill(visited, false);
		int root = arr[1];
		
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(root);
		visited[root] = true;
		
		int[] level = new int[n];
		int[] parent = new int[n];
		level[root] = 0;
		parent[root] = -1;
		
		int maxLevel = 0;
		int maxLevelNode = root;
		while(!queue.isEmpty()) {
			int u = queue.remove();
			for(int v : adj[u]) {
				if(!visited[v]) {
					visited[v] = true;
					queue.add(v);
					parent[v] = u;
					level[v] = level[u] + 1;
					if(level[v] > maxLevel) {
						maxLevel = level[v];
						maxLevelNode = v;
					}
				}
			}
		}


		
		int start = parent[maxLevelNode];
		Arrays.fill(visited, false);
		visited[maxLevelNode] = true;
		while(start != -1) {


			visited[start] = true;
			start = parent[start];
		}
		Point[] points = new Point[n];
		for(int i = 0; i < n; i++) {
			points[i] = new Point(0, i);
		}
		maxPoint.x = 0;
		maxPoint.y = parent[maxLevelNode];
		dfs(root, -1, adj, visited, points);
		








		out.println((maxLevel + maxPoint.x));
		out.println((root + 1) + " " + (maxLevelNode + 1) + " " + (maxPoint.y + 1));
		






























		
		
		out.flush();
		out.close();
		System.exit(0);
	}

	static Point maxPoint = new Point(0, 0);
	private static void dfs(int u, int parent, List<Integer>[] adj, boolean[] visited, Point[] points) {
		
		Point p = new Point(0, 0);
		for(int v : adj[u]) {
			if(v != parent) {
				dfs(v, u, adj, visited, points);
				if(!visited[v]) {
					if(p.x < points[v].x + 1) {
						p.x = points[v].x + 1;
						p.y = points[v].y;
					}
				}
			}
		}
		if(adj[u].size() == 1) {
			return;
		}
		
		points[u].x = p.x;
		points[u].y = p.y;
		if(points[u].x > maxPoint.x) {
			maxPoint.x = points[u].x;
			maxPoint.y = points[u].y;
		}
	}


	private static Point maxPoint(Point p1, Point p2) {
		

		return null;
	}


	private static int[] bfs(int root, int n, List<Integer>[] adj, boolean[] visited) {
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(root);
		visited[root] = true;
		
		int[] level = new int[n];
		level[root] = 0;
		int maxLevel = 0;
		int maxLevelNode = root;
		while(!queue.isEmpty()) {
			int u = queue.remove();
			for(int v : adj[u]) {
				if(!visited[v]) {
					visited[v] = true;
					queue.add(v);
					level[v] = level[u] + 1;
					if(level[v] > maxLevel) {
						maxLevel = level[v];
						maxLevelNode = v;
					}
				}
			}
		}


		int arr[] = {maxLevel, maxLevelNode};
		return arr;
	}


	static Map<Integer, Integer> primeFactorization(long n){
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for(int i = 2; i <= Math.sqrt(n); i++){
			if(n % i == 0){
			int count = 0;
			while(n % i == 0){
				count++;
				n = n / i;
			}
			map.put(i, count);


		}
			
		}
		if(n != 1) {


			map.put((int)n, 1);
		}
		return map;
	}

	private static class Pair<T>{
		T a;
		T b;
		Pair(T a, T b){
			this.a = a;
			this.b = b;
		}
	}
	
	private static class SegmentTree{
		int n;
		private final int MAXN = 100007;
		private long[] tree = new long[MAXN << 2];
		private long[] lazy = new long[MAXN << 2];
		private long[] arr = new long[MAXN];
		
		
		
		SegmentTree(int n, long[] arr){
			this.n = n;
			for(int i = 0; i < arr.length; i++) {
				this.arr[i] = arr[i];
			}
		}
		
		void build(int index, int left, int right) {
			if(left == right) {
				tree[index] = arr[left];
			}
			else {
				int mid = (left + right) / 2;
				
				build(index * 2, left, mid);
				build((index * 2) + 1, mid + 1, right);
				tree[index] = max(tree[(index * 2)], tree[(index * 2) + 1]);
			}
		}
		
		long query(int node, int left, int right, int start, int end) {
			
			if(left > end || right < start) {
				return NEG_INF;
			}
			
			if(left >= start && right <= end) {
				return tree[node];
			}
			int mid = (left + right) / 2;
			long val1 = query(2 * node, left, mid, start, end);
			long val2 = query(2 * node + 1, mid + 1, right, start, end);
			
			return max(val1, val2);
		}
		
		void update(int node, int left, int right, int idx, long val) {
			if(left == right) {
				tree[node] += val;
			}
			else {
				int mid = (left + right) / 2;
				if(idx <= mid) {
					update(2 * node, left, mid, idx, val);
				}
				else {
					update(2 * node + 1, mid + 1, right, idx, val);
				}
				tree[node] = max(tree[(2 * node) + 1], tree[(2 * node)]);
			}
		}
		
		

		 void updateRange(int node, int start, int end, int l, int r, long val)
		{
		    if(lazy[node] != 0)
		    { 
		        

		        tree[node] =  lazy[node];    

		        if(start != end)
		        {
		            lazy[node*2] = lazy[node];                  

		            lazy[node*2+1] = lazy[node];                

		        }
		        lazy[node] = 0;                                  

		    }
		    if(start > end || start > r || end < l)              

		        return;
		    if(start >= l && end <= r)
		    {
		        

		        tree[node] =  val;
		        if(start != end)
		        {
		            

		            lazy[node*2] = val;
		            lazy[node*2+1] = val;
		        }
		        return;
		    }
		    int mid = (start + end) / 2;
		    updateRange(node*2, start, mid, l, r, val);        

		    updateRange(node*2 + 1, mid + 1, end, l, r, val);   

		    tree[node] = max(tree[node*2], tree[node*2+1]);        

		}

		 long queryRange(int node, int start, int end, int l, int r)
		{
		    if(start > end || start > r || end < l)
		        return 0;         

		    if(lazy[node] != 0)
		    {
		        

		        tree[node] =  lazy[node];            

		        if(start != end)
		        {
		            lazy[node*2] = lazy[node];         

		            lazy[node*2+1] = lazy[node];    

		        }
		        lazy[node] = 0;                 

		    }
		    if(start >= l && end <= r)             

		        return tree[node];
		    int mid = (start + end) / 2;
		    long p1 = queryRange(node*2, start, mid, l, r);         

		    long p2 = queryRange(node*2 + 1, mid + 1, end, l, r); 

		    return max(p1, p2);
		}
		
		 void buildRange(int node, int low, int high){
			if(low == high){
				tree[node] =  arr[low];
				return;
			}
			
			int mid = (low + high) / 2;
			int left = node << 1;
			int right = left | 1;
			buildRange(left, low, mid);
			buildRange(right, mid + 1, high);
			tree[node] = max(tree[left], tree[right]);
		}
		
		
		void printSegmentTree() {
			System.out.println(Arrays.toString(tree));
		}
		
	}
	
	private static class KMP{
		
		private static char[] t;
		private static char[] s;
		
		public int kmp(char[]t, char[]s) {
			this.t = t;
			this.s = s;
			return this.kmp();
		}
		
		private int kmp() {
			
			List<Integer> prefixTable = getPrefixTable(s);
			
			int match = 0;
			int i = 0;
			int j = 0;
			
			int n = t.length;
			int m = s.length;
			while(i < n) {
				if(t[i] == s[j]) {
					if(j == m - 1) {
						match++;
						j = prefixTable.get(j - 1);
						continue;
					}
					i++;
					j++;
				}
				else if(j > 0) {
					j = prefixTable.get(j - 1);
				}
				else {
					i++;
				}
			}
			
			return match;
		}

		
		private List<Integer> getPrefixTable(char[] pattern){
			
			List<Integer> prefixTable = new ArrayList<Integer>();
			int n = pattern.length;
			for(int i = 0; i < n; i++) {
				prefixTable.add(0);
			}
			
			for(int i = 1; i < n; i++) {
				for(int j = prefixTable.get(i - 1); j >= 0;) {
					if(pattern[j] == pattern[i]) {
						prefixTable.set(i, j + 1);
						break;
					}
					else if(j > 0){
						j = prefixTable.get(j - 1);
					}
					else {
						break;
					}
				}
			}
			
			return prefixTable;
		}
	}
	


	private static class Point {
		int x;
		int y;
		Point(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		@Override
		public boolean equals(Object obj) {
			Point ob = (Point) obj;
			if(this.x == ob.x && this.y == ob.y){
				return true;
			}
			return false;
		}
		@Override
		public String toString() {
			return this.x + " " + this.y;
		}
	}

	private static long pow(int base, int pow) {
		long val = 1L;
		for(int i = 1; i <= pow; i++) {
			val *= base;
		}
		return val;
	}
	
	private static int log(int x, int base) {
		return (int) (Math.log(x) / Math.log(base));
	}
	private static int log(long x, int base) {
		return (int) (Math.log(x) / Math.log(base));
	}
	private static long max(long a, long b) {
		if (a >= b) {
			return a;
		}
		return b;
	}

	private static long abs(long a) {
		if (a < 0) {
			return -a;
		}
		return a;
	}

	private static int abs(int a) {
		if (a < 0) {
			return -a;
		}
		return a;
	}

	private static int max(int a, int b) {
		if (a >= b) {
			return a;
		}
		return b;
	}

	private static int min(int a, int b) {
		if (a <= b) {
			return a;
		}
		return b;
	}
	
	private static long min(long a, long b) {
		if (a <= b) {
			return a;
		}
		return b;
	}

	private static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	private static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	private static long bigMod(long n, long k, long m) {

		long ans = 1;
		while (k > 0) {
			if ((k & 1) == 1) {
				ans = (ans * n) % m;
			}
			n = (n * n) % m;
			k >>= 1;
		}
		return ans;
	}

	
	private static int lowerBoundNew(long[] arr, long num) {
		int start = 0;
		int end = arr.length - 1;
		int index = 0;
		int len = arr.length;
		int mid = 0;
		while (true) {
			if (start > end) {
				break;
			}
			mid = (start + end) / 2;
			if (arr[mid] > num) {
				end = mid - 1;
			} else if (arr[mid] < num) {
				start = mid + 1;
			} else {
				while (mid >= 0 && arr[mid] == num) {
					mid--;
				}
				return mid + 1;
			}
		}
		if (arr[mid] < num) {
			return mid + 1;
		}
		return mid;
	}

	
	private static int upperBoundNew(long[] arr, long num) {

		int start = 0;
		int end = arr.length - 1;
		int index = 0;
		int len = arr.length;
		int mid = 0;
		while (true) {
			if (start > end) {
				break;
			}
			mid = (start + end) / 2;
			if (arr[mid] > num) {
				end = mid - 1;
			} else if (arr[mid] < num) {
				start = mid + 1;
			} else {
				while (mid < len && arr[mid] == num) {
					mid++;
				}
				if (mid == len - 1 && arr[mid] == num) {
					return mid + 1;
				} else {
					return mid;
				}
			}
		}
		if (arr[mid] < num) {
			return mid + 1;
		}
		return mid;
	}

	private static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public String next() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());

				}
			} catch (IOException e) {
				return null;
			}
			return tokenizer.nextToken();
		}

		public String nextLine() {
			String line = null;
			try {
				tokenizer = null;
				line = reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			return line;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public boolean hasNext() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());
				}
			} catch (Exception e) {
				return false;
			}
			return true;
		}
	}
}