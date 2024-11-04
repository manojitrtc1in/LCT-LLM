
import java.io.*;
import java.util.*;




public class Main {








































	private static Set<Integer> tree[];

	
	private static int MAXN = 300009; 
	private static int MAXA = 1000009;
	private static int BLOCK_SZ = 555;
	private static long answer = 0;
	private static int frequency[] = new int[MAXA];
	private static int arr[] = new int[MAXN];

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		

		int n = in.nextInt();
		int m = in.nextInt();
		
		List<Integer> adj[] = new ArrayList[n + 1];
		for(int i = 0; i <= n; i++){
			adj[i] = new ArrayList<Integer>();
		}
		int colors[] = new int[n + 1];
		for(int i = 1; i <= n; i++){
			colors[i] = in.nextInt();
		}
		for(int i = 0; i < n - 1; i++){
			int u = in.nextInt();
			int v = in.nextInt();
			
			adj[u].add(v);
			adj[v].add(u);
		}
		
		start = new int[n + 1];
		end = new int[n + 1];
		color = new int[n + 1];
		time = 0;
		dfs(1, 0, adj, colors);
		
		






		






		
		Node[] queries = new Node[m];
		for(int i = 0; i < m; i++){
			int u = in.nextInt();
			int k = in.nextInt();
			queries[i] = new Node(i, start[u], end[u], k);
		}
		
		Arrays.sort(queries);
		
		int ans[] = new int[m];
		
		int currentLeft = 1;
		int currentRight = 0;
		
		for(Node query : queries){
			int left = query.left;
			int right = query.right;
			
			while (currentRight < right) {
				add(color[currentRight + 1]);
				currentRight++;
			}
			
			while (currentRight > right) {
				remove(color[currentRight]);
				currentRight--;
			}
			
			while (currentLeft > left) {
				add(color[currentLeft - 1]);
				currentLeft--;
			}
			
			while (currentLeft < left) {
				remove(color[currentLeft]);
				currentLeft++;
			}
			
			

			ans[query.index] = frequency[query.k];
		}
	


		for(int i = 0; i < m; i++){
			out.println(ans[i]);
		}


		out.close();
		System.exit(0);
	}

	
	private static void dfs(int u, int p, List<Integer>[] adj, int[] colors) {
		start[u] = ++time;
		color[time] = colors[u];
		for(int v : adj[u]){
			if(v != p){
				dfs(v, u, adj, colors);
			}
		}
		end[u] = time;
	}


	static int start[];
	static int end[];
	static int time;
	static int color[];
	private static void add(int position) {

		frequency[++arr[position]]++;




















	}

	private static void remove(int position) {
		frequency[arr[position]--]--;
		


















	}

	private static class Node implements Comparable<Node> {
		int index;
		int left;
		int right;
		int k;

		Node(int index, int left, int right, int k) {
			this.index = index;
			this.left = left;
			this.right = right;
			this.k = k;
		}

		@Override
		public int compareTo(Node node2) {
			if (this.left / BLOCK_SZ != node2.left / BLOCK_SZ) {
				return (this.left / BLOCK_SZ) - (node2.left / BLOCK_SZ);
			}
			return this.right - node2.right;
		}

	}

	private static Set<Integer> query(int node, int start, int end, int left, int right) {

		if (start > right || end < left) {
			return new HashSet<>();
		}

		if (start >= left && end <= right) {
			return tree[node];
		}
		int mid = (start + end) / 2;

		query(2 * node, start, mid, left, right);
		query((2 * node) + 1, mid + 1, end, left, right);
		return null;
	}

	private static Set<Integer> combine(Set<Integer> set1, Set<Integer> set2) {
		Set<Integer> set = new HashSet<>();
		for (Integer e : set1) {
			set.add(e);
		}
		for (Integer e : set2) {
			set.add(e);
		}
		return set;
	}

	private static void id0(int node, int start, int end, int[] arr) {

		if (start == end) {
			

			tree[node].add(arr[start]);
			return;
		}
		int mid = (start + end) / 2;

		id0(2 * node, start, mid, arr);
		id0((2 * node) + 1, mid + 1, end, arr);
		

		tree[node].addAll(tree[2 * node]);
		tree[node].addAll(tree[(2 * node) + 1]);
	}

	private static void mergeSet(int node, Set<Integer> set1, Set<Integer> set2) {
		Set<Integer> tempSet = new HashSet<>();
		for (Integer e : set1) {
			tempSet.add(e);
		}
		for (Integer e : set2) {
			tempSet.add(e);
		}
		tree[node] = tempSet;
	}

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	private static class Pair {
		int first;
		String second;

		Pair(int first, String second) {
			this.first = first;
			this.second = second;
		}
	}

	private static class Point {
		int x;
		int y;

		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {

			return this.x + " " + this.y;
		}
	}

	private static int log(int x, int base)
	{
	    return (int) (Math.log(x) / Math.log(base));
	}
	
	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	


	private static double getDistance(double x1, double y1, double x2, double y2) {

		return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
	}

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	


	

	

	

	

	

	

	


	

	

	


	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	static class InputReader {
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
