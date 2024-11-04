import java.util.*;
import java.util.function.*;
import java.io.*;



public class RoundEdu134F {
	MyPrintWriter out;
	MyScanner in;









	final static String IMPOSSIBLE = "IMPOSSIBLE";
	final static String POSSIBLE = "POSSIBLE";
	final static String YES = "YES";
	final static String NO = "NO";

	private void initIO(boolean isFileIO) {
		if (System.getProperty("ONLINE_JUDGE") == null && isFileIO) {
			try {
				in = new MyScanner(new FileInputStream("input.txt"));
				out = new MyPrintWriter(new FileOutputStream("output.txt"));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		} else {
			in = new MyScanner(System.in);
			out = new MyPrintWriter(new BufferedOutputStream(System.out));
		}
	}

	public static void main(String[] args) {



		

		

		

		


		RoundEdu134F sol = new RoundEdu134F();
		sol.run();
	}

	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = false;

		initIO(isFileIO);

		int t = hasMultipleTests ? in.nextInt() : 1;

		for (int i = 1; i <= t; ++i) {
			if (isDebug) {
				out.printf("Test %d\n", i);
			}

			getInput();

			solve();
		}

		in.close();
		out.close();
	}

	

	int n1, n2, m, q;
	int[] x, y;
	Edge[][] neighbor1;
	Edge[][] neighbor2;


	class Edge {
		int other, index;
		public Edge(int other, int index) {
			this.other = other;
			this.index = index;
		}
		public String toString() {
			return String.format("%d %d", other, index);
		}
	}






	void getInput() {
		n1 = in.nextInt();
		n2 = in.nextInt();
		m = in.nextInt();
		q = in.nextInt();
		int[][] xy = in.nextTransposedMatrix(m, 2, -1);
		x = xy[0];
		y = xy[1];
		int[] deg1 = new int[n1];
		int[] deg2 = new int[n2];
		for (int u : x)
			deg1[u]++;
		for (int v : y)
			deg2[v]++;
		neighbor1 = new Edge[n1][];
		for (int u = 0; u < n1; u++)
			neighbor1[u] = new Edge[deg1[u]];
		neighbor2 = new Edge[n2][];
		for (int v = 0; v < n2; v++)
			neighbor2[v] = new Edge[deg2[v]];
		for (int i = 0; i < m; i++) {
			int u = x[i];
			int v = y[i];
			neighbor1[u][--deg1[u]] = new Edge(v, i);
			neighbor2[v][--deg2[v]] = new Edge(u, i);
		}














	}

	void answerDeleteQuery(ArrayList<Integer> us, ArrayList<Integer> vs) {
		out.println(us.size() + vs.size());
		for (int u : us) {
			out.print(u + 1);
			out.print(' ');
		}
		for (int v : vs) {
			out.print(-(v + 1));
			out.print(' ');
		}
		out.println();
		out.println(sumIndicesMatching + matching.size());
		out.println();
		out.flush();
	}

	void answerPrintQuery() {
		out.println(matching.size());
		for (int index : matching) {
			out.print(index + 1);
			out.print(' ');
		}
		out.println();
		out.println();
		out.flush();
	}

	boolean[] deleted1, deleted2;
	HashSet<Integer> matching;
	long sumIndicesMatching;
	void solve() {
		


		

		

		

		

		


		

		


		var bm = new BipartiteMatching();
		matching = bm.computeMatching();
		sumIndicesMatching = 0;
		for (int idx : matching)
			sumIndicesMatching += idx;





























































		HashSet<Integer> candidates1 = new HashSet<>();
		HashSet<Integer> candidates2 = new HashSet<>();
		bm.computeMinCut(candidates1, candidates2);

		var iter1 = candidates1.iterator();
		var iter2 = candidates2.iterator();

		for (int qq = 0; qq < q; qq++) {
			if (in.nextInt() == 1) {
				ArrayList<Integer> us = new ArrayList<>();
				ArrayList<Integer> vs = new ArrayList<>();
				if (iter1.hasNext()) {
					int u = iter1.next();
					us.add(u);
					int index = bm.match1To2[u].index;
					sumIndicesMatching -= index;
					matching.remove(index);
				} else {
					int v = iter2.next();
					vs.add(v);
					int index = bm.match2To1[v].index;
					sumIndicesMatching -= index;
					matching.remove(index);
				}
				answerDeleteQuery(us, vs);
			} else {
				answerPrintQuery();
			}
		}
	}

	

