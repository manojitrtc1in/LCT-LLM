import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
import java.util.Set;







public class Main {
	public static void main(String[] args) throws Exception {

		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int h = sc.id20();
		int w = sc.id20();
		int k = sc.id20();
		
		
		Graph grid = new Graph(h*w);
		
		for(int i=0; i<h; i++) {
			for(int j=1; j<w; j++) {
				long w1 = sc.id13();
				grid.add2(getad(w, i, j-1), getad(w, i, j), w1);
			}
		}
		for(int i=1; i<h; i++) {
			for(int j=0; j<w; j++) {
				long w1 = sc.id13();
				grid.add2(getad(w, i-1, j), getad(w, i, j), w1);
			}
		}
		
		if(k%2 != 0) {
			int[][] anss = new int[h][w];
			fill(anss,-1);
			for(int i=0; i<h; i++) {
				id4(anss[i]);
			}
			
			return;
		}
		if((h*w) == 1) {
			System.out.println(-1);
			return;
		}
		
		long[][] mincos = new long[(k/2)+1][h*w];
		fill(mincos[0],0L);
		
		for(int t=1; t<=(k/2); t++) {
			fill(mincos[t], INFL);
			for(int i=0; i<h; i++) {
				for(int j=0; j<w; j++) {
					int ad = getad(w, i, j);
					for(Edge e: grid.get(ad)) {
						mincos[t][ad] = min(mincos[t][ad], mincos[t-1][e.v2]+e.w);
					}
				}
			}
		}
		
		
		for(int i=0; i<(h*w); i++) {
			mincos[k/2][i]*=2L;
		}
		for(int i=0; i<h; i++) {
			id4(Arrays.copyOfRange(mincos[k/2], i*w, i*w + w));
		}
		
		out.flush();
		return;
	}
	
	public static int getad(int w, int i, int j) {
		return (i*w + j);
	}

	static class Graph { 

		private ArrayList<Node> dt = new ArrayList<>();

		Graph(int sz) {
			for (int i = 0; i < sz; i++) {
				Node node1 = new Node();
				dt.add(node1);
			}
		}

		public void add(int v8, int id33, long w) {
			dt.get(v8).add(new Edge(v8, id33, w));
		}

		public void add2(int v1, int v2, long w) {
			dt.get(v1).add(new Edge(v1, v2, w));
			dt.get(v2).add(new Edge(v2, v1, w));
		}

		public Set<Edge> get(int v) {
			return dt.get(v).getAll();
		}

		public int size() {
			return dt.size();
		}

		public int sizeOf(int v) {
			return dt.get(v).size();
		}

		public void clear() {
			for (int i = 0; i < dt.size(); i++)
				dt.get(i).clear();
		}

		public void clear(int v) {
			dt.get(v).clear();
		}

		private void add_v(Node v_new) {
			dt.add(v_new);
		}

		public void show2() {
			for (int i = 0; i < dt.size(); i++) {
				System.out.print(i + ":");
				for (Edge e : dt.get(i).getAll())
					e.show2();
				System.out.println();
			}
		}

		public static Graph id27(int vn, int en, FastScanner sc) {
			Graph g = new Graph(vn);
			for (int i = 0; i < en; i++) {
				int s1 = sc.id20() - 1;
				int g1 = sc.id20() - 1;
				long w = sc.id13();
				g.add2(s1, g1, w);
			}
			return g;
		}

		public static Graph make_tree(int vn, FastScanner sc) {
			Graph g = new Graph(vn);
			for (int i = 1; i < vn; i++) {
				int s1 = sc.id20() - 1;
				int g1 = sc.id20() - 1;
				long w = sc.id13();
				g.add2(s1, g1, w);
			}
			return g;
		}
		

		private long[] dijkstra(int from) {
			PriorityQueue<Edge> dijk = new PriorityQueue<>(new id35());
			long[] id31 = new long[this.dt.size()];
			fill(id31, INFL);
			dijk.add(new Edge(from, 0L));

			while (!dijk.isEmpty()) {
				Edge dw = dijk.poll();
				if (id31[dw.v2] > dw.w) {
					id31[dw.v2] = dw.w;
					for (Edge e : this.get(dw.v2)) {
						long w2 = dw.w + e.w;
						if (id31[e.v2] > w2)
							dijk.add(new Edge(e.v2, w2));
					}
				}
			}
			return id31;
		}
	}

