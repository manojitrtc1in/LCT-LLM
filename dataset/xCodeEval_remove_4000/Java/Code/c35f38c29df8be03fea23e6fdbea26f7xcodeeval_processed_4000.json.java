import java.io.*;
import java.util.*;

public class id15 {
	private static final int id17 = 1;
	
	static {


	}
	
	final int GRID_MAX = 16;
	
	private static void precompute() {
		ArrayList<Integer> id0 = new ArrayList<>();
		
		for (int N = 2; N <= 16; ++N) {
			for (int M = 2; M <= 16; ++M) {
				if (N != 16 || M != 11) {
					continue;
				}
				System.err.format("working: N = %d, M = %d\n", N, M);
				
				ArrayList<Point> points = new ArrayList<>();;
				for (int r0 = 1; r0 <= N; ++r0) {
					for (int c0 = 1; c0 <= M; ++c0) {
						points.add(new Point(r0, c0));
					}
				}

				ArrayList<PointPair> id2 = new ArrayList<>();
				for (int i = 0; i < points.size(); ++i) {
					for (int j = i + 1; j < points.size(); ++j) {
						id2.add(new PointPair(points.get(i), points.get(j)));
					}
				}
				
				HashSet<Integer> firstResults = new HashSet<>();
				Point firstGuess = new Point(1, 1);
				for (PointPair treasures : id2) {
					firstResults.add(evaluateGuess(treasures, firstGuess));
				}
				Point secondGuess = new Point(1, M);
				for (int firstResult : firstResults) {
					ArrayList<PointPair> id6 = id14(id2, firstGuess, firstResult);
					ArrayList<Integer> secondResults = new ArrayList<>();
					for (PointPair treasures : id6) {
						secondResults.add(evaluateGuess(treasures, secondGuess));
					}
					for (int secondResult : secondResults) {
						ArrayList<PointPair> id4 = id14(id6, secondGuess, secondResult);
						DecisionTree tree = construct(id4, points, 2);
						if (tree == null) {
							System.err.format("N = %d, M = %d, firstResult = %d, secondResult = %d, FAILURE\n", N, M, firstResult, secondResult);
							return;
						} else if (tree.guess != null) {
							System.err.format("N = %d, M = %d, firstResult = %d, secondResult = %d, thirdGuess = %s\n", N, M, firstResult, secondResult, tree.guess);


						}
					}
				}
			}
		}
		
		System.err.println("done");
	}
	
	private static int id8(int N, int M, int firstResult, Point secondGuess) {
		System.err.format("N = %d, M = %d, firstResult = %d, secondGuess = %s\n", N, M, firstResult, secondGuess);
		return (N << 18) | (M << 15) | (firstResult << 6) | (secondGuess.r << 3) | secondGuess.c;
	}
	
	public static void solveCase(FastIO io, int testCase) {
		final int N = io.nextInt();
		final int M = io.nextInt();
		
		ArrayList<Point> points = new ArrayList<>();;
		for (int r0 = 1; r0 <= N; ++r0) {
			for (int c0 = 1; c0 <= M; ++c0) {
				points.add(new Point(r0, c0));
			}
		}





		ArrayList<PointPair> id2 = new ArrayList<>();
		for (int i = 0; i < points.size(); ++i) {
			for (int j = i + 1; j < points.size(); ++j) {
				id2.add(new PointPair(points.get(i), points.get(j)));
			}
		}
		


		




		




















		










		
		Point firstGuess = new Point(1, 1);
		int firstResult = scan(io, firstGuess);
		id2 = id14(id2, firstGuess, firstResult);
		Point secondGuess = new Point(1, M);






















		int secondResult = scan(io, secondGuess);
		id2 = id14(id2, secondGuess, secondResult);
		DecisionTree tree = construct(id2, points, 2);


		while (id2.size() > 2) {
			int result = scan(io, tree.guess);
			id2 = id14(id2, tree.guess, result);
			tree = tree.id11.get(result);


		}
		
		assert(id2.size() <= 2);
		
		if (dig(io, id2.get(0).p.r, id2.get(0).p.c)) {
			if (!dig(io, id2.get(0).q.r, id2.get(0).q.c)) {
				HashSet<Point> dug = new HashSet<>();
				dug.add(id2.get(0).p);
				dug.add(id2.get(0).q);
				for (Point p : id2.get(1).both()) {
					if (dug.contains(p)) {
						continue;
					}
					dig(io, p.r, p.c);
				}
			}
		} else {
			dig(io, id2.get(1).p.r, id2.get(1).p.c);
			dig(io, id2.get(1).q.r, id2.get(1).q.c);
		}
		
		if (true) {
			return;
		}
		
		boolean[][] guessed = new boolean[N][M];
		for (int g = 0; g < 6; ++g) {
			Point bestPoint = null;
			
			
			
































































			
			
			
			
			
			
			
			while (true) {
				Point guess = points.get(Double.valueOf(Math.random() * points.size()).intValue());
				if (guessed[guess.r][guess.c]) {
					continue;
				}

				bestPoint = guess;
				break;
			}
			int id12 = scan(io, bestPoint.r, bestPoint.c);
			ArrayList<PointPair> id9 = new ArrayList<>();
			for (PointPair treasures : id2) {
				if (evaluateGuess(treasures, bestPoint) == id12) {
					id9.add(treasures);
				}
			}
			id2 = id9;
			guessed[bestPoint.r][bestPoint.c] = true; 
			
			System.err.format("g = %d, id2.size() = %d\n", g, id2.size());
		}
		
		if (dig(io, id2.get(0).p.r, id2.get(0).p.c)) {
			dig(io, id2.get(0).q.r, id2.get(0).q.c);
		} else {
			dig(io, id2.get(1).p.r, id2.get(1).p.c);
			dig(io, id2.get(1).q.r, id2.get(1).q.c);
		}
	}
	
