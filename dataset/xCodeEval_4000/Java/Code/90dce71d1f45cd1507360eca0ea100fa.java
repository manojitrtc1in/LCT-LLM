import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.io.FilterInputStream;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputUtil in = new InputUtil(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputUtil in, PrintWriter out) {
        int n = in.nextInt();
        CostGraph g = new CostGraph(n, n * n);

        boolean validGraph = true;
        int[][] mat = in.next2DIntArray(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    validGraph &= mat[i][j] == 0;
                } else if (i > j) {
                    validGraph &= mat[i][j] > 0;
                    g.addUndirectedEdge(i, j, mat[i][j]);
                } else {
                    validGraph &= mat[i][j] == mat[j][i];
                }
            }
        }

        if (validGraph) {
            CostGraph mst = Kruskals.getMST(g);

            LowestCommonAncestor lca = new LowestCommonAncestor(mst, 0);
            int[] dist = new Dijkstra(mst).dist(0);

            for (int i = 0; i < n && validGraph; i++) {
                for (int j = i + 1; j < n && validGraph; j++) {
                    validGraph &= mat[i][j] == dist[i] + dist[j] - (dist[lca.query(i, j)] << 1);
                }
            }
        }

        out.println(validGraph ? "YES" : "NO");
    }
}

class InputUtil {

    JoltyScanner in;

    public InputUtil(InputStream istream) {
        in = new JoltyScanner(istream);
    }

    public String next() {
        return in.nextOrNull();
    }

    public int nextInt() {
        String s = next();
        if (s == null) {
            throw new NoSuchElementException("Attempted to read integer that is not there.");
        }
        return Integer.parseInt(s);
    }

    public int[][] next2DIntArray(int rows, int cols) {
        int[][] arr = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = in.nextInt();
            }
        }
        return arr;
    }

}

class CostGraph extends SimpleGraph {

    public IntArrayList cost;

    public CostGraph(int vertexCount) {
        this(vertexCount, 16);
    }

    public CostGraph(int vertexCount, int edgeCount) {
        super(vertexCount, edgeCount);
        this.cost = new IntArrayList(edgeCount);
    }

    public int cost(int edge) {
        return cost.get(edge);
    }

    public IntDeque edges(int u) {
        return edges[u];
    }

    public void addUndirectedEdge(int u, int v, int edgeCost) {
        addDirectedEdge(u, v, edgeCost);
        addDirectedEdge(v, u, edgeCost);
    }

    public void addDirectedEdge(int u, int v, int edgeCost) {
        super.addDirectedEdge(u, v);
        cost.add(edgeCost);
    }

}

class Kruskals {
    public static CostGraph getMST(CostGraph g) {
        int[] from = new int[g.edgeCount];
        IntHeap q = new IntHeap(g.edgeCount);
        for (int i = 0; i < g.vertexCount; i++) {
            for (int edge: g.edges(i)) {
                from[edge] = i;
                q.set(edge, g.cost(edge));
            }
        }

        CostGraph mst = new CostGraph(g.vertexCount, g.vertexCount << 1);
        DisjointSet ds = new DisjointSet(g.vertexCount);
        while (ds.size(0) != g.vertexCount) {
            int edge = q.poll();
            int u = from[edge];
            int v = g.to(edge);
            if (ds.find(u) != ds.find(v)) {
                ds.union(u, v);
                mst.addUndirectedEdge(u, v, g.cost(edge));
            }
        }
        return mst;
    }
}

class LowestCommonAncestor {
    int n;
    int currIdx = 0;
    int currArrIdx = 0;
    public int[] idx;
    public int[] invIdx;
    public int[] arrIdx;
    public int[] level;
    public long[] arr;
    public IntDeque[] children;
    RangeMinimumQuery rmq;
    public LowestCommonAncestor(SimpleGraph g, int root) {
        n = g.vertexCount;
        children = new IntDeque[n];
        BreadthFirstSearch bfs = new BreadthFirstSearch(g, root);
        for (int i = 0; i < n; i++) {
            children[i] = new IntDeque();
        }
        for (int i = 0; i < n; i++) {
            if (i != root) {
                children[bfs.prev[i]].add(i);
            }
        }
        initArrays();
        dfs(root);
        rmq = new RangeMinimumQuery(arr);
    }
    public LowestCommonAncestor(IntDeque children[], int root) {
        this.children = children;
        n = children.length;
        initArrays();
        dfs(root);
        rmq = new RangeMinimumQuery(arr);
    }
    private void initArrays() {
        idx = new int[n];
        invIdx = new int[n];
        arrIdx = new int[n];
        level = new int[n];
        arr = new long[n << 2];
    }
    public int query(int u, int v) {
        int x = Math.min(arrIdx[u], arrIdx[v]);
        int y = Math.max(arrIdx[u], arrIdx[v]);
        return invIdx[(int) rmq.query(x, y)];
    }
    private void dfs(int root) {


















        boolean[] processed = new boolean[n];
        IntDeque stk = new IntDeque(n);
        stk.push(root);
        while (!stk.isEmpty()) {
            int u = stk.pop();
            if (!processed[u]) {
                processed[u] = true;
                idx[u] = currIdx;
                invIdx[currIdx++] = u;
                arrIdx[u] = currArrIdx;
                arr[currArrIdx++] = idx[u];
                for (Integer v: children[u]) {
                    level[v] = level[u] + 1;
                    stk.push(u);
                    stk.push(v);
                }
            }
            else {
                arr[currArrIdx++] = idx[u];
            }
        }
    }
}

