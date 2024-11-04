import java.util.*;
import java.io.*;
import java.io.File;
import java.util.AbstractSet;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.*;
public class Hello {

  

  public static void main(String[] args) {
    

    

    

      Scanner in = new Scanner(System.in);
      

      


      int n = in.nextInt();
      int m = in.nextInt();
      
      int [][]a = new int[n][m];
      
      for (int i = 0;i < n;++i) {
	for (int j = 0;j < m;++j) {
	  a[i][j] = in.nextInt() - 1;
	}
      }
      
      

      

      
      int shoe = m * n / 2;
      
      int []dx = {-1, 0, 0, 1};
      int []dy = {0, -1, 1, 0};
      
      

      
      

      Graph graph = new Graph(2 * shoe + 2);

      int source = 2 * shoe, sink = 2 * shoe + 1;
      
      for (int i = 0;i < n;++i) {
	for (int j = 0;j < m;++j) {
	  int id = i * m + j;
	  if ((i + j) % 2 == 0) {

	    for (int z = 0;z < 4;++z) {
	      int i1 = i + dx[z];
	      int j1 = j + dy[z];
	      if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m) continue;
	      int id1 = i1 * m + j1;
	      int wt = (a[i][j] == a[i1][j1])?0:1;
	      graph.addFlowWeightedEdge(id, id1, wt, 1);
	    }
	    graph.addFlowWeightedEdge(source, id, 0, 1);
	  } else {

	    graph.addFlowWeightedEdge(id, sink, 0, 1);
	  }
	}
      }
      MinCostFlow mcf = new MinCostFlow(graph, source, sink, false);
      Pair<Long, Long> ans = mcf.minCostMaxFlow();
      System.out.println(ans.first);
    

    

    

  }


}
class Graph {
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

  public final int addFlowEdge(int from, int to, long capacity) {
    return addFlowWeightedEdge(from, to, 0, capacity);
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
    return flag(id, REMOVED_BIT);
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


class MinCostFlow {
  private final Graph graph;
  private final int source;
  private final int destination;
  private final long[] phi;
  private final long[] dijkstraResult;
  private final int[] lastEdge;
  private final Heap heap;
  private final int vertexCount;
  private final int[] visited;
  private int visitIndex;

  public MinCostFlow(Graph graph, int source, int destination, boolean hasNegativeEdges) {
    this.graph = graph;
    this.source = source;
    this.destination = destination;
    vertexCount = graph.vertexCount();
    phi = new long[vertexCount];
    if (hasNegativeEdges)
      fordBellman();
    dijkstraResult = new long[vertexCount];
    lastEdge = new int[vertexCount];
    if (graph.isSparse()) {
      heap = new Heap(vertexCount, new IntComparator() {
	  public int compare(int first, int second) {
	  return IntegerUtils.longCompare(dijkstraResult[first], dijkstraResult[second]);
	  }
	  }, vertexCount);
      visited = null;
    } else {
      heap = null;
      visited = new int[vertexCount];
    }
  }

  private void fordBellman() {
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

    public Heap(int vertexCount, IntComparator intComparator, int vertexCount1) {
      list = new IntArrayList(vertexCount);
      index = new int[vertexCount1];
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
      list = new IntArrayList();
      shift = 0;
      Arrays.fill(index, -1);
    }
  }

  public Pair<Long, Long> minCostMaxFlow() {
    return minCostMaxFlow(Long.MAX_VALUE);
  }

  public Pair<Long, Long> minCostMaxFlow(long maxFlow) {
    long cost = 0;
    long flow = 0;
    while (maxFlow != 0) {
      if (graph.isSparse())
	dijkstraAlgorithm();
      else
	dijkstraAlgorithmFull();
      if (lastEdge[destination] == -1)
	return Pair.makePair(cost, flow);
      for (int i = 0; i < dijkstraResult.length; i++) {
	if (dijkstraResult[i] != Long.MAX_VALUE)
	  phi[i] += dijkstraResult[i];
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

  private void dijkstraAlgorithm() {
    Arrays.fill(dijkstraResult, Long.MAX_VALUE);
    Arrays.fill(lastEdge, -1);
    dijkstraResult[source] = 0;
    heap.clear();
    heap.add(source);
    while (!heap.isEmpty()) {
      int current = heap.poll();
      int edgeID = graph.firstOutbound(current);
      while (edgeID != -1) {
	if (graph.capacity(edgeID) != 0) {
	  int next = graph.destination(edgeID);
	  long total = graph.weight(edgeID) - phi[next] + phi[current] + dijkstraResult[current];
	  if (dijkstraResult[next] > total) {
	    dijkstraResult[next] = total;
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

  private void dijkstraAlgorithmFull() {
    visitIndex++;
    Arrays.fill(dijkstraResult, Long.MAX_VALUE);
    lastEdge[destination] = -1;
    dijkstraResult[source] = 0;
    for (int i = 0; i < vertexCount; i++) {
      int index = -1;
      long length = Long.MAX_VALUE;
      for (int j = 0; j < vertexCount; j++) {
	if (visited[j] != visitIndex && dijkstraResult[j] < length) {
	  length = dijkstraResult[j];
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
	    if (dijkstraResult[next] > total) {
	      dijkstraResult[next] = total;
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

class IntArrayList extends IntList {
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

