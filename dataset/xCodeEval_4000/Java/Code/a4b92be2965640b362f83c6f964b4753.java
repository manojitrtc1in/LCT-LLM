import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	private static final int START_TEST_CASE = 1;

	private static final int A_MAX = 1_000_000_000;

	

	


	public static void solveCase(FastIO io, int testCase) {
		final int N = io.nextInt();
		final int K = io.nextInt();
		final int[] A = io.nextIntArray(N);

		if (K >= N) {
			io.println(A_MAX);
			return;
		}

		if (N == 2) {
			io.println(Math.max(A[0], A[1]));
			return;
		}

		IndexNum[] nums = new IndexNum[N];
		for (int i = 0; i < N; ++i) {
			nums[i] = new IndexNum(i, A[i]);
		}

		int[] state = new int[N];
		TreeSet<IndexNum> obliterated = new TreeSet<>(IndexNum.BY_VALUE_THEN_INDEX);
		TreeSet<IndexNum> intact = new TreeSet<>(IndexNum.BY_VALUE_THEN_INDEX);
		for (int i = 0; i < N; ++i) {
			intact.add(nums[i]);
		}
		for (int i = 0; i < K; ++i) {
			IndexNum num = intact.pollFirst();
			obliterated.add(num);
		}

		int best = 0;
		for (int i = 1; i < N; ++i) {
			IndexNum a = nums[i - 1];
			IndexNum b = nums[i];

			ArrayList<IndexNum> restoreObliterate = new ArrayList<>();

			

			

			{
				


				obliterated.remove(a);
				obliterated.remove(b);
				restoreObliterate.add(a);
				restoreObliterate.add(b);
				intact.remove(a);
				intact.remove(b);

				while (!intact.isEmpty() && obliterated.size() < K) {
					IndexNum x = intact.pollFirst();
					obliterated.add(x);
				}

				int dist = Math.min(A[a.index], A[b.index]);
				if (!intact.isEmpty()) {
					dist = Math.min(dist, intact.first().value << 1);
				}
				best = Math.max(best, dist);

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

				

			}

			

			{
				

				while (!obliterated.isEmpty() && obliterated.size() + 1 > K) {
					IndexNum x = obliterated.pollLast();
					restoreObliterate.add(x);
					intact.add(x);
				}
				int dist = Math.max(A[a.index], A[b.index]);
				if (!intact.isEmpty()) {
					dist = Math.min(dist, intact.first().value << 1);
				}
				best = Math.max(best, dist);
			}

			

			if (K > 1) {
				

				while (!obliterated.isEmpty() && obliterated.size() + 2 > K) {
					IndexNum x = obliterated.pollLast();
					restoreObliterate.add(x);
					intact.add(x);
				}
				int dist = A_MAX;
				if (!intact.isEmpty()) {
					dist = Math.min(dist, intact.first().value << 1);
				}
				best = Math.max(best, dist);
			}

			


			for (IndexNum x : restoreObliterate) {
				obliterated.add(x);
				intact.remove(x);
			}
			

			while (obliterated.size() > K) {
				IndexNum x = obliterated.pollLast();
				

				intact.add(x);
			}

			

		}
		io.println(best);

		if (N > 0) {
			return;
		}

		

		

		

		


		GenericSegmentTree<IndexNum> gst = new GenericSegmentTree<>(
				N,
				new GenericSegmentTree.Combiner<IndexNum>() {
					@Override
					public IndexNum combine(IndexNum a, IndexNum b) {
						if (a == null) {
							return b;
						}
						if (b == null) {
							return a;
						}
						if (a.value < b.value) {
							return a;
						}
						return b;
					}
				},
				new GenericSegmentTree.DefaultProvider<IndexNum>() {
					@Override
					public IndexNum getDefault() {
						return null;
					}
				});

		for (int i = 0; i < N; ++i) {
			gst.insert(i, nums[i]);
		}

		int hero = -1;
		int maxPower = -1;
		for (int i = 0; i < N; ++i) {
			int p = computePower(i, A, gst);
			if (p > maxPower) {
				hero = i;
				maxPower = p;
			}
		}

		for (int z = 0; z < K; ++z) {

		}

		

		

		

		


		


		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		

		

		

		

		

		

		

		

		

		

	}

	private static class MultiSet<T> {
		public TreeMap<T, Integer> tm;
		public int size;

		public void add(T item, int count) {
			int val = count + tm.getOrDefault(item, 0);
			if (val == 0) {
				tm.remove(item);
			} else {
				tm.put(item, count);
			}
			size += count;
		}
	}

	private static int computePower(int i, int[] A, GenericSegmentTree<IndexNum> gst) {
		final int N = A.length;

		int diam = 0;
		if (i > 0) {
			int lEdge = Math.min(A[i], A[i - 1]);
			int lSmall = A_MAX;
			if (i - 2 >= 0) {
				lSmall = Math.min(lSmall, gst.get(0, i - 2).value);
			}
			if (i + 1 < N) {
				lSmall = Math.min(lSmall, gst.get(i + 1, N - 1).value);
			}
			lEdge = Math.min(lEdge, lSmall << 1);
			diam = Math.max(diam, lEdge);
		}
		if (i + 1 < N) {
			int rEdge = Math.min(A[i], A[i + 1]);
			int rSmall = A_MAX;
			if (i - 1 >= 0) {
				rSmall = Math.min(rSmall, gst.get(0, i - 1).value);
			}
			if (i + 2 < N) {
				rSmall = Math.min(rSmall, gst.get(i + 2, N - 1).value);
			}
			rEdge = Math.min(rEdge, rSmall << 1);
			diam = Math.max(diam, rEdge);
		}
		return diam;
	}

	private static class IndexNum {
		public int index;
		public int value;

		public IndexNum(int index, int value) {
			this.index = index;
			this.value = value;
		}

		@Override
		public String toString() {
			return String.format("{%d, %d}", index, value);
		}

		public static final Comparator<IndexNum> BY_VALUE = new Comparator<IndexNum>() {
			@Override
			public int compare(IndexNum a, IndexNum b) {
				return Integer.compare(a.value, b.value);
			}
		};

		public static final Comparator<IndexNum> BY_VALUE_THEN_INDEX = new Comparator<IndexNum>() {
			@Override
			public int compare(IndexNum a, IndexNum b) {
				int dv = Integer.compare(a.value, b.value);
				if (dv != 0) {
					return dv;
				}
				return Integer.compare(a.index, b.index);
			}
		};
	}

	
	public static class GenericSegmentTree<T> {
		public ArrayList<SegmentTreeNode> leaves;
		public SegmentTreeNode root;
		public Combiner<T> combiner;
		public DefaultProvider<T> defaultProvider;

		public GenericSegmentTree(int n, Combiner<T> cmb, DefaultProvider<T> defProv) {
			this.combiner = cmb;
			this.defaultProvider = defProv;
			this.leaves = new ArrayList<SegmentTreeNode>(n);
			for (int i = 0; i < n; ++i) {
				this.leaves.add(null);
			}
			this.root = new SegmentTreeNode(null, 0, n - 1);
		}

		public GenericSegmentTree(T[] vals, Combiner<T> cmb, DefaultProvider<T> defProv) {
			this(vals.length, cmb, defProv);
			for (int i = 0; i < vals.length; i++) {
				this.insert(i, vals[i]);
			}
		}

		public void insert(int idx, T v) {
			this.leaves.get(idx).setAndUpdate(v);
		}

		public T get(int idx) {
			return this.leaves.get(idx).val;
		}

		public T get(int lower, int upper) {
			return this.root.getRange(lower, upper);
		}

		public static interface Combiner<T> {
			public T combine(T lhs, T rhs);
		}

		public static interface DefaultProvider<T> {
			public T getDefault();
		}

		private class SegmentTreeNode {
			public int L;
			public int R;

			public T val;

			public SegmentTreeNode parent;
			public SegmentTreeNode left;
			public SegmentTreeNode rite;

			public SegmentTreeNode(SegmentTreeNode p, int lower, int upper) {
				this.parent = p;
				this.L = lower;
				this.R = upper;

				if (lower == upper) {
					

					leaves.set(lower, this);
				} else {
					int mid = (lower + upper) / 2;
					this.left = new SegmentTreeNode(this, lower, mid);
					this.rite = new SegmentTreeNode(this, mid + 1, upper);
				}
			}

			public void setAndUpdate(T v) {
				this.val = v;
				this.update();
			}

			public void update() {
				if (this.left != null && this.rite != null) {
					

					this.val = combiner.combine(this.left.val, this.rite.val);
				} else if (this.left != null) {
					this.val = this.left.val;
				} else if (this.rite != null) {
					this.val = this.rite.val;
				}

				if (this.parent != null) {
					this.parent.update();
				}
			}

			public T getRange(int lower, int upper) {
				if (this.L >= lower && this.R <= upper) {
					return this.val;
				} else if (this.L > upper || this.R < lower) {
					

					return defaultProvider.getDefault();
				} else {
					

					return combiner.combine(this.left.getRange(lower, upper), this.rite.getRange(lower, upper));
				}
			}
		}
	}

	
	public static class SparseTable {
		private int[][] table;

		public SparseTable(int[] a) {
			int n = a.length;
			int p = Integer.SIZE - Integer.numberOfLeadingZeros(n - 1);

			this.table = new int[n][p];

			for (int i = 0; i < n; i++) {
				this.table[i][0] = a[i];
			}
			for (int j = 1; j < p; j++) {
				for (int i = 0; i < n; i++) {
					int off = (1 << (j - 1));
					int next = (i + off >= n) ? Integer.MAX_VALUE : this.table[i + off][j - 1];
					this.table[i][j] = Math.min(this.table[i][j - 1], next);
				}
			}
		}

		public int getMin(int lower, int upper) {
			int k = (int) (Math.log(upper - lower + 1) / Math.log(2));
			int off = (1 << k);
			return Math.min(this.table[lower][k], this.table[upper - off + 1][k]);
		}
	}

	public static void solve(FastIO io) {
		final int T = io.nextInt();

		for (int t = 0; t < T; ++t) {
			solveCase(io, START_TEST_CASE + t);
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
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
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
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
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
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] nextIntArray(int n) {
			return nextIntArray(n, 0);
		}

		public int[] nextIntArray(int n, int off) {
			int[] arr = new int[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) {
			return nextLongArray(n, 0);
		}

		public long[] nextLongArray(int n, int off) {
			long[] arr = new long[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextLong();
			}
			return arr;
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
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