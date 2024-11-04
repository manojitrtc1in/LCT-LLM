import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            CDigitTree solver = new CDigitTree();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CDigitTree {
        Modular mod;
        int[] pow;
        int[] inv;
        long cnt = 0;
        IntegerHashMap hm = new IntegerHashMap((int) 1e5, false);
        List<Node> trace = new ArrayList<>((int) 1e5);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            mod = new Modular(m);
            pow = new int[n + 1];
            inv = new int[n + 1];
            pow[0] = inv[0] = 1;
            pow[1] = mod.valueOf(10);
            inv[1] = new Power(mod).inverse(pow[1]);
            for (int i = 2; i <= n; i++) {
                pow[i] = mod.mul(pow[i - 1], pow[1]);
                inv[i] = mod.mul(inv[i - 1], inv[1]);
            }


            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            for (int i = 0; i < n - 1; i++) {
                Node a = nodes[in.readInt()];
                Node b = nodes[in.readInt()];
                Edge e = new Edge();
                e.a = a;
                e.b = b;
                e.digit = in.readInt();
                a.adj.add(e);
                b.adj.add(e);
            }

            dac(nodes[0]);
            out.println(cnt);
        }

        public void findSize(Node root, Edge p) {
            root.size = 1;
            for (Edge e : root.adj) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                findSize(node, e);
                root.size += node.size;
            }
        }

        public Node findCentroid(Node root, Edge p, int total) {
            int max = total - root.size;
            for (Edge e : root.adj) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                Node ans = findCentroid(node, e, total);
                if (ans != null) {
                    return ans;
                }
                max = Math.max(max, node.size);
            }
            if (max * 2 <= total) {
                return root;
            }
            return null;
        }

        public void trace(Node root, Edge p) {
            Node top = p.other(root);
            root.depth = top.depth + 1;
            root.down = mod.mul(top.down, 10);
            root.down = mod.plus(root.down, p.digit);
            root.up = mod.mul(p.digit, pow[root.depth - 1]);
            root.up = mod.plus(root.up, top.up);

            trace.add(root);
            for (Edge e : root.adj) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                trace(node, e);
            }
        }

        public void dac(Node root) {
            if (root.adj.isEmpty()) {
                return;
            }
            findSize(root, null);
            root = findCentroid(root, null, root.size);
            root.up = root.down = 0;
            root.depth = 0;
            hm.clear();
            hm.put(root.up, 1);
            for (Edge e : root.adj) {
                trace.clear();
                trace(e.other(root), e);
                

                for (Node node : trace) {
                    node.down = mod.mul(node.down, inv[node.depth]);
                    cnt += hm.getOrDefault(mod.valueOf(-node.down), 0);
                }
                for (Node node : trace) {
                    hm.put(node.up, hm.getOrDefault(node.up, 0) + 1);
                }
            }

            SequenceUtils.reverse(root.adj);
            hm.clear();
            for (Edge e : root.adj) {
                trace.clear();
                trace(e.other(root), e);
                

                for (Node node : trace) {
                    node.down = mod.mul(node.down, inv[node.depth]);
                    cnt += hm.getOrDefault(mod.valueOf(-node.down), 0);
                }
                for (Node node : trace) {
                    hm.put(node.up, hm.getOrDefault(node.up, 0) + 1);
                }
            }
            cnt += hm.getOrDefault(mod.valueOf(-root.down), 0);

            for (Edge e : root.adj) {
                Node node = e.other(root);
                node.adj.remove(e);
                dac(node);
            }
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

    static interface IntegerEntryIterator {
        boolean hasNext();

        void next();

        int getEntryKey();

        int getEntryValue();

    }

    static class Hasher {
        private long time = System.nanoTime() + System.currentTimeMillis() * 31L;

        public int shuffle(long z) {
            z += time;
            z = (z ^ (z >>> 33)) * 0x62a9d9ed799705f5L;
            return (int) (((z ^ (z >>> 28)) * 0xcb24d0a5c88c35b3L) >>> 32);
        }

        public int hash(int x) {
            return shuffle(x);
        }

    }

    static class IntegerHashMap {
        private int now;
        private int[] slot;
        private int[] version;
        private int[] next;
        private int[] keys;
        private int[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;
        private Hasher hasher = new Hasher();

        public IntegerHashMap(int cap, boolean rehash) {
            now = 1;
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            version = new int[slot.length];
            next = new int[cap + 1];
            keys = new int[cap + 1];
            values = new int[cap + 1];
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
            int[] newVersions = new int[newSlots.length];
            int newMask = newSlots.length - 1;
            for (int i = 0; i < slot.length; i++) {
                access(i);
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
            this.version = newVersions;
            now = 0;
            this.mask = newMask;
        }

        private int hash(int x) {
            return hasher.hash(x);
        }

        public void put(int x, int y) {
            put(x, y, true);
        }

        public void put(int x, int y, boolean cover) {
            int h = hash(x);
            int s = h & mask;
            access(s);
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

        public int getOrDefault(int x, int def) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        private int findIndexOrLastEntry(int s, int x) {
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

        public void clear() {
            alloc = 0;
            size = 0;
            now++;
        }

        private void access(int i) {
            if (version[i] != now) {
                version[i] = now;
                slot[i] = 0;
            }
        }

        public IntegerEntryIterator iterator() {
            return new IntegerEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public int getEntryKey() {
                    return keys[readIndex];
                }


                public int getEntryValue() {
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
            IntegerEntryIterator iterator = iterator();
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

    static class ExtGCD {
        public static int extGCD(int a, int b, int[] xy) {
            if (a >= b) {
                return extGCD0(a, b, xy);
            }
            int ans = extGCD0(b, a, xy);
            SequenceUtils.swap(xy, 0, 1);
            return ans;
        }

        private static int extGCD0(int a, int b, int[] xy) {
            if (b == 0) {
                xy[0] = 1;
                xy[1] = 0;
                return a;
            }
            int ans = extGCD0(b, a % b, xy);
            int x = xy[0];
            int y = xy[1];
            xy[0] = y;
            xy[1] = x - a / b * y;
            return ans;
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

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(long c) {
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

    static class Node {
        int id;
        List<Edge> adj = new ArrayList<>();
        int size;
        int up;
        int down;
        int depth;

        public String toString() {
            return "" + (id);
        }

    }

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

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

    static interface InverseNumber {
    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> void swap(List<T> data, int i, int j) {
            T tmp = data.get(i);
            data.set(i, data.get(j));
            data.set(j, tmp);
        }

        public static <T> void reverse(List<T> data, int l, int r) {
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

        public static <T> void reverse(List<T> data) {
            reverse(data, 0, data.size() - 1);
        }

    }

    static class IntExtGCDObject {
        private int[] xy = new int[2];

        public int extgcd(int a, int b) {
            return ExtGCD.extGCD(a, b, xy);
        }

        public int getX() {
            return xy[0];
        }

    }

    static class Edge {
        Node a;
        Node b;
        int digit;

        Node other(Node x) {
            return a == x ? b : a;
        }

    }

    static class Power implements InverseNumber {
        static IntExtGCDObject extGCD = new IntExtGCDObject();
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int inverse(int x) {
            int ans = inverseExtGCD(x);






            return ans;
        }

        public int inverseExtGCD(int x) {
            if (extGCD.extgcd(x, modular.getMod()) != 1) {
                throw new IllegalArgumentException();
            }
            return modular.valueOf(extGCD.getX());
        }

    }
}