	static class Node { 

		private Set<Edge> next_vs = new HashSet<>();

		public void add(Edge id33) {
			next_vs.add(id33);
		}

		public Set<Edge> getAll() {
			return next_vs;
		}

		public int size() {
			return next_vs.size();
		}

		public void clear() {
			next_vs.clear();
		}

		public void addAll(Node id32) {
			this.next_vs.addAll(id32.next_vs);
		}
	}

	static class Edge { 

		int from = -1, v2 = -1;
		long w;

		public Edge(int going2, long weight_route) {
			this.v2 = going2;
			this.w = weight_route;
		}

		public Edge(int come8, int going2, long weight_route) {
			this.from = come8;
			this.v2 = going2;
			this.w = weight_route;
		}

		public void show2() {
			System.out.println(this.from + "->" + this.v2 + " :w=" + this.w);
		}
	}

	static class id35 implements Comparator<Edge> {
		

		public int compare(Edge a, Edge b) {
			if (a.w > b.w)
				return 1;
			else if (a.w < b.w)
				return -1;
			else
				return a.v2 - b.v2;
		}
	}

	private static final int INF = (int) 3e8;
	private static final long INFL = (long) 1e17;
	private static final int INTMAX = Integer.MAX_VALUE;
	private static final long LONGMAX = Long.MAX_VALUE;
	private static final long e97 = 1000000007L;
	private static final long e99 = 998244353L;
	private static final double PI = Math.PI;

	private static void assertion(boolean should_true) {
		

		if (!should_true)
			throw new AssertionError();
	}

	private static int abs(int a) {
		return (a >= 0) ? a : -a;
	}

	private static long abs(long a) {
		return (a >= 0L) ? a : -a;
	}

	private static double abs(double a) {
		return (a >= 0.0) ? a : -a;
	}

	private static int min(int a, int b) {
		return (a < b) ? a : b;
	}

	private static long min(long a, long b) {
		return (a < b) ? a : b;
	}

	private static double min(double a, double b) {
		return (a < b) ? a : b;
	}

	private static int max(int a, int b) {
		return (a > b) ? a : b;
	}

	private static long max(long a, long b) {
		return (a > b) ? a : b;
	}

	private static double max(double a, double b) {
		return (a > b) ? a : b;
	}

	private static int pow2(int id23) {
		if (id23 > 4e4)
			throw new IllegalArgumentException("Input is to Large. Use Long.");
		return id23 * id23;
	}

	private static long pow2(long id23) {
		if (id23 > 1e8)
			throw new IllegalArgumentException("Input is to Large. Use PowP.");
		return id23 * id23;
	}

	private static int pow(int id17, int index) {
		int ans = 1;
		for (int i = 0; i < index; i++) {
			if (ans >= (INTMAX / id17))
				throw new IllegalArgumentException("Input is to Large. Use Long.");
			ans *= id17;
		}
		return ans;
	}

	private static long pow(long id17, int index) {
		long ans = 1L;
		for (int i = 0; i < index; i++) {
			if (ans >= (LONGMAX / id17))
				throw new IllegalArgumentException("Input is to Large. Use PowP.");
			ans *= id17;
		}
		return ans;
	}

	private static long powP(long id17, long index, long p) {
		

		

		if (id17 == 0L)
			return 0L;
		if (index == 0L)
			return 1L;
		if (index == 2L) {
			return (pow2(id17) % p);
		}

		int d = id0(index);
		long[] id25 = new long[d + 1];
		id25[0] = id17;
		for (int i = 1; i <= d; i++) {
			id25[i] = id25[i - 1] * id25[i - 1];
			id25[i] %= p;
		}
		long ans = 1L;
		for (int i = d; i >= 0; i--) {
			long cf = (1L << (long) i);
			if (index >= cf) {
				index -= cf;
				ans = ans * id25[i];
				ans %= p;
			}
		}
		return ans;
	}

