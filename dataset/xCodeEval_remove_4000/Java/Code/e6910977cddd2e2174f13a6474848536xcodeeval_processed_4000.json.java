import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.function.IntFunction;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
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
            id0 solver = new id0();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id0 {
        Debug debug = new Debug(true);
        int order = 0;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int rootV = in.readInt();
            int q = in.readInt();
            int[][] qs = new int[q][3];
            List<Node> nodes = new ArrayList<>(q);
            nodes.add(new Node(nodes.size()));
            for (int i = 0; i < q; i++) {
                qs[i][0] = in.readInt();
                qs[i][1] = in.readInt();
                if (qs[i][0] == 1) {
                    qs[i][2] = in.readInt();
                    Node node = new Node(nodes.size());
                    nodes.add(node);
                    Node p = nodes.get(qs[i][1] - 1);
                    p.adj.add(node);
                }
            }

            dfs(nodes.get(0));
            debug.debug("nodes", nodes);

            int mod = (int) 1e9 + 7;
            Power pow = new Power(mod);

            SegTree<SumImpl, UpdateImpl> st = new SegTree<>(1, order, SumImpl::new,
                    UpdateImpl::new, i -> {
                SumImpl ans = new SumImpl();
                ans.path = 1;
                return ans;
            });
            debug.debug("st", st);
            UpdateImpl upd = new UpdateImpl();
            SumImpl sum1 = new SumImpl();
            SumImpl sum2 = new SumImpl();
            upd.mul = 1;
            upd.plus = rootV;
            st.update(1, 1, 1, order, upd);
            int lastNode = 0;
            int[] size = new int[nodes.size()];
            size[0]++;
            debug.debug("st", st);
            for (int[] query : qs) {
                if (query[0] == 1) {
                    lastNode++;
                    int p = query[1] - 1;
                    int v = query[2];
                    upd.plus = v;
                    upd.mul = 1;
                    size[lastNode]++;
                    st.update(nodes.get(lastNode).id5,
                            nodes.get(lastNode).id5,
                            1, order, upd);
                    upd.plus = 0;
                    upd.mul = (long) (size[p] + 1) * pow.inverse(size[p]) % mod;
                    st.update(nodes.get(p).id5,
                            nodes.get(p).id2, 1, order, upd);
                    size[p]++;
                } else {
                    Node node = nodes.get(query[1] - 1);
                    sum1.sum = 0;
                    sum1.path = 0;
                    st.query(node.id5, node.id2, 1, order, sum1);
                    sum2.sum = 0;
                    sum2.path = 0;
                    st.query(node.id5, node.id5, 1, order, sum2);
                    long ans = sum1.sum;
                    ans = ans * pow.inverse((int) sum2.path) % mod * size[node.id] % mod;
                    out.println(ans);
                }
                debug.debug("st", st);
            }
        }

        public void dfs(Node root) {
            root.id5 = ++order;
            for (Node node : root.adj) {
                dfs(node);
            }
            root.id2 = order;
        }

    }

    static class SumImpl implements Sum<SumImpl, UpdateImpl> {
        long path;
        long sum;
        static int mod = (int) 1e9 + 7;

        public void add(SumImpl right) {
            sum = DigitUtils.modplus(sum, right.sum, mod);
            path = DigitUtils.modplus(path, right.path, mod);
        }

        public void update(UpdateImpl update) {
            path = path * update.mul % mod;
            sum = (sum * update.mul + update.plus * path) % mod;
        }

        public void copy(SumImpl right) {
            sum = right.sum;
            path = right.path;
        }

        public SumImpl clone() {
            SumImpl s = new SumImpl();
            s.copy(this);
            return s;
        }

        public String toString() {
            return String.format("(%d, %d)", path, sum);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int id7 = 1 << 13;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(id7 * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < id7) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
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

    static class Power implements InverseNumber {
        static id10 id6 = new id10();
        int mod;

        public Power(Modular modular) {
            this.mod = modular.getMod();
        }

        public Power(int mod) {
            this(new Modular(mod));
        }

        public int inverse(int x) {
            int ans = id8(x);






            return ans;
        }

        public int id8(int x) {
            if (id6.id3(x, mod) != 1) {
                throw new IllegalArgumentException();
            }
            return DigitUtils.mod(id6.getX(), mod);
        }

    }

    static interface InverseNumber {
    }

    static interface Sum<S, U> extends Cloneable {
        void add(S s);

        void update(U u);

        void copy(S s);

        S clone();

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

        public String toString() {
            return "mod " + m;
        }

    }

    static abstract class id1<T> implements Cloneable {
        public T clone() {
            try {
                return (T) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }

    static class id10 {
        private int[] xy = new int[2];

        public int id3(int a, int b) {
            return id9.id6(a, b, xy);
        }

        public int getX() {
            return xy[0];
        }

    }

    static class SegTree<S extends Sum<S, U>, U extends Update<U>> implements Cloneable {
        private SegTree<S, U> left;
        private SegTree<S, U> right;
        public S sum;
        private U update;

        private void modify(U x) {
            update.update(x);
            sum.update(x);
        }

        private void pushDown() {
            if (update.ofBoolean()) {
                left.modify(update);
                right.modify(update);
                update.clear();
                assert !update.ofBoolean();
            }
        }

        private void pushUp() {
            sum.copy(left.sum);
            sum.add(right.sum);
        }

        public SegTree(int l, int r, Supplier<S> sSupplier, Supplier<U> uSupplier,
                       IntFunction<S> func) {
            update = uSupplier.get();
            update.clear();
            if (l < r) {
                sum = sSupplier.get();
                int m = DigitUtils.floorAverage(l, r);
                left = new SegTree<>(l, m, sSupplier, uSupplier, func);
                right = new SegTree<>(m + 1, r, sSupplier, uSupplier, func);
                pushUp();
            } else {
                sum = func.apply(l);
            }
        }

        private boolean cover(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean leave(int ll, int rr, int l, int r) {
            return rr < l || ll > r;
        }

        public void update(int ll, int rr, int l, int r, U u) {
            if (leave(ll, rr, l, r)) {
                return;
            }
            if (cover(ll, rr, l, r)) {
                modify(u);
                return;
            }
            int m = DigitUtils.floorAverage(l, r);
            pushDown();
            left.update(ll, rr, l, m, u);
            right.update(ll, rr, m + 1, r, u);
            pushUp();
        }

        public void query(int ll, int rr, int l, int r, S s) {
            if (leave(ll, rr, l, r)) {
                return;
            }
            if (cover(ll, rr, l, r)) {
                s.add(sum);
                return;
            }
            int m = DigitUtils.floorAverage(l, r);
            pushDown();
            left.query(ll, rr, l, m, s);
            right.query(ll, rr, m + 1, r, s);
        }

        public SegTree<S, U> deepClone() {
            SegTree<S, U> clone = clone();
            clone.sum = clone.sum.clone();
            clone.update = clone.update.clone();
            if (clone.left != null) {
                clone.left = clone.left.deepClone();
                clone.right = clone.right.deepClone();
            }
            return clone;
        }

        public void visitLeave(Consumer<SegTree<S, U>> consumer) {
            if (left == null) {
                consumer.accept(this);
                return;
            }
            pushDown();
            left.visitLeave(consumer);
            right.visitLeave(consumer);
        }

        public String toString() {
            StringBuilder ans = new StringBuilder();
            deepClone().visitLeave(x -> ans.append(x.sum).append(' '));
            return ans.toString();
        }

        public SegTree<S, U> clone() {
            try {
                return (SegTree<S, U>) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new UnsupportedOperationException(e);
            }
        }

    }

    static class UpdateImpl extends id1<UpdateImpl> implements Update<UpdateImpl> {
        long plus;
        long mul;
        static int mod = (int) 1e9 + 7;

        public void update(UpdateImpl update) {
            plus = plus * update.mul % mod;
            mul = mul * update.mul % mod;
            plus = DigitUtils.modplus(plus, update.plus, mod);
        }

        public void clear() {
            plus = 0;
            mul = 1;
        }

        public boolean ofBoolean() {
            return !(mul == 1 && plus == 0);
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, Object x) {
            return debug(name, x, empty);
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (x == null || !x.getClass().isArray()) {
                    out.append(name);
                    for (int i : indexes) {
                        out.printf("[%d]", i);
                    }
                    out.append("=").append("" + x);
                    out.println();
                } else {
                    indexes = Arrays.copyOf(indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(int x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static long modplus(long a, long b, long mod) {
            long ans = a + b;
            if (ans >= mod) {
                ans -= mod;
            }
            return ans;
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }

    static class Node {
        List<Node> adj = new ArrayList<>();
        int id;
        int id5;
        int id2;

        public Node(int id) {
            this.id = id;
        }

        public String toString() {
            return String.format("(%d, %d, %d)", id + 1, id5, id2);
        }

    }

    static class id9 {
        public static int id6(int a, int b, int[] xy) {
            if (a >= b) {
                return id4(a, b, xy);
            }
            int ans = id4(b, a, xy);
            SequenceUtils.swap(xy, 0, 1);
            return ans;
        }

        private static int id4(int a, int b, int[] xy) {
            if (b == 0) {
                xy[0] = 1;
                xy[1] = 0;
                return a;
            }
            int ans = id4(b, a % b, xy);
            int x = xy[0];
            int y = xy[1];
            xy[0] = y;
            xy[1] = x - a / b * y;
            return ans;
        }

    }

    static interface Update<U extends Update<U>> extends Cloneable {
        void update(U u);

        void clear();

        boolean ofBoolean();

        U clone();

    }
}

