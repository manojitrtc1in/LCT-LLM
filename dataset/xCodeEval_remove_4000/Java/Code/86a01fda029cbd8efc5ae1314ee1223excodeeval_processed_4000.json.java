import java.util.NavigableSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Iterator;
import java.util.Collections;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeMap;
import java.io.InputStream;
import java.util.Random;
import java.util.Collection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.Comparator;
import java.util.AbstractSet;
import java.util.SortedSet;
import java.util.Set;
import java.util.HashSet;
import java.util.TreeSet;
import java.util.HashMap;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id7 solver = new id7();
        solver.solve(1, in, out);
        out.close();
    }
}

class id7 {

    int[] hx, hy, hl, vx, vy, vl;

    class Tree {
        Tree left, right;
        int value, middle, from, to;
        Tree(int from, int to) {
            this.from=from;
            this.to=to;
            middle=(from+to)/2;
            value=Integer.MIN_VALUE;
            if (from==to) return;
            left=new Tree(from, middle);
            right=new Tree(middle+1, to);
        }
        void update(int pos, int val) {
            if (from==to) {
                value=val;
                return;
            }
            if (pos<=middle) left.update(pos, val);
            else right.update(pos, val);
            value=MiscUtils.max(left.value, right.value);
        }
        int query(int from, int to) {
            if (to<this.from || from>this.to) return Integer.MIN_VALUE;
            if (from<=this.from && to>=this.to) return value;
            return MiscUtils.max(left.query(from, to), right.query(from, to));
        }
    }

    
    
    
    Set<Integer> set;
    Map<Integer, Integer> map;
    
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n=in.readInt(), m=in.readInt(), ret=0;
            int[] a=new int[n];
            set=new HashSet<>();
            map=new HashMap<>();
            for (int i=0; i<n; i++) a[i]=in.readInt();
            while (m-->0) set.add(in.readInt());
            for (int i=n-1; i>=0; i--) {
                int gcd=0;
                for (int j=0; j<=i; j++) gcd=IntegerUtils.gcd(gcd, a[j]);
                if (f(gcd)<0) for (int j=0; j<=i; j++) a[j]/=gcd;
            }
            for (int i: a) ret+=f(i);
            out.printLine(ret);
        }
        
        int f(int x) {
            if (map.containsKey(x)) return map.get(x);
            int ret=0, X=x;
            for (int i=2; i*i<=x; i++) while (x%i==0) {
                x/=i;
                ret+=set.contains(i)?-1:1;
            }
            if (x!=1) ret+=set.contains(x)?-1:1;
            map.put(X, ret);
            return ret;
        }
        
        int gcd(int a, int b) {
            return b==0?a:gcd(b, a%b);
        }
    
    List<IntPair> bfs(TreeSet<Integer>[] dist, int k, int n) {
        List<IntPair> ret=new ArrayList<IntPair>();
        int[] degree=new int[n+1];
        if (dist[0].size()!=1) return null;
        for (int i=1; i<n; i++) {
            for (Object J: dist[i].toArray()) {
                int j=(int)(Integer)J;
                if (dist[i-1].size()==0) return null;
                int x=dist[i-1].first();
                degree[j]++;
                degree[x]++;
                ret.add(new IntPair(j, x));
                if (degree[x]==k) dist[i-1].remove(x);
                if (degree[j]==k) dist[i].remove(j);
            }
        }
        return ret;
    }
}

class MiscUtils {

    public static long binarySearch(long from, long to, Function<Long, Boolean> function) {
        while (from < to) {
            long argument = from + (to - from) / 2;
            if (function.value(argument))
                to = argument;
            else
                from = argument + 1;
        }
        return from;
    }