	private static double hypod(double a, double b) {
		return Math.sqrt(a * a + b * b);
	}

	private static int id0(long id9) {
		

		long compare4 = 1L;
		int digit = 0;
		while (id9 >= compare4) {
			digit++;
			compare4 = (1L << (long) digit);
		}
		return digit;
		

	}

	private static int id15(long id9) {
		

		long compare4 = 1L;
		int digit = 0;
		while (id9 >= compare4) {
			digit++;
			compare4 *= 10L;
		}
		return digit; 


	}

	private static int divceil(int numerator, int denominator) {
		return (numerator + denominator - 1) / denominator;
	}

	private static long divceil(long numerator, long denominator) {
		return (numerator + denominator - 1L) / denominator;
	}

	private static long factorial(int n) {
		

		long ans = 1L;
		for (long i = 2; i <= n; i++) {
			if (ans >= (LONGMAX / i))
				throw new IllegalArgumentException("Input is to Large. Use facP.");
			ans *= i;
		}
		return ans;
	}

	private static long facP(int n, long p) {
		

		long ans = 1L;
		for (long i = 2; i <= n; i++) {
			ans *= i;
			ans %= p;
		}
		return ans;
	}

	private static long lcm(long m, long n) {
		long ans = m / gcd(m, n);
		if (ans >= (LONGMAX / n))
			throw new IllegalArgumentException("Input is to Large.");
		ans *= n;
		return ans;
	}

	private static long gcd(long m, long n) {
		

		if ((m <= 0L) || (n <= 0L))
			throw new IllegalArgumentException("m and n should be natural.");

		while ((m > 0L) && (n > 0L)) {
			if (m >= n)
				m %= n;
			else
				n %= m;
		}
		if (m > 0L)
			return m;
		else
			return n;
	}

	private static boolean is_prime(long id3) {
		

		if (id3 == 1L)
			return false;
		for (long i = 2L; i <= Math.sqrt(id3); i++) {
			if (id3 % i == 0L)
				return false;
		}
		return true;
	}

	private static int safe_mod(int n, int p) {
		n %= p;
		if (n >= 0)
			return n;
		return (n + p);
	}

	private static long safe_mod(long n, long p) {
		n %= p;
		if (n >= 0L)
			return n;
		return (n + p);
	}

	private static long modinv(long n, long p) {
		

		

		

		


		n %= p;
		if ((p == 1L) || (gcd(n, p) != 1L))
			throw new IllegalArgumentException("n and p should be coprime.");

		

		

		

		

		

		


		long a = p, b = n, s = 1L, t = 0L, u = 0L, v = 1L;
		while (b > 1) {
			long quo = a / b, rem = a % b;
			a = b;
			b = rem;
			long s2 = s * quo + u, t2 = t * quo + v;
			u = s;
			v = t;
			s = s2;
			t = t2;
		}
		long det = s * v - t * u;
		if (abs(det) != 1L)
			throw new ArithmeticException("My algorithm was Wrong!!");
		s /= det;
		s %= p;
		if (s < 0L)
			s += p;
		return s;
	}

	private static int minAll(int[] id22) {
		

		int min = INF;
		for (int element : id22) {
			if (element < min)
				min = element;
		}
		return min;
	}

	private static long minAll(long[] id22) {
		

		long min = INFL;
		for (long element : id22) {
			if (element < min)
				min = element;
		}
		return min;
	}

	private static int maxAll(int[] id2) {
		

		int max = -INF;
		for (int element : id2) {
			if (element > max)
				max = element;
		}
		return max;
	}

	private static long maxAll(long[] id2) {
		

		long max = -INFL;
		for (long element : id2) {
			if (element > max)
				max = element;
		}
		return max;
	}

	private static int sumAll(int[] id18) {
		

		int id10 = 0;
		for (int element : id18) {
			if (id10 > (INTMAX - element))
				throw new IllegalArgumentException("Input is to Large. Use Long.");
			id10 += element;
		}
		return id10;
	}

