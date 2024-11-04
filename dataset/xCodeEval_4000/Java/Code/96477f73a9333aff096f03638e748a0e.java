import java.io.*;
import java.math.*;
import java.util.*;

public class WeightTheTree {
	public static void solve(FastIO io) {
		final int N = io.nextInt();
		
		Node[] nodes = new Node[N + 1];
		for (int i = 1; i <= N; ++i) {
			nodes[i] = new Node(i);
		}
		
		for (int i = 1; i < N; ++i) {
			final int U = io.nextInt();
			final int V = io.nextInt();
			
			nodes[U].next.add(nodes[V]);
			nodes[V].next.add(nodes[U]);
		}
		
		if (N == 2) {
			io.println(2, 2);
			io.println(1, 1);
			return;
		}
		
		root(nodes[1], null);
		MemoData[][] memo = new MemoData[2][N + 1];
		
		MemoData happyResult = get(HAPPY, nodes[1], memo);
		MemoData unhappyResult = get(UNHAPPY, nodes[1], memo);
		MemoData result = betterResult(happyResult, unhappyResult);
		boolean[] markHappy = new boolean[N + 1];
		if (result == happyResult) {
			mark(HAPPY, nodes[1], memo, markHappy);
		} else {
			mark(UNHAPPY, nodes[1], memo, markHappy);
		}
		
		
		int goodCount = 0;
		int weightSum = 0;
		int[] nodeValues = new int[N + 1];
		for (int i = 1; i <= N; ++i) {
			if (markHappy[i]) {
				++goodCount;
				nodeValues[i] = nodes[i].next.size();
				if (i > 1) {
					++nodeValues[i];
				}
			} else {
				nodeValues[i] = 1;
			}
			weightSum += nodeValues[i];
		}

		io.println(goodCount, weightSum);
		io.printlnArray(Arrays.copyOfRange(nodeValues, 1, N + 1));
		
		
		if (N > 0) {
			return;
		}
		
		
		
		
		
		
		
		
		
		
		
		PriorityQueue<NodeValue> pq = new PriorityQueue<>(new Comparator<NodeValue>() {
			@Override
			public int compare(NodeValue a, NodeValue b) {
				return Integer.compare(a.value, b.value);
			}
		});
		TreeSet<NodeValue> ts = new TreeSet<>(new Comparator<NodeValue>() {
			@Override
			public int compare(NodeValue a, NodeValue b) {
				int dv = Integer.compare(a.value, b.value);
				if (dv != 0) {
					return dv;
				}
				return Integer.compare(a.node.id, b.node.id);
			}
		});
		int visited = 0;
		int[] updates = new int[N + 1];
		int[] values = new int[N + 1];
		boolean[] fixed = new boolean[N + 1];
		for (int i = 1; i <= N; ++i) {
			if (nodes[i].next.size() == 1) {
				values[i] = 1;
				updates[i] = 1;
				fixed[i] = true;
				
				Node parent = nodes[i].next.get(0);
				++updates[parent.id];
				values[parent.id] = 1;
				++visited;
				if (!fixed[parent.id] && parent.next.size() > 1) {


					pq.offer(new NodeValue(parent, values[parent.id]));
					ts.add(new NodeValue(parent, values[parent.id]));
				}
				fixed[i] = true;
				fixed[parent.id] = true; 
			}
		}
		
		int[] theoreticalGood = new int[N + 1];
		Arrays.fill(theoreticalGood, 1);
		for (int i = 1; i <= N; ++i) {
			if (nodes[i].next.size() == 1) {
				Node parent = nodes[i].next.get(0);
				if (parent.next.size() > 1) {
					theoreticalGood[parent.id] = 0;
				}
			}
		}
		int theoreticalGoodCount = 0;
		for (int i = 1; i <= N; ++i) {
			theoreticalGoodCount += theoreticalGood[i];
		}
		
		
		while (!ts.isEmpty()) {
			NodeValue nv = ts.first();
			ts.remove(nv);
			
			Node u = nv.node;
			fixed[u.id] = true;
			
			for (Node v : u.next) {
				if (!fixed[v.id]) {
					NodeValue item = new NodeValue(v, values[v.id]);
					ts.remove(item);
					values[v.id] += values[u.id];
					ts.add(new NodeValue(v, values[v.id]));
				}
			}
		}
		
		int good = 0;
		for (int i = 1; i <= N; ++i) {
			int neighborSum = 0;
			for (Node v : nodes[i].next) {
				neighborSum += values[v.id];
			}
			if (values[i] == neighborSum) {
				++good;
			}
		}
		
		long valueSum = 0;
		for (int i = 1; i <= N; ++i) {
			valueSum += values[i];
		}
		
		if (theoreticalGoodCount != good) {
			System.out.format("FAIL: want good %d, got %d\n", theoreticalGoodCount, good);
		}
		
		io.println(good, valueSum);
		io.printlnArray(Arrays.copyOfRange(values, 1, N + 1));
		
		if (N > 0) {
			return;
		}
		
		boolean[] queued = new boolean[N + 1];
		while (!pq.isEmpty()) {
			NodeValue nv = pq.poll();
			System.out.format("working on: %d\n", nv.node.id);
			for (Node v : nv.node.next) {
				if (!fixed[v.id] && !queued[v.id] && updates[v.id] < v.next.size()) {
					System.out.format("  propagating value = %d: %d -> %d\n", values[nv.node.id], nv.node.id, v.id);
					++updates[nv.node.id];
					++updates[v.id];
					values[v.id] += values[nv.node.id];
					queued[v.id] = true;
					pq.offer(new NodeValue(v, values[v.id]));
				}
			}
			if (1 + 1 == 2) {
				continue;
			}
			
			++visited;








			


			
			Node parent = null;
			for (Node v : nv.node.next) {
				if (!fixed[v.id] && updates[v.id] < v.next.size()) {


					if (parent != null) {
						System.out.println("FAIL!");
					}
					parent = v;


				}
			}
			if (parent == null) {
				continue;
			}


			
			++updates[nv.node.id];
			++updates[parent.id];
			values[parent.id] += values[nv.node.id]; 
			if (updates[parent.id] == parent.next.size() - 1) {


				pq.offer(new NodeValue(parent, values[parent.id]));
			}
		}
		
		if (visited != N) {
			System.out.format("FAIL: visited %d of %d nodes\n", visited, N);
		}
		




































	}
	
