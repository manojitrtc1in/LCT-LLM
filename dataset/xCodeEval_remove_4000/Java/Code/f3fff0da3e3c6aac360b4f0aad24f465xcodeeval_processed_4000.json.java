import java.io.*;
import java.util.*;

public class E implements Runnable {
	FastReader scn;
	PrintWriter out;
	String INPUT = "";

	int time = 0;
	long inf = Long.MAX_VALUE / 4;
	int[] ord, st, en;
	long[] seg, lazy;

	void solve() {
		int n = scn.nextInt(), Q = scn.nextInt();
		int[] par = new int[n], w = new int[n];
		for (int i = 1; i < n; i++) {
			par[i] = scn.nextInt() - 1;
			w[i] = scn.nextInt();
		}
		par[0] = -1;
		int[][][] g = id0(par, w);
		for (int i = 0; i < n; i++) {
			Arrays.sort(g[i], (o1, o2) -> o1[0] - o2[0]);
		}
		ord = new int[n];
		st = new int[n];
		en = new int[n];

		seg = new long[4 * n];
		lazy = new long[4 * n];

		long[] arr = new long[n];
		dfs(g, 0, -1, 0, arr);

		id3 tree = new id3(arr);

		int[] count = new int[n];
		int[][] qr = new int[Q][];
		for (int i = 0; i < Q; i++) {
			qr[i] = new int[] { scn.nextInt() - 1, scn.nextInt() - 1, scn.nextInt() - 1, i };
			count[qr[i][0]]++;
		}

		int[][][] need = new int[n][][];
		for (int i = 0; i < n; i++) {
			need[i] = new int[count[i]][3];
		}

		for (int[] q : qr) {
			need[q[0]][count[q[0]] - 1][0] = q[1];
			need[q[0]][count[q[0]] - 1][1] = q[2] + 1;
			need[q[0]][count[q[0]] - 1][2] = q[3];
			count[q[0]]--;
		}

		long[] ans = new long[Q];
		func(g, need, ans, 0, -1, tree);
		for (long x : ans) {
			out.println(x);
		}
	}

	void func(int[][][] g, int[][][] need, long[] ans, int u, int p, id3 tree) {
		for (int[] q : need[u]) {
			int l = q[0], r = q[1], ind = q[2];
			ans[ind] = tree.minx(l, r);
		}

		for (int[] v : g[u]) {
			if (v[0] != p) {
				tree.add(0, g.length, v[1]);
				tree.add(st[v[0]], en[v[0]], -2 * v[1]);

				func(g, need, ans, v[0], u, tree);

				tree.add(0, g.length, -v[1]);
				tree.add(st[v[0]], en[v[0]], 2 * v[1]);
			}
		}
	}

	void dfs(int[][][] g, int u, int p, long d, long[] arr) {
		ord[time] = u;
		st[u] = time;
		time++;
		for (int[] v : g[u]) {
			if (v[0] != p) {
				dfs(g, v[0], u, d + v[1], arr);
			}
		}
		en[u] = time;

		if (g[u].length == 1 && p != -1) {
			arr[st[u]] = d;
		} else {
			arr[st[u]] = inf;
		}
	}

	public static class id3 {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long I = Long.MAX_VALUE / 4; 


		public id3(int n) {
			N = n;
			M = Integer.highestOneBit(Math.max(n - 1, 1)) << 2;
			H = M >>> 1;
			st = new long[M];
			plus = new long[H];
		}

		public id3(long[] a) {
			N = a.length;
			M = Integer.highestOneBit(Math.max(N - 1, 1)) << 2;
			H = M >>> 1;
			st = new long[M];
			for (int i = 0; i < N; i++) {
				st[H + i] = a[i];
			}
			plus = new long[H];
			Arrays.fill(st, H + N, M, I);
			for (int i = H - 1; i >= 1; i--)
				propagate(i);
		}

		private void propagate(int i) {
			st[i] = Math.min(st[2 * i], st[2 * i + 1]) + plus[i];
		}

