import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.SortedSet;
import java.util.InputMismatchException;
import java.util.Random;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            try {
                int n = in.readInt();
                int[] x = new int[n], y = new int[n];
                in.readIntArrays(x, y);
                int nx = ArrayUtils.compress(x).length, ny = ArrayUtils.compress(y).length;
                IntList[] list = new IntList[ny];
                Arrays.setAll(list, i -> new IntArrayList());
                for (int i = 0; i < n; i++) {
                    list[y[i]].add(x[i]);
                }
                int[] counter = new int[nx];
                int dist = 0;
                NavigableSet<Integer> set = new TreapSet<>();
                for (int i = 0; i < n; i++) {
                    if (counter[x[i]] == 0) {
                        dist++;
                        set.add(x[i]);
                    }
                    counter[x[i]]++;
                }
                long res = 0;
                for (int yy = 0; yy < ny; yy++) {
                    int s = set.size();
                    res += (long) s * (s + 1) / 2;
                    list[yy] = list[yy].sort();
                    int minX = list[yy].min(), maxX = list[yy].max();
                    Set<Integer> lowerSet = set.headSet(minX), higherSet = set.tailSet(maxX, false);
                    int ls = lowerSet.size(), hs = higherSet.size();
                    res -= (long) ls * (ls + 1) / 2;
                    res -= (long) hs * (hs + 1) / 2;
                    for (int i = 1; i < list[yy].size(); i++) {
                        Set<Integer> subSet = set.subSet(list[yy].get(i - 1), false, list[yy].get(i), false);
                        int ss = subSet.size();
                        res -= (long) ss * (ss + 1) / 2;
                    }
                    for (int i : list[yy]) {
                        if (--counter[i] == 0) {
                            set.remove(i);
                        }
                    }
                }
                out.printLine(res);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public void swap(int first, int second) {
            if (first == second) {
                return;
            }
            int temp = get(first);
            set(first, get(second));
            set(second, temp);
        }

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }

        default public void add(int value) {
            addAt(size(), value);
        }

        default public IntList sort() {
            sort(IntComparator.DEFAULT);
            return this;
        }

        default public IntList sort(IntComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
        }

        default IntList unique() {
            int last = Integer.MIN_VALUE;
            IntList result = new IntArrayList();
            int size = size();
            for (int i = 0; i < size; i++) {
                int current = get(i);
                if (current != last) {
                    result.add(current);
                    last = current;
                }
            }
            return result;
        }

        default public IntList subList(final int from, final int to) {
            return new IntList() {
                private final int shift;
                private final int size;

                {
                    if (from < 0 || from > to || to > IntList.this.size()) {
                        throw new IndexOutOfBoundsException("from = " + from + ", to = " + to + ", size = " + size());
                    }
                    shift = from;
                    size = to - from;
                }

                public int size() {
                    return size;
                }

                public int get(int at) {
                    if (at < 0 || at >= size) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    return IntList.this.get(at + shift);
                }

                public void addAt(int index, int value) {
                    throw new UnsupportedOperationException();
                }

                public void removeAt(int index) {
                    throw new UnsupportedOperationException();
                }

                public void set(int at, int value) {
                    if (at < 0 || at >= size) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    IntList.this.set(at + shift, value);
                }

                public IntList compute() {
                    return new IntArrayList(this);
                }
            };
        }

    }

    static class Sorter {
        private static final int INSERTION_THRESHOLD = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if (to - from < INSERTION_THRESHOLD) {
                insertionSort(list, from, to, comparator);
                return;
            }
            if (remaining == 0) {
                heapSort(list, from, to, comparator);
                return;
            }
            remaining--;
            int pivotIndex = (from + to) >> 1;
            int pivot = list.get(pivotIndex);
            list.swap(pivotIndex, to);
            int storeIndex = from;
            int equalIndex = to;
            for (int i = from; i < equalIndex; i++) {
                int value = comparator.compare(list.get(i), pivot);
                if (value < 0) {
                    list.swap(storeIndex++, i);
                } else if (value == 0) {
                    list.swap(--equalIndex, i--);
                }
            }
            quickSort(list, from, storeIndex - 1, remaining, comparator);
            for (int i = equalIndex; i <= to; i++) {
                list.swap(storeIndex++, i);
            }
            quickSort(list, storeIndex, to, remaining, comparator);
        }

        private static void heapSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = (to + from - 1) >> 1; i >= from; i--) {
                siftDown(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                siftDown(list, from, i - 1, comparator, from);
            }
        }

        private static void siftDown(IntList list, int start, int end, IntComparator comparator, int delta) {
            int value = list.get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end) {
                    return;
                }
                int childValue = list.get(child);
                if (child + 1 <= end) {
                    int otherValue = list.get(child + 1);
                    if (comparator.compare(otherValue, childValue) > 0) {
                        child++;
                        childValue = otherValue;
                    }
                }
                if (comparator.compare(value, childValue) >= 0) {
                    return;
                }
                list.swap(start, child);
                start = child;
            }
        }

        private static void insertionSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = from + 1; i <= to; i++) {
                int value = list.get(i);
                for (int j = i - 1; j >= from; j--) {
                    if (comparator.compare(list.get(j), value) <= 0) {
                        break;
                    }
                    list.swap(j, j + 1);
                }
            }
        }

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        IntIterator intIterator();

        default Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

        default int min() {
            int result = Integer.MAX_VALUE;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                int current = it.value();
                if (current < result) {
                    result = current;
                }
            }
            return result;
        }

        default int max() {
            int result = Integer.MIN_VALUE;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                int current = it.value();
                if (current > result) {
                    result = current;
                }
            }
            return result;
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

    static class IntArray extends IntAbstractStream implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void addAt(int index, int value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

        public void set(int index, int value) {
            data[index] = value;
        }

    }

    static class TreapSet<K> implements NavigableSet<K> {
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

        public TreapSet(Iterable<? extends K> collection, Comparator<? super K> comparator) {
            this(comparator);
            addAll(collection);
        }

        protected TreapSet(K from, K to, boolean fromInclusive, boolean toInclusive, Comparator<? super K> comparator,
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
            for (K key : this) {
                array[index++] = key;
            }
            return array;
        }

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
            List<K> toRemove = new ArrayList<>();
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
            retainAll(Collections.emptySet());
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

        public NavigableSet<K> subSet(K fromElement, boolean fromInclusive, K toElement, boolean toInclusive) {
            return new TreapSet<>(fromElement, toElement, fromInclusive, toInclusive, comparator, root, nullNode);
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

    static abstract class IntAbstractStream implements IntStream {
        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }

        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }

        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static class ArrayUtils {
        public static int[] sort(int[] array, IntComparator comparator) {
            return sort(array, 0, array.length, comparator);
        }

        public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
            if (from == 0 && to == array.length) {
                new IntArray(array).sort(comparator);
            } else {
                new IntArray(array).subList(from, to).sort(comparator);
            }
            return array;
        }

        public static int[] unique(int[] array) {
            return new IntArray(array).unique().toArray();
        }

        public static int[] compress(int[]... arrays) {
            int totalLength = 0;
            for (int[] array : arrays) {
                totalLength += array.length;
            }
            int[] all = new int[totalLength];
            int delta = 0;
            for (int[] array : arrays) {
                System.arraycopy(array, 0, all, delta, array.length);
                delta += array.length;
            }
            sort(all, IntComparator.DEFAULT);
            all = unique(all);
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i] = Arrays.binarySearch(all, array[i]);
                }
            }
            return all;
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface IntComparator {
        IntComparator DEFAULT = Integer::compare;

        int compare(int first, int second);

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class IntArrayList extends IntAbstractStream implements IntList {
        private int size;
        private int[] data;

        public IntArrayList() {
            this(3);
        }

        public IntArrayList(int capacity) {
            data = new int[capacity];
        }

        public IntArrayList(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public IntArrayList(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public IntArrayList(IntArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public IntArrayList(int[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public int get(int at) {
            if (at >= size) {
                throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
            }
            return data[at];
        }

        private void ensureCapacity(int capacity) {
            if (data.length >= capacity) {
                return;
            }
            capacity = Math.max(2 * data.length, capacity);
            data = Arrays.copyOf(data, capacity);
        }

        public void addAt(int index, int value) {
            ensureCapacity(size + 1);
            if (index > size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if (index >= size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
        }

        public void set(int index, int value) {
            if (index >= size) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            data[index] = value;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void readIntArrays(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
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

        public interface SpaceCharFilter {
            boolean isSpaceChar(int ch);

        }

    }
}

