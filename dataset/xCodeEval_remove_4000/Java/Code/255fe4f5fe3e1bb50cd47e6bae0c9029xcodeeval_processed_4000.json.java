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
import java.util.LinkedList;
import java.util.NoSuchElementException;


final public class Main implements Runnable {
	private static String[] args;

	public static void main(String[] args) {
		Main.args = args;
		new Thread(null, new Main(), "MyRunThread", 1 << 27).start();
	}

	@Override
	public void run() {
		long id6 = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			id6 = System.currentTimeMillis();
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
			s.dout = new DebugWriter(s.out);
		}

		s.solve();

		if (args.length > 0 && args[0].equals("outside")) {
			s.dout.printFormat("*** Total time: %.3f ***\n", (System.currentTimeMillis() - id6) / 1000.0);
		}

		s.out.close();
	}
}

final class Solver {
	InputReader in;
	OutputWriter out;
	DebugWriter dout;

	public void solve() {

		int n = in.readInt();
		int m = in.readInt();
		int H = in.readInt();
		int T = in.readInt();

		firstEdge = new int[n];
		for (int i = 0; i < n; ++i)
			firstEdge[i] = -1;
		nextEdge = new int[2 * m];
		value = new int[2 * m];


		for (int i = 0; i < m; ++i) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			addEdge(a, b);
			addEdge(b, a);
		}


		int iter = 0;
		int[] first = new int[n];
		int[] intersect = new int[n];
		int[] id3 = new int[n];

		for (int source = 0; source < n; ++source)
			for (int e = firstEdge[source]; e != -1; e = nextEdge[e]) {
				int dest = value[e];
				++iter;
				int countSource = 0;
				int countDest = 0;
				int interSize = 0;

				for (int e2 = firstEdge[source]; e2 != -1; e2 = nextEdge[e2]) {
					int nDest = value[e2];
					if (dest != nDest) {
						first[nDest] = iter;
						++countSource;
						if (countSource == H + T) break;
					}
				}

				for (int e2 = firstEdge[dest]; e2 != -1; e2 = nextEdge[e2]) {
					int nDest = value[e2];
					if (source != nDest) {
						if (first[nDest] == iter) {
							intersect[nDest] = iter;
							id3[interSize++] = nDest;
							--countSource;
						} else ++countDest;
						if (countDest == T) break;
					}
				}

				if (H - Math.min(countSource, H) + T - Math.min(countDest, T) <= interSize) {
					int[] ans1 = new int[H];
					int i1 = 0;
					int[] ans2 = new int[T];
					int i2 = 0;

					out.printLine("YES");
					out.printLine((source + 1) + " " + (dest + 1));

					for (int e2 = firstEdge[source]; e2 != -1; e2 = nextEdge[e2]) {
						int nDest = value[e2];
						if (H > 0 && countSource > 0 && nDest != dest && intersect[nDest] != iter) {
							ans1[i1++] = nDest + 1;
							--H;
							--countSource;
						}
					}

					for (int e2 = firstEdge[dest]; e2 != -1; e2 = nextEdge[e2]) {
						int nDest = value[e2];
						if (T > 0 && countDest > 0 && nDest != source && intersect[nDest] != iter) {
							ans2[i2++] = nDest + 1;
							--T;
							--countDest;
						}
					}

					for (int v = 0; v < interSize; ++v) {
						if (H > 0) {
							ans1[i1++] = id3[v] + 1;
							--H;
						} else if (T > 0) {
							ans2[i2++] = id3[v] + 1;
							--T;
						} else break;
					}

					out.printLine(ans1);
					out.printLine(ans2);

					return;
				}
			}
		out.printLine("NO");

	}

	void addEdge(int source, int destination) {
		nextEdge[edgeCount] = firstEdge[source];
		firstEdge[source] = edgeCount;
		value[edgeCount++] = destination;
	}

	int edgeCount = 0;
	int[] firstEdge;
	int[] nextEdge;
	int[] value;
}

final class InputReader {
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

	public String readLine(boolean id11) {
		if (id11)
			return readLine();
		else
			return id0();
	}

