import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
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
        id6 solver = new id6();
        solver.solve(1, in, out);
        out.close();
    }

    static class id6 {
        int[] primes = IntegerUtils.id15(40_000_000);

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int t = in.readInt();
            long[] n = new long[t];
            long[] k = new long[t];
            in.id11(n, k);
            int[] answer = new int[t];
            for (int i = 0; i < t; i++) {
                if (answer[i] != 0) {
                    continue;
                }
                LongList id0 = new id8();
                long number = k[i];
                if (isPrime(number)) {
                    id0.add(number);
                } else {
                    for (long j : primes) {
                        if (number % j == 0) {
                            id0.add(j);
                            do {
                                number /= j;
                            } while (number % j == 0);
                            if (isPrime(number)) {
                                id0.add(number);
                                break;
                            }
                        }
                    }
                }
                if (id0.size() <= 1) {
                    for (int j = i; j < t; j++) {
                        if (k[j] == k[i]) {
                            if (k[i] != 1 && n[j] % id0.get(0) == 0) {
                                answer[j] = 1;
                            } else {
                                answer[j] = -1;
                            }
                        }
                    }
                    continue;
                }
                if (id0.size() == 2) {
                    long a = id0.get(0);
                    long b = id0.get(1);
                    BigInteger bigB = BigInteger.valueOf(b);
                    BigInteger revA = BigInteger.valueOf(a).modInverse(bigB);
                    for (int j = i; j < t; j++) {
                        if (k[j] == k[i]) {
                            long x = BigInteger.valueOf(n[j]).multiply(revA).mod(bigB).longValue();
                            if (n[j] / a >= x) {
                                answer[j] = 1;
                            } else {
                                answer[j] = -1;
                            }
                        }
                    }
                    continue;
                }
                long[] min = new long[(int) id0.get(0)];
                Arrays.fill(min, Long.MAX_VALUE / 2);
                min[0] = 0;
                id14 was = new id14();
                for (long d : id0) {
                    if (d % min.length == 0) {
                        continue;
                    }
                    int shift = (int) (d % min.length);
                    if (was.contains(shift)) {
                        continue;
                    }
                    was.add(shift);
                    int current = 0;
                    for (int j = 0; j < min.length; j++) {
                        int next = current + shift;
                        if (next >= min.length) {
                            next -= min.length;
                        }
                        min[next] = Math.min(min[next], min[current] + d);
                        current = next;
                    }
                    for (int j = 0; j < min.length; j++) {
                        int next = current + shift;
                        if (next >= min.length) {
                            next -= min.length;
                        }
                        if (min[next] <= min[current] + d) {
                            break;
                        }
                        min[next] = min[current] + d;
                        current = next;
                    }
                }
                for (int j = i; j < t; j++) {
                    if (k[j] == k[i]) {
                        if (min[(int) (n[j] % min.length)] <= n[j]) {
                            answer[j] = 1;
                        } else {
                            answer[j] = -1;
                        }
                    }
                }
            }
            for (int i = 0; i < t; i++) {
                out.printLine(answer[i] == 1 ? "YES" : "NO");
            }
        }

        boolean isPrime(long n) {
            return BigInteger.valueOf(n).isProbablePrime(30);
        }

    }

    static class id8 extends id7 implements LongList {
        private int size;
        private long[] data;

        public id8() {
            this(3);
        }

        public id8(int capacity) {
            data = new long[capacity];
        }

        public id8(LongCollection c) {
            this(c.size());
            addAll(c);
        }

        public id8(LongStream c) {
            this();
            if (c instanceof LongCollection) {
                ensureCapacity(((LongCollection) c).size());
            }
            addAll(c);
        }

        public id8(id8 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id8(long[] arr) {
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

    static interface id12 extends IntCollection {
    }

    static abstract class id7 implements LongStream {

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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class id13 extends id4 implements IntList {
        private int size;
        private int[] data;

        public id13() {
            this(3);
        }

        public id13(int capacity) {
            data = new int[capacity];
        }

        public id13(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id13(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id13(id13 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id13(int[] arr) {
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


        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

    }

    static class id14 extends id4 implements IntSet {
        private static final Random RND = new Random();
        private static final int[] id9 = new int[4];
        private static final byte id1 = 1;
        private static final byte id5 = 2;
        private int size;
        private int realSize;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;

        static {
            for (int i = 0; i < 4; i++) {
                id9[i] = RND.nextInt(31) + 1;
            }
        }

        public id14() {
            this(3);
        }

        public id14(int capacity) {
            capacity = Math.max(capacity, 3);
            values = new int[capacity];
            present = new byte[capacity];
            ratio = 2;
            initStep(capacity);
        }

        public id14(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id14(int[] arr) {
            this(new IntArray(arr));
        }

        private void initStep(int capacity) {
            step = RND.nextInt(capacity - 2) + 1;
            while (IntegerUtils.gcd(step, capacity) != 1) {
                step++;
            }
        }


        public IntIterator intIterator() {
            return new IntIterator() {
                private int position = size == 0 ? values.length : -1;

                public int value() throws NoSuchElementException {
                    if (position == -1) {
                        advance();
                    }
                    if (position >= values.length) {
                        throw new NoSuchElementException();
                    }
                    if ((present[position] & id1) == 0) {
                        throw new IllegalStateException();
                    }
                    return values[position];
                }

                public boolean advance() throws NoSuchElementException {
                    if (position >= values.length) {
                        throw new NoSuchElementException();
                    }
                    position++;
                    while (position < values.length && (present[position] & id1) == 0) {
                        position++;
                    }
                    return isValid();
                }

                public boolean isValid() {
                    return position < values.length;
                }

                public void remove() {
                    if ((present[position] & id1) == 0) {
                        throw new IllegalStateException();
                    }
                    present[position] = id5;
                }
            };
        }


        public int size() {
            return size;
        }


        public void add(int value) {
            ensureCapacity((realSize + 1) * ratio + 2);
            int current = getHash(value);
            while (present[current] != 0) {
                if ((present[current] & id1) != 0 && values[current] == value) {
                    return;
                }
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            while ((present[current] & id1) != 0) {
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            if (present[current] == 0) {
                realSize++;
            }
            present[current] = id1;
            values[current] = value;
            size++;
        }

        private int getHash(int value) {
            int hash = IntHash.hash(value);
            int result = hash;
            for (int i : id9) {
                result ^= hash >> i;
            }
            result %= values.length;
            if (result < 0) {
                result += values.length;
            }
            return result;
        }

        private void ensureCapacity(int capacity) {
            if (values.length < capacity) {
                capacity = Math.max(capacity * 2, values.length);
                rebuild(capacity);
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
                if ((oldPresent[i] & id1) == id1) {
                    add(oldValues[i]);
                }
            }
        }


        public boolean contains(int value) {
            int current = getHash(value);
            while (present[current] != 0) {
                if (values[current] == value && (present[current] & id1) != 0) {
                    return true;
                }
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            return false;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id16 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void id11(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
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

        public long readLong() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id16 {
            public boolean id3(int ch);

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

    static abstract class id4 implements IntStream {

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

    static interface IntSet extends IntCollection {
    }

    static class IntArray extends id4 implements IntList {
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

    static interface IntList extends id12 {
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

    static class IntegerUtils {
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

        public static int[] id15(int upTo) {
            int[] isPrime = id2(upTo);
            IntList primes = new id13();
            for (int i = 0; i < upTo; i++) {
                if ((isPrime[i >> 5] >>> (i & 31) & 1) == 1) {
                    primes.add(i);
                }
            }
            return primes.toArray();
        }

        public static int[] id2(int upTo) {
            int[] isPrime = new int[(upTo + 31) >> 5];
            if (upTo < 2) {
                return isPrime;
            }
            Arrays.fill(isPrime, -1);
            isPrime[0] &= -4;
            for (int i = 2; i * i < upTo; i++) {
                if ((isPrime[i >> 5] >>> (i & 31) & 1) == 1) {
                    for (int j = i * i; j < upTo; j += i) {
                        isPrime[j >> 5] &= -1 - (1 << (j & 31));
                    }
                }
            }
            return isPrime;
        }

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

    static interface LongList extends id10 {
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

    static interface id10 extends LongCollection {
    }

    static class IntHash {
        private IntHash() {
        }

        public static int hash(int c) {
            return c;
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

    static interface LongIterator {
        public long value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }
}