		public void add(int l, int r, long v) {
			if (l < r)
				add(l, r, v, 0, H, 1);
		}

		private void add(int l, int r, long v, int cl, int cr, int cur) {
			if (l <= cl && cr <= r) {
				if (cur >= H) {
					st[cur] += v;
				} else {
					plus[cur] += v;
					propagate(cur);
				}
			} else {
				int mid = cl + cr >>> 1;
				if (cl < r && l < mid) {
					add(l, r, v, cl, mid, 2 * cur);
				}
				if (mid < r && l < cr) {
					add(l, r, v, mid, cr, 2 * cur + 1);
				}
				propagate(cur);
			}
		}

		public long min(int l, int r) {
			return l >= r ? I : min(l, r, 0, H, 1);
		}

		private long min(int l, int r, int cl, int cr, int cur) {
			if (l <= cl && cr <= r) {
				return st[cur];
			} else {
				int mid = cl + cr >>> 1;
				long ret = I;
				if (cl < r && l < mid) {
					ret = Math.min(ret, min(l, r, cl, mid, 2 * cur));
				}
				if (mid < r && l < cr) {
					ret = Math.min(ret, min(l, r, mid, cr, 2 * cur + 1));
				}
				return ret + plus[cur];
			}
		}

		public void fall(int i) {
			if (i < H) {
				if (2 * i < H) {
					plus[2 * i] += plus[i];
					plus[2 * i + 1] += plus[i];
				}
				st[2 * i] += plus[i];
				st[2 * i + 1] += plus[i];
				plus[i] = 0;
			}
		}

		public int firstle(int l, long v) {
			int cur = H + l;
			for (int i = 1, j = Integer.numberOfTrailingZeros(H) - 1; i <= cur; j--) {
				fall(i);
				i = i * 2 | cur >>> j & 1;
			}
			while (true) {
				fall(cur);
				if (st[cur] <= v) {
					if (cur < H) {
						cur = 2 * cur;
					} else {
						return cur - H;
					}
				} else {
					cur++;
					if ((cur & cur - 1) == 0)
						return -1;
					cur = cur >>> Integer.numberOfTrailingZeros(cur);
				}
			}
		}

		public int lastle(int l, long v) {
			int cur = H + l;
			for (int i = 1, j = Integer.numberOfTrailingZeros(H) - 1; i <= cur; j--) {
				fall(i);
				i = i * 2 | cur >>> j & 1;
			}
			while (true) {
				fall(cur);
				if (st[cur] <= v) {
					if (cur < H) {
						cur = 2 * cur + 1;
					} else {
						return cur - H;
					}
				} else {
					if ((cur & cur - 1) == 0)
						return -1;
					cur = cur >>> Integer.numberOfTrailingZeros(cur);
					cur--;
				}
			}
		}

		public void addx(int l, int r, long v) {
			if (l >= r)
				return;
			while (l != 0) {
				int f = l & -l;
				if (l + f > r)
					break;
				if (f == 1) {
					st[(H + l) / f] += v;
				} else {
					plus[(H + l) / f] += v;
				}
				l += f;
			}

			while (l < r) {
				int f = r & -r;
				if (f == 1) {
					st[(H + r) / f - 1] += v;
				} else {
					plus[(H + r) / f - 1] += v;
				}
				r -= f;
			}
		}

		public long minx(int l, int r) {
			long lmin = I;
			if (l >= r)
				return lmin;
			if (l != 0) {
				for (int d = 0; H >>> d > 0; d++) {
					if (d > 0) {
						int id = (H + l - 1 >>> d);
						lmin += plus[id];
					}
					if (l << ~d < 0 && l + (1 << d) <= r) {
						long v = st[H + l >>> d];
						if (v < lmin)
							lmin = v;
						l += 1 << d;
					}
				}
			}
			long rmin = I;
			for (int d = 0; H >>> d > 0; d++) {
				if (d > 0 && r < H)
					rmin += plus[H + r >>> d];
				if (r << ~d < 0 && l < r) {
					long v = st[(H + r >>> d) - 1];
					if (v < rmin)
						rmin = v;
					r -= 1 << d;
				}
			}
			long min = Math.min(lmin, rmin);
			return min;
		}

