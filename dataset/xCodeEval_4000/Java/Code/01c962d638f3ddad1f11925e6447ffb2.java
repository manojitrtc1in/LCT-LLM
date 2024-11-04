import java.io.*;
import java.util.*;


public class Main {
	private InputStream is;
	private PrintWriter out;
	int time = 0, DP[], start[], end[], dist[], black[], MOD = (int) (1e9 + 7), arr[], weight[][], x[], y[], parent[];
	int MAX = 100010, N, K;
	long red[], ans = Long.MAX_VALUE;

	ArrayList<Character>[] amp;
	ArrayList<Pair>[] pmp;
	boolean b[][], boo[][], b1[];
	Pair prr[];
	HashMap<Pair, Integer> hm = new HashMap();
	long Dp[][][][] = new long[110][110][12][12];

	void soln() {
		is = System.in;
		out = new PrintWriter(System.out);
		long s = System.currentTimeMillis();
		solve();

		

		out.flush();
		

	}

	static class ST1 

	{
		long arr[], st[];
		int size;

		ST1(long a[]) {
			arr = a.clone();
			size = 10 * arr.length;
			st = new long[size];
			build(0, arr.length - 1, 1);
		}

		void build(int ss, int se, int si) {
			if (ss == se) {
				st[si] = arr[ss];
				return;
			}
			int mid = (ss + se) / 2;
			int val = 2 * si;
			build(ss, mid, val);
			build(mid + 1, se, val + 1);
			st[si] = Math.min(st[val], st[val + 1]);
		}

		void update(int ss, int se, int idx, long val, int si) {
			if (ss == se) {
				

				st[si] = val;
				return;
			}
			int mid = (ss + se) / 2;
			if (ss <= idx && idx <= mid) {
				update(ss, mid, idx, val, 2 * si);
			} else {
				update(mid + 1, se, idx, val, 2 * si + 1);
			}
			int v = 2 * si;
			st[si] = Math.min(st[v], st[v + 1]);
		}

		long get(int ss, int se, int l, int r, int si) {
			if (l > se || r < ss || l > r)
				return Long.MAX_VALUE / 1000;
			if (l <= ss && r >= se)
				return st[si];
			int mid = (ss + se) / 2;
			int val = 2 * si;
			return Math.min(get(ss, mid, l, r, val), get(mid + 1, se, l, r, val + 1));
		}
	}

	public static void main(String[] args) throws Exception {
		new Thread(null, new Runnable() {
			public void run() {
				try {
					

				} catch (Exception e) {
					System.out.println(e);
				}
			}
		}, "1", 1 << 26).start();
		new Main().soln();
	}

