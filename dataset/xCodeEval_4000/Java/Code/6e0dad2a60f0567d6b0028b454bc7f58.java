import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.OutputStream;

public class Main{
	public static void main(String[] args){
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
	static class TaskD{
		public void solve(int testNumber, InputReader in, OutputWriter out){
			int n = in.ri(), m = in.ri(), s = in.ri() - 1;
			BidirectionalGraph g = new BidirectionalGraph(n);
			ArrayList<TaskD.Edgee> edges = new ArrayList<>();
			for(int i = 0; i < m; i++) {
				int a = in.ri() - 1, b = in.ri() - 1, w = in.ri();
				g.addWeightedEdge(a, b, w);
				edges.add(new TaskD.Edgee(a, b, w));
			}
			int want = in.ri();
			Pair<long[], int[]> res = ShortestDistance.dijkstraAlgorithm(g, s);
			long[] distances = res.first;
			int ans = 0;
			for(long d : distances)
				if(d == want)
					ans++;
			for(TaskD.Edgee e : edges) {
				boolean foundfromlefttoa = false;
				long distancefromlefttoa = -1;
				long leftfroma = want - distances[e.a];
				if(leftfroma > 0 && leftfroma < e.l){
					long leftfromb = e.l - leftfroma;
					if(leftfromb > 0 && leftfromb + distances[e.b] >= want){
						ans++;
						foundfromlefttoa = true;
						distancefromlefttoa = leftfroma;
					}
				}
				long rightfromb = want - distances[e.b];
				if(rightfromb > 0 && rightfromb < e.l){
					long rightfroma = e.l - rightfromb;
					if(rightfroma > 0 && rightfroma + distances[e.a] >= want){
						ans++;
						if(foundfromlefttoa && distancefromlefttoa == rightfroma){
							ans--;
						}
					}
				}
				

				

				

				

				

				

				

				

				

				

				

				

			}
			out.printLine(ans);
		}
		class Edgee{
			int a;
			int b;
			int l;
			public Edgee(int a, int b, int l){
				this.a = a;
				this.b = b;
				this.l = l;
			}
		}
	}
	static interface IntComparator{
		public static final IntComparator DEFAULT = new IntComparator(){
			public int compare(int first, int second){
				if(first < second)
					return -1;
				if(first > second)
					return 1;
				return 0;
			}
		};
		public int compare(int first, int second);
	}
	static interface Edge{
	}
	static class OutputWriter{
		private final PrintWriter writer;
		public OutputWriter(OutputStream outputStream){
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}
		public OutputWriter(Writer writer){
			this.writer = new PrintWriter(writer);
		}
		public void close(){
			writer.close();
		}
		public void printLine(int i){
			writer.println(i);
		}
	}
	static class Graph{
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
		public Graph(int vertexCount){
			this(vertexCount, vertexCount);
		}
		public Graph(int vertexCount, int edgeCapacity){
			this.vertexCount = vertexCount;
			firstOutbound = new int[vertexCount];
			Arrays.fill(firstOutbound, -1);
			from = new int[edgeCapacity];
			to = new int[edgeCapacity];
			nextOutbound = new int[edgeCapacity];
			flags = new int[edgeCapacity];
		}
		public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge){
			ensureEdgeCapacity(edgeCount + 1);
			if(firstOutbound[fromID] != -1)
				nextOutbound[edgeCount] = firstOutbound[fromID];
			else
				nextOutbound[edgeCount] = -1;
			firstOutbound[fromID] = edgeCount;
			if(firstInbound != null){
				if(firstInbound[toID] != -1)
					nextInbound[edgeCount] = firstInbound[toID];
				else
					nextInbound[edgeCount] = -1;
				firstInbound[toID] = edgeCount;
			}
			this.from[edgeCount] = fromID;
			this.to[edgeCount] = toID;
			if(capacity != 0){
				if(this.capacity == null)
					this.capacity = new long[from.length];
				this.capacity[edgeCount] = capacity;
			}
			if(weight != 0){
				if(this.weight == null)
					this.weight = new long[from.length];
				this.weight[edgeCount] = weight;
			}
			if(reverseEdge != -1){
				if(this.reverseEdge == null){
					this.reverseEdge = new int[from.length];
					Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
				}
				this.reverseEdge[edgeCount] = reverseEdge;
			}
			if(edges != null)
				edges[edgeCount] = createEdge(edgeCount);
			return edgeCount++;
		}
		protected final Graph.GraphEdge createEdge(int id){
			return new Graph.GraphEdge(id);
		}
		public final int addFlowWeightedEdge(int from, int to, long weight, long capacity){
			if(capacity == 0){
				return addEdge(from, to, weight, 0, -1);
			} else{
				int lastEdgeCount = edgeCount;
				addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
				return addEdge(from, to, weight, capacity, lastEdgeCount);
			}
		}
		protected int entriesPerEdge(){
			return 1;
		}
		public final int addWeightedEdge(int from, int to, long weight){
			return addFlowWeightedEdge(from, to, weight, 0);
		}
		public final int vertexCount(){
			return vertexCount;
		}
		protected final int edgeCapacity(){
			return from.length;
		}
		public final int firstOutbound(int vertex){
			int id = firstOutbound[vertex];
			while(id != -1 && isRemoved(id))
				id = nextOutbound[id];
			return id;
		}
		public final int nextOutbound(int id){
			id = nextOutbound[id];
			while(id != -1 && isRemoved(id))
				id = nextOutbound[id];
			return id;
		}
		public final int destination(int id){
			return to[id];
		}
		public final long weight(int id){
			if(weight == null)
				return 0;
			return weight[id];
		}
		public final boolean flag(int id, int bit){
			return (flags[id] >> bit & 1) != 0;
		}
		public final boolean isRemoved(int id){
			return flag(id, REMOVED_BIT);
		}
		protected void ensureEdgeCapacity(int size){
			if(from.length < size){
				int newSize = Math.max(size, 2 * from.length);
				if(edges != null)
					edges = resize(edges, newSize);
				from = resize(from, newSize);
				to = resize(to, newSize);
				nextOutbound = resize(nextOutbound, newSize);
				if(nextInbound != null)
					nextInbound = resize(nextInbound, newSize);
				if(weight != null)
					weight = resize(weight, newSize);
				if(capacity != null)
					capacity = resize(capacity, newSize);
				if(reverseEdge != null)
					reverseEdge = resize(reverseEdge, newSize);
				flags = resize(flags, newSize);
			}
		}
		protected final int[] resize(int[] array, int size){
			int[] newArray = new int[size];
			System.arraycopy(array, 0, newArray, 0, array.length);
			return newArray;
		}
		private long[] resize(long[] array, int size){
			long[] newArray = new long[size];
			System.arraycopy(array, 0, newArray, 0, array.length);
			return newArray;
		}
		private Edge[] resize(Edge[] array, int size){
			Edge[] newArray = new Edge[size];
			System.arraycopy(array, 0, newArray, 0, array.length);
			return newArray;
		}
		public final boolean isSparse(){
			return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
		}
		protected class GraphEdge implements Edge{
			protected int id;
			protected GraphEdge(int id){
				this.id = id;
			}
		}
	}
	static class Heap{
		private IntComparator comparator;
		private int size = 0;
		private int[] elements;
		private int[] at;
		public Heap(int maxElement){
			this(10, maxElement);
		}
		public Heap(IntComparator comparator, int maxElement){
			this(10, comparator, maxElement);
		}
		public Heap(int capacity, int maxElement){
			this(capacity, IntComparator.DEFAULT, maxElement);
		}
		public Heap(int capacity, IntComparator comparator, int maxElement){
			this.comparator = comparator;
			elements = new int[capacity];
			at = new int[maxElement];
			Arrays.fill(at, -1);
		}
		public boolean isEmpty(){
			return size == 0;
		}
		public int add(int element){
			ensureCapacity(size + 1);
			elements[size] = element;
			at[element] = size;
			shiftUp(size++);
			return at[element];
		}
		public void shiftUp(int index){
			

			

			int value = elements[index];
			while(index != 0){
				int parent = (index - 1) >>> 1;
				int parentValue = elements[parent];
				if(comparator.compare(parentValue, value) <= 0){
					elements[index] = value;
					at[value] = index;
					return;
				}
				elements[index] = parentValue;
				at[parentValue] = index;
				index = parent;
			}
			elements[0] = value;
			at[value] = 0;
		}
		public void shiftDown(int index){
			if(index < 0 || index >= size)
				throw new IllegalArgumentException();
			while(true){
				int child = (index << 1) + 1;
				if(child >= size)
					return;
				if(child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0)
					child++;
				if(comparator.compare(elements[index], elements[child]) <= 0)
					return;
				swap(index, child);
				index = child;
			}
		}
		public int getIndex(int element){
			return at[element];
		}
		private void swap(int first, int second){
			int temp = elements[first];
			elements[first] = elements[second];
			elements[second] = temp;
			at[elements[first]] = first;
			at[elements[second]] = second;
		}
		private void ensureCapacity(int size){
			if(elements.length < size){
				int[] oldElements = elements;
				elements = new int[Math.max(2 * elements.length, size)];
				System.arraycopy(oldElements, 0, elements, 0, this.size);
			}
		}
		public int poll(){
			if(isEmpty())
				throw new IndexOutOfBoundsException();
			int result = elements[0];
			at[result] = -1;
			if(size == 1){
				size = 0;
				return result;
			}
			elements[0] = elements[--size];
			at[elements[0]] = 0;
			shiftDown(0);
			return result;
		}
	}
	static class BidirectionalGraph extends Graph{
		public int[] transposedEdge;
		public BidirectionalGraph(int vertexCount){
			this(vertexCount, vertexCount);
		}
		public BidirectionalGraph(int vertexCount, int edgeCapacity){
			super(vertexCount, 2 * edgeCapacity);
			transposedEdge = new int[2 * edgeCapacity];
		}
		public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge){
			int lastEdgeCount = edgeCount;
			super.addEdge(fromID, toID, weight, capacity, reverseEdge);
			super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
			this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
			this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
			return lastEdgeCount;
		}
		protected int entriesPerEdge(){
			return 2;
		}
		protected void ensureEdgeCapacity(int size){
			if(size > edgeCapacity()){
				super.ensureEdgeCapacity(size);
				transposedEdge = resize(transposedEdge, edgeCapacity());
			}
		}
	}
	static class Pair<U, V> implements Comparable<Pair<U, V>>{
		public U first;
		public V second;
		public static <U, V> Pair<U, V> makePair(U first, V second){
			return new Pair<U, V>(first, second);
		}
		private Pair(U first, V second){
			this.first = first;
			this.second = second;
		}
		public boolean equals(Object o){
			if(this == o)
				return true;
			if(o == null || getClass() != o.getClass())
				return false;
			Pair pair = (Pair) o;
			return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);
		}
		public int hashCode(){
			int result = first != null ? first.hashCode() : 0;
			result = 31 * result + (second != null ? second.hashCode() : 0);
			return result;
		}
		public String toString(){
			return "(" + first + "," + second + ")";
		}
		@SuppressWarnings({"unchecked"})
		public int compareTo(Pair<U, V> o){
			int value = ((Comparable<U>) first).compareTo(o.first);
			if(value != 0)
				return value;
			return ((Comparable<V>) second).compareTo(o.second);
		}
	}
	static class InputReader{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private InputReader.SpaceCharFilter filter;
		public InputReader(InputStream stream){
			this.stream = stream;
		}
		public int read(){
			if(numChars == -1)
				throw new InputMismatchException();
			if(curChar >= numChars){
				curChar = 0;
				try{
					numChars = stream.read(buf);
				} catch(IOException e){
					throw new InputMismatchException();
				}
				if(numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
		public int ri(){
			return readInt();
		}
		public int readInt(){
			int c = read();
			while(isSpaceChar(c))
				c = read();
			int sgn = 1;
			if(c == '-'){
				sgn = -1;
				c = read();
			}
			int res = 0;
			do{
				if(c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while(!isSpaceChar(c));
			return res * sgn;
		}
		public boolean isSpaceChar(int c){
			if(filter != null)
				return filter.isSpaceChar(c);
			return isWhitespace(c);
		}
		public static boolean isWhitespace(int c){
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
		public interface SpaceCharFilter{
			public boolean isSpaceChar(int ch);
		}
	}
	static class IntegerUtils{
		public static int longCompare(long a, long b){
			if(a < b)
				return -1;
			if(a > b)
				return 1;
			return 0;
		}
	}
	static class ShortestDistance{
		public static Pair<long[], int[]> dijkstraAlgorithm(Graph graph, int source){
			int vertexCount = graph.vertexCount();
			final long[] distance = new long[vertexCount];
			int[] last = new int[vertexCount];
			Arrays.fill(distance, Long.MAX_VALUE);
			Arrays.fill(last, -1);
			distance[source] = 0;
			if(graph.isSparse()){
				Heap heap = new Heap(vertexCount, new IntComparator(){
					public int compare(int first, int second){
						return IntegerUtils.longCompare(distance[first], distance[second]);
					}
				}, vertexCount);
				heap.add(source);
				while(!heap.isEmpty()){
					int current = heap.poll();
					int id = graph.firstOutbound(current);
					while(id != -1){
						int next = graph.destination(id);
						long total = graph.weight(id) + distance[current];
						if(distance[next] > total){
							distance[next] = total;
							if(heap.getIndex(next) == -1)
								heap.add(next);
							else
								heap.shiftUp(heap.getIndex(next));
							last[next] = id;
						}
						id = graph.nextOutbound(id);
					}
				}
			} else{
				boolean[] visited = new boolean[vertexCount];
				for(int i = 0; i < vertexCount; i++) {
					int index = -1;
					long length = Long.MAX_VALUE;
					for(int j = 0; j < vertexCount; j++) {
						if(!visited[j] && distance[j] < length){
							length = distance[j];
							index = j;
						}
					}
					if(index == -1)
						break;
					visited[index] = true;
					int id = graph.firstOutbound(index);
					while(id != -1){
						int next = graph.destination(id);
						if(!visited[next]){
							long total = graph.weight(id) + length;
							if(distance[next] > total){
								distance[next] = total;
								last[next] = id;
							}
						}
						id = graph.nextOutbound(id);
					}
				}
			}
			return Pair.makePair(distance, last);
		}
	}
}

