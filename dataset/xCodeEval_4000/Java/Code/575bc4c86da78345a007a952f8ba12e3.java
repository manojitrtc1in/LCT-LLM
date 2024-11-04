import java.util.*;
import java.io.*;
import java.io.File;
import java.util.AbstractSet;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.*;
public class Hello {

  

  public static void main(String[] args) {
    try {
    

    

      

       Scanner in = new Scanner(new File("input.txt"));
       PrintWriter out = new PrintWriter("output.txt");

      
      int n = in.nextInt();
      String []words = new String[n];
      for (int i = 0;i < n;++i) words[i] = in.next();
      

      

      
      Map<String, Set<Integer>> indices = new CPPMap<String, Set<Integer>>(new Factory<Set<Integer>>() {
	  public Set<Integer> create() {
	  return new HashSet<Integer>();
	  }
	  });
    
      for (int i = 0;i < n;++i) {
	int ln = words[i].length();
	for (int i0 = 0;i0 < ln;++i0) {
	  StringBuilder builder = new StringBuilder();
	  builder.append(words[i].charAt(i0));
	  indices.get(builder.toString()).add(i);
	}
	for (int i0 = 0;i0 < ln;++i0) {
	for (int i1 = i0 + 1;i1 < ln;++i1) {
	  StringBuilder builder = new StringBuilder();
	  builder.append(words[i].charAt(i0));
	  builder.append(words[i].charAt(i1));
	  indices.get(builder.toString()).add(i);
	}
	}
	for (int i0 = 0;i0 < ln;++i0) {
	for (int i1 = i0 + 1;i1 < ln;++i1) {
	for (int i2 = i1 + 1;i2 < ln;++i2) {
	  StringBuilder builder = new StringBuilder();
	  builder.append(words[i].charAt(i0));
	  builder.append(words[i].charAt(i1));
	  builder.append(words[i].charAt(i2));
	  indices.get(builder.toString()).add(i);
	}
	}
	}
	for (int i0 = 0;i0 < ln;++i0) {
	for (int i1 = i0 + 1;i1 < ln;++i1) {
	for (int i2 = i1 + 1;i2 < ln;++i2) {
	for (int i3 = i2 + 1;i3 < ln;++i3) {
	  StringBuilder builder = new StringBuilder();
	  builder.append(words[i].charAt(i0));
	  builder.append(words[i].charAt(i1));
	  builder.append(words[i].charAt(i2));
	  builder.append(words[i].charAt(i3));
	  indices.get(builder.toString()).add(i);
	}
	}
	}
	}
      }

      Graph g = new Graph(2 + n + indices.size());
      int source = g.getSize() - 2;
      int sink = g.getSize() - 1;
      int index = 0;
      String []shorts = new String[indices.size()];
      for (Map.Entry<String, Set<Integer>> entry:indices.entrySet()) {
        g.add(new FlowEdge(n + index, sink, 1));
        for (int i:entry.getValue()) {
          g.add(new FlowEdge(i, index + n, 1));
          
        }
        shorts[index++] = entry.getKey();
      }
      

      

      

      for (int i = 0;i < n;++i) {
        g.add(new FlowEdge(source, i, 1));
      }
      if (GraphAlgorithms.dinic(g, source, sink) != n) {
        

        out.println(-1);

	out.close();
        return;
      }
      for (int i = 0;i < n;++i) {
        for (Edge edge:g.getIncident(i)) {
          if (edge.getFlow()!=0) {
            

            out.println(shorts[edge.getDestination() - n]);
          }
        }
      }
      out.close();
      
      
      
    } catch (FileNotFoundException e){
      System.out.println("error");
    }
  }
}
abstract class InputReader {
	private boolean finished = false;
 
	public abstract int read();
 
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
 
	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
 
	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	public void setFinished(boolean finished) {
		this.finished = finished;
	}
 
	public abstract void close();
}
class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;
 
	public StreamInputReader(InputStream stream) {
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
 
	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}
