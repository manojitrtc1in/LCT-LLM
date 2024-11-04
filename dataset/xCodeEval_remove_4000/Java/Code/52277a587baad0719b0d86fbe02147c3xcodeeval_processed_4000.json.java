

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Random;

public class D {
	


	

	private static int n, m, p;
	private static int[] a, b;
	private static long ans;
	private static int[][] id, dp;
	private static int idf;
	private static String s, t;
	private static HashMap<Integer, ArrayList<Integer>> g;

	

	private static final int MOD = (int) 1e9 + 7;

	public static void main(String[] args) {
		int testCases = in.nextInt();

		long time1 = System.currentTimeMillis();
		


		
		for (int z = 1; z <= testCases; z++) {
			initCase(z);

			


			
			n = ini();
			p = ini();
			a = ina(n);






			
			PriorityQueue<int[]> edges = new PriorityQueue<>((p, q)->{
				return p[2]-q[2];
			});
			
			for(int i=0; i<n-1; i++) {
				edges.add(new int[] {i, i+1, p});
			}
			
			int[] left = new int[n];
			int[] right = new int[n];
			Deque<int[]> deque = new ArrayDeque<>();

			Arrays.fill(left, 1);
			




































































			






			
			




































































































			

			PriorityQueue<int[]> pq = new PriorityQueue<>((p, q)-> {
				return p[1]-q[1];
			});
			
			for(int i=0; i<n; i++) {
				pq.add(new int[] {i, a[i]});
			}
			
			
			

			
			DSU dsu = new DSU(n);
			
			int cc = n;
			long ans = 0;
			
			while(cc>1) {
				int[] node = pq.peek();
				int[] edge = (edges.size()>0?edges.peek():null);
				
				if (edge==null || (node!=null && node[1]<edge[2])) {
					int i = node[0];
					int j = i-1;
					while(j>=0) {
						if (a[j]%a[i]!=0) break;
						if (dsu.connected(i, j)) {
							j--;
							break;
						}
						dsu.union(i, j);
						ans += a[i];
						cc--;
						j--;
					}
					j = i+1;
					while(j<n) {
						if (a[j]%a[i]!=0) break;
						if (dsu.connected(i, j)) {
							j++;
							break;
						}
						dsu.union(i, j);
						ans += a[i];
						cc--;
						j++;
					}
					pq.poll();
					continue;
				}
				
				edge = edges.poll();
				int u = edge[0];
				int v = edge[1];
				int w = edge[2];
				
				if (dsu.connected(u, v)) continue;
				
				cc--;
				dsu.union(u, v);
				ans += w;
			}
			
			println(ans);
			
		}
		





		out.flush();
		out.close();

	}
	
	private static int[] randomArray(int n, int max) {
		int[] a = new int[n];
		Random rand = new Random();
		for(int i=0; i<n; i++) {
			a[i] = rand.nextInt(max)+1;
		}
		return a;
	}

	

	private static void initCase(int z) {
		idf = z;
		ans = 0;
	}

	

	private static void printAns(Object o) {
		out.println(o);
	}

	private static void printAns(Object o, int id1) {
		out.println("Case 
	}

	private static void printArray(Object[] a) {
		for (int i = 0; i < a.length; i++) {
			out.print(a[i] + " ");
		}
		out.println();
	}

	

	private static void sort(int[] a) {
		int n = a.length;
		Integer[] b = new Integer[n];
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}

		Arrays.sort(b);

		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
	}

	private static void sort(long[] a) {
		int n = a.length;
		Long[] b = new Long[n];
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}