	class BipartiteMatching {
		final int SINK = n1;
		final Edge UNASSIGNED = new Edge(SINK, -1);
		Edge[] match1To2, match2To1;
		public BipartiteMatching() {
			match1To2 = new Edge[n1];
			match2To1 = new Edge[n2];
			Arrays.fill(match1To2, UNASSIGNED);
			Arrays.fill(match2To1, UNASSIGNED);
			level = new int[n1 + 1];
		}

		int[] level;
		public HashSet<Integer> computeMatching() {
			while (computeLayer())
				for (int u = 0; u < n1; u++)
					if (match1To2[u] == UNASSIGNED)
						dfs(u);

			HashSet<Integer> matching = new HashSet<>();
			for (int u = 0; u < n1; u++)
				if (match1To2[u] != UNASSIGNED)
					matching.add(match1To2[u].index);
			return matching;
		}

		

		public void computeMinCut(HashSet<Integer> vertices1, HashSet<Integer> vertices2) {
			

			

			

			


			boolean[] visited = new boolean[n1];
			ArrayDeque<Integer> queue = new ArrayDeque<>();
			for (int u = 0; u < n1; u++)
				if (match1To2[u] == UNASSIGNED)
					queue.add(u);

			while (!queue.isEmpty()) {
				int u = queue.pollFirst();
				if (visited[u])
					continue;
				visited[u] = true;
				for (Edge e : neighbor1[u]) {
					int v = e.other;
					vertices2.add(v);
					

					queue.add(match2To1[v].other);
				}
			}

			for (int u = 0; u < n1; u++)
				if (!visited[u])
					vertices1.add(u);
		}

		public boolean dfs(int u) {
			if (u == SINK)
				return true;
			for (Edge e : neighbor1[u]) {
				int v = e.other;
				int next = match2To1[v].other;
				if (level[next] == level[u] + 1) {
					if (dfs(next)) {
						match2To1[v] = new Edge(u, e.index);
						match1To2[u] = e;
						return true;
					}
				}
			}
			return false;
		}

		public boolean computeLayer() {
			ArrayDeque<Integer> queue = new ArrayDeque<>();
			for (int u = 0; u < n1; u++) {
				if (match1To2[u] == UNASSIGNED) {
					level[u] = 0;
					queue.add(u);
				} else {
					level[u] = Integer.MAX_VALUE;
				}
			}
			level[SINK] = Integer.MAX_VALUE;
			while (!queue.isEmpty()) {
				int u = queue.pollFirst();
				if (u == SINK)
					break;
				if (level[u] < level[SINK]) {
					for (Edge e : neighbor1[u]) {
						int v = e.other;
						int next = match2To1[v].other;
						if (level[next] == Integer.MAX_VALUE) {
							level[next] = level[u] + 1;
							queue.add(next);
						}
					}
				}
			}
			return level[SINK] != Integer.MAX_VALUE;
		}
	}






	static class Pair implements Comparable<Pair> {
		final static long FIXED_RANDOM = System.currentTimeMillis();
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}


		@Override
		public int hashCode() {
			

			long x = first;
			x <<= 32;
			x += second;
			x += FIXED_RANDOM;
			x += 0x9e3779b97f4a7c15l;
			x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9l;
			x = (x ^ (x >> 27)) * 0x94d049bb133111ebl;
			return (int)(x ^ (x >> 31));
		}
		@Override
		public boolean equals(Object obj) {












			Pair other = (Pair) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}


