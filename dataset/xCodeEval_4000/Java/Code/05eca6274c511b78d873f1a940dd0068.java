

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		try {
			int t = sc.nextInt();
			while (t-- > 0)
				solve();
		} catch (Exception e) {
			return;
		}
		out.flush();
	}

	

	

	static void solve() {
		int r = sc.nextInt();
		int c = sc.nextInt();
		int x = (r + 1) / 2, y = (c + 1) / 2;
		int st = Math.abs(r - x) + Math.abs(c - y);
		int a[][] = new int[r + 1][c + 1];
		boolean[][] vis = new boolean[r + 1][c + 1];
		Queue<int[]> q = new LinkedList<>();
		if (r % 2 == 0 && c % 2 == 0) {
			a[r / 2][c / 2] = st;
			a[(r / 2) + 1][(c / 2) + 1] = st;
			a[r / 2][(c / 2) + 1] = st;
			a[(r / 2) + 1][c / 2] = st;

			q.add(new int[] { r / 2, c / 2 });
			q.add(new int[] { (r / 2) + 1, (c / 2) + 1 });
			q.add(new int[] { r / 2, (c / 2) + 1 });
			q.add(new int[] { (r / 2) + 1, c / 2 });

			vis[r / 2][c / 2] = true;
			vis[(r / 2) + 1][(c / 2) + 1] = true;
			vis[r / 2][(c / 2) + 1] = true;
			vis[(r / 2) + 1][c / 2] = true;
		} else if (r % 2 != 0 && c % 2 != 0) {
			a[(r + 1) / 2][(c + 1) / 2] = st;
			q.add(new int[] { (r + 1) / 2, (c + 1) / 2 });
			vis[(r + 1) / 2][(c + 1) / 2] = true;
		} else if (r % 2 == 0 && c % 2 != 0) {
			a[r / 2][(c + 1) / 2] = st;
			a[(r / 2) + 1][(c + 1) / 2] = st;
			q.add(new int[] { r / 2, (c + 1) / 2 });
			q.add(new int[] { (r / 2) + 1, (c + 1) / 2 });
			vis[r / 2][(c + 1) / 2] = true;
			vis[(r / 2) + 1][(c + 1) / 2] = true;
		} else if (r % 2 != 0 && c % 2 == 0) {
			a[(r + 1) / 2][(c / 2) + 1] = st;
			a[(r + 1) / 2][c / 2] = st;
			q.add(new int[] { (r + 1) / 2, (c / 2) + 1 });
			q.add(new int[] { (r + 1) / 2, c / 2 });
			vis[(r + 1) / 2][(c / 2) + 1] = true;
			vis[(r + 1) / 2][c / 2] = true;
		}
		int dir[][] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
		ArrayList<Integer> ans = new ArrayList<>();
		while (!q.isEmpty()) {
			int size = q.size();
			while (size-- > 0) {
				int[] curr = q.remove();
				ans.add(a[curr[0]][curr[1]]);
				for (int d[] : dir) {
					int newX = d[0] + curr[0];
					int newY = d[1] + curr[1];
					if (newX <= 0 || newY <= 0 || newX > r || newY > c)
						continue;
					if (vis[newX][newY])
						continue;
					a[newX][newY] = a[curr[0]][curr[1]] + 1;
					q.add(new int[] { newX, newY });
					vis[newX][newY] = true;
				}
			}
		}
		Collections.sort(ans);
		for (int i : ans)
			System.out.print(i + " ");
		System.out.println();
	}

	

	

	static class DSU {
		int rank[];
		int parent[];

		DSU(int n) {
			rank = new int[n + 1];
			parent = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				parent[i] = i;
			}
		}

		int findParent(int node) {
			if (parent[node] == node)
				return node;
			return parent[node] = findParent(parent[node]);
		}

		boolean union(int x, int y) {
			int px = findParent(x);
			int py = findParent(y);
			if (px == py)
				return false;
			if (rank[px] < rank[py]) {
				parent[px] = py;
			} else if (rank[px] > rank[py]) {
				parent[py] = px;
			} else {
				parent[px] = py;
				rank[py]++;
			}
			return true;
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l = new ArrayList<>();
		for (int i : a)
			l.add(i);
		Collections.sort(l);
		for (int i = 0; i < a.length; i++)
			a[i] = l.get(i);
	}

	static boolean[] seiveOfEratosthenes(int n) {
		boolean[] isPrime = new boolean[n + 1];
		Arrays.fill(isPrime, true);
		for (int i = 2; i * i <= n; i++) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
		return isPrime;
	}

	static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static boolean isPrime(long n) {
		if (n < 2)
			return false;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
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

		char[][] readCharMatrix(int n, int m) {
			char a[][] = new char[n][m];
			for (int i = 0; i < n; i++) {
				String s = sc.next();
				for (int j = 0; j < m; j++) {
					a[i][j] = s.charAt(j);
				}
			}
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		int[] readIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = Integer.parseInt(next());
			}
			return a;
		}

		void printIntArray(int a[]) {
			for (int i = 0; i < a.length; i++) {
				System.out.print(a[i] + " ");
			}
		}

		long[] readLongArray(int n) {
			long a[] = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = Long.parseLong(next());
			}
			return a;
		}

		void printLongArray(long a[]) {
			for (int i = 0; i < a.length; i++) {
				System.out.print(a[i] + " ");
			}
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
	}

	public static class FastWriter {
		private static final int BUF_SIZE = 1 << 13;
		private final byte[] buf = new byte[BUF_SIZE];
		private final OutputStream out;
		private int ptr = 0;

		private FastWriter() {
			out = null;
		}

		public FastWriter(OutputStream os) {
			this.out = os;
		}

		public FastWriter(String path) {
			try {
				this.out = new FileOutputStream(path);
			} catch (FileNotFoundException e) {
				throw new RuntimeException("FastWriter");
			}
		}

		public FastWriter write(byte b) {
			buf[ptr++] = b;
			if (ptr == BUF_SIZE)
				innerflush();
			return this;
		}

		public FastWriter write(char c) {
			return write((byte) c);
		}

		public FastWriter write(char[] s) {
			for (char c : s) {
				buf[ptr++] = (byte) c;
				if (ptr == BUF_SIZE)
					innerflush();
			}
			return this;
		}

		public FastWriter write(String s) {
			s.chars().forEach(c -> {
				buf[ptr++] = (byte) c;
				if (ptr == BUF_SIZE)
					innerflush();
			});
			return this;
		}

		private static int countDigits(int l) {
			if (l >= 1000000000)
				return 10;
			if (l >= 100000000)
				return 9;
			if (l >= 10000000)
				return 8;
			if (l >= 1000000)
				return 7;
			if (l >= 100000)
				return 6;
			if (l >= 10000)
				return 5;
			if (l >= 1000)
				return 4;
			if (l >= 100)
				return 3;
			if (l >= 10)
				return 2;
			return 1;
		}

		public FastWriter write(int x) {
			if (x == Integer.MIN_VALUE) {
				return write((long) x);
			}
			if (ptr + 12 >= BUF_SIZE)
				innerflush();
			if (x < 0) {
				write((byte) '-');
				x = -x;
			}
			int d = countDigits(x);
			for (int i = ptr + d - 1; i >= ptr; i--) {
				buf[i] = (byte) ('0' + x % 10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		private static int countDigits(long l) {
			if (l >= 1000000000000000000L)
				return 19;
			if (l >= 100000000000000000L)
				return 18;
			if (l >= 10000000000000000L)
				return 17;
			if (l >= 1000000000000000L)
				return 16;
			if (l >= 100000000000000L)
				return 15;
			if (l >= 10000000000000L)
				return 14;
			if (l >= 1000000000000L)
				return 13;
			if (l >= 100000000000L)
				return 12;
			if (l >= 10000000000L)
				return 11;
			if (l >= 1000000000L)
				return 10;
			if (l >= 100000000L)
				return 9;
			if (l >= 10000000L)
				return 8;
			if (l >= 1000000L)
				return 7;
			if (l >= 100000L)
				return 6;
			if (l >= 10000L)
				return 5;
			if (l >= 1000L)
				return 4;
			if (l >= 100L)
				return 3;
			if (l >= 10L)
				return 2;
			return 1;
		}

		public FastWriter write(long x) {
			if (x == Long.MIN_VALUE) {
				return write("" + x);
			}
			if (ptr + 21 >= BUF_SIZE)
				innerflush();
			if (x < 0) {
				write((byte) '-');
				x = -x;
			}
			int d = countDigits(x);
			for (int i = ptr + d - 1; i >= ptr; i--) {
				buf[i] = (byte) ('0' + x % 10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		public FastWriter write(double x, int precision) {
			if (x < 0) {
				write('-');
				x = -x;
			}
			x += Math.pow(10, -precision) / 2;
			

			write((long) x).write(".");
			x -= (long) x;
			for (int i = 0; i < precision; i++) {
				x *= 10;
				write((char) ('0' + (int) x));
				x -= (int) x;
			}
			return this;
		}

		public FastWriter writeln(char c) {
			return write(c).writeln();
		}

		public FastWriter writeln(int x) {
			return write(x).writeln();
		}

		public FastWriter writeln(long x) {
			return write(x).writeln();
		}

		public FastWriter writeln(double x, int precision) {
			return write(x, precision).writeln();
		}

		public FastWriter write(int... xs) {
			boolean first = true;
			for (int x : xs) {
				if (!first)
					write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter write(long... xs) {
			boolean first = true;
			for (long x : xs) {
				if (!first)
					write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter writeln() {
			return write((byte) '\n');
		}

		public FastWriter writeln(int... xs) {
			return write(xs).writeln();
		}

		public FastWriter writeln(long... xs) {
			return write(xs).writeln();
		}

		public FastWriter writeln(char[] line) {
			return write(line).writeln();
		}

		public FastWriter writeln(char[]... map) {
			for (char[] line : map)
				write(line).writeln();
			return this;
		}

		public FastWriter writeln(String s) {
			return write(s).writeln();
		}

		private void innerflush() {
			try {
				out.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new RuntimeException("innerflush");
			}
		}

		public void flush() {
			innerflush();
			try {
				out.flush();
			} catch (IOException e) {
				throw new RuntimeException("flush");
			}
		}

		public FastWriter print(byte b) {
			return write(b);
		}

		public FastWriter print(char c) {
			return write(c);
		}

		public FastWriter print(char[] s) {
			return write(s);
		}

		public FastWriter print(String s) {
			return write(s);
		}

		public FastWriter print(int x) {
			return write(x);
		}

		public FastWriter print(long x) {
			return write(x);
		}

		public FastWriter print(double x, int precision) {
			return write(x, precision);
		}

		public FastWriter println(char c) {
			return writeln(c);
		}

		public FastWriter println(int x) {
			return writeln(x);
		}

		public FastWriter println(long x) {
			return writeln(x);
		}

		public FastWriter println(double x, int precision) {
			return writeln(x, precision);
		}

		public FastWriter print(int... xs) {
			return write(xs);
		}

		public FastWriter print(long... xs) {
			return write(xs);
		}

		public FastWriter println(int... xs) {
			return writeln(xs);
		}

		public FastWriter println(long... xs) {
			return writeln(xs);
		}

		public FastWriter println(char[] line) {
			return writeln(line);
		}

		public FastWriter println(char[]... map) {
			return writeln(map);
		}

		public FastWriter println(String s) {
			return writeln(s);
		}

		public FastWriter println() {
			return writeln();
		}
	}

	private static final FastReader sc = new FastReader();
	private static final FastWriter out = new FastWriter(System.out);

}
