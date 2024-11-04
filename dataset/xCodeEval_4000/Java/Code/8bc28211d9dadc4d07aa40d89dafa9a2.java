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
		InformationGraph solver = new InformationGraph();
		solver.solve(1, in, out);
		out.close();
	}
}

class InformationGraph {

    public int n;
    public int q;
    public int levels;

    public int[][] parent;
    public int[][] bottleneck;

    public void solve(int testNumber, InputUtil in, PrintWriter out) {
        n = in.nextInt();
        q = in.nextInt();

        SimpleGraph tree = new SimpleGraph(n);

        levels = 33 - Integer.numberOfLeadingZeros(n);
        parent = new int[levels][n];
        bottleneck = new int[levels][n];

        for (int i = 0; i < levels; i++) {
            Arrays.fill(parent[i], -1);
            Arrays.fill(bottleneck[i], -1);
        }

        

        IntHashMap[] papers = new IntHashMap[n];
        for (int i = 0; i < n; i++) {
            papers[i] = new IntHashMap();
        }

        IntDeque[] queryIndices = IntDeque.IntDeques(n);
        int[] type = new int[q];
        int[] x = new int[q];
        int[] y = new int[q];
        int[] first = new int[q + 1];

        for (int i = 0, paperIdx = 1; i < q; i++) {
            type[i] = in.nextInt();
            x[i] = in.nextInt() - 1;
            if (type[i] == 1) {
                y[i] = in.nextInt() - 1;
                parent[0][x[i]] = y[i];
                bottleneck[0][x[i]] = i;
                tree.addDirectedEdge(x[i], y[i]);
            } else if (type[i] == 2) {
                y[i] = i;
                papers[x[i]].put(paperIdx, i);
                first[paperIdx] = x[i];
                paperIdx++;
            } else {
                y[i] = in.nextInt();
                queryIndices[x[i]].add(i);
            }
        }

        int[] order = TopologicalSort.order(tree);
        int[] level = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (parent[0][u] != -1) {
                level[u] = level[parent[0][u]] + 1;
                for (int j = 1; parent[j - 1][parent[j - 1][u]] != -1; j++) {
                    parent[j][u] = parent[j - 1][parent[j - 1][u]];
                    bottleneck[j][u] = Math.max(bottleneck[j - 1][u], bottleneck[j - 1][parent[j - 1][u]]);
                }
            }
        }

        for (int u : order) {
            for (int queryIndex : queryIndices[u]) {
                int paper = y[queryIndex];
                int from = first[paper];
                if (!papers[u].containsKey(paper) || papers[u].get(paper) < getBottleNeck(from, level[from] - level[u])) {
                    y[queryIndex] = 0;
                } else {
                    y[queryIndex] = 1;
                }
            }

            int par = parent[0][u];
            if (par != -1) {
                papers[par] = merge(papers[par], papers[u]);
            }
        }

