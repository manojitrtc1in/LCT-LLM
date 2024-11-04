import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.InputMismatchException;
import java.io.IOException;
import java.math.BigInteger;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		int n;
		int[] a;
		int[] p;
		int[] f;
		int[][] g;
		int np;
		static final int MAXN = 200200;
		static int nprime = 0;
		static int[] prime;
		int[] lprime = new int[100];
		int[] lcnt = new int[100];
		int ndiv = 0;
		int[] div = new int[MAXN + 1];
		int[] cnt = new int[MAXN];

		static {
			int sqrt = (int) Math.sqrt(MAXN) + 1;
			prime = new int[sqrt + 1];
			for (int i = 2; i < sqrt; ++i)
				if (IntMath.isPrime(i)) {
					prime[nprime++] = i;
				}
		}

		void id4(int n) {
			np = 0;
			for (int i = 0; i < nprime; ++i) {
				if (n % prime[i] == 0) {
					lprime[np] = prime[i];
					lcnt[np] = 0;

					while (n % prime[i] == 0) {
						n /= prime[i];
						lcnt[np]++;

					}
					np++;
					if (n == 1) break;
				}
			}
			if (n > 1) {
				lprime[np] = n;
				lcnt[np] = 1;
				np++;
			}

			ndiv = 0;
			rec(1, 0);
			div[ndiv++] = 1;
			

		}

		private void rec(int mul, int id) {
			if (mul != 1) {
				div[ndiv++] = mul;

			}
			for (int i = id; i < np; ++i) {
				int lastMul = 1;
				for (int mu = 1; mu <= lcnt[i]; mu++) {
					lastMul *= lprime[i];
					rec(mul * lastMul, i + 1);

				}
			}
		}

		void dfs(int v, int par, int depth) {
			int re = 1;
			for (int i = 0; i < ndiv; ++i) {
				if (a[v] % div[i] == 0) {
					cnt[i]++;
				}
				if (cnt[i] >= depth) {
					re = Math.max(re, div[i]);
				}
			}

			f[v] = re;
			for (int u : g[v])
				if (u != par) {
					p[u] = v;
					dfs(u, v, depth + 1);
				}

			for (int i = 0; i < ndiv; ++i)
				if (a[v] % div[i] == 0) {
					cnt[i]--;
				}
		}

		void dfs2(int v, int par, int id3) {
			if (v != 0) {
				id3 = IntMath.gcd(id3, a[v]);
			}
			f[v] = Math.max(id3, f[v]);
			for (int u : g[v])
				if (u != par) {
					dfs2(u, v, id3);
				}
		}

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			long startTime = System.currentTimeMillis();
			n = in.nextInt();
			a = new int[n];
			for (int i = 0; i < n; ++i) a[i] = in.nextInt();
			f = new int[n];
			int[] from = new int[n - 1];
			int[] to = new int[n - 1];
			for (int i = 0; i < n - 1; ++i) {
				from[i] = in.nextInt() - 1;
				to[i] = in.nextInt() - 1;
			}
			g = Graphs.packU(n, from, to);

			p = new int[n];
			p[0] = -1;

			id4(a[0]);
			dfs(0, -1, 0);

			dfs2(0, -1, 0);
			for (int i = 0; i < n; ++i) {
				out.print(f[i] + " ");
			}


			System.err.println("Time: " + (System.currentTimeMillis() - startTime) + " miliseconds");
		}

	}

	static final class id1 {
		static int id6(String role, int x) {
			if (x < 0) {
				throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
			}
			return x;
		}

		static long id6(String role, long x) {
			if (x < 0) {
				throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
			}
			return x;
		}

		private id1() {
		}

	}

	static final class Longs {
		private Longs() {
		}

		public static int compare(long a, long b) {
			return (a < b) ? -1 : ((a > b) ? 1 : 0);
		}

	}

	static final class IntMath {
		public static int gcd(int a, int b) {
	
			id1.id6("a", a);
			id1.id6("b", b);
			if (a == 0) {
				

				

				return b;
			} else if (b == 0) {
				return a; 

			}
    
			int id11 = Integer.numberOfTrailingZeros(a);
			a >>= id11; 

			int id5 = Integer.numberOfTrailingZeros(b);
			b >>= id5; 

			while (a != b) { 

				

				

				


				

				


				int delta = a - b; 


				int id7 = delta & (delta >> (Integer.SIZE - 1));
				


				a = delta - id7 - id7; 

				


				b += id7; 

				a >>= Integer.numberOfTrailingZeros(a); 

			}
			return a << Math.min(id11, id5);
		}

		public static boolean isPrime(int n) {
			return LongMath.isPrime(n);
		}

		private IntMath() {
		}

	}

	static final class id13 {
		private id13() {
		}

		private static long flip(long a) {
			return a ^ Long.MIN_VALUE;
		}

		public static int compare(long a, long b) {
			return Longs.compare(flip(a), flip(b));
		}

		public static long remainder(long dividend, long divisor) {
			if (divisor < 0) { 

				if (compare(dividend, divisor) < 0) {
					return dividend; 

				} else {
					return dividend - divisor; 

				}
			}

			

			if (dividend >= 0) {
				return dividend % divisor;
			}

    
			long quotient = ((dividend >>> 1) / divisor) << 1;
			long rem = dividend - quotient * divisor;
			return rem - (compare(rem, divisor) >= 0 ? divisor : 0);
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = read();
			while (id2(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id2(c));
			return res * sgn;
		}

		public static boolean id2(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}

	static final class LongMath {
		static final long id9 = 3037000499L;
		private static final int id12 = ~((1 << 1) | (1 << 7) | (1 << 11) | (1 << 13)
				| (1 << 17) | (1 << 19) | (1 << 23) | (1 << 29));
		private static final long[][] id0 = {
				{291830, 126401071349994536L},
				{885594168, 725270293939359937L, 3569819667048198375L},
				{273919523040L, 15, 7363882082L, 992620450144556L},
				{47636622961200L, 2, 2570940, 211991001, 3749873356L},
				{
						7999252175582850L,
						2,
						4130806001517L,
						149795463772692060L,
						186635894390467037L,
						3967304179347715805L
				},
				{
						585226005592931976L,
						2,
						123635709730000L,
						9233062284813009L,
						43835965440333360L,
						761179012939631437L,
						1263739024124850375L
				},
				{Long.MAX_VALUE, 2, 325, 9375, 28178, 450775, 9780504, 1795265022}
		};

		public static boolean isPrime(long n) {
			if (n < 2) {
				id1.id6("n", n);
				return false;
			}
			if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) {
				return true;
			}

			if ((id12 & (1 << (n % 30))) != 0) {
				return false;
			}
			if (n % 7 == 0 || n % 11 == 0 || n % 13 == 0) {
				return false;
			}
			if (n < 17 * 17) {
				return true;
			}

			for (long[] baseSet : id0) {
				if (n <= baseSet[0]) {
					for (int i = 1; i < baseSet.length; i++) {
						if (!LongMath.id10.test(baseSet[i], n)) {
							return false;
						}
					}
					return true;
				}
			}
			throw new AssertionError();
		}

		private LongMath() {
		}

		private enum id10 {
			
			SMALL {
				long mulMod(long a, long b, long m) {
        
					return (a * b) % m;
				}


				long squareMod(long a, long m) {
					return (a * a) % m;
				}
			},
			
			LARGE {
				
				private long plusMod(long a, long b, long m) {
					return (a >= m - b) ? (a + b - m) : (a + b);
				}

				
				private long id8(long a, long m) {
					int id14 = 32;
					do {
						int shift = Math.min(id14, Long.numberOfLeadingZeros(a));
						

						

						a = id13.remainder(a << shift, m);
						id14 -= shift;
					} while (id14 > 0);
					return a;
				}


				long mulMod(long a, long b, long m) {
					long aHi = a >>> 32; 

					long bHi = b >>> 32; 

					long aLo = a & 0xFFFFFFFFL; 

					long bLo = b & 0xFFFFFFFFL; 


        
					long result = id8(aHi * bHi , m); 

					result += aHi * bLo; 

					if (result < 0) {
						result = id13.remainder(result, m);
					}
					

					result += aLo * bHi; 

					result = id8(result, m); 

					return plusMod(
							result,
							id13.remainder(aLo * bLo , m),
							m);
				}


				long squareMod(long a, long m) {
					long aHi = a >>> 32; 

					long aLo = a & 0xFFFFFFFFL; 


        
					long result = id8(aHi * aHi , m); 

					long hiLo = aHi * aLo * 2;
					if (hiLo < 0) {
						hiLo = id13.remainder(hiLo, m);
					}
					

					result += hiLo; 

					result = id8(result, m); 

					return plusMod(
							result,
							id13.remainder(aLo * aLo , m),
							m);
				}
			},;

			static boolean test(long base, long n) {
				

				

				return ((n <= id9) ? SMALL : LARGE).testWitness(base, n);
			}

			abstract long mulMod(long a, long b, long m);

			abstract long squareMod(long a, long m);

			private long powMod(long a, long p, long m) {
				long res = 1;
				for (; p != 0; p >>= 1) {
					if ((p & 1) != 0) {
						res = mulMod(res, a, m);
					}
					a = squareMod(a, m);
				}
				return res;
			}

			private boolean testWitness(long base, long n) {
				int r = Long.numberOfTrailingZeros(n - 1);
				long d = (n - 1) >> r;
				base %= n;
				if (base == 0) {
					return true;
				}
				

				long a = powMod(base, d, n);
				

				

				

				if (a == 1) {
					return true;
				}
				int j = 0;
				while (a != n - 1) {
					if (++j == r) {
						return false;
					}
					a = squareMod(a, n);
				}
				return true;
			}

		}

	}

	static class Graphs {
		public static int[][] packU(int n, int[] from, int[] to) {
			int[][] g = new int[n][];
			int[] p = new int[n];
			for (int f : from)
				p[f]++;
			for (int t : to)
				p[t]++;
			for (int i = 0; i < n; i++)
				g[i] = new int[p[i]];
			for (int i = 0; i < from.length; i++) {
				g[from[i]][--p[from[i]]] = to[i];
				g[to[i]][--p[to[i]]] = from[i];
			}
			return g;
		}

	}
}

