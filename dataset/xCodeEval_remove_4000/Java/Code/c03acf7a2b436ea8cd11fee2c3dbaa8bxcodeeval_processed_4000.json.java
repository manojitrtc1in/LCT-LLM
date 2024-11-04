import java.io.*;
import java.util.*;

public class id5 {
	private static final int id7 = 1;
	
	private static void debug() {






































































































	}
	
	private static class AK {
		public int[] A;
		public int K;
		
		public AK(int[] A, int K) {
			this.A = A;
			this.K = K;
		}
	}
	
	private static int[] makeB(int[] A, int K) {
		final int N = A.length - 1;
		int[] B = new int[N + 1];
		for (int i = 1; i <= N; ++i) {
			int x = A[i];
			if (x <= K) {
				B[x] = id3(A, i, K);
			} else {
				B[x] = id6(A, i, K);
			}
		}
		return B;
	}
	
	private static int id3(int[] A, int i, int K) {
		for (int j = i - 1; j >= 0; --j) {
			if (A[j] > K) {
				return A[j];
			}
		}
		return A.length;
	}
	
	private static int id6(int[] A, int i, int K) {
		for (int j = i - 1; j >= 0; --j) {
			if (A[j] <= K) {
				return A[j];
			}
		}
		return 0;
	}
	
	public static void solveCase(FastIO io, int testCase) {
		final int N = io.nextInt();
		final int[] B = io.id2(N, 1);
		
		if (testCase == 1) {
			debug();
		}
		
		int[] A = solveIt(N, B);
		
		io.println(A[0]);
		io.printlnArray(Arrays.copyOfRange(A, 1, N + 1));
	}
	
	private static int[] solveIt(int N, int[] B) {
		int[] minPrefix = new int[N + 1];
		minPrefix[0] = N + 1;
		for (int i = 1; i <= N; ++i) {
			minPrefix[i] = Math.min(minPrefix[i - 1], B[i]);
		}
		
		int[] maxSuffix = new int[N + 1];
		maxSuffix[0] = 0;
		for (int i = 1; i <= N; ++i) {
			maxSuffix[i] = Math.max(maxSuffix[i - 1], B[N - i + 1]);
		}
		
		int k;
		for (int i = 0; ; ++i) {
			if (minPrefix[i] > i && maxSuffix[N - i] <= i) {
				k = i;
				break;
			}
		}
		


		
		if (k == 0) {
			int[] A = new int[N + 1];
			for (int i = 1; i <= N; ++i) {
				A[i] = i;
			}
			return A;
		}
		
		int[] A = reconstruct(B, k);
		A[0] = k;
		return A;




	}
	
	private static int[] reconstruct(int[] B, int K) {
		final int N = B.length - 1;
		LLNode[] nodes = new LLNode[N + 2];
		nodes[0] = nodes[N + 1] = new LLNode(-1);
		for (int i = 1; i <= N; ++i) {
			nodes[i] = new LLNode(i);
		}
		
		for (int i = 1; i <= N; ++i) {


			nodes[B[i]].insertNext(nodes[i]);


		}
		
		ArrayList<Integer> output = new ArrayList<>();
		dfs(nodes[0], output);
		
		int[] A = new int[N + 1];
		A[0] = K;
		for (int i = 1; i <= N; ++i) {
			A[i] = output.get(i);
		}
		return A;
		
















	}
	
	private static void dfs(LLNode u, ArrayList<Integer> output) {
		output.add(u.value);
		Collections.sort(u.next, new Comparator<LLNode>() {
			@Override
			public int compare(LLNode a, LLNode b) {
				return Integer.compare(a.next.size(), b.next.size());
			}
		});
		for (LLNode v : u.next) {
			dfs(v, output);
		}
	}
	
















	
	public static class LLNode {
		int value;
		public ArrayList<LLNode> next = new ArrayList<>();
		
		public LLNode(int value) {
			this.value = value;
		}
		
		public void insertNext(LLNode node) {




			
			next.add(node);
		}
	}
	







































































	public static void solve(FastIO io) {
		final int T = io.nextInt();

		for (int t = 0; t < T; ++t) {
			solveCase(io, id7 + t);
		}
	}

	
	public static class Permutations {
		public static <T> List<T[]> objects(T[] arr) {
			CountMap<T> cm = new CountMap<>();
			for (T v : arr) {
				cm.increment(v, 1);
			}
			
			ArrayList<Freq<T>> freq = new ArrayList<>();
			for (Map.Entry<T, Integer> kvp : cm.entrySet()) {
				freq.add(new Freq<>(kvp.getKey(), kvp.getValue()));
			}

			List<List<T>> ans = new ArrayList<>();
			permute(freq, null, new ArrayList<T>(arr.length), ans);

			List<T[]> perms = new ArrayList<>(ans.size());
			T[] empty = Arrays.copyOf(arr, 0);
			for (List<T> lst : ans) {
				perms.add(lst.toArray(empty));
			}
			return perms;
		}

		public static List<int[]> ints(int[] arr) {
			Integer[] objs = Arrays.stream(arr).mapToObj(Integer::valueOf).toArray(Integer[]::new);
			List<Integer[]> perms = objects(objs);

			List<int[]> ans = new ArrayList<>(perms.size());
			for (Integer[] p : perms) {
				ans.add(Arrays.stream(p).mapToInt(Integer::intValue).toArray());
			}
			return ans;
		}

		private static <T> void permute(ArrayList<Freq<T>> freq, Freq<T> lastUsed, ArrayList<T> curr, List<List<T>> ans) {
			if (freq.size() == 1 && Freq.isZero(lastUsed)) {
				Freq<T> f = freq.get(0);
				ArrayList<T> lst = new ArrayList<>(curr);
				lst.addAll(Collections.nCopies(f.count, f.value));
				ans.add(lst);
				return;
			}

			int startIndex = 0;
			if (!Freq.isZero(lastUsed)) {
				startIndex = 1;
				freq.add(lastUsed);
				swap(freq, 0, freq.size() - 1);
			}

			for (int i = startIndex; i < freq.size(); ++i) {
				swap(freq, i, freq.size() - 1);
				Freq<T> used = freq.remove(freq.size() - 1);

				int id1 = used.count;
				for (int j = 1; j <= id1; ++j) {
					--used.count;
					curr.add(used.value);
					permute(freq, used, curr, ans);
				}
				for (int j = 1; j <= id1; ++j) {
					++used.count;
					curr.remove(curr.size() - 1);
				}

				freq.add(used);
				swap(freq, i, freq.size() - 1);
			}

			if (startIndex > 0) {
				swap(freq, 0, freq.size() - 1);
				freq.remove(freq.size() - 1);
			}
		}

		private static class Freq<T> {
			public T value;
			public int count;

			public Freq(T value, int count) {
				this.value = value;
				this.count = count;
			}

			public static <T> boolean isZero(Freq<T> f) {
				return f == null || f.count == 0;
			}
		}

		private static <T> void swap(ArrayList<T> lst, int i, int j) {
			T tmp = lst.get(i);
			lst.set(i, lst.get(j));
			lst.set(j, tmp);
		}

		private static class CountMap<T> extends HashMap<T, Integer> {
			public int getCount(T k) {
				return getOrDefault(k, 0);
			}
	
			public void increment(T k, int v) {
				int next = getCount(k) + v;
				if (next == 0) {
					remove(k);
				} else {
					put(k, next);
				}
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
			} while (!id4(c));
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

		public int[] id2(int n) {
			return id2(n, 0);
		}

		public int[] id2(int n, int off) {
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

		private boolean id4(int c) {
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