	private static final int UNHAPPY = 0;
	private static final int HAPPY = 1;
	
	private static MemoData get(int isHappy, Node u, MemoData[][] memo) {
		if (memo[isHappy][u.id] == null) {
			if (isHappy == HAPPY) {
				int maxHappiness = 1;
				int minWeight = u.next.size();
				if (u.id > 1) {
					++minWeight;
				}
				for (Node v : u.next) {
					MemoData result = get(UNHAPPY, v, memo);
					maxHappiness += result.maxHappiness;
					minWeight += result.minWeight;
				}
				memo[isHappy][u.id] = new MemoData(maxHappiness, minWeight);
			} else {
				int maxHappiness = 0;
				int minWeight = 1;
				for (Node v : u.next) {
					MemoData happyResult = get(HAPPY, v, memo);
					MemoData unhappyResult = get(UNHAPPY, v, memo);
					MemoData result;
					if (happyResult.maxHappiness > unhappyResult.maxHappiness) {
						result = happyResult;
					} else if (happyResult.maxHappiness < unhappyResult.maxHappiness) {
						result = unhappyResult;
					} else if (happyResult.minWeight < unhappyResult.minWeight) {
						result = happyResult;
					} else {
						result = unhappyResult;
					}
					maxHappiness += result.maxHappiness;
					minWeight += result.minWeight;
				}
				memo[isHappy][u.id] = new MemoData(maxHappiness, minWeight); 
			}


		}
		return memo[isHappy][u.id];
	}
	
	private static void mark(int isHappy, Node u, MemoData[][] memo, boolean[] outHappy) {
		if (isHappy == HAPPY) {
			outHappy[u.id] = true;
			for (Node v : u.next) {
				mark(UNHAPPY, v, memo, outHappy);
			}
		} else {
			for (Node v : u.next) {
				MemoData happyResult = get(HAPPY, v, memo);
				MemoData unhappyResult = get(UNHAPPY, v, memo);
				MemoData result = betterResult(happyResult, unhappyResult);
				if (result == happyResult) {
					mark(HAPPY, v, memo, outHappy);
				} else {
					mark(UNHAPPY, v, memo, outHappy);
				}
			}
		}
	}
	
	private static MemoData betterResult(MemoData a, MemoData b) {
		if (a.maxHappiness > b.maxHappiness) {
			return a;
		} else if (a.maxHappiness < b.maxHappiness) {
			return b;
		} else if (a.minWeight < b.minWeight) {
			return a;
		} else {
			return b;
		}
	}
	
	private static void root(Node u, Node p) {
		u.next.remove(p);
		for (Node v : u.next) {
			root(v, u);
		}
	}
	
	private static class MemoData {
		public int maxHappiness;
		public int minWeight;
		
		public MemoData(int maxHappiness, int minWeight) {
			this.maxHappiness = maxHappiness;
			this.minWeight = minWeight;
		}
	}
	
	private static class NodeValue {
		public Node node;
		public int value;
		
		public NodeValue(Node node, int value) {
			this.node = node;
			this.value = value;
		}
	}
	










	
	private static class Node {
		public int id;
		public ArrayList<Node> next = new ArrayList<>();
		
		public Node(int id) {
			this.id = id;
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