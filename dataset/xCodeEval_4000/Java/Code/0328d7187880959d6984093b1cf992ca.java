import java.io.*;
import java.math.*;
import java.util.*;



public class Main {

	private static int dx[] = { 1, 0, -1, 0};
	private static int dy[] = { 0, -1, 0, 1};

	private static final long INF = (long) (1e15);
	private static final int INT_INF = Integer.MAX_VALUE;
	private static final long NEG_INF = Long.MIN_VALUE;
	private static final int NEG_INT_INF = Integer.MIN_VALUE;
	private static final double EPSILON = 1e-10;

	private static final int MAX = 1007;
	private static final long MOD = 1000000007;
	
	private static final int MAXN = 100007;
	private static final int MAXA = 10000009;
	private static final int MAXLOG = 22;

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		


		
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		
		int count = 0;
		List<String> list = new ArrayList<String>();


		int val = 0;
		for(int i = 0; i < m - 1; i++) {
			count++;
			val++;


			if(count == k) {
				list.add(val + " R");
				val = 0;
				break;
			}
		}
		if(count != k) {
			if(val > 0) {
				list.add(val + " R");
			}
			val = 0;
			for(int i = 0; i < m - 1; i++) {


				count++;
				val++;
				if(count == k) {
					list.add(val + " L");
					val = 0;
					break;
				}
			}
			if(count != k && val > 0) {
				list.add(val + " L");
				val = 0;
			}
		}
		
