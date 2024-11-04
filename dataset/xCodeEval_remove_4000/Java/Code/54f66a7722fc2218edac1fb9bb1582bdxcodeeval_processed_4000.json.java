import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;


public class TaskD {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;

	private void solve() {
		int roomCount = in.readInt();
		int edgeCount = in.readInt();
		Edge[] edges = new Edge[edgeCount];
		int last = in.readInt() - 1;
		for (int i = 0; i < edgeCount; i++) {
			int next = in.readInt() - 1;
			edges[i] = new SimpleEdge(last, next);
			last = next;
		}
		Graph graph = new id9(roomCount);
		boolean found = false;
		for (int i = edgeCount - 1; i >= 0; i--) {
			graph.addEdge(edges[i]);
			Edge minimal = id24(edges[i].getSource(), edges[i].getDestination(), graph);
			if (minimal != null) {
				edges[i] = minimal;
				graph.removeEdge(minimal);
				for (i++; i < edgeCount; i++) {
					edges[i] = id24(edges[i - 1].getDestination(), -1, graph);
					graph.removeEdge(edges[i]);
				}
				found = true;
				break;
			}
		}
		if (found) {
			out.print(edges[0].getSource() + 1);
			for (Edge edge : edges)
				out.print(" " + (edge.getDestination() + 1));
			out.println();
		} else
			out.println("No solution");
	}

	private Edge restrictedEdge;
	private Edge id8;
	private int visited;

	private id28 callback = new id28() {
		public boolean vertexAdded(Graph graph, Edge edge) {
			if (edge == restrictedEdge || edge == id8)
				return false;
			visited++;
			return true;
		}

		public void alreadyVisited(Graph graph, Edge edge) {
		}
	};

	private Edge id24(int source, int destination, Graph graph) {
		List<Edge> edges = graph.getIncident(source);
		Collections.sort(edges, new Comparator<Edge>() {
			public int compare(Edge o1, Edge o2) {
				return o1.getDestination() - o2.getDestination();
			}
		});
		int nonZero = 0;
		int vertexCount = graph.id18();
		for (int i = 0; i < vertexCount; i++) {
			if (!graph.getIncident(i).isEmpty())
				nonZero++;
		}
		if (edges.size() == 1)
			nonZero--;
		for (Edge edge : edges) {
			if (edge.getDestination() <= destination) {
				continue;
			}
			visited = 1;
			restrictedEdge = edge;
			id8 = edge.id3();
			graph.bfs(edge.getDestination(), callback);
			if (visited == nonZero) {
				return edge;
			}
		}
		return null;
	}

	public interface DFSCallback<R, P> {
		public static final Object EMPTY_PARAMETERS = new Object();
		public R id21(Graph graph, int vertex, Edge edge, P parameters);
		public R id15(Graph graph, int vertex, Edge edge, P parameters);
		public void exitVertex(Graph graph, int vertex, Edge edge, P parameters, R currentResult);
		public P id1(Graph graph, int vertex, Edge edge, P parameters, R currentResult, Edge nextEdge);
		public boolean id10(Graph graph, int vertex, Edge edge, P parameters, R currentResult,
				Edge nextEdge, R visitResult, P passedParameters);
	}

	public static abstract class id14<R> implements DFSCallback<R, Object> {
		public R id21(Graph graph, int vertex, Edge edge, Object parameters) {
			return null;
		}

		public R id15(Graph graph, int vertex, Edge edge, Object parameters) {
			return null;
		}

		public void exitVertex(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult) {
		}

		public Object id1(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult,
								 Edge nextEdge) {
			return EMPTY_PARAMETERS;
		}

		public boolean id10(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult, Edge nextEdge,
										 Object visitResult, Object passedParameters)
		{
			return true;
		}
	}

	public interface id29<R, P> extends DFSCallback<R, P> {
		public R start(Graph graph);
		public P id30(R currentResult, int startVertex);
		public boolean id19(R currentResult, int startVertex, R visitResult, P parameters);
		public void finish(Graph graph, R currentResult);
	}

	public static abstract class id17<R> extends id14<R>
			implements id29<R, Object>
	{
		public R start(Graph graph) {
			return null;
		}

		public Object id30(R currentResult, int startVertex) {
			return EMPTY_PARAMETERS;
		}

		public boolean id19(R currentResult, int startVertex, R visitResult, Object parameters) {
			return true;
		}

		public void finish(Graph graph, R currentResult) {
		}
	}

