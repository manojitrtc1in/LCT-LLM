import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
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
            int m = in.readInt();
            char[] s = in.next().toCharArray();
            int n = s.length;
            id5[] byLetter = new id5[26];
            for (int i = 0; i < byLetter.length; i++) {
                byLetter[i] = new id5();
            }
            for (int i = 0; i < n; i++) {
                byLetter[s[i] - 'a'].add(i);
            }

            IntList result = new id9();
            id5 doneLetters = new id5(n);
            for (int c = 0; c < byLetter.length; c++) {
                doneLetters.addAll(byLetter[c]);
                if (!isOk(n, m, doneLetters)) {
                    continue;
                }

                doneLetters.removeAll(byLetter[c]);
                result = new id9(doneLetters);
                id1(n, m, result, byLetter[c]);
                break;
            }

            result.sort((i1, i2) -> Character.compare(s[i1], s[i2]));
            for (int i : result) {
                out.print(s[i]);
            }
        }

        private void id1(int n, int m, IntList done, id5 canUse) {
            int last = -1;
            done.add(n);
            int size = done.size();
            for (int idx = 0; idx < size; idx++) {
                int i = done.get(idx);

                if (i < last) {
                    continue;
                }

                if (i - last <= m) {
                    last = i;
                } else {
                    while (canUse.first() < last) {
                        canUse.remove(canUse.first());
                    }
                    while (true) {
                        int i1 = canUse.first();
                        canUse.remove(i1);
                        if (canUse.isEmpty() || canUse.first() - last > m) {
                            last = i1;
                            done.add(i1);
                            idx--;
                            break;
                        }
                    }
                }
            }
            done.removeAt(size - 1);
        }

        private boolean isOk(int n, int m, id5 done) {
            int last = -1;
            for (int i : done) {
                if (i - last > m) {
                    return false;
                }
                last = i;
            }
            return n - last <= m;
        }

    }

    static class id5 implements IntSet {
        protected int[] value;
        protected int[] left;
        protected int[] right;
        protected int[] parent;
        private int[] size;
        private final IntComparator comparator;
        private int nextFree;
        protected int root = -1;

        public id5() {
            this(null);
        }

        public id5(IntComparator comparator) {
            this(comparator, 5);
        }

        public id5(int capacity) {
            this(null, capacity);
        }

        public id5(IntComparator comparator, int capacity) {
            this.comparator = comparator;
            value = new int[capacity];
            left = new int[capacity];
            right = new int[capacity];
            parent = new int[capacity];
            size = new int[capacity];
        }

        protected final int compare(int first, int second) {
            if (comparator == null) {
                return first < second ? -1 : first == second ? 0 : 1;
            } else {
                return comparator.compare(first, second);
            }
        }


        public IntIterator intIterator() {
            return new IntIterator() {
                private boolean first = true;
                private boolean id4 = root == -1;


                public int value() throws NoSuchElementException {
                    if (first) {
                        if (root == -1) {
                            throw new NoSuchElementException();
                        }
                        int leftmost = leftmost(root);
                        splay(leftmost);
                        first = false;
                    }
                    return value[root];
                }


                public boolean advance() throws NoSuchElementException {
                    if (root == -1 || id4) {
                        throw new NoSuchElementException();
                    }
                    int next = leftmost(right[root]);
                    if (next == -1) {
                        id4 = true;
                        return false;
                    }
                    splay(next);
                    return true;
                }


                public boolean isValid() {
                    return !id4;
                }


                public void remove() throws NoSuchElementException {
                    throw new UnsupportedOperationException();
                }
            };
        }

        private void splay(int node) {
            if (node == -1) {
                return;
            }
            while (parent[node] != -1) {
                if (parent[parent[node]] == -1) {
                    rotate(node);
                } else if ((left[parent[node]] == node) == (left[parent[parent[node]]] == parent[node])) {
                    rotate(parent[node]);
                    rotate(node);
                } else {
                    rotate(node);
                    rotate(node);
                }
            }
            this.root = node;
        }

        private void rotate(int node) {
            int cParent = parent[node];
            if (node == left[cParent]) {
                setLeft(cParent, right[node]);
                if (parent[cParent] != -1) {
                    if (cParent == left[parent[cParent]]) {
                        setLeft(parent[cParent], node);
                    } else {
                        setRight(parent[cParent], node);
                    }
                } else {
                    parent[node] = -1;
                }
                setRight(node, cParent);
            } else {
                setRight(cParent, left[node]);
                if (parent[cParent] != -1) {
                    if (cParent == left[parent[cParent]]) {
                        setLeft(parent[cParent], node);
                    } else {
                        setRight(parent[cParent], node);
                    }
                } else {
                    parent[node] = -1;
                }
                setLeft(node, cParent);
            }
            update(cParent);
            update(node);
        }

        protected void update(int node) {
            size[node] = size(left[node]) + size(right[node]) + 1;
        }

        protected int size(int node) {
            if (node != -1) {
                return size[node];
            }
            return 0;
        }

        protected int leftmost(int root) {
            if (root == -1) {
                return -1;
            }
            while (left[root] != -1) {
                root = left[root];
            }
            return root;
        }

        protected int rightmost(int root) {
            if (root == -1) {
                return -1;
            }
            while (right[root] != -1) {
                root = right[root];
            }
            return root;
        }


        public int size() {
            return size(root);
        }


        public void add(int value) {
            if (contains(value)) {
                return;
            }
            ensureCapacity(nextFree + 1);
            id5.Split roots = split(root, value);
            setLeft(nextFree, roots.left);
            setRight(nextFree, roots.right);
            parent[nextFree] = -1;
            this.value[nextFree] = value;
            update(nextFree);
            root = nextFree++;
        }

        private void merge(int left, int right) {
            if (left == -1) {
                root = right;
            } else if (right == -1) {
                root = left;
            } else {
                splay(rightmost(left));
                setRight(root, right);
                update(root);
            }
        }

        private void setLeft(int node, int child) {
            left[node] = child;
            if (child != -1) {
                parent[child] = node;
            }
        }

        private void setRight(int node, int child) {
            right[node] = child;
            if (child != -1) {
                parent[child] = node;
            }
        }

        protected id5.Split split(int root, int value) {
            if (root == -1) {
                return new id5.Split();
            }
            int compare = compare(this.value[root], value);
            if (compare < 0) {
                id5.Split result = split(right[root], value);
                setRight(root, result.left);
                result.left = root;
                update(root);
                behead(root);
                return result;
            } else if (compare > 0) {
                id5.Split result = split(left[root], value);
                setLeft(root, result.right);
                result.right = root;
                update(root);
                behead(root);
                return result;
            } else {
                id5.Split result = new id5.Split();
                result.left = left[root];
                result.right = right[root];
                behead(left[root]);
                behead(right[root]);
                return result;
            }
        }

        protected int ensureCapacity(int capacity) {
            if (parent.length < capacity) {
                capacity = Math.max(2 * parent.length, capacity);
                left = Arrays.copyOf(left, capacity);
                right = Arrays.copyOf(right, capacity);
                parent = Arrays.copyOf(parent, capacity);
                size = Arrays.copyOf(size, capacity);
                value = Arrays.copyOf(value, capacity);
                return capacity;
            }
            return parent.length;
        }


        public boolean remove(int value) {
            if (contains(value)) {
                behead(left[root]);
                behead(right[root]);
                merge(left[root], right[root]);
                return true;
            }
            return false;
        }


        public boolean contains(int value) {
            int node = root;
            int lastNode = -1;
            while (node != -1) {
                lastNode = node;
                int compare = compare(value, this.value[node]);
                if (compare == 0) {
                    splay(node);
                    return true;
                }
                if (compare < 0) {
                    node = left[node];
                } else {
                    node = right[node];
                }
            }
            if (lastNode != -1) {
                splay(lastNode);
            }
            return false;
        }

        protected void behead(int node) {
            if (node != -1) {
                parent[node] = -1;
            }
        }

        protected static class Split {
            protected int left = -1;
            protected int right = -1;

        }

    }

    static interface id8 extends IntCollection {
    }

    static interface IntList extends id8 {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public int first() {
            return get(0);
        }

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

        default public IntList sort(IntComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
        }

    }

    static interface IntComparator {
        public int compare(int first, int second);

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(char i) {
            writer.print(i);
        }

        public void close() {
            writer.close();
        }

    }

    static interface IntSet extends IntCollection {
    }

    static class Sorter {
        private static final int id7 = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if (to - from < id7) {
                id6(list, from, to, comparator);
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
                id0(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                id0(list, from, i - 1, comparator, from);
            }
        }

        private static void id0(IntList list, int start, int end, IntComparator comparator, int delta) {
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

        private static void id6(IntList list, int from, int to, IntComparator comparator) {
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

    static interface IntCollection extends IntStream {
        public int size();

        default public boolean isEmpty() {
            return size() == 0;
        }

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public boolean remove(int value) {
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (value == it.value()) {
                    it.remove();
                    return true;
                }
            }
            return false;
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

        default public IntCollection removeAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                remove(it.value());
            }
            return this;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

        public void remove();

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
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

        default public int first() {
            return intIterator().value();
        }

        default public int compareTo(IntStream c) {
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

    }

    static class id9 extends id2 implements IntList {
        private int size;
        private int[] data;

        public id9() {
            this(3);
        }

        public id9(int capacity) {
            data = new int[capacity];
        }

        public id9(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id9(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id9(id9 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id9(int[] arr) {
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

    }

    static abstract class id2 implements IntStream {

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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id10 filter;

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
            while (id3(c)) {
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
            } while (!id3(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id3(c));
            return res.toString();
        }

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface id10 {
            public boolean id3(int ch);

        }

    }
}

