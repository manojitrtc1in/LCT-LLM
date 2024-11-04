import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;





public class Main {
	static final long MOD1=1000000007;
	static final long MOD=998244353;
	static final int NTT_MOD1 = 998244353;
	static final int NTT_MOD2 = 1053818881;
	static final int NTT_MOD3 = 1004535809;
	static long MAX = 1000000000000000000l;

	static int index = 2;
	public static void main(String[] args){
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int t = sc.nextInt();
		long MOD = 1000000007;
		for (int i = 0; i < t; i++) {
			String S = sc.next();
			String T = sc.next();
			out.println(solve(S, T, MOD));
 		}
		out.flush();
   	}
	static String solve(String S, String T, long MOD) {
		StringBuilder sb = new StringBuilder(T);
		sb.append("#");
		sb.append(S);
		int n = S.length();
		int m = T.length();
		int[] Z = StringAlgorithm.zAlgorithm(String.valueOf(sb));
		long[][] dp = new long[n + 1][n + 1];
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				if(dp[i][j] == 0) continue;
				if (Z[m + 1 + i] == m) {
					for (int j2 = 0; j2 < m; j2++) {
						if (i + j2 < n && Z[m + 1 + i + j2] == m) {
							dp[i + j2 + m][j + 1] = (dp[i + j2 + m][j + 1] + dp[i][j]) % MOD; 
 						}
					}
				}else {
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			if (dp[n][i] > 0) {
				return i + " " + dp[n][i];
			}
		}
		return null;
	}
	static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
		public double[] nextDoubleArray(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; i++)
				a[i] = nextDouble();
			return a;
		}
		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}


class StringAlgorithm {
	private static int[] saNaive(int[] s) {
		int n = s.length;
		Integer[] _sa = new Integer[n];
		for (int i = 0; i < n; i++) {
			_sa[i] = i;
		}
		java.util.Arrays.sort(_sa, (l, r) -> {
			while (l < n && r < n) {
				if (s[l] != s[r]) return s[l] - s[r];
				l++;
				r++;
			}
			return -(l - r);
		});
		int[] sa = new int[n];
		for (int i = 0; i < n; i++) {
			sa[i] = _sa[i];
		}
		return sa;
	}

	private static int[] saDoubling(int[] s) {
		int n = s.length;
		Integer[] _sa = new Integer[n];
		for (int i = 0; i < n; i++) {
			_sa[i] = i;
		}
		int[] rnk = s;
		int[] tmp = new int[n];

		for (int k = 1; k < n; k *= 2) {
			final int _k = k;
			final int[] _rnk = rnk;
			java.util.Comparator<Integer> cmp = (x, y) -> {
				if (_rnk[x] != _rnk[y]) return _rnk[x] - _rnk[y];
				int rx = x + _k < n ? _rnk[x + _k] : -1;
				int ry = y + _k < n ? _rnk[y + _k] : -1;
				return rx - ry;
			};
			java.util.Arrays.sort(_sa, cmp);
			tmp[_sa[0]] = 0;
			for (int i = 1; i < n; i++) {
				tmp[_sa[i]] = tmp[_sa[i - 1]] + (cmp.compare(_sa[i - 1], _sa[i]) < 0 ? 1 : 0);
			}
			int[] buf = tmp;
			tmp = rnk;
			rnk = buf;
		}

		int[] sa = new int[n];
		for (int i = 0; i < n; i++) {
			sa[i] = _sa[i];
		}
		return sa;
	}

	private static final int THRESHOLD_NAIVE = 10;
	private static final int THRESHOLD_DOUBLING = 40;

	private static int[] sais(int[] s, int upper) {
		int n = s.length;
		if (n == 0) return new int[0];
		if (n == 1) return new int[]{0};
		if (n == 2) {
			if (s[0] < s[1]) {
				return new int[]{0, 1};
			} else {
				return new int[]{1, 0};
			}
		}
		if (n < THRESHOLD_NAIVE) {
			return saNaive(s);
		}
		if (n < THRESHOLD_DOUBLING) {
			return saDoubling(s);
		}

		int[] sa = new int[n];
		boolean[] ls = new boolean[n];
		for (int i = n - 2; i >= 0; i--) {
			ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];
		}

		int[] sumL = new int[upper + 1];
		int[] sumS = new int[upper + 1];

		for (int i = 0; i < n; i++) {
			if (ls[i]) {
				sumL[s[i] + 1]++;
			} else {
				sumS[s[i]]++;
			}
		}

		for (int i = 0; i <= upper; i++) {
			sumS[i] += sumL[i];
			if (i < upper) sumL[i + 1] += sumS[i];
		}

		java.util.function.Consumer<int[]> induce = lms -> {
			java.util.Arrays.fill(sa, -1);
			int[] buf = new int[upper + 1];
			System.arraycopy(sumS, 0, buf, 0, upper + 1);
			for (int d : lms) {
				if (d == n) continue;
				sa[buf[s[d]]++] = d;
			}
			System.arraycopy(sumL, 0, buf, 0, upper + 1);
			sa[buf[s[n - 1]]++] = n - 1;
			for (int i = 0; i < n; i++) {
				int v = sa[i];
				if (v >= 1 && !ls[v - 1]) {
					sa[buf[s[v - 1]]++] = v - 1;
				}
			}
			System.arraycopy(sumL, 0, buf, 0, upper + 1);
			for (int i = n - 1; i >= 0; i--) {
				int v = sa[i];
				if (v >= 1 && ls[v - 1]) {
					sa[--buf[s[v - 1] + 1]] = v - 1;
				}
			}
		};