	public interface id28 {
		public boolean vertexAdded(Graph graph, Edge edge);
		public void alreadyVisited(Graph graph, Edge edge);
	}

	public interface id6 extends id28 {
		public void id22(Graph graph, int vertex);
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
		protected final id27 transposed;

		public SimpleEdge(int source, int destination) {
			this.source = source;
			this.destination = destination;
			transposed = new id27(this);
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
			return transposed;
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

		public Edge id23() {
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

	public static class id27 implements Edge {
		private final Edge parent;

		public id27(Edge parent) {
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
		public int id18();
		public List<Edge> getIncident(int source);
		public void addEdge(Edge edge);
		public <R, P> R dfs(int startVertex, DFSCallback<R, P> callback, P parameters);
		public <R, P> R fullDFS(id29<R, P> callback);
		public <R, P> R fullDFS(id29<R, P> callback, int[] order);
		public void bfs(int startVertex, id28 callback);
		public void id12(id6 callback);
		public void id12(id6 callback, int[] order);
		public List<Edge> getEdges();
		public Graph transposed();
		public void removeEdge(Edge edge);
	}

	public static class id9 extends SparseGraph {
		public id9(int vertexCount) {
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

		public void removeEdge(Edge edge) {
			super.removeEdge(edge);
			super.removeEdge(edge.id3());
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

		public int id18() {
			return vertexCount;
		}

		public void addEdge(Edge edge) {
			allEdges = null;
			edges[edge.getSource()].add(edge);
			if (edge instanceof FlowEdge)
				edges[edge.getDestination()].add(((FlowEdge)edge).id23());
		}

		public <R, P> R dfs(int startVertex, DFSCallback<R, P> callback, P parameters) {
			boolean[] visited  = new boolean[vertexCount];
			return dfsImpl(startVertex, callback, visited, parameters, null);
		}

		public <R, P> R fullDFS(id29<R, P> callback) {
			boolean[] visited = new boolean[vertexCount];
			R result = callback.start(this);
			for (int i = 0; i < vertexCount; i++) {
				P parameters = callback.id30(result, i);
				if (parameters == null)
					continue;
				R currentResult = dfsImpl(i, callback, visited, parameters, null);
				if (!callback.id19(result, i, currentResult, parameters))
					break;
			}
			callback.finish(this, result);
			return result;
		}

		public <R, P> R fullDFS(id29<R, P> callback, int[] order) {
			boolean[] visited = new boolean[vertexCount];
			R result = callback.start(this);
			for (int i : order) {
				P parameters = callback.id30(result, i);
				if (parameters == null)
					continue;
				R currentResult = dfsImpl(i, callback, visited, parameters, null);
				if (!callback.id19(result, i, currentResult, parameters))
					break;
			}
			callback.finish(this, result);
			return result;
		}

		public void bfs(int startVertex, id28 callback) {
			boolean[] visited = new boolean[vertexCount];
			id13(startVertex, callback, visited);
		}

		private void id13(int startVertex, id28 callback, boolean[] visited) {
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

		public void id12(id6 callback) {
			boolean[] visited = new boolean[vertexCount];
			for (int i = 0; i < vertexCount; i++) {
				if (!visited[i]) {
					callback.id22(this, i);
					id13(i, callback, visited);
				}
			}
		}

		public void id12(id6 callback, int[] order) {
			boolean[] visited = new boolean[vertexCount];
			for (int i : order) {
				if (!visited[i]) {
					callback.id22(this, i);
					id13(i, callback, visited);
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

		public void removeEdge(Edge edge) {
			edges[edge.getSource()].remove(edge);
		}

		private <R, P> R dfsImpl(int vertex, DFSCallback<R, P> callback, boolean[] visited, P parameters, Edge edge) {
			if (visited[vertex])
				return callback.id15(this, vertex, edge, parameters);
			R result = callback.id21(this, vertex, edge, parameters);
			visited[vertex] = true;
			for (Edge nextEdge : getIncident(vertex)) {
				P passedParameters = callback.id1(this, vertex, edge, parameters, result,
						nextEdge);
				if (passedParameters == null) {
					if (!callback.id10(this, vertex, edge, parameters, result, nextEdge, null, null))
						break;
					continue;
				}
				if (!callback.id10(this, vertex, edge, parameters, result, nextEdge,
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
		new TaskD().run();
	}

	private TaskD() {
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

		public String readLine(boolean id25) {
			if (id25)
				return readLine();
			else
				return id5();
		}

		public BigInteger id20() {
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

		public long[] id11(int size) {
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

		public String[] id26(int size) {
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