	private static void sortPoints(ArrayList<Point> points) {
		PointList[] buckets = new PointList[17];
		for (int i = 1; i < buckets.length; ++i) {
			buckets[i] = new PointList();
		}
		for (Point p : points) {
			int b = Math.max(p.r, p.c);
			buckets[b].add(p);
		}
		
		points.clear();
		for (int i = 1; i < buckets.length; ++i) {
			points.addAll(buckets[i]);
		}
	}
	
	private static class PointList extends ArrayList<Point> {}
	
	private static class DecisionTree {
		public Point guess;
		public HashMap<Integer, DecisionTree> id11 = new HashMap<>();
	}
	
	private static void printTree(DecisionTree t, int indent) {
		for (Map.Entry<Integer, DecisionTree> kvp : t.id11.entrySet()) {
			System.err.format("%s%s -- %d -->\n", " ".repeat(indent), t.guess, kvp.getKey());
			printTree(kvp.getValue(), indent + 4);
		}
	}
	
	private static ArrayList<PointPair> id14(ArrayList<PointPair> id2, Point guess, int result) {
		ArrayList<PointPair> id5 = new ArrayList<>();
		for (PointPair treasures : id2) {
			if (evaluateGuess(treasures, guess) == result) {
				id5.add(treasures);
			}
		}
		return id5;
	}
	
	private static DecisionTree construct(ArrayList<PointPair> id2, ArrayList<Point> points, int id10) {
		return constructInternal(id2, points, id10, new HashSet<Point>());
	}

	private static DecisionTree constructInternal(ArrayList<PointPair> id2, ArrayList<Point> points, int id10, HashSet<Point> seen) {
		if (id2.size() == 0) {
			return null;
		}
		
		if (id2.size() <= 2) {
			return new DecisionTree();
		}
		
		if (id10 <= 0) {
			return null;
		}
		
		ArrayList<Point> iterPoints = new ArrayList<>(points);




		for (Point p : iterPoints) {
			if (p.r == 1 && p.c == 1) {
				continue;
			}
			if (seen.contains(p)) {
				continue;
			}
			seen.add(p);
			
			DecisionTree tree = new DecisionTree();
			tree.guess = p;
			
			if (id10 == 4 && p != points.get(0)) {
				continue;
			}












			HashMap<Integer, ArrayList<PointPair>> id16 = new HashMap<>();
			for (PointPair t : id2) {
				int result = evaluateGuess(t, p);
				ArrayList<PointPair> lst = id16.getOrDefault(result, null);
				if (lst == null) {
					lst = new ArrayList<>();
					id16.put(result, lst);
				}
				lst.add(t);
			}
			boolean good = true;
			tree.id11.clear();
			for (Map.Entry<Integer, ArrayList<PointPair>> kvp : id16.entrySet()) {
				ArrayList<PointPair> id13 = kvp.getValue();
				int result = kvp.getKey();
				
				DecisionTree next = construct(id13, points, id10 - 1);
				tree.id11.put(result, next);
				if (!doable(id13, points, id10 - 1)) {
					good = false;
					break;
				}
			}
			if (good) {
				return tree;
			}
			
			seen.remove(p);
		}
		return null;
	}
	
