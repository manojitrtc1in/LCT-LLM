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
		long id13 = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			id13 = System.currentTimeMillis();
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
			s.dout.printFormat("*** Total time: %.3f ***\n", (System.currentTimeMillis() - id13) / 1000.0);
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
		G.id17(n);


		for (int i = 0; i < n - 1; ++i) {
			int v = in.readInt() - 1;
			int u = in.readInt() - 1;
			G.id12(v, u);
			G.id12(u, v);
		}




		int power = 0;
		for (int e = G.id6(0); e != -1; e = G.id8(e))
			++power;

		mainTree = init(n * 2 + 2);
		tree = new int[power][];

		int[] X = new int[n];
		int[] Y = new int[n];

		int powerCount = 0;

		for (int e = G.id6(0); e != -1; e = G.id8(e)) {
			int parent = 0;
			int v = G.getDestination(e);
			int len = 1;
			X[v] = len++;
			Y[v] = powerCount;

			boolean flag = true;
			while (flag) {
				flag = false;
				for (int x = G.id6(v); x != -1; x = G.id8(x))
					if (G.getDestination(x) != parent) {
						parent = v;
						v = G.getDestination(x);
						X[v] = len++;
						Y[v] = powerCount;

						flag = true;
						break;
					}
			}

			tree[powerCount++] = init(len * 2 + 2);
		}










		while (q-- > 0) {
			int t = in.readInt();
			int v = in.readInt() - 1;
			if (t == 0) {
				int value = in.readInt();
				int distance = in.readInt();
				if (distance < X[v]) {
					add(X[v] - distance, value, tree[Y[v]]);
					if (X[v] + distance + 1 < tree[Y[v]][0])
						add(X[v] + distance + 1, -value, tree[Y[v]]);
				} else {
					add(0, value, mainTree);
					if (distance - X[v] + 1 < mainTree[0])
						add(distance - X[v] + 1, -value, mainTree);

					add(0, -value, tree[Y[v]]);
					if (distance - X[v] + 1 < tree[Y[v]][0])
						add(distance - X[v] + 1, value, tree[Y[v]]);

					add(1, value, tree[Y[v]]);
					if (X[v] + distance + 1 < tree[Y[v]][0])
						add(X[v] + distance + 1, -value, tree[Y[v]]);
				}
			} else {
				int res = get(0, X[v], mainTree);
				if (v > 0)
					res += get(0, X[v], tree[Y[v]]);
				out.printLine(res);
			}






		}

	}

	int[] mainTree;
	int[][] tree;

	int[] init(int n) {
		int two = 1;
		while (two < n) two *= 2;
		int[] T = new int[two * 2];
		T[0] = two;
		return T;
	}

	void add(int v, int value, int[] T) {
		v += T[0];
		T[v] += value;
		v /= 2;

		while (v > 0) {
			T[v] = T[v * 2] + T[v * 2 + 1];
			v /= 2;
		}
	}

	int get(int L, int R, int[] T) {
		L += T[0];
		R += T[0];

		int res = 0;

		for (; L <= R; L = (L + 1) / 2, R = (R - 1) / 2) {
			if ((L & 1) == 1) res += T[L];
			if ((R & 1) == 0) res += T[R];
		}

		return res;
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
		while (id4(c))
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
		} while (!id4(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id4(c))
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
		} while (!id4(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id4(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id4(c));
		return res.toString();
	}

	public static boolean id4(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id2() {
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
		String s = id2();
		while (s.trim().length() == 0)
			s = id2();
		return s;
	}

	public String readLine(boolean id16) {
		if (id16)
			return readLine();
		else
			return id2();
	}

	public BigInteger id14() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id4(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id4(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id4(c) && c != '.') {
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
			while (!id4(c)) {
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

	public boolean id3() {
		int value;
		while (id4(value = peek()) && value != -1)
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

	private void id9() {
		writer.print("DEBUG:\t");
	}


	public void printLine(Object... objects) {
		flush();
		id9();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		id9();
		writer.printFormat(format, objects);
		flush();
	}


	public void printLine(char[] objects) {
		flush();
		id9();
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
		id9();
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
		id9();
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
		id9();
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
		id9();
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
		id9();
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
		id9();
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
	

	public void id17(int amount);

	

	public void id12(int source, int destination);

	public void id0(int source, int destination, long weight);

	public void id5(int source, int destination, long capacity);

	public void id1(int source, int destination, long weight, long capacity);

	

	public int id6(int source);

	public int id8(int edge);

	

	public int id10();

	public int id18();

	public void show(DebugWriter writer);

	

	public int getSource(int edge);

	public int getDestination(int edge);

	public String id15(int edge);

	

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

	protected void id7(int vertexCapacity) {
	}

	protected void id11(int edgeCapacity) {
	}

	

	@Override
	public void id17(int amount) {
		id7(vertexCount + amount);
		for (int i = 0; i < amount; ++i)
			firstEdge[i + vertexCount] = -1;
		vertexCount += amount;
	}

	

	@Override
	public void id12(int source, int destination) {
		if (source >= vertexCount || destination >= vertexCount)
			throw new ArrayIndexOutOfBoundsException("wrong vertex's number");

		id11(edgeCount + 1);

		nextEdge[edgeCount] = firstEdge[source];
		firstEdge[source] = edgeCount;

		this.source[edgeCount] = source;
		this.destination[edgeCount] = destination;
		++edgeCount;
	}

	@Override
	public void id0(int source, int destination, long weight) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void id5(int source, int destination, long capacity) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void id1(int source, int destination, long weight, long capacity) {
		throw new UnsupportedOperationException();
	}

	

	@Override
	public int id6(int source) {
		if (source >= vertexCount)
			throw new ArrayIndexOutOfBoundsException("wrong vertex's number");
		return firstEdge[source];
	}

	@Override
	public int id8(int edge) {
		return nextEdge[edge];
	}

	

	@Override
	public int id10() {
		return vertexCount;
	}

	@Override
	public int id18() {
		return edgeCount;
	}

	@Override
	public void show(DebugWriter writer) {
		writer.printLine("Graph:");
		for (int source = 0; source < id10(); ++source) {
			writer.printLine("\tincident to vertex [" + source + "]: ");
			for (int edgeID = id6(source); edgeID != -1; edgeID = id8(edgeID))
				writer.printLine("\t\t" + id15(edgeID));
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
	public String id15(int edge) {
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