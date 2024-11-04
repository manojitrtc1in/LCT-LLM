import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.UncheckedIOException;
import java.util.Objects;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.util.Map.Entry;
import java.io.Writer;
import java.util.Comparator;
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
            id5 solver = new id5();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id5 {
        id12 id21 = new id12();
        id20 id14 = new id20();
        long inf = (long) 1e18;
        LongList collector = new LongList(30000);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int t = in.readInt();
            Query[] queries = new Query[t];
            for (int i = 0; i < t; i++) {
                queries[i] = new Query();
                queries[i].n = in.readLong();
                queries[i].k = in.readLong();
            }
            Map<Long, List<Query>> map = Arrays.stream(queries).collect(Collectors.groupingBy(a -> a.k));
            for (Map.Entry<Long, List<Query>> entry : map.entrySet()) {
                handle(entry.getKey(), entry.getValue());
            }

            for (Query q : queries) {
                out.println(q.ans ? "YES" : "NO");
            }
        }

        public void handle(long k, List<Query> queries) {
            Map<Long, Long> id18 = id21.id7(k, true);
            long[][] pairs = id18.entrySet().stream().map(x -> new long[]{x.getKey(), x.getValue()})
                    .toArray(n -> new long[n][]);

            if (pairs.length == 0) {
                for (Query q : queries) {
                    q.ans = false;
                }
                return;
            }
            if (pairs.length == 1) {
                for (Query q : queries) {
                    q.ans = q.n % pairs[0][0] == 0;
                }
                return;
            }

            if (pairs.length == 2) {
                id13 modular = new id6(pairs[1][0]);
                for (Query q : queries) {
                    long g = id14.id3(pairs[0][0], pairs[1][0]);
                    if (q.n % g != 0) {
                        q.ans = false;
                        continue;
                    }
                    long x = modular.mul(id14.getX(), modular.valueOf(q.n));
                    q.ans = !DigitUtils.id19(x, pairs[0][0], q.n);
                }
                return;
            }

            collector.clear();
            id2(collector, pairs, 0, 1);
            collector.remove(collector.indexOf(1));
            collector.unique();
            long[] allFactors = collector.getData();
            int m = collector.size();
            int min = (int) allFactors[0];
            

            Node[] nodes = new Node[min];
            id11<Node> heap = id11.NIL;
            for (int i = 0; i < min; i++) {
                nodes[i] = new Node();
                nodes[i].remain = i;
                nodes[i].dist = i == 0 ? 0 : inf;
                nodes[i].heap = new id11<>(nodes[i]);
                heap = id11.merge(heap, nodes[i].heap, Node.id9);
            }
            

            

            while (!id11.isEmpty(heap)) {
                Node node = id11.peek(heap);
                heap = id11.pop(heap, Node.id9);
                for (int i = 0; i < m; i++) {
                    long d = allFactors[i];
                    Node next = nodes[DigitUtils.mod(node.remain + d, min)];
                    if (next.dist <= node.dist + d) {
                        continue;
                    }
                    

                    next.dist = node.dist + d;
                    

                    heap = id11.decrease(heap, next.heap, next, Node.id9);
                }
            }

            for (Query q : queries) {
                Node node = nodes[DigitUtils.mod(q.n, min)];
                q.ans = node.dist <= q.n;
            }
        }

        private void id2(LongList list, long[][] pairs, int i, long val) {
            if (i == pairs.length) {
                list.add(val);
                return;
            }
            for (long t = 1; ; t *= pairs[i][0]) {
                id2(list, pairs, i + 1, val * t);
                if (t >= pairs[i][1]) {
                    break;
                }
            }
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

        public FastOutput println(String c) {
            cache.append(c).append('\n');
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

    static class Query {
        long n;
        long k;
        boolean ans;

    }

    static interface id13 {
        long plus(long a, long b);

        long valueOf(long x);

        long mul(long a, long b);

    }

    static class id11<T> implements Cloneable {
        public static final id11 NIL = new id11(null);
        id11<T> father = NIL;
        id11<T> prev = NIL;
        id11<T> next = NIL;
        id11<T> children = NIL;
        private T val;

        static {
            NIL.children = NIL.prev = NIL.next = NIL.children;
        }

        public id11(T val) {
            this.val = val;
        }

        private static <T> void detach(id11<T> father, id11<T> child) {
            if (father == NIL || child == NIL) {
                return;
            }

            child.prev.next = child.next;
            child.next.prev = child.prev;

            if (child.next == child) {
                father.children = NIL;
            } else if (father.children == child) {
                father.children = child.next;
            }
            child.next = child.prev = child.father = NIL;
        }

        private static <T> void attach(id11<T> father, id11<T> child) {
            if (father == NIL || child == NIL) {
                return;
            }

            if (father.children == NIL) {
                child.prev = child.next = child;
                child.father = father;
                father.children = child;
                return;
            }
            child.prev = father.children;
            child.next = father.children.next;
            child.prev.next = child;
            child.next.prev = child;
            child.father = father;
        }

        public static <T> id11<T> merge(id11<T> a, id11<T> b, Comparator<T> comp) {
            if (a == NIL) {
                return b;
            }
            if (b == NIL) {
                return a;
            }
            if (comp.compare(a.val, b.val) > 0) {
                id11<T> tmp = a;
                a = b;
                b = tmp;
            }
            attach(a, b);
            return a;
        }

        public static <T> T peek(id11<T> root) {
            return root.val;
        }

        public static <T> id11<T> decrease(id11<T> root, id11<T> node,
                                                  T val, Comparator<T> comp) {
            if (root == node) {
                root.val = val;
                return root;
            }
            detach(node.father, node);
            node.val = val;
            return merge(root, node, comp);
        }

        private static <T> id11<T> id16(id11<T> head, Comparator<T> comp) {
            id11<T> loop = head;
            loop.father = NIL;
            loop.father.children = NIL;
            for (id11<T> i = loop.next; i != loop; i = i.next) {
                loop.father = NIL;
            }

            id11<T> begin = loop;
            id11<T> end = begin.prev;
            end.next = NIL;

            while (begin.next != NIL) {
                id11<T> next = begin.next.next;
                id11<T> m = merge(begin, begin.next, comp);
                m.next = NIL;
                begin = next;
                if (begin == NIL) {
                    begin = end = m;
                } else {
                    end.next = m;
                    end = m;
                }
            }
            begin.prev = begin.next = NIL;
            return begin;
        }

        public static <T> id11<T> pop(id11<T> root, Comparator<T> comp) {
            if (root.children == NIL) {
                return NIL;
            }
            return id16(root.children, comp);
        }

        public static <T> boolean isEmpty(id11<T> root) {
            return root == NIL;
        }

        public id11<T> clone() {
            id11<T> ans = new id11<>(this.val);
            if (children == NIL) {
                return ans;
            }
            attach(ans, children.clone());
            for (id11<T> i = children.next; i != children; i = i.next) {
                attach(ans, i.clone());
            }
            return ans;
        }

        public String toString() {
            return Objects.toString(val);
        }

    }

    static class id15 {
        private id15() {
        }

        public static long gcd(long a, long b) {
            return a >= b ? id17(a, b) : id17(b, a);
        }

        private static long id17(long a, long b) {
            return b == 0 ? a : id17(b, a % b);
        }

    }

    static class LongPower {
        final id13 modular;

        public LongPower(id13 modular) {
            this.modular = modular;
        }

        public long pow(long x, long n) {
            if (n == 0) {
                return 1;
            }
            long r = pow(x, n >> 1);
            r = modular.mul(r, r);
            if ((n & 1) == 1) {
                r = modular.mul(r, x);
            }
            return r;
        }

    }

    static class id6 implements id13 {
        final long m;

        public id6(long m) {
            this.m = m;
        }

        public long mul(long a, long b) {
            return DigitUtils.mulMod(a, b, m);
        }

        public long plus(long a, long b) {
            return valueOf(a + b);
        }

        public long valueOf(long a) {
            a %= m;
            if (a < 0) {
                a += m;
            }
            return a;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
        }

        public static boolean id19(long a, long b, long limit) {
            if (limit < 0) {
                limit = -limit;
            }
            if (a < 0) {
                a = -a;
            }
            if (b < 0) {
                b = -b;
            }
            if (a == 0 || b == 0) {
                return false;
            }
            

            return a > limit / b;
        }

        public static int mod(long x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return (int) x;
        }

        public static long mod(long x, long mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static long mulMod(long a, long b, long mod) {
            long k = DigitUtils.round((double) a / mod * b);
            return DigitUtils.mod(a * b - k * mod, mod);
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

    static class id12 {
        id4 mr = new id4();
        id13 modular;
        Random random = new Random();

        public long findFactor(long n, boolean danger) {
            if (mr.mr(n, 3)) {
                return n;
            }
            if (danger) {
                modular = new id6(n);
            } else {
                modular = new id8(n);
            }
            while (true) {
                long f = id0((long) (random.nextDouble() * n), (long) (random.nextDouble() * n), n);
                if (f != -1) {
                    return f;
                }
            }
        }

        private long id0(long x, long c, long n) {
            long xi = x;
            long xj = x;
            int j = 2;
            int i = 1;
            while (i < n) {
                i++;
                xi = modular.plus(modular.mul(xi, xi), c);
                long g = id15.gcd(n, Math.abs(xi - xj));
                if (g != 1 && g != n) {
                    return g;
                }
                if (i == j) {
                    j = j << 1;
                    xj = xi;
                }
            }
            return -1;
        }

        public Map<Long, Long> id7(long n, boolean danger) {
            Map<Long, Long> map = new HashMap();
            id7(map, n, danger);
            return map;
        }

        private void id7(Map<Long, Long> map, long n, boolean danger) {
            if (n == 1) {
                return;
            }
            long f = findFactor(n, danger);
            if (f == n) {
                Long value = map.get(f);
                if (value == null) {
                    value = 1L;
                }
                map.put(f, value * f);
                return;
            }
            id7(map, f, danger);
            id7(map, n / f, danger);
        }

    }

    static class id4 {
        id13 modular;
        LongPower power;
        Random random = new Random();

        public boolean mr(long n, int s) {
            return mr(n, s, false);
        }

        public boolean mr(long n, int s, boolean danger) {
            if (n <= 1) {
                return false;
            }
            if (n == 2) {
                return true;
            }
            if (n % 2 == 0) {
                return false;
            }
            if (danger) {
                modular = new id6(n);
            } else {
                modular = new id8(n);
            }
            power = new LongPower(modular);
            for (int i = 0; i < s; i++) {
                long x = (long) (random.nextDouble() * (n - 2) + 2);
                if (!mr0(x, n)) {
                    return false;
                }
            }
            return true;
        }

        private boolean mr0(long x, long n) {
            long exp = n - 1;
            while (true) {
                long y = power.pow(x, exp);
                if (y != 1 && y != n - 1) {
                    return false;
                }
                if (y != 1 || exp % 2 == 1) {
                    break;
                }
                exp = exp / 2;
            }
            return true;
        }

    }

    static class id20 {
        private long x;
        private long y;
        private long g;

        public long getX() {
            return x;
        }

        public long id3(long a, long b) {
            if (a >= b) {
                g = id1(a, b);
            } else {
                g = id1(b, a);
                long tmp = x;
                x = y;
                y = tmp;
            }
            return g;
        }

        private long id1(long a, long b) {
            if (b == 0) {
                x = 1;
                y = 0;
                return a;
            }
            long g = id1(b, a % b);
            long n = x;
            long m = y;
            x = m;
            y = n - m * (a / b);
            return g;
        }

    }

    static class Node {
        long dist;
        int remain;
        id11<Node> heap;
        static Comparator<Node> id9 = (a, b) -> a.dist == b.dist ? a.remain - b.remain : Long.compare(a.dist, b.dist);

    }

    static class id8 implements id13 {
        final long m;

        public id8(long m) {
            this.m = m;
        }

        public long mul(long a, long b) {
            return b == 0 ? 0 : ((mul(a, b >> 1) << 1) % m + a * (b & 1)) % m;
        }

        public long plus(long a, long b) {
            return valueOf(a + b);
        }

        public long valueOf(long a) {
            a %= m;
            if (a < 0) {
                a += m;
            }
            return a;
        }

    }

    static class LongList {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public LongList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public long[] getData() {
            return data;
        }

        public LongList(LongList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public LongList() {
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

        public void add(long x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public int indexOf(long x) {
            for (int i = 0; i < size; i++) {
                if (x == data[i]) {
                    return i;
                }
            }
            return -1;
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.id10(data, 0, size);
            Arrays.sort(data, 0, size);
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

        public long pop() {
            return data[--size];
        }

        public int size() {
            return size;
        }

        public void remove(int index) {
            checkRange(index);
            if (index == size - 1) {
                pop();
                return;
            }
            System.arraycopy(data, index + 1, data, index, size - index);
            size--;
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(data, size));
        }

    }

    static class Randomized {
        static Random random = new Random();

        public static void id10(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }
}

