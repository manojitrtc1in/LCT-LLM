import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
}

class Task {

    int[] arr, c;
    Map<IntPair, Integer> map;
    
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n=in.readInt();
        arr=IOUtils.readIntArray(in, n);
        c=IOUtils.readIntArray(in, n);
        map=new TreeMap<IntPair, Integer>();
        out.printLine(dp(0, 0));
    }
    
    int dp(int gcd, int pos) {
        IntPair pair=new IntPair(gcd, pos);
        if (map.containsKey(pair)) return map.get(pair);
        int ret;
        if (pos==arr.length) {
            ret=gcd==1?0:-1;
            map.put(pair, ret);
            return ret;
        }
        int ngcd=gcd(gcd, arr[pos]);
        if (dp(ngcd, pos+1)==-1) ret=dp(gcd, pos+1);
        else if (dp(gcd, pos+1)==-1) ret=dp(ngcd, pos+1)+c[pos];
        else ret=MiscUtils.min(dp(ngcd, pos+1)+c[pos], dp(gcd, pos+1));
        map.put(pair, ret);
        return ret;
    }
    
    int gcd(int a, int b) {
        return b==0?a:gcd(b, a%b);
    }
}


class InputReader {
    private boolean finished = false;

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

    public int peek() {
        if (numChars == -1)
            return -1;
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar];
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

