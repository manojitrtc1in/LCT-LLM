import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;


final public class Main implements Runnable {
	private static String[] args;

	public static void main(String[] args) {
		Main.args = args;
		new Thread(null, new Main(), "MyRunThread", 1 << 27).start();
	}

	@Override
	public void run() {
		long time_beg = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			time_beg = System.currentTimeMillis();
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
			s.dout.printFormat("*** Total time: %.3f ***\n", (System.currentTimeMillis() - time_beg) / 1000.0);
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

		GraphSimple graph = new GraphSimple(n, m * 2);

		for (int i = 0; i < m; ++i) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			graph.addEdge(a, b, false);
		}





		int iter = 0;
		int[] first = new int[n];
		int[] intersect = new int[n];
		int[] intersectArray = new int[n];

		for (int source = 0; source < n; ++source)
			for (int e = graph.firstEdge[source]; e != -1; e = graph.nextEdge[e]) {
				int dest = graph.directEdge[e].getDestination();
				++iter;
				int countSource = 0;
				int countDest = 0;
				int interSize = 0;

				for (int e2 = graph.firstEdge[source]; e2 != -1; e2 = graph.nextEdge[e2]) {
					int nDest = graph.directEdge[e2].getDestination();
					if (dest != nDest) {
						first[nDest] = iter;
						++countSource;
						if (countSource == H + T) break;
					}
				}

				for (int e2 = graph.firstEdge[dest]; e2 != -1; e2 = graph.nextEdge[e2]) {
					int nDest = graph.directEdge[e2].getDestination();
					if (source != nDest) {
						if (first[nDest] == iter) {
							intersect[nDest] = iter;
							intersectArray[interSize++] = nDest;
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

					for (int e2 = graph.firstEdge[source]; e2 != -1; e2 = graph.nextEdge[e2]) {
						int nDest = graph.directEdge[e2].getDestination();
						if (H > 0 && countSource > 0 && nDest != dest && intersect[nDest] != iter) {
							ans1[i1++] = nDest + 1;
							--H;
							--countSource;
						}
					}

					for (int e2 = graph.firstEdge[dest]; e2 != -1; e2 = graph.nextEdge[e2]) {
						int nDest = graph.directEdge[e2].getDestination();
						if (T > 0 && countDest > 0 && nDest != source && intersect[nDest] != iter) {
							ans2[i2++] = nDest + 1;
							--T;
							--countDest;
						}
					}

					for (int v = 0; v < interSize; ++v) {
						if (H > 0) {
							ans1[i1++] = intersectArray[v] + 1;
							--H;
						} else if (T > 0) {
							ans2[i2++] = intersectArray[v] + 1;
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

	public long readLong() {
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

	public String readString() {
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

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String readLine0() {
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
		String s = readLine0();
		while (s.trim().length() == 0)
			s = readLine0();
		return s;
	}

	public String readLine(boolean ignoreEmptyLines) {
		if (ignoreEmptyLines)
			return readLine();
		else
			return readLine0();
	}

	public BigInteger readBigInteger() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') {
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
			while (!isSpaceChar(c)) {
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

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
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

	private void printDebugMessage() {
		writer.print("DEBUG:\t");
	}


	public void printLine(Object... objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		printDebugMessage();
		writer.printFormat(format, objects);
		flush();
	}


	public void printLine(char[] objects) {
		flush();
		printDebugMessage();
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
		printDebugMessage();
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
		printDebugMessage();
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
		printDebugMessage();
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
		printDebugMessage();
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
		printDebugMessage();
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
		printDebugMessage();
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

	public boolean hasReverseEdge();

	public Edge getReverseEdge();
}


final class GraphSimple {
	public int[] firstEdge;
	public int[] nextEdge;
	protected int edgeCount = 0;

	protected Edge[] directEdge;
	protected int[] reverseEdge;
	protected int[] source;
	protected int[] destination;
	protected int[] color;

	public GraphSimple() {
		this(16, 16);
	}

	public GraphSimple(int vertexCapacity, int edgeCapacity) {
		firstEdge = new int[vertexCapacity];
		Arrays.fill(firstEdge, -1);
		nextEdge = new int[edgeCapacity];

		directEdge = new Edge[edgeCapacity];
		reverseEdge = new int[edgeCapacity];
		source = new int[edgeCapacity];
		destination = new int[edgeCapacity];
		color = new int[edgeCapacity];
	}

	public void addEdge(int source, int destination, boolean directed) {
		ensureEdgeCapacity(edgeCount + 2);
		nextEdge[edgeCount] = firstEdge[source];
		firstEdge[source] = edgeCount;
		directEdge[edgeCount] = new SimpleEdge(edgeCount);

		this.source[edgeCount] = source;
		this.destination[edgeCount] = destination;
		this.color[edgeCount] = -1;

		if (directed) reverseEdge[edgeCount++] = -1;
		else {
			reverseEdge[edgeCount++] = edgeCount + 1;
			nextEdge[edgeCount] = firstEdge[destination];
			firstEdge[destination] = edgeCount;
			directEdge[edgeCount] = new SimpleEdge(edgeCount);

			this.source[edgeCount] = destination;
			this.destination[edgeCount] = source;
			this.color[edgeCount] = -1;

			reverseEdge[edgeCount++] = edgeCount - 1;
		}
	}

	private void ensureVertexCapacity(int size) {
	}

	private void ensureEdgeCapacity(int size) {
	}

	public int getVertexCount() {
		return firstEdge.length;
	}

	public int getEdgeCount() {
		return edgeCount;
	}

	public void show(DebugWriter writer) {
		writer.printLine("Graph:");
		for (int i = 0; i < firstEdge.length; ++i) {
			writer.printLine("\tincident to vertex [" + i + "]: ");
			for (int id = firstEdge[i]; id != -1; id = nextEdge[id])
				writer.printLine("\t\t" + directEdge[id]);
		}
	}

	final class SimpleEdge implements Edge {
		protected int id;

		public SimpleEdge(int id) {
			this.id = id;
		}

		@Override
		public int getSource() {
			return source[id];
		}

		@Override
		public int getDestination() {
			return destination[id];
		}

		@Override
		public int getColor() {
			return color[id];
		}

		@Override
		public void setColor(int color) {
			GraphSimple.this.color[id] = GraphSimple.this.color[reverseEdge[id]] = color;
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
		public boolean hasReverseEdge() {
			return reverseEdge[id] != -1;
		}

		@Override
		public Edge getReverseEdge() {
			if (reverseEdge[id] != -1)
				throw new NoSuchFieldError();
			return directEdge[reverseEdge[id]];
		}

		@Override
		public String toString() {
			return "<(" + getSource() + " -> " + getDestination() + ") color : " + getColor() + ">";
		}
	}
}