		int[] lmsMap = new int[n + 1];
		java.util.Arrays.fill(lmsMap, -1);
		int m = 0;
		for (int i = 1; i < n; i++) {
			if (!ls[i - 1] && ls[i]) {
				lmsMap[i] = m++;
			}
		}

		int[] lms = new int[m];
		{
			int p = 0;
			for (int i = 1; i < n; i++) {
				if (!ls[i - 1] && ls[i]) {
					lms[p++] = i;
				}
			}
		}

		induce.accept(lms);

		if (m > 0) {
			int[] sortedLms = new int[m];
			{
				int p = 0;
				for (int v : sa) {
					if (lmsMap[v] != -1) {
						sortedLms[p++] = v;
					}
				}
			}
			int[] recS = new int[m];
			int recUpper = 0;
			recS[lmsMap[sortedLms[0]]] = 0;
			for (int i = 1; i < m; i++) {
				int l = sortedLms[i - 1], r = sortedLms[i];
				int endL = (lmsMap[l] + 1 < m) ? lms[lmsMap[l] + 1] : n;
				int endR = (lmsMap[r] + 1 < m) ? lms[lmsMap[r] + 1] : n;
				boolean same = true;
				if (endL - l != endR - r) {
					same = false;
				} else {
					while (l < endL && s[l] == s[r]) {
						l++;
						r++;
					}
					if (l == n || s[l] != s[r]) same = false;
				}
				if (!same) {
					recUpper++;
				}
				recS[lmsMap[sortedLms[i]]] = recUpper;
			}

			int[] recSA = sais(recS, recUpper);

			for (int i = 0; i < m; i++) {
				sortedLms[i] = lms[recSA[i]];
			}
			induce.accept(sortedLms);
		}
		return sa;
	}

	public static int[] suffixArray(int[] s, int upper) {
		assert (0 <= upper);
		for (int d : s) {
			assert (0 <= d && d <= upper);
		}
		return sais(s, upper);
	}

	public static int[] suffixArray(int[] s) {
		int n = s.length;
		Integer[] idx = new Integer[n];
		for (int i = 0; i < n; i++) {
			idx[i] = i;
		}
		java.util.Arrays.sort(idx, (l, r) -> s[l] - s[r]);
		int[] s2 = new int[n];
		int now = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && s[idx[i - 1]] != s[idx[i]]) {
				now++;
			}
			s2[idx[i]] = now;
		}
		return sais(s2, now);
	}

	public static int[] suffixArray(char[] s) {
		int n = s.length;
		int[] s2 = new int[n];
		for (int i = 0; i < n; i++) {
			s2[i] = s[i];
		}
		return sais(s2, 255);
	}

	public static int[] suffixArray(java.lang.String s) {
		return suffixArray(s.toCharArray());
	}

	public static int[] lcpArray(int[] s, int[] sa) {
		int n = s.length;
		assert (n >= 1);
		int[] rnk = new int[n];
		for (int i = 0; i < n; i++) {
			rnk[sa[i]] = i;
		}
		int[] lcp = new int[n - 1];
		int h = 0;
		for (int i = 0; i < n; i++) {
			if (h > 0) h--;
			if (rnk[i] == 0) {
				continue;
			}
			int j = sa[rnk[i] - 1];
			for (; j + h < n && i + h < n; h++) {
				if (s[j + h] != s[i + h]) break;
			}
			lcp[rnk[i] - 1] = h;
		}
		return lcp;
	}

	public static int[] lcpArray(char[] s, int[] sa) {
		int n = s.length;
		int[] s2 = new int[n];
		for (int i = 0; i < n; i++) {
			s2[i] = s[i];
		}
		return lcpArray(s2, sa);
	}

	public static int[] lcpArray(java.lang.String s, int[] sa) {
		return lcpArray(s.toCharArray(), sa);
	}

	public static int[] zAlgorithm(int[] s) {
		int n = s.length;
		if (n == 0) return new int[0];
		int[] z = new int[n];
		for (int i = 1, j = 0; i < n; i++) {
			int k = j + z[j] <= i ? 0 : Math.min(j + z[j] - i, z[i - j]);
			while (i + k < n && s[k] == s[i + k]) k++;
			z[i] = k;
			if (j + z[j] < i + z[i]) j = i;
		}
		z[0] = n;
		return z;
	}

	public static int[] zAlgorithm(char[] s) {
		int n = s.length;
		if (n == 0) return new int[0];
		int[] z = new int[n];
		for (int i = 1, j = 0; i < n; i++) {
			int k = j + z[j] <= i ? 0 : Math.min(j + z[j] - i, z[i - j]);
			while (i + k < n && s[k] == s[i + k]) k++;
			z[i] = k;
			if (j + z[j] < i + z[i]) j = i;
		}
		z[0] = n;
		return z;
	}

	public static int[] zAlgorithm(String s) {
		return zAlgorithm(s.toCharArray());
	}
}