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
            EWaitForIt solver = new EWaitForIt();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EWaitForIt {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int q = in.readInt();

            HeavyLightDecompose dec = new HeavyLightDecompose(Math::max, n, 0);
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
                dec.setInitVal(u, i + 1);
            }
            dec.finish();

            IntegerArrayList list = new IntegerArrayList(n);
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
                    dec.updateSubtree(v, k);
                }
            }


        }

    }

    static class HeavyLightDecompose {
        private LongBinaryOperator op;
        int n;
        int order = 1;
        HeavyLightDecompose.HLDNode root;
        HeavyLightDecompose.HLDNode[] nodes;
        HeavyLightDecompose.HLDNode[] segIndexToNode;
        HeavyLightDecompose.Segment segment;

        public HeavyLightDecompose(LongBinaryOperator op, int n, int rootId) {
            this.op = op;
            this.n = n;
            nodes = new HeavyLightDecompose.HLDNode[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new HeavyLightDecompose.HLDNode();
                nodes[i].id = i;
            }
            root = nodes[rootId];
        }

        public void updateSubtree(int u, long k) {
            segment.update(nodes[u].dfsOrderFrom, nodes[u].dfsOrderTo, 1, n, k);
        }

        public void addEdge(int a, int b) {
            nodes[a].next.add(nodes[b]);
            nodes[b].next.add(nodes[a]);
        }

        public void setInitVal(int nodeId, int val) {
            nodes[nodeId].pq.add(val);
        }

        public void pop(int nodeId) {
            HeavyLightDecompose.HLDNode node = nodes[nodeId];
            segment.updateRep(node.dfsOrderFrom, node.dfsOrderFrom, 1, n, node);
        }

        public void finish() {
            dfs(root, null);
            dfs2(root, root);
            segIndexToNode = new HeavyLightDecompose.HLDNode[n + 1];
            for (int i = 0; i < n; i++) {
                segIndexToNode[nodes[i].dfsOrderFrom] = nodes[i];
            }
            segment = new HeavyLightDecompose.Segment(1, n, i -> segIndexToNode[i]);
        }

        public void processPath(int uId, int vId, QueryObject qo) {
            HeavyLightDecompose.HLDNode u = nodes[uId];
            HeavyLightDecompose.HLDNode v = nodes[vId];
            while (u != v) {
                if (u.link == v.link) {
                    if (u.size > v.size) {
                        HeavyLightDecompose.HLDNode tmp = u;
                        u = v;
                        v = tmp;
                    }
                    segment.query(v.dfsOrderFrom + 1, u.dfsOrderFrom, 1, n, qo);
                    u = v;
                } else {
                    if (u.link.size > v.link.size) {
                        HeavyLightDecompose.HLDNode tmp = u;
                        u = v;
                        v = tmp;
                    }
                    segment.query(u.link.dfsOrderFrom, u.dfsOrderFrom, 1, n, qo);
                    u = u.link.father;
                }
            }
            segment.query(u.dfsOrderFrom, u.dfsOrderFrom, 1, n, qo);
        }

        private static void dfs(HeavyLightDecompose.HLDNode root, HeavyLightDecompose.HLDNode father) {
            root.size = 1;
            root.father = father;
            for (HeavyLightDecompose.HLDNode node : root.next) {
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

        private void dfs2(HeavyLightDecompose.HLDNode root, HeavyLightDecompose.HLDNode link) {
            root.dfsOrderFrom = order++;
            root.link = link;
            if (root.heavy != null) {
                dfs2(root.heavy, link);
            }
            for (HeavyLightDecompose.HLDNode node : root.next) {
                if (node == root.father || node == root.heavy) {
                    continue;
                }
                dfs2(node, node);
            }
            root.dfsOrderTo = order - 1;
        }

        public static class Segment implements Cloneable {
            private HeavyLightDecompose.Segment left;
            private HeavyLightDecompose.Segment right;
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

            public void replace(HeavyLightDecompose.HLDNode node) {
                if (node.pq.isEmpty()) {
                    minVal = inf;
                } else {
                    int top = node.pq.remove();
                    minVal = top + val;
                    minIndex = top - 1;
                }
            }

            public Segment(int l, int r, IntFunction<HeavyLightDecompose.HLDNode> function) {
                if (l < r) {
                    int m = DigitUtils.floorAverage(l, r);
                    left = new HeavyLightDecompose.Segment(l, m, function);
                    right = new HeavyLightDecompose.Segment(m + 1, r, function);
                    pushUp();
                } else {
                    HeavyLightDecompose.HLDNode node = function.apply(l);
                    replace(node);
                }
            }

            private boolean covered(int ll, int rr, int l, int r) {
                return ll <= l && rr >= r;
            }

            private boolean noIntersection(int ll, int rr, int l, int r) {
                return ll > r || rr < l;
            }

            public void updateRep(int ll, int rr, int l, int r, HeavyLightDecompose.HLDNode x) {
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

            private HeavyLightDecompose.Segment deepClone() {
                HeavyLightDecompose.Segment seg = clone();
                if (seg.left != null) {
                    seg.left = seg.left.deepClone();
                }
                if (seg.right != null) {
                    seg.right = seg.right.deepClone();
                }
                return seg;
            }

            protected HeavyLightDecompose.Segment clone() {
                try {
                    return (HeavyLightDecompose.Segment) super.clone();
                } catch (CloneNotSupportedException e) {
                    throw new RuntimeException(e);
                }
            }

        }

        public static class HLDNode {
            List<HeavyLightDecompose.HLDNode> next = new ArrayList<>(2);
            int id;
            int dfsOrderFrom;
            int dfsOrderTo;
            int size;
            HeavyLightDecompose.HLDNode link;
            HeavyLightDecompose.HLDNode heavy;
            HeavyLightDecompose.HLDNode father;
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

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
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

        public void addAll(IntegerArrayList list) {
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
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
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

