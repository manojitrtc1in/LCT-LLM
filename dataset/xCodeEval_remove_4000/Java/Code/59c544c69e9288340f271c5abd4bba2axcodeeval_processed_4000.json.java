import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;


public class TaskC {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;

	private void solve() {
		int vertexCount = in.readInt();
		Graph graph = new id8(vertexCount);
		int edgeCount = in.readInt();
		for (int i = 0; i < edgeCount; i++) {
			int source = in.readInt() - 1;
			int destination = in.readInt() - 1;
			int gcd = in.readInt();
			int lcm = in.readInt();
			graph.addEdge(new MyEdge(source, destination, gcd, lcm));
		}
		long[] base = new long[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			base[i] = 1;
			int maxValue = Integer.MAX_VALUE;
			for (Edge edge : graph.getIncident(i)) {
				base[i] = lcm(base[i], ((MyEdge)edge).id15());
				maxValue = Math.min(maxValue, ((MyEdge) edge).id26());
				if (base[i] > maxValue) {
					out.println("NO");
					return;
				}
			}
		}
		for (Edge edge : graph.getEdges()) {
			long a = base[edge.getSource()];
			long b = base[edge.getDestination()];
			if (gcd(a, b) != ((MyEdge)edge).id15()) {
				out.println("NO");
				return;
			}
			a /= gcd(a, b);
			if (((MyEdge)edge).id26() % (a * b) != 0) {
				out.println("NO");
				return;
			}
			((MyEdge)edge).lcm = (int) (((MyEdge)edge).id26() / (a * b));
		}
		long[] additional = new long[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			if (additional[i] != 0)
				continue;
			long maxAdditional = 0;
			for (Edge edge : graph.getIncident(i))
				maxAdditional = gcd(maxAdditional, ((MyEdge)edge).id26());
			if (maxAdditional == 0) {
				additional[i] = 1;
				continue;
			}
			boolean found = false;
			for (long add = 1; add * add <= maxAdditional; add++) {
				if ((maxAdditional % add) != 0)
					continue;
				if (tryApply(graph, additional, i, add, base)) {
					found = true;
					break;
				}
				if (add * add != maxAdditional && tryApply(graph, additional, i, maxAdditional / add, base)) {
					found = true;
					break;
				}
			}
			if (!found) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		for (int i = 0; i < vertexCount; i++)
			out.print((base[i] * additional[i]) + " ");
		out.println();
	}

	private boolean tryApply(Graph graph, final long[] additional, int vertex, long add, final long[] base) {
		final boolean[] ok = new boolean[1];
		ok[0] = true;
		additional[vertex] = add;
		graph.bfs(vertex, new id27() {
			public boolean vertexAdded(Graph graph, Edge edge) {
				int source = edge.getSource();
				int destination = edge.getDestination();
				long a = additional[source];
				long lcm = ((MyEdge)edge).id26();
				if (lcm % a != 0) {
					ok[0] = false;
					additional[destination] = 1;
					return true;
				}
				long b = additional[destination] = lcm / a;
				if (gcd(a * base[source], b * base[destination]) != ((MyEdge)edge).id15())
					ok[0] = false;
				return true;
			}

			public void alreadyVisited(Graph graph, Edge edge) {
				int source = edge.getSource();
				int destination = edge.getDestination();
				long a = additional[source];
				long b = additional[destination];
				long lcm = ((MyEdge)edge).id26();
				if (a * b != lcm && gcd(a * base[source], b * base[destination]) != ((MyEdge)edge).id15())
					ok[0] = false;
			}
		});
		return ok[0];
	}

	private long lcm(long a, long b) {
		return a * b / gcd(a, b);
	}

	private long gcd(long a, long b) {
		while (b != 0) {
			long temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	public static class MyEdge extends SimpleEdge {
		private final int gcd;
		private int lcm;

		public MyEdge(int source, int destination, int gcd, int lcm) {
			super(source, destination);
			this.gcd = gcd;
			this.lcm = lcm;
		}

		public int id15() {
			return gcd;
		}

		public int id26() {
			return lcm;
		}

		@Override
		public Edge id3() {
			return new MyEdge(destination, source, gcd, lcm);
		}
	}

	public interface DFSCallback<R, P> {
		public static final Object EMPTY_PARAMETERS = new Object();
		public R id20(Graph graph, int vertex, Edge edge, P parameters);
		public R id14(Graph graph, int vertex, Edge edge, P parameters);
		public void exitVertex(Graph graph, int vertex, Edge edge, P parameters, R currentResult);
		public P id1(Graph graph, int vertex, Edge edge, P parameters, R currentResult, Edge nextEdge);
		public boolean id9(Graph graph, int vertex, Edge edge, P parameters, R currentResult,
				Edge nextEdge, R visitResult, P passedParameters);
	}

	public static abstract class id13<R> implements DFSCallback<R, Object> {
		public R id20(Graph graph, int vertex, Edge edge, Object parameters) {
			return null;
		}

		public R id14(Graph graph, int vertex, Edge edge, Object parameters) {
			return null;
		}

		public void exitVertex(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult) {
		}

		public Object id1(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult,
								 Edge nextEdge) {
			return EMPTY_PARAMETERS;
		}

		public boolean id9(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult, Edge nextEdge,
										 Object visitResult, Object passedParameters)
		{
			return true;
		}
	}

	public interface id28<R, P> extends DFSCallback<R, P> {
		public R start(Graph graph);
		public P id29(R currentResult, int startVertex);
		public boolean id18(R currentResult, int startVertex, R visitResult, P parameters);
		public void finish(Graph graph, R currentResult);
	}

	public interface id27 {
		public boolean vertexAdded(Graph graph, Edge edge);
		public void alreadyVisited(Graph graph, Edge edge);
	}

	public interface id6 extends id27 {
		public void id21(Graph graph, int vertex);
	}

	public interface Edge {
		public int getSource();
		public int getDestination();
		public int getWeight();
		public int getCapacity();
		public int getFlow();
		public void pushFlow(int flow);
		public Edge id3();
	}

	public static class SimpleEdge implements Edge {
		protected final int source;
		protected final int destination;

		public SimpleEdge(int source, int destination) {
			this.source = source;
			this.destination = destination;
		}

		public int getSource() {
			return source;
		}

		public int getDestination() {
			return destination;
		}

		public int getWeight() {
			return 1;
		}

		public int getCapacity() {
			return 0;
		}

		public int getFlow() {
			return 0;
		}

		public void pushFlow(int flow) {
			throw new UnsupportedOperationException();
		}

		public Edge id3() {
			return new id25(this);
		}
	}

	public static class WeightedEdge extends SimpleEdge {
		protected final int weight;

		public WeightedEdge(int source, int destination, int weight) {
			super(source, destination);
			this.weight = weight;
		}

		@Override
		public int getWeight() {
			return weight;
		}

		@Override
		public Edge id3() {
			return new WeightedEdge(destination, source, weight);
		}
	}

	public static class FlowEdge extends SimpleEdge {
		protected int capacity;
		private int flow = 0;

		public FlowEdge(int source, int destination, int capacity) {
			super(source, destination);
			this.capacity = capacity;
		}

		@Override
		public int getCapacity() {
			return capacity;
		}

		@Override
		public int getFlow() {
			return flow;
		}

		@Override
		public void pushFlow(int flow) {
			if (this.capacity < flow)
				throw new IllegalArgumentException("Not enough capacity");
			if (this.flow < -flow)
				throw new IllegalArgumentException("Not enough flow");
			this.flow += flow;
			this.capacity -= flow;
		}

		@Override
		public int getWeight() {
			return 0;
		}

		@Override
		public Edge id3() {
			return new FlowEdge(destination, source, capacity);
		}

		public Edge id22() {
			return new ReverseEdge(this);
		}

		protected static class ReverseEdge implements Edge {
			private final FlowEdge parent;

			public ReverseEdge(FlowEdge edge) {
				parent = edge;
			}

			public int getSource() {
				return parent.getDestination();
			}

			public int getDestination() {
				return parent.getSource();
			}

			public int getWeight() {
				return -parent.getWeight();
			}

			public int getCapacity() {
				return parent.getFlow();
			}

			public int getFlow() {
				return 0;
			}

			public void pushFlow(int flow) {
				parent.pushFlow(-flow);
			}

			public Edge id3() {
				throw new UnsupportedOperationException();
			}
		}
	}

	public static class id2 extends FlowEdge {
		protected final int weight;

		public id2(int source, int destination, int capacity, int weight) {
			super(source, destination, capacity);
			this.weight = weight;
		}

		@Override
		public int getWeight() {
			return weight;
		}

		@Override
		public Edge id3() {
			return new id2(destination, source, capacity, weight);
		}
	}

	public static class id25 implements Edge {
		private final Edge parent;

		public id25(Edge parent) {
			this.parent = parent;
		}

		public int getSource() {
			return parent.getDestination();
		}

		public int getDestination() {
			return parent.getSource();
		}

		public int getWeight() {
			return parent.getWeight();
		}

		public int getCapacity() {
			return 0;
		}

		public int getFlow() {
			return 0;
		}

		public void pushFlow(int flow) {
			throw new UnsupportedOperationException();
		}

		public Edge id3() {
			return parent;
		}
	}

	public interface Graph {
		public int id17();
		public List<Edge> getIncident(int source);
		public void addEdge(Edge edge);
		public <R, P> R dfs(int startVertex, DFSCallback<R, P> callback, P parameters);
		public <R, P> R fullDFS(id28<R, P> callback);
		public <R, P> R fullDFS(id28<R, P> callback, int[] order);
		public void bfs(int startVertex, id27 callback);
		public void id11(id6 callback);
		public void id11(id6 callback, int[] order);
		public List<Edge> getEdges();
		public Graph transposed();
	}

	public static class id8 extends SparseGraph {
		public id8(int vertexCount) {
			super(vertexCount);
		}

		@Override
		public void addEdge(Edge edge) {
			super.addEdge(edge);
			super.addEdge(edge.id3());
		}

		@Override
		public Graph transposed() {
			return this;
		}
	}

	public static class SparseGraph implements Graph {
		private final int vertexCount;
		private final List<Edge>[] edges;
		private List<Edge> allEdges = null;

		public SparseGraph(int vertexCount) {
			this.vertexCount = vertexCount;
			

			edges = new List[vertexCount];
			for (int i = 0; i < vertexCount; i++)
				edges[i] = new ArrayList<Edge>();
		}

		public int id17() {
			return vertexCount;
		}

		public void addEdge(Edge edge) {
			allEdges = null;
			edges[edge.getSource()].add(edge);
			if (edge instanceof FlowEdge)
				edges[edge.getDestination()].add(((FlowEdge)edge).id22());
		}

		public <R, P> R dfs(int startVertex, DFSCallback<R, P> callback, P parameters) {
			boolean[] visited  = new boolean[vertexCount];
			return dfsImpl(startVertex, callback, visited, parameters, null);
		}

		public <R, P> R fullDFS(id28<R, P> callback) {
			boolean[] visited = new boolean[vertexCount];
			R result = callback.start(this);
			for (int i = 0; i < vertexCount; i++) {
				P parameters = callback.id29(result, i);
				if (parameters == null)
					continue;
				R currentResult = dfsImpl(i, callback, visited, parameters, null);
				if (!callback.id18(result, i, currentResult, parameters))
					break;
			}
			callback.finish(this, result);
			return result;
		}

		public <R, P> R fullDFS(id28<R, P> callback, int[] order) {
			boolean[] visited = new boolean[vertexCount];
			R result = callback.start(this);
			for (int i : order) {
				P parameters = callback.id29(result, i);
				if (parameters == null)
					continue;
				R currentResult = dfsImpl(i, callback, visited, parameters, null);
				if (!callback.id18(result, i, currentResult, parameters))
					break;
			}
			callback.finish(this, result);
			return result;
		}

		public void bfs(int startVertex, id27 callback) {
			boolean[] visited = new boolean[vertexCount];
			id12(startVertex, callback, visited);
		}

		private void id12(int startVertex, id27 callback, boolean[] visited) {
			if (visited[startVertex])
				return;
			Queue<Integer> queue = new ArrayDeque<Integer>(vertexCount);
			queue.add(startVertex);
			visited[startVertex] = true;
			while (!queue.isEmpty()) {
				int currentVertex = queue.poll();
				for (Edge edge : getIncident(currentVertex)) {
					int destination = edge.getDestination();
					if (!visited[destination] && callback.vertexAdded(this, edge)) {
						visited[destination] = true;
						queue.add(destination);
					} else if (visited[destination])
						callback.alreadyVisited(this, edge);
				}
			}
		}

		public void id11(id6 callback) {
			boolean[] visited = new boolean[vertexCount];
			for (int i = 0; i < vertexCount; i++) {
				if (!visited[i]) {
					callback.id21(this, i);
					id12(i, callback, visited);
				}
			}
		}

		public void id11(id6 callback, int[] order) {
			boolean[] visited = new boolean[vertexCount];
			for (int i : order) {
				if (!visited[i]) {
					callback.id21(this, i);
					id12(i, callback, visited);
				}
			}
		}

		public List<Edge> getEdges() {
			if (allEdges != null)
				return allEdges;
			allEdges = new ArrayList<Edge>();
			for (int i = 0; i < vertexCount; i++)
				allEdges.addAll(getIncident(i));
			return allEdges;
		}

		public Graph transposed() {
			Graph graph = new SparseGraph(vertexCount);
			for (Edge edge : getEdges())
				graph.addEdge(edge.id3());
			return graph;
		}

		private <R, P> R dfsImpl(int vertex, DFSCallback<R, P> callback, boolean[] visited, P parameters, Edge edge) {
			if (visited[vertex])
				return callback.id14(this, vertex, edge, parameters);
			R result = callback.id20(this, vertex, edge, parameters);
			visited[vertex] = true;
			for (Edge nextEdge : getIncident(vertex)) {
				P passedParameters = callback.id1(this, vertex, edge, parameters, result,
						nextEdge);
				if (passedParameters == null) {
					if (!callback.id9(this, vertex, edge, parameters, result, nextEdge, null, null))
						break;
					continue;
				}
				if (!callback.id9(this, vertex, edge, parameters, result, nextEdge,
						dfsImpl(nextEdge.getDestination(), callback, visited, passedParameters, nextEdge),
						passedParameters))
				{
					break;
				}
			}
			callback.exitVertex(this, vertex, edge, parameters, result);
			return result;
		}

		public List<Edge> getIncident(int source) {
			return edges[source];
		}
	}

	public static void main(String[] args) {
		new TaskC().run();
	}

	private TaskC() {
		@SuppressWarnings({"UnusedDeclaration"})
		String id = getClass().getName().toLowerCase();
		

		try {








		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	private void run() {
		







		solve();
		exit();
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private void exit() {
		out.close();
		System.exit(0);
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

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

		public int readInt() {
			int c = read();
			while (id7(c))
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
			} while (!id7(c));
			return res * sgn;
		}

		public long readLong() {
			int c = read();
			while (id7(c))
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
			} while (!id7(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (id7(c))
				c = read();
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id7(c));
			return res.toString();
		}

		private boolean id7(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String id5() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = id5();
			while (s.trim().length() == 0)
				s = id5();
			return s;
		}

		public String readLine(boolean id23) {
			if (id23)
				return readLine();
			else
				return id5();
		}

		public BigInteger id19() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (id7(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
			int c = read();
			while (id7(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!id7(c) && c != '.') {
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
				while (!id7(c)) {
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

		public int[] id0(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		public long[] id10(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		public double[] id4(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		public String[] id24(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		public char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		public void id16(int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}
}
