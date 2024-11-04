




import java.io.*;
import java.util.*;

public class id6 {
	private static final int id8 = 1;

	private static final int BIT_MAX = 31;














































































































	public static void solveCase(FastIO io, int testCase) {
		final int N = io.nextInt();
		final int Q = io.nextInt();
		final long[] A = io.id9(N);

		long[] addSum = new long[N + 1];
		long[] xorSum = new long[N + 1];
		for (int i = 0; i < N; ++i) {
			addSum[i + 1] = addSum[i] + A[i];
			xorSum[i + 1] = xorSum[i] ^ A[i];
		}




		int[][] id3 = new int[BIT_MAX][N];
		int[][] id2 = new int[BIT_MAX][N];
		for (int b = 0; b < BIT_MAX; ++b) {
			Arrays.fill(id3[b], -1);
			for (int i = N - 1; i >= 0; --i) {
				long val = (A[i] >> b) & 1;


				if (val != 0) {
					id3[b][i] = i;
				} else if (i + 1 < N) {
					id3[b][i] = id3[b][i + 1];
				}
			}

			Arrays.fill(id2[b], -1);
			for (int i = 0; i < N; ++i) {
				long val = (A[i] >> b) & 1;
				if (val != 0) {
					id2[b][i] = i;
				} else if (i - 1 >= 0) {
					id2[b][i] = id2[b][i - 1];
				}
			}





		}

		for (int q = 0; q < Q; ++q) {
			final int L = io.nextInt() - 1;
			final int R = io.nextInt() - 1;









			




			long[] ans = smartSolve(L, R, addSum, xorSum, id3, id2);
			io.println(ans[0] + 1, ans[1] + 1);














































































































































































































































		}
	}

	private static long F(int L, int R, long[] addSum, long[] xorSum) {
		return (addSum[R + 1] - addSum[L]) - (xorSum[R + 1] ^ xorSum[L]);
	}

	private static long[] smartSolve(int L, int R, long[] addSum, long[] xorSum, int[][] id3, int[][] id2) {
		long best = F(L, R, addSum, xorSum);
		if (best == 0) {
			return new long[] {L, L, 0};
		}

		int minWidth = R - L;
		int ansL = L;
		int ansR = R;
		for (int b = 0; b < BIT_MAX; ++b) {
			int i = L - 1;
			for (int k = 0; k < 2; ++k) {
				if (i >= R) {
					break;
				}
				
				i = id3[b][i + 1];
				if (i < 0) {
					break;
				}
				if (i > R) {
					break;
				}

				long rangeBest = F(i, R, addSum, xorSum);
				if (rangeBest < best) {
					continue;
				}

				final int startIndex = i;
				int j = BinarySearch.firstThat(i, R + 1, new BinarySearch.IntCheck() {
					@Override
					public boolean valid(int index) {
						return F(startIndex, index, addSum, xorSum) >= best;
					}
				});

				int w = j - i;
				if (w < minWidth) {
					minWidth = w;
					ansL = i;
					ansR = j;
				}
			}
		}








































































		return new long[] {ansL, ansR, F(ansL, ansR, addSum, xorSum)};
	}

	private static long[] id4(int L, int R, long[] addSum, long[] xorSum) {
		long best = F(L, R, addSum, xorSum);
		int minWidth = R - L;
		int ansL = L;
		int ansR = R;
		for (int i = L; i <= R && i <= L + 32; ++i) {
			long rangeBest = F(i, R, addSum, xorSum);
			if (rangeBest < best) {
				continue;
			}

			final int startIndex = i;
			int j = BinarySearch.firstThat(i, R + 1, new BinarySearch.IntCheck() {
				@Override
				public boolean valid(int index) {
					return F(startIndex, index, addSum, xorSum) >= best;
				}
			});





















			int w = j - i;
			if (w < minWidth) {
				minWidth = w;
				ansL = i;
				ansR = j;
			}
		}
		return new long[] {ansL, ansR, F(ansL, ansR, addSum, xorSum)};
	}

	private static long[] id0(int L, int R, long[] addSum, long[] xorSum) {
		long best = F(L, R, addSum, xorSum);

		int minWidth = R - L;
		int ansL = L;
		int ansR = R;
		for (int i = L; i <= R; ++i) {
			for (int j = i; j <= R; ++j) {
				long got = F(i, j, addSum, xorSum);
				if (got == best) {
					int w = j - i;
					if (w < minWidth) {
						minWidth = w;
						ansL = i;
						ansR = j;
					}
				}
			}
		}
		return new long[] {ansL, ansR, F(ansL, ansR, addSum, xorSum)};
	}

	
	

	
	public static class BinarySearch {
		

		

		public static int firstThat(int L, int R, IntCheck check) {
			while (L < R) {
				int M = (L >> 1) + (R >> 1) + (L & R & 1);
				if (check.valid(M)) {
					R = M;
				} else {
					L = M + 1;
				}
			}
			return L;
		}

		

		

		public static int lastThat(int L, int R, IntCheck check) {
			int firstValue = firstThat(L, R, new IntCheck() {
				@Override
				public boolean valid(int value) {
					return !check.valid(value);
				}
			});
			return firstValue - 1;
		}

		

		public static long firstThat(long L, long R, LongCheck check) {
			while (L < R) {
				long M = (L >> 1) + (R >> 1) + (L & R & 1);
				if (check.valid(M)) {
					R = M;
				} else {
					L = M + 1;
				}
			}
			return L;
		}

		

		

		public static long lastThat(long L, long R, LongCheck check) {
			long firstValue = firstThat(L, R, new LongCheck() {
				@Override
				public boolean valid(long value) {
					return !check.valid(value);
				}
			});
			return firstValue - 1;
		}

		public static interface LongCheck {
			public boolean valid(long value);
		}

		public static interface IntCheck {
			public boolean valid(int value);
		}
	}

	public static void solve(FastIO io) {
		final int T = io.nextInt();

		for (int t = 0; t < T; ++t) {
			solveCase(io, id8 + t);
		}
	}

	public static class FastIO {
		private InputStream reader;
		private PrintWriter writer;

		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastIO(InputStream r, OutputStream w) {
			reader = r;
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(w)));
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = reader.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public String nextLine() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id7(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (id1(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id1(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (id1(c))
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
			} while (!id1(c));
			return res * sgn;
		}

		

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] id5(int n) {
			return id5(n, 0);
		}

		public int[] id5(int n, int off) {
			int[] arr = new int[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextInt();
			}
			return arr;
		}

		public long[] id9(int n) {
			return id9(n, 0);
		}

		public long[] id9(int n, int off) {
			long[] arr = new long[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextLong();
			}
			return arr;
		}

		private boolean id1(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean id7(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0) {
					writer.print(' ');
				}
				writer.print(objects[i]);
			}
		}

		public void println(Object... objects) {
			print(objects);
			writer.println();
		}

		public void printArray(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				if (i != 0) {
					writer.print(' ');
				}
				writer.print(arr[i]);
			}
		}

		public void printArray(long[] arr) {
			for (int i = 0; i < arr.length; i++) {
				if (i != 0) {
					writer.print(' ');
				}
				writer.print(arr[i]);
			}
		}

		public void printlnArray(int[] arr) {
			printArray(arr);
			writer.println();
		}

		public void printlnArray(long[] arr) {
			printArray(arr);
			writer.println();
		}

		public void printf(String format, Object... args) {
			print(String.format(format, args));
		}

		public void flush() {
			writer.flush();
		}
	}

	public static void main(String[] args) {
		FastIO io = new FastIO(System.in, System.out);
		solve(io);
		io.flush();
	}
}