		public long[] toArray() {
			return toArray(1, 0, H, new long[H]);
		}

		private long[] toArray(int cur, int l, int r, long[] ret) {
			if (r - l == 1) {
				ret[cur - H] = st[cur];
			} else {
				toArray(2 * cur, l, l + r >>> 1, ret);
				toArray(2 * cur + 1, l + r >>> 1, r, ret);
				for (int i = l; i < r; i++)
					ret[i] += plus[cur];
			}
			return ret;
		}
	}

	int[][][] id0(int[] par, int[] w) {
		int n = par.length;
		int[] ct = new int[n];
		for (int i = 0; i < n; i++) {
			if (par[i] >= 0) {
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][][] g = new int[n][][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[ct[i]][2];
		}
		for (int i = 0; i < n; i++) {
			if (par[i] >= 0) {
				g[par[i]][ct[par[i]] - 1][0] = i;
				g[par[i]][ct[par[i]] - 1][1] = w[i];
				--ct[par[i]];
				g[i][ct[i] - 1][0] = par[i];
				g[i][ct[i] - 1][1] = w[i];
				--ct[i];
			}
		}
		return g;
	}

	public void run() {
		long time = System.currentTimeMillis();
		boolean oj = System.getProperty("ONLINE_JUDGE") != null;
		out = new PrintWriter(System.out);
		scn = new FastReader(oj);
		solve();
		out.flush();
		if (!oj) {
			System.out.println(Arrays.deepToString(new Object[] { System.currentTimeMillis() - time + " ms" }));
		}
	}

	public static void main(String[] args) {
		new Thread(null, new E(), "Main", 1 << 26).start();
	}

	class FastReader {
		InputStream is;

		public FastReader(boolean onlineJudge) {
			is = onlineJudge ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		}

		byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;

		int readByte() {
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

		boolean id4(int c) {
			return !(c >= 33 && c <= 126);
		}

		int skip() {
			int b;
			while ((b = readByte()) != -1 && id4(b))
				;
			return b;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		char nextChar() {
			return (char) skip();
		}

		String next() {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(id4(b))) { 

				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		String nextLine() {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while ((!id4(b) || b == ' ')) { 

				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		char[] next(int n) {
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(id4(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}

		int nextInt() {
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

		long nextLong() {
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

		char[][] nextMatrix(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = next(m);
			return map;
		}

		int[] id5(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long[] id6(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		int[][] id1(int n, int m) {
			int[][] arr = new int[n][];
			for (int i = 0; i < n; i++) {
				arr[i] = id5(m);
			}
			return arr;
		}

		long[][] id2(int n, int m) {
			long[][] arr = new long[n][];
			for (int i = 0; i < n; i++) {
				arr[i] = id6(m);
			}
			return arr;
		}

		int[] shuffle(int[] arr) {
			Random r = new Random();
			for (int i = 1, j; i < arr.length; i++) {
				j = r.nextInt(i);
				arr[i] = arr[i] ^ arr[j];
				arr[j] = arr[i] ^ arr[j];
				arr[i] = arr[i] ^ arr[j];
			}
			return arr;
		}

		int[] uniq(int[] arr) {
			Arrays.sort(arr);
			int[] rv = new int[arr.length];
			int pos = 0;
			rv[pos++] = arr[0];
			for (int i = 1; i < arr.length; i++) {
				if (arr[i] != arr[i - 1]) {
					rv[pos++] = arr[i];
				}
			}
			return Arrays.copyOf(rv, pos);
		}

		int[] reverse(int[] arr) {
			int l = 0, r = arr.length - 1;
			while (l < r) {
				arr[l] = arr[l] ^ arr[r];
				arr[r] = arr[l] ^ arr[r];
				arr[l] = arr[l] ^ arr[r];
				l++;
				r--;
			}
			return arr;
		}

	}
}