		Arrays.sort(b);

		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
	}

	


	private static int[] ina(int n) {
		int[] temp = new int[n];
		for (int i = 0; i < n; i++) {
			temp[i] = in.nextInt();
		}
		return temp;
	}

	private static int[][] ina2d(int n, int m) {
		int[][] temp = new int[n][m];
		for (int i = 0; i < n; i++) {
			temp[i] = ina(m);
		}
		return temp;
	}

	private static int ini() {
		return in.nextInt();
	}

	private static long inl() {
		return in.nextLong();
	}

	private static double ind() {
		return Double.parseDouble(ins());
	}

	private static String ins() {
		return in.readString();
	}

	

	private static void println(Object... o) {
		for (Object x : o) {
			out.write(x + "");
		}
		out.write("\n");
	}

	private static void pd(Object... o) {
		for (Object x : o) {
			out.write(x + "");
		}
		out.flush();
		out.write("\n");
	}

	private static void print(Object... o) {
		for (Object x : o) {
			out.write(x + "");
		}
	}

	

	private static HashMap<Integer, ArrayList<Integer>> intree(int n) {

		HashMap<Integer, ArrayList<Integer>> g = new HashMap<>();
		for (int i = 0; i < n; i++) {
			g.put(i, new ArrayList<>());
		}

		for (int i = 0; i < n - 1; i++) {
			int u = ini() - 1;
			int v = ini() - 1;
			g.get(u).add(v);
			g.get(v).add(u);
		}

		return g;
	}

	private static HashMap<Integer, ArrayList<Integer>> ingraph(int n, int m) {
		HashMap<Integer, ArrayList<Integer>> g = new HashMap<>();

		for (int i = 0; i < n; i++) {
			g.put(i, new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			int u = ini() - 1;
			int v = ini() - 1;
			g.get(u).add(v);
			g.get(v).add(u);
		}

		return g;

	}

	private static HashMap<Integer, ArrayList<Integer>> id4(int n, int m) {
		HashMap<Integer, ArrayList<Integer>> g = new HashMap<>();

		for (int i = 0; i < n; i++) {
			g.put(i, new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			int u = ini() - 1;
			int v = ini() - 1;
			g.get(u).add(v);
		}

		return g;

	}

	private static HashMap<Integer, ArrayList<Edge>> id5(int n, int m) {
		HashMap<Integer, ArrayList<Edge>> g = new HashMap<>();

		for (int i = 0; i < n; i++) {
			g.put(i, new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			int u = ini() - 1;
			int v = ini() - 1;
			int w = ini();
			Edge edge = new Edge(u, v, w);
			g.get(u).add(edge);
			g.get(v).add(edge);
		}

		return g;

	}

	private static class Edge implements Comparable<Edge> {
		private int u, v;
		private long w;

		public Edge(int a, int b, long c) {
			u = a;
			v = b;
			w = c;
		}

		public int other(int x) {
			return (x == u ? v : u);
		}

		public int compareTo(Edge edge) {
			return Long.compare(w, edge.w);
		}
	}

	private static class Pair {
		private int u, v;

		public Pair(int a, int b) {
			u = a;
			v = b;
		}

		public int hashCode() {
			return u + v + u * v;
		}

		public boolean equals(Object object) {
			Pair pair = (Pair) object;
			return u == pair.u && v == pair.v;
		}
	}

	private static class Node implements Comparable<Node> {
		private int u;
		private long dist;

		public Node(int a, long b) {
			u = a;
			dist = b;
		}

		public int compareTo(Node node) {
			return Long.compare(dist, node.dist);
		}
	}

	

	private static int gcd(int a, int b) {
		

		if (b == 0)
			return a;

		return gcd(b, a % b);
	}

	private static long modExp(long a, long b) {
		if (b == 0)
			return 1;

		a %= MOD;

		long exp = modExp(a, b / 2);

		if (b % 2 == 0) {
			return (exp * exp) % MOD;
		} else {
			return (a * ((exp * exp) % MOD)) % MOD;
		}
	}

	private long mul(int a, int b) {
		return a * 1L * b;
	}

	

	private static class SegmentTree<T extends Comparable<T>> {
		private int n, m;
		private T[] a;
		private T[] seg;
		private T NULLVALUE;

		public SegmentTree(int n, T NULLVALUE) {
			this.NULLVALUE = NULLVALUE;
			this.n = n;
			m = 4 * n;
			seg = (T[]) new Object[m];

		}

		public SegmentTree(T[] a, int n, T NULLVALUE) {
			this.NULLVALUE = NULLVALUE;
			this.a = a;
			this.n = n;
			m = 4 * n;
			seg = (T[]) new Object[m];
			construct(0, n - 1, 0);
		}

		private void update(int pos) {
			

			


			

			if (seg[2 * pos + 1].compareTo(seg[2 * pos + 2]) <= 0) {
				seg[pos] = seg[2 * pos + 1];
			} else {
				seg[pos] = seg[2 * pos + 2];
			}
		}

		private T optimum(T leftValue, T rightValue) {
			

			


			

			if (leftValue.compareTo(rightValue) <= 0) {
				return leftValue;
			} else {
				return rightValue;
			}
		}

		public void construct(int low, int high, int pos) {
			if (low == high) {
				seg[pos] = a[low];
				return;
			}

			int mid = (low + high) / 2;

			construct(low, mid, 2 * pos + 1);
			construct(mid + 1, high, 2 * pos + 2);
			update(pos);
		}

		public void add(int index, T value) {
			add(index, value, 0, n - 1, 0);
		}

		private void add(int index, T value, int low, int high, int pos) {
			if (low == high) {
				seg[pos] = value;
				return;
			}

			int mid = (low + high) / 2;

			if (index <= mid) {
				add(index, value, low, mid, 2 * pos + 1);
			} else {
				add(index, value, mid + 1, high, 2 * pos + 2);
			}
			update(pos);
		}

		public T get(int qlow, int qhigh) {
			return get(qlow, qhigh, 0, n - 1, 0);
		}

		public T get(int qlow, int qhigh, int low, int high, int pos) {
			if (qlow > low || low > qhigh) {
				return NULLVALUE;
			} else if (qlow <= low || qhigh >= high) {
				return seg[pos];
			} else {
				int mid = (low + high) / 2;
				T leftValue = get(qlow, qhigh, low, mid, 2 * pos + 1);
				T rightValue = get(qlow, qhigh, mid + 1, high, 2 * pos + 2);

				return optimum(leftValue, rightValue);
			}
		}
	}

	

	private static class DSU {
		private int[] id;
		private int[] size;
		private int n;

		public DSU(int n) {
			this.n = n;

			id = new int[n];
			for (int i = 0; i < n; i++) {
				id[i] = i;
			}

			size = new int[n];
			Arrays.fill(size, 1);
		}

		private int root(int u) {
			while (u != id[u]) {
				id[u] = id[id[u]];
				u = id[u];
			}
			return u;
		}

		public boolean connected(int u, int v) {
			return root(u) == root(v);
		}

		public void union(int u, int v) {
			int p = root(u);
			int q = root(v);

			if (size[p] >= size[q]) {
				id[q] = p;
				size[p] += size[q];
			} else {
				id[p] = q;
				size[q] += size[p];
			}
		}
	}

	

	private static int countSearch(String s, String p) {
		int n = s.length();
		int m = p.length();

		int[] b = backTable(p);

		int j = 0;
		int count = 0;

		for (int i = 0; i < n; i++) {
			if (j == m) {
				j = b[j - 1];
				count++;
			}
			while (j != 0 && s.charAt(i) != p.charAt(j)) {
				j = b[j - 1];
			}
			if (s.charAt(i) == p.charAt(j)) {
				j++;
			}
		}

		if (j == m)
			count++;

		return count;
	}

	private static int[] backTable(String p) {
		int m = p.length();

		int j = 0;
		int[] b = new int[m];

		for (int i = 1; i < m; i++) {
			while (j != 0 && p.charAt(i) != p.charAt(j)) {
				j = b[j - 1];
			}
			if (p.charAt(i) == p.charAt(j)) {
				b[i] = ++j;
			}
		}
		return b;
	}

	

	private static InputReader in = new InputReader(System.in);
	private static PrintWriter out = new PrintWriter(System.out);

	private static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, id2;

		public InputReader(InputStream st) {
			this.stream = st;
		}

		public int read() {
			if (id2 == -1)
				throw new InputMismatchException();
			if (curChar >= id2) {
				curChar = 0;
				try {
					id2 = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (id2 <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = read();
			while (id0(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id0(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = read();
			while (id0(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id0(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (id0(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id0(c));
			return res.toString();
		}

		public String nextLine() {
			int c = read();
			while (id0(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id3(c));
			return res.toString();
		}

		public boolean id0(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean id3(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

	}
}