class Dijkstra {
    CostGraph g;
    public Dijkstra(CostGraph g) {
        this.g = g;
    }
    public int[] dist(int src) {
        IntHeap q = new IntHeap(g.vertexCount);
        q.set(src, 0);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int edge: g.edges(u)) {
                int v = g.to(edge);
                int length = q.value[u] + g.cost(edge);
                if (q.value[v] > length) {
                    q.set(v, length);
                }
            }
        }
        return q.value;
    }
}

class JoltyScanner {
    public static final int BUFFER_SIZE = 1 << 16;
	public static final char NULL_CHAR = (char) -1;

    BufferedInputStream in;
	StringBuilder str = new StringBuilder();
	byte[] buffer = new byte[BUFFER_SIZE];
	boolean EOF_FLAG = false;

    char c = NULL_CHAR;
	int bufferIdx = 0;
    int size = 0;

	public JoltyScanner(InputStream in) {
		this.in = new BufferedInputStream(in, BUFFER_SIZE);
	}

	public int nextInt() {
		long x = nextLong();
		if (x > Integer.MAX_VALUE || x < Integer.MIN_VALUE) {
			throw new ArithmeticException("Scanned value overflows integer");
		}
		return (int) x;
	}

	public long nextLong() {
		boolean negative = false;
		if (c == NULL_CHAR) {
			c = nextChar();
		}
		for (; !EOF_FLAG && (c < '0' || c > '9'); c = nextChar()) {
			if (c == '-') {
				negative = true;
			}				
		}
		checkEOF();
		long res = 0;
		for (; c >= '0' && c <= '9'; c = nextChar()) {
			res = (res << 3) + (res << 1) + c - '0';
		}
		return negative ? -res : res;
	}

    public String next() {
		checkEOF();
		for (c = c == NULL_CHAR ? nextChar() : c; Character.isWhitespace(c); checkEOF()) {
			c = nextChar();
		}
		str.setLength(0);
		for (; !EOF_FLAG && !Character.isWhitespace(c); c = nextChar()) {
			str.append(c);
		}
		return str.toString();
	}

	public String nextOrNull() {
		try {
			return next();
		} catch (EndOfFileException e) {
			return null;
		}
	}

    public char nextChar() {
		if (EOF_FLAG) {
			return NULL_CHAR;
		}
		while (bufferIdx == size) {
			try {
				size = in.read(buffer);
				if (size == -1) {
					throw new Exception();
				}
			} catch (Exception e) {
				EOF_FLAG = true;
				return NULL_CHAR;
			}
			if (size == -1) {
				size = BUFFER_SIZE;
			}
			bufferIdx = 0;
		}
		return (char) buffer[bufferIdx++];
	}

    public void checkEOF() {
		if (EOF_FLAG) {
			throw new EndOfFileException();
		}
	}

	public class EndOfFileException extends RuntimeException {
	}
}

class SimpleGraph {

    public IntArrayList to;
    public IntDeque edges[];
    public int vertexCount;
    public int edgeCount;

    public SimpleGraph(int vertexCount) {
        this(vertexCount, 16);
    }

    public SimpleGraph(int vertexCount, int edgeCount) {
        this.to = new IntArrayList(edgeCount);
        this.edges = new IntDeque[vertexCount];
        this.vertexCount = vertexCount;
        this.edgeCount = 0;
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = new IntDeque();
        }
    }

    public void addDirectedEdge(int u, int v) {
        to.add(v);
        edges[u].add(edgeCount);
        edgeCount++;
    }

    public int to(int edge) {
        return to.get(edge);
    }

}

class IntArrayList implements Iterable<Integer> {
    int size = 0;
    int[] array;

    public IntArrayList() {
        this(16);
    }