		if(count != k) {
			val = 0;
			for(int i = 1; i < n; i++) {
				if(count == k) {
					break;
				}
				count++;
				
				if(m == 1) {
					val++;
					continue;
				}
				
				list.add(1 + " D");
				val = 0;
				if(count == k) {
					break;
				}
				
				for(int j = 0; j < m - 1; j++) {
					count++;
					val++;
					if(count == k) {
						list.add(val + " R");
						val = 0;
						break;
					}
				}
				if(count != k) {
					if(val > 0) {
						list.add(val + " R");
					}
					val = 0;
					for(int j = 0; j < m - 1; j++) {
						count++;
						val++;
						if(count == k) {
							break;
						}
						count++;
						val++;
						if(count == k) {
							break;
						}
						count++;
						val++;
						if(count == k) {
							break;
						}
					}
					if(val > 0 && val % 3 == 0) {
						list.add((val/3) + " " + "UDL");
					}
					else if(val > 3) {
						list.add((val/3) + " " + "UDL");
						val = val % 3;
						if(val == 1) {
							list.add(1 + " " + "U");
						}
						else if(val == 2) {
							list.add(1 + " " + "UD");
						}
					}
					else if(val > 0) {
						if(val == 1) {
							list.add(1 + " " + "U");
						}
						else if(val == 2) {
							list.add(1 + " " + "UD");
						}
					}
					
				}
			}
		}
		if(m == 1 && val > 0) {
			list.add(val + " D");
		}
		if(count != k) {
			val = 0;
			for(int i = 0; i < n - 1; i++) {


				count++;
				val++;
				if(count == k) {
					break;
				}
			}
			if(val > 0) {
				list.add(val + " U");
			}
			
		}
		
		
		if(count != k) {
			System.out.println("NO");
		}
		else {
			System.out.println("YES");
			System.out.println(list.size());
			for(String str : list) {
				System.out.println(str);
			}
		}
		
	
		out.flush();
		out.close();
		System.exit(0);
	}
	
	
	private static class Graph{
		private int node;
		private List<Edge>[] adj;
		
		Graph(int node){
			this.node = node;
			adj = new ArrayList[this.node];
			for(int i = 0; i < node; i++) {
				adj[i] = new ArrayList<Main.Edge>();
			}
		}
		
		void addEdge(int u, int v, long cost) {
			Edge e = new Edge(u, v, cost);
			Edge e1 = new Edge(v, u, cost);
			adj[u].add(e);
			adj[v].add(e1);
		}
		
		long[] calculateShortestPath(int source) {
			
			long dist[] = new long[node];
			PriorityQueue<Node> queue = new PriorityQueue<Main.Node>(new Comparator<Node>() {

				@Override
				public int compare(Node o1, Node o2) {
					int val = Long.compare(o1.distance, o2.distance);
					return val;
					
				}
			});
			
			Arrays.fill(dist, INT_INF);
			
			queue.add(new Node(source, 0));
			dist[source] = 0;
			
			while(!queue.isEmpty()) {
				Node nn = queue.remove();
				int u = nn.node;
				long udist = nn.distance;
				if(udist > dist[u]) {
					continue;
				}
				for(Edge e : adj[u]) {
						int v = e.v;
						long vdist = e.cost;
						long arrive = udist + vdist;
						if(arrive < dist[v]) {
							dist[v] = arrive;
							queue.add(new Node(v, dist[v]));


						}
					
				}
				
			}
			return dist;
			
		}
	}
	
	private static class Node{
		int operation;
		int node;
		long distance;
		Node(int operation, int node, long distance){
			this.operation = operation;
			this.node = node;
			this.distance = distance;
		}
		
		Node(int node, long distance){
			this.node = node;
			this.distance = distance;
		}
	}
	
	private static class Edge{
		int u;
		int v;
		long cost;
		
		Edge(int u, int v, long cost){
			this.u = u;
			this.v = v;
			this.cost = cost;
		}
		
		int getNeighbourIndex(int node) {
			if(this.u == node) {
				return v;
			}
			return u;
		}
	}
	
	private static boolean isPalindrome(String str) {
		StringBuilder sb = new StringBuilder();
		sb.append(str);
		String str1 = sb.reverse().toString();
		return str.equals(str1);
 	}

	private static String reverseString(String str) {
		StringBuilder sb = new StringBuilder();
		sb.append(str);
		return sb.reverse().toString();
	}
	
	
	private static double distance(Point p1, Point p2) {
		long divx = p2.x - p1.x;
		long divy = p2.y - p1.y;
		divx = divx * divx;
		divy = divy * divy;
		return Math.sqrt(divx + divy);
	}
	
	private static String getBinaryStr(int n, int j) {
		String str = Integer.toBinaryString(n);
		int k = str.length();
		for(int i = 1; i <= j - k; i++) {
			str = "0" + str;
		}
		
		return str;
	}

	

	static long modInverse(long a, long m) {
		extendedEuclid(a, m);
		return (x % m + m) % m;
	}

	static long x;
	static long y;
	static long gcdx;

	private static void extendedEuclid(long a, long b) {
		if (b == 0) {
			gcdx = a;
			x = 1;
			y = 0;
		} else {
			extendedEuclid(b, a % b);
			long temp = x;
			x = y;
			y = temp - ((a / b) * y);
		}
	}
	
	private static void generatePrime(int n) {
		 

		boolean arr[] = new boolean[n + 5];
		Arrays.fill(arr, true);
		for(int i = 2; i * i <=n; i++){
			if(arr[i] == true){
				for(int j = i * i; j <= n; j+=i){
					arr[j] = false; 
				}
			}
		}
		int count = 0;
		int start = 0;
		for(int i = 2; i <= n; i++){
			if(arr[i] == true){


				count++;
			}
			if(count == (start * 100) + 1) {


				start++;
			}
		}
		System.out.println();
		System.out.println(count);
		
	}
	
	private static Map<Long, Long> primeFactorization(long n, long m){
		Map<Long, Long> map = new HashMap<>();
		
		for(long i = 2; i <= Math.sqrt(n); i++){
			if(n % i == 0){
			long count = 0;
			while(n % i == 0){
				count++;
				n = n / i;
			}
			long val = count * m;
			map.put(i, val);


		}
			
		}
		if(n != 1) {


			map.put(n, m);
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
		long x;
		long y;
		Point(long x, long y){
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
		
		@Override
		public int hashCode() {
		    return 0;
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

	
	private static int upperBoundNew(long arr[], long num) {

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
			long val = arr[mid];
			if (val > num) {
				end = mid - 1;
			} else if (val < num) {
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