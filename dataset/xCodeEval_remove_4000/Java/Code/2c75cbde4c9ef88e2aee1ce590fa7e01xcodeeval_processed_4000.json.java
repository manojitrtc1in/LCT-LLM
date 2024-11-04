import java.io.*;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.NoSuchElementException;


public class Main {
	public static void main(String[] args) {
		long id4 = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			id4 = System.currentTimeMillis();
			try {
				inputStream = new FileInputStream("io/in.txt");


			} catch (Exception e) {
				System.err.println(e);
				System.exit(1);
			}
		} else {














		}
		Solver s = new Solver();
		s.in = new InputReader(inputStream);
		s.out = new OutputWriter(outputStream);
		if (args.length > 0 && args[0].equals("outside")) {
			s.debug = new DebugWriter(s.out);
		}
		s.solve();
		s.out.close();
		if (args.length > 0 && args[0].equals("outside")) {
			System.err.printf("*** Total time: %.3f ***\n", (System.currentTimeMillis() - id4) / 1000.0);
		}
	}
}

class Solver {
	InputReader in;
	OutputWriter out;
	DebugWriter debug;

	void solve() {
		int n = in.readInt();
		G = new Graph(n);
		int m = in.readInt();
		while (m-- > 0) {
			int a = in.readInt();
			int b = in.readInt();
			G.add(new SimpleEdge(a - 1, b - 1, false));
		}


		D = new int[n];
		bfs(0);
		marked = new int[n];
		dfs(n - 1);
		upDP = new long[n];
		downDP = new long[n];
		ArrayUtils.fill(upDP, -1);
		ArrayUtils.fill(downDP, -1);

		double best = 0;

		for (int v = 0; v < n; ++v)
			if (marked[v] == 1) {
				long val1 = countDown(v);
				long val2 = countUp(v);
				long val = val1 * val2;
	

	

	


				if (v != 0 && v != n - 1) val *= 2;
	

	


				double res = val / (double) countDown(n - 1);
				best = Math.max(best, res);
			}

		out.printLine(best);

























	}

	int[] D;
	Graph G;

	private void bfs(int v) {
		ArrayUtils.fill(D, -1);
		D[v] = 0;
		int[] Q = new int[D.length];
		int lo = 0;
		int hi = 0;
		Q[hi++] = v;
		while (lo != hi) {
			v = Q[lo++];
			for (Edge e : G.getIncident(v)) {
				int u = e.getDestination();
				if (D[u] == -1) {
					D[u] = D[v] + 1;
					Q[hi++] = u;
				}
			}
		}
	}

	int[] marked;

	private void dfs(int v) {
		if (marked[v] == 1) return;
		marked[v] = 1;
		for (Edge e : G.getIncident(v)) {
			int u = e.getDestination();
			if (D[v] == 1 + D[u])
				dfs(u);
		}
	}

	long[] upDP, downDP;

	long countUp(int v) {
		if (upDP[v] != -1) return upDP[v];
		if (v == D.length - 1) return upDP[v] = 1;
		long res = 0;
		for (Edge e : G.getIncident(v)) {
			int u = e.getDestination();
			if (D[v] + 1 == D[u] && marked[u] == 1)
				res += countUp(u);
		}
		return upDP[v] = res;
	}

	long countDown(int v) {
		if (downDP[v] != -1) return downDP[v];
		if (v == 0) return downDP[v] = 1;
		long res = 0;
		for (Edge e : G.getIncident(v)) {
			int u = e.getDestination();
			if (D[v] == 1 + D[u])
				res += countDown(u);
		}
		return downDP[v] = res;
	}
}