		@Override
		public int compareTo(Pair o) {
			int cmp = Integer.compare(first, o.first);
			return cmp != 0 ? cmp : Integer.compare(second, o.second);
		}
	}

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		

		public MyScanner(InputStream is, int bufferSize) {
			br = new BufferedReader(new InputStreamReader(is), bufferSize);
		}

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
			

			

		}

		public void close() {
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}

		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
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

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[][] nextMatrix(int n, int m) {
			return nextMatrix(n, m, 0);
		}

		int[][] nextMatrix(int n, int m, int offset) {
			int[][] mat = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					mat[i][j] = nextInt() + offset;
				}
			}
			return mat;
		}

		int[][] nextTransposedMatrix(int n, int m) {
			return nextTransposedMatrix(n, m, 0);
		}

		int[][] nextTransposedMatrix(int n, int m, int offset) {
			int[][] mat = new int[m][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					mat[j][i] = nextInt() + offset;
				}
			}
			return mat;
		}

		int[] nextIntArray(int len) {
			return nextIntArray(len, 0);
		}
		int[] nextIntArray(int len, int offset) {
			int[] a = new int[len];
			for (int j = 0; j < len; j++)
				a[j] = nextInt() + offset;
			return a;
		}

		long[] nextLongArray(int len) {
			return nextLongArray(len, 0);
		}
		long[] nextLongArray(int len, int offset) {
			long[] a = new long[len];
			for (int j = 0; j < len; j++)
				a[j] = nextLong() + offset;
			return a;
		}

		String[] nextStringArray(int len) {
			String[] s = new String[len];
			for (int i = 0; i < len; i++)
				s[i] = next();
			return s;
		}
	}

	public static class MyPrintWriter extends PrintWriter {
		public MyPrintWriter(OutputStream os) {
			super(os);
		}














		public void printlnAns(OptionalInt ans) {
			println(ans.orElse(-1));
		}

		public void printlnAns(long ans) {
			println(ans);
		}

		public void printlnAns(int ans) {
			println(ans);
		}

		public void printlnAns(boolean ans) {
			if (ans)
				println(YES);
			else
				println(NO);
		}

		public void printAns(long[] arr) {
			if (arr != null && arr.length > 0) {
				print(arr[0]);
				for (int i = 1; i < arr.length; i++) {
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void printlnAns(long[] arr) {
			printAns(arr);
			println();
		}

		public void printAns(int[] arr) {
			if (arr != null && arr.length > 0) {
				print(arr[0]);
				for (int i = 1; i < arr.length; i++) {
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void printlnAns(int[] arr) {
			printAns(arr);
			println();
		}

		public <T> void printAns(ArrayList<T> arr) {
			if (arr != null && arr.size() > 0) {
				print(arr.get(0));
				for (int i = 1; i < arr.size(); i++) {
					print(" ");
					print(arr.get(i));
				}
			}
		}
		public <T> void printlnAns(ArrayList<T> arr) {
			printAns(arr);
			println();
		}

		public void printAns(int[] arr, int add) {
			if (arr != null && arr.length > 0) {
				print(arr[0] + add);
				for (int i = 1; i < arr.length; i++) {
					print(" ");
					print(arr[i] + add);
				}
			}
		}
		public void printlnAns(int[] arr, int add) {
			printAns(arr, add);
			println();
		}

		public void printAns(ArrayList<Integer> arr, int add) {
			if (arr != null && arr.size() > 0) {
				print(arr.get(0) + add);
				for (int i = 1; i < arr.size(); i++) {
					print(" ");
					print(arr.get(i) + add);
				}
			}
		}

		public void printlnAns(ArrayList<Integer> arr, int add) {
			printAns(arr, add);
			println();
		}

		public void printlnAnsSplit(long[] arr, int split) {
			if (arr != null) {
				for (int i = 0; i < arr.length; i += split) {
					print(arr[i]);
					for (int j = i + 1; j < i + split; j++) {
						print(" ");
						print(arr[j]);
					}
					println();
				}
			}
		}

		public void printlnAnsSplit(int[] arr, int split) {
			if (arr != null) {
				for (int i = 0; i < arr.length; i += split) {
					print(arr[i]);
					for (int j = i + 1; j < i + split; j++) {
						print(" ");
						print(arr[j]);
					}
					println();
				}
			}
		}

		public <T> void printlnAnsSplit(ArrayList<T> arr, int split) {
			if (arr != null && !arr.isEmpty()) {
				for (int i = 0; i < arr.size(); i += split) {
					print(arr.get(i));
					for (int j = i + 1; j < i + split; j++) {
						print(" ");
						print(arr.get(j));
					}
					println();
				}
			}
		}
	}

	static private void permutateAndSort(long[] a) {
		int n = a.length;
		Random R = new Random(System.currentTimeMillis());
		for (int i = 0; i < n; i++) {
			int t = R.nextInt(n - i);
			long temp = a[n - 1 - i];
			a[n - 1 - i] = a[t];
			a[t] = temp;
		}
		Arrays.sort(a);
	}

	static private void permutateAndSort(int[] a) {
		int n = a.length;
		Random R = new Random(System.currentTimeMillis());
		for (int i = 0; i < n; i++) {
			int t = R.nextInt(n - i);
			int temp = a[n - 1 - i];
			a[n - 1 - i] = a[t];
			a[t] = temp;
		}
		Arrays.sort(a);
	}

	static private int[][] constructChildren(int n, int[] parent, int parentRoot) {
		int[][] childrens = new int[n][];

		int[] numChildren = new int[n];
		for (int i = 0; i < parent.length; i++) {
			if (parent[i] != parentRoot)
				numChildren[parent[i]]++;
		}

		for (int i = 0; i < n; i++) {
			childrens[i] = new int[numChildren[i]];
		}


		int[] idx = new int[n];
		for (int i = 0; i < parent.length; i++) {
			if (parent[i] != parentRoot)
				childrens[parent[i]][idx[parent[i]]++] = i;
		}

		return childrens;
	}

	static private int[][][] constructDirectedNeighborhood(int n, int[][] e) {
		int[] inDegree = new int[n];
		int[] outDegree = new int[n];
		for (int i = 0; i < e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outDegree[u]++;
			inDegree[v]++;
		}

		int[][] inNeighbors = new int[n][];
		int[][] outNeighbors = new int[n][];
		for (int i = 0; i < n; i++) {
			inNeighbors[i] = new int[inDegree[i]];
			outNeighbors[i] = new int[outDegree[i]];
		}

		for (int i = 0; i < e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outNeighbors[u][--outDegree[u]] = v;
			inNeighbors[v][--inDegree[v]] = u;
		}

		return new int[][][] {inNeighbors, outNeighbors};
	}

	static private int[][] constructNeighborhood(int n, int[][] e) {
		int[] degree = new int[n];
		for (int i = 0; i < e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			degree[u]++;
			degree[v]++;
		}

		int[][] neighbors = new int[n][];
		for (int i = 0; i < n; i++)
			neighbors[i] = new int[degree[i]];

		for (int i = 0; i < e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			neighbors[u][--degree[u]] = v;
			neighbors[v][--degree[v]] = u;
		}

		return neighbors;
	}

	static private void drawGraph(int[][] e) {
		makeDotUndirected(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
			.redirectOutput(new File("graph.png"))
			.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}

	}

	static private void makeDotUndirected(int[][] e) {
		MyPrintWriter out2 = null;
		try {
			out2 = new MyPrintWriter(new FileOutputStream("graph.dot"));
		} catch (FileNotFoundException e1) {
			

			e1.printStackTrace();
		}
		out2.println("strict graph {");
		for (int i = 0; i < e.length; i++) {
			out2.println(e[i][0] + "--" + e[i][1] + ";");
		}
		out2.println("}");
		out2.close();
	}

	static private void makeDotDirected(int[][] e) {
		MyPrintWriter out2 = null;
		try {
			out2 = new MyPrintWriter(new FileOutputStream("graph.dot"));
		} catch (FileNotFoundException e1) {
			

			e1.printStackTrace();
		}
		out2.println("strict digraph {");
		for (int i = 0; i < e.length; i++) {
			out2.println(e[i][0] + "->" + e[i][1] + ";");
		}
		out2.println("}");
		out2.close();
	}

}
