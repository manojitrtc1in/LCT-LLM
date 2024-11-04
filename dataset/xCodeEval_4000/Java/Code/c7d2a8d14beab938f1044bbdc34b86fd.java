import java.io.*;
import java.util.*;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class DSU {
		int[] sz;
		int[] p;

		public DSU(int n) {
			sz = new int[n];
			p = new int[n];
			for (int i = 0; i < p.length; i++) {
				p[i] = i;
				sz[i] = 1;
			}
		}

		public int get(int x) {
			if (x == p[x]) {
				return x;
			}
			int par = get(p[x]);
			p[x] = par;
			return par;
		}

		public boolean unite(int a, int b) {
			int pa = get(a);
			int pb = get(b);
			if (sz[pa] == 1) {
				p[pa] = pb;
				sz[pb] += sz[pa];
				return true;
			}
			if (sz[pb] == 1) {
				p[pb] = pa;
				sz[pa] += sz[pb];
				return true;
			}
			return false;
		}
	}

	public class SegmentTreeAdd {
		int pow;
		long[] max;
		long[] delta;
		boolean[] flag;

		public SegmentTreeAdd(long[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			max = new long[2 * pow];
			delta = new long[2 * pow];
			for (int i = 0; i < max.length; i++) {
				max[i] = Long.MIN_VALUE / 2;
			}
			for (int i = 0; i < a.length; i++) {
				max[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				max[i] = f(max[2 * i], max[2 * i + 1]);
			}
		}

		public long get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l > r) {
				return Long.MIN_VALUE / 2;
			}
			if (l == tl && r == tr) {
				return max[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
		}

		public void set(int v, int tl, int tr, int l, int r, long x) {
			push(v, tl, tr);
			if (l > tr || r < tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				delta[v] += x;
				flag[v] = true;
				push(v, tl, tr);
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, l, r, x);
			set(2 * v + 1, tm + 1, tr, l, r, x);
			max[v] = f(max[2 * v], max[2 * v + 1]);
		}

		public void push(int v, int tl, int tr) {
			if (flag[v]) {
				if (v < pow) {
					flag[2 * v] = true;
					flag[2 * v + 1] = true;
					delta[2 * v] += delta[v];
					delta[2 * v + 1] += delta[v];
				}
				flag[v] = false;
				max[v] += delta[v];
				delta[v] = 0;
			}
		}

		public long f(long a, long b) {
			return Math.max(a, b);
		}
	}

	public class SegmentTreeSet {
		int pow;
		int[] sum;
		int[] delta;
		boolean[] flag;

		public SegmentTreeSet(int[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			sum = new int[2 * pow];
			delta = new int[2 * pow];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
			}
		}

		public int get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l > r) {
				return 0;
			}
			if (l == tl && r == tr) {
				return sum[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
		}

		public void set(int v, int tl, int tr, int l, int r, int x) {
			push(v, tl, tr);
			if (l > tr || r < tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				delta[v] = x;
				flag[v] = true;
				push(v, tl, tr);
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, l, r, x);
			set(2 * v + 1, tm + 1, tr, l, r, x);
			sum[v] = f(sum[2 * v], sum[2 * v + 1]);
		}

		public void push(int v, int tl, int tr) {
			if (flag[v]) {
				if (v < pow) {
					flag[2 * v] = true;
					flag[2 * v + 1] = true;
					delta[2 * v] = delta[v];
					delta[2 * v + 1] = delta[v];
				}
				flag[v] = false;
				sum[v] = delta[v] * (tr - tl + 1);
			}
		}

		public int f(int a, int b) {
			return a + b;
		}
	}

	public class Pair implements Comparable<Pair> {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public Pair clone() {
			return new Pair(x, y);
		}

		public String toString() {
			return x + " " + y;
		}

		@Override
		public int compareTo(Pair o) {
			if (y > o.y) {
				return 1;
			}
			if (y < o.y) {
				return -1;
			}
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			return 0;
		}
	}

	long mod = 1000000007;
	Random random = new Random();

	public void shuffle(Pair[] a) {
		for (int i = 0; i < a.length; i++) {
			int x = random.nextInt(i + 1);
			Pair t = a[x];
			a[x] = a[i];
			a[i] = t;
		}
	}

	public void sort(int[][] a) {
		for (int i = 0; i < a.length; i++) {
			Arrays.sort(a[i]);
		}
	}

	public void add(TreeMap<Integer, Integer> map, Integer s) {
		if (map.containsKey(s)) {
			map.put(s, map.get(s) + 1);
		} else {
			map.put(s, 1);
		}
	}

	public void remove(TreeMap<Integer, Integer> map, Integer s) {
		if (map.get(s) > 1) {
			map.put(s, map.get(s) - 1);
		} else {
			map.remove(s);
		}
	}

	long max = Long.MAX_VALUE / 2;
	double eps = 1e-10;

	public int signum(double x) {
		if (x > eps) {
			return 1;
		}
		if (x < -eps) {
			return -1;
		}
		return 0;
	}

	public long abs(long x) {
		return x < 0 ? -x : x;
	}

	public long min(long x, long y) {
		return x < y ? x : y;
	}

	public long max(long x, long y) {
		return x > y ? x : y;
	}

	public long gcd(long x, long y) {
		while (y > 0) {
			long c = y;
			y = x % y;
			x = c;
		}
		return x;
	}

	public final Vector ZERO = new Vector(0, 0);

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	public class Rect {
		long x1;
		long x2;
		long y1;
		long y2;
		int number;

		public Rect(long x1, long x2, long y1, long y2, int number) {
			this.x1 = x1;
			this.x2 = x2;
			this.y1 = y1;
			this.y2 = y2;
			this.number = number;
		}
	}

	public static class Fenvik {
		int[] t;

		public Fenvik(int n) {
			t = new int[n];
		}

		public void add(int x, int delta) {
			for (int i = x; i < t.length; i = (i | (i + 1))) {
				t[i] += delta;
			}
		}

		private int sum(int r) {
			int ans = 0;
			int x = r;
			while (x >= 0) {
				ans += t[x];
				x = (x & (x + 1)) - 1;
			}
			return ans;
		}

		public int sum(int l, int r) {
			return sum(r) - sum(l - 1);
		}
	}

	public class SegmentTreeMaxSum {
		int pow;
		int[] sum;
		int[] maxPrefSum;
		int[] maxSufSum;
		int[] maxSum;

		public SegmentTreeMaxSum(int[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			sum = new int[2 * pow];
			maxPrefSum = new int[2 * pow];
			maxSum = new int[2 * pow];
			maxSufSum = new int[2 * pow];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
				maxSum[pow + i] = Math.max(a[i], 0);
				maxPrefSum[pow + i] = maxSum[pow + i];
				maxSufSum[pow + i] = maxSum[pow + i];
			}
			for (int i = pow - 1; i > 0; i--) {
				update(i);
			}
		}

		public int[] get(int v, int tl, int tr, int l, int r) {
			if (r <= tl || l >= tr) {
				int[] ans = { 0, 0, 0, 0 };
				return ans;
			}
			if (l <= tl && r >= tr) {
				int[] ans = { maxPrefSum[v], maxSum[v], maxSufSum[v], sum[v] };
				return ans;
			}
			int tm = (tl + tr) / 2;
			int[] left = get(2 * v, tl, tm, l, r);
			int[] right = get(2 * v + 1, tm, tr, l, r);
			int[] ans = { Math.max(left[0], right[0] + left[3]),
					Math.max(left[1], Math.max(right[1], left[2] + right[0])), Math.max(right[2], left[2] + right[3]),
					left[3] + right[3] };
			return ans;
		}

		public void set(int v, int tl, int tr, int x, int value) {
			if (v >= pow) {
				sum[v] = value;
				maxSum[v] = Math.max(value, 0);
				maxPrefSum[v] = maxSum[v];
				maxSufSum[v] = maxSum[v];
				return;
			}
			int tm = (tl + tr) / 2;
			if (x < tm) {
				set(2 * v, tl, tm, x, value);
			} else {
				set(2 * v + 1, tm, tr, x, value);
			}
			update(v);
		}

		public void update(int i) {
			sum[i] = f(sum[2 * i], sum[2 * i + 1]);
			maxSum[i] = Math.max(maxSum[2 * i], Math.max(maxSum[2 * i + 1], maxSufSum[2 * i] + maxPrefSum[2 * i + 1]));
			maxPrefSum[i] = Math.max(maxPrefSum[2 * i], maxPrefSum[2 * i + 1] + sum[2 * i]);
			maxSufSum[i] = Math.max(maxSufSum[2 * i + 1], maxSufSum[2 * i] + sum[2 * i + 1]);
		}

		public int f(int a, int b) {
			return a + b;
		}
	}

	public class Point implements Comparable<Point> {
		double x;
		double y;

		public Point() {
			x = 0;
			y = 0;
		}

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return x + " " + y;
		}

		public boolean equals(Point p) {
			return x == p.x && y == p.y;
		}

		public double dist2() {
			return x * x + y * y;
		}

		public Point add(Point v) {
			return new Point(x + v.x, y + v.y);
		}

		@Override
		public int compareTo(Point o) {
			int z = signum(x + y - o.x - o.y);
			if (z != 0) {
				return z;
			}
			return signum(x - o.x) != 0 ? signum(x - o.x) : signum(y - o.y);
		}
	}

	public class Circle implements Comparable<Circle> {
		Point p;
		int r;

		public Circle(Point p, int r) {
			this.p = p;
			this.r = r;
		}

		public Point angle() {
			double z = r / sq2;
			z -= z % 1e-5;
			return new Point(p.x - z, p.y - z);
		}

		public boolean inside(Point p) {
			return hypot2(p.x - this.p.x, p.y - this.p.y) <= sq(r);
		}

		@Override
		public int compareTo(Circle o) {
			Point a = angle();
			Point oa = o.angle();
			int z = signum(a.x + a.y - oa.x - oa.y);
			if (z != 0) {
				return z;
			}
			return signum(a.y - oa.y);
		}

	}

	public class Fraction implements Comparable<Fraction> {
		long x;
		long y;

		public Fraction(long x, long y, boolean needNorm) {
			this.x = x;
			this.y = y;
			if (y < 0) {
				this.x *= -1;
				this.y *= -1;
			}
			if (needNorm) {
				long gcd = gcd(this.x, this.y);
				this.x /= gcd;
				this.y /= gcd;
			}
		}

		public Fraction clone() {
			return new Fraction(x, y, false);
		}

		public String toString() {
			return x + "/" + y;
		}

		@Override
		public int compareTo(Fraction o) {
			long res = x * o.y - y * o.x;
			if (res > 0) {
				return 1;
			}
			if (res < 0) {
				return -1;
			}
			return 0;
		}
	}

	public class Event implements Comparable<Event> {
		Fraction f;
		int type;

		public Event(Fraction f, int type) {
			this.f = f;
			this.type = type;
		}

		@Override
		public int compareTo(Event o) {
			int c = f.compareTo(o.f);
			if (c != 0) {
				return c;
			}
			return type - o.type;
		}

	}

	public double sq(double x) {
		return x * x;
	}

	public double hypot2(double x, double y) {
		return sq(x) + sq(y);
	}

	public boolean kuhn(int v, int[][] edge, boolean[] used, int[] mt) {
		used[v] = true;
		for (int u : edge[v]) {
			if (mt[u] < 0 || (!used[mt[u]] && kuhn(mt[u], edge, used, mt))) {
				mt[u] = v;
				return true;
			}
		}
		return false;
	}

	public int matching(int[][] edge) {
		int n = edge.length;
		int[] mt = new int[n];
		Arrays.fill(mt, -1);
		boolean[] used = new boolean[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i] && kuhn(i, edge, used, mt)) {
				Arrays.fill(used, false);
				ans++;
			}
		}
		return ans;
	}

	double sq2 = Math.sqrt(2);

	int small = 20;

	public class Stack {
		int[] st;
		int sz;

		public Stack(int n) {
			this.st = new int[n];
			sz = 0;
		}

		public boolean isEmpty() {
			return sz == 0;
		}

		public int peek() {
			return st[sz - 1];
		}

		public int pop() {
			sz--;
			return st[sz];
		}

		public void clear() {
			sz = 0;
		}

		public void add(int x) {
			st[sz++] = x;
		}

		public int get(int x) {
			return st[x];
		}
	}

	public int[][] readGraph(int n, int m) {
		int[][] to = new int[n][];
		int[] sz = new int[n];
		int[] x = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
			sz[x[i]]++;
			sz[y[i]]++;
		}
		for (int i = 0; i < to.length; i++) {
			to[i] = new int[sz[i]];
			sz[i] = 0;
		}
		for (int i = 0; i < x.length; i++) {
			to[x[i]][sz[x[i]]++] = y[i];
			to[y[i]][sz[y[i]]++] = x[i];
		}
		return to;
	}

	public void solve() {
		for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			int n = in.nextInt();
			int m = in.nextInt();
			int[] color = new int[n];
			Pair[] p = new Pair[m];
			for (int i = 0; i < p.length; i++) {
				p[i] = new Pair(in.nextInt() - 1, in.nextInt() - 1); 
			}
			shuffle(p);
			Arrays.sort(p);
			for (Pair e : p) {
				if (color[e.x] == 1) {
					color[e.y] = 2;
				} else if (color[e.x] == 0) {
					color[e.y] = Math.max(color[e.y], 1);
				}
			}
			ArrayList<Integer> ans = new ArrayList<>();
			for (int i = 0; i < color.length; i++) {
				if (color[i] == 2) {
					ans.add(i + 1);
				}
			}
			out.println(ans.size());
			for (int i : ans) {
				out.print(i + " ");
			}
			out.println();
		}
	}

	public void solve0(int n, int m, double[][] p) {
		double[][] probMask = new double[2][1 << m];
		int n1 = n / 2;
		int n2 = n - n1;
		for (int mask = 0; mask < (1 << n1 * m); mask++) {
			boolean[][] wall = new boolean[n1][m];
			double prob = 1;
			for (int x = 0; x < n1; x++) {
				for (int y = 0; y < m; y++) {
					int th = x * m + y;
					wall[x][y] = (mask & (1 << th)) > 0;
					if (wall[x][y]) {
						prob *= p[x][y];
					} else {
						prob *= (1 - p[x][y]);
					}
				}
			}
			if (wall[0][0]) {
				continue;
			}
			boolean[][] can = new boolean[n1][m];
			can[0][0] = true;
			for (int x = 0; x < n1; x++) {
				for (int y = 0; y < m; y++) {
					if (x < n1 - 1) {
						can[x + 1][y] |= can[x][y] & !wall[x + 1][y];
					}
					if (y < m - 1) {
						can[x][y + 1] |= can[x][y] & !wall[x][y + 1];
					}
				}
			}
			int m1 = 0;
			for (int y = 0; y < m; y++) {
				if (can[n1 - 1][y]) {
					m1 += (1 << y);
				}
			}
			probMask[0][m1] += prob;
		}

		for (int mask = 0; mask < (1 << n2 * m); mask++) {
			boolean[][] wall = new boolean[n2][m];
			double prob = 1;
			for (int x = 0; x < n2; x++) {
				for (int y = 0; y < m; y++) {
					int th = x * m + y;
					wall[x][y] = (mask & (1 << th)) > 0;
					if (wall[x][y]) {
						prob *= p[n1 + x][y];
					} else {
						prob *= (1 - p[n1 + x][y]);
					}
				}
			}
			if (wall[n2 - 1][m - 1]) {
				continue;
			}
			boolean[][] can = new boolean[n2][m];
			can[n2 - 1][m - 1] = true;
			for (int x = n2 - 1; x >= 0; x--) {
				for (int y = m - 1; y >= 0; y--) {
					if (x > 0) {
						can[x - 1][y] |= can[x][y] & !wall[x - 1][y];
					}
					if (y > 0) {
						can[x][y - 1] |= can[x][y] & !wall[x][y - 1];
					}
				}
			}
			int m1 = 0;
			for (int y = 0; y < m; y++) {
				if (can[0][y]) {
					m1 += (1 << y);
				}
			}
			probMask[1][m1] += prob;
		}

		double[][] pr = new double[2][probMask[0].length];
		for (int i = 0; i < pr[0].length; i++) {
			for (int j = 0; j < pr[0].length; j++) {
				if ((i & j) > 0) {
					pr[0][i] += probMask[1][j];
					pr[1][i] += probMask[0][j];
				}
			}
		}

		double sum = 0;
		double[][] ans = new double[n][m];

		for (int mask = 0; mask < (1 << n1 * m); mask++) {
			boolean[][] wall = new boolean[n1][m];
			double prob = 1;
			for (int x = 0; x < n1; x++) {
				for (int y = 0; y < m; y++) {
					int th = x * m + y;
					wall[x][y] = (mask & (1 << th)) > 0;
					if (wall[x][y]) {
						prob *= p[x][y];
					} else {
						prob *= (1 - p[x][y]);
					}
				}
			}
			if (wall[0][0]) {
				continue;
			}
			boolean[][] can = new boolean[n1][m];
			can[0][0] = true;
			for (int x = 0; x < n1; x++) {
				for (int y = 0; y < m; y++) {
					if (x < n1 - 1) {
						can[x + 1][y] |= can[x][y] & !wall[x + 1][y];
					}
					if (y < m - 1) {
						can[x][y + 1] |= can[x][y] & !wall[x][y + 1];
					}
				}
			}
			int m1 = 0;
			for (int y = 0; y < m; y++) {
				if (can[n1 - 1][y]) {
					m1 += (1 << y);
				}
			}
			for (int i = 0; i < n1; i++) {
				for (int j = 0; j < m; j++) {
					if (wall[i][j]) {
						ans[i][j] += prob * pr[0][m1];
					}
				}
			}
			sum += prob * pr[0][m1];
		}

		for (int mask = 0; mask < (1 << n2 * m); mask++) {
			boolean[][] wall = new boolean[n2][m];
			double prob = 1;
			for (int x = 0; x < n2; x++) {
				for (int y = 0; y < m; y++) {
					int th = x * m + y;
					wall[x][y] = (mask & (1 << th)) > 0;
					if (wall[x][y]) {
						prob *= p[n1 + x][y];
					} else {
						prob *= (1 - p[n1 + x][y]);
					}
				}
			}
			if (wall[n2 - 1][m - 1]) {
				continue;
			}
			boolean[][] can = new boolean[n2][m];
			can[n2 - 1][m - 1] = true;
			for (int x = n2 - 1; x >= 0; x--) {
				for (int y = m - 1; y >= 0; y--) {
					if (x > 0) {
						can[x - 1][y] |= can[x][y] & !wall[x - 1][y];
					}
					if (y > 0) {
						can[x][y - 1] |= can[x][y] & !wall[x][y - 1];
					}
				}
			}
			int m1 = 0;
			for (int y = 0; y < m; y++) {
				if (can[0][y]) {
					m1 += (1 << y);
				}
			}

			for (int i = 0; i < n2; i++) {
				for (int j = 0; j < m; j++) {
					if (wall[i][j]) {
						ans[n1 + i][j] += prob * pr[1][m1];
					}
				}
			}
		}

		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				out.print(ans[i][j] / sum + " ");
			}
			out.println();
		}
	}

	public void solveSmall(int n, int m, double[][] p) {
		double[][] ans = new double[n][m];
		double sum = 0;
		for (int mask = 0; mask < (1 << n * m); mask++) {
			boolean[][] wall = new boolean[n][m];
			double prob = 1;
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					int th = x * m + y;
					wall[x][y] = (mask & (1 << th)) > 0;
					if (wall[x][y]) {
						prob *= p[x][y];
					} else {
						prob *= (1 - p[x][y]);
					}
				}
			}
			if (wall[0][0] || wall[n - 1][m - 1]) {
				continue;
			}
			boolean[][] can = new boolean[n][m];
			can[0][0] = true;
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					if (x < n - 1) {
						can[x + 1][y] |= can[x][y] & !wall[x + 1][y];
					}
					if (y < m - 1) {
						can[x][y + 1] |= can[x][y] & !wall[x][y + 1];
					}
				}
			}
			if (can[n - 1][m - 1]) {
				sum += prob;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (wall[i][j]) {
							ans[i][j] += prob;
						}
					}
				}
			}
		}
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				out.print(ans[i][j] / sum + " ");
			}
			out.println();
		}
	}

	public void add(HashMap<Integer, Integer> map, int x) {
		if (map.containsKey(x)) {
			map.put(x, map.get(x) + 1);
		} else {
			map.put(x, 1);
		}
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("end.in"));
				out = new PrintWriter(new File("end.out"));
			}
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				return null;
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
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

	}

	

	public static void main(String[] arg) {
		new E().run();
	}
}