import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		Task solver = new TaskA();
		int t=in.readInt();
		for (int i=1; i<=t; i++) solver.solve(i, in, out);
		out.close();
	}
}

interface Task {
	public void solve(int testNumber, InputReader in, OutputWriter out);
}

class TaskA implements Task {

	boolean[][] madj;
	int[] aux={0, 2, 3, 3, 2};
	
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int n=in.readInt(), p=in.readInt();
		madj=new boolean[n][n];
		for (int i=0; i<n; i+=5) {
			int x=MiscUtils.min(i+5, n);
			for (int j=i; j<x; j++) for (int k=j+1; k<x; k++) madj[j][k]=madj[k][j]=true;
			if (x-i<5 && x-i>0) for (int j=0; j<aux[x-i]; j++) madj[j][i+j/2]=madj[i+j/2][j]=true;
		}
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) if (!madj[i][j] && p>0) {
			p--;
			madj[i][j]=madj[j][i]=true;
		}
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) if (madj[i][j]) out.printLine(i+1, j+1);
	}

}

class TaskB implements Task {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		
	}

}

class TaskC implements Task {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		
	}

}

class TaskD implements Task {

	char[][] tab;
	Graph graph;
	int[] DX = { -1, -1, 1, 1 }, DY = { -1, 1, -1, 1 };
	boolean[][] val;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		while (true) {
			int n=in.readInt(), m=in.readInt(), s=n*m, t=n*m+1, ret=0;
			if (n==0 && m==0) break;
			val=new boolean[n][m];
			tab=IOUtils.readTable(in, n, m);
			graph=new Graph(t+1);
			for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
				val[i][j]=tab[i][j]=='F';
				for (int k=0; k<4; k++) {
					int i2=i+2*DX[k], j2=j+2*DY[k], i3=i+DX[k], j3=j+DY[k];
					if (MiscUtils.id69(i2, j2, n, m) && (tab[i2][j2]=='G' && tab[i3][j3]!='P')) val[i][j]=false;
				}
				if (val[i][j]) ret++;
			}
			for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (val[i][j]) {
				int u=m*i+j;
				if (i%4>1) {
					graph.id28(u, t, 1);
					continue;
				}
				graph.id28(s, u, 1);
				for (int k=0; k<4; k++) {
					int i2=i+2*DX[k], j2=j+2*DY[k], i3=i+DX[k], j3=j+DY[k], v=m*i2+j2;
					if (MiscUtils.id69(i2, j2, n, m) && val[i2][j2] && tab[i3][j3]!='P') graph.id28(u, v, 1);
				}
			}
			ret-=MaxFlow.dinic(graph, s, t);
			out.printLine(ret);
		}
	}
}

class TaskE implements Task {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int x = in.readInt(), k = in.readInt(), p = in.readInt(), c = 0;
		for (; x % 2 == 0; x /= 2)
			c++;
		double prob = 0.01 * p, ret = Math.pow(prob, k) * (k + c);
		for (int i = 1; i <= k; i++)
			ret += (1.0 - prob) * Math.pow(prob, k - i) * (k - i);
		out.printLine(ret);
	}

}

class TaskF implements Task {

	public void solve(int testNumber, InputReader in, OutputWriter out) {

	}

}

class MaxFlow {
	private final Graph graph;
	private int source;
	private int destination;
	private int[] queue;
	private int[] distance;
	private int[] nextEdge;