    public long readLong() {
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
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String readLine0() {
        StringBuilder buf = new StringBuilder();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r')
                buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = readLine0();
        while (s.trim().length() == 0)
            s = readLine0();
        return s;
    }

    public String readLine(boolean ignoreEmptyLines) {
        if (ignoreEmptyLines)
            return readLine();
        else
            return readLine0();
    }

    public BigInteger readBigInteger() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char readCharacter() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
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
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, readInt());
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
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
        return readString();
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

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
                outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(char[] array) {
        writer.print(array);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void print(long[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(int[] array) {
        print(array);
        writer.println();
    }

    public void printLine(long[] array) {
        print(array);
        writer.println();
    }

    public void printLine() {
        writer.println();
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void print(char i) {
        writer.print(i);
    }

    public void printLine(char i) {
        writer.println(i);
    }

    public void printLine(char[] array) {
        writer.println(array);
    }

    public void printFormat(String format, Object... objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

    public void print(long i) {
        writer.print(i);
    }

    public void printLine(long i) {
        writer.println(i);
    }

    public void print(int i) {
        writer.print(i);
    }

    public void printLine(int i) {
        writer.println(i);
    }
}

class IOUtils {

    public static int[] readIntArray(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    public static long[] readLongArray(InputReader in, int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readLong();
        return array;
    }

    public static double[] readDoubleArray(InputReader in, int size) {
        double[] array = new double[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readDouble();
        return array;
    }

    public static String[] readStringArray(InputReader in, int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readString();
        return array;
    }

    public static char[] readCharArray(InputReader in, int size) {
        char[] array = new char[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readCharacter();
        return array;
    }

    public static void readIntArrays(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

    public static void readLongArrays(InputReader in, long[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readLong();
        }
    }

    public static void readDoubleArrays(InputReader in, double[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readDouble();
        }
    }

    public static char[][] readTable(InputReader in, int rowCount,
            int columnCount) {
        char[][] table = new char[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = readCharArray(in, columnCount);
        return table;
    }

    public static int[][] readIntTable(InputReader in, int rowCount,
            int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = readIntArray(in, columnCount);
        return table;
    }

    public static double[][] readDoubleTable(InputReader in, int rowCount,
            int columnCount) {
        double[][] table = new double[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = readDoubleArray(in, columnCount);
        return table;
    }

    public static long[][] readLongTable(InputReader in, int rowCount,
            int columnCount) {
        long[][] table = new long[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = readLongArray(in, columnCount);
        return table;
    }

    public static String[][] readStringTable(InputReader in, int rowCount,
            int columnCount) {
        String[][] table = new String[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = readStringArray(in, columnCount);
        return table;
    }

    public static String readText(InputReader in) {
        StringBuilder result = new StringBuilder();
        while (true) {
            int character = in.read();
            if (character == '\r')
                continue;
            if (character == -1)
                break;
            result.append((char) character);
        }
        return result.toString();
    }

    public static void readStringArrays(InputReader in, String[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readString();
        }
    }

    public static void printTable(OutputWriter out, char[][] table) {
        for (char[] row : table)
            out.printLine(new String(row));
    }
}

class SumIntervalTree extends LongIntervalTree {
    public SumIntervalTree(int size) {
        super(size);
    }

    @Override
    protected long joinValue(long left, long right) {
        return left + right;
    }

    @Override
    protected long joinDelta(long was, long delta) {
        return was + delta;
    }

    @Override
    protected long accumulate(long value, long delta, int length) {
        return value + delta * length;
    }

    @Override
    protected long neutralValue() {
        return 0;
    }

    @Override
    protected long neutralDelta() {
        return 0;
    }
}

abstract class IntervalTree {
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

    protected abstract void updatePostProcess(int root, int left, int right,
            int from, int to, long delta, int middle);

    protected abstract void updatePreProcess(int root, int left, int right,
            int from, int to, long delta, int middle);

    protected abstract void updateFull(int root, int left, int right, int from,
            int to, long delta);

    protected abstract long queryPostProcess(int root, int left, int right,
            int from, int to, int middle, long leftResult, long rightResult);

    protected abstract void queryPreProcess(int root, int left, int right,
            int from, int to, int middle);

    protected abstract long queryFull(int root, int left, int right, int from,
            int to);

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

    public void update(int from, int to, long delta) {
        update(0, 0, size - 1, from, to, delta);
    }

    protected void update(int root, int left, int right, int from, int to,
            long delta) {
        if (left > to || right < from)
            return;
        if (left >= from && right <= to) {
            updateFull(root, left, right, from, to, delta);
            return;
        }
        int middle = (left + right) >> 1;
        updatePreProcess(root, left, right, from, to, delta, middle);
        update(2 * root + 1, left, middle, from, to, delta);
        update(2 * root + 2, middle + 1, right, from, to, delta);
        updatePostProcess(root, left, right, from, to, delta, middle);
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
        return queryPostProcess(root, left, right, from, to, middle,
                leftResult, rightResult);
    }
}

class TreapSet<K> implements NavigableSet<K> {
    protected static final Random rnd = new Random(239);

    protected final Node nullNode;
    protected final Comparator<? super K> comparator;
    protected Node root;
    private final K from;
    private final K to;
    private final boolean fromInclusive;
    private final boolean toInclusive;

    public TreapSet() {
        this((Comparator<? super K>) null);
    }

    public TreapSet(Comparator<? super K> comparator) {
        this(null, null, false, false, comparator, null, null);
    }

    public TreapSet(Iterable<? extends K> collection) {
        this(collection, null);
    }

    public TreapSet(Iterable<? extends K> collection,
            Comparator<? super K> comparator) {
        this(comparator);
        addAll(collection);
    }

    protected TreapSet(K from, K to, boolean fromInclusive,
            boolean toInclusive, Comparator<? super K> comparator, Node root,
            Node nullNode) {
        this.comparator = comparator;
        this.from = from;
        this.to = to;
        this.fromInclusive = fromInclusive;
        this.toInclusive = toInclusive;
        if (nullNode == null)
            nullNode = new NullNode();
        if (root == null)
            root = nullNode;
        this.root = root;
        this.nullNode = nullNode;
    }

    public boolean addAll(Iterable<? extends K> collection) {
        boolean result = false;
        for (K element : collection)
            result |= add(element);
        return result;
    }

    public K lower(K k) {
        Node target = root.lower(k);
        if (target == nullNode)
            return null;
        if (belongs(target.key))
            return target.key;
        return null;
    }

    private boolean belongs(K key) {
        int valueFrom = compare(from, key);
        int valueTo = compare(key, to);
        return (valueFrom < 0 || valueFrom == 0 && fromInclusive)
                && (valueTo < 0 || valueTo == 0 && toInclusive);
    }

    public K floor(K k) {
        Node target = root.floor(k);
        if (target == nullNode)
            return null;
        if (belongs(target.key))
            return target.key;
        return null;
    }

    public K ceiling(K k) {
        Node target = root.ceil(k);
        if (target == nullNode)
            return null;
        if (belongs(target.key))
            return target.key;
        return null;
    }

    public K higher(K k) {
        Node target = root.higher(k);
        if (target == nullNode)
            return null;
        if (belongs(target.key))
            return target.key;
        return null;
    }

    public K pollFirst() {
        K first = first();
        if (first == null)
            throw new NoSuchElementException();
        root.erase(first);
        return first;
    }

    public K pollLast() {
        K last = last();
        if (last == null)
            throw new NoSuchElementException();
        root.erase(last);
        return last;
    }

    public int size() {
        if (from == null && to == null)
            return root.size;
        if (from == null) {
            Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
            if (to == nullNode)
                return 0;
            return root.indexOf(to) + 1;
        }
        if (to == null) {
            Node from = fromInclusive ? root.ceil(this.from) : root
                    .higher(this.from);
            if (from == nullNode)
                return 0;
            return root.size - root.indexOf(from);
        }
        Node from = fromInclusive ? root.ceil(this.from) : root
                .higher(this.from);
        if (from == nullNode || !belongs(from.key))
            return 0;
        Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
        return root.indexOf(to) - root.indexOf(from) + 1;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    @SuppressWarnings({ "unchecked" })
    public boolean contains(Object o) {
        return belongs((K) o) && root.search((K) o) != nullNode;
    }

    public Iterator<K> iterator() {
        return new Iterator<K>() {
            private K current = first();

            public boolean hasNext() {
                return current != null;
            }

            public K next() {
                K result = current;
                current = higher(current);
                return result;
            }

            public void remove() {
                TreapSet.this.remove(current);
            }
        };
    }

    public Object[] toArray() {
        Object[] array = new Object[size()];
        int index = 0;
        for (K key : this)
            array[index++] = key;
        return array;
    }

    @SuppressWarnings({ "unchecked" })
    public <T> T[] toArray(T[] a) {
        if (a.length < size())
            throw new IllegalArgumentException();
        int index = 0;
        for (K key : this)
            a[index++] = (T) key;
        return a;
    }

    public boolean add(K k) {
        if (k == null)
            throw new NullPointerException();
        if (contains(k))
            return false;
        root = root.insert(createNode(k));
        return true;
    }

    protected Node createNode(K k) {
        return new Node(k, rnd.nextLong());
    }

    public boolean remove(Object o) {
        if (!contains(o))
            return false;
        

        root = root.erase((K) o);
        return true;
    }

    public boolean containsAll(Collection<?> c) {
        for (Object o : c) {
            if (!contains(o))
                return false;
        }
        return true;
    }

    public boolean addAll(Collection<? extends K> c) {
        return addAll((Iterable<? extends K>) c);
    }

    public boolean retainAll(Collection<?> c) {
        List<K> toRemove = new ArrayList<K>();
        for (K key : this) {
            if (!c.contains(key))
                toRemove.add(key);
        }
        return removeAll(toRemove);
    }

    public boolean removeAll(Collection<?> c) {
        boolean result = false;
        for (Object o : c)
            result |= remove(o);
        return result;
    }

    public void clear() {
        retainAll(Collections.<Object> emptySet());
    }

    public NavigableSet<K> descendingSet() {
        throw new UnsupportedOperationException();
    }

    public Iterator<K> descendingIterator() {
        return new Iterator<K>() {
            private K current = last();

            public boolean hasNext() {
                return current != null;
            }

            public K next() {
                K result = current;
                current = lower(current);
                return result;
            }

            public void remove() {
                TreapSet.this.remove(current);
            }
        };
    }

    public NavigableSet<K> subSet(K fromElement, boolean fromInclusive,
            K toElement, boolean toInclusive) {
        return new TreapSet<K>(fromElement, toElement, fromInclusive,
                toInclusive, comparator, root, nullNode);
    }

    public NavigableSet<K> headSet(K toElement, boolean inclusive) {
        return subSet(null, false, toElement, inclusive);
    }

    public NavigableSet<K> tailSet(K fromElement, boolean inclusive) {
        return subSet(fromElement, inclusive, null, false);
    }

    public Comparator<? super K> comparator() {
        return comparator;
    }

    public SortedSet<K> subSet(K fromElement, K toElement) {
        return subSet(fromElement, true, toElement, false);
    }

    public SortedSet<K> headSet(K toElement) {
        return subSet(null, false, toElement, false);
    }

    public SortedSet<K> tailSet(K fromElement) {
        return tailSet(fromElement, true);
    }

    public K first() {
        if (isEmpty())
            return null;
        if (from == null)
            return root.first().key;
        if (fromInclusive)
            return ceiling(from);
        return higher(from);
    }

    public K last() {
        if (isEmpty())
            return null;
        if (to == null)
            return root.last().key;
        if (toInclusive)
            return floor(to);
        return lower(to);
    }

    public K get(int index) {
        if (index >= size() || index < 0)
            throw new IndexOutOfBoundsException(Integer.toString(index));
        if (from != null)
            index += headSet(from, !fromInclusive).size();
        return root.get(index);
    }

    protected int compare(K first, K second) {
        if (first == null || second == null)
            return -1;
        if (comparator != null)
            return comparator.compare(first, second);
        

        return ((Comparable<? super K>) first).compareTo(second);
    }

    protected class Node {
        protected final K key;
        protected final long priority;
        protected Node left;
        protected Node right;
        protected int size;

        protected Node(K key, long priority) {
            this.key = key;
            this.priority = priority;
            left = nullNode;
            right = nullNode;
            size = 1;
        }

        @SuppressWarnings({ "unchecked" })
        protected Object[] split(K key) {
            if (compare(key, this.key) < 0) {
                Object[] result = left.split(key);
                left = (Node) result[1];
                result[1] = this;
                updateSize();
                return result;
            }
            Object[] result = right.split(key);
            right = (Node) result[0];
            result[0] = this;
            updateSize();
            return result;
        }

        protected void updateSize() {
            size = left.size + right.size + 1;
        }

        @SuppressWarnings({ "unchecked" })
        protected Node insert(Node node) {
            if (node.priority > priority) {
                Object[] result = split(node.key);
                node.left = (Node) result[0];
                node.right = (Node) result[1];
                node.updateSize();
                return node;
            }
            if (compare(node.key, this.key) < 0) {
                left = left.insert(node);
                updateSize();
                return this;
            }
            right = right.insert(node);
            updateSize();
            return this;
        }

        protected Node merge(Node left, Node right) {
            if (left == nullNode)
                return right;
            if (right == nullNode)
                return left;
            if (left.priority > right.priority) {
                left.right = left.right.merge(left.right, right);
                left.updateSize();
                return left;
            }
            right.left = right.left.merge(left, right.left);
            right.updateSize();
            return right;
        }

        protected Node erase(K key) {
            int value = compare(key, this.key);
            if (value == 0)
                return merge(left, right);
            if (value < 0) {
                left = left.erase(key);
                updateSize();
                return this;
            }
            right = right.erase(key);
            updateSize();
            return this;
        }

        protected Node lower(K key) {
            if (compare(key, this.key) <= 0)
                return left.lower(key);
            Node result = right.lower(key);
            if (result == nullNode)
                return this;
            return result;
        }

        protected Node floor(K key) {
            if (compare(key, this.key) < 0)
                return left.floor(key);
            Node result = right.floor(key);
            if (result == nullNode)
                return this;
            return result;
        }

        protected Node higher(K key) {
            if (compare(key, this.key) >= 0)
                return right.higher(key);
            Node result = left.higher(key);
            if (result == nullNode)
                return this;
            return result;
        }

        protected Node ceil(K key) {
            if (compare(key, this.key) > 0)
                return right.ceil(key);
            Node result = left.ceil(key);
            if (result == nullNode)
                return this;
            return result;
        }

        protected Node first() {
            if (left == nullNode)
                return this;
            return left.first();
        }

        protected Node last() {
            if (right == nullNode)
                return this;
            return right.last();
        }

        protected Node search(K key) {
            int value = compare(key, this.key);
            if (value == 0)
                return this;
            if (value < 0)
                return left.search(key);
            return right.search(key);
        }

        public int indexOf(Node node) {
            if (this == node)
                return left.size;
            if (compare(node.key, this.key) > 0)
                return left.size + 1 + right.indexOf(node);
            return left.indexOf(node);
        }

        public K get(int index) {
            if (index < left.size)
                return left.get(index);
            else if (index == left.size)
                return key;
            else
                return right.get(index - left.size - 1);
        }
    }

    private class NullNode extends Node {
        private Object[] splitResult = new Object[2];

        private NullNode() {
            super(null, Long.MIN_VALUE);
            left = this;
            right = this;
            size = 0;
        }

        @Override
        protected Object[] split(K key) {
            splitResult[0] = splitResult[1] = this;
            return splitResult;
        }

        @Override
        protected Node insert(Node node) {
            return node;
        }

        @Override
        protected Node erase(K key) {
            return this;
        }

        @Override
        protected Node lower(K key) {
            return this;
        }

        @Override
        protected Node floor(K key) {
            return this;
        }

        @Override
        protected Node higher(K key) {
            return this;
        }

        @Override
        protected Node ceil(K key) {
            return this;
        }

        @Override
        protected Node first() {
            throw new NoSuchElementException();
        }

        @Override
        protected Node last() {
            throw new NoSuchElementException();
        }

        @Override
        protected void updateSize() {
        }

        @Override
        protected Node search(K key) {
            return this;
        }

    }
}

abstract class LongIntervalTree extends IntervalTree {
    protected long[] value;
    protected long[] delta;

    protected LongIntervalTree(int size) {
        this(size, true);
    }

    public LongIntervalTree(int size, boolean shouldInit) {
        super(size, shouldInit);
    }

    @Override
    protected void initData(int size, int nodeCount) {
        value = new long[nodeCount];
        delta = new long[nodeCount];
    }

    protected abstract long joinValue(long left, long right);

    protected abstract long joinDelta(long was, long delta);

    protected abstract long accumulate(long value, long delta, int length);

    protected abstract long neutralValue();

    protected abstract long neutralDelta();

    protected long initValue(int index) {
        return neutralValue();
    }

    @Override
    protected void initAfter(int root, int left, int right, int middle) {
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        delta[root] = neutralDelta();
    }

    @Override
    protected void initBefore(int root, int left, int right, int middle) {
    }

    @Override
    protected void initLeaf(int root, int index) {
        value[root] = initValue(index);
        delta[root] = neutralDelta();
    }

    @Override
    protected void updatePostProcess(int root, int left, int right, int from,
            int to, long delta, int middle) {
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
    }

    @Override
    protected void updatePreProcess(int root, int left, int right, int from,
            int to, long delta, int middle) {
        pushDown(root, left, middle, right);
    }

    protected void pushDown(int root, int left, int middle, int right) {
        value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root],
                middle - left + 1);
        value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root],
                right - middle);
        delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
        delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
        delta[root] = neutralDelta();
    }

    @Override
    protected void updateFull(int root, int left, int right, int from, int to,
            long delta) {
        value[root] = accumulate(value[root], delta, right - left + 1);
        this.delta[root] = joinDelta(this.delta[root], delta);
    }

    @Override
    protected long queryPostProcess(int root, int left, int right, int from,
            int to, int middle, long leftResult, long rightResult) {
        return joinValue(leftResult, rightResult);
    }

    @Override
    protected void queryPreProcess(int root, int left, int right, int from,
            int to, int middle) {
        pushDown(root, left, middle, right);
    }

    @Override
    protected long queryFull(int root, int left, int right, int from, int to) {
        return value[root];
    }

    @Override
    protected long emptySegmentResult() {
        return neutralValue();
    }
}

class IntPair implements Comparable<IntPair> {
    public final int first, second;

    public IntPair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return "(" + first + "," + second + ")";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;

        IntPair intPair = (IntPair) o;

        return first == intPair.first && second == intPair.second;

    }

    @Override
    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(IntPair o) {
        if (first < o.first)
            return -1;
        if (first > o.first)
            return 1;
        if (second < o.second)
            return -1;
        if (second > o.second)
            return 1;
        return 0;
    }
}

class Matrix {
    public static long mod = Long.MAX_VALUE;
    public final long[][] data;
    public final int rowCount;
    public final int columnCount;

    public Matrix(int rowCount, int columnCount) {
        this.rowCount = rowCount;
        this.columnCount = columnCount;
        this.data = new long[rowCount][columnCount];
    }

    public Matrix(long[][] data) {
        this.rowCount = data.length;
        this.columnCount = data[0].length;
        this.data = data;
    }

    public static Matrix add(Matrix first, Matrix second) {
        Matrix result = new Matrix(first.rowCount, first.columnCount);
        for (int i = 0; i < result.rowCount; i++) {
            for (int j = 0; j < result.columnCount; j++) {
                result.data[i][j] = first.data[i][j] + second.data[i][j];
                if (result.data[i][j] >= mod)
                    result.data[i][j] -= mod;
            }
        }
        return result;
    }

    public static Matrix multiply(Matrix first, Matrix second) {
        Matrix result = new Matrix(first.rowCount, second.columnCount);
        for (int i = 0; i < first.rowCount; i++) {
            for (int j = 0; j < second.rowCount; j++) {
                for (int k = 0; k < second.columnCount; k++)
                    result.data[i][k] = (result.data[i][k] + first.data[i][j]
                            * second.data[j][k])
                            % mod;
            }
        }
        return result;
    }

    public static Matrix fastMultiply(Matrix first, Matrix second) {
        Matrix result = new Matrix(first.rowCount, second.columnCount);
        for (int i = 0; i < first.rowCount; i++) {
            for (int j = 0; j < second.rowCount; j++) {
                for (int k = 0; k < second.columnCount; k++)
                    result.data[i][k] += first.data[i][j] * second.data[j][k];
            }
        }
        for (int i = 0; i < first.rowCount; i++) {
            for (int j = 0; j < second.columnCount; j++)
                result.data[i][j] %= mod;
        }
        return result;
    }

    public static Matrix identityMatrix(int size) {
        Matrix result = new Matrix(size, size);
        for (int i = 0; i < size; i++)
            result.data[i][i] = 1;
        return result;
    }

    public static long[] convert(long[][] matrix) {
        long[] result = new long[matrix.length * matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++)
                result[i * matrix.length + j] = matrix[i][j];
        }
        return result;
    }

    public static long[] sumPowers(long[] matrix, long exponent, long mod,
            int side) {
        long[] result = new long[matrix.length];
        long[] power = new long[matrix.length];
        long[] temp = new long[matrix.length];
        long[] temp2 = new long[matrix.length];
        sumPowers(matrix, result, power, temp, temp2, exponent + 1, mod, side);
        return result;
    }

    private static void sumPowers(long[] matrix, long[] result, long[] power,
            long[] temp, long[] temp2, long exponent, long mod, int side) {
        if (exponent == 0) {
            for (int i = 0; i < matrix.length; i += side + 1)
                power[i] = 1 % mod;
            return;
        }
        if ((exponent & 1) == 0) {
            sumPowers(matrix, result, temp, power, temp2, exponent >> 1, mod,
                    side);
            multiply(temp2, result, temp, mod, side);
            add(result, temp2, mod, side);
            multiply(power, temp, temp, mod, side);
        } else {
            sumPowers(matrix, result, temp, power, temp2, exponent - 1, mod,
                    side);
            add(result, temp, mod, side);
            multiply(power, temp, matrix, mod, side);
        }
    }

    public static long[][] convert(long[] matrix, int side) {
        long[][] result = new long[side][side];
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++)
                result[i][j] = matrix[i * side + j];
        }
        return result;
    }

    public static long[] power(long[] matrix, long exponent, long mod, int side) {
        long[] result = new long[matrix.length];
        long[] temp = new long[result.length];
        power(matrix, result, temp, exponent, mod, side);
        return result;
    }

    private static void power(long[] matrix, long[] result, long[] temp,
            long exponent, long mod, int side) {
        if (exponent == 0) {
            for (int i = 0; i < matrix.length; i += side + 1)
                result[i] = 1 % mod;
            return;
        }
        if ((exponent & 1) == 0) {
            power(matrix, temp, result, exponent >> 1, mod, side);
            multiply(result, temp, temp, mod, side);
        } else {
            power(matrix, temp, result, exponent - 1, mod, side);
            multiply(result, temp, matrix, mod, side);
        }
    }

    public static void multiply(long[] c, long[] a, long[] b, long mod, int side) {
        Arrays.fill(c, 0);
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                for (int k = 0; k < side; k++) {
                    c[i * side + k] += a[i * side + j] * b[j * side + k];
                    if ((j & 3) == 3) {
                        c[i * side + k] %= mod;
                    }
                }
            }
        }
        for (int i = 0; i < c.length; i++)
            c[i] %= mod;
    }

    public static void add(long[] c, long[] a, long mod, int side) {
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                c[i * side + j] += a[i * side + j];
                if (c[i * side + j] >= mod)
                    c[i * side + j] -= mod;
            }
        }
    }

    public static long[] fastPower(long[] matrix, long exponent, long mod,
            int side) {
        long[] result = new long[matrix.length];
        long[] temp = new long[result.length];
        fastPower(matrix, result, temp, exponent, mod, side);
        return result;
    }

    private static void fastPower(long[] matrix, long[] result, long[] temp,
            long exponent, long mod, int side) {
        if (exponent == 0) {
            for (int i = 0; i < matrix.length; i += side + 1)
                result[i] = 1;
            return;
        }
        if ((exponent & 1) == 0) {
            fastPower(matrix, temp, result, exponent >> 1, mod, side);
            fastMultiply(result, temp, temp, mod, side);
        } else {
            power(matrix, temp, result, exponent - 1, mod, side);
            fastMultiply(result, temp, matrix, mod, side);
        }
    }

    public static void fastMultiply(long[] c, long[] a, long[] b, long mod,
            int side) {
        Arrays.fill(c, 0);
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                for (int k = 0; k < side; k++)
                    c[i * side + k] += a[i * side + j] * b[j * side + k];
            }
        }
        for (int i = 0; i < c.length; i++)
            c[i] %= mod;
    }