    public IntArrayList(int length) {
        array = new int[length];
    }

    public <T extends Iterable<Integer>> IntArrayList(T intList) {
        this(16);
        addAll(intList);
    }

    public void add(int element) {
        ensureCapacity();
        array[size] = element;
        size++;
    }

    public <T extends Iterable<Integer>>void addAll(T intList) {
        for (int i: intList) {
            add(i);
        }
    }

    private void checkIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("" + index);
        }
    }

    public void ensureCapacity() {
        if (size == array.length) {
            int[] newArray = new int[size << 1];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }
    }

    public int get(int index) {
        checkIndex(index);
        return array[index];
    }

    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            int index = 0;
            public boolean hasNext() {
                return index < size;
            }
            public Integer next() {
                return array[index++];
            }
            

            public void remove() {
                if (index == 0) {
                    throw new IndexOutOfBoundsException();
                }
                index--;
                System.arraycopy(array, index + 1, array, index, size - index);
                size--;
            }
        };
    }

    public String toString() {
        if (size == 0) {
            return "";
        }
        StringBuilder res = new StringBuilder();
        for (int i: this) {
            res.append(i);
            res.append(" ");
        }
        res.setLength(res.length() - 1);
        return res.toString();
    }

}

class IntDeque implements Iterable<Integer> {

    private int capacity;
    private int size = 0;
    private int front = 0;
    private int back = 0;
    private int[] deque;
    public IntDeque() {
        this(16);
    }
    public IntDeque(int capacity) {
        this.capacity = capacity;
        deque = new int[capacity];
    }

    public <T extends Iterable<Integer>>IntDeque(T intList) {
        this(16);
        addAll(intList);
    }
    public IntDeque(int[] intArr) {
        this(16);
        for (int i: intArr) {
            addLast(i);
        }
    }
    public void add(int x) {
        addLast(x);
    }
    public <T extends Iterable<Integer>>void addAll(T intList) {
        for (int i: intList) {
            addLast(i);
        }
    }
    public void addLast(int x) {
        ensureCapacity();
        size++;
        deque[back++] = x;
        if (back == capacity) {
            back = 0;
        }
    }
    public void addFirst(int x) {
        ensureCapacity();
        size++;
        if (front == 0) {
            front = capacity;
        }
        deque[--front] = x;
    }

    public void ensureCapacity() {
        if (size < capacity) {
            return;
        }
        int[] newDeque = new int[capacity << 1];
        for (int i = 0, j = front; i < size; i++, j++) {
            if (j == capacity) {
                j = 0;
            }
            newDeque[i] = deque[j];
        }
        deque = newDeque;
        capacity <<= 1;
        front = 0;
        back = size;
    }

    public boolean isEmpty() {
        return size == 0;
    }
    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            int done = 0;
            int curr = front;
            public boolean hasNext() {
                return done < size;
            }
            public Integer next() {
                Integer res = deque[curr++];
                if (curr == capacity) {
                    curr = 0;
                }
                done++;
                return res;
            }
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    }

    public int poll() {
        return pollFirst();
    }
    public int pollFirst() {
        if (size == 0) {
            throw new RuntimeException("IntDeque is empty!");
        }
        size--;
        int res = deque[front++];
        if (front == capacity) {
            front = 0;
        }
        return res;
    }

    public int pop() {
        return pollFirst();
    }
    public void push(int x) {
        addFirst(x);
    }

    public String toString() {
        if (size == 0) {
            return "";
        }
        StringBuilder res = new StringBuilder();
        for (int i: this) {
            res.append(i);
            res.append(" ");
        }
        res.setLength(res.length() - 1);
        return res.toString();
    }
}

class IntHeap {
    int size;
    int[] heap;
    int[] location;
    public int[] value;
    public static final int INF = (int) (1e9);