	private static boolean doable(ArrayList<PointPair> id2, ArrayList<Point> points, int id10) {
		if (id2.size() <= 2) {
			return true;
		}
		
		if (id10 <= 0) {
			return false;
		}
		
		ArrayList<Point> iterPoints = new ArrayList<>(points);
		Collections.shuffle(iterPoints);
		Collections.sort(iterPoints, new Comparator<Point>() {
			@Override
			public int compare(Point a, Point b) {
				return Integer.compare(Math.max(a.r, a.c), Math.max(b.r, b.c));
			}
		});
		for (Point p : iterPoints) {
			if (id10 == 4 && p != points.get(0)) {
				continue;
			}












			HashMap<Integer, ArrayList<PointPair>> id16 = new HashMap<>();
			for (PointPair t : id2) {
				int result = evaluateGuess(t, p);
				ArrayList<PointPair> lst = id16.getOrDefault(result, null);
				if (lst == null) {
					lst = new ArrayList<>();
					id16.put(result, lst);
				}
				lst.add(t);
			}
			boolean good = true;
			for (ArrayList<PointPair> id13 : id16.values()) {
				if (!doable(id13, points, id10 - 1)) {
					good = false;
					break;
				}
			}
			if (good) {
				return true;
			}
		}
		return false;
	}
	










































	
	private static boolean validate(ArrayList<PointPair> id2, Point[] guesses) {
		CountMap<ArrayList<Integer>> seen = new CountMap<>();
		for (PointPair treasures : id2) {
			ArrayList<Integer> results = new ArrayList<>(guesses.length);
			for (Point guess : guesses) {
				results.add(evaluateGuess(treasures, guess));
			}
			seen.increment(results, 1);
		}


		for (long f : seen.values()) {
			if (f > 2) {
				return false;
			}
		}
		return true;






	}
	
	private static int scan(FastIO io, Point p) {
		return scan(io, p.r, p.c);
	}
	
	private static int scan(FastIO io, int r, int c) {
		io.printf("SCAN %d %d\n", r, c);
		io.flush();
		return io.nextInt();
	}
	
	private static boolean dig(FastIO io, int r, int c) {
		io.printf("DIG %d %d\n", r, c);
		io.flush();
		return io.nextInt() == 1;
	}
	
	private static class Point {
		public int r, c;
		
		public Point(int r, int c) {
			this.r = r;
			this.c = c;
		}
		
		@Override
		public int hashCode() {
			return 4051 * r + 101419 * c;
		}
		
		@Override
		public boolean equals(Object other) {
			Point p = (Point)other;
			return r == p.r && c == p.c;
		}
		
		@Override
		public String toString() {
			return String.format("(%d, %d)", r, c);
		}
	}
	
	private static class PointPair {
		public Point p, q;
		
		public PointPair(Point p, Point q) {
			this.p = p;
			this.q = q;
		}
		
		public Point[] both() {
			return new Point[] { p, q };
		}
	}
	
	private static int evaluateGuess(PointPair treasures, Point guess) {


		return Math.abs(treasures.p.r - guess.r) + Math.abs(treasures.p.c - guess.c) + Math.abs(treasures.q.r - guess.r) + Math.abs(treasures.q.c - guess.c);
	}
	

























	public static void solve(FastIO io) {
		final int T = io.nextInt();

		for (int t = 0; t < T; ++t) {
			solveCase(io, id17 + t);
		}
	}
	
    public static class CountMap<T> extends HashMap<T, Long> {
        public long getCount(T k) {
            return getOrDefault(k, 0L);
        }

        public void increment(T k, int v) {
            long next = getCount(k) + v;
            if (next == 0) {
                remove(k);
            } else {
                put(k, next);
            }
        }
   
        public static <T> CountMap<T> fromArray(T[] A) {
            CountMap<T> cm = new CountMap<>();
            for (T x : A) {
                cm.increment(x, 1);
            }
            return cm;
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

		public long[] id18(int n) {
			return id18(n, 0);
		}

		public long[] id18(int n, int off) {
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