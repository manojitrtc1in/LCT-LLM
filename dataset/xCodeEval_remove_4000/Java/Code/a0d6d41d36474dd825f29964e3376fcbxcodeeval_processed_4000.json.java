import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Iterator;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		id6 solver = new id6();
		solver.solve(1, in, out);
		out.close();
	}
}

class id6 {
	private int rowCount;
	private int columnCount;
	private int[][] distance;
	private int[] malePosition;
	private int[] femalePosition;
	private int[] maleTime;
	private int[] femaleTime;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		rowCount = in.readInt();
		columnCount = in.readInt();
		int maleCount = in.readInt();
		int femaleCount = in.readInt();
		if (Math.abs(maleCount - femaleCount) != 1) {
			out.printLine(-1);
			return;
		}
		char[][] map = IOUtils.readTable(in, rowCount, columnCount);
		distance = new int[rowCount * columnCount][rowCount * columnCount];
		ArrayUtils.fill(distance, Integer.MAX_VALUE / 2);
		int[] queueRow = new int[rowCount * columnCount];
		int[] queueColumn = new int[rowCount * columnCount];
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (map[i][j] == '
					continue;
				}
				int id = i * columnCount + j;
				distance[id][id] = 0;
				queueRow[0] = i;
				queueColumn[0] = j;
				int size = 1;
				for (int k = 0; k < size; k++) {
					int row = queueRow[k];
					int column = queueColumn[k];
					for (int l = 0; l < 4; l++) {
						int nRow = row + MiscUtils.DX4[l];
						int nColumn = column + MiscUtils.DY4[l];
						if (MiscUtils.id18(nRow, nColumn, rowCount, columnCount) && map[nRow][nColumn] != '
							int nId = nRow * columnCount + nColumn;
							if (distance[id][nId] == Integer.MAX_VALUE / 2) {
								queueRow[size] = nRow;
								queueColumn[size++] = nColumn;
								distance[id][nId] = distance[id][row * columnCount + column] + 1;
							}
						}
					}
				}














			}
		}














		malePosition = new int[Math.max(maleCount, femaleCount)];
		femalePosition = new int[Math.max(maleCount, femaleCount)];
		maleTime = new int[Math.max(maleCount, femaleCount)];
		femaleTime = new int[Math.max(maleCount, femaleCount)];
		if (maleCount < femaleCount) {
			malePosition[maleCount] = read(in);
			maleTime[maleCount] = in.readInt();
		} else {
			femalePosition[femaleCount] = read(in);
			femaleTime[femaleCount] = in.readInt();
		}
		for (int i = 0; i < maleCount; i++) {
			malePosition[i] = read(in);
			maleTime[i] = in.readInt();
		}
		for (int i = 0; i < femaleCount; i++) {
			femalePosition[i] = read(in);
			femaleTime[i] = in.readInt();
		}








		Graph graph = new Graph(2 * malePosition.length + 2 * rowCount * columnCount + 2);
		int source = 2 * malePosition.length + 2 * rowCount * columnCount;
		int sink = source + 1;
		for (int i = 0; i < rowCount * columnCount; i++) {
			graph.id5(2 * malePosition.length + i, 2 * malePosition.length + rowCount * columnCount + i, 1);
		}
		for (int i = 0; i < malePosition.length; i++) {
			graph.id5(source, i, 1);
			graph.id5(i + malePosition.length, sink, 1);
		}
		int[] from = new int[2 * malePosition.length * rowCount * columnCount];
		int[] to = new int[from.length];
		long[] at = new long[from.length];
		int size = 0;
		for (int i = 0; i < malePosition.length; i++) {
			for (int j = 0; j < rowCount * columnCount; j++) {
				if (distance[malePosition[i]][j] != Integer.MAX_VALUE / 2) {
					from[size] = i;
					to[size] = 2 * malePosition.length + j;
					at[size++] = (long)distance[malePosition[i]][j] * maleTime[i];
				}
				if (distance[femalePosition[i]][j] != Integer.MAX_VALUE / 2) {
					from[size] = 2 * malePosition.length + rowCount * columnCount + j;
					to[size] = malePosition.length + i;
					at[size++] = (long)distance[femalePosition[i]][j] * femaleTime[i];
				}
			}
		}
		int[] order = ArrayUtils.createOrder(size);
		ArrayUtils.sort(order, new IntComparator() {
			public int compare(int first, int second) {
				return Long.compare(at[first], at[second]);
			}
		});
		MaxFlow maxFlow = new MaxFlow(graph, source, sink);
		int total = 0;
		for (int i : order) {
			graph.id5(from[i], to[i], 1);
			total += maxFlow.dinic();
			if (total == malePosition.length) {
				out.printLine(at[i]);
				return;
			}
		}
		out.printLine(-1);






















	}




















	private int read(InputReader in) {
		int row = in.readInt() - 1;
		int column = in.readInt() - 1;
		return row * columnCount + column;
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id17 filter;

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
		while (id3(c))
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
		} while (!id3(c));
		return res * sgn;
	}

	public boolean id3(int c) {
		if (filter != null)
			return filter.id3(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public char readCharacter() {
		int c = read();
		while (id3(c))
			c = read();
		return (char) c;
	}

	public interface id17 {
		public boolean id3(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {

	public static char[] id2(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id2(in, columnCount);
		return table;
	}

}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static int[] createOrder(int size) {
		int[] order = new int[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static int[] sort(int[] array, IntComparator comparator) {
		return sort(array, 0, array.length, comparator);
	}

	public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
		if (from == 0 && to == array.length)
			new IntArray(array).id11(comparator);
		else
			new IntArray(array).subList(from, to).id11(comparator);
		return array;
	}

}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

	public static boolean id18(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

}

class Graph {
	public static final int id19 = 0;

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
		id12(edgeCount + 1);
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

	public final int id8(int from, int to, long weight, long capacity) {
		if (capacity == 0) {
			return addEdge(from, to, weight, 0, -1);
		} else {
			int id10 = edgeCount;
			addEdge(to, from, -weight, 0, id10 + id13());
			return addEdge(from, to, weight, capacity, id10);
		}
	}

	protected int id13() {
		return 1;
	}

	public final int id5(int from, int to, long capacity) {
		return id8(from, to, 0, capacity);
	}

	public final int vertexCount() {
		return vertexCount;
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

	public final boolean flag(int id, int bit) {
		return (flags[id] >> bit & 1) != 0;
	}

	public final boolean isRemoved(int id) {
		return flag(id, id19);
	}

	protected void id12(int size) {
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

	}

}

interface IntComparator {

	public int compare(int first, int second);
}

class MaxFlow {
	private final Graph graph;
	private int source;
	private int destination;
	private int[] queue;
	private int[] distance;
	private int[] nextEdge;

	public MaxFlow(Graph graph, int source, int destination) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		int vertexCount = graph.vertexCount();
		queue = new int[vertexCount];
		distance = new int[vertexCount];
		nextEdge = new int[vertexCount];
	}

	public long dinic() {
		long totalFlow = 0;
		while (true) {
			edgeDistances();
			if (distance[destination] == -1)
				break;
			Arrays.fill(nextEdge, -2);
			totalFlow += id0(source, Long.MAX_VALUE);
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

	private long id0(int source, long flow) {
		if (source == destination)
			return flow;
		if (flow == 0 || distance[source] == distance[destination])
			return 0;
		int id = nextEdge[source];
		if (id == -2)
			nextEdge[source] = id = graph.firstOutbound(source);
		long id14 = 0;
		while (id != -1) {
			int id9 = graph.destination(id);
			if (graph.capacity(id) != 0 && distance[id9] == distance[source] + 1) {
				long pushed = id0(id9, Math.min(flow, graph.capacity(id)));
				if (pushed != 0) {
					graph.pushFlow(id, pushed);
					flow -= pushed;
					id14 += pushed;
					if (flow == 0)
						return id14;
				}
			}
			nextEdge[source] = id = graph.nextOutbound(id);
		}
		return id14;
	}
}

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();

}

interface IntIterator {
	public int value() throws NoSuchElementException;
	
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
	private static final int id15 = 16;

	public abstract int get(int index);
	public abstract void set(int index, int value);

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

	public IntList subList(final int from, final int to) {
		return new SubList(from, to);
	}

	private void swap(int first, int second) {
		if (first == second)
			return;
		int temp = get(first);
		set(first, get(second));
		set(second, temp);
	}

	public id16 id11(IntComparator comparator) {
		quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
		return new id7(this, comparator);
	}

	private void quickSort(int from, int to, int remaining, IntComparator comparator) {
		if (to - from < id15) {
			id4(from, to, comparator);
			return;
		}
		if (remaining == 0) {
			heapSort(from, to, comparator);
			return;
		}
		remaining--;
		int pivotIndex = (from + to) >> 1;
		int pivot = get(pivotIndex);
		swap(pivotIndex, to);
		int storeIndex = from;
		int equalIndex = to;
		for (int i = from; i < equalIndex; i++) {
			int value = comparator.compare(get(i), pivot);
			if (value < 0)
				swap(storeIndex++, i);
			else if (value == 0)
				swap(--equalIndex, i--);
		}
		quickSort(from, storeIndex - 1, remaining, comparator);
		for (int i = equalIndex; i <= to; i++)
			swap(storeIndex++, i);
		quickSort(storeIndex, to, remaining, comparator);
	}

	private void heapSort(int from, int to, IntComparator comparator) {
		for (int i = (to + from - 1) >> 1; i >= from; i--)
			id1(i, to, comparator, from);
		for (int i = to; i > from; i--) {
			swap(from, i);
			id1(from, i - 1, comparator, from);
		}
	}

	private void id1(int start, int end, IntComparator comparator, int delta) {
		int value = get(start);
		while (true) {
			int child = ((start - delta) << 1) + 1 + delta;
			if (child > end)
				return;
			int childValue = get(child);
			if (child + 1 <= end) {
				int otherValue = get(child + 1);
				if (comparator.compare(otherValue, childValue) > 0) {
					child++;
					childValue = otherValue;
				}
			}
			if (comparator.compare(value, childValue) >= 0)
				return;
			swap(start, child);
			start = child;
		}
	}

	private void id4(int from, int to, IntComparator comparator) {
		for (int i = from + 1; i <= to; i++) {
			int value = get(i);
			for (int j = i - 1; j >= from; j--) {
				if (comparator.compare(get(j), value) <= 0)
					break;
				swap(j, j + 1);
			}
		}
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
		IntList list = (IntList)obj;
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

	private class SubList extends IntList {
        private final int to;
        private final int from;
        private int size;

        public SubList(int from, int to) {
            this.to = to;
            this.from = from;
            size = to - from;
        }

        public int get(int index) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            return IntList.this.get(index + from);
        }

        public void set(int index, int value) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            IntList.this.set(index + from, value);
        }

        public int size() {
            return size;
        }

	}
}

abstract class id16 extends IntList {
	protected final IntComparator comparator;

	protected id16(IntComparator comparator) {
		this.comparator = comparator;
	}

	public void set(int index, int value) {
		throw new UnsupportedOperationException();
	}

	public id16 id11(IntComparator comparator) {
		if (comparator == this.comparator)
			return this;
		throw new UnsupportedOperationException();
	}

	protected void ensureSorted() {
		int size = size();
		if (size == 0)
			return;
		int last = get(0);
		for (int i = 1; i < size; i++) {
			int current = get(i);
			if (comparator.compare(last, current) > 0)
				throw new IllegalArgumentException();
			last = current;
		}
	}

	public id16 subList(final int from, final int to) {
		return new id16(comparator) {
			private int size = to - from;

			public int get(int index) {
				if (index < 0 || index >= size)
					throw new IndexOutOfBoundsException();
				return id16.this.get(index + from);
			}

			public int size() {
				return size;
			}
		};
	}
}

class IntArray extends IntList {
	private final int[] array;

	public IntArray(int[] array) {
		this.array = array;
	}

	public int get(int index) {
		return array[index];
	}

	public void set(int index, int value) {
		array[index] = value;
	}

	public int size() {
		return array.length;
	}

}

interface Edge {
}

class id7 extends id16 {
	private final int[] array;

	public id7(IntCollection collection, IntComparator comparator) {
		super(comparator);
		array = new int[collection.size()];
		int i = 0;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
		ensureSorted();
	}

	public int get(int index) {
		return array[index];
	}

	public int size() {
		return array.length;
	}
}

