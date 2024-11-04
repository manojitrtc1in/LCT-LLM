import java.io.*;
import java.util.*;

public class id1 {
	public static void solve(FastIO io) {
		final int N = io.nextInt();
		final int Q = io.nextInt();
		final int[] A = io.id3(N);
		
		int[] xorSum = new int[N + 1];
		for (int i = 0; i < N; ++i) {
			xorSum[i + 1] = xorSum[i] ^ A[i];
		}
		
		id4[] xorIdx = new id4[2];
		for (int i = 0; i < xorIdx.length; ++i) {
			xorIdx[i] = new id4();
		}
		
		for (int i = 0; i <= N; ++i) {
			int xor = xorSum[i];
			IntKey k = IntKey.of(xor);
			int parity = i & 1;
			IntDeque s = xorIdx[parity].getOrDefault(k, null);
			if (s == null) {
				s = new IntDeque();
				xorIdx[parity].put(k, s);
			}
			s.add(i);
		}
		
		for (int p = 0; p < xorIdx.length; ++p) {
			for (IntDeque d : xorIdx[p].values()) {
				int[] arr = d.toArray();
				Sort.ints(arr);
				
				d.clear();
				d.addAll(arr);
			}
		}
		
		int[] isZero = new int[N];
		for (int i = 0; i < N; ++i) {
			if (A[i] == 0) {
				isZero[i] = 1;
			}
		}
		
		int[] zeroSum = new int[N + 1];
		for (int i = 0; i < N; ++i) {
			zeroSum[i + 1] = zeroSum[i] + isZero[i];
		}
		
		for (int q = 0; q < Q; ++q) {
			final int L = io.nextInt() - 1;
			final int R = io.nextInt() - 1;
			
			int w = R - L + 1;
			
			if (zeroSum[R + 1] - zeroSum[L] == w) {
				io.println(0);
				continue;
			}
			
			if ((xorSum[R + 1] ^ xorSum[L]) != 0) {
				io.println(-1);
				continue;
			}
			
			if ((w & 1) != 0) {
				io.println(1);
				continue;
			}
			
			if (A[L] == 0 || A[R] == 0) {
				io.println(1);
				continue;
			}
			
			int wantParity = (L & 1) ^ 1;
			IntDeque d = xorIdx[wantParity].getOrDefault(IntKey.of(xorSum[L]), null);
			if (d == null) {
				io.println(-1);
				continue;
			}
			
			int findIdx = BinarySearch.firstThat(0, d.size(), new BinarySearch.IntCheck() {
				@Override
				public boolean valid(int index) {
					return d.get(index) >= L + 3;
				}
			});
			if (findIdx >= d.size()) {
				io.println(-1);
				continue;
			}
			
			if (d.get(findIdx) > R + 1) {
				io.println(-1);
				continue;
			}
			
			io.println(2);
			




















		}
	}
	
	private static class id4 extends HashMap<IntKey, IntDeque> {
		
	}
	
	private static class IntSet extends TreeSet<Integer> {
		private static final IntSet EMPTY = new IntSet();
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

	public static class Sort {
		public static int[] ints(int[] A) {
			final int N = A.length;

			int[] buf = new int[N];
			for (int lw = 1; lw < N; lw <<= 1) {
				int w = lw << 1;
				for (int i = 0; i + lw <= N; i += w) {
					int k = Math.min(i + w, N);

					int segLen = k - i;
					System.arraycopy(A, i, buf, 0, segLen);

					int p = i;
					int a = 0;
					int b = lw;
					while (a < lw && b < segLen) {
						if (buf[a] < buf[b]) {
							A[p++] = buf[a++];
						} else {
							A[p++] = buf[b++];
						}
					}
					if (a < lw) {
						System.arraycopy(buf, a, A, p, lw - a);
					} else {
						System.arraycopy(buf, b, A, p, segLen - b);
					}
				}
			}
			return A;
		}

		public static long[] longs(long[] A) {
			final int N = A.length;

			long[] buf = new long[N];
			for (int lw = 1; lw < N; lw <<= 1) {
				int w = lw << 1;
				for (int i = 0; i + lw <= N; i += w) {
					int k = Math.min(i + w, N);

					int segLen = k - i;
					System.arraycopy(A, i, buf, 0, segLen);

					int p = i;
					int a = 0;
					int b = lw;
					while (a < lw && b < segLen) {
						if (buf[a] < buf[b]) {
							A[p++] = buf[a++];
						} else {
							A[p++] = buf[b++];
						}
					}
					if (a < lw) {
						System.arraycopy(buf, a, A, p, lw - a);
					} else {
						System.arraycopy(buf, b, A, p, segLen - b);
					}
				}
			}
			return A;
		}

		public static double[] doubles(double[] A) {
			final int N = A.length;

			double[] buf = new double[N];
			for (int lw = 1; lw < N; lw <<= 1) {
				int w = lw << 1;
				for (int i = 0; i + lw <= N; i += w) {
					int k = Math.min(i + w, N);

					int segLen = k - i;
					System.arraycopy(A, i, buf, 0, segLen);

					int p = i;
					int a = 0;
					int b = lw;
					while (a < lw && b < segLen) {
						if (buf[a] < buf[b]) {
							A[p++] = buf[a++];
						} else {
							A[p++] = buf[b++];
						}
					}
					if (a < lw) {
						System.arraycopy(buf, a, A, p, lw - a);
					} else {
						System.arraycopy(buf, b, A, p, segLen - b);
					}
				}
			}
			return A;
		}
	}

	
	public static class IntDeque {
		private int[] arr;
		private int off;
		private int len;

		public IntDeque() {
			this(2);
		}

		public IntDeque(int capacity) {
			this.arr = new int[capacity];
		}