        for (int i = 0; i < q; i++) {
            if (type[i] == 3) {
                out.println(y[i] == 0 ? "NO" : "YES");
            }
        }
    }

    public int getBottleNeck(int u, int dist) {
        int maxBottleneck = -1;
        for (int i = 0; dist > 0; i++, dist >>= 1) {
            if ((dist & 1) > 0) {
                maxBottleneck = Math.max(maxBottleneck, bottleneck[i][u]);
                u = parent[i][u];
            }
        }
        return maxBottleneck;
    }

    public IntHashMap merge(IntHashMap x, IntHashMap y) {
        if (x.size < y.size) {
            return merge(y, x);
        }
        x.addAndDestroy(y);
        return x;
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

class IntHashMap {

    protected static int[] deref = IntLinkedList.value;
    protected static int[] next = IntLinkedList.next;
    protected IntLinkedList[] table;

    public int limit;
    public int size;

    public IntHashMap() {
        this(16);
    }

    public IntHashMap(int capacity) {
        if (capacity < 1) {
            throw new IllegalArgumentException("Capacity for IntHashSet must be at least 1");
        }

        capacity = 1 << (32 - Integer.numberOfLeadingZeros(capacity - 1));
        this.table = new IntLinkedList[capacity];
        this.limit = capacity << 1;
        this.size = 0;
    }

    public boolean containsKey(int key) {
        return getPairPtr(getBucket(key), key) != -1;
    }

    protected void ensureCapacity() {
        if (size > limit) {

            IntLinkedList[] newTable = new IntLinkedList[table.length << 1];

            deref = IntLinkedList.value;
            next = IntLinkedList.next;

            for (int bucket = 0; bucket < table.length; bucket++) {
                if (table[bucket] == null) {
                    continue;
                }
                while (table[bucket].head != -1) {
                    int key = table[bucket].poll();
                    int val = table[bucket].poll();

                    int bucketIdx = hash(key) & (newTable.length - 1);
                    if (newTable[bucketIdx] == null) {
                        newTable[bucketIdx] = new IntLinkedList();
                    }
                    newTable[bucketIdx].add(key);
                    newTable[bucketIdx].add(val);
                }
            }

            table = newTable;
            limit <<= 1;
        }
    }

    public int get(int key) {
        int pairPtr = getPairPtr(table[hash(key) & (table.length - 1)], key);
        if (pairPtr != -1) {
            return deref[next[pairPtr]];
        }
        throw new NoSuchElementException("Key " + key + " does not exist in IntHashMap");
    }

    public IntLinkedList getBucket(int key) {
        return table[hash(key) & (table.length - 1)];
    }

    protected int getPairPtr(IntLinkedList list, int key) {
        if (list != null) {
            deref = IntLinkedList.value;
            next = IntLinkedList.next;

            for (int pairPtr = list.head; pairPtr != IntLinkedList.NULL; pairPtr = next[next[pairPtr]]) {
                if (deref[pairPtr] == key) {
                    return pairPtr;
                }
            }
        }
        return -1;
    }

    protected int hash(int key) {
        return key ^ (key >>> 5) ^ (key >>> 16);
    }

    public boolean put(int key, int value) {
        ensureCapacity();

        int bucket = hash(key) & (table.length - 1);
        if (table[bucket] == null) {
            table[bucket] = new IntLinkedList();
        } else {
            int pairPtr = getPairPtr(table[bucket], key);
            if (pairPtr != -1) {
                deref[next[pairPtr]] = value;
                return false;
            }
        }

        size++;
        table[bucket].add(key);
        table[bucket].add(value);

        return true;
    }

    public String toString() {
        if (size == 0) {
            return "[]";
        }

        deref = IntLinkedList.value;
        next = IntLinkedList.next;

        StringBuilder res = new StringBuilder("[");
        for (int bucket = 0; bucket < table.length; bucket++) {
            if (table[bucket] == null) {
                continue;
            }
            for (int ptr = table[bucket].head; ptr != IntLinkedList.NULL; ptr = next[next[ptr]]) {
                res.append(deref[ptr]);
                res.append("->");
                res.append(deref[next[ptr]]);
                res.append(' ');
            }
        }
        res.setLength(res.length() - 1);
        res.append(']');
        return res.toString();
    }

    public void addAndDestroy(IntHashMap map) {
        deref = IntLinkedList.value;
        next = IntLinkedList.next;

        IntLinkedList list;
        for (int i = map.table.length - 1; i > -1; i--) {
            list = map.table[i];
            if (list != null) {
                while (list.head != -1) {
                    put(list.poll(), list.poll());
                }
            }
        }
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
    public static IntDeque[] IntDeques(int length) {
        IntDeque[] arr = new IntDeque[length];
        for (int i = 0; i < length; i++) {
            arr[i] = new IntDeque();
        }
        return arr;
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

class TopologicalSort {
    public static int[] order(SimpleGraph g) {
        int vertices = g.vertexCount;
        int[] order = new int[vertices];
        Arrays.fill(order, -1);
        int[] inDegree = new int[vertices];
        for (int v: g.to) {
            inDegree[v]++;
        }
        int back = 0;
        for (int i = 0; i < vertices; i++) {
            if (inDegree[i] == 0) {
                order[back++] = i;
            }
        }
        for (int i = 0; i < vertices; i++) {
            int u = order[i];
            for (int edge: g.edges[u]) {
                int v = g.to(edge);
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    order[back++] = v;
                }
            }
        }
        return order;
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

class IntLinkedList implements Iterable<Integer> {
    public static final int NULL = -1;
    protected int head;
    protected int tail;

    public static final int INITIAL_CAPACITY = 128;
    protected static int[] value = new int[INITIAL_CAPACITY];
    protected static int[] prev = new int[INITIAL_CAPACITY];
    protected static int[] next = new int[INITIAL_CAPACITY];
    protected static IntDeque free = new IntDeque();

    static {
        for (int i = 0; i < INITIAL_CAPACITY; i++) {
            prev[i] = NULL;
            next[i] = NULL;
            free.add(i);
        }
    }

    public IntLinkedList() {
        this.head = NULL;
        this.tail = NULL;
    }

    public int add(int x) {
        return addLast(x);
    }

    public int addLast(int x) {
        ensureCapacity();

        int nextSpot = free.poll();
        if (head == NULL) {
            head = tail = nextSpot;
        } else {
            next[tail] = nextSpot;
            prev[nextSpot] = tail;
            tail = nextSpot;
        }
        value[nextSpot] = x;
        return nextSpot;
    }

    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            int curr = head;
            public boolean hasNext() {
                return curr != NULL;
            }

            public Integer next() {
                int val = value[curr];
                curr = next[curr];
                return val;
            }
        };
    }

    public int removeByPtr(int ptr) {
        if (ptr < 0 || (prev[ptr] == NULL && ptr != head)) {
            throw new IndexOutOfBoundsException("Attempted to remove pointer at head of a different LL");
        }
        if (ptr == head) {
            head = next[ptr];
            if (head == NULL) {
                tail = NULL;
            } else {
                prev[head] = NULL;
            }
        } else if (ptr == tail) {
            tail = prev[tail];
            next[tail] = NULL;
        } else {
            int prevPtr = prev[ptr];
            int nextPtr = next[ptr];

            next[prevPtr] = nextPtr;
            if (nextPtr != NULL) {
                prev[nextPtr] = prevPtr;
            }
        }
        prev[ptr] = NULL;
        next[ptr] = NULL;
        free.add(ptr);

        return value[ptr];
    }

    public int removeFirst() {
        return removeByPtr(head);
    }

    public void ensureCapacity() {
        if (free.isEmpty()) {
            int size = prev.length;
            int newSize = size << 1;

            value = Arrays.copyOf(value, newSize);
            prev = Arrays.copyOf(prev, newSize);
            next = Arrays.copyOf(next, newSize);

            for (int i = size; i < newSize; i++) {
                prev[i] = NULL;
                next[i] = NULL;
                free.add(i);
            }
        }
    }

    public int poll() {
        return removeFirst();
    }

    public String toString() {
        if (head == -1) {
            return "[]";
        }
        StringBuilder res = new StringBuilder();
        res.append("[");
        for (int tmp = head; tmp != NULL; tmp = next[tmp]) {
            res.append(tmp);
            res.append(':');
            res.append(value[tmp]);
            res.append(' ');
        }
        res.setLength(res.length() - 1);
        res.append("]");
        return res.toString();
    }
}
