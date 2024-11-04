import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.SortedSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
    static class TaskE {
        int id3 = 10000;
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k = in.readInt();
            Station[] stations = new Station[n];
            for (int i = 0; i < stations.length; i++)
                stations[i] = new Station(in.readInt(), in.readInt(), in.readInt());
            Arrays.sort(stations, Comparator.comparingInt(o -> o.x));
            id0<Integer>[] combined = new id0[id3];
            for (int i = 0; i < combined.length; i++) combined[i] = new id0<>();
            TreeSet<Station> byReach = new TreeSet<>((a, b) -> {
                if (a.reach != b.reach) return Integer.compare(a.reach, b.reach);
                return Integer.compare(a.x, b.x);
            });
            long res = 0;
            for (Station station : stations) {
                while (true) {
                    if (byReach.isEmpty()) break;
                    Station first = byReach.first();
                    if (first.reach < station.x) {
                        combined[first.f].remove(first.x);
                        byReach.remove(first);
                    } else break;
                }
                for (int closeFreq = Math.max(0, station.f - k); closeFreq <= Math.min(id3 - 1, station.f + k); closeFreq++) {
                    Integer leftX = combined[closeFreq].ceiling(station.x - station.r); 

                    if (leftX != null) {
                        int id2 = combined[closeFreq].headSet(leftX, true).size() - 1;
                        res += (combined[closeFreq].size() - id2);
                    }
                }
                combined[station.f].add(station.x);
                byReach.add(station);
            }
            out.printLine(res);
        }
        class Station {
            int x;
            int r;
            int f;
            int reach;
            public Station(int x, int r, int f) {
                this.x = x;
                this.r = r;
                this.f = f - 1;
                reach = x + r;
            }
        }
    }
    static class id0<K> implements NavigableSet<K> {
        protected static final Random rnd = new Random(239);
        protected final Node nullNode;
        protected final Comparator<? super K> comparator;
        protected Node root;
        private final K from;
        private final K to;
        private final boolean fromInclusive;
        private final boolean toInclusive;
        public id0() {
            this((Comparator<? super K>) null);
        }
        public id0(Comparator<? super K> comparator) {
            this(null, null, false, false, comparator, null, null);
        }
        public id0(Iterable<? extends K> collection) {
            this(collection, null);
        }
        public id0(Iterable<? extends K> collection, Comparator<? super K> comparator) {
            this(comparator);
            addAll(collection);
        }
        protected id0(K from, K to, boolean fromInclusive, boolean toInclusive, Comparator<? super K> comparator,
                           Node root, Node nullNode) {
            this.comparator = comparator;
            this.from = from;
            this.to = to;
            this.fromInclusive = fromInclusive;
            this.toInclusive = toInclusive;
            if (nullNode == null) {
                nullNode = new NullNode();
            }
            if (root == null) {
                root = nullNode;
            }
            this.root = root;
            this.nullNode = nullNode;
        }
        public boolean addAll(Iterable<? extends K> collection) {
            boolean result = false;
            for (K element : collection) {
                result |= add(element);
            }
            return result;
        }
        public K lower(K k) {
            Node target = root.lower(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }
        private boolean belongs(K key) {
            int valueFrom = compare(from, key);
            int valueTo = compare(key, to);
            return (valueFrom < 0 || valueFrom == 0 && fromInclusive) && (valueTo < 0 || valueTo == 0 && toInclusive);
        }
        public K floor(K k) {
            Node target = root.floor(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }
        public K ceiling(K k) {
            Node target = root.ceil(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }
        public K higher(K k) {
            Node target = root.higher(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }
        public K pollFirst() {
            K first = first();
            if (first == null) {
                throw new NoSuchElementException();
            }
            root.erase(first);
            return first;
        }
        public K pollLast() {
            K last = last();
            if (last == null) {
                throw new NoSuchElementException();
            }
            root.erase(last);
            return last;
        }
        public int size() {
            if (from == null && to == null) {
                return root.size;
            }
            if (from == null) {
                Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
                if (to == nullNode) {
                    return 0;
                }
                return root.indexOf(to) + 1;
            }
            if (to == null) {
                Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
                if (from == nullNode) {
                    return 0;
                }
                return root.size - root.indexOf(from);
            }
            Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
            if (from == nullNode || !belongs(from.key)) {
                return 0;
            }
            Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
            return root.indexOf(to) - root.indexOf(from) + 1;
        }
        public boolean isEmpty() {
            return size() == 0;
        }
        @SuppressWarnings ({"unchecked"})
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
                    id0.this.remove(current);
                }
            };
        }
        public Object[] toArray() {
            Object[] array = new Object[size()];
            int index = 0;
            for (K key : this) {
                array[index++] = key;
            }
            return array;
        }
        @SuppressWarnings ({"unchecked"})
        public <T> T[] toArray(T[] a) {
            if (a.length < size()) {
                throw new IllegalArgumentException();
            }
            int index = 0;
            for (K key : this) {
                a[index++] = (T) key;
            }
            return a;
        }
        public boolean add(K k) {
            if (k == null) {
                throw new NullPointerException();
            }
            if (contains(k)) {
                return false;
            }
            root = root.insert(createNode(k));
            return true;
        }
        protected Node createNode(K k) {
            return new Node(k, rnd.nextLong());
        }
        public boolean remove(Object o) {
            if (!contains(o)) {
                return false;
            }
            

            root = root.erase((K) o);
            return true;
        }
        public boolean containsAll(Collection<?> c) {
            for (Object o : c) {
                if (!contains(o)) {
                    return false;
                }
            }
            return true;
        }
        public boolean addAll(Collection<? extends K> c) {
            return addAll((Iterable<? extends K>) c);
        }
        public boolean retainAll(Collection<?> c) {
            List<K> toRemove = new ArrayList<K>();
            for (K key : this) {
                if (!c.contains(key)) {
                    toRemove.add(key);
                }
            }
            return removeAll(toRemove);
        }
        public boolean removeAll(Collection<?> c) {
            boolean result = false;
            for (Object o : c) {
                result |= remove(o);
            }
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
                    id0.this.remove(current);
                }
            };
        }
        public NavigableSet<K> subSet(K fromElement, boolean fromInclusive, K toElement, boolean toInclusive) {
            return new id0<K>(fromElement, toElement, fromInclusive, toInclusive, comparator, root, nullNode);
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
            if (isEmpty()) {
                return null;
            }
            if (from == null) {
                return root.first().key;
            }
            if (fromInclusive) {
                return ceiling(from);
            }
            return higher(from);
        }
        public K last() {
            if (isEmpty()) {
                return null;
            }
            if (to == null) {
                return root.last().key;
            }
            if (toInclusive) {
                return floor(to);
            }
            return lower(to);
        }
        protected int compare(K first, K second) {
            if (first == null || second == null) {
                return -1;
            }
            if (comparator != null) {
                return comparator.compare(first, second);
            }
            

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
            @SuppressWarnings ({"unchecked"})
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
            @SuppressWarnings ({"unchecked"})
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
                if (left == nullNode) {
                    return right;
                }
                if (right == nullNode) {
                    return left;
                }
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
                if (value == 0) {
                    return merge(left, right);
                }
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
                if (compare(key, this.key) <= 0) {
                    return left.lower(key);
                }
                Node result = right.lower(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }
            protected Node floor(K key) {
                if (compare(key, this.key) < 0) {
                    return left.floor(key);
                }
                Node result = right.floor(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }
            protected Node higher(K key) {
                if (compare(key, this.key) >= 0) {
                    return right.higher(key);
                }
                Node result = left.higher(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }
            protected Node ceil(K key) {
                if (compare(key, this.key) > 0) {
                    return right.ceil(key);
                }
                Node result = left.ceil(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }
            protected Node first() {
                if (left == nullNode) {
                    return this;
                }
                return left.first();
            }
            protected Node last() {
                if (right == nullNode) {
                    return this;
                }
                return right.last();
            }
            protected Node search(K key) {
                int value = compare(key, this.key);
                if (value == 0) {
                    return this;
                }
                if (value < 0) {
                    return left.search(key);
                }
                return right.search(key);
            }
            public int indexOf(Node node) {
                if (this == node) {
                    return left.size;
                }
                if (compare(node.key, this.key) > 0) {
                    return left.size + 1 + right.indexOf(node);
                }
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
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id4 filter;
        public InputReader(InputStream stream) {
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
        public int readInt() {
            int c = read();
            while (id1(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id1(c));
            return res * sgn;
        }
        public boolean id1(int c) {
            if (filter != null) {
                return filter.id1(c);
            }
            return isWhitespace(c);
        }
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
        public interface id4 {
            public boolean id1(int ch);
        }
    }
    static class OutputWriter {
        private final PrintWriter writer;
        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }
        public void close() {
            writer.close();
        }
        public void printLine(long i) {
            writer.println(i);
        }
    }
}
