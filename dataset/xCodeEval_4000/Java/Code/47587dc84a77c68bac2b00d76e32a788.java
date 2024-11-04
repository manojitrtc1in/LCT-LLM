import java.util.PriorityQueue;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractCollection;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.io.FilterInputStream;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.TreeSet;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputUtil in = new InputUtil(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		DeletionOfRepeats solver = new DeletionOfRepeats();
		solver.solve(1, in, out);
		out.close();
	}
}

class DeletionOfRepeats {
    public void solve(int testNumber, InputUtil in, PrintWriter out) {
        int length = in.nextInt();
        int[] originalArray = in.nextIntArray(length);

        IntegerCompressor ic = new IntegerCompressor(originalArray);
        IntArrayUtil.increment(ic.compressedArray);
        int[] arr = Arrays.copyOf(ic.compressedArray, originalArray.length + 3);
        int distinct = ic.map.size;
        int cnt[] = new int[distinct];
        int idx[][] = new int[distinct][10];
        LinearSuffixArray sa = new LinearSuffixArray(arr, length, distinct);
        PriorityQueue<Repeat> repeats = new PriorityQueue<>();
        IntArrayUtil.decrement(arr);
        for (int i = 0; i < length; i++) {
            int curr = arr[i];
            int currIdx = cnt[curr];
            for (int j = 0; j < currIdx; j++) {
                int k = idx[curr][j];
                if (sa.lcp(k, i) >= i - k) {
                    repeats.add(new Repeat(k, i - k));
                }
            }
            idx[curr][currIdx] = i;
            cnt[curr]++;
        }
        int left = 0;
        while (!repeats.isEmpty()) {
            Repeat r = repeats.poll();
            if (r.idx >= left) {
                left = r.idx + r.w;
            }
        }
        out.println(length - left);
        for (int i = left; i < length; i++) {
            out.print(originalArray[i]);
            out.print(" ");
        }
    }
    public class Repeat implements Comparable<Repeat> {
        int idx;
        int w;
        public Repeat(int idx, int w) {
            this.idx = idx;
            this.w = w;
        }
        public int compareTo(Repeat o) {
            if (w != o.w) {
                return w - o.w;
            }
            return idx - o.idx;
        }
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

    public int[] nextIntArray (int size) {
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = in.nextInt();
        }
        return arr;
    }

}

class IntegerCompressor {
    public IntHashMap map;
    public IntHashMap rev;
    public int[] compressedArray;

    public IntegerCompressor(int[] arr) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int i: arr) {
            set.add(i);
        }

        map = new IntHashMap(set.size());
        rev = new IntHashMap(set.size());
        for (int i: set) {
            rev.put(map.size, i);
            map.put(i, map.size);
        }

        int n = arr.length;
        compressedArray = new int[n];
        for (int i = 0; i < n; i++) {
            compressedArray[i] = map.get(arr[i]);
        }
    }

}

class IntArrayUtil {

    public static void decrement(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i]--;
        }
    }

    public static void increment(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i]++;
        }
    }

}

class LinearSuffixArray {
    public RangeMinimumQuery rmq;
    public int[] str;
    public int[] idx;
    public int[] inv;
    public int[] lcp;

    public int length;
    public int letters;

    public LinearSuffixArray(String str, int letters) {
        

        this(toIntArray(str), str.length(), letters + 1);
    }
    public static int[] toIntArray(String str) {
        int[] arr = new int[str.length() + 3];
        for (int i = 0; i < str.length(); i++) {
            arr[i] = str.charAt(i) - 'a' + 1;
        }
        return arr;
    }

    public LinearSuffixArray(int[] str, int length, int letters) {
        this.length = length;
        this.letters = letters;
        this.str = str;
        this.idx = new int[length];

        if (length > 1) {
            build(str, idx, length, letters);
        }

        this.inv = new int[length];
        for (int i = 0; i < length; i++) {
            inv[idx[i]] = i;
        }

        this.lcp = getLCP();
        this.rmq = new RangeMinimumQuery(this.lcp);
    }

