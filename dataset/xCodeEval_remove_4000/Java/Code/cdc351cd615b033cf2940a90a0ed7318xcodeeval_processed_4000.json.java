import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.ListIterator;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
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
            id4 solver = new id4();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id4 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int r = in.readInt();
            int b = in.readInt();
            char rChar = 'r';
            char bChar = 'b';
            if (r > b) {
                int tmp = r;
                r = b;
                b = tmp;

                char cTmp = rChar;
                rChar = bChar;
                bChar = cTmp;
            }

            Edge[] edges = new Edge[n];
            Map<Integer, Node> rows = new HashMap<>();
            Map<Integer, Node> cols = new HashMap<>();
            for (int i = 0; i < n; i++) {
                Node u = rows.computeIfAbsent(in.readInt(), x -> new Node());
                Node v = cols.computeIfAbsent(in.readInt(), x -> new Node());
                Edge e = new Edge();
                edges[i] = e;
                e.a = u;
                e.b = v;
                e.a.deg++;
                e.b.deg++;
            }

            for (int i = 0; i < m; i++) {
                int t = in.readInt();
                int l = in.readInt();
                int k = in.readInt();
                Node node;
                if (t == 1) {
                    node = rows.computeIfAbsent(l, x -> new Node());
                } else {
                    node = cols.computeIfAbsent(l, x -> new Node());
                }
                intersect(node.lr, bounds(node.deg, k));
                if (node.lr[0] > node.lr[1]) {
                    out.println(-1);
                    return;
                }
            }

            int idAlloc = 0;
            for (Node u : rows.values()) {
                u.id = idAlloc++;
            }
            for (Node v : cols.values()) {
                v.id = idAlloc++;
            }
            int src = idAlloc++;
            int dst = idAlloc++;
            List<id5>[] g = IntegerFlow.id8(dst + 1);

            for (Edge e : edges) {
                e.e = IntegerFlow.id6(g, e.a.id, e.b.id, 1, 0);
            }

            for (Node node : rows.values()) {
                IntegerFlow.id6(g, src, node.id, node.lr[1], node.lr[0]);
            }
            for (Node node : cols.values()) {
                IntegerFlow.id6(g, node.id, dst, node.lr[1], node.lr[0]);
            }

            id9 flow = new id3();
            boolean feasible = IntegerFlow.id7(g, src, dst, flow);
            if (!feasible) {
                out.println(-1);
                return;
            }
            flow.apply((List[]) g, src, dst, (int) 1e9);
            long ans = 0;
            for (Edge e : edges) {
                if (e.e.flow == 1) {
                    ans += r;
                } else {
                    ans += b;
                }
            }

            out.println(ans);
            for (Edge e : edges) {
                if (e.e.flow == 1) {
                    out.append(rChar);
                } else {
                    out.append(bChar);
                }
            }
        }

        public void intersect(int[] a, int[] b) {
            a[0] = Math.max(a[0], b[0]);
            a[1] = Math.min(a[1], b[1]);
        }

        public int[] bounds(int n, int k) {
            

            

            

            

            return new int[]{DigitUtils.ceilDiv(n - k, 2),
                    DigitUtils.floorDiv(n + k, 2)};
        }

    }

    static class Node {
        int id;
        int[] lr = new int[]{0, (int) 1e8};
        int deg;

    }

    static class Edge {
        Node a;
        Node b;
        id1 e;

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

    static interface IntegerStack {
        void addLast(int x);

        boolean isEmpty();

        void clear();

    }

    static class id1<T extends id1<T>> extends DirectedEdge {
        public int flow;
        public boolean real;
        public T rev;

        public id1(int to, int flow, boolean real) {
            super(to);
            this.flow = flow;
            this.real = real;
        }

        public String toString() {
            return rev.to + "-[" + flow + "/" + (flow + rev.flow) + "]->" + to;
        }

    }

    static class id5 extends id1<id5> {
        public int low;

        public id5(int to, int flow, boolean real, int low) {
            super(to, flow, real);
            this.low = low;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

        public static boolean equal(int a, int b) {
            return a == b;
        }

    }

    static interface id9 {
        int apply(List<id1>[] g, int s, int t, int send);

    }

    static class id3 implements id9 {
        List<id1>[] g;
        int s;
        int t;
        IntegerDeque deque;
        int[] dists;
        ListIterator<id1>[] iterators;

        public id3() {
        }

        public void ensure(int vertexNum) {
            if (dists != null && dists.length >= vertexNum) {
                return;
            }
            deque = new id0(vertexNum);
            dists = new int[vertexNum];
            iterators = new ListIterator[vertexNum];
        }

        public int send(int root, int flow) {
            if (root == t) {
                return flow;
            }
            int snapshot = flow;
            while (iterators[root].hasNext()) {
                id1 e = iterators[root].next();
                int remain;
                if (dists[e.to] + 1 != dists[root] || (remain = e.rev.flow) == 0) {
                    continue;
                }
                int sent = send(e.to, Math.min(flow, remain));
                flow -= sent;
                IntegerFlow.send(e, sent);
                if (flow == 0) {
                    iterators[root].previous();
                    break;
                }
            }
            return snapshot - flow;
        }

        public int apply(List<id1>[] g, int s, int t, int send) {
            ensure(g.length);
            this.s = s;
            this.t = t;
            this.g = g;
            int flow = 0;
            while (flow < send) {
                IntegerFlow.id2(g, t, dists, Integer.MAX_VALUE, deque);
                if (dists[s] == Integer.MAX_VALUE) {
                    break;
                }
                for (int i = 0; i < g.length; i++) {
                    iterators[i] = g[i].listIterator();
                }
                flow += send(s, send - flow);
            }
            return flow;
        }

    }

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
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

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
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

    static class id0 implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public id0(int cap) {
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
                    index = id0.this.next(index);
                    return ans;
                }
            };
        }

        public int removeFirst() {
            int ans = data[bpos];
            bpos = next(bpos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public void clear() {
            bpos = epos = 0;
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

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }

    static class IntegerFlow {
        public static <T extends id1> void send(T edge, int flow) {
            edge.flow += flow;
            edge.rev.flow -= flow;
        }

        public static id1 addEdge(List<id1>[] g, int s, int t, int cap) {
            id1 real = new id1(t, 0, true);
            id1 virtual = new id1(s, cap, false);
            real.rev = virtual;
            virtual.rev = real;
            g[s].add(real);
            g[t].add(virtual);
            return real;
        }

        public static id5 id6(List<id5>[] g, int s, int t, int cap, int low) {
            id5 real = new id5(t, 0, true, low);
            id5 virtual = new id5(s, cap - low, false, low);
            real.rev = virtual;
            virtual.rev = real;
            g[s].add(real);
            g[t].add(virtual);
            return real;
        }

        public static List<id5>[] id8(int n) {
            return createGraph(n);
        }

        public static boolean id7(List<id5>[] g, int s, int t, id9 mf) {
            id6(g, t, s, Integer.MAX_VALUE / 4, 0);
            boolean ans = id7(g, mf);
            g[s].remove(g[s].size() - 1);
            g[t].remove(g[t].size() - 1);
            return ans;
        }

        public static boolean id7(List<id5>[] g, id9 mf) {
            int n = g.length;
            List<id1>[] expand = expand(g, n + 2);
            int src = n;
            int dst = n + 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < expand[i].size(); j++) {
                    id1 fe = expand[i].get(j);
                    if (fe.to == src || fe.to == dst ||
                            !fe.real) {
                        continue;
                    }
                    id5 e = (id5) fe;
                    addEdge(expand, src, e.to, e.low);
                    addEdge(expand, i, dst, e.low);
                }
            }

            mf.apply(expand, src, dst, Integer.MAX_VALUE / 4);

            boolean ans = true;
            for (id1 e : expand[src]) {
                ans = ans && DigitUtils.equal(e.rev.flow, 0);
            }
            for (id1 e : expand[dst]) {
                ans = ans && DigitUtils.equal(e.flow, 0);
            }

            for (int i = 0; i < n; i++) {
                while (g[i].size() > 0) {
                    id1 tail = g[i].get(g[i].size() - 1);
                    if (tail.to == src || tail.to == dst) {
                        g[i].remove(g[i].size() - 1);
                    } else {
                        break;
                    }
                }
            }

            return ans;
        }

        private static List[] expand(List[] g, int n) {
            List[] ans = Arrays.copyOf(g, n);
            for (int i = g.length; i < n; i++) {
                ans[i] = new ArrayList();
            }
            return ans;
        }

        private static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

        public static <T extends id1> void id2(List<T>[] g, int s, int[] dist, int inf, IntegerDeque deque) {
            Arrays.fill(dist, 0, g.length, inf);
            dist[s] = 0;
            deque.clear();
            deque.addLast(s);
            while (!deque.isEmpty()) {
                int head = deque.removeFirst();
                for (T e : g[head]) {
                    if (!DigitUtils.equal(e.flow, 0) && dist[e.to] == inf) {
                        dist[e.to] = dist[head] + 1;
                        deque.addLast(e.to);
                    }
                }
            }
        }

    }

    static interface IntegerDeque extends IntegerStack {
        int removeFirst();

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }
}

