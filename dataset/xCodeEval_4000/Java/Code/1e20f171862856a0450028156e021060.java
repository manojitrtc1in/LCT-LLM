import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Input in = new Input(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
	final static long MOD = (long) 1e9 + 7;
	int[] primes;
	long[] factorials;
	int[] dx = new int[] { 0, 0, 1, -1 };
	int[] dy = new int[] { 1, -1, 0, 0 };

	void solve(int testNumber, Input in, PrintWriter out) {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		for (int i = 0; i < n; i++)
			a[i] += i;
		Arrays.sort(a);
		for (int i = 1; i < n; i++) {
			if (a[i - 1] >= a[i]) {
				out.println(":(");
				return;
			}
		}
		for (int i = 0; i < n; i++) {
			out.print((a[i] - i) + " ");
		}
		out.println();
	}

	int[] getLowestPrimeFactors(int n) {
		int lim = n + 1;
		int[] lowestPrimeFactors = new int[lim];
		boolean[] flags = new boolean[lim];
		for (int i = 2; i < lim; i += 2) {
			lowestPrimeFactors[i] = 2;
		}
		for (int i = 3; i < lim; i += 2) {
			if (!flags[i]) {
				lowestPrimeFactors[i] = i;
				for (int j = i; (long) j * i < lim; j += 2) {
					if (!flags[i * j]) {
						flags[i * j] = true;
						lowestPrimeFactors[i * j] = i;
					}

				}
			}
		}
		return lowestPrimeFactors;
	}

	private int lowerBound(int[] marks, int x) {
		int left = 0;
		int right = marks.length;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (marks[mid] <= x) {
				left = mid + 1;
			} else {
				right = mid;
			}

		}
		return left;
	}

	public int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static boolean nextPermutation(int[] p) {
		for (int a = p.length - 2; a >= 0; --a)
			if (p[a] < p[a + 1])
				for (int b = p.length - 1;; --b)
					if (p[b] > p[a]) {
						int t = p[a];
						p[a] = p[b];
						p[b] = t;
						for (++a, b = p.length - 1; a < b; ++a, --b) {
							t = p[a];
							p[a] = p[b];
							p[b] = t;
						}
						return true;
					}
		return false;
	}

	static void generatePermutations(int[] p, int depth) {
		int n = p.length;
		if (depth == n) {
			System.out.println(Arrays.toString(p));
			return;
		}
		for (int i = 0; i < n; i++) {
			if (p[i] == 0) {
				p[i] = depth;
				generatePermutations(p, depth + 1);
				p[i] = 0;
			}
		}
	}

	long[][] matrixPow(long[][] a, long ex) {
		long[][] res = matrixUnit(a.length);
		if (ex == 0)
			return res;
		while (ex > 0) {
			if ((ex & 1) == 1) {
				res = matrixMul(res, a);
			}
			a = matrixMul(a, a);
			ex >>= 1L;
		}
		return res;
	}

	long[][] matrixMul(long[][] a, long[][] b) {
		int r = a.length;
		int c = b[0].length;
		int l = a[0].length;
		long[][] res = new long[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				for (int k = 0; k < l; k++) {
					res[i][j] += a[i][k] * b[k][j] % MOD;
					res[i][j] %= MOD;
				}
			}
		}
		return res;
	}

	long[][] matrixUnit(int n) {
		long[][] unit = new long[n][n];
		for (int i = 0; i < n; i++)
			unit[i][i] = 1;
		return unit;
	}

	long[] getSumAndNumberOfDivisors(int n) {
		int lim = primes.length;
		long[] res = new long[2];
		long numberOfDivisor = 1;
		long sumOfDivisor = 1;
		for (int i = 0; i < lim; i++) {
			int p = primes[i];
			long ex = 0;
			long cur = 1;
			while (n % p == 0) {
				n /= p;
				ex++;
				cur += Math.pow(p, ex);
			}
			numberOfDivisor *= (ex + 1);
			sumOfDivisor *= cur;
			if (n == 1)
				break;
		}
		if (n > 1) {
			numberOfDivisor <<= 1L;
			sumOfDivisor *= (long) (n + 1);
		}
		res[0] = numberOfDivisor;
		res[1] = sumOfDivisor;
		return res;
	}

	boolean isQuare(int[][] m) {
		long[] dist = new long[6];
		int index = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				dist[index++] = dist(m[i][0], m[i][1], m[j][0], m[j][1]);
			}
		}
		Arrays.sort(dist);
		if (dist[0] == 0 || dist[5] == 0)
			return false;
		for (int i = 0; i < 2; i++) {
			if (dist[i] != dist[i + 1])
				return false;
		}

		return dist[4] == dist[5];
	}

	long dist(long x1, long y1, long x2, long y2) {
		return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	}

	void rotate(int[][] m, int row) {
		int x = m[row][0] - m[row][2];
		int y = m[row][1] - m[row][3];
		m[row][0] = m[row][2] - y;
		m[row][1] = m[row][3] + x;
	}

	class BIT {
		int[] MAX;
		int[] MIN;
		int[] SUM;
		int n;

		public BIT(int n) {
			MAX = new int[n + 1];
			MIN = new int[n + 1];
			SUM = new int[n + 1];
			this.n = n + 1;
		}

		public void setSum(int pos, int val) {
			for (int i = pos; i < n; i += (i & -i)) {
				SUM[i] += val;
			}
		}

		public int getSum(int to) {
			int sum = 0;
			for (int i = to; i > 0; i -= (i & -i)) {
				sum += SUM[i];
			}
			return sum;
		}

		public int getSum(int from, int to) {
			return getSum(to) - getSum(from);
		}

		public void setMax(int pos, int val) {
			for (int i = pos; i < n; i += (i & -i)) {
				MAX[i] = Math.max(val, MAX[i]);
			}
		}

		public int getMax(int to) {
			int max = 0;
			for (int i = to; i > 0; i -= (i & -i)) {
				max = Math.max(max, MAX[i]);
			}
			return max;
		}

		public void setMin(int pos, int val) {
			for (int i = pos; i < n; i += (i & -i)) {
				MIN[i] = Math.min(val, MIN[i]);
			}
		}

		public int getMin(int to) {
			int min = 0;
			for (int i = to; i > 0; i -= (i & -i)) {
				min = Math.min(min, MIN[i]);
			}
			return min;
		}

	}

	class DisjointSet {
		int[] set;

		public DisjointSet(int n) {
			set = new int[n];
			for (int i = 0; i < n; i++) {
				set[i] = i;
			}
		}

		public int findSet(int a) {
			if (set[a] == a)
				return a;
			return set[a] = findSet(set[a]);
		}

		public void unionSet(int a, int b) {
			set[findSet(a)] = findSet(b);
		}

		public boolean isSameSet(int a, int b) {
			return findSet(a) == findSet(b);
		}
	}

	class SegmentTree {
		int[] MAX;
		int[] MIN;
		int[] SUM;
		int[] data;
		int n;

		SegmentTree(int[] data) {
			this.n = data.length;
			this.data = data;
			MAX = new int[4 * n + 10];
			MIN = new int[4 * n + 10];
			SUM = new int[4 * n + 10];
			buildTree(1, 0, n - 1);
		}

		int left(int root) {
			return root << 1;
		}

		int right(int root) {
			return (root << 1) + 1;
		}

		void buildTree(int root, int rl, int rr) {
			if (rr == rl) {
				MAX[root] = MIN[root] = SUM[root] = data[rr];
			} else {
				int rm = (rl + rr) >> 1;
				buildTree(left(root), rl, rm);
				buildTree(right(root), rm + 1, rr);
				MAX[root] = Math.max(MAX[left(root)], MAX[right(root)]);
				MIN[root] = Math.min(MIN[left(root)], MIN[right(root)]);
				SUM[root] = SUM[left(root)] + SUM[right(root)];
			}
		}

		void set(int pos, int val) {
			set(1, 0, n - 1, pos, val);
		}

		

		private void set(int root, int rl, int rr, int pos, int val) {
			if (rl > rr || pos > rr || pos < rl)
				return;
			if (rl == rr) {
				MAX[root] = MIN[root] = SUM[root] = val;
			} else {
				int mid = (rl + rr) >> 1;
				set(left(root), rl, mid, pos, val);
				set(right(root), rl, mid, pos, val);
				MAX[root] = Math.max(MAX[left(root)], MAX[right(root)]);
				MIN[root] = Math.min(MIN[left(root)], MIN[right(root)]);
				SUM[root] = SUM[left(root)] + SUM[right(root)];
			}
		}

		int getMax(int from, int to) {
			return getMax(1, 0, n - 1, from, to);
		}

		int getMax(int root, int rl, int rr, int from, int to) {
			if (from > rr || to < rl || rl > rr) {
				return -1;
			}
			if (from == rl && to == rr) {
				return MAX[root];
			}
			int rm = (rr + rl) >> 1;
			int m1 = getMax(left(root), rl, rm, from, Math.min(to, rm));
			int m2 = getMax(right(root), rm + 1, rr, Math.max(from, rm + 1), to);
			return Math.max(m1, m2);
		}

		int getMin(int from, int to) {
			return getMin(1, 0, n - 1, from, to);
		}

		int getMin(int root, int rl, int rr, int from, int to) {
			if (from > rr || to < rl || rl > rr) {
				return Integer.MAX_VALUE;
			}
			if (from == rl && to == rr) {
				return MIN[root];
			}
			int rm = (rr + rl) >> 1;
			int m1 = getMin(left(root), rl, rm, from, Math.min(to, rm));
			int m2 = getMin(right(root), rm + 1, rr, Math.max(from, rm + 1), to);
			return Math.min(m1, m2);
		}

		int getSum(int from, int to) {
			return getSum(1, 0, n - 1, from, to);
		}

		int getSum(int root, int rl, int rr, int from, int to) {
			if (from > rr || to < rl || rl > rr) {
				return 0;
			}
			if (from == rl && to == rr) {
				return SUM[root];
			}
			int rm = (rr + rl) >> 1;
			int m1 = getSum(left(root), rl, rm, from, Math.min(to, rm));
			int m2 = getSum(right(root), rm + 1, rr, Math.max(from, rm + 1), to);
			return m1 + m2;
		}
	}

	static String lcs(String s1, String s2) {
		int n = s1.length();
		int m = s2.length();
		int[][] dp = new int[n + 1][m + 1];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		int i = n;
		int j = m;
		while (i > 0 && j > 0) {
			if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
				sb.append(s1.charAt(i - 1));
				i--;
				j--;
			} else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					i--;
				} else {
					j--;
				}
			}
		}
		return sb.reverse().toString();
	}

	static boolean isPrime(int n) {
		if (n <= 3)
			return n > 1;
		else if (n % 3 == 0 || n % 2 == 0)
			return false;
		for (long i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		}
		return true;
	}

	static int[] getPrimes(int n) {
		int len = n + 1;
		boolean[] isPrimes = new boolean[len];
		int[] temps = new int[len];
		int index = 0;
		Arrays.fill(isPrimes, true);
		isPrimes[0] = isPrimes[1] = false;
		for (int i = 2; i * i < len; i++) {
			if (isPrimes[i]) {
				for (int j = i * i; j < len; j += i) {
					isPrimes[j] = false;
				}
			}
		}
		for (int i = 0; i < len; i++) {
			if (isPrimes[i])
				temps[index++] = i;
		}
		int[] primes = Arrays.copyOf(temps, index);
		return primes;
	}

	static void swap(char[] arrays, int pos1, int pos2) {
		char tmp = arrays[pos1];
		arrays[pos1] = arrays[pos2];
		arrays[pos2] = tmp;
	}

	static void swap(int[] arrays, int pos1, int pos2) {
		int tmp = arrays[pos1];
		arrays[pos1] = arrays[pos2];
		arrays[pos2] = tmp;
	}

	long modPow(long n, long ex) {
		long res = 1;
		while (ex > 0) {
			if ((ex & 1) == 1)
				res = res * n % MOD;
			n = n * n % MOD;
			ex >>= 1;
		}
		return res;
	}

	long ModInverse(long n) {
		return modPow(n, MOD - 2);
	}

	void genFactorial(int n) {
		factorials = new long[n + 1];
		factorials[0] = 1;
		for (int i = 1; i <= n; i++) {
			factorials[i] = factorials[i - 1] * i;
			factorials[i] %= MOD;
		}
	}

	long nCr(int n, int r) {
		if (r > n)
			return -1;
		return (factorials[n] * ModInverse((factorials[r] * factorials[n - r])
				% MOD))
				% MOD;
		

	}

	static class Pair<K, V> {
		private K key;
		private V value;

		public K getKey() {
			return this.key;
		}

		public V getValue() {
			return this.value;
		}

		public Pair(K var1, V var2) {
			this.key = var1;
			this.value = var2;
		}

		public String toString() {
			return this.key + "=" + this.value;
		}

		public int hashCode() {
			return this.key.hashCode() * 13
					+ (this.value == null ? 0 : this.value.hashCode());
		}

		public boolean equals(Object var1) {
			if (this == var1) {
				return true;
			} else if (!(var1 instanceof Pair)) {
				return false;
			} else {
				Pair var2 = (Pair) var1;
				if (this.key != null) {
					if (!this.key.equals(var2.key)) {
						return false;
					}
				} else if (var2.key != null) {
					return false;
				}

				if (this.value != null) {
					if (!this.value.equals(var2.value)) {
						return false;
					}
				} else if (var2.value != null) {
					return false;
				}

				return true;
			}
		}
	}
}

class Input {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public Input(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String nextLine() {
		String s = "";
		try {
			s = reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return s;
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
