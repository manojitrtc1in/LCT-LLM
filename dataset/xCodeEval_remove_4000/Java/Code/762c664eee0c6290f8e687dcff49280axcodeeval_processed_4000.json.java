import java.io.IOException;
import java.math.BigInteger;
import java.util.Set;
import java.util.TreeSet;

public class B {

	private static final int id9 = 1 << 16;
	private static final int id7 = 1 << 16;
	private byte[] input = new byte[id9];
	private int ix = id9;
	private int bytesRead = ix;
	private byte[] output = new byte[id7];
	private int ox = 0;

	private void readMore() {
		try {
			bytesRead = System.in.read(input, 0, id9);
			if (bytesRead <= 0)
				throw new RuntimeException();
			ix = 0;
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	private void flushOut() {
		System.out.write(output, 0, ox);
		ox = 0;
	}

	private void append(String s) {
		append(s.toCharArray());
	}

	private void append(char[] ca) {
		for (int i = 0; i < ca.length; i++) {
			append(ca[i]);
		}
	}

	private void append(char[] ca, int len) {
		append(ca, 0, len);
	}

	private void append(char[] ca, int start, int endExclusive) {
		for (int i = start; i < endExclusive; i++) {
			append(ca[i]);
		}
	}

	private void append(char c) {
		if (ox == id7)
			flushOut();
		output[ox++] = (byte) c;
	}

	private int nextInt() {
		skipSpaces();
		int ret = 0;
		if (ix == bytesRead) {
			readMore();
		}
		int sign = 1;
		if (input[ix] == '-') {
			sign = -1;
			ix++;
		}
		while (true) {
			if (ix == bytesRead) {
				try {
					readMore();
				} catch (RuntimeException e) {
					return ret;
				}
			}
			if (input[ix] < '0') {
				break;
			}
			ret *= 10;
			ret += input[ix++] - '0';
		}
		return sign * ret;
	}

	private int id0() {
		skipSpaces();
		int ret = 0;
		if (ix == bytesRead) {
			readMore();
		}
		int sign = 1;
		if (input[ix] == '-') {
			sign = -1;
			ix++;
		}
		while (true) {
			if (ix == bytesRead) {
				try {
					readMore();
				} catch (RuntimeException e) {
					return ret;
				}
			}
			if (input[ix] == '.') {
				ix++;
				continue;
			}
			if (input[ix] < '0') {
				break;
			}
			ret *= 10;
			ret += input[ix++] - '0';
		}
		return sign * ret;
	}

	private long nextLong() {
		skipSpaces();
		long ret = 0;
		if (ix == bytesRead) {
			readMore();
		}
		int sign = 1;
		if (input[ix] == '-') {
			sign = -1;
			ix++;
		}
		while (true) {
			if (ix == bytesRead) {
				try {
					readMore();
				} catch (RuntimeException e) {
					return ret;
				}
			}
			if (input[ix] < '0')
				break;
			ret *= 10;
			ret += input[ix++] - '0';
		}
		return sign * ret;
	}

	private String nextLine() {
		StringBuilder sb = new StringBuilder();
		while (true) {
			if (ix == bytesRead) {
				try {
					readMore();
				} catch (RuntimeException e) {
					if (sb.length() > 0)
						return sb.toString();
					return null;
				}
			}
			char c = (char) input[ix++];
			if (c == '\n')
				break;
			sb.append(c);
		}
		return sb.toString();
	}

	private String nextString() {
		try {
			skipSpaces();
		} catch (RuntimeException e) {
			return null;
		}
		StringBuilder sb = new StringBuilder();
		while (true) {
			if (ix == bytesRead) {
				try {
					readMore();
				} catch (RuntimeException e) {
					return sb.toString();
				}
			}
			if (input[ix] <= ' ')
				break;
			sb.append((char) input[ix++]);
		}
		return sb.toString();
	}

	private String id6() {
		try {
			skipSpaces();
		} catch (RuntimeException e) {
			return null;
		}
		StringBuilder sb = new StringBuilder();
		while (true) {
			if (ix == bytesRead) {
				try {
					readMore();
				} catch (RuntimeException e) {
					return sb.toString();
				}
			}
			if (input[ix] < ' ')
				break;
			sb.append((char) input[ix++]);
		}
		return sb.toString();
	}

	private void id5(char[] ca, int len) {
		skipSpaces();
		for (int i = 0; i < len; i++) {
			if (ix == bytesRead) {
				readMore();
			}
			ca[i] = (char) input[ix++];
		}
	}

	private int id2;

	private void id5(char[] ca) {
		id2 = 0;
		try {
			skipSpaces();
			if (ix == bytesRead) {
				readMore();
			}
		} catch (RuntimeException e) {
			return;
		}
		ca[id2++] = (char) input[ix++];
		while (true) {
			if (ix == bytesRead) {
				try {
					readMore();
				} catch (RuntimeException e) {
					return;
				}
			}
			char c = (char) input[ix++];
			if (c < ' ')
				break;
			ca[id2++] = c;
		}
	}

	private char id12() {
		skipSpaces();
		if (ix == bytesRead) {
			readMore();
		}
		char ret = (char) input[ix++];
		while (true) {
			if (ix == bytesRead) {
				readMore();
			}
			if (input[ix++] <= ' ')
				break;
		}
		return ret;
	}

	int cntSize;

	private char id4() {
		skipSpaces();
		if (ix == bytesRead) {
			readMore();
		}
		char ret = (char) input[ix++];
		cntSize = 1;
		while (true) {
			if (ix == bytesRead) {
				readMore();
			}
			char c = (char) input[ix++];
			if (c <= ' ')
				break;
			ret = c;
			cntSize++;
		}
		return ret;
	}

	private void skipSpaces() {
		while (true) {
			if (ix == bytesRead) {
				readMore();
			}
			if (input[ix] > ' ')
				break;
			ix++;
		}
	}

	private char[] nn = new char[32];

	private void printLong(long n) {
		if (n == 0) {
			append('0');
		} else {
			if (n < 0) {
				append('-');
				n = -n;
			}
			int kk = 0;
			while (n > 0) {
				nn[kk++] = (char) (n % 10 + '0');
				n /= 10;
			}
			for (int i = kk - 1; i >= 0; i--) {
				append(nn[i]);
			}
		}
	}

	private void printInt(int n) {
		if (n == 0) {
			append('0');
		} else {
			if (n < 0) {
				append('-');
				n = -n;
			}
			int kk = 0;
			while (n > 0) {
				nn[kk++] = (char) (n % 10 + '0');
				n /= 10;
			}
			for (int i = kk - 1; i >= 0; i--) {
				append(nn[i]);
			}
		}
	}

	private void id10(int n, int just) {
		if (n == 0) {
			if (just > 0) {
				while (--just != 0)
					append(' ');
			}
			append('0');
			if (just < 0) {
				while (++just != 0)
					append(' ');
			}
		} else {
			boolean neg = false;
			if (n < 0) {
				neg = true;
				n = -n;
			}
			int kk = 0;
			while (n > 0) {
				nn[kk++] = (char) (n % 10 + '0');
				n /= 10;
			}
			if (neg) {
				nn[kk++] = '-';
			}
			if (just > 0) {
				while (--just >= kk)
					append(' ');
			}
			for (int i = kk - 1; i >= 0; i--) {
				append(nn[i]);
			}
			if (just < 0) {
				just = -just;
				while (--just >= kk)
					append(' ');
			}
		}
	}

	private void printDouble(double x, int p) {
		if (p == 0) {
			printLong(Math.round(x));
		} else {
			long pow = 1;
			for (int i = 0; i < p; i++) {
				pow *= 10;
			}
			x *= pow;
			long t = Math.round(x);
			printLong(t / pow);
			append('.');
			long rem = t % pow;
			if (rem == 0) {
				while (p-- > 0)
					append('0');
			} else {
				long tt = rem;
				while (tt > 0) {
					p--;
					tt /= 10;
				}
				while (p-- > 0)
					append('0');
				printLong(rem);
			}
		}
	}

	private int parseInt(String s) {
		int result = 0;
		int sign = (s.charAt(0) == '-') ? -1 : 1;
		if (sign == -1) {
			s = s.substring(1);
		}
		if (s.charAt(0) == '+') {
			s = s.substring(1);
		}
		int i = 0, max = s.length();
		if (max > 0) {
			while (i < max) {
				result *= 10;
				result += s.charAt(i++) - 48;
			}
		}
		return sign * result;
	}

	private boolean nextPerm(int[] a) {
		if (a.length <= 1) {
			return false;
		}
		int i = a.length - 1;
		while (a[i - 1] >= a[i]) {
			i--;
			if (i == 0) {
				return false;
			}
		}
		int j = a.length;
		while (a[j - 1] <= a[i - 1]) {
			j--;
			if (j == 0) {
				return false;
			}
		}
		int tmp = a[i - 1];
		a[i - 1] = a[j - 1];
		a[j - 1] = tmp;
		i++;
		j = a.length;
		while (i < j) {
			tmp = a[i - 1];
			a[i - 1] = a[j - 1];
			a[j - 1] = tmp;
			i++;
			j--;
		}
		return true;
	}

	private boolean[][] pow(boolean[][] a, int k, int n) {
		boolean[][] ret = new boolean[n][n];
		if (k == 0) {
			for (int i = 0; i < n; i++) {
				ret[i][i] = true;
			}
		} else {
			if ((k & 1) == 0) {
				boolean[][] t = pow(a, k / 2, n);
				ret = mul(t, t, n);
			} else {
				ret = mul(pow(a, k - 1, n), a, n);
			}
		}
		return ret;
	}

	private boolean[][] mul(boolean[][] a, boolean[][] b, int n) {
		boolean[][] c = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					c[i][j] |= a[i][k] & b[k][j];
				}
			}
		}
		return c;
	}

	private long gcd(long a, long b) {
		if (a == 0)
			return gcd(b, a);
		return b == 0 ? a : gcd(b, a % b);
	}

	private int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	private int powMod(int n, int k, int m) {
		if (k == 0)
			return 1;
		if ((k & 1) == 0) {
			int t = powMod(n, k / 2, m);
			return (t * t) % m;
		}
		return (n * powMod(n, k - 1, m)) % m;
	}

	private long[][] ID = { { 1, 0 }, { 0, 1 } };

	private long[][] pow(long[][] a, long k, long m) {
		if (k == 0)
			return ID;
		if ((k & 1) == 0) {
			long[][] t = pow(a, k / 2, m);
			return mul(t, t, m);
		}
		return mul(a, pow(a, k - 1, m), m);
	}

	private long[][] mul(long[][] a, long[][] b, long m) {
		return new long[][] {
				{ (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % m,
						(a[0][0] * b[0][1] + a[0][1] * b[1][1]) % m },
				{ (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % m,
						(a[1][0] * b[0][1] + a[1][1] * b[1][1]) % m } };
	}

	private String romanDigits = "MDCLXVI";
	private int[] id11 = { 1000, 500, 100, 50, 10, 5, 1 };

	private int id3(char[] ca, int len) {
		int n = 0;
		for (int i = 0; i < len; i++) {
			int k = romanDigits.indexOf(ca[i]);
			int v = id11[k];
			if (i < len - 1) {
				int kk = romanDigits.indexOf(ca[i + 1]);
				if (kk < k)
					v = -v;
			}
			n += v;
		}
		return n;
	}

	private String id8(int n) {
		StringBuilder sb = new StringBuilder();
		while (n >= 1000) {
			sb.append('M');
			n -= 1000;
		}
		if (n >= 900) {
			sb.append('C');
			sb.append('M');
			n -= 900;
		}
		if (n >= 500) {
			sb.append('D');
			n -= 500;
		}
		if (n >= 400) {
			sb.append('C');
			sb.append('D');
			n -= 400;
		}
		while (n >= 100) {
			sb.append('C');
			n -= 100;
		}
		if (n >= 90) {
			sb.append('X');
			sb.append('C');
			n -= 90;
		}
		if (n >= 50) {
			sb.append('L');
			n -= 50;
		}
		if (n >= 40) {
			sb.append('X');
			sb.append('L');
			n -= 40;
		}
		while (n >= 10) {
			sb.append('X');
			n -= 10;
		}
		if (n == 9) {
			sb.append('I');
			sb.append('X');
			n -= 9;
		}
		if (n >= 5) {
			sb.append('V');
			n -= 5;
		}
		if (n == 4) {
			sb.append('I');
			sb.append('V');
			n -= 4;
		}
		while (n > 0) {
			sb.append('I');
			n--;
		}
		return sb.toString();
	}

	private int[] id1(int N) {
		int[] ret = new int[10];
		if (N < 10) {
			for (int i = 1; i <= N; i++) {
				ret[i] = 1;
			}
			return ret;
		}
		while (N % 10 != 9) {
			int t = N--;
			while (t > 0) {
				ret[t % 10]++;
				t /= 10;
			}
		}
		N++;
		for (int i = 0; i < 10; i++) {
			ret[i] += N / 10;
		}
		int[] tmp = id1(N / 10 - 1);
		for (int i = 0; i < 10; i++) {
			ret[i] += 10 * tmp[i];
		}
		ret[0]--;
		return ret;
	}

	private int[] tempSort; 


	private void sort(int array[], int begin, int end) {
		int mid;
		if (end - begin <= 1) {
			return;
		}
		mid = (begin + end) / 2;
		sort(array, begin, mid);
		sort(array, mid, end);
		merge(array, begin, mid, end);
	}

	private void merge(int[] array, int start, int mid, int end) {
		int i = start;
		int j = mid;
		int k = 0;
		while ((i < mid) && (j < end)) {
			if (array[i] <= array[j]) {
				tempSort[k++] = array[i++];
			} else {
				tempSort[k++] = array[j++];
			}
		}
		while (i < mid) {
			tempSort[k++] = array[i++];
		}
		while (j < end) {
			tempSort[k++] = array[j++];
		}
		for (i = start; i < end; i++) {
			array[i] = tempSort[i - start];
		}
	}

	private void work() {

		long n = nextLong();

		Set<BigInteger> set = new TreeSet<BigInteger>();
		BigInteger three = BigInteger.valueOf(3);
		BigInteger eightN = BigInteger.valueOf(8 * n);

		int x = 0;
		BigInteger pow2 = BigInteger.ONE;
		while ((1L << x) <= n + 10) {
			BigInteger z = pow2.shiftLeft(1).subtract(three);
			BigInteger d = z.multiply(z).add(eightN);
			BigInteger s = isqrt(d);
			if (s.multiply(s).compareTo(d) == 0) {
				BigInteger y = z.negate().add(s);
				if (y.compareTo(BigInteger.ZERO) > 0) {
					y = y.shiftRight(1);
					if (y.testBit(0))
						set.add(pow2.multiply(y));
				}
				y = z.negate().subtract(s);
				if (y.compareTo(BigInteger.ZERO) > 0) {
					y = y.shiftRight(1);
					if (y.testBit(0))
						set.add(pow2.multiply(y));
				}
			}
			pow2 = pow2.shiftLeft(1);
			x++;
		}

		if (set.isEmpty())
			append("-1\n");
		else
			for (BigInteger bi : set) {
				append(bi.toString());
				append('\n');
			}

		if (ox > 0)
			flushOut();
		System.out.close();
	}

	private BigInteger isqrt(BigInteger N) {
		BigInteger x0 = BigInteger
				.valueOf((long) (Math.sqrt(N.doubleValue()) + 1e-10));
		for (int i = 0; i < 15; i++) {
			if (x0.compareTo(BigInteger.ZERO) == 0)
				while (1 < 2)
					;
			BigInteger x1 = x0.multiply(x0).add(N).divide(x0.shiftLeft(1));
			x0 = x1;
		}
		return x0;
	}

	public static void main(String[] args) {
		new B().work();
	}

}