    public void build(int[] str, int[] sa, int n, int letters) {
        int n0 = (n + 2) / 3, n2 = n / 3, n02 = n0 + n2, delta = n0 - (n + 1) / 3;

        int[] sa12 = new int[n02 + 3];
        int[] s12 = new int[n02 + 3];

        int[] sa0 = new int[n0];
        int[] s0 = new int[n0];

        

        for (int i = 0, j = 0; i < n + delta; i++) {
            if (i % 3 > 0) {
                s12[j++] = i;
            }
        }

        radixPass(s12, sa12, str, 2, n02, letters);
        radixPass(sa12, s12, str, 1, n02, letters);
        radixPass(s12, sa12, str, 0, n02, letters);

        

        int name = 0, c0 = -1, c1 = -1, c2 = -1;
        for (int i = 0; i < n02; i++) {
            if (str[sa12[i]] != c0 || str[sa12[i] + 1] != c1 || str[sa12[i] + 2] != c2) {
                name++;
                c0 = str[sa12[i]];
                c1 = str[sa12[i] + 1];
                c2 = str[sa12[i] + 2];
            }
            if (sa12[i] % 3 == 1) {
                s12[sa12[i] / 3] = name;
            } else {
                s12[sa12[i] / 3 + n0] = name;
            }
        }

        

        if (name < n02) {
            build(s12, sa12, n02, name);
            for (int i = 0; i < n02; i++) {
                s12[sa12[i]] = i + 1;
            }
        } else {
            for (int i = 0; i < n02; i++) {
                sa12[s12[i] - 1] = i;
            }
        }

        

        for (int i = 0, j = 0; i < n02; i++) {
            if (sa12[i] < n0) {
                s0[j++] = 3 * sa12[i];
            }
        }
        radixPass(s0, sa0, str, 0, n0, letters);

        

        for (int p = 0, t = delta, k = 0; k < n; k++) {
            int i = sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2;
            int j = sa0[p];
            if (sa12[t] < n0 ?
                    leq(str[i], s12[sa12[t] + n0], str[j], s12[j / 3]) :
                    leq(str[i], str[i + 1], s12[sa12[t] - n0 + 1],
                            str[j], str[j + 1], s12[j / 3 + n0])) {
                sa[k] = i;
                if (++t == n02) {
                    for (k++; p < n0; p++, k++) {
                        sa[k] = sa0[p];
                    }
                }
            } else {
                sa[k] = j;
                if (++p == n0) {
                    for (k++; t < n02; t++, k++) {
                        sa[k] = sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2;
                    }
                }
            }
        }
    }

