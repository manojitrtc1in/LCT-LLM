import java.util.*;
import java.io.*;
import java.math.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
public class Hello {
  static int n, K;
  static char [][]mat;
  public static void main(String[] args) {
    

    

    

      

      FastReader in = new FastReader(System.in);
      
      n = in.nextInt();
      K = in.nextInt();
      mat = new char[2][n];
      for (int i = 0;i < 2;++i) {
	String s = in.nextLine();
	for (int j = 0;j < n;++j) {
	  mat[i][j] = s.charAt(j);
	}
      }
      

      
      int [][]wt = new int[K][K];
      for (int j = 0;j < n;++j) {
	int i0 = (mat[0][j] >= 'A' && mat[0][j] <= 'Z')?mat[0][j] - 'A' + 26:mat[0][j] - 'a';
	int i1 = (mat[1][j] >= 'A' && mat[1][j] <= 'Z')?mat[1][j] - 'A' + 26:mat[1][j] - 'a';
	

	wt[i0][i1] += 1;
      }
      
      Graph graph = new Graph(K * 2 + 2);

      int source = 2 * K, sink = K * 2 + 1;
      
      
      for (int i = 0;i < K;++i) {
	graph.id7(source, i, 0, 1);
      }
      for (int i = 0;i < K;++i) {
	graph.id7(K + i, sink, 0, 1);
      }
      
      Long max = Long.MAX_VALUE;
      int [][]id = new int[K][K];
      for (int i = 0;i < K;++i) {
	for (int j = 0;j < K;++j) {
	  id[i][j] = graph.id7(i, j + K, max - wt[i][j], 1);
	}
      }
      id10 mcf = new id10(graph, source, sink, false);
      Pair<Long, Long> ans = mcf.id6();
      
      System.out.println(max * K - ans.first);

      for (int i = 0;i < K;++i) {
	for (int j = 0;j < K;++j) {
	  if (graph.flow(id[i][j]) == 1) {
	    char c = 'a';
	    if (j >= 26) c = (char)('A' + (j - 26));
	    else c = (char)('a' + j);
	    System.out.print(c);
	  }
	}
      }
      
	  
      
    

    

    

  }
}

class FastReader {
    private boolean finished = false;
 
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id18 filter;
 
    public FastReader(InputStream stream) {
        this.stream = stream;
    }
 
    public int read() {
        if (numChars == -1) {
            throw new InputMismatchException();
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0) {
                return -1;
            }
        }
 
