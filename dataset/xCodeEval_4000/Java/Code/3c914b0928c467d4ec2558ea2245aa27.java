
import java.io.*;
import java.util.*;




public class Main {








































	private static Set<Integer> tree[];

	
	private static int MAXN = 300009; 
	private static int MAXA = 1000009;
	private static int BLOCK_SZ = 555;
	private static long answer = 0;
	private static long frequency[] = new long[MAXA];
	private static int arr[] = new int[MAXN];

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);

		





			int n = in.nextInt();
			int m = in.nextInt();
			Node[] queries = new Node[m];
			long ans[] = new long[m];
			
			for(int i = 0; i < MAXN; i++){
				arr[i] = 0;
			}
			answer = 0;
			for(int i = 0; i < MAXA; i++){
				frequency[i] = 0;
			}
			for (int i = 0; i < n; i++) {
				arr[i] = in.nextInt();
			}
			

			

			

			

			
			for (int i = 0; i < m; i++) {
				int left = in.nextInt() - 1;
				int right = in.nextInt() - 1;
				queries[i] = new Node(i, left, right);
			}

			Arrays.sort(queries, new Comparator<Node>() {

				@Override
				public int compare(Node node1, Node node2) {
					if (node1.left / BLOCK_SZ != node2.left / BLOCK_SZ) {
						return (node1.left / BLOCK_SZ) - (node2.left / BLOCK_SZ);
					}
					return node1.right - node2.right;
				}
			});

			

			

			


			int currentLeft = 0;
			int currentRight = 0;

			for (int i = 0; i < m; i++) {
				int left = queries[i].left;
				int right = queries[i].right;
				while (currentLeft < left) {
					remove(currentLeft);
					currentLeft++;
				}
				while (currentLeft > left) {
					add(currentLeft - 1);
					currentLeft--;
				}
				while (currentRight <= right) {
					add(currentRight);
					currentRight++;
				}
				while (currentRight > right + 1) {
					remove(currentRight - 1);
					currentRight--;
				}
				

				ans[queries[i].index] = answer;
			}


			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < m; i++) {
				sb.append(ans[i] + "\n");
			}
			System.out.println(sb.toString());


		
		System.exit(0);
	}

	private static void add(int position) {

		frequency[arr[position]]++;
		
		long k = frequency[arr[position]];
		int s = arr[position];
		
		if (frequency[arr[position]] == 1) {
			answer += (k * k * s);
		}
		else{
			answer += s * ((2 * k) - 1);
		}
	}

	private static void remove(int position) {
		frequency[arr[position]]--;
		
		long k = frequency[arr[position]];
		long s = arr[position];
		
		if (frequency[arr[position]] == 0) {
			answer -= ((k + 1) * (k + 1) * s);
		}
		else{
			answer += s * (-1) * ((2 * k) + 1);
		}
	}

	private static class Node {
		int index;
		int left;
		int right;

		Node(int index, int left, int right) {
			this.index = index;
			this.left = left;
			this.right = right;
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

	private static void buildSegTree(int node, int start, int end, int[] arr) {

		if (start == end) {
			

			tree[node].add(arr[start]);
			return;
		}
		int mid = (start + end) / 2;

		buildSegTree(2 * node, start, mid, arr);
		buildSegTree((2 * node) + 1, mid + 1, end, arr);
		

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
