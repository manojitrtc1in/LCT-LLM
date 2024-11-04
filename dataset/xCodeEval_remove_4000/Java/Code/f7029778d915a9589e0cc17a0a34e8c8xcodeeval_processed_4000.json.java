import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.function.LongBinaryOperator;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.io.OutputStreamWriter;
import java.util.function.IntFunction;
import java.io.OutputStream;
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
            id3 solver = new id3();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id3 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int q = in.readInt();

            id7 dec = new id7(Math::max, n, 0);
            for (int i = 0; i < n - 1; i++) {
                int u = in.readInt() - 1;
                int v = in.readInt() - 1;
                dec.addEdge(u, v);
            }

            long inf = (long) 1e18;

            int[] belong = new int[m];
            QueryObject qo = new QueryObject();
            for (int i = 0; i < m; i++) {
                int u = in.readInt() - 1;
                belong[i] = u;
                dec.id6(u, i + 1);
            }
            dec.finish();

            id0 list = new id0(n);
            for (int i = 0; i < q; i++) {
                int t = in.readInt();
                if (t == 1) {
                    int u = in.readInt() - 1;
                    int v = in.readInt() - 1;
                    int k = in.readInt();

                    list.clear();
                    while (k > 0) {
                        qo.reset();
                        dec.processPath(u, v, qo);
                        if (qo.val >= inf) {
                            break;
                        }
                        k--;
                        list.add(qo.index + 1);
                        dec.pop(belong[qo.index]);
                    }
                    out.println(list.size());
                    for (int j = 0; j < list.size(); j++) {
                        out.append(list.get(j)).append(' ');
                    }
                    out.println();
                } else {
                    int v = in.readInt() - 1;
                    int k = in.readInt();
                    dec.id5(v, k);
                }
            }


        }

    }

    static class id7 {
        private LongBinaryOperator op;
        int n;
        int order = 1;
        id7.id2 root;
        id7.id2[] nodes;
        id7.id2[] id8;
        id7.Segment segment;

        public id7(LongBinaryOperator op, int n, int rootId) {
            this.op = op;
            this.n = n;
            nodes = new id7.id2[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new id7.id2();
                nodes[i].id = i;
            }
            root = nodes[rootId];
        }

        public void id5(int u, long k) {
            segment.update(nodes[u].id1, nodes[u].id4, 1, n, k);
        }

        public void addEdge(int a, int b) {
            nodes[a].next.add(nodes[b]);
            nodes[b].next.add(nodes[a]);
        }

        public void id6(int nodeId, int val) {
            nodes[nodeId].pq.add(val);
        }

        public void pop(int nodeId) {
            id7.id2 node = nodes[nodeId];
            segment.updateRep(node.id1, node.id1, 1, n, node);
        }

        public void finish() {
            dfs(root, null);
            dfs2(root, root);
            id8 = new id7.id2[n + 1];
            for (int i = 0; i < n; i++) {
                id8[nodes[i].id1] = nodes[i];
            }
            segment = new id7.Segment(1, n, i -> id8[i]);
        }

        public void processPath(int uId, int vId, QueryObject qo) {
            id7.id2 u = nodes[uId];
            id7.id2 v = nodes[vId];
            while (u != v) {
                if (u.link == v.link) {
                    if (u.size > v.size) {
                        id7.id2 tmp = u;
                        u = v;
                        v = tmp;
                    }
                    segment.query(v.id1 + 1, u.id1, 1, n, qo);
                    u = v;
                } else {
                    if (u.link.size > v.link.size) {
                        id7.id2 tmp = u;
                        u = v;
                        v = tmp;
                    }
                    segment.query(u.link.id1, u.id1, 1, n, qo);
                    u = u.link.father;
                }
            }
            segment.query(u.id1, u.id1, 1, n, qo);
        }

        private static void dfs(id7.id2 root, id7.id2 father) {
            root.size = 1;
            root.father = father;
            for (id7.id2 node : root.next) {
                if (node == father) {
                    continue;
                }
                dfs(node, root);
                root.size += node.size;
                if (root.heavy == null || root.heavy.size < node.size) {
                    root.heavy = node;
                }
            }
        }

        private void dfs2(id7.id2 root, id7.id2 link) {
            root.id1 = order++;
            root.link = link;
            if (root.heavy != null) {
                dfs2(root.heavy, link);
            }
            for (id7.id2 node : root.next) {
                if (node == root.father || node == root.heavy) {
                    continue;
                }
                dfs2(node, node);
            }
            root.id4 = order - 1;
        }

        public static class Segment implements Cloneable {
            private id7.Segment left;
            private id7.Segment right;
            private long val;
            private long minVal;
            private int minIndex;
            private static long inf = (long) 1e18;

            public void pushUp() {
                minVal = Math.min(left.minVal, right.minVal);
                minIndex = minVal == left.minVal ? left.minIndex : right.minIndex;
            }

            public void modify(long x) {
                this.val += x;
                this.minVal += x;
            }

            public void pushDown() {
                if (val != 0) {
                    left.modify(val);
                    right.modify(val);
                    val = 0;
                }
            }

            public void replace(id7.id2 node) {
                if (node.pq.isEmpty()) {
                    minVal = inf;
                } else {
                    int top = node.pq.remove();
                    minVal = top + val;
                    minIndex = top - 1;
                }
            }

            public Segment(int l, int r, IntFunction<id7.id2> function) {
                if (l < r) {
                    int m = DigitUtils.floorAverage(l, r);
                    left = new id7.Segment(l, m, function);
                    right = new id7.Segment(m + 1, r, function);
                    pushUp();
                } else {
                    id7.id2 node = function.apply(l);
                    replace(node);
                }
            }

            private boolean covered(int ll, int rr, int l, int r) {
                return ll <= l && rr >= r;
            }

            private boolean noIntersection(int ll, int rr, int l, int r) {
                return ll > r || rr < l;
            }

            public void updateRep(int ll, int rr, int l, int r, id7.id2 x) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    replace(x);
                    return;
                }
                pushDown();
                int m = DigitUtils.floorAverage(l, r);
                left.updateRep(ll, rr, l, m, x);
                right.updateRep(ll, rr, m + 1, r, x);
                pushUp();
            }

            public void update(int ll, int rr, int l, int r, long x) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    modify(x);
                    return;
                }
                pushDown();
                int m = DigitUtils.floorAverage(l, r);
                left.update(ll, rr, l, m, x);
                right.update(ll, rr, m + 1, r, x);
                pushUp();
            }

            public void query(int ll, int rr, int l, int r, QueryObject qo) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    qo.update(minVal, minIndex);
                    return;
                }
                pushDown();
                int m = DigitUtils.floorAverage(l, r);
                left.query(ll, rr, l, m, qo);
                right.query(ll, rr, m + 1, r, qo);
            }

            private void toString(StringBuilder builder) {
                if (left == null && right == null) {
                    builder.append("val").append(",");
                    return;
                }
                pushDown();
                left.toString(builder);
                right.toString(builder);
            }

            public String toString() {
                StringBuilder builder = new StringBuilder();
                deepClone().toString(builder);
                if (builder.length() > 0) {
                    builder.setLength(builder.length() - 1);
                }
                return builder.toString();
            }

            private id7.Segment deepClone() {
                id7.Segment seg = clone();
                if (seg.left != null) {
                    seg.left = seg.left.deepClone();
                }
                if (seg.right != null) {
                    seg.right = seg.right.deepClone();
                }
                return seg;
            }

            protected id7.Segment clone() {
                try {
                    return (id7.Segment) super.clone();
                } catch (CloneNotSupportedException e) {
                    throw new RuntimeException(e);
                }
            }

        }

        public static class id2 {
            List<id7.id2> next = new ArrayList<>(2);
            int id;
            int id1;
            int id4;
            int size;
            id7.id2 link;
            id7.id2 heavy;
            id7.id2 father;
            PriorityQueue<Integer> pq = new PriorityQueue<>();

            public String toString() {
                return "" + id;
            }

        }

    }

    static class QueryObject {
        long val;
        int index;

        public void reset() {
            val = (long) 1e18;
        }

        public void update(long val, int index) {
            if (this.val > val) {
                this.val = val;
                this.index = (int) 1e9;
            }
            if (this.val == val) {
                this.index = Math.min(index, this.index);
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
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

    static class id0 implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public id0(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public id0(id0 list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public id0() {
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

        public void addAll(id0 list) {
            addAll(list.data, 0, list.size);
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof id0)) {
                return false;
            }
            id0 other = (id0) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public id0 clone() {
            id0 ans = new id0();
            ans.addAll(this);
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
}