    public IntHeap(int N) {
        size = 0;
        heap = new int[N];
        location = new int[N];
        value = new int[N];

        Arrays.fill(value, INF);
        Arrays.fill(location, -1);
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void set(int n, int v) {
        if (location[n] == -1) {
            location[n] = size;
            heap[size] = n;
            size++;
        }
        value[n] = v;
        percolateDown(location[n]);
        percolateUp(location[n]);
    }

    public int poll() {
        if (size == 0) return -1;

        int res = heap[0];
        --size;
        location[heap[size]] = 0;
        heap[0] = heap[size];
        percolateDown(0);

        location[res] = -1;
        return res;
    }

    private void percolateUp(int idx) {
        int par = (idx - 1) >> 1;
        while (idx != 0 && value[heap[idx]] < value[heap[par]]) {
            location[heap[idx]] = par;
            location[heap[par]] = idx;

            int temp = heap[idx];
            heap[idx] = heap[par];
            heap[par] = temp;

            idx = par;
            par = (par - 1) >> 1;
        }
    }

    private void percolateDown(int idx) {
        int idx2, temp;
        long min;

        while (true) {
            min = Long.MAX_VALUE;
            idx2 = -1;
            temp = (idx << 1) + 1;
            if (temp >= size) break;
            for (int i = 0; i < 2 && temp < size; i++) {
                if (value[heap[temp]] < min) {
                    min = value[heap[temp]];
                    idx2 = temp;
                }
                temp++;
            }
            if (value[heap[idx]] <= min) break;

            location[heap[idx]] = idx2;
            location[heap[idx2]] = idx;

            temp = heap[idx];
            heap[idx] = heap[idx2];
            heap[idx2] = temp;

            idx = idx2;
        }
    }

}

class DisjointSet {
    public int[] par;
    public int[] rank;
    public int[] size;
    public int sets;

    public DisjointSet(int n) {
        sets = n;
        par = new int[n];
        rank = new int[n];
        size = new int[n];
        Arrays.fill(size, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    public void union(int u, int v) {
        if (find(u) == find(v)) return;
        sets --;
        if (rank[find(u)] < rank[find(v)]) {
            int t = u;
            u = v;
            v = t;
        }
        size[find(u)] += size[find(v)];
        size[find(v)] = 0;
        par[find(v)] = find(u);
        rank[find(u)] = Math.max(rank[find(u)], rank[find(v)] + 1);
    }

    public int size(int u) {
        return size[find(u)];
    }

    public int find(int u) {
        if (par[u] == u) {
            return u;
        }
        else {
            par[u] = find(par[u]);
            return par[u];
        }
    }
}

class RangeMinimumQuery {

    int n;
    private long[][] memo;

    public RangeMinimumQuery(long[] arr) {
        n = arr.length;
        int d = 32 - Integer.numberOfLeadingZeros(n - 1);
        memo = new long[n][d];

        for (int i = 0; i < n; i++) {
            memo[i][0] = arr[i];
        }
        for (int j = 1; j < d; j++) {
            for (int k = 0; k < n - (1 << j); k++) {
                memo[k][j] = Math.min(memo[k][j - 1], memo[k + (1 << (j - 1))][j - 1]);
            }
        }
    }

    public long query(int a, int b) {
        if (b < a || a < 0 || b >= n) {
            throw new IndexOutOfBoundsException();
        }

        long res = Long.MAX_VALUE;

        int d = b - a + 1;
        int idx = 0, bit = 1;
        while (d > 0) {
            if ((d & bit) > 0) {
                res = Math.min(res, memo[a][idx]);
                a += bit;
                d ^= bit;
            }

            idx++;
            bit <<= 1;
        }

        return res;
    }
}

class BreadthFirstSearch {

    public int[] dist;
    public int[] prev;
    public final static int INFINITY = Integer.MAX_VALUE;

    public BreadthFirstSearch(SimpleGraph g, int src) {
        dist = new int[g.vertexCount];
        prev = new int[g.vertexCount];
        Arrays.fill(dist, INFINITY);
        Arrays.fill(prev, -1);
        IntDeque q = new IntDeque();

        dist[src] = 0;
        q.add(src);

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int edge: g.edges[u]) {
                int v = g.to(edge);
                if (dist[v] > dist[u] + 1) {
                    prev[v] = u;
                    dist[v] = dist[u] + 1;
                    q.add(v);
                }
            }
        }
    }

    public BreadthFirstSearch(FlowGraph g, int src) {
        dist = new int[g.vertexCount];
        prev = new int[g.vertexCount];
        Arrays.fill(dist, INFINITY);
        Arrays.fill(prev, -1);
        IntDeque q = new IntDeque();

        dist[src] = 0;
        q.add(src);

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int edge: g.edges[u]) {
                int v = g.to(edge);
                if (g.flow(edge) > 0 && dist[v] > dist[u] + 1) {
                    prev[v] = u;
                    dist[v] = dist[u] + 1;
                    q.add(v);
                }
            }
        }
    }
}

class FlowGraph extends CostGraph {

    public IntArrayList flow;
    public IntArrayList reverse;

    public FlowGraph(int vertexCount) {
        this(vertexCount, 16);
    }

    public FlowGraph(int vertexCount, int edgeCount) {
        super(vertexCount, edgeCount);
        this.flow = new IntArrayList(edgeCount);
        this.reverse = new IntArrayList(edgeCount);
    }

    public int flow(int edge) {
        return flow.get(edge);
    }

}