	private static long sumAll(long[] id18) {
		

		long id10 = 0L;
		for (long element : id18) {
			if (id10 > (LONGMAX - element))
				throw new IllegalArgumentException("Input is to Large.");
			id10 += element;
		}
		return id10;
	}

	private static int sumAll(ArrayList<Integer> id18) {
		int id10 = 0;
		for (long element : id18) {
			if (id10 > (INTMAX - element))
				throw new IllegalArgumentException("Input is to Large. Use Long.");
			id10 += element;
		}
		return id10;
	}

	private static int[] reverse(int[] as) {
		int ln = as.length;
		int[] bs = new int[ln];
		for (int i = 0; i < ln; i++)
			bs[i] = as[ln - i - 1];
		return bs;
	}

	private static void reverseSub(int[] as, int S_include, int id28) {
		

		int ln = id28 - S_include;

		int[] bs = new int[ln];
		for (int i = S_include; i < id28; i++)
			bs[i - S_include] = as[i];
		for (int i = 0; i < ln; i++)
			as[i + S_include] = bs[ln - i - 1];
	}

	private static boolean id7(int y, int x, int height, int width) {
		if (y < 0)
			return false;
		if (x < 0)
			return false;
		if (y >= height)
			return false;
		if (x >= width)
			return false;
		return true;
	}

	private static boolean id7(Vector v, int height, int width) {
		if (v.y < 0)
			return false;
		if (v.x < 0)
			return false;
		if (v.y >= height)
			return false;
		if (v.x >= width)
			return false;
		return true;
	}

	private static int id30(int n) {
		return ((n * (n - 1)) / 2);
	}

	private static long id30(long n) {
		return ((n * (n - 1L)) / 2L);
	}

	private static int iflag(int pos) {
		if (pos >= 32)
			throw new IllegalArgumentException("Input is to Large. Use Long.");
		return (1 << pos);
	}

	private static long flag(int pos) {
		if (pos >= 64)
			throw new IllegalArgumentException("Input is to Large. Use Long.");
		return (1L << (long) pos);
	}

	private static boolean id19(int bit, int pos) {
		if (pos >= 32)
			throw new IllegalArgumentException("Input is to Large.");
		return ((bit & (1 << pos)) != 0);
	}

	private static boolean id19(long bit, int pos) {
		if (pos >= 64)
			throw new IllegalArgumentException("Input is to Large.");
		return ((bit & (1L << (long) pos)) != 0L);
	}

	private static int deflag(int bit, int pos) {
		return (bit & (~(1 << pos)));
	}

	private static int id16(int bit) {
		int ans = 0;
		for (int i = 0; i < 31; i++) {
			if ((bit & (1 << i)) != 0)
				ans++;
		}
		return ans;
	}

	private static int id16(long bit) {
		int ans = 0;
		for (long i = 0L; i < 63L; i++) {
			if ((bit & (1L << i)) != 0L)
				ans++;
		}
		return ans;
	}

	private static int[] id8 = { 1, 0, 0, -1 };
	private static int[] id11 = { 0, 1, -1, 0 };
	private static int[] id6 = { 1, 1, 1, 0, 0, -1, -1, -1 };
	private static int[] id29 = { 1, 0, -1, 1, -1, 1, 0, -1 };

	public static int biSearch(int[] dt, int target) {
		

		

		

		int left = 0, right = dt.length - 1;
		int mid = -1;
		while (left <= right) {
			mid = ((right + left) / 2);
			if (dt[mid] == target)
				return mid;
			if (dt[mid] < target)
				left = (mid + 1);
			else
				right = (mid - 1);
		}
		return -1;
	}

	public static int id1(long[] dt, long target) {
		

		

		int left = -1, right = dt.length, mid = -1;
		while ((right - left) > 1) {
			mid = ((right + left) / 2);
			if (dt[mid] <= target)
				left = mid;
			else
				right = mid;
		}
		return left;
		

	}