	private MaxFlow(Graph graph, int source, int destination) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		int vertexCount = graph.vertexCount();
		queue = new int[vertexCount];
		distance = new int[vertexCount];
		nextEdge = new int[vertexCount];
	}

	public static long dinic(Graph graph, int source, int destination) {
		return new MaxFlow(graph, source, destination).dinic();
	}

	private long dinic() {
		long totalFlow = 0;
		while (true) {
			edgeDistances();
			if (distance[destination] == -1)
				break;
			Arrays.fill(nextEdge, -2);
			totalFlow += id57(source, Long.MAX_VALUE);
		}
		return totalFlow;
	}

	private void edgeDistances() {
		Arrays.fill(distance, -1);
		distance[source] = 0;
		int size = 1;
		queue[0] = source;
		for (int i = 0; i < size; i++) {
			int current = queue[i];
			int id = graph.firstOutbound(current);
			while (id != -1) {
				if (graph.capacity(id) != 0) {
					int next = graph.destination(id);
					if (distance[next] == -1) {
						distance[next] = distance[current] + 1;
						queue[size++] = next;
					}
				}
				id = graph.nextOutbound(id);
			}
		}
	}

	private long id57(int source, long flow) {
		if (source == destination)
			return flow;
		if (flow == 0 || distance[source] == distance[destination])
			return 0;
		int id = nextEdge[source];
		if (id == -2)
			nextEdge[source] = id = graph.firstOutbound(source);
		long id18 = 0;
		while (id != -1) {
			int id63 = graph.destination(id);
			if (graph.capacity(id) != 0
					&& distance[id63] == distance[source] + 1) {
				long pushed = id57(id63,
						Math.min(flow, graph.capacity(id)));
				if (pushed != 0) {
					graph.pushFlow(id, pushed);
					flow -= pushed;
					id18 += pushed;
					if (flow == 0)
						return id18;
				}
			}
			nextEdge[source] = id = graph.nextOutbound(id);
		}
		return id18;
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(char[] array) {
		writer.print(array);
	}

	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void print(long[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void print(Collection<Integer> collection) {
		boolean first = true;
		for (Integer iterator : collection) {
			if (first)
				first = false;
			else
				writer.print(' ');
			writer.print(iterator);
		}
	}

	public void printLine(int[] array) {
		print(array);
		writer.println();
	}

	public void printLine(long[] array) {
		print(array);
		writer.println();
	}

	public void printLine(Collection<Integer> collection) {
		print(collection);
		writer.println();
	}

	public void printLine() {
		writer.println();
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void print(char i) {
		writer.print(i);
	}

	public void printLine(char i) {
		writer.println(i);
	}

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}

	public void print(long i) {
		writer.print(i);
	}

	public void printLine(long i) {
		writer.println(i);
	}

	public void print(int i) {
		writer.print(i);
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id54 filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
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
		while (id5(c))
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
		} while (!id5(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id5(c))
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
		} while (!id5(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id5(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!id5(c));
		return res.toString();
	}

	public boolean id5(int c) {
		if (filter != null)
			return filter.id5(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id23() {
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
		String s = id23();
		while (s.trim().length() == 0)
			s = id23();
		return s;
	}

	public String readLine(boolean id67) {
		if (id67)
			return readLine();
		else
			return id23();
	}

	public BigInteger id15() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id5(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id5(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id5(c) && c != '.') {
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
			while (!id5(c)) {
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

	public boolean id25() {
		int value;
		while (id5(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	public String next() {
		return readString();
	}

	public id54 getFilter() {
		return filter;
	}

	public void setFilter(id54 filter) {
		this.filter = filter;
	}

	public interface id54 {
		public boolean id5(int ch);
	}
}

class IOUtils {
	public static Pair<Integer, Integer> id59(InputReader in) {
		int first = in.readInt();
		int second = in.readInt();
		return Pair.makePair(first, second);
	}

	public static Pair<Long, Long> id11(InputReader in) {
		long first = in.readLong();
		long second = in.readLong();
		return Pair.makePair(first, second);
	}

	public static int[] id1(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static long[] id7(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

	public static double[] id38(InputReader in, int size) {
		double[] array = new double[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readDouble();
		return array;
	}

	public static String[] id37(InputReader in, int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readString();
		return array;
	}

	public static char[] id4(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static Pair<Integer, Integer>[] id10(InputReader in,
			int size) {
		@SuppressWarnings({ "unchecked" })
		Pair<Integer, Integer>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = id59(in);
		return result;
	}

	public static Pair<Long, Long>[] id56(InputReader in, int size) {
		@SuppressWarnings({ "unchecked" })
		Pair<Long, Long>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = id11(in);
		return result;
	}

	public static void id12(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	public static void id49(InputReader in, long[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readLong();
		}
	}

	public static void id51(InputReader in, double[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readDouble();
		}
	}

	public static char[][] readTable(InputReader in, int rowCount,
			int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id4(in, columnCount);
		return table;
	}

	public static int[][] id40(InputReader in, int rowCount,
			int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id1(in, columnCount);
		return table;
	}

	public static double[][] id0(InputReader in, int rowCount,
			int columnCount) {
		double[][] table = new double[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id38(in, columnCount);
		return table;
	}

	public static long[][] id20(InputReader in, int rowCount,
			int columnCount) {
		long[][] table = new long[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id7(in, columnCount);
		return table;
	}

	public static String[][] id66(InputReader in, int rowCount,
			int columnCount) {
		String[][] table = new String[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id37(in, columnCount);
		return table;
	}

	public static String readText(InputReader in) {
		StringBuilder result = new StringBuilder();
		while (true) {
			int character = in.read();
			if (character == '\r')
				continue;
			if (character == -1)
				break;
			result.append((char) character);
		}
		return result.toString();
	}

	public static void id31(InputReader in, String[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readString();
		}
	}

	public static void printTable(OutputWriter out, char[][] table) {
		for (char[] row : table)
			out.printLine(new String(row));
	}
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static <U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		Pair<?, ?> pair = (Pair<?, ?>) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null)
				&& !(second != null ? !second.equals(pair.second)
						: pair.second != null);

	}

	@Override
	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public Pair<V, U> swap() {
		return makePair(second, first);
	}

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
	}

	@SuppressWarnings({ "unchecked" })
	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>) first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>) second).compareTo(o.second);
	}
}

class id27 extends Graph {
	public int[] id22;

	public id27(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public id27(int vertexCount, int edgeCapacity) {
		super(vertexCount, 2 * edgeCapacity);
		id22 = new int[2 * edgeCapacity];
	}

	public static id27 createGraph(int vertexCount, int[] from,
			int[] to) {
		id27 graph = new id27(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id14(from[i], to[i]);
		return graph;
	}

	public static id27 id21(int vertexCount,
			int[] from, int[] to, long[] weight) {
		id27 graph = new id27(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id2(from[i], to[i], weight[i]);
		return graph;
	}

	public static id27 id50(int vertexCount,
			int[] from, int[] to, long[] capacity) {
		id27 graph = new id27(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id28(from[i], to[i], capacity[i]);
		return graph;
	}

	public static id27 id42(int vertexCount,
			int[] from, int[] to, long[] weight, long[] capacity) {
		id27 graph = new id27(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id43(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	@Override
	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		int id64 = edgeCount;
		super.addEdge(fromID, toID, weight, capacity, reverseEdge);
		super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1
				: reverseEdge + 1);
		this.id22[id64] = id64 + 1;
		this.id22[id64 + 1] = id64;
		return id64;
	}

	@Override
	protected int id13() {
		return 2;
	}

	@Override
	public final int transposed(int id) {
		return id22[id];
	}

	@Override
	protected void id48(int size) {
		if (size > edgeCapacity()) {
			super.id48(size);
			id22 = resize(id22, edgeCapacity());
		}
	}
}

class Graph {
	public static final int id70 = 0;

	protected int vertexCount;
	protected int edgeCount;

	private int[] firstOutbound;
	private int[] firstInbound;

	private Edge[] edges;
	private int[] nextInbound;
	private int[] nextOutbound;
	private int[] from;
	private int[] to;
	private long[] weight;
	private long[] capacity;
	private int[] reverseEdge;
	private int[] flags;

	public Graph(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public Graph(int vertexCount, int edgeCapacity) {
		this.vertexCount = vertexCount;
		firstOutbound = new int[vertexCount];
		Arrays.fill(firstOutbound, -1);

		from = new int[edgeCapacity];
		to = new int[edgeCapacity];
		nextOutbound = new int[edgeCapacity];
		flags = new int[edgeCapacity];
	}

	public static Graph createGraph(int vertexCount, int[] from, int[] to) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.id14(from[i], to[i]);
		return graph;
	}

	public static Graph id21(int vertexCount, int[] from,
			int[] to, long[] weight) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.id2(from[i], to[i], weight[i]);
		return graph;
	}

	public static Graph id50(int vertexCount, int[] from, int[] to,
			long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id28(from[i], to[i], capacity[i]);
		return graph;
	}

	public static Graph id42(int vertexCount, int[] from,
			int[] to, long[] weight, long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id43(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	public static Graph createTree(int[] parent) {
		Graph graph = new Graph(parent.length + 1, parent.length);
		for (int i = 0; i < parent.length; i++)
			graph.id14(parent[i], i + 1);
		return graph;
	}

	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		id48(edgeCount + 1);
		if (firstOutbound[fromID] != -1)
			nextOutbound[edgeCount] = firstOutbound[fromID];
		else
			nextOutbound[edgeCount] = -1;
		firstOutbound[fromID] = edgeCount;
		if (firstInbound != null) {
			if (firstInbound[toID] != -1)
				nextInbound[edgeCount] = firstInbound[toID];
			else
				nextInbound[edgeCount] = -1;
			firstInbound[toID] = edgeCount;
		}
		this.from[edgeCount] = fromID;
		this.to[edgeCount] = toID;
		if (capacity != 0) {
			if (this.capacity == null)
				this.capacity = new long[from.length];
			this.capacity[edgeCount] = capacity;
		}
		if (weight != 0) {
			if (this.weight == null)
				this.weight = new long[from.length];
			this.weight[edgeCount] = weight;
		}
		if (reverseEdge != -1) {
			if (this.reverseEdge == null) {
				this.reverseEdge = new int[from.length];
				Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
			}
			this.reverseEdge[edgeCount] = reverseEdge;
		}
		if (edges != null)
			edges[edgeCount] = createEdge(edgeCount);
		return edgeCount++;
	}

	protected final GraphEdge createEdge(int id) {
		return new GraphEdge(id);
	}

	public final int id43(int from, int to, long weight,
			long capacity) {
		if (capacity == 0) {
			return addEdge(from, to, weight, 0, -1);
		} else {
			int id64 = edgeCount;
			addEdge(to, from, -weight, 0, id64 + id13());
			return addEdge(from, to, weight, capacity, id64);
		}
	}

	protected int id13() {
		return 1;
	}

	public final int id28(int from, int to, long capacity) {
		return id43(from, to, 0, capacity);
	}

	public final int id2(int from, int to, long weight) {
		return id43(from, to, weight, 0);
	}

	public final int id14(int from, int to) {
		return id2(from, to, 0);
	}

	public final int vertexCount() {
		return vertexCount;
	}

	public final int edgeCount() {
		return edgeCount;
	}

	protected final int edgeCapacity() {
		return from.length;
	}

	public final Edge edge(int id) {
		initEdges();
		return edges[id];
	}

	public final int firstOutbound(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int nextOutbound(int id) {
		id = nextOutbound[id];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int firstInbound(int vertex) {
		initInbound();
		int id = firstInbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int nextInbound(int id) {
		initInbound();
		id = nextInbound[id];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int source(int id) {
		return from[id];
	}

	public final int destination(int id) {
		return to[id];
	}

	public final long weight(int id) {
		if (weight == null)
			return 0;
		return weight[id];
	}

	public final long capacity(int id) {
		if (capacity == null)
			return 0;
		return capacity[id];
	}

	public final long flow(int id) {
		if (reverseEdge == null)
			return 0;
		return capacity[reverseEdge[id]];
	}

	public final void pushFlow(int id, long flow) {
		if (flow == 0)
			return;
		if (flow > 0) {
			if (capacity(id) < flow)
				throw new IllegalArgumentException("Not enough capacity");
		} else {
			if (flow(id) < -flow)
				throw new IllegalArgumentException("Not enough capacity");
		}
		capacity[id] -= flow;
		capacity[reverseEdge[id]] += flow;
	}

	public int transposed(int id) {
		return -1;
	}

	public final int reverse(int id) {
		if (reverseEdge == null)
			return -1;
		return reverseEdge[id];
	}

	public final void addVertices(int count) {
		id46(vertexCount + count);
		Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
		if (firstInbound != null)
			Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
		vertexCount += count;
	}

	protected final void initEdges() {
		if (edges == null) {
			edges = new Edge[from.length];
			for (int i = 0; i < edgeCount; i++)
				edges[i] = createEdge(i);
		}
	}

	public final void removeVertex(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextOutbound[id];
		}
		initInbound();
		id = firstInbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextInbound[id];
		}
	}

	private void initInbound() {
		if (firstInbound == null) {
			firstInbound = new int[firstOutbound.length];
			Arrays.fill(firstInbound, 0, vertexCount, -1);
			nextInbound = new int[from.length];
			for (int i = 0; i < edgeCount; i++) {
				nextInbound[i] = firstInbound[to[i]];
				firstInbound[to[i]] = i;
			}
		}
	}

	public final boolean flag(int id, int bit) {
		return (flags[id] >> bit & 1) != 0;
	}

	public final void setFlag(int id, int bit) {
		flags[id] |= 1 << bit;
	}

	public final void removeFlag(int id, int bit) {
		flags[id] &= -1 - (1 << bit);
	}

	public final void removeEdge(int id) {
		setFlag(id, id70);
	}

	public final void restoreEdge(int id) {
		removeFlag(id, id70);
	}

	public final boolean isRemoved(int id) {
		return flag(id, id70);
	}

	public final Iterable<Edge> outbound(final int id) {
		initEdges();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstOutbound, nextOutbound);
			}
		};
	}

	public final Iterable<Edge> inbound(final int id) {
		initEdges();
		initInbound();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstInbound, nextInbound);
			}
		};
	}

	protected void id48(int size) {
		if (from.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			if (edges != null)
				edges = resize(edges, newSize);
			from = resize(from, newSize);
			to = resize(to, newSize);
			nextOutbound = resize(nextOutbound, newSize);
			if (nextInbound != null)
				nextInbound = resize(nextInbound, newSize);
			if (weight != null)
				weight = resize(weight, newSize);
			if (capacity != null)
				capacity = resize(capacity, newSize);
			if (reverseEdge != null)
				reverseEdge = resize(reverseEdge, newSize);
			flags = resize(flags, newSize);
		}
	}

	private void id46(int size) {
		if (firstOutbound.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			firstOutbound = resize(firstOutbound, newSize);
			if (firstInbound != null)
				firstInbound = resize(firstInbound, newSize);
		}
	}

	protected final int[] resize(int[] array, int size) {
		int[] newArray = new int[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private long[] resize(long[] array, int size) {
		long[] newArray = new long[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private Edge[] resize(Edge[] array, int size) {
		Edge[] newArray = new Edge[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	public final boolean isSparse() {
		return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
	}

	protected class GraphEdge implements Edge {
		protected int id;

		protected GraphEdge(int id) {
			this.id = id;
		}

		public int getSource() {
			return source(id);
		}

		public int getDestination() {
			return destination(id);
		}

		public long getWeight() {
			return weight(id);
		}

		public long getCapacity() {
			return capacity(id);
		}

		public long getFlow() {
			return flow(id);
		}

		public void pushFlow(long flow) {
			Graph.this.pushFlow(id, flow);
		}

		public boolean getFlag(int bit) {
			return flag(id, bit);
		}

		public void setFlag(int bit) {
			Graph.this.setFlag(id, bit);
		}

		public void removeFlag(int bit) {
			Graph.this.removeFlag(id, bit);
		}

		public int id55() {
			return transposed(id);
		}

		public Edge id58() {
			int reverseID = id55();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int id17() {
			return reverse(id);
		}

		public Edge id52() {
			int reverseID = id17();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int getID() {
			return id;
		}

		public void remove() {
			removeEdge(id);
		}

		public void restore() {
			restoreEdge(id);
		}
	}

	public class EdgeIterator implements Iterator<Edge> {
		private int edgeID;
		private final int[] next;
		private int lastID = -1;

		public EdgeIterator(int id, int[] first, int[] next) {
			this.next = next;
			edgeID = nextEdge(first[id]);
		}

		private int nextEdge(int id) {
			while (id != -1 && isRemoved(id))
				id = next[id];
			return id;
		}

		public boolean hasNext() {
			return edgeID != -1;
		}

		public Edge next() {
			if (edgeID == -1)
				throw new NoSuchElementException();
			lastID = edgeID;
			edgeID = nextEdge(next[lastID]);
			return edges[lastID];
		}

		public void remove() {
			if (lastID == -1)
				throw new IllegalStateException();
			removeEdge(lastID);
			lastID = -1;
		}
	}

}

interface Edge {
	public int getSource();

	public int getDestination();

	public long getWeight();

	public long getCapacity();

	public long getFlow();

	public void pushFlow(long flow);

	public boolean getFlag(int bit);

	public void setFlag(int bit);

	public void removeFlag(int bit);

	public int id55();

	public Edge id58();

	public int id17();

	public Edge id52();

	public int getID();

	public void remove();

	public void restore();
}

class MiscUtils {
	public static final int[] DX4 = { 1, 0, -1, 0 };
	public static final int[] DY4 = { 0, -1, 0, 1 };
	public static final int[] DX8 = { 1, 1, 1, 0, -1, -1, -1, 0 };
	public static final int[] DY8 = { -1, 0, 1, 1, 1, 0, -1, -1 };
	public static final int[] id35 = { 2, 1, -1, -2, -2, -1, 1, 2 };
	public static final int[] id26 = { 1, 2, 2, 1, -1, -2, -2, -1 };

	private static final String[] id41 = { "M", "CM", "D", "CD", "C",
			"XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	private static final int[] id68 = { 1000, 900, 500, 400, 100, 90,
			50, 40, 10, 9, 5, 4, 1 };

	public static long id24(long n, int k) {
		if (n == 1)
			return 0;
		if (k == 1)
			return n - 1;
		if (k > n)
			return (id24(n - 1, k) + k) % n;
		long count = n / k;
		long result = id24(n - count, k);
		result -= n % k;
		if (result < 0)
			result += n;
		else
			result += result / (k - 1);
		return result;
	}

	public static boolean id69(int row, int column, int rowCount,
			int columnCount) {
		return row >= 0 && row < rowCount && column >= 0
				&& column < columnCount;
	}

	public static List<Integer> getPath(int[] last, int destination) {
		List<Integer> path = new ArrayList<Integer>();
		while (destination != -1) {
			path.add(destination);
			destination = last[destination];
		}
		Collections.reverse(path);
		return path;
	}

	public static List<Integer> getPath(int[][] lastIndex,
			int[][] id9, int destination, int pathNumber) {
		List<Integer> path = new ArrayList<Integer>();
		while (destination != -1 || pathNumber != 0) {
			path.add(destination);
			int nextDestination = lastIndex[destination][pathNumber];
			pathNumber = id9[destination][pathNumber];
			destination = nextDestination;
		}
		Collections.reverse(path);
		return path;
	}

	public static long id53(long[][] array) {
		int n = array.length;
		int m = array[0].length;
		long[][] id60 = new long[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			long rowSum = 0;
			for (int j = 0; j < m; j++) {
				rowSum += array[i][j];
				id60[i + 1][j + 1] = id60[i][j + 1] + rowSum;
			}
		}
		long result = Long.MIN_VALUE;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				long id47 = 0;
				for (int k = 1; k <= n; k++) {
					long current = id60[k][j + 1] - id60[k][i];
					result = Math.max(result, current - id47);
					id47 = Math.min(id47, current);
				}
			}
		}
		return result;
	}

	public static int parseIP(String ip) {
		String[] components = ip.split("[.]");
		int result = 0;
		for (int i = 0; i < 4; i++)
			result += (1 << (24 - 8 * i)) * Integer.parseInt(components[i]);
		return result;
	}

	public static String buildIP(int mask) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < 4; i++) {
			if (i != 0)
				result.append('.');
			result.append(mask >> (24 - 8 * i) & 255);
		}
		return result.toString();
	}

	public static long binarySearch(long from, long to,
			Function<Long, Boolean> function) {
		while (from < to) {
			long argument = from + (to - from) / 2;
			if (function.value(argument))
				to = argument;
			else
				from = argument + 1;
		}
		return from;
	}

	public static <T> boolean equals(T first, T second) {
		return first == null && second == null || first != null
				&& first.equals(second);
	}

	public static boolean id45(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
				|| ch == 'Y';
	}

	public static boolean id3(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}

	public static String id33(int number) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < id41.length; i++) {
			while (number >= id68[i]) {
				number -= id68[i];
				result.append(id41[i]);
			}
		}
		return result.toString();
	}

	public static int id29(String number) {
		int result = 0;
		for (int i = 0; i < id41.length; i++) {
			while (number.startsWith(id41[i])) {
				number = number.substring(id41[i].length());
				result += id68[i];
			}
		}
		return result;
	}

	public static int distance(int x1, int y1, int x2, int y2) {
		int dx = x1 - x2;
		int dy = y1 - y2;
		return dx * dx + dy * dy;
	}

	public static <T extends Comparable<T>> T min(T first, T second) {
		if (first.compareTo(second) <= 0)
			return first;
		return second;
	}

	public static <T extends Comparable<T>> T max(T first, T second) {
		if (first.compareTo(second) <= 0)
			return second;
		return first;
	}

	public static void id62(int[]... arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	public static int[] id16(String s) {
		String[] tokens = s.split(" ");
		int[] result = new int[tokens.length];
		for (int i = 0; i < result.length; i++)
			result[i] = Integer.parseInt(tokens[i]);
		return result;
	}
}

interface Function<A, V> {
	public abstract V value(A argument);
}

interface IntComparator {
	public static final IntComparator DEFAULT = new IntComparator() {
		public int compare(int first, int second) {
			if (first < second)
				return -1;
			if (first > second)
				return 1;
			return 0;
		}
	};

	public static final IntComparator REVERSE = new IntComparator() {
		public int compare(int first, int second) {
			if (first < second)
				return 1;
			if (first > second)
				return -1;
			return 0;
		}
	};

	public int compare(int first, int second);
}

class DFSOrder {
	public final int[] position;
	public final int[] end;

	public DFSOrder(Graph graph) {
		this(graph, 0);
	}

	public DFSOrder(Graph graph, int root) {
		int count = graph.vertexCount();
		position = new int[count];
		end = new int[count];
		int[] edge = new int[count];
		int[] stack = new int[count];
		for (int i = 0; i < count; i++)
			edge[i] = graph.firstOutbound(i);
		stack[0] = root;
		int size = 1;
		position[root] = 0;
		int index = 0;
		while (size > 0) {
			int current = stack[size - 1];
			if (edge[current] == -1) {
				end[current] = index;
				size--;
			} else {
				int next = graph.destination(edge[current]);
				edge[current] = graph.nextOutbound(edge[current]);
				position[next] = ++index;
				stack[size++] = next;
			}
		}
	}

	public DFSOrder(id27 graph) {
		this(graph, 0);
	}

	public DFSOrder(id27 graph, int root) {
		int count = graph.vertexCount();
		position = new int[count];
		end = new int[count];
		int[] edge = new int[count];
		int[] stack = new int[count];
		int[] last = new int[count];
		for (int i = 0; i < count; i++)
			edge[i] = graph.firstOutbound(i);
		stack[0] = root;
		last[root] = -1;
		int size = 1;
		position[root] = 0;
		int index = 0;
		while (size > 0) {
			int current = stack[size - 1];
			if (edge[current] == -1) {
				end[current] = index;
				size--;
			} else {
				int next = graph.destination(edge[current]);
				if (next == last[current]) {
					edge[current] = graph.nextOutbound(edge[current]);
					continue;
				}
				edge[current] = graph.nextOutbound(edge[current]);
				position[next] = ++index;
				last[next] = current;
				stack[size++] = next;
			}
		}
	}
}

abstract class IntervalTree {
	protected int size;

	protected IntervalTree(int size) {
		this(size, true);
	}

	public IntervalTree(int size, boolean shouldInit) {
		this.size = size;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		initData(size, nodeCount);
		if (shouldInit)
			init();
	}

	protected abstract void initData(int size, int nodeCount);

	protected abstract void initAfter(int root, int left, int right, int middle);

	protected abstract void initBefore(int root, int left, int right, int middle);

	protected abstract void initLeaf(int root, int index);

	protected abstract void id39(int root, int left, int right,
			int from, int to, long delta, int middle);

	protected abstract void id44(int root, int left, int right,
			int from, int to, long delta, int middle);

	protected abstract void updateFull(int root, int left, int right, int from,
			int to, long delta);

	protected abstract long id6(int root, int left, int right,
			int from, int to, int middle, long leftResult, long rightResult);

	protected abstract void id61(int root, int left, int right,
			int from, int to, int middle);

	protected abstract long queryFull(int root, int left, int right, int from,
			int to);

	protected abstract long id19();

	public void init() {
		if (size == 0)
			return;
		init(0, 0, size - 1);
	}

	private void init(int root, int left, int right) {
		if (left == right) {
			initLeaf(root, left);
		} else {
			int middle = (left + right) >> 1;
			initBefore(root, left, right, middle);
			init(2 * root + 1, left, middle);
			init(2 * root + 2, middle + 1, right);
			initAfter(root, left, right, middle);
		}
	}

	public void update(int from, int to, long delta) {
		update(0, 0, size - 1, from, to, delta);
	}

	protected void update(int root, int left, int right, int from, int to,
			long delta) {
		if (left > to || right < from)
			return;
		if (left >= from && right <= to) {
			updateFull(root, left, right, from, to, delta);
			return;
		}
		int middle = (left + right) >> 1;
		id44(root, left, right, from, to, delta, middle);
		update(2 * root + 1, left, middle, from, to, delta);
		update(2 * root + 2, middle + 1, right, from, to, delta);
		id39(root, left, right, from, to, delta, middle);
	}

	public long query(int from, int to) {
		return query(0, 0, size - 1, from, to);
	}

	protected long query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return id19();
		if (left >= from && right <= to)
			return queryFull(root, left, right, from, to);
		int middle = (left + right) >> 1;
		id61(root, left, right, from, to, middle);
		long leftResult = query(2 * root + 1, left, middle, from, to);
		long rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return id6(root, left, right, from, to, middle,
				leftResult, rightResult);
	}
}

class LCA {
	private final long[] order;
	private final int[] position;
	private final IntervalTree id34;
	private final int[] level;

	public LCA(Graph graph) {
		this(graph, 0);
	}

	public LCA(Graph graph, int root) {
		order = new long[2 * graph.vertexCount() - 1];
		position = new int[graph.vertexCount()];
		level = new int[graph.vertexCount()];
		int[] index = new int[graph.vertexCount()];
		for (int i = 0; i < index.length; i++)
			index[i] = graph.firstOutbound(i);
		int[] last = new int[graph.vertexCount()];
		int[] stack = new int[graph.vertexCount()];
		stack[0] = root;
		int size = 1;
		int j = 0;
		last[root] = -1;
		Arrays.fill(position, -1);
		while (size > 0) {
			int vertex = stack[--size];
			if (position[vertex] == -1)
				position[vertex] = j;
			order[j++] = vertex;
			if (last[vertex] != -1)
				level[vertex] = level[last[vertex]] + 1;
			while (index[vertex] != -1
					&& last[vertex] == graph.destination(index[vertex]))
				index[vertex] = graph.nextOutbound(index[vertex]);
			if (index[vertex] != -1) {
				stack[size++] = vertex;
				stack[size++] = graph.destination(index[vertex]);
				last[graph.destination(index[vertex])] = vertex;
				index[vertex] = graph.nextOutbound(index[vertex]);
			}
		}
		id34 = new id8(order) {
			@Override
			protected long joinValue(long left, long right) {
				if (left == -1)
					return right;
				if (right == -1)
					return left;
				if (level[((int) left)] < level[((int) right)])
					return left;
				return right;
			}

			@Override
			protected long neutralValue() {
				return -1;
			}
		};
		id34.init();
	}

	public int getPosition(int vertex) {
		return position[vertex];
	}

	public int id36(int first, int second) {
		return (int) id34.query(Math.min(position[first], position[second]),
				Math.max(position[first], position[second]));
	}

	public int getLevel(int vertex) {
		return level[vertex];
	}

	public int id32(int first, int second) {
		return level[first] + level[second] - 2 * level[id36(first, second)];
	}
}

abstract class id65 extends IntervalTree {
	protected long[] value;
	protected long[] delta;

	protected id65(int size) {
		this(size, true);
	}

	public id65(int size, boolean shouldInit) {
		super(size, shouldInit);
	}

	@Override
	protected void initData(int size, int nodeCount) {
		value = new long[nodeCount];
		delta = new long[nodeCount];
	}

	protected abstract long joinValue(long left, long right);

	protected abstract long joinDelta(long was, long delta);

	protected abstract long accumulate(long value, long delta, int length);

	protected abstract long neutralValue();

	protected abstract long neutralDelta();

	protected long initValue(int index) {
		return neutralValue();
	}

	@Override
	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
		delta[root] = neutralDelta();
	}

	@Override
	protected void initBefore(int root, int left, int right, int middle) {
	}

	@Override
	protected void initLeaf(int root, int index) {
		value[root] = initValue(index);
		delta[root] = neutralDelta();
	}

	@Override
	protected void id39(int root, int left, int right, int from,
			int to, long delta, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	@Override
	protected void id44(int root, int left, int right, int from,
			int to, long delta, int middle) {
		pushDown(root, left, middle, right);
	}

	protected void pushDown(int root, int left, int middle, int right) {
		value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root],
				middle - left + 1);
		value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root],
				right - middle);
		delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
		delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
		delta[root] = neutralDelta();
	}

	@Override
	protected void updateFull(int root, int left, int right, int from, int to,
			long delta) {
		value[root] = accumulate(value[root], delta, right - left + 1);
		this.delta[root] = joinDelta(this.delta[root], delta);
	}

	@Override
	protected long id6(int root, int left, int right, int from,
			int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	@Override
	protected void id61(int root, int left, int right, int from,
			int to, int middle) {
		pushDown(root, left, middle, right);
	}

	@Override
	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	@Override
	protected long id19() {
		return neutralValue();
	}
}

class id30 extends id65 {
	public id30(int size) {
		super(size);
	}

	@Override
	protected long joinValue(long left, long right) {
		return left + right;
	}

	@Override
	protected long joinDelta(long was, long delta) {
		return was + delta;
	}

	@Override
	protected long accumulate(long value, long delta, int length) {
		return value + delta * length;
	}

	@Override
	protected long neutralValue() {
		return 0;
	}

	@Override
	protected long neutralDelta() {
		return 0;
	}
}

abstract class id8 extends IntervalTree {
	protected long[] value;
	protected long[] array;

	protected id8(long[] array) {
		super(array.length, false);
		this.array = array;
		init();
	}

	@Override
	protected void initData(int size, int nodeCount) {
		value = new long[nodeCount];
	}

	@Override
	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	@Override
	protected void initBefore(int root, int left, int right, int middle) {
	}

	@Override
	protected void initLeaf(int root, int index) {
		value[root] = array[index];
	}

	@Override
	protected void id39(int root, int left, int right, int from,
			int to, long delta, int middle) {
		throw new UnsupportedOperationException();
	}

	@Override
	protected void id44(int root, int left, int right, int from,
			int to, long delta, int middle) {
		throw new UnsupportedOperationException();
	}

	@Override
	protected void updateFull(int root, int left, int right, int from, int to,
			long delta) {
		throw new UnsupportedOperationException();
	}

	@Override
	protected long id6(int root, int left, int right, int from,
			int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	@Override
	protected void id61(int root, int left, int right, int from,
			int to, int middle) {
	}

	@Override
	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	@Override
	protected long id19() {
		return neutralValue();
	}

	@Override
	public void update(int from, int to, long delta) {
		throw new UnsupportedOperationException();
	}

	@Override
	protected void update(int root, int left, int right, int from, int to,
			long delta) {
		throw new UnsupportedOperationException();
	}

	protected abstract long neutralValue();

	protected abstract long joinValue(long left, long right);
}