import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

public class Main {
	MyScanner sc = new MyScanner();
	Scanner sc2 = new Scanner(System.in);
	long start = System.currentTimeMillis();
	long fin = System.currentTimeMillis();
	final int MOD = 1000000007;
	int[] dx = { 1, 0, 0, -1 };
	int[] dy = { 0, 1, -1, 0 };

	char[] d1 = { '-', '|' };
	char[] d2 = { '^', '>', 'v', '<' };
	char[] d3 = { 'L', 'U', 'R', 'D' };

	Map<Character, Integer> map = new HashMap<Character, Integer>() {
		{
			put('*', Integer.valueOf("0000", 2));
		}
		{
			put('+', Integer.valueOf("1111", 2));
		}
		{
			put('-', Integer.valueOf("0101", 2));
		}
		{
			put('|', Integer.valueOf("1010", 2));
		}
		{
			put('^', Integer.valueOf("0010", 2));
		}
		{
			put('>', Integer.valueOf("0001", 2));
		}
		{
			put('v', Integer.valueOf("1000", 2));
		}
		{
			put('<', Integer.valueOf("0100", 2));
		}
		{
			put('L', Integer.valueOf("1011", 2));
		}
		{
			put('U', Integer.valueOf("1101", 2));
		}
		{
			put('R', Integer.valueOf("1110", 2));
		}
		{
			put('D', Integer.valueOf("0111", 2));
		}
	};

	void run() {
		int h = sc.nextInt();
		int w = sc.nextInt();
		char[][] f = sc.id3(h, w);
		int[][][] c = new int[h][w][4];
		for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) Arrays.fill(c[i][j], Integer.MAX_VALUE / 10);
		int th = sc.nextInt() - 1;
		int tw = sc.nextInt() - 1;
		int mh = sc.nextInt() - 1;
		int mw = sc.nextInt() - 1;
		c[th][tw][0] = 0;
		LinkedList<Pos> que = new LinkedList<>();
		que.add(new Pos(th, tw, 0));
		int res = Integer.MAX_VALUE / 10;
		while (!que.isEmpty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				Pos now = que.poll();
				if (now.nh == mh && now.nw == mw)
					res = Math.min(res, c[now.nh][now.nw][now.deg]);
				

				if (inner(now.nh - 1, now.nw, h, w)) {
					boolean from = false;
					boolean to = false;
					if (!(f[now.nh][now.nw] == '*' || f[now.nh - 1][now.nw] == '*')) {
						if (f[now.nh][now.nw] == '+')
							from = true;
						if (f[now.nh - 1][now.nw] == '+')
							to = true;
						int deg = -1;
						

						deg = getDirection(d1, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 1) > 0)
								from |= true;
						deg = getDirection(d2, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 1) > 0)
								from |= true;
						deg = getDirection(d3, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 1) > 0)
								from |= true;

						

						deg = getDirection(d1, f[now.nh - 1][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 3) > 0)
								to |= true;
						deg = getDirection(d2, f[now.nh - 1][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 3) > 0)
								to |= true;
						deg = getDirection(d3, f[now.nh - 1][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 3) > 0)
								to |= true;

