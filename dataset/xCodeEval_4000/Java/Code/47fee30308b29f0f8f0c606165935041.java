import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskE {
		final int maxP = 16;
		int n;
		int m;
		int q;
		Graph gr;
		int[][] pr;
		IntArrayList[][] people;
		int[] depth;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			

			n = in.readInt();
			m = in.readInt();
			q = in.readInt();
			gr = new BidirectionalGraph(n, n - 1);
			for (int iter = 0; iter < n - 1; iter++) {
				int a = in.readInt() - 1;
				int b = in.readInt() - 1;
				gr.addSimpleEdge(a, b);
			}
			people = new IntArrayList[maxP + 1][n];
			for (int i = 0; i < n; i++) {
				people[0][i] = new IntArrayList(10);
			}
			for (int i = 1; i <= m; i++) {
				int v = in.readInt() - 1;
				if (people[0][v].size() < 10)
					people[0][v].add(i);
			}
		

		


			depth = new int[n];
			pr = new int[maxP + 1][n];
			ArrayUtils.fill(pr, -1);
			dfs(0, -1);

			for (int p = 0; p <= maxP; p++) {
				for (int v = 0; v < n; v++) {
					if (p == 0) {
					} else {
						int up = pr[p - 1][v];
						if (up == -1) {
							people[p][v] = people[p - 1][v];
						} else {
							people[p][v] = merge(people[p - 1][v], people[p - 1][up]);
							pr[p][v] = pr[p - 1][up];
						}
					}
				}
			}


			LCA lca = new LCA(gr);

			for (int iter = 0; iter < q; iter++) {
				int v = in.readInt() - 1;
				int to = in.readInt() - 1;
				int cnt = in.readInt();








				int vto = lca.getLCA(v, to);

				IntArrayList a = go(v, vto);
				IntArrayList b = go(to, vto);
				IntSet set = new IntSplaySet();
				for (int x : a.toArray()) set.add(x);
				for (int x : b.toArray()) set.add(x);

				

				out.print(Math.min(cnt, set.size()));



				int[] ints = set.toArray();
				for (int i = 0; i < Math.min(cnt, ints.length); i++) {
					out.print(" ");
					out.print(ints[i]);
				}


				out.printLine();
			}
		}

		IntArrayList merge(IntArrayList a, IntArrayList b) {
			IntArrayList c = new IntArrayList(Math.min(10, a.size() + b.size()));
			int posA = 0;
			int posB = 0;
			for (; c.size() < 10 && posA != a.size() && posB != b.size(); ) {
				if (a.get(posA) < b.get(posB))
					c.add(a.get(posA++));
				else
					c.add(b.get(posB++));
			}
			for (; c.size() < 10 && posA != a.size(); ) c.add(a.get(posA++));
			for (; c.size() < 10 && posB != b.size(); ) c.add(b.get(posB++));
			return c;
		}

		private IntArrayList go(int v, int u) {
			IntArrayList res = new IntArrayList(0);
			for (int p = maxP; 0 <= p; p--) {
				int to = pr[p][v];
				if (to != -1 && depth[u] <= depth[to]) {
					res = merge(res, people[p][v]);
					v = to;
				}
			}
			if (!(v == u || pr[0][v] == u))
				throw new RuntimeException();
			res = merge(res, people[0][u]);
			return res;
		}

		private void dfs(int v, int p) {
			pr[0][v] = p;
			for (Edge edge : gr.outbound(v)) {
				if (edge.getDestination() == p) continue;
				depth[edge.getDestination()] = depth[v] + 1;
				dfs(edge.getDestination(), v);
			}
		}

	}

	static abstract class IntList extends IntCollection implements Comparable<IntList> {
		public abstract int get(int index);


		public IntIterator iterator() {
			return new IntIterator() {
				private int size = size();
				private int index = 0;

				public int value() throws NoSuchElementException {
					if (!isValid())
						throw new NoSuchElementException();
					return get(index);
				}

				public void advance() throws NoSuchElementException {
					if (!isValid())
						throw new NoSuchElementException();
					index++;
				}

				public boolean isValid() {
					return index < size;
				}
			};
		}

		public int hashCode() {
			int hashCode = 1;
			for (IntIterator i = iterator(); i.isValid(); i.advance())
				hashCode = 31 * hashCode + i.value();
			return hashCode;
		}


		public boolean equals(Object obj) {
			if (!(obj instanceof IntList))
				return false;
			IntList list = (IntList) obj;
			if (list.size() != size())
				return false;
			IntIterator i = iterator();
			IntIterator j = list.iterator();
			while (i.isValid()) {
				if (i.value() != j.value())
					return false;
				i.advance();
				j.advance();
			}
			return true;
		}

		public int compareTo(IntList o) {
			IntIterator i = iterator();
			IntIterator j = o.iterator();
			while (true) {
				if (i.isValid()) {
					if (j.isValid()) {
						if (i.value() != j.value()) {
							if (i.value() < j.value())
								return -1;
							else
								return 1;
						}
					} else
						return 1;
				} else {
					if (j.isValid())
						return -1;
					else
						return 0;
				}
				i.advance();
				j.advance();
			}
		}

	}

	static class IntArrayList extends IntList {
		private int[] array;
		private int size;

		public IntArrayList() {
			this(10);
		}

		public IntArrayList(int capacity) {
			array = new int[capacity];
		}

		public IntArrayList(IntList list) {
			this(list.size());
			addAll(list);
		}


		public int get(int index) {
			if (index >= size)
				throw new IndexOutOfBoundsException();
			return array[index];
		}


		public int size() {
			return size;
		}


		public void add(int value) {
			ensureCapacity(size + 1);
			array[size++] = value;
		}

		public void ensureCapacity(int newCapacity) {
			if (newCapacity > array.length) {
				int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
				System.arraycopy(array, 0, newArray, 0, size);
				array = newArray;
			}
		}


		public int[] toArray() {
			int[] array = new int[size];
			System.arraycopy(this.array, 0, array, 0, size);
			return array;
		}

	}

	static class OutputWriter {
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

		public void printLine() {
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void print(int i) {
			writer.print(i);
		}

	}

	static abstract class IntCollection {
		public abstract IntIterator iterator();

		public abstract int size();

		public abstract void add(int value);

		public int[] toArray() {
			int size = size();
			int[] array = new int[size];
			int i = 0;
			for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
				array[i++] = iterator.value();
			return array;
		}

		public void addAll(IntCollection values) {
			for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
				add(it.value());
			}
		}

	}

	static abstract class IntervalTree {
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

		protected abstract long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);

		protected abstract void queryPreProcess(int root, int left, int right, int from, int to, int middle);

		protected abstract long queryFull(int root, int left, int right, int from, int to);

		protected abstract long emptySegmentResult();

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

		public long query(int from, int to) {
			return query(0, 0, size - 1, from, to);
		}

		protected long query(int root, int left, int right, int from, int to) {
			if (left > to || right < from)
				return emptySegmentResult();
			if (left >= from && right <= to)
				return queryFull(root, left, right, from, to);
			int middle = (left + right) >> 1;
			queryPreProcess(root, left, right, from, to, middle);
			long leftResult = query(2 * root + 1, left, middle, from, to);
			long rightResult = query(2 * root + 2, middle + 1, right, from, to);
			return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult);
		}

	}

	static class BidirectionalGraph extends Graph {
		public int[] transposedEdge;

		public BidirectionalGraph(int vertexCount) {
			this(vertexCount, vertexCount);
		}

		public BidirectionalGraph(int vertexCount, int edgeCapacity) {
			super(vertexCount, 2 * edgeCapacity);
			transposedEdge = new int[2 * edgeCapacity];
		}


		public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
			int lastEdgeCount = edgeCount;
			super.addEdge(fromID, toID, weight, capacity, reverseEdge);
			super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
			this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
			this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
			return lastEdgeCount;
		}


		protected int entriesPerEdge() {
			return 2;
		}


		protected void ensureEdgeCapacity(int size) {
			if (size > edgeCapacity()) {
				super.ensureEdgeCapacity(size);
				transposedEdge = resize(transposedEdge, edgeCapacity());
			}
		}

	}

	static abstract class IntSet extends IntCollection {
	}

	static class LCA {
		private final long[] order;
		private final int[] position;
		private final Graph graph;
		private final IntervalTree lcaTree;
		private final int[] level;

		public LCA(Graph graph) {
			this(graph, 0);
		}

		public LCA(Graph graph, int root) {
			this.graph = graph;
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
				while (index[vertex] != -1 && last[vertex] == graph.destination(index[vertex]))
					index[vertex] = graph.nextOutbound(index[vertex]);
				if (index[vertex] != -1) {
					stack[size++] = vertex;
					stack[size++] = graph.destination(index[vertex]);
					last[graph.destination(index[vertex])] = vertex;
					index[vertex] = graph.nextOutbound(index[vertex]);
				}
			}
			lcaTree = new ReadOnlyIntervalTree(order) {

				protected long joinValue(long left, long right) {
					if (left == -1)
						return right;
					if (right == -1)
						return left;
					if (level[((int) left)] < level[((int) right)])
						return left;
					return right;
				}


				protected long neutralValue() {
					return -1;
				}
			};
			lcaTree.init();
		}

		public int getLCA(int first, int second) {
			return (int) lcaTree.query(Math.min(position[first], position[second]), Math.max(position[first], position[second]));
		}

	}

	static class ArrayUtils {
		public static void fill(int[][] array, int value) {
			for (int[] row : array)
				Arrays.fill(row, value);
		}

	}

	static class IntSplaySet extends IntSet {
		protected int[] value;
		protected int[] left;
		protected int[] right;
		protected int[] parent;
		private int[] size;
		private final IntComparator comparator;
		private int nextFree;
		protected int root = -1;

		public IntSplaySet() {
			this(null);
		}

		public IntSplaySet(IntComparator comparator) {
			this(comparator, 5);
		}

		public IntSplaySet(int capacity) {
			this(null, capacity);
		}

		public IntSplaySet(IntComparator comparator, int capacity) {
			this.comparator = comparator;
			value = new int[capacity];
			left = new int[capacity];
			right = new int[capacity];
			parent = new int[capacity];
			size = new int[capacity];
		}

		protected final int compare(int first, int second) {
			if (comparator == null) {
				return first < second ? -1 : first == second ? 0 : 1;
			} else {
				return comparator.compare(first, second);
			}
		}


		public IntIterator iterator() {
			return new IntIterator() {
				private boolean first = true;
				private boolean exhausted = root == -1;


				public int value() throws NoSuchElementException {
					if (first) {
						if (root == -1) {
							throw new NoSuchElementException();
						}
						int leftmost = leftmost(root);
						splay(leftmost);
						first = false;
					}
					return value[root];
				}


				public void advance() throws NoSuchElementException {
					if (root == -1 || exhausted) {
						throw new NoSuchElementException();
					}
					int next = leftmost(right[root]);
					if (next == -1) {
						exhausted = true;
						return;
					}
					splay(next);
				}


				public boolean isValid() {
					return !exhausted;
				}
			};
		}

		private void splay(int node) {
			if (node == -1) {
				return;
			}
			while (parent[node] != -1) {
				if (parent[parent[node]] == -1) {
					rotate(node);
				} else if ((left[parent[node]] == node) == (left[parent[parent[node]]] == parent[node])) {
					rotate(parent[node]);
					rotate(node);
				} else {
					rotate(node);
					rotate(node);
				}
			}
			this.root = node;
		}

		private void rotate(int node) {
			int cParent = parent[node];
			if (node == left[cParent]) {
				setLeft(cParent, right[node]);
				if (parent[cParent] != -1) {
					if (cParent == left[parent[cParent]]) {
						setLeft(parent[cParent], node);
					} else {
						setRight(parent[cParent], node);
					}
				} else {
					parent[node] = -1;
				}
				setRight(node, cParent);
			} else {
				setRight(cParent, left[node]);
				if (parent[cParent] != -1) {
					if (cParent == left[parent[cParent]]) {
						setLeft(parent[cParent], node);
					} else {
						setRight(parent[cParent], node);
					}
				} else {
					parent[node] = -1;
				}
				setLeft(node, cParent);
			}
			update(cParent);
			update(node);
		}

		protected void update(int node) {
			size[node] = size(left[node]) + size(right[node]) + 1;
		}

		protected int size(int node) {
			if (node != -1) {
				return size[node];
			}
			return 0;
		}

		protected int leftmost(int root) {
			if (root == -1) {
				return -1;
			}
			while (left[root] != -1) {
				root = left[root];
			}
			return root;
		}


		public int size() {
			return size(root);
		}


		public void add(int value) {
			if (contains(value)) {
				return;
			}
			ensureCapacity(nextFree + 1);
			Split roots = split(root, value);
			setLeft(nextFree, roots.left);
			setRight(nextFree, roots.right);
			parent[nextFree] = -1;
			this.value[nextFree] = value;
			update(nextFree);
			root = nextFree++;
		}

		private void setLeft(int node, int child) {
			left[node] = child;
			if (child != -1) {
				parent[child] = node;
			}
		}

		private void setRight(int node, int child) {
			right[node] = child;
			if (child != -1) {
				parent[child] = node;
			}
		}

		protected Split split(int root, int value) {
			if (root == -1) {
				return new Split();
			}
			int compare = compare(this.value[root], value);
			if (compare < 0) {
				Split result = split(right[root], value);
				setRight(root, result.left);
				result.left = root;
				update(root);
				behead(root);
				return result;
			} else if (compare > 0) {
				Split result = split(left[root], value);
				setLeft(root, result.right);
				result.right = root;
				update(root);
				behead(root);
				return result;
			} else {
				Split result = new Split();
				result.left = left[root];
				result.right = right[root];
				behead(left[root]);
				behead(right[root]);
				return result;
			}
		}

		protected int ensureCapacity(int capacity) {
			if (parent.length < capacity) {
				capacity = Math.max(2 * parent.length, capacity);
				left = Arrays.copyOf(left, capacity);
				right = Arrays.copyOf(right, capacity);
				parent = Arrays.copyOf(parent, capacity);
				size = Arrays.copyOf(size, capacity);
				value = Arrays.copyOf(value, capacity);
				return capacity;
			}
			return parent.length;
		}


		public boolean contains(int value) {
			int node = root;
			int lastNode = -1;
			while (node != -1) {
				lastNode = node;
				int compare = compare(value, this.value[node]);
				if (compare == 0) {
					splay(node);
					return true;
				}
				if (compare < 0) {
					node = left[node];
				} else {
					node = right[node];
				}
			}
			if (lastNode != -1) {
				splay(lastNode);
			}
			return false;
		}

		protected void behead(int node) {
			if (node != -1) {
				parent[node] = -1;
			}
		}

		protected static class Split {
			protected int left = -1;
			protected int right = -1;

		}

	}

	static interface Edge {
		public int getDestination();

	}

	static abstract class ReadOnlyIntervalTree extends IntervalTree {
		protected long[] value;
		protected long[] array;

		protected ReadOnlyIntervalTree(long[] array) {
			super(array.length, false);
			this.array = array;
			init();
		}


		protected void initData(int size, int nodeCount) {
			value = new long[nodeCount];
		}


		protected void initAfter(int root, int left, int right, int middle) {
			value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
		}


		protected void initBefore(int root, int left, int right, int middle) {
		}


		protected void initLeaf(int root, int index) {
			value[root] = array[index];
		}


		protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
			return joinValue(leftResult, rightResult);
		}


		protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
		}


		protected long queryFull(int root, int left, int right, int from, int to) {
			return value[root];
		}


		protected long emptySegmentResult() {
			return neutralValue();
		}

		protected abstract long neutralValue();

		protected abstract long joinValue(long left, long right);

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;

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

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);

		}

	}

	static interface IntComparator {
		public int compare(int first, int second);

	}

	static class Graph {
		public static final int REMOVED_BIT = 0;
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
		public long[] capacity;
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

		public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
			ensureEdgeCapacity(edgeCount + 1);
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

		public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
			if (capacity == 0) {
				return addEdge(from, to, weight, 0, -1);
			} else {
				int lastEdgeCount = edgeCount;
				addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
				return addEdge(from, to, weight, capacity, lastEdgeCount);
			}
		}

		protected int entriesPerEdge() {
			return 1;
		}

		public final int addWeightedEdge(int from, int to, long weight) {
			return addFlowWeightedEdge(from, to, weight, 0);
		}

		public final int addSimpleEdge(int from, int to) {
			return addWeightedEdge(from, to, 0);
		}

		public final int vertexCount() {
			return vertexCount;
		}

		protected final int edgeCapacity() {
			return from.length;
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

		public final int destination(int id) {
			return to[id];
		}

		protected final void initEdges() {
			if (edges == null) {
				edges = new Edge[from.length];
				for (int i = 0; i < edgeCount; i++)
					edges[i] = createEdge(i);
			}
		}

		public final boolean flag(int id, int bit) {
			return (flags[id] >> bit & 1) != 0;
		}

		public final void setFlag(int id, int bit) {
			flags[id] |= 1 << bit;
		}

		public final void removeEdge(int id) {
			setFlag(id, REMOVED_BIT);
		}

		public final boolean isRemoved(int id) {
			return flag(id, REMOVED_BIT);
		}

		public final Iterable<Edge> outbound(final int id) {
			initEdges();
			return new Iterable<Edge>() {
				public Iterator<Edge> iterator() {
					return new EdgeIterator(id, firstOutbound, nextOutbound);
				}
			};
		}

		protected void ensureEdgeCapacity(int size) {
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

		protected class GraphEdge implements Edge {
			protected int id;

			protected GraphEdge(int id) {
				this.id = id;
			}

			public int getDestination() {
				return destination(id);
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

	static interface IntIterator {
		public int value();

		public void advance();

		public boolean isValid();

	}
}