    public static<T extends Comparable<T>> T max(T first, T second) {
        if (first.compareTo(second) <= 0)
            return second;
        return first;
    }

}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id12 filter;

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
        while (id2(c))
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
        } while (!id2(c));
        return res * sgn;
    }

    public boolean id2(int c) {
        if (filter != null)
            return filter.id2(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id12 {
        public boolean id2(int ch);
    }
    
    public String readString() {
                int c = read();
                while (id2(c))
                        c = read();
                StringBuilder res = new StringBuilder();
                do {
                        if (Character.isValidCodePoint(c))
                                res.appendCodePoint(c);
                        c = read();
                } while (!id2(c));
                return res.toString();
   }
   
   public double readDouble() {
                int c = read();
                while (id2(c))
                        c = read();
                int sgn = 1;
                if (c == '-') {
                        sgn = -1;
                        c = read();
                }
                double res = 0;
                while (!id2(c) && c != '.') {
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
                        while (!id2(c)) {
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
    
    public void print(Object...objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
        
   public void printLine(Object...objects) {
                print(objects);
                writer.println();
        }

}

class IOUtils {

    public static void id6(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

}

interface Function<A, V> {
    public abstract V value(A argument);
}

class ArrayUtils {

    public static int maxElement(int[] array) {
        return maxElement(array, 0, array.length);
    }

    public static int maxElement(int[] array, int from, int to) {
        int result = Integer.MIN_VALUE;
        for (int i = from; i < to; i++)
            result = Math.max(result, array[i]);
        return result;
    }

}

class id4<K, V> extends TreeMap<K, V> {
    private final Factory<V> id9;

    public id4(Factory<V> id9) {
        this.id9 = id9;
    }

    public V get(Object key) {
        if (containsKey(key))
            return super.get(key);
        V value = id9.create();
        try {
            

            super.put((K) key, value);
            return value;
        } catch (ClassCastException e) {
            return value;
        }
    }
}

class IntPair implements Comparable<IntPair> {
    public final int first, second;

    public IntPair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        IntPair intPair = (IntPair) o;

        return first == intPair.first && second == intPair.second;

    }

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

interface Factory<V> {
    public V create();
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

class id1<K> implements NavigableSet<K> {
    protected static final Random rnd = new Random(239);

    protected final Node nullNode;
    protected final Comparator<? super K> comparator;
    protected Node root;
    private final K from;
    private final K to;
    private final boolean fromInclusive;
    private final boolean toInclusive;

    public id1() {
        this((Comparator<? super K>)null);
    }

    public id1(Comparator<? super K> comparator) {
        this(null, null, false, false, comparator, null, null);
    }

    protected id1(K from, K to, boolean fromInclusive, boolean toInclusive, Comparator<? super K> comparator, Node root, Node nullNode) {
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
        return (valueFrom < 0 || valueFrom == 0 && fromInclusive) && (valueTo < 0 || valueTo == 0 && toInclusive);
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
            Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
            if (from == nullNode)
                return 0;
            return root.size - root.indexOf(from);
        }
        Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
        if (from == nullNode || !belongs(from.key))
            return 0;
        Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
        return root.indexOf(to) - root.indexOf(from) + 1;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

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
                id1.this.remove(current);
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
        return addAll((Iterable<? extends K>)c);
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
        retainAll(Collections.<Object>emptySet());
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
                id1.this.remove(current);
            }
        };
    }

    public NavigableSet<K> subSet(K fromElement, boolean fromInclusive, K toElement, boolean toInclusive) {
        return new id1<K>(fromElement, toElement, fromInclusive, toInclusive, comparator, root, nullNode);
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

    protected int compare(K first, K second) {
        if (first == null || second == null)
            return -1;
        if (comparator != null)
            return comparator.compare(first, second);
        

        return ((Comparable<? super K>)first).compareTo(second);
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

    }

    private class NullNode extends Node {
        private Object[] splitResult = new Object[2];

        private NullNode() {
            super(null, Long.MIN_VALUE);
            left = this;
            right = this;
            size = 0;
        }

        protected Object[] split(K key) {
            splitResult[0] = splitResult[1] = this;
            return splitResult;
        }

        protected Node insert(Node node) {
            return node;
        }

        protected Node erase(K key) {
            return this;
        }

        protected Node lower(K key) {
            return this;
        }

        protected Node floor(K key) {
            return this;
        }

        protected Node higher(K key) {
            return this;
        }

        protected Node ceil(K key) {
            return this;
        }

        protected Node first() {
            throw new NoSuchElementException();
        }

        protected Node last() {
            throw new NoSuchElementException();
        }

        protected void updateSize() {
        }

        protected Node search(K key) {
            return this;
        }


    }
}

class Indexer<K> extends id5<K, Integer> {
    private int index = 0;

    public Integer get(Object key) {
        if (!containsKey(key))
            put((K) key, index++);
        return super.get(key);
    }
}

class id5<E, V> extends AbstractMap<E, V> {
    private static final int[] shifts = new int[10];

    private int size;
    private HashEntry<E, V>[] data;
    private int capacity;
    private Set<Entry<E, V>> entrySet;

    static {
        Random random = new Random(System.currentTimeMillis());
        for (int i = 0; i < 10; i++)
            shifts[i] = 1 + 3 * i + random.nextInt(3);
    }

    public id5() {
        this(4);
    }

    private void setCapacity(int size) {
        capacity = Integer.highestOneBit(4 * size);
        

        data = new HashEntry[capacity];
    }

    public id5(int maxSize) {
        setCapacity(maxSize);
        entrySet = new AbstractSet<Entry<E, V>>() {
            public Iterator<Entry<E, V>> iterator() {
                return new Iterator<Entry<E, V>>() {
                    private HashEntry<E, V> last = null;
                    private HashEntry<E, V> current = null;
                    private HashEntry<E, V> base = null;
                    private int lastIndex = -1;
                    private int index = -1;

                    public boolean hasNext() {
                        if (current == null) {
                            for (index++; index < capacity; index++) {
                                if (data[index] != null) {
                                    base = current = data[index];
                                    break;
                                }
                            }
                        }
                        return current != null;
                    }

                    public Entry<E, V> next() {
                        if (!hasNext())
                            throw new NoSuchElementException();
                        last = current;
                        lastIndex = index;
                        current = current.next;
                        if (base.next != last)
                            base = base.next;
                        return last;
                    }

                    public void remove() {
                        if (last == null)
                            throw new IllegalStateException();
                        size--;
                        if (base == last)
                            data[lastIndex] = last.next;
                        else
                            base.next = last.next;
                    }
                };
            }

            public int size() {
                return size;
            }
        };
    }

    public Set<Entry<E, V>> entrySet() {
        return entrySet;
    }

    public void clear() {
        Arrays.fill(data, null);
        size = 0;
    }

    private int index(Object o) {
        return getHash(o.hashCode()) & (capacity - 1);
    }

    private int getHash(int h) {
        int result = h;
        for (int i : shifts)
            result ^= h >>> i;
        return result;
    }

    public V remove(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        HashEntry<E, V> last = null;
        while (current != null) {
            if (current.key.equals(o)) {
                if (last == null)
                    data[index] = current.next;
                else
                    last.next = current.next;
                size--;
                return current.value;
            }
            last = current;
            current = current.next;
        }
        return null;
    }

    public V put(E e, V value) {
        if (e == null)
            return null;
        int index = index(e);
        HashEntry<E, V> current = data[index];
        if (current != null) {
            while (true) {
                if (current.key.equals(e)) {
                    V oldValue = current.value;
                    current.value = value;
                    return oldValue;
                }
                if (current.next == null)
                    break;
                current = current.next;
            }
        }
        if (current == null)
            data[index] = new HashEntry<E, V>(e, value);
        else
            current.next = new HashEntry<E, V>(e, value);
        size++;
        if (2 * size > capacity) {
            HashEntry<E, V>[] oldData = data;
            setCapacity(size);
            for (HashEntry<E, V> entry : oldData) {
                while (entry != null) {
                    HashEntry<E, V> next = entry.next;
                    index = index(entry.key);
                    entry.next = data[index];
                    data[index] = entry;
                    entry = next;
                }
            }
        }
        return null;
    }

    public V get(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        while (current != null) {
            if (current.key.equals(o))
                return current.value;
            current = current.next;
        }
        return null;
    }

    public boolean containsKey(Object o) {
        if (o == null)
            return false;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        while (current != null) {
            if (current.key.equals(o))
                return true;
            current = current.next;
        }
        return false;
    }

    public int size() {
        return size;
    }

    private static class HashEntry<E, V> implements Entry<E, V> {
        private final E key;
        private V value;
        private HashEntry<E, V> next;

        private HashEntry(E key, V value) {
            this.key = key;
            this.value = value;
        }


        public E getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }
    }
}

class id10 extends IntSet {
        private static final Random RND = new Random();
        private static final int[] id8 = new int[4];
        private static final byte id0 = 1;
        private static final byte id3 = 2;

        static {
                for (int i = 0; i < 4; i++)
                        id8[i] = RND.nextInt(31) + 1;
        }

        private int size;
        private int realSize;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;

        public id10() {
                this(3);
        }


        public id10(int capacity) {
                capacity = Math.max(capacity, 1);
                values = new int[capacity];
                present = new byte[capacity];
                ratio = 2;
                initStep(capacity);
        }

        private void initStep(int capacity) {
                step = RND.nextInt(capacity - 2) + 1;
                while (IntegerUtils.gcd(step, capacity) != 1)
                        step++;
        }

        @Override
        public IntIterator iterator() {
                return new IntIterator() {
                        private int position = size == 0 ? values.length : -1;

                        public int value() throws NoSuchElementException {
                                if (position == -1)
                                        advance();
                                if (position >= values.length)
                                        throw new NoSuchElementException();
                                return values[position];
                        }

                        public void advance() throws NoSuchElementException {
                                if (position >= values.length)
                                        throw new NoSuchElementException();
                                position++;
                                while (position < values.length && (present[position] & id0) == 0)
                                        position++;
                        }

                        public boolean isValid() {
                                return position < values.length;
                        }
                };
        }

        @Override
        public int size() {
                return size;
        }

        @Override
        public void add(int value) {
                ensureCapacity((realSize + 1) * ratio + 2);
                int current = getHash(value);
                while (present[current] != 0) {
                        if ((present[current] & id0) != 0 && values[current] == value) {
                                return;
                        }
                        current += step;
                        if (current >= values.length)
                                current -= values.length;
                }
                while ((present[current] & id0) != 0) {
                        current += step;
                        if (current >= values.length)
                                current -= values.length;
                }
                if (present[current] == 0) {
                        realSize++;
                }
                present[current] = id0;
                values[current] = value;
                size++;
        }

        private int getHash(int value) {
                int result = value;
                for (int i : id8)
                        result ^= value >> i;
                result %= values.length;
                if (result < 0)
                        result += values.length;
                return result;
        }

        private void ensureCapacity(int capacity) {
                if (values.length < capacity) {
                        capacity = Math.max(capacity * 2, values.length);
                        rebuild(capacity);
                }
        }

        private void id11() {
                if (values.length > size * ratio * 2 + 10) {
                        rebuild(size * ratio + 3);
                }
        }

        private void rebuild(int capacity) {
                initStep(capacity);
                int[] oldValues = values;
                byte[] oldPresent = present;
                values = new int[capacity];
                present = new byte[capacity];
                size = 0;
                realSize = 0;
                for (int i = 0; i < oldValues.length; i++) {
                        if ((oldPresent[i] & id0) == id0)
                                add(oldValues[i]);
                }
        }

        @Override
        public void remove(int value) {
                int current = getHash(value);
                while (present[current] != 0) {
                        if (values[current] == value && (present[current] & id0) != 0) {
                                present[current] = id3;
                                size--;
                                id11();
                                return;
                        }
                        current += step;
                        if (current >= values.length)
                                current -= values.length;
                }
        }

        @Override
        public boolean contains(int value) {
                int current = getHash(value);
                while (present[current] != 0) {
                        if (values[current] == value && (present[current] & id0) != 0)
                                return true;
                        current += step;
                        if (current >= values.length)
                                current -= values.length;
                }
                return false;
        }
}

abstract class IntSet extends IntCollection {
        @Override
        public int count(int value) {
                return contains(value) ? 1 : 0;
        }
}

abstract class IntCollection {
        public abstract IntIterator iterator();
        public abstract int size();
        public abstract void add(int value);
        public abstract void remove(int value);

        public void forEach(IntTask task) {
                for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
                        task.process(iterator.value());
        }

        public boolean contains(int value) {
                for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance()) {
                        if (iterator.value() == value)
                                return true;
                }
                return false;
        }

        public int count(int value) {
                int result = 0;
                for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance()) {
                        if (iterator.value() == value)
                                result++;
                }
                return result;
        }

        public int min() {
                if (size() == 0)
                        throw new NoSuchElementException();
                int result = Integer.MAX_VALUE;
                for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
                        result = Math.min(result, iterator.value());
                return result;
        }

        public int max() {
                if (size() == 0)
                        throw new NoSuchElementException();
                int result = Integer.MIN_VALUE;
                for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
                        result = Math.max(result, iterator.value());
                return result;
        }

        public IntCollection union(final IntCollection other) {
                return new IntCollection() {
                        @Override
                        public IntIterator iterator() {
                                return new IntIterator() {
                                        private IntIterator first = IntCollection.this.iterator();
                                        private IntIterator second;

                                        public int value() throws NoSuchElementException {
                                                if (first.isValid())
                                                        return first.value();
                                                return second.value();
                                        }

                                        public void advance() throws NoSuchElementException {
                                                if (first.isValid()) {
                                                        first.advance();
                                                        if (!first.isValid())
                                                                second = other.iterator();
                                                } else
                                                        second.advance();
                                        }

                                        public boolean isValid() {
                                                return first.isValid() || second.isValid();
                                        }
                                };
                        }

                        @Override
                        public int size() {
                                return IntCollection.this.size() + other.size();
                        }

                        @Override
                        public void add(int value) {
                                throw new UnsupportedOperationException();
                        }

                        @Override
                        public void remove(int value) {
                                throw new UnsupportedOperationException();
                        }
                };
        }

        public IntCollection map(final IntFunction function) {
                return new IntCollection() {
                        @Override
                        public IntIterator iterator() {
                                return new IntIterator() {
                                        private IntIterator iterator = IntCollection.this.iterator();

                                        public int value() throws NoSuchElementException {
                                                return function.value(iterator.value());
                                        }

                                        public void advance() throws NoSuchElementException {
                                                iterator().advance();
                                        }

                                        public boolean isValid() {
                                                return iterator().isValid();
                                        }
                                };
                        }

                        @Override
                        public int size() {
                                return IntCollection.this.size();
                        }

                        @Override
                        public void add(int value) {
                                throw new UnsupportedOperationException();
                        }

                        @Override
                        public void remove(int value) {
                                throw new UnsupportedOperationException();
                        }
                };
        }

        public int[] toArray() {
                int size = size();
                int[] array = new int[size];
                int i = 0;
                for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
                        array[i++] = iterator.value();
                return array;
        }

        public long sum() {
                long result = 0;
                for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
                        result += iterator.value();
                return result;
        }

        public void addAll(IntCollection values) {
                for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
                        add(it.value());
                }
        }

        public void removeAll(IntCollection values) {
                for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
                        remove(it.value());
                }
        }

        public void retainAll(IntCollection values) {
                for (IntIterator it = iterator(); it.isValid(); it.advance()) {
                        if (!values.contains(it.value())) {
                                remove(it.value());
                        }
                }
        }
}

interface IntTask {
        public void process(int value);
}

interface IntFunction {
        public int value(int key);
}

class IntegerUtils {
    public static long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
                while (b != 0) {
                        long temp = a % b;
                        a = b;
                        b = temp;
                }
                return a;
        }

    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}

interface IntIterator {
        public int value() throws NoSuchElementException;
        
        public void advance() throws NoSuchElementException;
        public boolean isValid();
}