						if (from && to && c[now.nh - 1][now.nw][now.deg] > c[now.nh][now.nw][now.deg] + 1) {
							c[now.nh - 1][now.nw][now.deg] = c[now.nh][now.nw][now.deg] + 1;
							que.add(new Pos(now.nh - 1, now.nw, now.deg));
						}
					}
				}
				

				if (inner(now.nh, now.nw + 1, h, w)) {
					boolean from = false;
					boolean to = false;
					if (!(f[now.nh][now.nw] == '*' || f[now.nh][now.nw + 1] == '*')) {
						if (f[now.nh][now.nw] == '+')
							from = true;
						if (f[now.nh][now.nw + 1] == '+')
							to = true;
						int deg = -1;
						

						deg = getDirection(d1, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 0) > 0)
								from |= true;
						deg = getDirection(d2, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 0) > 0)
								from |= true;
						deg = getDirection(d3, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 0) > 0)
								from |= true;

						

						deg = getDirection(d1, f[now.nh][now.nw + 1], now.deg);
						if (deg != -1)
							if ((deg & 1 << 2) > 0)
								to |= true;
						deg = getDirection(d2, f[now.nh][now.nw + 1], now.deg);
						if (deg != -1)
							if ((deg & 1 << 2) > 0)
								to |= true;
						deg = getDirection(d3, f[now.nh][now.nw + 1], now.deg);
						if (deg != -1)
							if ((deg & 1 << 2) > 0)
								to |= true;

						if (from && to && c[now.nh][now.nw + 1][now.deg] > c[now.nh][now.nw][now.deg] + 1) {
							c[now.nh][now.nw + 1][now.deg] = c[now.nh][now.nw][now.deg] + 1;
							que.add(new Pos(now.nh, now.nw + 1, now.deg));
						}
					}
				}
				

				if (inner(now.nh, now.nw - 1, h, w)) {
					boolean from = false;
					boolean to = false;
					if (!(f[now.nh][now.nw] == '*' || f[now.nh][now.nw - 1] == '*')) {
						if (f[now.nh][now.nw] == '+')
							from = true;
						if (f[now.nh][now.nw - 1] == '+')
							to = true;
						int deg = -1;
						

						deg = getDirection(d1, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 2) > 0)
								from |= true;
						deg = getDirection(d2, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 2) > 0)
								from |= true;
						deg = getDirection(d3, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 2) > 0)
								from |= true;

						

						deg = getDirection(d1, f[now.nh][now.nw - 1], now.deg);
						if (deg != -1)
							if ((deg & 1 << 0) > 0)
								to |= true;
						deg = getDirection(d2, f[now.nh][now.nw - 1], now.deg);
						if (deg != -1)
							if ((deg & 1 << 0) > 0)
								to |= true;
						deg = getDirection(d3, f[now.nh][now.nw - 1], now.deg);
						if (deg != -1)
							if ((deg & 1 << 0) > 0)
								to |= true;

						if (from && to && c[now.nh][now.nw - 1][now.deg] > c[now.nh][now.nw][now.deg] + 1) {
							c[now.nh][now.nw - 1][now.deg] = c[now.nh][now.nw][now.deg] + 1;
							que.add(new Pos(now.nh, now.nw - 1, now.deg));
						}
					}
				}
				

				if (inner(now.nh + 1, now.nw, h, w)) {
					boolean from = false;
					boolean to = false;
					if (!(f[now.nh][now.nw] == '*' || f[now.nh + 1][now.nw] == '*')) {
						if (f[now.nh][now.nw] == '+') from = true;
						if (f[now.nh + 1][now.nw] == '+') to = true;
						int deg = -1;
						

						deg = getDirection(d1, f[now.nh][now.nw], now.deg);
						if (deg != -1) if ((deg & 1 << 3) > 0) from |= true;
						deg = getDirection(d2, f[now.nh][now.nw], now.deg);
						if (deg != -1) {
							if ((deg & 1 << 3) > 0) from |= true;
						}
						deg = getDirection(d3, f[now.nh][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 3) > 0)
								from |= true;

						

						deg = getDirection(d1, f[now.nh + 1][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 1) > 0)
								to |= true;
						deg = getDirection(d2, f[now.nh + 1][now.nw], now.deg); 
						if (deg != -1) if ((deg & 1 << 1) > 0) to |= true;
						deg = getDirection(d3, f[now.nh + 1][now.nw], now.deg);
						if (deg != -1)
							if ((deg & 1 << 1) > 0)
								to |= true;
						if (from && to && c[now.nh + 1][now.nw][now.deg] > c[now.nh][now.nw][now.deg] + 1) {
							c[now.nh + 1][now.nw][now.deg] = c[now.nh][now.nw][now.deg] + 1;
							que.add(new Pos(now.nh + 1, now.nw, now.deg));
						}
					}
				}
				

				if (c[now.nh][now.nw][(now.deg + 1) % 4] > c[now.nh][now.nw][now.deg] + 1) {
					c[now.nh][now.nw][(now.deg + 1) % 4] = c[now.nh][now.nw][now.deg] + 1;
					que.add(new Pos(now.nh, now.nw, (now.deg + 1) % 4));
				}
			}
		}
		System.out.println(res == Integer.MAX_VALUE / 10 ? -1 : res);
	}

	class Pos {
		int nh;
		int nw;
		int deg;

		public Pos(int nh, int nw, int deg) {
			super();
			this.nh = nh;
			this.nw = nw;
			this.deg = deg;
		}
		
		void show() {
			System.out.println("h = " + this.nh +" w = " + this.nw +" deg = " + this.deg);
		}
	}

	int getDirection(char[] c, char d, int rotate) {
		int f = -1;
		for (int i = 0; i < c.length; i++) if (c[i] == d) f = i;
		if (f == -1)
			return f;
		return map.get(c[(f + rotate) % c.length]);
	}

	public static void main(String[] args) {
		new Main().run();
	}

	void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	void debug2(char[][] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[i].length; j++) {
				System.out.print(array[i][j]);
			}
			System.out.println();
		}
	}

	boolean inner(int h, int w, int limH, int limW) {
		return 0 <= h && h < limH && 0 <= w && w < limW;
	}

	void swap(int[] x, int a, int b) {
		int tmp = x[a];
		x[a] = x[b];
		x[b] = tmp;
	}

	

	int lower_bound(int a[], int k) {
		int l = -1;
		int r = a.length;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (k <= a[mid])
				r = mid;
			else
				l = mid;
		}
		

		return r;
	}

	

	int upper_bound(int a[], int k) {
		int l = -1;
		int r = a.length;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (k < a[mid])
				r = mid;
			else
				l = mid;
		}
		

		return r;
	}

	long gcd(long a, long b) {
		return a % b == 0 ? b : gcd(b, a % b);
	}

	long lcm(long a, long b) {
		return a * b / gcd(a, b);
	}

	boolean palindrome(String s) {
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}

	class MyScanner {
		int nextInt() {
			try {
				int c = System.in.read();
				while (c != '-' && (c < '0' || '9' < c))
					c = System.in.read();
				if (c == '-')
					return -nextInt();
				int res = 0;
				do {
					res *= 10;
					res += c - '0';
					c = System.in.read();
				} while ('0' <= c && c <= '9');
				return res;
			} catch (Exception e) {
				return -1;
			}
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		String next() {
			try {
				StringBuilder res = new StringBuilder("");
				int c = System.in.read();
				while (Character.isWhitespace(c))
					c = System.in.read();
				do {
					res.append((char) c);
				} while (!Character.isWhitespace(c = System.in.read()));
				return res.toString();
			} catch (Exception e) {
				return null;
			}
		}

		int[] id1(int n) {
			int[] in = new int[n];
			for (int i = 0; i < n; i++) {
				in[i] = nextInt();
			}
			return in;
		}

		int[][] id0(int n, int m) {
			int[][] in = new int[n][m];
			for (int i = 0; i < n; i++) {
				in[i] = id1(m);
			}
			return in;
		}

		double[] id2(int n) {
			double[] in = new double[n];
			for (int i = 0; i < n; i++) {
				in[i] = nextDouble();
			}
			return in;
		}

		long[] id4(int n) {
			long[] in = new long[n];
			for (int i = 0; i < n; i++) {
				in[i] = nextLong();
			}
			return in;
		}

		char[][] id3(int n, int m) {
			char[][] in = new char[n][m];
			for (int i = 0; i < n; i++) {
				String s = sc.next();
				for (int j = 0; j < m; j++) {
					in[i][j] = s.charAt(j);
				}
			}
			return in;
		}
	}
}