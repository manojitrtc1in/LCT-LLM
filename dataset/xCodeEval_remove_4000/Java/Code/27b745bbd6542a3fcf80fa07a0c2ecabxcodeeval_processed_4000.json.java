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
    public int[][] id4;

    public void solve(int testNumber, InputUtil in, PrintWriter out) {
        n = in.nextInt();
        q = in.nextInt();

        SimpleGraph tree = new SimpleGraph(n);

        levels = 33 - Integer.numberOfLeadingZeros(n);
        parent = new int[levels][n];
        id4 = new int[levels][n];

        for (int i = 0; i < levels; i++) {
            Arrays.fill(parent[i], -1);
            Arrays.fill(id4[i], -1);
        }

        

        id14[] papers = new id14[n];
        for (int i = 0; i < n; i++) {
            papers[i] = new id14();
        }

        IntDeque[] queryIndices = IntDeque.id1(n);
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
                id4[0][x[i]] = i;
                tree.id8(x[i], y[i]);
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

        int[] order = id2.order(tree);
        int[] level = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (parent[0][u] != -1) {
                level[u] = level[parent[0][u]] + 1;
                for (int j = 1; parent[j - 1][parent[j - 1][u]] != -1; j++) {
                    parent[j][u] = parent[j - 1][parent[j - 1][u]];
                    id4[j][u] = Math.max(id4[j - 1][u], id4[j - 1][parent[j - 1][u]]);
                }
            }
        }

        for (int u : order) {
            for (int queryIndex : queryIndices[u]) {
                int paper = y[queryIndex];
                int from = first[paper];
                if (!papers[u].containsKey(paper) || papers[u].get(paper) < id5(from, level[from] - level[u])) {
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

    public int id5(int u, int dist) {
        int id3 = -1;
        for (int i = 0; dist > 0; i++, dist >>= 1) {
            if ((dist & 1) > 0) {
                id3 = Math.max(id3, id4[i][u]);
                u = parent[i][u];
            }
        }
        return id3;
    }

    public id14 merge(id14 x, id14 y) {
        if (x.size < y.size) {
            return merge(y, x);
        }
        for (IntEntry e : y) {
            x.put(e.key, e.value);
        }
        return x;
    }
}

class InputUtil {

    id10 in;

    public InputUtil(InputStream istream) {
        in = new id10(istream);
    }

    public String next() {
        return in.id11();
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

    public id12 to;
    public IntDeque edges[];
    public int vertexCount;
    public int edgeCount;

    public SimpleGraph(int vertexCount) {
        this(vertexCount, 16);
    }

    public SimpleGraph(int vertexCount, int edgeCount) {
        this.to = new id12(edgeCount);
        this.edges = new IntDeque[vertexCount];
        this.vertexCount = vertexCount;
        this.edgeCount = 0;
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = new IntDeque();
        }
    }

    public void id8(int u, int v) {
        to.add(v);
        edges[u].add(edgeCount);
        edgeCount++;
    }

    public int to(int edge) {
        return to.get(edge);
    }

}

class id14 implements Iterable<IntEntry> {

    protected static int[] deref = id15.value;


    protected id15 keys = new id15();
    protected id15 values = new id15();
    protected id15 pairs = new id15();
    protected id15[] table;

    public int limit;
    public int size;

    public id14() {
        this(16);
    }

    public id14(int capacity) {
        if (capacity < 1) {
            throw new IllegalArgumentException("Capacity for IntHashSet must be at least 1");
        }

        for (int tmp = 1; tmp < capacity; ) {
            tmp <<= 1;
            if (tmp >= capacity) {
                capacity = tmp;
                break;
            }
        }

        this.keys = new id15();
        this.table = new id15[capacity];
        this.limit = table.length;
        this.size = 0;
    }

    public boolean containsKey(int key) {
        return id13(getBucket(key), key) != -1;
    }

    protected void ensureCapacity() {
        if (size > limit) {

            id15[] newTable = new id15[table.length << 1];





            for (int bucket = 0; bucket < table.length; bucket++) {
                if (table[bucket] == null) {
                    continue;
                }
                while (table[bucket].head != -1) {
                    int pairPtr = table[bucket].poll();
                    int key = deref[deref[pairPtr]];

                    int bucketIdx = hash(key) & (newTable.length - 1);
                    if (newTable[bucketIdx] == null) {


                        newTable[bucketIdx] = new id15();
                    }
                    newTable[bucketIdx].add(pairPtr);
                }
            }

            table = newTable;
            limit <<= 1;
        }
    }

    public int get(int key) {
        int pairPtr = id13(table[hash(key) & (table.length - 1)], key);
        if (pairPtr != -1) {
            return deref[deref[pairs.next[pairPtr]]];
        }
        throw new NoSuchElementException("Key " + key + " does not exist in id14");
    }

    public id15 getBucket(int key) {
        return table[hash(key) & (table.length - 1)];
    }

    protected int id13(id15 list, int key) {
        deref = id15.value;
        if (list != null) {
            for (int listPtr = list.head; listPtr != id15.NULL; listPtr = list.next[listPtr]) {
                int pairPtr = deref[listPtr];
                if (deref[deref[pairPtr]] == key) {
                    return pairPtr;
                }
            }
        }
        return -1;
    }

    protected int hash(int key) {
        return key ^ (key >>> 20) ^ (key >>> 12) ^ (key >>> 7) ^ (key >>> 4);
    }

    public boolean put(int key, int value) {
        ensureCapacity();

        int bucket = hash(key) & (table.length - 1);
        if (table[bucket] == null) {


            table[bucket] = new id15();
        } else {
            int pairPtr = id13(table[bucket], key);
            if (pairPtr != -1) {
                values.value[deref[pairs.next[pairPtr]]] = value;
                return false;
            }
        }

        size++;
        int pairPtr = pairs.add(keys.add(key));
        pairs.add(values.add(value));
        table[bucket].add(pairPtr);

        return true;
    }

    public String toString() {
        if (keys.head == -1) {
            return "[]";
        }
        StringBuilder res = new StringBuilder("[");
        int kPtr = keys.head;
        int vPtr = values.head;
        while (kPtr != -1) {
            res.append(keys.id9(kPtr));
            res.append("->");
            res.append(values.id9(vPtr));
            res.append(' ');
            kPtr = keys.next[kPtr];
            vPtr = values.next[vPtr];
        }
        res.setLength(res.length() - 1);
        res.append(']');
        return res.toString();
    }

    public Iterator<IntEntry> iterator() {
        return new Iterator<IntEntry>() {
            int kPtr = keys.head;
            int vPtr = values.head;

            public boolean hasNext() {
                return kPtr != id15.NULL;
            }

            public IntEntry next() {
                IntEntry entry = new IntEntry(keys.id9(kPtr), values.id9(vPtr));
                kPtr = keys.next[kPtr];
                vPtr = values.next[vPtr];
                return entry;
            }
        };
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
    public static IntDeque[] id1(int length) {
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

class id2 {
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

class IntEntry {
    public int key;
    public int value;
    public IntEntry(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

class id10 {
    public static final int BUFFER_SIZE = 1 << 16;
	public static final char NULL_CHAR = (char) -1;

    BufferedInputStream in;
	StringBuilder str = new StringBuilder();
	byte[] buffer = new byte[BUFFER_SIZE];
	boolean EOF_FLAG = false;

    char c = NULL_CHAR;
	int bufferIdx = 0;
    int size = 0;

	public id10(InputStream in) {
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

	public String id11() {
		try {
			return next();
		} catch (id7 e) {
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
			throw new id7();
		}
	}

	public class id7 extends RuntimeException {
	}
}

class id12 implements Iterable<Integer> {
    int size = 0;
    int[] array;

    public id12() {
        this(16);
    }

    public id12(int length) {
        array = new int[length];
    }

    public <T extends Iterable<Integer>> id12(T intList) {
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

class id15 implements Iterable<Integer> {
    public static final int NULL = -1;
    protected int head;
    protected int tail;

    public static final int id6 = 128;
    protected static int[] value = new int[id6];
    protected static int[] prev = new int[id6];
    protected static int[] next = new int[id6];
    protected static IntDeque free = new IntDeque();

    static {
        for (int i = 0; i < id6; i++) {
            prev[i] = NULL;
            next[i] = NULL;
            free.add(i);
        }
    }

    public id15() {
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

    public int id9(int ptr) {
        return value[ptr];
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

    public int id0(int ptr) {
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
        return id0(head);
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

