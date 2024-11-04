import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class id2 {

	static final int P = 998_244_353;

	static int[] inv = new int[100_010];
	static {
		inv[1] = 1;
		for (int x = 2; x < inv.length; x++) {
			inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
		}
	}

	static int[] piePoly(int n, int m) {
		int[] p = new int[n + 1];
		p[0] = P - 1;
		for (int i = 1; i <= n; i++) {
			

			p[i] = (int) ((long) p[i - 1] * (m + i) % P * (m + 1 - i) % P * inv[2 * i] % P * inv[2 * i - 1] % P);
		}
		p[0] = 0;
		return p;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();

		if (n % 2 == 0) {
			int[] p = piePoly(n / 2, m);

			int[] first = p.clone();
			for (int i = 1; i <= n / 2; i++) {
				first[i] = (int) ((long) first[i] * i % P);
			}

			p[0] = 1;
			for (int i = 1; i < p.length; i++) {
				p[i] = p[i] == 0 ? 0 : P - p[i];
			}

			int[] ans = mult(first, invert(p));
			int ret = n / 2 < ans.length ? ans[n / 2] : 0; 
			if (n / 2 % 2 == 1 && ret > 0) {
				ret = P - ret;
			}

			out.println(ret);
			return;
		}

		int[] p = piePoly(n / 2, m / 2);

		int[] first = new int[n / 2 + 2];
		int s = m / 2;
		first[1] = s == 0 ? 0 : P - s;
		for (int i = 2; i <= n / 2 + 1; i++) {
			first[i] = (int) ((long) first[i - 1] * (s - 1 + i) % P * (s + 1 - i) % P * inv[2 * i - 1] % P
					* inv[2 * i - 2] % P);
		}

		p[0] = 1;
		for (int i = 1; i < p.length; i++) {
			p[i] = p[i] == 0 ? 0 : P - p[i];
		}

		int[] oddChains = mult(first, invert(p));
		if (oddChains.length < 2) {
			oddChains = Arrays.copyOf(oddChains, 2);
		}
		if (m % 2 == 1) {
			oddChains[1] = P - (m / 2 + 1);
		}

		int[] q = new int[n + 1];
		for (int i = 1; i <= n && i / 2 + 1 < oddChains.length; i += 2) {
			q[i] = oddChains[i / 2 + 1];
			if (i / 2 % 2 == 0 && q[i] != 0) {
				q[i] = P - q[i];
			}
		}
		
		int[] fq = q.clone();
		for (int i = 1; i <= n; i++) {
			fq[i] = (int)((long)fq[i] * i % P);
		}
		
		q[0] = 1;
		for (int i = 1; i <= n; i++) {
			if (q[i] != 0) {
				q[i] = P - q[i];
			}
		}
		
		int[] ans = mult(fq, invert(q));
		out.println(ans[n]);

	}

	static final int id0 = 128;

	static final int L = (int) Math.sqrt(P);
	static final int L2 = L * L;
	static final long P2 = (long) P * P;

	static int[] mult(int[] a, int[] b) {
		int[] ret = multSmall(a, b);
		return ret != null ? ret : multFFT(a, b);
	}

	static int inverse(int x) {
		return x == 1 ? 1 : P - (int) ((long) (P / x) * inverse(P % x) % P);
	}

	static int[] invertStep(int[] b, int[] a) {
		int oLen = Math.min(2 * b.length, a.length);
		int len = id7(b.length + oLen - 1);
		int len2 = len << 1;

		double[][] fB = id1(b, len);
		double[][] fA = id1(Arrays.copyOf(a, oLen), len);

		double[][] invF = new double[2][len2];
		for (int ia = 0; ia < 2; ia++) {
			for (int ib = 0; ib < 2; ib++) {
				double[] r = invF[(ia + ib) >> 1];
				double[] p = fA[ia];
				double[] q = fB[ib];

				if (((ia + ib) & 1) == 0) {
					for (int i = 0; i < len2; i += 2) {
						r[i] += p[i] * q[i] - p[i + 1] * q[i + 1];
						r[i + 1] += p[i] * q[i + 1] + p[i + 1] * q[i];
					}
				} else {
					for (int i = 0; i < len2; i += 2) {
						r[i] -= p[i] * q[i + 1] + p[i + 1] * q[i];
						r[i + 1] += p[i] * q[i] - p[i + 1] * q[i + 1];
					}
				}
			}
		}

		fft(invF[0], true);
		fft(invF[1], true);

		int[] aux = new int[oLen - b.length];

		for (int i = 0; i < oLen; i++) {
			long v0 = Math.round(invF[0][i * 2]);
			long v1 = Math.round(invF[0][i * 2 + 1]) % P * L;
			long v2 = Math.round(invF[1][i * 2]) % P * L2;

			int val = (int) ((v0 + v1 + v2) % P);
			

			if (i < b.length) {
				if (val != (i == 0 ? 1 : 0)) {
					throw new AssertionError();
				}
			} else if (val != 0) {
				aux[i - b.length] = P - val;
			}
		}

		double[][] fC = id1(aux, len);
		Arrays.fill(invF[0], 0);
		Arrays.fill(invF[1], 0);

		for (int ia = 0; ia < 2; ia++) {
			for (int ib = 0; ib < 2; ib++) {
				double[] r = invF[(ia + ib) >> 1];
				double[] p = fC[ia];
				double[] q = fB[ib];

				if (((ia + ib) & 1) == 0) {
					for (int i = 0; i < len2; i += 2) {
						r[i] += p[i] * q[i] - p[i + 1] * q[i + 1];
						r[i + 1] += p[i] * q[i + 1] + p[i + 1] * q[i];
					}
				} else {
					for (int i = 0; i < len2; i += 2) {
						r[i] -= p[i] * q[i + 1] + p[i + 1] * q[i];
						r[i + 1] += p[i] * q[i] - p[i + 1] * q[i + 1];
					}
				}
			}
		}

		fft(invF[0], true);
		fft(invF[1], true);

		int[] ret = Arrays.copyOf(b, oLen);
		for (int i = b.length; i < oLen; i++) {
			long v0 = Math.round(invF[0][(i - b.length) * 2]);
			long v1 = Math.round(invF[0][(i - b.length) * 2 + 1]) % P * L;
			long v2 = Math.round(invF[1][(i - b.length) * 2]) % P * L2;

			ret[i] = (int) ((v0 + v1 + v2) % P);
		}

		return ret;
	}

	static int[] invert(int[] a) {
		int[] b = new int[] { inverse(a[0]) };
		while (b.length < a.length) {
			b = invertStep(b, a);
		}
		return b;
	}

	static int[] multFFT(int[] a, int[] b) {
		int len = id7(a.length + b.length - 1);
		int len2 = len << 1;

		double[][] fA = id1(a, len);
		double[][] fB = id1(b, len);

		

		

		

		

		

		double[][] invF = new double[2][len2];
		for (int ia = 0; ia < 2; ia++) {
			for (int ib = 0; ib < 2; ib++) {
				double[] r = invF[(ia + ib) >> 1];
				double[] p = fA[ia];
				double[] q = fB[ib];

				if (((ia + ib) & 1) == 0) {
					for (int i = 0; i < len2; i += 2) {
						r[i] += p[i] * q[i] - p[i + 1] * q[i + 1];
						r[i + 1] += p[i] * q[i + 1] + p[i + 1] * q[i];
					}
				} else {
					for (int i = 0; i < len2; i += 2) {
						r[i] -= p[i] * q[i + 1] + p[i + 1] * q[i];
						r[i + 1] += p[i] * q[i] - p[i + 1] * q[i + 1];
					}
				}
			}
		}

		fft(invF[0], true);
		fft(invF[1], true);

		int[] ret = new int[len];

		for (int i = 0; i < len2; i += 2) {
			long v0 = Math.round(invF[0][i]);
			long v1 = Math.round(invF[0][i + 1]) % P * L;
			long v2 = Math.round(invF[1][i]) % P * L2;
			ret[i >> 1] = (int) ((v0 + v1 + v2) % P);
		}

		return id6(ret);
	}

	static void fft(double[] v, boolean invert) {
		int n2 = v.length;
		int n = n2 >> 1;
		int logN = Integer.numberOfTrailingZeros(n);
		prepareArrays(logN);
		int[] rev = id5[logN];

		for (int i = 0; i < n2; i += 2) {
			int j = rev[i >> 1] << 1;
			if (i < j) {
				double t = v[i];
				v[i] = v[j];
				v[j] = t;
				t = v[i + 1];
				v[i + 1] = v[j + 1];
				v[j + 1] = t;
			}
		}

		double conj = invert ? -1 : 1;

		for (int len = 2, row = 0; len <= n; len <<= 1, row++) {
			double[] pow = id4[row];
			for (int i = 0; i < n; i += len) {
				for (int j1 = i << 1, j2 = j1 + len, k = 0; k < len; j1 += 2, j2 += 2, k += 2) {
					double uA = v[j1];
					double uB = v[j1 + 1];

					double mRe = pow[k];
					double mIm = pow[k + 1] * conj;

					double vA = v[j2] * mRe - v[j2 + 1] * mIm;
					double vB = v[j2] * mIm + v[j2 + 1] * mRe;

					v[j1] = uA + vA;
					v[j1 + 1] = uB + vB;
					v[j2] = uA - vA;
					v[j2 + 1] = uB - vB;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n2; i++) {
				v[i] /= n;
			}
		}
	}

	static int[] multSmall(int[] a, int[] b) {
		int[] nza = id3(a);
		int[] nzb = id3(b);
		if (nza.length == 0 || nzb.length == 0) {
			return new int[] { 0 };
		}
		if (Math.min(nza.length, nzb.length) <= id0) {
			long[] c = new long[nza[0] + nzb[0] + 1];
			for (int i : nza) {
				for (int j : nzb) {
					c[i + j] += (long) a[i] * b[j];
					if (c[i + j] >= P2) {
						c[i + j] -= P2;
					}
				}
			}
			int[] ret = new int[c.length];
			for (int i = 0; i < c.length; i++) {
				ret[i] = (int) (c[i] % P);
			}
			return id6(ret);
		}
		return null;
	}

	static int[] id3(int[] p) {
		int n = 0;
		for (int i = 0; i < p.length; i++) {
			if (p[i] != 0) {
				n++;
			}
		}
		int[] ret = new int[n];
		for (int i = 0; i < p.length; i++) {
			if (p[i] != 0) {
				ret[--n] = i;
			}
		}
		return ret;
	}

	static int[] id6(int[] a) {
		int i = a.length - 1;
		while (i >= 0 && a[i] == 0) {
			i--;
		}
		return i == a.length - 1 ? a : Arrays.copyOf(a, i + 1);
	}

	static int id7(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	
	static double[][] id1(int[] intV, int len) {
		

		double[] f = new double[len << 1];
		for (int i = 0; i < intV.length; i++) {
			f[i << 1] = intV[i] % L;
			f[i << 1 | 1] = intV[i] / L;
		}

		fft(f, false);

		

		double[] f1 = new double[len << 1];
		double[] f2 = new double[len << 1];
		int zzz = (len << 1) - 1;
		for (int i = 0; i < len << 1; i += 2) {
			int j = (-i) & zzz;
			f1[i] = .5 * (f[i] + f[j]);
			f1[i + 1] = .5 * (f[i + 1] - f[j + 1]);
			f2[i] = .5 * (f[i + 1] + f[j + 1]);
			f2[i + 1] = .5 * (f[j] - f[i]);
		}

		return new double[][] { f1, f2 };
	}

	static double[][] id4 = { { 1, 0 } };
	static int[][] id5 = {};

	static void prepareArrays(int n) {
		if (id5.length < n + 1) {
			id5 = Arrays.copyOf(id5, n + 1);
		}

		if (id5[n] == null) {
			int[] tmp = id5[n] = new int[1 << n];
			for (int i = 0; i < (1 << n); i++) {
				tmp[i] = (tmp[i >> 1] >> 1) | ((i & 1) << (n - 1));
			}
		}

		int oldN = id4.length;

		if (oldN >= n) {
			return;
		}

		id4 = Arrays.copyOf(id4, n);

		for (int i = oldN; i < n; i++) {
			double angle = Math.PI / (1 << i);

			double mRe = Math.cos(angle);
			double mIm = Math.sin(angle);

			double[] dst = id4[i] = new double[2 << i];
			double[] src = id4[i - 1];

			for (int j = 0; j < 1 << i; j += 2) {
				double re = src[j];
				double im = src[j + 1];

				dst[j << 1] = re;
				dst[j << 1 | 1] = im;
				dst[j << 1 | 2] = re * mRe - im * mIm;
				dst[j << 1 | 3] = re * mIm + im * mRe;
			}
		}
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	id2() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		

		

		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new id2();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}