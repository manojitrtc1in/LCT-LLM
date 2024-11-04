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
        int n;
        int[] a;
        int sqrt;
        int q;
        int[] ql;
        int[] qr;
        final static int max = (int) 1e5 + 5;
        int[] cnt = new int[max];
        int[] cntCnt = new int[max];
        int[] prev = new int[max];
        int[] next = new int[max];
        static final int inf = (int) 1e9;
        TaskD.Queue q0 = new TaskD.Queue();
        TaskD.Queue q1 = new TaskD.Queue();
        OutputWriter out;

        void init() {
            cntCnt[0] = (int) 1e9;
            Arrays.fill(prev, -1);
            Arrays.fill(next, -1);
        }

        private void add(int ai) {
            int c = cnt[ai];
            ++cnt[ai];

            --cntCnt[c];
            ++cntCnt[c + 1];

            if (cntCnt[c + 1] == 1) {
                int w = next[c];

                next[c + 1] = w;
                next[c] = c + 1;

                prev[c + 1] = c;
                if (w != -1) {
                    prev[w] = c + 1;
                }
            }

            if (cntCnt[c] == 0) {
                int x = prev[c];

                next[x] = c + 1;
                prev[c + 1] = x;

                next[c] = -1;
                prev[c] = -1;
            }
        }

        void delete(int ai) {
            int c = cnt[ai];
            --cnt[ai];

            --cntCnt[c];
            ++cntCnt[c - 1];

            if (cntCnt[c - 1] == 1) {
                int x = prev[c];

                next[x] = c - 1;
                next[c - 1] = c;

                prev[c] = c - 1;
                prev[c - 1] = x;
            }

            if (cntCnt[c] == 0) {
                int w = next[c];

                next[c - 1] = w;
                if (w != -1) {
                    prev[w] = c - 1;
                }

                next[c] = -1;
                prev[c] = -1;
            }
        }

        public long getAns() {

            q0.reset();
            q1.reset();
            for (int weight = next[0]; weight != -1; weight = next[weight]) {
                q0.add(weight, cntCnt[weight]);
            }

            if (q0.size() == 1 && q0.id7[q0.head] == 1) {
                return 0;
            }
            long messageLength = 0;
            while (!(q0.size() == 0 && q1.size() == 1 && q1.id7[q1.head] == 1)) {
                int w = inf;
                int cc = inf;
                int type = -1;
                int id20 = -228;

                if (w > q0.id16()) {
                    w = q0.id16();
                    cc = q0.id10();
                    id20 = q0.id14();
                    type = 0;
                }
                if (w > q0.id3()) {
                    w = q0.id3();
                    cc = q0.id4();
                    id20 = q0.id0();
                    type = 1;
                }
                if (w > q1.id16()) {
                    w = q1.id16();
                    cc = q1.id10();
                    id20 = q1.id14();
                    type = 2;
                }
                if (w > q1.id3()) {
                    w = q1.id3();
                    cc = q1.id4();
                    id20 = q1.id0();
                    type = 3;
                }
                if (w > (q0.id24() + q1.id24())) {
                    w = q0.id24() + q1.id24();
                    cc = Math.min(q0.id15(), q1.id15());
                    id20 = q0.id22(cc) + q1.id22(cc);
                    type = 4;
                }

                if ((w >= inf) || (cc >= inf)) {
                    throw new RuntimeException();
                }


                if (type == 0) {
                    q0.id11(cc);
                } else if (type == 1) {
                    q0.id25(cc);
                } else if (type == 2) {
                    q1.id11(cc);
                } else if (type == 3) {
                    q1.id25(cc);
                } else if (type == 4) {
                    q0.id21(cc);
                    q1.id21(cc);
                } else {
                    throw new RuntimeException();
                }
                messageLength += id20;
                q1.add(w, cc);
            }

            return messageLength;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.out = out;
            n = in.readInt();
            a = IOUtils.id1(in, n);

            q = in.readInt();
            ql = new int[q];
            qr = new int[q];
            IOUtils.id13(in, ql, qr);
            MiscUtils.id12(ql, qr);

            sqrt = (int) Math.sqrt(n);

            init();

            int[] orderQ = ArrayUtils.createOrder(q);
            ArrayUtils.sort(orderQ, (first, second) -> {
                int res = (ql[first] / sqrt) - (ql[second] / sqrt);
                if (res != 0) {
                    return res;
                }
                return qr[first] - qr[second];
            });

            long[] answer = new long[q];
            Arrays.fill(answer, 228L);
            int l = 0, r = -1;
            for (int id : orderQ) {
                while (r < qr[id]) {
                    ++r;
                    add(a[r]);
                }
                while (ql[id] < l) {
                    --l;
                    add(a[l]);
                }

                while (qr[id] < r) {
                    delete(a[r]);
                    --r;
                }
                while (l < ql[id]) {
                    delete(a[l]);
                    ++l;
                }

                if (ql[id] != l || qr[id] != r) {
                    throw new RuntimeException();
                }
                answer[id] = getAns();
            }
        

            for (long ans : answer) {
                out.printLine(ans);
            }
        }

        static class Queue {
            int head;
            int tail;
            int[] id5 = new int[max];
            int[] id7 = new int[max];

            Queue() {
                reset();
            }

            void reset() {
                head = tail = 0;
            }

            int size() {
                return tail - head;
            }

            void add(int w, int cc) {
                id5[tail] = w;
                id7[tail] = cc;
                ++tail;
            }

            void poll() {
                ++head;
            }

            int id16() {
                return head < tail && 2 <= id7[head] ? id5[head] << 1 : inf;
            }

            int id10() {
                return id7[head] >>> 1;
            }

            int id14() {
                return id10() * (id5[head] << 1);
            }

            int id3() {
                return head + 1 < tail ? (id5[head] + id5[head + 1]) : inf;
            }

            int id4() {
                return Math.min(id7[head], id7[head + 1]);
            }

            int id0() {
                return id4() * (id5[head] + id5[head + 1]);
            }

            int id24() {
                return head < tail ? id5[head] : inf;
            }

            int id15() {
                return id7[head];
            }

            int id22(int cc) {
                return cc * id5[head];
            }

            public void id11(int cc) {
                if (id7[head] == (cc + cc)) {
                    poll();
                } else {
                    id7[head] = 1;
                }
            }

            public void id25(int cc) {
                id7[head] -= cc;
                id7[head + 1] -= cc;
                if (id7[head] == 0 && id7[head + 1] == 0) {
                    poll();
                    poll();
                } else if (id7[head] == 0) {
                    poll();
                } else if (id7[head + 1] == 0) {
                    id5[head + 1] = id5[head];
                    id7[head + 1] = id7[head];
                    ++head;
                }
            }

            public void id21(int cc) {
                if ((id7[head] -= cc) == 0) {
                    poll();
                }
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id23 filter;

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
            while (id6(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if ((c < '0') || (c > '9')) {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id6(c));
            return res * sgn;
        }

        public boolean id6(int c) {
            if (filter != null) {
                return filter.id6(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return (c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == -1);
        }

        public interface id23 {
            public boolean id6(int ch);

        }

    }

    static class Range {
        public static IntList range(int from, int to) {
            int[] result = new int[Math.abs(from - to)];
            int current = from;
            if (from <= to) {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current++;
                }
            } else {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current--;
                }
            }
            return new IntArray(result);
        }

    }

    static class Sorter {
        private static final int id17 = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if ((to - from) < id17) {
                id9(list, from, to, comparator);
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
            for (int i = ((to + from) - 1) >> 1; i >= from; i--) {
                id2(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                id2(list, from, i - 1, comparator, from);
            }
        }

        private static void id2(IntList list, int start, int end, IntComparator comparator, int delta) {
            int value = list.get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end) {
                    return;
                }
                int childValue = list.get(child);
                if ((child + 1) <= end) {
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

        private static void id9(IntList list, int from, int to, IntComparator comparator) {
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

    static class ArrayUtils {
        public static int[] range(int from, int to) {
            return Range.range(from, to).toArray();
        }

        public static int[] createOrder(int size) {
            return range(0, size);
        }

        public static int[] sort(int[] array, IntComparator comparator) {
            return sort(array, 0, array.length, comparator);
        }

        public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
            if ((from == 0) && (to == array.length)) {
                new IntArray(array).sort(comparator);
            } else {
                new IntArray(array).subList(from, to).sort(comparator);
            }
            return array;
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

    static class id19 extends id8 implements IntList {
        private int size;
        private int[] data;

        public id19() {
            this(3);
        }

        public id19(int capacity) {
            data = new int[capacity];
        }

        public id19(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id19(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id19(id19 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id19(int[] arr) {
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
            if ((index > size) || (index < 0)) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if ((index >= size) || (index < 0)) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != (size - 1)) {
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

    static class IntArray extends id8 implements IntList {
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

    static class MiscUtils {
        public static void id12(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }

    }

    static interface IntList extends id18 {
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
                    return !removed && (at < size());
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

        default public IntList subList(final int from, final int to) {
            return new IntList() {
                private final int shift;
                private final int size;

                {
                    if ((from < 0) || (from > to) || (to > IntList.this.size())) {
                        throw new IndexOutOfBoundsException("from = " + from + ", to = " + to + ", size = " + size());
                    }
                    shift = from;
                    size = to - from;
                }

                public int size() {
                    return size;
                }

                public int get(int at) {
                    if ((at < 0) || (at >= size)) {
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
                    if ((at < 0) || (at >= size)) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    IntList.this.set(at + shift, value);
                }

                public IntList compute() {
                    return new id19(this);
                }
            };
        }

    }

    static abstract class id8 implements IntStream {

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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface id18 extends IntCollection {
    }

    static class IOUtils {
        public static int[] id1(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readInt();
            }
            return array;
        }

        public static void id13(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
        }

    }

    static interface IntComparator {
        public int compare(int first, int second);

    }
}

