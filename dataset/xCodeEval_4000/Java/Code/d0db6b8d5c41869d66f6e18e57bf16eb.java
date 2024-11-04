import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.AbstractCollection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.util.AbstractMap;
import java.io.Writer;
import java.util.Map.Entry;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            String[] name0 = new String[n];
            String[] name1 = new String[n];
            CPPMap<String, IntArrayList> map = new CPPMap<>(IntArrayList::new);
            for (int i = 0; i < n; i++) {
                String a = in.readString();
                String b = in.readString();
                name0[i] = a.substring(0, 3);
                name1[i] = a.substring(0, 2) + b.charAt(0);
                map.get(name0[i]).add(i);
            }

            EHashSet<String> set = new EHashSet<>();
            String[] answer = new String[n];
            for (IntArrayList arrayList : map.values()) {
                if (arrayList.size() <= 1) {
                    continue;
                }
                for (Integer x : arrayList) {
                    if (set.contains(name1[x])) {
                        out.printLine("NO");
                        return;
                    }
                    answer[x] = name1[x];
                    set.add(name1[x]);
                }
            }

            for (; ; ) {
                boolean doSome = false;
                for (int i = 0; i < n; i++) {
                    if (answer[i] == null) {
                        boolean f0 = set.contains(name0[i]);
                        boolean f1 = set.contains(name1[i]);
                        if (!f0 && f1) {
                            answer[i] = name0[i];
                            set.add(name0[i]);
                            doSome = true;
                        } else if (f0 && !f1) {
                            answer[i] = name1[i];
                            set.add(name1[i]);
                            doSome = true;
                        } else if (f0 && f1) {
                            out.printLine("NO");
                            return;
                        }
                    }
                }
                if (!doSome) {
                    break;
                }
            }

            for (int i = 0; i < n; i++) {
                if (answer[i] == null) {
                    if (set.contains(name0[i])) {
                        throw new RuntimeException();
                    }
                    answer[i] = name0[i];
                    set.add(name0[i]);
                }
            }

            out.printLine("YES");
            for (String s : answer) {
                out.printLine(s);
            }
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

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class EHashMap<E, V> extends AbstractMap<E, V> {
        private static final int[] shifts = new int[10];
        private int size;
        private EHashMap.HashEntry<E, V>[] data;
        private int capacity;
        private Set<Entry<E, V>> entrySet;

        static {
            Random random = new Random(System.currentTimeMillis());
            for (int i = 0; i < 10; i++) {
                shifts[i] = 1 + 3 * i + random.nextInt(3);
            }
        }

        public EHashMap() {
            this(4);
        }

        private void setCapacity(int size) {
            capacity = Integer.highestOneBit(4 * size);
            

            data = new EHashMap.HashEntry[capacity];
        }

        public EHashMap(int maxSize) {
            setCapacity(maxSize);
            entrySet = new AbstractSet<Entry<E, V>>() {

                public Iterator<Entry<E, V>> iterator() {
                    return new Iterator<Entry<E, V>>() {
                        private EHashMap.HashEntry<E, V> last = null;
                        private EHashMap.HashEntry<E, V> current = null;
                        private EHashMap.HashEntry<E, V> base = null;
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
                            if (!hasNext()) {
                                throw new NoSuchElementException();
                            }
                            last = current;
                            lastIndex = index;
                            current = current.next;
                            if (base.next != last) {
                                base = base.next;
                            }
                            return last;
                        }

                        public void remove() {
                            if (last == null) {
                                throw new IllegalStateException();
                            }
                            size--;
                            if (base == last) {
                                data[lastIndex] = last.next;
                            } else {
                                base.next = last.next;
                            }
                        }
                    };
                }


                public int size() {
                    return size;
                }
            };
        }

        public EHashMap(Map<E, V> map) {
            this(map.size());
            putAll(map);
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
            for (int i : shifts) {
                result ^= h >>> i;
            }
            return result;
        }


        public V remove(Object o) {
            if (o == null) {
                return null;
            }
            int index = index(o);
            EHashMap.HashEntry<E, V> current = data[index];
            EHashMap.HashEntry<E, V> last = null;
            while (current != null) {
                if (current.key.equals(o)) {
                    if (last == null) {
                        data[index] = current.next;
                    } else {
                        last.next = current.next;
                    }
                    size--;
                    return current.value;
                }
                last = current;
                current = current.next;
            }
            return null;
        }


        public V put(E e, V value) {
            if (e == null) {
                return null;
            }
            int index = index(e);
            EHashMap.HashEntry<E, V> current = data[index];
            if (current != null) {
                while (true) {
                    if (current.key.equals(e)) {
                        V oldValue = current.value;
                        current.value = value;
                        return oldValue;
                    }
                    if (current.next == null) {
                        break;
                    }
                    current = current.next;
                }
            }
            if (current == null) {
                data[index] = new EHashMap.HashEntry<E, V>(e, value);
            } else {
                current.next = new EHashMap.HashEntry<E, V>(e, value);
            }
            size++;
            if (2 * size > capacity) {
                EHashMap.HashEntry<E, V>[] oldData = data;
                setCapacity(size);
                for (EHashMap.HashEntry<E, V> entry : oldData) {
                    while (entry != null) {
                        EHashMap.HashEntry<E, V> next = entry.next;
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
            if (o == null) {
                return null;
            }
            int index = index(o);
            EHashMap.HashEntry<E, V> current = data[index];
            while (current != null) {
                if (current.key.equals(o)) {
                    return current.value;
                }
                current = current.next;
            }
            return null;
        }


        public boolean containsKey(Object o) {
            if (o == null) {
                return false;
            }
            int index = index(o);
            EHashMap.HashEntry<E, V> current = data[index];
            while (current != null) {
                if (current.key.equals(o)) {
                    return true;
                }
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
            private EHashMap.HashEntry<E, V> next;

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

    static class EHashSet<E> extends AbstractSet<E> {
        private static final Object VALUE = new Object();
        private final Map<E, Object> map;

        public EHashSet() {
            this(4);
        }

        public EHashSet(int maxSize) {
            map = new EHashMap<E, Object>(maxSize);
        }

        public EHashSet(Collection<E> collection) {
            this(collection.size());
            addAll(collection);
        }


        public boolean contains(Object o) {
            return map.containsKey(o);
        }


        public boolean add(E e) {
            if (e == null) {
                return false;
            }
            return map.put(e, VALUE) == null;
        }


        public boolean remove(Object o) {
            if (o == null) {
                return false;
            }
            return map.remove(o) != null;
        }


        public void clear() {
            map.clear();
        }


        public Iterator<E> iterator() {
            return map.keySet().iterator();
        }


        public int size() {
            return map.size();
        }

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

    static interface Factory<V> {
        public V create();

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

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

    }

    static class CPPMap<K, V> extends EHashMap<K, V> {
        private final Factory<V> defaultValueFactory;

        public CPPMap(Factory<V> defaultValueFactory) {
            this.defaultValueFactory = defaultValueFactory;
        }


        public V get(Object key) {
            if (containsKey(key)) {
                return super.get(key);
            }
            V value = defaultValueFactory.create();
            try {
                

                super.put((K) key, value);
                return value;
            } catch (ClassCastException e) {
                return value;
            }
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }
}