class FastReader {
    private boolean finished = false;
 
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
 
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
        while (isSpaceChar(c))
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
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public long nextLong() {
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
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public String nextString() {
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
 
    public boolean isSpaceChar(int c) {
        if (filter != null) {
            return filter.isSpaceChar(c);
        }
        return isWhitespace(c);
    }
 
    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    private String readLine0() {
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
        String s = readLine0();
        while (s.trim().length() == 0)
            s = readLine0();
        return s;
    }
 
    public String nextLine(boolean ignoreEmptyLines) {
        if (ignoreEmptyLines) {
            return nextLine();
        } else {
            return readLine0();
        }
    }
 
    public BigInteger nextBigInteger() {
        try {
            return new BigInteger(nextString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }
 
    public char nextCharacter() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }
 
    public double nextDouble() {
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
            while (!isSpaceChar(c)) {
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
 
    public boolean isExhausted() {
        int value;
        while (isSpaceChar(value = peek()) && value != -1)
            read();
        return value == -1;
    }
 
    public String next() {
        return nextString();
    }
 
    public SpaceCharFilter getFilter() {
        return filter;
    }
 
    public void setFilter(SpaceCharFilter filter) {
        this.filter = filter;
    }
 
    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

interface Factory<V> {
	public V create();
}
 
class CPPMap<K, V> extends HashMap<K, V> {
	private final Factory<V> defaultValueFactory;
 
	public CPPMap(Factory<V> defaultValueFactory) {
		this.defaultValueFactory = defaultValueFactory;
	}
 
	public V get(Object key) {
		if (containsKey(key))
			return super.get(key);
		V value = defaultValueFactory.create();
		try {
			

			super.put((K) key, value);
			return value;
		} catch (ClassCastException e) {
			return value;
		}
	}
}
interface Edge {
	public int getSource();
	public int getDestination();
	public long getCapacity();
	public long getFlow();
	public void pushFlow(long flow);
	public Edge getReverseEdge();
}
 
class FlowEdge extends SimpleEdge {
	private long capacity;
	private long flow = 0;
	private Edge reverseEdge;
 
	public FlowEdge(int source, int destination, long capacity) {
		super(source, destination);
		this.capacity = capacity;
		reverseEdge = new ReverseEdge();
	}
 
	public long getCapacity() {
		return capacity;
	}
 
	public long getFlow() {
		return flow;
	}
 
	public void pushFlow(long flow) {
		if (flow > 0) {
			if (this.capacity < flow)
				throw new IllegalArgumentException();
		} else {
			if (this.flow < -flow)
				throw new IllegalArgumentException();
		}
		capacity -= flow;
		this.flow += flow;
	}
 
	public Edge getReverseEdge() {
		return reverseEdge;
	}
 
	private class ReverseEdge implements Edge {
		public int getSource() {
			return destination;
		}
 
		public int getDestination() {
			return source;
		}
 
		public long getCapacity() {
			return flow;
		}
 
		public long getFlow() {
			return capacity;
		}
 
		public void pushFlow(long flow) {
			FlowEdge.this.pushFlow(-flow);
		}
 
		public Edge getReverseEdge() {
			return FlowEdge.this;
		}
	}
}
 
class Graph {
  private final int size;
  private final List<Edge>[] edges;

  public Graph(int size) {
    this.size = size;
    

    edges = new List[size];
    for (int i = 0; i < size; i++)
      edges[i] = new ArrayList<Edge>();
  }

  public int getSize() {
    return size;
  }

  public List<Edge> getIncident(int vertex) {
    return edges[vertex];
  }

  public void add(Edge edge) {
    edges[edge.getSource()].add(edge);
    edge = edge.getReverseEdge();
    if (edge != null)
      edges[edge.getSource()].add(edge);
  }

}
 
class GraphAlgorithms {
  public static long dinic(Graph graph, int source, int destination) {
    long totalFlow = 0;
    int vertexCount = graph.getSize();
    int[] nextEdge = new int[vertexCount];
    while (true) {
      long[] distance = edgeDistances(graph, source).getDistances();
      if (distance[destination] == Long.MAX_VALUE)
	break;
      Arrays.fill(nextEdge, 0);
      totalFlow += dinicImpl(graph, source, destination, Long.MAX_VALUE, distance, nextEdge);
    }
    return totalFlow;
  }

  private static DistanceResult edgeDistances(Graph graph, int source) {
    int size = graph.getSize();
    Deque<Integer> queue = new ArrayDeque<Integer>(size);
    boolean[] processed = new boolean[size];
    boolean[] notReached = new boolean[size];
    Arrays.fill(notReached, true);
    long[] distance = new long[size];
    int[] last = new int[size];
    Arrays.fill(distance, Long.MAX_VALUE);
    distance[source] = 0;
    last[source] = -1;
    queue.add(source);
    notReached[source] = false;
    int iterationCount = 0;
    while (!queue.isEmpty()) {
      iterationCount++;
      if (iterationCount / size / size / size != 0)
	return null;
      int current = queue.poll();
      processed[current] = true;
      for (Edge edge : graph.getIncident(current)) {
	if (edge.getCapacity() == 0)
	  continue;
	int next = edge.getDestination();
	long weight = 1;
	if (distance[next] > distance[current] + weight) {
	  distance[next] = distance[current] + weight;
	  last[next] = current;
	  if (notReached[next]) {
	    notReached[next] = false;
	    queue.add(next);
	  } else if (processed[next]) {
	    processed[next] = false;
	    queue.addFirst(next);
	  }
	}
      }
    }
    return new DistanceResult(distance, last);
  }

  private static long dinicImpl(Graph graph, int source, int destination, long flow, long[] distance, int[] nextEdge) {
    if (source == destination)
      return flow;
    if (flow == 0 || distance[source] == distance[destination])
      return 0;
    List<Edge> incident = graph.getIncident(source);
    int incidentSize = incident.size();
    int totalPushed = 0;
    for (int i = nextEdge[source]; i < incidentSize; i++) {
      Edge edge = incident.get(i);
      int nextDestination = edge.getDestination();
      if (distance[nextDestination] != distance[source] + 1)
	continue;
      long pushed = dinicImpl(graph, nextDestination, destination, Math.min(flow, edge.getCapacity()),
	  distance, nextEdge);
      if (pushed != 0) {
	edge.pushFlow(pushed);
	flow -= pushed;
	totalPushed += pushed;
	if (flow == 0) {
	  nextEdge[source] = i;
	  return totalPushed;
	}
      }
    }
    nextEdge[source] = incidentSize;
    return totalPushed;
  }

  public static class DistanceResult {
    private final long[] distances;
    private final int[] last;

    public DistanceResult(long[] distances, int[] last) {
      this.distances = distances;
      this.last = last;
    }

    public long[] getDistances() {
      return distances;
    }

  }

}
 
class SimpleEdge implements Edge {
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

  public long getCapacity() {
    return 0;
  }

  public long getFlow() {
    return 0;
  }

  public void pushFlow(long flow) {
    throw new UnsupportedOperationException();
  }

  public Edge getReverseEdge() {
    return null;
  }

}