	int cost = 0, D[][];
	char ch[], ch1[];
	int hash = 29;
	TreeSet<Cell> ts;
	int x2, y2;
	HashSet<Integer>[] hs = (HashSet<Integer>[]) new HashSet[110];
	cell[] c;
	Pair[] p = new Pair[4];
	void solve() {
		int n = ni(), m = ni(), k = ni();
		int arr[][] = new int[n][m];
		int row[] = new int[n];
		int col[] = new int[m];
		int q[][] = new int[k][3];
		Arrays.fill(row, -1);
		Arrays.fill(col, -1);
		for(int i = 0;i<k;i++) {
			int t = ni(), r = ni()-1, a = ni();
			q[i][0] = t;
			q[i][1] = r;
			q[i][2] = a;
		}
		for(int i = k-1;i>=0;i--) {
			int t = q[i][0], r = q[i][1], a = q[i][2];
			if(t==1) {
				if(row[r]==-1) {
					row[r] = 1;
					for(int j = 0;j<m;j++) {
						if(arr[r][j]==0)
						arr[r][j] = a;
					}
				}
			}
			else {
				if(col[r]==-1) {
					col[r] = 1;
					for(int j = 0;j<n;j++) {
						if(arr[j][r]==0)
						arr[j][r] = a;
					}
				}
			}
		}
		for(int i = 0; i< n;i++) {
			for(int j = 0; j< m;j++) System.out.print(arr[i][j]+" ")
			;
			System.out.println();
		}
	}
	void print(int[][] arr) {
		int seed = 110, n = arr.length - 220;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(arr[i + seed][j + seed] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

	int recur(int i, int time) {
		if (i >= N)
			return 0;
		if (D[i][time] != -1)
			return D[i][time];
		if ((time + c[i].t) >= c[i].d)
			return D[i][time] = recur(i + 1, time);
		return D[i][time] = max(recur(i + 1, time), c[i].p + recur(i + 1, time + c[i].t));
	}

	static class cell implements Comparable<cell> {
		int t, d, p, i;

		cell(int t, int d, int p, int i) {
			this.t = t;
			this.p = p;
			this.d = d;
			this.i = i;
		}

		public int compareTo(cell other) {
			

			return Long.compare(d, other.d);

											

											

			

			

		}

		public String toString() {
			return this.d + " " + this.t;
		}
	}

	long abs(long x) {
		return ((x > 0) ? x : -x);
	}

	long ret(int p) {
		if (p >= 0)
			return 0;
		else
			return 1;
	}

	long val(int p, int a, int b) {
		if (p >= 0) {
			return (a * 1l * p);
		}
		return (b * 1l * p);
	}

	void ternary_search(int l, int r) {
		

		

		

		if (r >= l) {
			int mid1 = l + (r - l) / 3;
			int mid2 = r - (r - l) / 3;
			long cnt1 = 0, cnt2 = 0;
			cnt1 = compute(mid1);
			cnt2 = compute(mid2);
			

			ans = Math.min(cnt1, cnt2);
			if (cnt1 < cnt2) {
				ternary_search(l, mid2 - 1);
			} else {
				ternary_search(mid1 + 1, r);
			}
		}
		return;
	}

	long compute(int x) {
		long ans = 0;
		int c = arr[0];
		for (int i = 1; i <= x; i++) {
			ans += max(c + 1 - arr[i], 0);
			c = max(c + 1, arr[i]);
		}
		int temp = arr[x];
		arr[x] = max(c + 1, arr[x]);
		

		c = arr[arr.length - 1];
		for (int i = arr.length - 1; i > x; i--) {
			ans += max(c + 1 - arr[i - 1], 0);
			c = max(c + 1, arr[i - 1]);
		}
		arr[x] = temp;
		return ans;
	}

	public int getParent(int x) {
		while (parent[x] != x) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	void getFactors(int n, int x) {
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				hs[x].add(i);
				hs[x].add(n / i);
			}
		}
	}

	void recur(int a, int b, int k) {
		if (k == 0) {
			if (a == x2 && b == y2)
				ans++;
			return;
		}
		recur(a, b + 1, k - 1);
		recur(a, b - 1, k - 1);
		recur(a + 1, b, k - 1);
		recur(a - 1, b, k - 1);
	}

	int min(int a, int b) {
		return (a < b) ? a : b;
	}

	private class Cell implements Comparable<Cell> {
		int u, v, s;

		public Cell(int u, int v, int s) {
			this.u = u;
			this.v = v;
			this.s = s;
		}

		public int hashCode() {
			return Objects.hash();
		}

		public int compareTo(Cell other) {
			return (Long.compare(s, other.s) != 0 ? (Long.compare(s, other.s))
					: (Long.compare(v, other.v) != 0 ? Long.compare(v, other.v) : Long.compare(u, other.u)))
					& ((Long.compare(s, other.s) != 0 ? (Long.compare(s, other.s))
							: (Long.compare(u, other.v) != 0 ? Long.compare(u, other.v) : Long.compare(v, other.u))));
		}

		public String toString() {
			return this.u + " " + this.v;
		}
	}

	class Pair implements Comparable<Pair> {
		int u, v, i;

		Pair(int u, int v) {
			this.u = u;
			this.v = v;
		}

		Pair(int u, int v, int i) {
			this.u = u;
			this.v = v;
			this.i = i;
		}

		public int hashCode() {
			return Objects.hash();
		}

		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return ((u == other.u && v == other.v));
		}

		public int compareTo(Pair other) {
			

			return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u)) : (Long.compare(v, other.v));

																											

																											

																											

																											

																											

																											

			

			

		}

		public String toString() {
			return this.u + " " + this.v;
		}
	}

	int max(int a, int b) {
		if (a > b)
			return a;
		return b;
	}

	static class FenwickTree {

		int[] array; 

						

						


		public FenwickTree(int size) {
			array = new int[size + 1];
		}

		public int rsq(int ind) {
			assert ind > 0;
			int sum = 0;
			while (ind > 0) {
				sum += array[ind];
				

				

				

				ind -= ind & (-ind);
			}
			return sum;
		}

		public int rsq(int a, int b) {
			assert b >= a && a > 0 && b > 0;
			return rsq(b) - rsq(a - 1);
		}

		public void update(int ind, int value) {
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

	void buildGraph(int n) {
		for (int i = 0; i < n; i++) {
			int x1 = ni(), y1 = ni(), z = ni();
			pmp[x1].add(new Pair(y1, z));
		}
	}

	long modInverse(long a, long mOD2) {
		return power(a, mOD2 - 2, mOD2);
	}

	long power(long x, long y, long m) {
		if (y == 0)
			return 1;
		long p = power(x, y / 2, m) % m;
		p = (p * p) % m;

		return (y % 2 == 0) ? p : (x * p) % m;
	}

	public long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static class ST {
		int arr[], lazy[], n;

		ST(int a) {
			n = a;
			arr = new int[10 * n];
			lazy = new int[10 * n];
		}

		void up(int l, int r, int val) {
			update(0, n - 1, 0, l, r, val);
		}

		void update(int l, int r, int c, int x, int y, int val) {
			if (lazy[c] != 0) {
				lazy[2 * c + 1] += lazy[c];
				lazy[2 * c + 2] += lazy[c];
				if (l == r)
					arr[c] += lazy[c];
				lazy[c] = 0;
			}
			if (l > r || x > y || l > y || x > r)
				return;
			if (x <= l && y >= r)

			{
				lazy[c] += val;
				return;
			}
			int mid = l + r >> 1;
			update(l, mid, 2 * c + 1, x, y, val);
			update(mid + 1, r, 2 * c + 2, x, y, val);
			arr[c] = Math.max(arr[2 * c + 1], arr[2 * c + 2]);
		}

		int an(int ind) {
			return ans(0, n - 1, 0, ind);
		}

		int ans(int l, int r, int c, int ind) {
			if (lazy[c] != 0) {
				lazy[2 * c + 1] += lazy[c];
				lazy[2 * c + 2] += lazy[c];
				if (l == r)
					arr[c] += lazy[c];
				lazy[c] = 0;
			}
			if (l == r)
				return arr[c];
			int mid = l + r >> 1;
			if (mid >= ind)
				return ans(l, mid, 2 * c + 1, ind);
			return ans(mid + 1, r, 2 * c + 2, ind);
		}
	}

	public static int[] shuffle(int[] a, Random gen) {
		for (int i = 0, n = a.length; i < n; i++) {
			int ind = gen.nextInt(n - i) + i;
			int d = a[i];
			a[i] = a[ind];
			a[ind] = d;
		}
		return a;
	}

	long power(long x, long y, int mod) {
		long ans = 1;
		while (y > 0) {
			if (y % 2 == 0) {
				x = (x * x) % mod;
				y /= 2;
			} else {
				ans = (x * ans) % mod;
				y--;
			}
		}
		return ans;
	}

	

	

	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;

	private int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}

	private boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b))
			;
		return b;
	}

	private double nd() {
		return Double.parseDouble(ns());
	}

	private char nc() {
		return (char) skip();
	}

	private String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { 

									

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}

	private int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;

	private void tr(Object... o) {
		if (!oj)
			System.out.println(Arrays.deepToString(o));
	}
}