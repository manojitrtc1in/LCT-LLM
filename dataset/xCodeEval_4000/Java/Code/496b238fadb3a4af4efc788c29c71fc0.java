import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class cf745F {

	static final int P = 998_244_353;
	static final int PRIM_ROOT = 3;

	static int pow(long a, int n) {
		long ret = 1;
		for (; n > 0; n >>= 1) {
			if ((n & 1) == 1) {
				ret = ret * a % P;
			}
			a = a * a % P;
		}
		return (int) ret;
	}

	static final long P_LONG = P;
	static final int DBL_P = 2 * P;
	static final int DBL_P_MAGIC = (1 << 31) - DBL_P;
	static final long P_SQ = P_LONG * P_LONG;
	static final int LOG = Integer.numberOfTrailingZeros(P - 1);
	static final int OMEGA = pow(PRIM_ROOT, (P - 1) >> LOG);

	static int[] inv = new int[100_010];
	static {
		inv[1] = 1;
		for (int x = 2; x < inv.length; x++) {
			inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
		}
	}

	static int inverse(int x) {
		return x == 1 ? 1 : P - (int) ((long) (P / x) * inverse(P % x) % P);
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
			fq[i] = (int) ((long) fq[i] * i % P);
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

	static final int NAIVE_MULT_THRESHOLD = 128;

	static int[] mult(int[] a, int[] b) {
		int[] ret = multSmall(a, b);
		return ret != null ? ret : multFFT(a, b);
	}

	static int[] invertStep(int[] b, int[] a) {
		

		

		

		


		

		

		


		int len = 2 * b.length;

		int[] fB = Arrays.copyOf(b, len);
		int[] fA = Arrays.copyOf(a, len);

		fft(fA, false);
		fft(fB, false);

		for (int i = 0; i < len; i++) {
			fA[i] = (int) ((long) fA[i] * fB[i] % P);
		}

		fft(fA, true);
		


		int[] aux = new int[len];

		for (int i = b.length; i < Math.min(len, a.length); i++) {
			if (fA[i] != 0) {
				aux[i - b.length] = P - fA[i];
			}
		}

		fft(aux, false);
		for (int i = 0; i < len; i++) {
			aux[i] = (int) ((long) aux[i] * fB[i] % P);
		}

		fft(aux, true);

		int[] ret = Arrays.copyOf(b, Math.min(len, a.length));
		for (int i = b.length; i < ret.length; i++) {
			ret[i] = aux[i - b.length];
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
		int len = nextPowerOf2(a.length + b.length - 1);

		int[] fA = Arrays.copyOf(a, len);
		int[] fB = Arrays.copyOf(b, len);

		fft(fA, false);
		fft(fB, false);

		for (int i = 0; i < len; i++) {
			fA[i] = (int) ((long) fA[i] * fB[i] % P);
		}

		fft(fA, true);
		return removeLeadingZeroes(fA);
	}

	static void fft(int[] v, boolean invert) {
		int n = v.length;
		int logN = Integer.numberOfTrailingZeros(n);
		prepareArrays(logN);
		int[] rev = rev2D[logN];

		for (int i = 0; i < n; i++) {
			int j = rev[i];
			if (i < j) {
				int t = v[i];
				v[i] = v[j];
				v[j] = t;
			}
		}

		int[][] ws = invert ? INV_ROOTS : ROOTS;

		

		


		int hb = 1; 

		if (hb < n) {
			for (int i = 0; i < n; i += 2) {
				int delta = v[i + 1];
				int vi = v[i];
				v[i + 1] = vi + P - delta;
				v[i] = vi + delta;
			}

			hb <<= 1;
		}

		


		if (hb < n) {
			long root = ws[1][1];
			for (int i = 0; i < n; i += 4) {
				int delta;
				{
					int vi2 = v[i + 2];
					int vi = v[i];
					delta = vi2 >= P ? vi2 - P : vi2;
					v[i + 2] = vi + P - delta;
					v[i] = vi + delta;
				}

				{
					int vi1 = v[i + 1];
					delta = (int) (root * v[i + 3] % P_LONG);
					v[i + 3] = vi1 + P - delta;
					v[i + 1] = vi1 + delta;
				}
			}
			hb <<= 1;
		}

		int row = 2;

		while (hb < n) {
			

			{
				int[] roots = ws[row];
				for (int i0 = 0; i0 < n; i0 += hb << 1) {
					for (int i = i0; i < i0 + hb; i++) {
						int delta = (int) (roots[i - i0] * (((long) v[i + hb]) & 0xFFFFFFFFL) % P_LONG);
						int vi = v[i];
						v[i + hb] = vi + P - delta;
						v[i] = vi + delta;
					}
				}

				hb <<= 1;
				row++;
			}

			

			if (hb < n) {
				int[] roots = ws[row];
				for (int i0 = 0; i0 < n; i0 += hb << 1) {
					for (int i = i0; i < i0 + hb; i++) {
						int delta = (int) (roots[i - i0] * (((long) v[i + hb]) & 0xFFFFFFFFL) % P_LONG);
						

						int vi = v[i];


						if (vi + DBL_P_MAGIC < DBL_P_MAGIC) {
							vi -= DBL_P;
						}
						v[i + hb] = vi + P - delta;
						v[i] = vi + delta;
					}
				}

				hb <<= 1;
				row++;
			}
		}

		for (int i = 0; i < n; i++) {
			v[i] = (v[i] < 0 || v[i] >= DBL_P) ? v[i] - DBL_P : v[i];
			v[i] = v[i] >= P ? v[i] - P : v[i];
		}
		if (invert) {
			long invN = inverse(n);
			for (int i = 0; i < n; i++) {
				v[i] = (int) (invN * v[i] % P_LONG);
			}
		}
	}

	static int[] multSmall(int[] a, int[] b) {
		int[] nza = getNonZeroesIdx(a);
		int[] nzb = getNonZeroesIdx(b);
		if (nza.length == 0 || nzb.length == 0) {
			return new int[] { 0 };
		}
		if (Math.min(nza.length, nzb.length) <= NAIVE_MULT_THRESHOLD) {
			long[] c = new long[nza[0] + nzb[0] + 1];
			for (int i : nza) {
				for (int j : nzb) {
					long tmp = c[i + j] + (long) a[i] * b[j];
					if (tmp >= P_SQ) {
						tmp -= P_SQ;
					}
					c[i + j] = tmp;
				}
			}
			int[] ret = new int[c.length];
			for (int i = 0; i < c.length; i++) {
				ret[i] = (int) (c[i] % P);
			}
			return removeLeadingZeroes(ret);
		}
		return null;
	}

	static int[] getNonZeroesIdx(int[] p) {
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

	static int[] removeLeadingZeroes(int[] a) {
		int i = a.length - 1;
		while (i >= 0 && a[i] == 0) {
			i--;
		}
		return i == a.length - 1 ? a : Arrays.copyOf(a, i + 1);
	}

	static int nextPowerOf2(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	static int[][] ROOTS = { { 1 } };
	static int[][] INV_ROOTS = { { 1 } };
	static int[][] rev2D = {};

	static void prepareArrays(int n) {
		if (rev2D.length < n + 1) {
			rev2D = Arrays.copyOf(rev2D, n + 1);
		}

		if (rev2D[n] == null) {
			int[] tmp = rev2D[n] = new int[1 << n];
			for (int i = 0; i < (1 << n); i++) {
				tmp[i] = (tmp[i >> 1] >> 1) | ((i & 1) << (n - 1));
			}
		}

		int oldN = ROOTS.length;

		if (oldN >= n) {
			return;
		}

		ROOTS = Arrays.copyOf(ROOTS, n);
		INV_ROOTS = Arrays.copyOf(INV_ROOTS, n);

		for (int i = oldN; i < n; i++) {

			int x = pow(OMEGA, 1 << (LOG - i - 1));
			int y = inverse(x);

			int[] dst = ROOTS[i] = new int[1 << i];
			int[] src = ROOTS[i - 1];

			int[] dst2 = INV_ROOTS[i] = new int[1 << i];
			int[] src2 = INV_ROOTS[i - 1];

			for (int j = 0; j < 1 << (i - 1); j++) {
				int tmp = src[j];
				dst[2 * j] = tmp;
				dst[2 * j + 1] = (int) (x * (long) tmp % P);

				tmp = src2[j];
				dst2[2 * j] = tmp;
				dst2[2 * j + 1] = (int) (y * (long) tmp % P);
			}
		}
	}

	void test() {
		int[] a = { 0, 1, 0, 0, 0, 0, 0, 0 };
		fft(a, true);
		System.err.println(Arrays.toString(a));
	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	cf745F() throws IOException {
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
		new cf745F();
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