    public boolean leq(int a1, int a2, int b1, int b2) {
        return (a1 < b1 || (a1 == b1 && a2 < b2));
    }
    public boolean leq(int a1, int a2, int a3, int b1, int b2, int b3) {
        return (a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3)));
    }

    public void radixPass(int[] a, int[] b, int[] ref, int offset, int n, int letters) {
        int[] cnt = new int[letters + 1];
        for (int i = 0; i < n; i++) {
            cnt[ref[a[i] + offset]]++;
        }
        for (int i = 0, sum = 0; i <= letters; i++) {
            int t = cnt[i];
            cnt[i] = sum;
            sum += t;
        }
        for (int i = 0; i < n; i++) {
            b[cnt[ref[a[i] + offset]]++] = a[i];
        }
    }

    public int[] getLCP() {
        int[] lcp = new int[length - 1];
        int curr = 0;
        for (int i = 0; i < length; i++) {
            int k = inv[i];
            if (k < length - 1) {
                int j = idx[k + 1];
                while (i + curr < length && j + curr < length &&
                        str[i + curr] == str[j + curr]) {
                    curr++;
                }
                lcp[k] = curr;
            }
            if (curr > 0) {
                curr--;
            }
        }
        return lcp;
    }

    public int lcp(int aIdx, int bIdx) {
        if (aIdx == bIdx) {
            return length - aIdx;
        }
        int x = inv[aIdx];
        int y = inv[bIdx];
        return rmq.query(Math.min(x, y), Math.max(x, y) - 1);
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

class IntHashMap {

    public static final int NULL = -1;
    public static final int INITIAL_CAPACITY = 128;
    protected static int[] heap = new int[INITIAL_CAPACITY << 1];
    protected static int[] prev = new int[INITIAL_CAPACITY];
    protected static int[] next = new int[INITIAL_CAPACITY];
    protected static IntDeque free = new IntDeque();

    protected int[] table;
    protected static boolean initialized = false;

    public int limit;
    public int size;

    public IntHashMap() {
        this(16);
    }

    public IntHashMap(int capacity) {
        if (!initialized) {
            for (int i = 0; i < INITIAL_CAPACITY; i++) {
                prev[i] = NULL;
                next[i] = NULL;
                free.add(i);
            }
            initialized = true;
        }

        if (capacity < 1) {
            throw new IllegalArgumentException("Capacity for IntHashSet must be at least 1");
        }

        capacity = 1 << (32 - Integer.numberOfLeadingZeros(capacity - 1));
        this.table = new int[capacity];
        Arrays.fill(table, NULL);
        this.limit = capacity << 1;
        this.size = 0;
    }

    protected void ensureCapacity() {
        if (size > limit) {

            int[] newTable = new int[table.length << 1];
            Arrays.fill(newTable, NULL);

            for (int bucket = 0; bucket < table.length; bucket++) {
                while (table[bucket] != NULL) {
                    int k = heap[(table[bucket] << 1)];
                    int v = heap[(table[bucket] << 1) + 1];

                    poll(bucket);
                    add(newTable, (hash(k) & (newTable.length - 1)), k, v);
                }
            }

            table = newTable;
            limit <<= 1;
        }
    }

    public int get(int k) {
        int pairPtr = getPairPtr(getBucket(k), k);
        if (pairPtr != -1) {
            return heap[(pairPtr << 1) + 1];
        }
        throw new NoSuchElementException("Key " + heap + " does not exist in IntHashMap");
    }

    public int getBucket(int key) {
        return hash(key) & (table.length - 1);
    }

    protected int getPairPtr(int list, int k) {
        for (int pairPtr = table[list]; pairPtr != NULL; pairPtr = next[pairPtr]) {
            if (heap[pairPtr << 1] == k) {
                return pairPtr;
            }
        }
        return -1;
    }

    protected int hash(int key) {
        return key ^ (key >>> 5) ^ (key >>> 16);
    }

    public boolean put(int k, int v) {
        ensureCapacity();

        int bucket = getBucket(k);
        int pairPtr = getPairPtr(bucket, k);
        if (pairPtr != -1) {
            heap[(pairPtr << 1) + 1] = v;
            return false;
        }

        size++;
        add(table, bucket, k, v);

        return true;
    }

    public String toString() {
        if (size == 0) {
            return "[]";
        }

        StringBuilder res = new StringBuilder("[");
        for (int bucket = 0; bucket < table.length; bucket++) {
            for (int ptr = table[bucket]; ptr != NULL; ptr = next[ptr]) {
                res.append(bucket + ":");
                res.append(heap[ptr << 1]);
                res.append("->");
                res.append(heap[(ptr << 1) + 1]);
                res.append(' ');
            }
        }
        res.setLength(res.length() - 1);
        res.append(']');
        return res.toString();
    }


    public int add(int[] table, int b, int k, int v) {
        ensureHeapCapacity();

        int nextSpot = free.poll();
        if (table[b] != NULL) {
            next[nextSpot] = table[b];
            prev[table[b]] = nextSpot;
        }
        table[b] = nextSpot;
        heap[nextSpot << 1] = k;
        heap[(nextSpot << 1) + 1] = v;
        return nextSpot;
    }

    public void removeByPtr(int b, int ptr) {
        if (ptr == table[b]) {
            table[b] = next[ptr];
            if (table[b] != NULL) {
                prev[table[b]] = NULL;
            }
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
    }

    public void ensureHeapCapacity() {
        if (free.isEmpty()) {
            int size = prev.length;
            int newSize = size << 1;

            heap = Arrays.copyOf(heap, newSize << 1);
            prev = Arrays.copyOf(prev, newSize);
            next = Arrays.copyOf(next, newSize);

            for (int i = size; i < newSize; i++) {
                prev[i] = NULL;
                next[i] = NULL;
                free.add(i);
            }
        }
    }

    public void poll(int b) {
        removeByPtr(b, table[b]);
    }

}

class RangeMinimumQuery {

    int n;
    private int[][] memo;
    private int[] log;

    public RangeMinimumQuery(int[] arr) {
        n = arr.length;

        log = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            log[i] = log[i >> 1] + 1;
        }

        int d = log[n] + 1;
        memo = new int[n][d];

        for (int i = 0; i < n; i++) {
            memo[i][0] = arr[i];
        }
        for (int j = 1; j < d; j++) {
            for (int k = 0; k < n - (1 << j); k++) {
                memo[k][j] = Math.min(memo[k][j - 1], memo[k + (1 << (j - 1))][j - 1]);
            }
        }
    }

    public int query(int a, int b) {
        if (b < a || a < 0 || b >= n) {
            throw new IndexOutOfBoundsException("Query is out of bounds or makes no sense");
        }
        if (a == b) {
            return memo[a][0];
        }

        int l = log[b - a + 1];
        return Math.min(memo[a][l], memo[b - (1 << l) + 1][l]);
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

