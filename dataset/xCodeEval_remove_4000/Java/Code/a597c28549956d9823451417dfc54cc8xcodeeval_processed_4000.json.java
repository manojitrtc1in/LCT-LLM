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
	static final int id15 = 998244353;
	static final int id8 = 1053818881;
	static final int id0 = 1004535809;
	static long MAX = 1000000000000000000l;
	public static void main(String[] args){
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		String s = sc.next();
		char[] cs = s.toCharArray();
		int n = s.length();
		int q = sc.nextInt();
		HashMap<String, Integer> map = new HashMap<>();
		int[] Z = StringAlgorithm.zAlgorithm(s);
		for (int i = 1; i < Z.length; i++) {
			if (Z[i] == n - i) {
				StringBuilder sb = new StringBuilder();
				int c = 0;
				for (int j = 0; j < 10; j++) {
					if(Z[i] + j >= cs.length) {
						sb.append(sb.charAt(c));
						c++;
					}else {
						sb.append(cs[Z[i] + j]);
					}
					if(!map.containsKey(String.valueOf(sb))) map.put(String.valueOf(sb), Z[i] + j + 1);
				}
			}
		}
		for (int i = 0; i < q; i++) {
			char[] t = sc.next().toCharArray();
			int[] Z_t = new int[t.length];
			int[] Z_ = StringAlgorithm.zAlgorithm(t);
			for (int j = 0; j < Z_t.length; j++) {
				int k = 0;
				for (int k2 = 0; k2 + j < Z_t.length; k2++) {
					if(k2 >= cs.length) break;
					if(cs[k2] != t[j + k2]) {
						break;
					}
					k++;
				}
				Z_t[j] = k;
			}
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < t.length; j++) {
				sb.append(String.valueOf(t[j]));
				int ans = 0;
				if (map.containsKey(String.valueOf(sb))) ans = map.get(String.valueOf(sb));
				for (int j2 = 0; j2 <= j; j2++) {
					if (Z_t[j2] + j2 >= j + 1) {
						ans = Math.max(ans, j - j2 + 1);
					}
				}
				for (int j2 = 0; j2 < j; j2++) {
					if (Z_t[j2] == n && j2 + n <= j && Z_[j2 + n] + n >= j - j2 + 1) {
						ans = Math.max(ans, j - j2 + 1);
					}
				}
				out.print(ans+" ");
			}
			out.println();
		}
		out.flush();
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
		public boolean id12() {
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
			if (id12())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean id1(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (id12() && id1(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return id12();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!id1(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (id1(c))
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
			} while (!id1(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (id1(c))
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
			} while (!id1(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] id5(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
		public double[] id11(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; i++)
				a[i] = nextDouble();
			return a;
		}
		public long[] id13(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] id7(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}


class StringAlgorithm {
	private static int[] id4(int[] s) {
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

	private static int[] id10(int[] s) {
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

	private static final int id2 = 10;
	private static final int id6 = 40;

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
		if (n < id2) {
			return id4(s);
		}
		if (n < id6) {
			return id10(s);
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

		int[] id14 = new int[n + 1];
		java.util.Arrays.fill(id14, -1);
		int m = 0;
		for (int i = 1; i < n; i++) {
			if (!ls[i - 1] && ls[i]) {
				id14[i] = m++;
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
			int[] id3 = new int[m];
			{
				int p = 0;
				for (int v : sa) {
					if (id14[v] != -1) {
						id3[p++] = v;
					}
				}
			}
			int[] recS = new int[m];
			int recUpper = 0;
			recS[id14[id3[0]]] = 0;
			for (int i = 1; i < m; i++) {
				int l = id3[i - 1], r = id3[i];
				int endL = (id14[l] + 1 < m) ? lms[id14[l] + 1] : n;
				int endR = (id14[r] + 1 < m) ? lms[id14[r] + 1] : n;
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
				recS[id14[id3[i]]] = recUpper;
			}

			int[] recSA = sais(recS, recUpper);

			for (int i = 0; i < m; i++) {
				id3[i] = lms[recSA[i]];
			}
			induce.accept(id3);
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

	public static int[] id9(int[] s, int[] sa) {
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

	public static int[] id9(char[] s, int[] sa) {
		int n = s.length;
		int[] s2 = new int[n];
		for (int i = 0; i < n; i++) {
			s2[i] = s[i];
		}
		return id9(s2, sa);
	}

	public static int[] id9(java.lang.String s, int[] sa) {
		return id9(s.toCharArray(), sa);
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