	public BigInteger id7() {
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

final class OutputWriter {
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


	public void print(short[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(short[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(short[][] objects) {
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

final class DebugWriter {
	private final OutputWriter writer;

	public DebugWriter(OutputWriter writer) {
		this.writer = writer;
	}

	private void id4() {
		writer.print("DEBUG:\t");
	}


	public void printLine(Object... objects) {
		flush();
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		id4();
		writer.printFormat(format, objects);
		flush();
	}


	public void printLine(char[] objects) {
		flush();
		id4();
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
		id4();
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
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(int[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(short[] objects) {
		flush();
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(short[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(long[] objects) {
		flush();
		id4();
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
		id4();
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
		id4();
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
}

final class Pair<F, S> {
	public F first;
	public S second;

	public Pair(F first, S second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public int hashCode() {
		int hFirst = first != null ? first.hashCode() : 0;
		int hSecond = second != null ? second.hashCode() : 0;
		return 31 * hFirst + hSecond;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return (first != null ? first.equals(pair.first) : pair.first == null) &&
				(second != null ? second.equals(pair.second) : pair.second == null);
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		return new Pair<F, S>(first, second);
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}

interface Edge {
	public int getSource();

	public int getDestination();

	public int getColor();

	public void setColor(int color);

	public long getWeight();

	public void setWeight(long weight);

	public long getCapacity();

	public void addCapacity(long capacity);

	public long getFlow();

	public void pushFlow(long flow);

	public boolean id8();

	public Edge id10();
}

class SimpleEdge implements Edge {
	private final int source;
	private final int destination;
	private int color = -1;
	protected Edge reverseEdge = null;

	public SimpleEdge(int source, int destination, boolean directed) {
		this.source = source;
		this.destination = destination;
		if (!directed) reverseEdge = new id9();
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
	public int getColor() {
		return color;
	}

	@Override
	public void setColor(int color) {
		this.color = color;
	}

	@Override
	public long getWeight() {
		throw new UnsupportedOperationException();
	}

	@Override
	public void setWeight(long weight) {
		throw new UnsupportedOperationException();
	}

	@Override
	public long getCapacity() {
		throw new UnsupportedOperationException();
	}

	@Override
	public void addCapacity(long capacity) {
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
	public boolean id8() {
		return reverseEdge != null;
	}

	@Override
	public Edge id10() {
		if (reverseEdge == null)
			throw new NoSuchElementException();
		return reverseEdge;
	}

	@Override
	public boolean equals(Object object) {
		if (object == null || object.getClass() != Edge.class) return false;

		return getSource() == ((Edge) object).getSource()
				&& getDestination() == ((Edge) object).getDestination()
				&& getColor() == ((Edge) object).getColor()
				&& id8() == ((Edge) object).id8();
	}

	@Override
	public String toString() {
		return "<(" + getSource() + " -> " + getDestination() + ") color : " + getColor() + ">";
	}

	protected class id9 implements Edge {
		@Override
		public int getSource() {
			return destination;
		}

		@Override
		public int getDestination() {
			return source;
		}

		@Override
		public int getColor() {
			return color;
		}

		@Override
		public void setColor(int color) {
			SimpleEdge.this.color = color;
		}

		@Override
		public long getWeight() {
			throw new UnsupportedOperationException();
		}

		@Override
		public void setWeight(long weight) {
			throw new UnsupportedOperationException();
		}

		@Override
		public long getCapacity() {
			throw new UnsupportedOperationException();
		}

		@Override
		public void addCapacity(long capacity) {
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
		public boolean id8() {
			return true;
		}

		@Override
		public Edge id10() {
			return SimpleEdge.this;
		}

		@Override
		public boolean equals(Object object) {
			if (object == null || object.getClass() != Edge.class) return false;

			return getSource() == ((Edge) object).getSource()
					&& getDestination() == ((Edge) object).getDestination()
					&& getColor() == ((Edge) object).getColor()
					&& id8() == ((Edge) object).id8();
		}

		@Override
		public String toString() {
			return "<(" + getSource() + " -> " + getDestination() + ") color : " + getColor() + ">";
		}
	}
}


























































































































































































final class Graph {
	public class Node {
		public Edge edge;
		public Node next = null;

		public Node(Edge edge) {
			this.edge = edge;
		}
	}

	Node[] firstEdge;
	private int edgeCount = 0;

	public Graph(int length) {
		firstEdge = new Node[length];
	}

	public void add(Edge edge) {
		++edgeCount;

		Node v = new Node(edge);
		v.next = firstEdge[edge.getSource()];
		firstEdge[edge.getSource()] = v;

		if (edge.id8()) {
			edge = edge.id10();

			v = new Node(edge);
			v.next = firstEdge[edge.getSource()];
			firstEdge[edge.getSource()] = v;
		}
	}

	public int id5() {
		return firstEdge.length;
	}

	public int id12() {
		return edgeCount;
	}

}