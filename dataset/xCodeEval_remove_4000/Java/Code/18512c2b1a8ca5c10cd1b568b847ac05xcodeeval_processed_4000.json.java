import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.Writer;
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
        public static int MAX = 500001;
        id9[] tree;
        id9[] id5;
        int time = 0;
        int[] enter = new int[MAX];
        int[] leave = new int[MAX];
        char[] labels;
        int[] heap = new int[1 << 20];
        int hs = 1 << 19;
        int[] answer = new int[MAX];
        id4[] id1;
        void dfs(int vertex, int level) {
            id5[level].add(vertex);
            enter[vertex] = time++;
            for (int child : tree[vertex]) {
                dfs(child, level + 1);
            }
            leave[vertex] = time;
        }
        void xorAt(int position, int value) {
            for (int i = position + hs; i > 0; i /= 2) {
                heap[i] ^= value;
            }
        }
        int id7(int from, int to) {
            int result = 0;
            for (int left = from + hs, right = to + hs; left < right; left /= 2, right /= 2) {
                if (left % 2 == 1) {
                    result ^= heap[left++];
                }
                if (right % 2 == 1) {
                    result ^= heap[--right];
                }
            }
            return result;
        }
        void processLevel(int l) {
            for (int vertex : id5[l]) {
                xorAt(enter[vertex], 1 << labels[vertex - 1] - 'a');
            }
        }
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt(), m = in.readInt();
            tree = new id9[n + 1];
            for (int i = 0; i < tree.length; i++) tree[i] = new id9(0);
            id5 = new id9[n + 1];
            for (int i = 0; i < id5.length; i++) id5[i] = new id9(0);




            id1 = new id4[n + 1];
            for (int i = 0; i < id1.length; i++) id1[i] = new id4(0);
            for (int i = 2; i <= n; i++) {
                int parent = in.readInt();
                tree[parent].add(i);
            }
            dfs(1, 1);
            labels = in.next().toCharArray();
            for (int i = 0; i < m; i++) {
                int vertex = in.readInt(), level = in.readInt();
                Query q = new Query(vertex, i);


                long mask = (((long) i) << 32) + vertex;
                id1[level].add(mask);
            }
            for (int l = 1; l <= n; l++) {
                processLevel(l);






                for (long q : id1[l]) {
                    long vertex = q & ((1 << 30) - 1);
                    long id = q >> 32;
                    answer[(int) id] = id7(enter[(int) vertex], leave[(int) vertex]);
                }
                processLevel(l);
            }
            for (int i = 0; i < m; i++) {
                int anded = answer[i] & (answer[i] - 1);
                if (anded != 0) out.printLine("No");
                else out.printLine("Yes");
            }
        }
        class Query {
            int vertex;
            int id;
            public Query(int vertex, int id) {
                this.vertex = vertex;
                this.id = id;
            }
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
            while (id0(c)) {
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
            } while (!id0(c));
            return res * sgn;
        }
        public String readString() {
            int c = read();
            while (id0(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id0(c));
            return res.toString();
        }
        public boolean id0(int c) {
            if (filter != null) {
                return filter.id0(c);
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
            public boolean id0(int ch);
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
    static interface LongIterator {
        public long value() throws NoSuchElementException;
        public boolean advance();
        public boolean isValid();
    }
    static class id4 extends id3 implements LongList {
        private int size;
        private long[] data;
        public id4() {
            this(3);
        }
        public id4(int capacity) {
            data = new long[capacity];
        }
        public id4(LongCollection c) {
            this(c.size());
            addAll(c);
        }
        public id4(LongStream c) {
            this();
            if (c instanceof LongCollection) {
                ensureCapacity(((LongCollection) c).size());
            }
            addAll(c);
        }
        public id4(id4 c) {
            size = c.size();
            data = c.data.clone();
        }
        public id4(long[] arr) {
            size = arr.length;
            data = arr.clone();
        }
        public int size() {
            return size;
        }
        public long get(int at) {
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
        public void addAt(int index, long value) {
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
    static interface LongCollection extends LongStream {
        public int size();
        default public void add(long value) {
            throw new UnsupportedOperationException();
        }
        default public LongCollection addAll(LongStream values) {
            for (LongIterator it = values.longIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
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
    static interface IntList extends id8 {
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
    static interface IntIterator {
        public int value() throws NoSuchElementException;
        public boolean advance();
        public boolean isValid();
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
    static interface id6 extends LongCollection {
    }
    static interface LongStream extends Iterable<Long>, Comparable<LongStream> {
        public LongIterator longIterator();
        default public Iterator<Long> iterator() {
            return new Iterator<Long>() {
                private LongIterator it = longIterator();
                public boolean hasNext() {
                    return it.isValid();
                }
                public Long next() {
                    long result = it.value();
                    it.advance();
                    return result;
                }
            };
        }
        default public int compareTo(LongStream c) {
            LongIterator it = longIterator();
            LongIterator jt = c.longIterator();
            while (it.isValid() && jt.isValid()) {
                long i = it.value();
                long j = jt.value();
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
    static interface LongList extends id6 {
        public abstract long get(int index);
        public abstract void addAt(int index, long value);
        public abstract void removeAt(int index);
        default public LongIterator longIterator() {
            return new LongIterator() {
                private int at;
                private boolean removed;
                public long value() {
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
        default public void add(long value) {
            addAt(size(), value);
        }
    }
    static interface id8 extends IntCollection {
    }
    static abstract class id3 implements LongStream {
        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
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
            if (!(o instanceof LongStream)) {
                return false;
            }
            LongStream c = (LongStream) o;
            LongIterator it = longIterator();
            LongIterator jt = c.longIterator();
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
            for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }
    }
}

