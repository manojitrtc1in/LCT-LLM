import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            FClassical solver = new FClassical();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FClassical {
        int limit = 100000;
        MultiWayIntegerStack divisors = Factorization.factorizeRange(limit);
        MultiplicativeFunctionSieve sieve = new MultiplicativeFunctionSieve(limit, true, false, false);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();

            IntegerList list = new IntegerList(n);
            for (int i = 0; i < n; i++) {
                list.add(in.readInt());
            }
            list.unique();
            MultiWayIntegerDeque multiple = new MultiWayIntegerDeque(limit + 1, 20 * limit);
            for (int i = 0; i < list.size(); i++) {
                int x = list.get(i);
                for (IntegerIterator iterator = divisors.iterator(x); iterator.hasNext(); ) {
                    int divisor = iterator.next();
                    multiple.addLast(divisor, x / divisor);
                }
            }

            IntegerVersionArray iva = new IntegerVersionArray(limit + 1);
            IntegerDeque stack = new IntegerDequeImpl(n);
            long ans = list.tail();
            for (int i = 1; i <= limit; i++) {
                iva.clear();
                while (!multiple.isEmpty(i)) {
                    int last = multiple.removeLast(i);
                    int cop = countCoPrime(iva, last);
                    int pop = 0;
                    while (cop > 0) {
                        pop = stack.removeLast();
                        remove(iva, pop);
                        if (GCDs.gcd(pop, last) == 1) {
                            cop--;
                        }
                    }
                    ans = Math.max(ans, LCMs.lcm(pop, last) * i);
                    add(iva, last);
                    stack.addLast(last);
                }
            }

            out.println(ans);
        }

        public int countCoPrime(IntegerVersionArray iva, int x) {
            int ans = 0;
            for (IntegerIterator iterator = divisors.iterator(x); iterator.hasNext(); ) {
                int divisor = iterator.next();
                ans += iva.get(divisor) * sieve.mobius[divisor];
            }
            return ans;
        }

        public void add(IntegerVersionArray iva, int x) {
            for (IntegerIterator iterator = divisors.iterator(x); iterator.hasNext(); ) {
                int divisor = iterator.next();
                iva.inc(divisor);
            }
        }

        public void remove(IntegerVersionArray iva, int x) {
            for (IntegerIterator iterator = divisors.iterator(x); iterator.hasNext(); ) {
                int divisor = iterator.next();
                iva.dec(divisor);
            }
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class MultiWayIntegerDeque {
        private int[] values;
        private int[] next;
        private int[] prev;
        private int[] heads;
        private int[] tails;
        private int alloc;
        private int queueNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            prev = Arrays.copyOf(prev, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public MultiWayIntegerDeque(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            prev = new int[totalCapacity + 1];
            heads = new int[qNum];
            tails = new int[qNum];
            queueNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[tails[qId]] = alloc;
            prev[alloc] = tails[qId];
            tails[qId] = alloc;
        }

        public int removeLast(int qId) {
            int ans = values[tails[qId]];
            if (heads[qId] == tails[qId]) {
                heads[qId] = tails[qId] = 0;
            } else {
                tails[qId] = prev[tails[qId]];
                next[tails[qId]] = 0;
            }
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }

    static class MultiplicativeFunctionSieve {
        public int[] primes;
        public boolean[] isComp;
        public int primeLength;
        public int[] mobius;
        public int[] euler;
        public int[] factors;
        public int[] smallestPrimeFactor;
        public int[] numberOfSmallestPrimeFactor;

        public MultiplicativeFunctionSieve(int limit, boolean enableMobius, boolean enableEuler, boolean enableFactors) {
            isComp = new boolean[limit + 1];
            primes = new int[limit + 1];
            numberOfSmallestPrimeFactor = new int[limit + 1];
            smallestPrimeFactor = new int[limit + 1];
            primeLength = 0;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    primes[primeLength++] = i;
                    numberOfSmallestPrimeFactor[i] = smallestPrimeFactor[i] = i;
                }
                for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                    int pi = primes[j] * i;
                    smallestPrimeFactor[pi] = primes[j];
                    numberOfSmallestPrimeFactor[pi] = smallestPrimeFactor[i] == primes[j]
                            ? (numberOfSmallestPrimeFactor[i] * numberOfSmallestPrimeFactor[primes[j]])
                            : numberOfSmallestPrimeFactor[primes[j]];
                    isComp[pi] = true;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }

            if (enableMobius) {
                mobius = new int[limit + 1];
                mobius[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        mobius[i] = -1;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] != smallestPrimeFactor[i]) {
                            mobius[i] = 0;
                        } else {
                            mobius[i] = mobius[numberOfSmallestPrimeFactor[i]] * mobius[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }

            if (enableEuler) {
                euler = new int[limit + 1];
                euler[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        euler[i] = i - 1;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] == i) {
                            euler[i] = i - i / smallestPrimeFactor[i];
                        } else {
                            euler[i] = euler[numberOfSmallestPrimeFactor[i]] * euler[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }

            if (enableFactors) {
                factors = new int[limit + 1];
                factors[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        factors[i] = 2;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] == i) {
                            factors[i] = 1 + factors[i / smallestPrimeFactor[i]];
                        } else {
                            factors[i] = factors[numberOfSmallestPrimeFactor[i]]
                                    * factors[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }
        }

    }

    static class MultiWayIntegerStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public MultiWayIntegerStack(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }

    static class IntegerVersionArray {
        int[] data;
        int[] version;
        int now;
        int def;

        public IntegerVersionArray(int cap) {
            this(cap, 0);
        }

        public IntegerVersionArray(int cap, int def) {
            data = new int[cap];
            version = new int[cap];
            now = 0;
            this.def = def;
        }

        public void clear() {
            now++;
        }

        public void visit(int i) {
            if (version[i] < now) {
                version[i] = now;
                data[i] = def;
            }
        }

        public int get(int i) {
            visit(i);
            return data[i];
        }

        public int inc(int i) {
            visit(i);
            return ++data[i];
        }

        public int dec(int i) {
            visit(i);
            return --data[i];
        }

    }

    static class GCDs {
        private GCDs() {
        }

        public static long gcd(long a, long b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static long gcd0(long a, long b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

        public static int gcd(int a, int b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static int gcd0(int a, int b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

    }

    static interface IntegerStack {
        void addLast(int x);

        int removeLast();

    }

    static class LCMs {
        private LCMs() {
        }

        public static long lcm(long x, long y) {
            return x / GCDs.gcd(x, y) * y;
        }

    }

    static class SequenceUtils {
        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }

    static interface IntegerDeque extends IntegerStack {
    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException("index " + i + " out of range");
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.shuffle(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public int tail() {
            checkRange(0);
            return data[size - 1];
        }

        public void unique() {
            if (size <= 1) {
                return;
            }

            sort();
            int wpos = 1;
            for (int i = 1; i < size; i++) {
                if (data[i] != data[wpos - 1]) {
                    data[wpos++] = data[i];
                }
            }
            size = wpos;
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static class Factorization {
        public static MultiWayIntegerStack factorizeRange(int n) {
            int size = 0;
            for (int i = 1; i <= n; i++) {
                size += n / i;
            }
            MultiWayIntegerStack stack = new MultiWayIntegerStack(n + 1, size);
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j += i) {
                    stack.addLast(j, i);
                }
            }
            return stack;
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class Randomized {
        private static Random random = new Random();

        public static void shuffle(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(long c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntegerDequeImpl.this.next(index);
                    return ans;
                }
            };
        }

        public int removeLast() {
            int ans = data[last(epos)];
            epos = last(epos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        private int last(int x) {
            return (x == 0 ? n : x) - 1;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }
}