class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	private int read() {
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

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}

	public int readInt() {
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

	public long readLong() {
		int c = read();
		while (id2(c))
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
		} while (!id2(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id2(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id2(c));
		return res.toString();
	}

	public static boolean id2(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id0() {
		StringBuilder buf = new StringBuilder();
		int c = read();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public String readLine() {
		String s = id0();
		while (s.trim().length() == 0)
			s = id0();
		return s;
	}

	public String readLine(boolean id9) {
		if (id9)
			return readLine();
		else
			return id0();
	}

	public BigInteger id5() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id2(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id2(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id2(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!id2(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}

	public boolean id1() {
		int value;
		while (id2(value = peek()) && value != -1)
			read();
		return value == -1;
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void printLine(char[] objects) {
		writer.println(objects);
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}

	public void print(int[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(long[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(double[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(byte[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(boolean[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(int[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(long[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(byte[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(boolean[] objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}
}

class DebugWriter {
	private final OutputWriter writer;

	public DebugWriter(OutputWriter writer) {
		this.writer = writer;
	}

	private void id3() {
		writer.print("debug:\t");
	}

	public void print(Object... objects) {
		flush();
		id3();
		writer.print(objects);
		flush();
	}

	public void printLine(Object... objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(char[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		id3();
		writer.printFormat(format, objects);
		flush();
	}

	public void print(int[] objects) {
		flush();
		id3();
		writer.print(objects);
		flush();
	}

	public void print(long[] objects) {
		flush();
		id3();
		writer.print(objects);
		flush();
	}

	public void print(double[] objects) {
		flush();
		id3();
		writer.print(objects);
		flush();
	}

	public void print(byte[] objects) {
		flush();
		id3();
		writer.print(objects);
		flush();
	}

	public void print(boolean[] objects) {
		flush();
		id3();
		writer.print(objects);
		flush();
	}

	public void printLine(int[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(long[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(byte[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(boolean[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void flush() {
		writer.flush();
	}

	public void close() {
		writer.close();
	}
}

interface Edge {
	public int getSource();

	public int getDestination();

	public long getWeight();

	public long getCapacity();

	public long getFlow();

	public void pushFlow(long flow);

	public int getColor();

	public void setColor(int color);

	public boolean id6();

	public Edge id8();
}

class SimpleEdge implements Edge {
	protected final int source;
	protected final int destination;
	protected int color = -1;
	protected Edge reverseEdge = null;

	public SimpleEdge(int source, int destination, boolean directed) {
		this.source = source;
		this.destination = destination;
		if (!directed) reverseEdge = new id7();
	}

	@Override
	public int getSource() {
		return source;
	}

	@Override
	public int getDestination() {
		return destination;
	}

	@Override
	public long getWeight() {
		throw new UnsupportedOperationException();
	}

	@Override
	public long getCapacity() {
		throw new UnsupportedOperationException();
	}

	@Override
	public long getFlow() {
		throw new UnsupportedOperationException();
	}

	@Override
	public void pushFlow(long flow) {
		throw new UnsupportedOperationException();
	}

	@Override
	public int getColor() {
		return color;
	}

	@Override
	public void setColor(int color) {
		this.color = color;
	}

	@Override
	public boolean id6() {
		return reverseEdge != null;
	}

	@Override
	public Edge id8() {
		if (reverseEdge == null)
			throw new NoSuchFieldError();
		return reverseEdge;
	}

	@Override
	public String toString() {
		return "<(" + getSource() + " -> " + getDestination() + ") color : " + getColor() + ">";
	}

	protected class id7 implements Edge {
		@Override
		public int getSource() {
			return destination;
		}

		@Override
		public int getDestination() {
			return source;
		}

		@Override
		public long getWeight() {
			throw new UnsupportedOperationException();
		}

		@Override
		public long getCapacity() {
			throw new UnsupportedOperationException();
		}

		@Override
		public long getFlow() {
			throw new UnsupportedOperationException();
		}

		@Override
		public void pushFlow(long flow) {
			throw new UnsupportedOperationException();
		}

		@Override
		public int getColor() {
			return color;
		}

		@Override
		public void setColor(int color) {
			SimpleEdge.this.setColor(color);
		}

		@Override
		public boolean id6() {
			return true;
		}

		@Override
		public Edge id8() {
			return SimpleEdge.this;
		}

		@Override
		public String toString() {
			return "<(" + getSource() + " -> " + getDestination() + ") color : " + getColor() + ">";
		}
	}
}

class Graph {
	private Node[] firstEdge;
	private HashSet<Edge> edgeRemove;

	public Graph(int length) {
		edgeRemove = new HashSet<Edge>();
		firstEdge = new Node[length];
	}

	public void add(Edge edge) {
		Node v = new Node(edge);
		if (firstEdge[edge.getSource()] == null) firstEdge[edge.getSource()] = v;
		else {
			v.next = firstEdge[edge.getSource()];
			firstEdge[edge.getSource()].previous = v;
			firstEdge[edge.getSource()] = v;
		}
		if (edge.id6()) {
			edge = edge.id8();
			v = new Node(edge);
			if (firstEdge[edge.getSource()] == null) firstEdge[edge.getSource()] = v;
			else {
				v.next = firstEdge[edge.getSource()];
				firstEdge[edge.getSource()].previous = v;
				firstEdge[edge.getSource()] = v;
			}
		}
	}

	public void remove(Edge edge) {
		if (!edgeRemove.contains(edge)) edgeRemove.add(edge);
		if (edge.id6()) edgeRemove.add(edge.id8());
	}

	public void remove(int vertex) {
		for (Edge edge : getIncident(vertex))
			remove(edge);
	}

	public Iterable<Edge> getIncident(final int vertex) {
		return new Iterable<Edge>() {
			@Override
			public Iterator<Edge> iterator() {
				return new EdgeIterator(vertex);
			}
		};
	}

	public void show(DebugWriter writer) {
		writer.printLine("graph:");
		for (int i = 0; i < firstEdge.length; ++i) {
			writer.printLine("\tincident to vertex [" + i + "]: ");
			for (Edge edge : getIncident(i))
				writer.printLine("\t\t" + edge);
		}
	}

	private class EdgeIterator implements Iterator<Edge> {
		private Node last, current;

		private EdgeIterator(int vertex) {
			while (firstEdge[vertex] != null && toRemove(firstEdge[vertex].edge))
				Graph.this.remove(firstEdge[vertex]);
			current = firstEdge[vertex];
		}

		@Override
		public boolean hasNext() {
			return current != null;
		}

		@Override
		public Edge next() {
			if (!hasNext()) throw new NoSuchElementException();
			last = current;
			current = current.next;
			while (current != null && toRemove(current.edge)) {
				Node next = current.next;
				Graph.this.remove(current);
				current = next;
			}
			return last.edge;
		}

		@Override
		public void remove() {
			if (last == null) throw new IllegalStateException();
			Graph.this.remove(last);
			last = null;
		}
	}

	private boolean toRemove(Edge edge) {
		return edgeRemove.contains(edge);
	}

	private void remove(Node node) {
		if (node.previous == null) firstEdge[node.edge.getSource()] = node.next;
		if (node.next == null) node.previous.next = null;
		node.previous.next = node.next;
		edgeRemove.remove(node.edge);
	}

	private class Node {
		public Edge edge;
		public Node next = null;
		public Node previous = null;

		public Node(Edge edge) {
			this.edge = edge;
		}
	}
}

class ArrayUtils {
	

	public static void fill(int[] array, int value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public static void fill(int[][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(int[][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(int[][][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(int[][][][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(int[][][][][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public static void fill(long[] array, long value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public static void fill(long[][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(long[][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(long[][][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(long[][][][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(long[][][][][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public static void fill(double[] array, double value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public static void fill(double[][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(double[][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(double[][][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(double[][][][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(double[][][][][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public static void fill(boolean[] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public static void fill(boolean[][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(boolean[][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(boolean[][][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(boolean[][][][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(boolean[][][][][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public static void fill(byte[] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public static void fill(byte[][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(byte[][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(byte[][][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(byte[][][][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(byte[][][][][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public static void fill(char[] array, char value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public static void fill(char[][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(char[][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(char[][][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(char[][][][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public static void fill(char[][][][][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}
}