        return buf[curChar++];
    }
 
    public int peek() {
        if (numChars == -1) {
            return -1;
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar];
    }
 
    public int nextInt() {
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
            if (c == ',') {
                c = read();
            }
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id3(c));
        return res * sgn;
    }
 
    public long nextLong() {
        int c = read();
        while (id3(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id3(c));
        return res * sgn;
    }
 
    public String nextString() {
        int c = read();
        while (id3(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id3(c));
        return res.toString();
    }
 
    public boolean id3(int c) {
        if (filter != null) {
            return filter.id3(c);
        }
        return isWhitespace(c);
    }
 
    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    private String id1() {
        StringBuilder buf = new StringBuilder();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r') {
                buf.appendCodePoint(c);
            }
            c = read();
        }
        return buf.toString();
    }
 
    public String nextLine() {
        String s = id1();
        while (s.trim().length() == 0)
            s = id1();
        return s;
    }
 
    public String nextLine(boolean id17) {
        if (id17) {
            return nextLine();
        } else {
            return id1();
        }
    }
 
    public BigInteger id4() {
        try {
            return new BigInteger(nextString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }
 
    public char nextCharacter() {
        int c = read();
        while (id3(c))
            c = read();
        return (char) c;
    }
 
    public double nextDouble() {
        int c = read();
        while (id3(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id3(c) && c != '.') {
            if (c == 'e' || c == 'E') {
                return res * Math.pow(10, nextInt());
            }
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!id3(c)) {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }
 
    public boolean id2() {
        int value;
        while (id3(value = peek()) && value != -1)
            read();
        return value == -1;
    }
 
    public String next() {
        return nextString();
    }
 
    public id18 getFilter() {
        return filter;
    }
 
    public void setFilter(id18 filter) {
        this.filter = filter;
    }
 
    public interface id18 {
        public boolean id3(int ch);
    }
}
class Graph {
  public static final int id20 = 0;

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

  public final int id7(int from, int to, long weight, long capacity) {
    if (capacity == 0) {
      return addEdge(from, to, weight, 0, -1);
    } else {
      int id9 = edgeCount;
      addEdge(to, from, -weight, 0, id9 + id13());
      return addEdge(from, to, weight, capacity, id9);
    }
  }

  protected int id13() {
    return 1;
  }

  public final int id5(int from, int to, long capacity) {
    return id7(from, to, 0, capacity);
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

  public final boolean flag(int id, int bit) {
    return (flags[id] >> bit & 1) != 0;
  }

  public final boolean isRemoved(int id) {
    return flag(id, id20);
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

  public final boolean isSparse() {
    return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
  }

  protected class GraphEdge implements Edge {
    protected int id;

    protected GraphEdge(int id) {
      this.id = id;
    }

  }

}


class id10 {
  private final Graph graph;
  private final int source;
  private final int destination;
  private final long[] phi;
  private final long[] id8;
  private final int[] lastEdge;
  private final Heap heap;
  private final int vertexCount;
  private final int[] visited;
  private int visitIndex;

  public id10(Graph graph, int source, int destination, boolean id16) {
    this.graph = graph;
    this.source = source;
    this.destination = destination;
    vertexCount = graph.vertexCount();
    phi = new long[vertexCount];
    if (id16)
      id11();
    id8 = new long[vertexCount];
    lastEdge = new int[vertexCount];
    if (graph.isSparse()) {
      heap = new Heap(vertexCount, new IntComparator() {
	  public int compare(int first, int second) {
	  return IntegerUtils.longCompare(id8[first], id8[second]);
	  }
	  }, vertexCount);
      visited = null;
    } else {
      heap = null;
      visited = new int[vertexCount];
    }
  }

  private void id11() {
    Arrays.fill(phi, Long.MAX_VALUE);
    phi[source] = 0;
    boolean[] inQueue = new boolean[vertexCount];
    int[] queue = new int[vertexCount + 1];
    queue[0] = source;
    inQueue[source] = true;
    int stepCount = 0;
    int head = 0;
    int end = 1;
    int maxSteps = 2 * vertexCount * vertexCount;
    while (head != end) {
      int vertex = queue[head++];
      if (head == queue.length)
	head = 0;
      inQueue[vertex] = false;
      int edgeID = graph.firstOutbound(vertex);
      while (edgeID != -1) {
	long total = phi[vertex] + graph.weight(edgeID);
	int destination = graph.destination(edgeID);
	if (graph.capacity(edgeID) != 0 && phi[destination] > total) {
	  phi[destination] = total;
	  if (!inQueue[destination]) {
	    queue[end++] = destination;
	    inQueue[destination] = true;
	    if (end == queue.length)
	      end = 0;
	  }
	}
	edgeID = graph.nextOutbound(edgeID);
      }
      if (++stepCount > maxSteps)
	throw new IllegalArgumentException("Graph contains negative cycle");
    }
  }

  class Heap {
    IntList list;
    int shift;
    int[] index;

    public Heap(int vertexCount, IntComparator intComparator, int id0) {
      list = new id15(vertexCount);
      index = new int[id0];
      Arrays.fill(index, -1);
    }

    public void add(int source) {
      index[source] = 0;
      list.add(source);
    }

    public boolean isEmpty() {
      return shift == list.size();
    }

    public int poll() {
      int result = list.get(shift++);
      index[result] = -1;
      return result;
    }

    public int getIndex(int next) {
      return index[next];
    }

    public void shiftUp(int index) {
    }

    public void clear() {
      list = new id15();
      shift = 0;
      Arrays.fill(index, -1);
    }
  }

  public Pair<Long, Long> id6() {
    return id6(Long.MAX_VALUE);
  }

  public Pair<Long, Long> id6(long maxFlow) {
    long cost = 0;
    long flow = 0;
    while (maxFlow != 0) {
      if (graph.isSparse())
	id19();
      else
	id14();
      if (lastEdge[destination] == -1)
	return Pair.makePair(cost, flow);
      for (int i = 0; i < id8.length; i++) {
	if (id8[i] != Long.MAX_VALUE)
	  phi[i] += id8[i];
      }
      int vertex = destination;
      long currentFlow = maxFlow;
      long currentCost = 0;
      while (vertex != source) {
	int edgeID = lastEdge[vertex];
	currentFlow = Math.min(currentFlow, graph.capacity(edgeID));
	currentCost += graph.weight(edgeID);
	vertex = graph.source(edgeID);
      }
      maxFlow -= currentFlow;
      cost += currentCost * currentFlow;
      flow += currentFlow;
      vertex = destination;
      while (vertex != source) {
	int edgeID = lastEdge[vertex];
	graph.pushFlow(edgeID, currentFlow);
	vertex = graph.source(edgeID);
      }
    }
    return Pair.makePair(cost, flow);
  }

  private void id19() {
    Arrays.fill(id8, Long.MAX_VALUE);
    Arrays.fill(lastEdge, -1);
    id8[source] = 0;
    heap.clear();
    heap.add(source);
    while (!heap.isEmpty()) {
      int current = heap.poll();
      int edgeID = graph.firstOutbound(current);
      while (edgeID != -1) {
	if (graph.capacity(edgeID) != 0) {
	  int next = graph.destination(edgeID);
	  long total = graph.weight(edgeID) - phi[next] + phi[current] + id8[current];
	  if (id8[next] > total) {
	    id8[next] = total;
	    if (heap.getIndex(next) == -1)
	      heap.add(next);
	    else
	      heap.shiftUp(heap.getIndex(next));
	    lastEdge[next] = edgeID;
	  }
	}
	edgeID = graph.nextOutbound(edgeID);
      }
    }
  }

  private void id14() {
    visitIndex++;
    Arrays.fill(id8, Long.MAX_VALUE);
    lastEdge[destination] = -1;
    id8[source] = 0;
    for (int i = 0; i < vertexCount; i++) {
      int index = -1;
      long length = Long.MAX_VALUE;
      for (int j = 0; j < vertexCount; j++) {
	if (visited[j] != visitIndex && id8[j] < length) {
	  length = id8[j];
	  index = j;
	}
      }
      if (index == -1) {
	return;
      }
      visited[index] = visitIndex;
      int edgeID = graph.firstOutbound(index);
      while (edgeID != -1) {
	if (graph.capacity(edgeID) != 0) {
	  int next = graph.destination(edgeID);
	  if (visited[next] != visitIndex) {
	    long total = graph.weight(edgeID) - phi[next] + phi[index] + length;
	    if (id8[next] > total) {
	      id8[next] = total;
	      lastEdge[next] = edgeID;
	    }
	  }
	}
	edgeID = graph.nextOutbound(edgeID);
      }
    }
  }
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
  public final U first;
  public final V second;

  public static<U, V> Pair<U, V> makePair(U first, V second) {
    return new Pair<U, V>(first, second);
  }

  private Pair(U first, V second) {
    this.first = first;
    this.second = second;
  }

  public boolean equals(Object o) {
    if (this == o) return true;
    if (o == null || getClass() != o.getClass()) return false;

    Pair pair = (Pair) o;

    return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

  }

  public int hashCode() {
    int result = first != null ? first.hashCode() : 0;
    result = 31 * result + (second != null ? second.hashCode() : 0);
    return result;
  }

  public String toString() {
    return "(" + first + "," + second + ")";
  }

  public int compareTo(Pair<U, V> o) {
    int value = ((Comparable<U>)first).compareTo(o.first);
    if (value != 0)
      return value;
    return ((Comparable<V>)second).compareTo(o.second);
  }
}

abstract class IntCollection {
  public abstract IntIterator iterator();
  public abstract int size();
  public abstract void add(int value);

  public void addAll(IntCollection values) {
    for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
      add(it.value());
    }
  }

}

interface IntIterator {
  public int value() throws NoSuchElementException;
  
  public void advance() throws NoSuchElementException;
  public boolean isValid();
}

interface Edge {
}

abstract class IntList extends IntCollection implements Comparable<IntList> {

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

}

class id15 extends IntList {
  private int[] array;
  private int size;

  public id15() {
    this(10);
  }

  public id15(int capacity) {
    array = new int[capacity];
  }

  public id15(IntList list) {
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

}

interface IntComparator {

}

class IntegerUtils {

  public static int longCompare(long a, long b) {
    if (a < b)
      return -1;
    if (a > b)
      return 1;
    return 0;
  }

}
