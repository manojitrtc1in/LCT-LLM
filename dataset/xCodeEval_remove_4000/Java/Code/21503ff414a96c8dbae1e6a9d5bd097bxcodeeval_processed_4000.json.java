import com.sun.org.apache.xerces.internal.dom.AttrNSImpl;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.NoSuchElementException;


public class Main implements Runnable {
	private static String[] args;

	public static void main(String[] args) {
		Main.args = args;
		new Thread(null, new Main(), "MyRunThread", 1 << 27).start();
	}

	@Override
	public void run() {
		long id5 = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			id5 = System.currentTimeMillis();
			try {
				inputStream = new FileInputStream("IO/in.txt");


			} catch (Exception e) {
				System.err.println(e);
				System.exit(1);
			}
		} else {
			try {




			} catch (Exception e) {
				System.err.println(e);
				System.exit(1);
			}
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
			s.debug.close();
			System.err.printf("*** Total time: %.3f ***\n", (System.currentTimeMillis() - id5) / 1000.0);
		}
	}
}

final class Solver {
	InputReader in;
	OutputWriter out;
	DebugWriter debug;

	public void solve() {
		int n = in.readInt();
		graph = new Graph(n);
		for (int i = 0; i < n - 1; ++i) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			Edge e = new SimpleEdge(a, b, true);
			e.setColor(0);
			graph.add(e);

			e = new SimpleEdge(b, a, true);
			e.setColor(1);
			graph.add(e);
		}
		rootDown = new int[n];
		rootUp = new int[n];
		up = new int[n];

		dfs(0, 0, 0, -1);

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; ++i) {
			int value = up[0] - rootUp[i] + rootDown[i];
			min = Math.min(min, value);
		}

		ArrayList<Integer> ans = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			int value = up[0] - rootUp[i] + rootDown[i];
			if (value == min) ans.add(i + 1);
		}

		out.printLine(min);
		out.printLine(ans.toArray(new Integer[0]));

	}

	Graph graph;
	int[] rootDown;
	int[] rootUp;
	int[] up;

	void dfs(int v, int nowUp, int nowDown, int parent) {
		rootUp[v] = nowUp;
		rootDown[v] = nowDown;
		for (Edge x : graph.getIncident(v))
			if (x.getDestination() != parent) {
				int dU = x.getColor() == 1 ? 1 : 0;
				int dD = x.getColor() == 0 ? 1 : 0;
				dfs(x.getDestination(), nowUp + dU, nowDown + dD, v);
				up[v] += up[x.getDestination()] + dU;
			}
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

	public String readLine(boolean id10) {
		if (id10)
			return readLine();
		else
			return id0();
	}

	public BigInteger id6() {
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

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}


	public void print(char[] objects) {
		writer.print(objects);
	}

	public void printLine(char[] objects) {
		writer.println(objects);
	}

	public void printLine(char[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(int[] objects) {
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

	public void printLine(int[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(long[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(long[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(long[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(double[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(double[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(double[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(byte[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(byte[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(byte[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(boolean[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(boolean[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(boolean[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
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


	public void printLine(Object... objects) {
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


	public void printLine(char[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(char[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(double[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(double[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(int[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(int[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(long[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(long[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(byte[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(byte[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(boolean[] objects) {
		flush();
		id3();
		writer.printLine(objects);
		flush();
	}

	public void printLine(boolean[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
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

	public boolean id7();

	public Edge id9();
}

class SimpleEdge implements Edge {
	protected final int source;
	protected final int destination;
	protected int color = -1;
	protected Edge reverseEdge = null;

	public SimpleEdge(int source, int destination, boolean directed) {
		this.source = source;
		this.destination = destination;
		if (!directed) reverseEdge = new id8();
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
	public boolean id7() {
		return reverseEdge != null;
	}

	@Override
	public Edge id9() {
		if (reverseEdge == null)
			throw new NoSuchFieldError();
		return reverseEdge;
	}

	@Override
	public String toString() {
		return "<(" + getSource() + " -> " + getDestination() + ") color : " + getColor() + ">";
	}

	protected class id8 implements Edge {
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
		public boolean id7() {
			return true;
		}

		@Override
		public Edge id9() {
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
	private int edgeCount = 0;

	public Graph(int length) {
		firstEdge = new Node[length];
	}

	public void add(Edge edge) {
		++edgeCount;

		Node v = new Node(edge);
		v.next = firstEdge[edge.getSource()];
		firstEdge[edge.getSource()] = v;

		if (edge.id7()) {
			edge = edge.id9();

			v = new Node(edge);
			v.next = firstEdge[edge.getSource()];
			firstEdge[edge.getSource()] = v;
		}
	}

	public Iterable<Edge> getIncident(final int vertex) {
		return new Iterable<Edge>() {
			@Override
			public Iterator<Edge> iterator() {
				return new EdgeIterator(vertex);
			}
		};
	}

	public int id4() {
		return firstEdge.length;
	}

	public int id11() {
		return edgeCount;
	}

	public void show(DebugWriter writer) {
		writer.printLine("Graph:");
		for (int i = 0; i < firstEdge.length; ++i) {
			writer.printLine("\tincident to vertex [" + i + "]: ");
			for (Edge edge : getIncident(i))
				writer.printLine("\t\t" + edge);
		}
	}

	public class EdgeIterator implements Iterator<Edge> {
		private Node current;

		private EdgeIterator(int vertex) {
			current = firstEdge[vertex];
		}

		@Override
		public boolean hasNext() {
			return current != null;
		}

		@Override
		public Edge next() {
			if (!hasNext()) throw new NoSuchElementException();
			Node last = current;
			current = current.next;
			return last.edge;
		}

		@Override
		public void remove() {
			throw new UnsupportedOperationException();
		}

		public Edge getCurrent() {
			return current.edge;
		}
	}

	private class Node {
		public Edge edge;
		public Node next = null;

		public Node(Edge edge) {
			this.edge = edge;
		}
	}
}
