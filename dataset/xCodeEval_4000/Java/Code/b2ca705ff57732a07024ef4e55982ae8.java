import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.function.IntUnaryOperator;
import java.util.Random;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            DTimofeyAndAFlatTree solver = new DTimofeyAndAFlatTree();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DTimofeyAndAFlatTree {
        Debug debug = new Debug(true);
        HashData[] hds;
        PartialHash[] phs;
        long mask = (1L << 32) - 1;
        int vertex = -1;
        int vertexVal = -1;
        LongHashMap map = new LongHashMap((int) 2e6, true);
        int nonZeroCnt = 0;
        Hasher hasher = new Hasher();

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 0; i < n - 1; i++) {
                Node a = nodes[in.readInt() - 1];
                Node b = nodes[in.readInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }

            for (int i = 0; i < 1; i++) {
                hds = new HashData[]{new HashData((int) 1e5, (int) 1e9 + 7, RandomWrapper.INSTANCE.nextInt(3, (int) (1e9 + 6))), new HashData((int) 1e5, (int) 1e9 + 7, RandomWrapper.INSTANCE.nextInt(3, (int) (1e9 + 6)))};
                phs = new PartialHash[]{new PartialHash(hds[0]), new PartialHash(hds[1])};
                nonZeroCnt = 0;
                dfsForHash(nodes[0], null);
                dfsForVertex(nodes[0], null, 0);
            }


            debug.debug("vertexVal", vertexVal);
            out.println(vertex + 1);
        }

        public int hashLong(long x) {
            return hasher.hash(x);
        }

        public void update(int vertex) {
            if (nonZeroCnt > vertexVal) {
                vertexVal = nonZeroCnt;
                this.vertex = vertex;
            }
        }

        public void add(long x) {
            long val = map.get(x);
            map.put(x, val + 1);
            if (val == 0) {
                nonZeroCnt++;
            }
        }

        public void remove(long x) {
            long val = map.get(x);
            map.put(x, val - 1);
            if (val == 1) {
                nonZeroCnt--;
            }
        }

        public int hashWithout(int h, int i, int l, int r) {
            int left = phs[h].hash(l, i - 1, false);
            int right = phs[h].hash(i + 1, r, false);
            int leftSize = i - l;
            int rightSize = r - i;
            right = hds[h].mod.mul(right, hds[h].pow[leftSize]);
            int ans = hds[h].mod.plus(left, right);
            ans = hds[h].mod.plus(ans, hds[h].pow[leftSize + rightSize]);
            return ans;
        }

        public void dfsForHash(Node root, Node p) {
            root.hash = new LongArrayList(root.adj.size());
            for (Node node : root.adj) {
                if (node == p) {
                    continue;
                }
                dfsForHash(node, root);
                root.hash.add(node.hashVal);
            }
            root.hash.sort();
            phs[0].populate(i -> hashLong(root.hash.get(i)), 0, root.hash.size() - 1);
            phs[1].populate(i -> hashLong(root.hash.get(i)), 0, root.hash.size() - 1);
            for (PartialHash ph : phs) {
                root.hashVal = (root.hashVal << 32) | (ph.hash(0, root.hash.size() - 1, true) & mask);
            }
            add(root.hashVal);
        }

        public void dfsForVertex(Node root, Node p, long pHash) {
            if (p != null) {
                root.hash.add(pHash);
            }

            long original = root.hashVal;
            root.hash.sort();
            root.hashVal = 0;
            phs[0].populate(i -> hashLong(root.hash.get(i)), 0, root.hash.size() - 1);
            phs[1].populate(i -> hashLong(root.hash.get(i)), 0, root.hash.size() - 1);
            for (PartialHash ph : phs) {
                root.hashVal = (root.hashVal << 32) | (ph.hash(0, root.hash.size() - 1, true) & mask);
            }

            remove(original);
            add(root.hashVal);
            update(root.id);

            for (Node node : root.adj) {
                if (node == p) {
                    continue;
                }
                node.mark = 0;
                int index = root.hash.binarySearch(node.hashVal);
                for (int i = 0; i < 2; i++) {
                    node.mark = (node.mark << 32) | (hashWithout(i, index, 0, root.hash.size() - 1) & mask);
                }
            }

            remove(root.hashVal);
            for (Node node : root.adj) {
                if (node == p) {
                    continue;
                }
                add(node.mark);
                dfsForVertex(node, root, node.mark);
                remove(node.mark);
            }
            add(original);
        }

    }

    static class PartialHash {
        HashData hd;
        int[] hash;

        public PartialHash(HashData hd) {
            this.hd = hd;
            hash = new int[hd.pow.length];
        }

        public void populate(IntUnaryOperator function, int l, int r) {
            if (l > r) {
                return;
            }
            if (l > 0) {
                hash[l - 1] = 0;
            }
            hash[l] = hd.mod.mul(function.applyAsInt(l), hd.pow[l]);
            for (int i = l + 1; i <= r; i++) {
                hash[i] = hd.mod.valueOf(hash[i - 1] + hd.pow[i] * (long) function.applyAsInt(i));
            }
        }

        public int hash(int l, int r, boolean verbose) {
            if (l > r) {
                return verbose ? hd.pow[0] : 0;
            }
            long h = hash[r];
            if (l > 0) {
                h -= hash[l - 1];
                h *= hd.inv[l];
            }
            if (verbose) {
                h += hd.pow[r - l + 1];
            }
            return hd.mod.valueOf(h);
        }

    }

    static interface InverseNumber {
    }

    static class HashData {
        public Modular mod;
        public int[] inv;
        public int[] pow;

        public HashData(int n, int p, int x) {
            this.mod = new Modular(p);
            n = Math.max(n, 1);
            inv = new int[n + 1];
            pow = new int[n + 1];
            inv[0] = 1;
            pow[0] = 1;
            int invX = new Power(mod).inverseByFermat(x);
            for (int i = 1; i <= n; i++) {
                inv[i] = mod.mul(inv[i - 1], invX);
                pow[i] = mod.mul(pow[i - 1], x);
            }
        }

    }

    static class Randomized {
        public static void shuffle(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return RandomWrapper.INSTANCE.nextInt(l, r);
        }

    }

    static class SequenceUtils {
        public static boolean equal(long[] a, int al, int ar, long[] b, int bl, int br) {
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int highBit(long x) {
            return (int) (x >> 32);
        }

        public static int lowBit(long x) {
            return (int) x;
        }

    }

    static class Power implements InverseNumber {
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, int n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

        public int inverseByFermat(int x) {
            return pow(x, modular.m - 2);
        }

    }

    static class LongHashMap {
        private int[] slot;
        private int[] next;
        private long[] keys;
        private long[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;
        private Hasher hasher = new Hasher();

        public LongHashMap(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            values = new long[cap + 1];
            removed = new boolean[cap + 1];
            this.rehash = rehash;
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            keys = Arrays.copyOf(keys, newSize);
            values = Arrays.copyOf(values, newSize);
            removed = Arrays.copyOf(removed, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
            removed[alloc] = false;
            size++;
        }

        private void rehash() {
            int[] newSlots = new int[Math.max(16, slot.length * 2)];
            int newMask = newSlots.length - 1;
            for (int i = 0; i < slot.length; i++) {
                if (slot[i] == 0) {
                    continue;
                }
                int head = slot[i];
                while (head != 0) {
                    int n = next[head];
                    int s = hash(keys[head]) & newMask;
                    next[head] = newSlots[s];
                    newSlots[s] = head;
                    head = n;
                }
            }
            this.slot = newSlots;
            this.mask = newMask;
        }

        private int hash(long x) {
            return hasher.hash(x);
        }

        public void put(long x, long y) {
            put(x, y, true);
        }

        public void put(long x, long y, boolean cover) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                values[alloc] = y;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                    values[alloc] = y;
                } else if (cover) {
                    values[index] = y;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
        }

        public long getOrDefault(long x, long def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        public long get(long x) {
            return getOrDefault(x, 0);
        }

        private int findIndexOrLastEntry(int s, long x) {
            int iter = slot[s];
            while (keys[iter] != x) {
                if (next[iter] != 0) {
                    iter = next[iter];
                } else {
                    return iter;
                }
            }
            return iter;
        }

        public LongEntryIterator iterator() {
            return new LongEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public long getEntryKey() {
                    return keys[readIndex];
                }


                public long getEntryValue() {
                    return values[readIndex];
                }


                public void next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    readIndex = index;
                    index++;
                }
            };
        }

        public String toString() {
            LongEntryIterator iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.getEntryKey()).append("->").append(iterator.getEntryValue()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
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

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class LongArrayList implements Cloneable {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public LongArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public LongArrayList(LongArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public LongArrayList() {
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
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public long get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(long x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(long[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(LongArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.shuffle(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public int binarySearch(long x) {
            return Arrays.binarySearch(data, 0, size, x);
        }

        public int size() {
            return size;
        }

        public long[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof LongArrayList)) {
                return false;
            }
            LongArrayList other = (LongArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Long.hashCode(data[i]);
            }
            return h;
        }

        public LongArrayList clone() {
            LongArrayList ans = new LongArrayList();
            ans.addAll(this);
            return ans;
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

    static class Hasher {
        private int highQualityShuffle(long x) {
            int high = DigitUtils.highBit(x);
            int low = DigitUtils.lowBit(x);
            return (int) ((high * 31L + low) % (1e9 + 7));
        }

        public int hash(long x) {
            return highQualityShuffle(x);
        }

    }

    static class RandomWrapper {
        private Random random;
        public static final RandomWrapper INSTANCE = new RandomWrapper(new Random());

        public RandomWrapper() {
            this(new Random());
        }

        public RandomWrapper(Random random) {
            this.random = random;
        }

        public int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, int x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

    }

    static class Node {
        List<Node> adj = new ArrayList<>();
        LongArrayList hash;
        long hashVal;
        long mark;
        int id;

        public String toString() {
            return "" + (id + 1);
        }

    }

    static interface LongEntryIterator {
        boolean hasNext();

        void next();

        long getEntryKey();

        long getEntryValue();

    }
}

