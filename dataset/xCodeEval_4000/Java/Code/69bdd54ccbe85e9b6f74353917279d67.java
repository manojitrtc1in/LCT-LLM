import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
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
		int q = in.readInt();

		Graph G = new GraphSimple(n, n * 2);
		G.addVertexes(n);


		for (int i = 0; i < n - 1; ++i) {
			int v = in.readInt() - 1;
			int u = in.readInt() - 1;
			G.addSimpleEdge(v, u);
			G.addSimpleEdge(u, v);
		}




		int power = 0;
		for (int e = G.getFirstEdge(0); e != -1; e = G.getNextEdge(e))
			++power;

		SegmentTree mainTree = new SegmentTreeSimple(n * 2 + 2);
		SegmentTree[] tree = new SegmentTreeSimple[power];

		int[] X = new int[n];
		int[] Y = new int[n];

		int powerCount = 0;

		for (int e = G.getFirstEdge(0); e != -1; e = G.getNextEdge(e)) {
			int parent = 0;
			int v = G.getDestination(e);
			int len = 1;
			X[v] = len++;
			Y[v] = powerCount;

			boolean flag = true;
			while (flag) {
				flag = false;
				for (int x = G.getFirstEdge(v); x != -1; x = G.getNextEdge(x))
					if (G.getDestination(x) != parent) {
						parent = v;
						v = G.getDestination(x);
						X[v] = len++;
						Y[v] = powerCount;

						flag = true;
						break;
					}
			}

			tree[powerCount++] = new SegmentTreeSimple(len * 2 + 2);
		}










		while (q-- > 0) {
			int t = in.readInt();
			int v = in.readInt() - 1;
			if (t == 0) {
				int value = in.readInt();
				int distance = in.readInt();
				if (distance < X[v]) {
					tree[Y[v]].set(X[v] - distance, value);
					if (X[v] + distance + 1 < tree[Y[v]].size())
						tree[Y[v]].set(X[v] + distance + 1, -value);
				} else {
					mainTree.set(0, value);
					if (distance - X[v] + 1 < mainTree.size())
						mainTree.set(distance - X[v] + 1, -value);

					tree[Y[v]].set(0, -value);
					if (distance - X[v] + 1 < tree[Y[v]].size())
						tree[Y[v]].set(distance - X[v] + 1, value);

					tree[Y[v]].set(1, value);
					if (X[v] + distance + 1 < tree[Y[v]].size())
						tree[Y[v]].set(X[v] + distance + 1, -value);
				}
			} else {
				int res = mainTree.get(0, X[v]);
				if (v > 0)
					res += tree[Y[v]].get(0, X[v]);
				out.printLine(res);
			}






		}

	}
}

interface SegmentTree {
	public int size();

	public int get(int index);

	public int get(int leftIndex, int rightIndex);

	public void set(int index, int value);

	public void set(int leftIndex, int rightIndex, int value);
}

final class SegmentTreeSimple implements SegmentTree {
	int[] tree;
	final int NEUTRAL_VALUE = 0;

	private int getFunction(int a, int b) {
		return a + b;
	}

	private int setFunction(int treeValue, int extraValue) {
		return treeValue + extraValue;
	}

	public SegmentTreeSimple(int size) {
		int two = 1;
		while (two < size) two *= 2;
		tree = new int[two * 2];
		tree[0] = two;
	}

	@Override
	public int size() {
		return tree[0];
	}

	@Override
	public int get(int index) {
		return tree[tree[0] + index];
	}

	@Override
	public int get(int leftIndex, int rightIndex) {
		leftIndex += tree[0];
		rightIndex += tree[0];

		int result = NEUTRAL_VALUE;

		for (; leftIndex <= rightIndex; leftIndex = (leftIndex + 1) / 2, rightIndex = (rightIndex - 1) / 2) {
			if ((leftIndex & 1) == 1) result = getFunction(result, tree[leftIndex]);
			if ((rightIndex & 1) == 0) result = getFunction(result, tree[rightIndex]);
		}

		return result;
	}

	@Override
	public void set(int index, int value) {
		index += tree[0];
		tree[index] = setFunction(tree[index], value);
		index /= 2;

		while (index > 0) {
			tree[index] = getFunction(tree[index * 2], tree[index * 2 + 1]);
			index /= 2;
		}
	}

	@Override
	public void set(int leftIndex, int rightIndex, int value) {
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

interface Graph {
	

	public void addVertexes(int amount);

	

	public void addSimpleEdge(int source, int destination);

	public void addWeightedEdge(int source, int destination, long weight);

	public void addFlowEdge(int source, int destination, long capacity);

	public void addWeightedFlowEdge(int source, int destination, long weight, long capacity);

	

	public int getFirstEdge(int source);

	public int getNextEdge(int edge);

	

	public int getVertexCount();

	public int getEdgeCount();

	public void show(DebugWriter writer);

	

	public int getSource(int edge);

	public int getDestination(int edge);

	public String edgeToString(int edge);

	

	public long getWeight(int edge);

	public void setWeight(int edge, long weight);

	

	public long getCapacity(int edge);

	public void addCapacity(int edge, long capacity);

	public long getFlow(int edge);

	public void pushFlow(int edge, long flow);
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

	protected void ensureVertexCapacity(int vertexCapacity) {
	}

	protected void ensureEdgeCapacity(int edgeCapacity) {
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
	public int getNextEdge(int edge) {
		return nextEdge[edge];
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
		for (int source = 0; source < getVertexCount(); ++source) {
			writer.printLine("\tincident to vertex [" + source + "]: ");
			for (int edgeID = getFirstEdge(source); edgeID != -1; edgeID = getNextEdge(edgeID))
				writer.printLine("\t\t" + edgeToString(edgeID));
		}
	}

	

	@Override
	public int getSource(int edge) {
		return source[edge];
	}

	@Override
	public int getDestination(int edge) {
		return destination[edge];
	}

	@Override
	public String edgeToString(int edge) {
		return "<(" + getSource(edge) + " -> " + getDestination(edge) + ")>";
	}

	

	@Override
	public long getWeight(int edge) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void setWeight(int edge, long weight) {
		throw new UnsupportedOperationException();
	}

	

	@Override
	public long getCapacity(int edge) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void addCapacity(int edge, long capacity) {
		throw new UnsupportedOperationException();
	}

	@Override
	public long getFlow(int edge) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void pushFlow(int edge, long flow) {
		throw new UnsupportedOperationException();
	}
}