	public static int id21(long[] dt, long target) {
		

		

		int left = -1, right = dt.length, mid = -1;
		while ((right - left) > 1) {
			mid = ((right + left) / 2);
			if (dt[mid] <= target)
				left = mid;
			else
				right = mid;
		}
		return right;
		

	}

	private static void fill(boolean[] target, boolean reset) {
		for (int i = 0; i < target.length; i++)
			target[i] = reset;
	}

	private static void fill(int[] target, int reset) {
		for (int i = 0; i < target.length; i++)
			target[i] = reset;
	}

	private static void fill(long[] target, long reset) {
		for (int i = 0; i < target.length; i++)
			target[i] = reset;
	}

	private static void fill(char[] target, char reset) {
		for (int i = 0; i < target.length; i++)
			target[i] = reset;
	}

	private static void fill(double[] target, double reset) {
		for (int i = 0; i < target.length; i++)
			target[i] = reset;
	}

	private static void fill(boolean[][] target, boolean reset) {
		for (int i = 0; i < target.length; i++) {
			for (int j = 0; j < target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}

	private static void fill(int[][] target, int reset) {
		for (int i = 0; i < target.length; i++) {
			for (int j = 0; j < target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}

	private static void fill(long[][] target, long reset) {
		for (int i = 0; i < target.length; i++) {
			for (int j = 0; j < target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}

	private static void fill(char[][] target, char reset) {
		for (int i = 0; i < target.length; i++) {
			for (int j = 0; j < target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}

	private static void fill(double[][] target, double reset) {
		for (int i = 0; i < target.length; i++) {
			for (int j = 0; j < target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}

	private static void fill(int[][][] target, int reset) {
		for (int i = 0; i < target.length; i++) {
			for (int j = 0; j < target[i].length; j++) {
				for (int k = 0; k < target[i][j].length; k++) {
					target[i][j][k] = reset;
				}
			}
		}
	}

	private static void fill(long[][][] target, long reset) {
		for (int i = 0; i < target.length; i++) {
			for (int j = 0; j < target[i].length; j++) {
				for (int k = 0; k < target[i][j].length; k++) {
					target[i][j][k] = reset;
				}
			}
		}
	}

	private static void fill_parent(int[] parent) {
		for (int i = 0; i < parent.length; i++) {
			parent[i] = i;
		}
	}

	private static void showBit(int bit) {
		for (int i = 0; i < id0(bit); i++) {
			if (id19(bit, i))
				System.out.print("O");
			else
				System.out.print(".");
		}
		System.out.println();
	}

	private static void showBit(long bit) {
		for (int i = 0; i < id0(bit); i++) {
			if (id19(bit, i))
				System.out.print("O");
			else
				System.out.print(".");
		}
		System.out.println();
	}

	static void show2(boolean[][] dt, String cmnt) {
		for (int i = 0; i < dt.length; i++) {
			for (int j = 0; j < dt[i].length; j++) {
				if (dt[i][j])
					System.out.print("O");
				else
					System.out.print(".");
			}
			if (!cmnt.equals(""))
				System.out.print("<-" + cmnt);
			System.out.println(" :" + i);
		}
	}

	static void show2(int[][] dt, String cmnt) {
		for (int i = 0; i < dt.length; i++) {
			for (int j = 0; j < dt[i].length; j++)
				System.out.print(dt[i][j] + ",");
			if (!cmnt.equals(""))
				System.out.print("<-" + cmnt);
			System.out.println(" :" + i);
		}
	}

	static void show2(long[][] dt, String cmnt) {
		for (int i = 0; i < dt.length; i++) {
			for (int j = 0; j < dt[i].length; j++)
				System.out.print(dt[i][j] + ",");
			if (!cmnt.equals(""))
				System.out.print("<-" + cmnt);
			System.out.println(" :" + i);
		}
	}

	static void show2(ArrayDeque<Long> dt) {
		long element = 0;
		while (dt.size() > 0) {
			element = dt.removeFirst();
			System.out.print(element);
		}
		System.out.println("\n");
	}

	static void show2(List<Object> dt) {
		for (int i = 0; i < dt.size(); i++)
			System.out.print(dt.get(i) + ",");
		System.out.println("\n");
	}

	private static void id12(int[] array) {
		PrintWriter out = new PrintWriter(System.out);
		for (int e: array)
			out.println(e);
		out.flush();
	}

	private static void id12(long[] array) {
		PrintWriter out = new PrintWriter(System.out);
		for (long e: array)
			out.println(e);
		out.flush();
	}

	private static void id12(ArrayList<Object> array) {
		PrintWriter out = new PrintWriter(System.out);
		for (Object e: array)
			out.println(e);
		out.flush();
	}

	private static void id4(int[] array) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(array[0]);
		for (int i = 1; i < array.length; i++)
			out.print(" " + array[i]);
		out.println();
		out.flush();
	}

	private static void id4(long[] array) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(array[0]);
		for (int i = 1; i < array.length; i++)
			out.print(" " + array[i]);
		out.println();
		out.flush();
	}

	private static void id4(double[] array) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(array[0]);
		for (int i = 1; i < array.length; i++)
			out.print(" " + array[i]);
		out.println();
		out.flush();
	}

	private static void id4(ArrayList<Integer> array) {
		if (array.isEmpty())
			return;
		PrintWriter out = new PrintWriter(System.out);
		out.print(array.get(0));
		for (int i = 1; i < array.size(); i++)
			out.print(" " + array.get(i));
		out.println();
		out.flush();
	}

	static class Vector {
		int x, y;

		public Vector(int sx, int sy) {
			this.x = sx;
			this.y = sy;
		}

		public boolean equals(Vector v) {
			return (this.x == v.x && this.y == v.y);
		}

		public void show2() {
			System.out.println(this.x + ", " + this.y);
		}

		public static int dist2(Vector a, Vector b) {
			int dx = abs(a.x - b.x);
			int dy = abs(a.y - b.y);
			if (dx > 3e4)
				throw new IllegalArgumentException("Input is to Large. Use Long.");
			if (dy > 3e4)
				throw new IllegalArgumentException("Input is to Large. Use Long.");
			return (dx * dx + dy * dy);
		}
	}

	static class CompVector implements Comparator<Vector> {
		public int compare(Vector a, Vector b) {
			if (a.x == b.x)
				return a.y - b.y;
			else
				return a.x - b.x;
		}
	}

	static class FastScanner {
		

		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		private boolean id34() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}

		private int readByte() {
			if (id34())
				return buffer[ptr++];
			else
				return -1;
		}

		private static boolean id36(int c) {
			return (33 <= c) && (c <= 126);
		}

		public boolean hasNext() {
			while (id34() && !id36(buffer[ptr]))
				ptr++;
			return id34();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (id36(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public long id13() {
			if (!hasNext())
				throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while (true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !id36(b) || b == ':') {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}

		public int id20() {
			long nl = id13();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
				throw new NumberFormatException();
			}
			return (int) nl;
		}

		public double id14() {
			return Double.parseDouble(next());
		}

		

		public void ai(int[]... array) {
			for (int i = 0; i < array[0].length; i++) {
				for (int j = 0; j < array.length; j++) {
					array[j][i] = id20();
				}
			}
			return;
		}

		public void al(long[]... array) {
			for (int i = 0; i < array[0].length; i++) {
				for (int j = 0; j < array.length; j++) {
					array[j][i] = id13();
				}
			}
			return;
		}

		public void id5(int[] array) {
			for (int i = 0; i < array.length; i++) {
				array[i] = id20() - 1;
			}
			return;
		}

		public void aD(double[] array) {
			for (int i = 0; i < array.length; i++) {
				array[i] = id14();
			}
			return;
		}

		public void id26(int[][] array) {
			for (int i = 0; i < array.length; i++) {
				for (int j = 0; j < array[0].length; j++) {
					array[i][j] = id20();
				}
			}
			return;
		}

		public void id24(long[][] array) {
			for (int i = 0; i < array.length; i++) {
				for (int j = 0; j < array[0].length; j++) {
					array[i][j] = id13();
				}
			}
			return;
		}
	}
}

