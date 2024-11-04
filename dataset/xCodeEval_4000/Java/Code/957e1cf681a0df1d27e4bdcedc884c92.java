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
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;


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

		Graph G = new GraphSimple(n, m * 2);
		G.addVertexes(n);


		for (int i = 0; i < m; ++i) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			G.addSimpleEdge(a, b);
			G.addSimpleEdge(b, a);
		}





		int iter = 0;
		int[] first = new int[n];
		int[] intersect = new int[n];
		int[] intersectArray = new int[n];

		for (int source = 0; source < n; ++source)
			for (int e = G.getFirstEdge(source); G.hasNextEdge(e); e = G.getNextEdge(e)) {
				int dest = G.getDestination(e);
				++iter;
				int countSource = 0;
				int countDest = 0;
				int interSize = 0;

				for (int e2 = G.getFirstEdge(source); G.hasNextEdge(e2); e2 = G.getNextEdge(e2)) {
					int nDest = G.getDestination(e2);
					if (dest != nDest) {
						first[nDest] = iter;
						++countSource;
						if (countSource == H + T) break;
					}
				}

				for (int e2 = G.getFirstEdge(dest); G.hasNextEdge(e2); e2 = G.getNextEdge(e2)) {
					int nDest = G.getDestination(e2);
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

					for (int e2 = G.getFirstEdge(source); G.hasNextEdge(e2); e2 = G.getNextEdge(e2)) {
						int nDest = G.getDestination(e2);
						if (H > 0 && countSource > 0 && nDest != dest && intersect[nDest] != iter) {
							ans1[i1++] = nDest + 1;
							--H;
							--countSource;
						}
					}

					for (int e2 = G.getFirstEdge(dest); G.hasNextEdge(e2); e2 = G.getNextEdge(e2)) {
						int nDest = G.getDestination(e2);
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


interface Graph {
	

	public void addVertexes(int amount);

	

	public void addSimpleEdge(int source, int destination);

	public void addWeightedEdge(int source, int destination, long weight);

	public void addFlowEdge(int source, int destination, long capacity);

	public void addWeightedFlowEdge(int source, int destination, long weight, long capacity);

	

	public int getFirstEdge(int source);

	public boolean hasNextEdge(int edgeID);

	public int getNextEdge(int edgeID);

	

	public int getVertexCount();

	public int getEdgeCount();

	public void show(DebugWriter writer);

	

	public int getSource(int edgeID);

	public int getDestination(int edgeID);

	public String edgeToString(int edgeID);

	

	public long getWeight(int edgeID);

	public void setWeight(int edgeID, long weight);

	

	public long getCapacity(int edgeID);

	public void addCapacity(int edgeID, long capacity);

	public long getFlow(int edgeID);

	public void pushFlow(int edgeID, long flow);
}


class GraphSimple implements Graph {
	protected int[] firstEdge;
	protected int[] nextEdge;
	protected int vertexCount = 0;
	protected int edgeCount = 0;

	protected int[] source;
	protected int[] destination;

	public GraphSimple() {
		this(16, 16);
	}

	public GraphSimple(int vertexCapacity, int edgeCapacity) {
		firstEdge = new int[vertexCapacity];
		nextEdge = new int[edgeCapacity];

		source = new int[edgeCapacity];
		destination = new int[edgeCapacity];
	}

	protected void ensureVertexCapacity(int size) {
	}

	protected void ensureEdgeCapacity(int size) {
	}

	

	@Override
	public void addVertexes(int amount) {
		ensureVertexCapacity(vertexCount + amount);
		for (int i = 0; i < amount; ++i)
			firstEdge[i + vertexCount] = -1;
		vertexCount += amount;
	}

	

	@Override
	public void addSimpleEdge(int source, int destination) {
		if (source >= vertexCount || destination >= vertexCount)
			throw new ArrayIndexOutOfBoundsException("wrong vertex's number");

		ensureEdgeCapacity(edgeCount + 1);
		nextEdge[edgeCount] = firstEdge[source];
		firstEdge[source] = edgeCount;

		this.source[edgeCount] = source;
		this.destination[edgeCount] = destination;
		++edgeCount;
	}

	@Override
	public void addWeightedEdge(int source, int destination, long weight) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void addFlowEdge(int source, int destination, long capacity) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void addWeightedFlowEdge(int source, int destination, long weight, long capacity) {
		throw new UnsupportedOperationException();
	}

	

	@Override
	public int getFirstEdge(int source) {
		if (source >= vertexCount)
			throw new ArrayIndexOutOfBoundsException("wrong vertex's number");
		return firstEdge[source];
	}

	@Override
	public boolean hasNextEdge(int edgeID) {
		return edgeID != -1;
	}

	@Override
	public int getNextEdge(int edgeID) {
		return nextEdge[edgeID];
	}

	

	@Override
	public int getVertexCount() {
		return vertexCount;
	}

	@Override
	public int getEdgeCount() {
		return edgeCount;
	}

	@Override
	public void show(DebugWriter writer) {
		writer.printLine("Graph:");
		for (int i = 0; i < getVertexCount(); ++i) {
			writer.printLine("\tincident to vertex [" + i + "]: ");
			for (int id = getFirstEdge(i); hasNextEdge(id); id = getNextEdge(id))
				writer.printLine("\t\t" + edgeToString(id));
		}
	}

	

	@Override
	public int getSource(int edgeID) {
		return source[edgeID];
	}

	@Override
	public int getDestination(int edgeID) {
		return destination[edgeID];
	}


	@Override
	public String edgeToString(int edgeID) {
		return "<(" + getSource(edgeID) + " -> " + getDestination(edgeID) + ")>";
	}

	

	@Override
	public long getWeight(int edgeID) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void setWeight(int edgeID, long weight) {
		throw new UnsupportedOperationException();
	}

	

	@Override
	public long getCapacity(int edgeID) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void addCapacity(int edgeID, long capacity) {
		throw new UnsupportedOperationException();
	}

	@Override
	public long getFlow(int edgeID) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void pushFlow(int edgeID, long flow) {
		throw new UnsupportedOperationException();
	}
}

final class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1 << 10];
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
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream), 1 << 10));
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