		public void addFirst(int x) {
			if (len == arr.length) {
				increaseCapacity();
			}
			if (off == 0) {
				off = arr.length;
			}
			arr[--off] = x;
			++len;
		}

		public void addLast(int x) {
			if (len == arr.length) {
				increaseCapacity();
			}
			int idx = index(off + len);
			arr[idx] = x;
			++len;
		}

		public int peekFirst() {
			return arr[off];
		}

		public int peekLast() {
			int idx = index(off + len - 1);
			return arr[idx];
		}

		public int removeFirst() {
			int ans = peekFirst();
			off = index(off + 1);
			--len;
			return ans;
		}

		public int removeLast() {
			int ans = peekLast();
			--len;
			return ans;
		}

		public void add(int x) {
			addLast(x);
		}

		public void offer(int x) {
			addLast(x);
		}

		public int poll() {
			return removeFirst();
		}

		public void push(int x) {
			addFirst(x);
		}

		public int pop() {
			return removeFirst();
		}

		public int peek() {
			return peekFirst();
		}

		public int get(int i) {
			if (i >= len) {
				throw new ArrayIndexOutOfBoundsException(String.format("index %d out of range [0, %d)", i, len));
			}
			int idx = index(i + off);
			return arr[idx];
		}

		public void set(int i, int x) {
			if (i >= len) {
				throw new ArrayIndexOutOfBoundsException(String.format("index %d out of range [0, %d)", i, len));
			}
			int idx = index(i + off);
			arr[idx] = x;
		}

		public int size() {
			return len;
		}

		public boolean isEmpty() {
			return size() == 0;
		}
		
		public void clear() {
			off = 0;
			len = 0;
		}
		
		public void addAll(int... items) {
			while (items.length + len > arr.length) {
				increaseCapacity();
			}
			int idx = index(off + len);
			int backCap = arr.length - idx;
			if (backCap >= items.length) {
				System.arraycopy(items, 0, arr, idx, items.length);
			} else {
				System.arraycopy(items, 0, arr, idx, backCap);
				System.arraycopy(items, backCap, arr, 0, items.length - backCap);
			}
			len += items.length;
		}

		public int[] toArray() {
			if (len == 0) {
				return new int[0];
			}
			int idx = index(off + len);
			if (idx > off) {
				return Arrays.copyOfRange(arr, off, idx);
			}
			int[] A = new int[len];
			int endLen = arr.length - off;
			int startLen = len - endLen;
			System.arraycopy(arr, off, A, 0, endLen);
			System.arraycopy(arr, 0, A, endLen, startLen);
			return A;
		}

		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append('[');
			id2(sb, ", ");
			sb.append(']');
			return sb.toString();
		}

		private void increaseCapacity() {
			int[] next = new int[arr.length << 1];
			int endLen = arr.length - off;
			System.arraycopy(arr, off, next, 0, endLen);
			System.arraycopy(arr, 0, next, endLen, off);
			arr = next;
			off = 0;
		}

		private int index(int i) {
			if (i >= arr.length) {
				i -= arr.length;
			} else if (i < 0) {
				i += arr.length;
			}
			return i;
		}

		private void id2(StringBuilder sb, CharSequence sep) {
			for (int i = 0; i < len; ++i) {
				if (i > 0) {
					sb.append(sep);
				}
				sb.append(get(i));
			}
		}

		public static IntDeque of(int... arr) {
			IntDeque deq = new IntDeque();
			for (int x : arr) {
				deq.add(x);
			}
			return deq;
		}
	}
	
	public static class IntKey {
		public int value;

		private IntKey(int value) {
			this.value = value;
		}

		@Override
		public int hashCode() {
			return id5(value + id7);
		}

		@Override
		public boolean equals(Object obj) {
			IntKey other = (IntKey) obj;
			return value == other.value;
		}

		@Override
		public String toString() {
			return Integer.toString(value);
		}

		private static final int id5(int x) {
			int z = (x + 0x6D2B79F5);
			z = (z ^ (z >>> 15)) * (z | 1);
			z ^= z + (z ^ (z >>> 7)) * (z | 61);
			return z ^ (z >>> 14);
		}

		public static IntKey of(int value) {
			if (CACHE_MIN <= value && value < CACHE_MAX) {
				return CACHE[value - CACHE_MIN];
			}
			return new IntKey(value);
		}

		private static final int id7 = id5((int) System.nanoTime());

		private static final int CACHE_MIN = -256;
		private static final int CACHE_MAX = 256;
		private static final IntKey[] CACHE = new IntKey[CACHE_MAX - CACHE_MIN];
		static {
			for (int i = CACHE_MIN; i < CACHE_MAX; ++i) {
				CACHE[i - CACHE_MIN] = new IntKey(i);
			}
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
			while (id0(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id6(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (id0(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id0(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (id0(c))
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
			} while (!id0(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (id0(c))
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
			} while (!id0(c));
			return res * sgn;
		}

		

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] id3(int n) {
			return id3(n, 0);
		}

		public int[] id3(int n, int off) {
			int[] arr = new int[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextInt();
			}
			return arr;
		}

		public long[] id8(int n) {
			return id8(n, 0);
		}

		public long[] id8(int n, int off) {
			long[] arr = new long[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextLong();
			}
			return arr;
		}

		private boolean id0(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean id6(int c) {
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

	private static class Solution implements Runnable {
		@Override
		public void run() {
			FastIO io = new FastIO(System.in, System.out);
			solve(io);
			io.flush();
		}
	}

	public static void main(String[] args) throws InterruptedException {
		Thread t = new Thread(null, new Solution(), "Solution", 1 << 30);
		t.start();
		t.join();
	}
}