    public Matrix power(long exponent) {
        if (exponent == 0)
            return identityMatrix(rowCount);
        if (exponent == 1)
            return this;
        Matrix result = power(exponent >> 1);
        result = multiply(result, result);
        if ((exponent & 1) == 1)
            result = multiply(result, this);
        return result;
    }

    public Matrix fastPower(long exponent) {
        if (exponent == 0)
            return identityMatrix(rowCount);
        if (exponent == 1)
            return this;
        Matrix result = power(exponent >> 1);
        result = fastMultiply(result, result);
        if ((exponent & 1) == 1)
            result = fastMultiply(result, this);
        return result;
    }
}

class MiscUtils {
    public static final int[] DX4 = { 1, 0, -1, 0 };
    public static final int[] DY4 = { 0, -1, 0, 1 };
    public static final int[] DX8 = { 1, 1, 1, 0, -1, -1, -1, 0 };
    public static final int[] DY8 = { -1, 0, 1, 1, 1, 0, -1, -1 };
    public static final int[] DX_KNIGHT = { 2, 1, -1, -2, -2, -1, 1, 2 };
    public static final int[] DY_KNIGHT = { 1, 2, 2, 1, -1, -2, -2, -1 };

    private static final String[] ROMAN_TOKENS = { "M", "CM", "D", "CD", "C",
            "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    private static final int[] ROMAN_VALUES = { 1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1 };

    public static long josephProblem(long n, int k) {
        if (n == 1)
            return 0;
        if (k == 1)
            return n - 1;
        if (k > n)
            return (josephProblem(n - 1, k) + k) % n;
        long count = n / k;
        long result = josephProblem(n - count, k);
        result -= n % k;
        if (result < 0)
            result += n;
        else
            result += result / (k - 1);
        return result;
    }

    public static boolean isValidCell(int row, int column, int rowCount,
            int columnCount) {
        return row >= 0 && row < rowCount && column >= 0
                && column < columnCount;
    }

    public static long maximalRectangleSum(long[][] array) {
        int n = array.length;
        int m = array[0].length;
        long[][] partialSums = new long[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            long rowSum = 0;
            for (int j = 0; j < m; j++) {
                rowSum += array[i][j];
                partialSums[i + 1][j + 1] = partialSums[i][j + 1] + rowSum;
            }
        }
        long result = Long.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                long minPartialSum = 0;
                for (int k = 1; k <= n; k++) {
                    long current = partialSums[k][j + 1] - partialSums[k][i];
                    result = Math.max(result, current - minPartialSum);
                    minPartialSum = Math.min(minPartialSum, current);
                }
            }
        }
        return result;
    }

    public static int parseIP(String ip) {
        String[] components = ip.split("[.]");
        int result = 0;
        for (int i = 0; i < 4; i++)
            result += (1 << (24 - 8 * i)) * Integer.parseInt(components[i]);
        return result;
    }

    public static String buildIP(int mask) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 4; i++) {
            if (i != 0)
                result.append('.');
            result.append(mask >> (24 - 8 * i) & 255);
        }
        return result.toString();
    }

    public static <T> boolean equals(T first, T second) {
        return first == null && second == null || first != null
                && first.equals(second);
    }

    public static boolean isVowel(char ch) {
        ch = Character.toUpperCase(ch);
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
                || ch == 'Y';
    }

    public static boolean isStrictVowel(char ch) {
        ch = Character.toUpperCase(ch);
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    public static String convertToRoman(int number) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < ROMAN_TOKENS.length; i++) {
            while (number >= ROMAN_VALUES[i]) {
                number -= ROMAN_VALUES[i];
                result.append(ROMAN_TOKENS[i]);
            }
        }
        return result.toString();
    }

    public static int convertFromRoman(String number) {
        int result = 0;
        for (int i = 0; i < ROMAN_TOKENS.length; i++) {
            while (number.startsWith(ROMAN_TOKENS[i])) {
                number = number.substring(ROMAN_TOKENS[i].length());
                result += ROMAN_VALUES[i];
            }
        }
        return result;
    }

    public static int distance(int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return dx * dx + dy * dy;
    }

    public static <T extends Comparable<T>> T min(T first, T second) {
        if (first.compareTo(second) <= 0)
            return first;
        return second;
    }

    public static <T extends Comparable<T>> T max(T first, T second) {
        if (first.compareTo(second) <= 0)
            return second;
        return first;
    }

    public static void decreaseByOne(int[]... arrays) {
        for (int[] array : arrays) {
            for (int i = 0; i < array.length; i++)
                array[i]--;
        }
    }

    public static int[] getIntArray(String s) {
        String[] tokens = s.split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < result.length; i++)
            result[i] = Integer.parseInt(tokens[i]);
        return result;
    }
}