import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Deque;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.util.ArrayDeque;
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
            id4 solver = new id4();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id4 {
        List<id3>[] g;
        Debug debug = new Debug(true);
        boolean valid = true;
        id2 lca;
        Node[] nodes;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            List<Node> known = new ArrayList<>(m);
            for (int i = 0; i < m && valid; i++) {
                int[] dist = new int[n];
                Node node = null;
                for (int j = 0; j < n; j++) {
                    dist[j] = in.readInt();
                    if (dist[j] == 0) {
                        if (node != null || nodes[j].dist != null) {
                            valid = false;
                        }
                        node = nodes[j];
                        node.dist = dist;
                    }
                }
                if (node == null) {
                    valid = false;
                }
                known.add(node);
            }

            if (!valid) {
                out.println(-1);
                return;
            }

            for (Node node : known) {
                node.heights = new id6(n, n);
                for (int i = 0; i < n; i++) {
                    node.heights.addLast(node.dist[i], i);
                }
            }


            Node root = known.get(0);
            for (Node node : nodes) {
                node.depth = root.dist[node.id];
            }
            for (int i = 0; i < n; i++) {
                for (IntegerIterator iterator = root.heights.iterator(i); iterator.hasNext(); ) {
                    int next = iterator.next();
                    if (nodes[next].dist != null) {
                        build(root, nodes[next], nodes[next]);
                    }
                }
            }

            Deque<Node> dq = new ArrayDeque<>(n);
            for (int i = 1; i < n && valid; i++) {
                for (IntegerIterator iterator = root.heights.iterator(i); iterator.hasNext(); ) {
                    Node next = nodes[iterator.next()];
                    if (next.visited) {
                        continue;
                    }
                    int lca = (int) -1e9;
                    Node which = null;
                    for (Node node : known) {
                        int local = (i + root.dist[node.id] - node.dist[next.id]) / 2;
                        if (lca < local) {
                            lca = local;
                            which = node;
                        }
                    }

                    if (which.depth - lca < 0) {
                        valid = false;
                        break;
                    }
                    Node id1 = toDepth(which, which.depth - lca);
                    next.parent = id1.chain;
                    setFather(next, next.parent);
                    id1.cand = next;
                    dq.add(id1);
                }

                while (!dq.isEmpty()) {
                    Node head = dq.removeFirst();
                    head.chain = head.cand;
                }
            }

            for (Node node : nodes) {
                if (node != root && node.parent == null) {
                    valid = false;
                }
            }

            if (!valid) {
                out.println(-1);
                return;
            }

            g = Graph.id7(n);
            for (Node node : nodes) {
                if (node == root) {
                    continue;
                }
                Graph.id5(g, node.id, node.parent.id);
            }

            debug.debug("root", root);
            debug.debug("g", g);

            lca = new id2(g, root.id);

            for (Node node : known) {
                for (Node x : nodes) {
                    if (dist(node.id, x.id) != node.dist[x.id]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
            }

            if (!valid) {
                out.println(-1);
                return;
            }

            for (Node node : nodes) {
                if (node == root) {
                    continue;
                }
                out.append(node.id + 1).append(' ').append(node.parent.id + 1).println();
            }
        }

        public Node toDepth(Node root, int d) {
            if (d == 0) {
                return root;
            }
            int log = Log2.floorLog(d);
            return toDepth(root.jump[log], d - (1 << log));
        }

        public void setFather(Node a, Node p) {
            a.parent = p;
            a.jump[0] = p;
            for (int i = 0; a.jump[i] != null; i++) {
                a.jump[i + 1] = a.jump[i].jump[i];
            }
        }

        public void build(Node root, Node node, Node child) {
            if (node.visited) {
                return;
            }
            node.visited = true;
            int depth = root.dist[node.id] - 1;
            int id0 = root.dist[child.id] - depth;

            for (IntegerIterator iterator = child.heights.iterator(id0); iterator.hasNext(); ) {
                int next = iterator.next();
                if (root.dist[next] == depth) {
                    node.parent = nodes[next];
                    build(root, node.parent, child);
                    setFather(node, node.parent);
                    return;
                }
            }
        }

        public int dist(int a, int b) {
            int c = lca.lca(a, b);
            return nodes[a].depth + nodes[b].depth - 2 * nodes[c].depth;
        }

    }

    static class id3 extends DirectedEdge {
        public id3 rev;

        public id3(int to) {
            super(to);
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

    static class id2 {
        int[] parent;
        int[] preOrder;
        int[] i;
        int[] head;
        int[] a;
        int time;

        void dfs1(List<? extends DirectedEdge>[] tree, int u, int p) {
            parent[u] = p;
            i[u] = preOrder[u] = time++;
            for (DirectedEdge e : tree[u]) {
                int v = e.to;
                if (v == p) continue;
                dfs1(tree, v, u);
                if (Integer.lowestOneBit(i[u]) < Integer.lowestOneBit(i[v])) {
                    i[u] = i[v];
                }
            }
            head[i[u]] = u;
        }

        void dfs2(List<? extends DirectedEdge>[] tree, int u, int p, int up) {
            a[u] = up | Integer.lowestOneBit(i[u]);
            for (DirectedEdge e : tree[u]) {
                int v = e.to;
                if (v == p) continue;
                dfs2(tree, v, u, a[u]);
            }
        }

        public id2(List<? extends DirectedEdge>[] tree, int root) {
            int n = tree.length;
            preOrder = new int[n];
            i = new int[n];
            head = new int[n];
            a = new int[n];
            parent = new int[n];

            dfs1(tree, root, -1);
            dfs2(tree, root, -1, 0);
        }

        private int id8(int x, int hz) {
            if (Integer.lowestOneBit(i[x]) == hz)
                return x;
            int hw = 1 << Log2.floorLog(a[x] & (hz - 1));
            return parent[head[i[x] & -hw | hw]];
        }

        public int lca(int x, int y) {
            int hb = i[x] == i[y] ? Integer.lowestOneBit(i[x]) : (1 << Log2.floorLog(i[x] ^ i[y]));
            int hz = Integer.lowestOneBit(a[x] & a[y] & -hb);
            int ex = id8(x, hz);
            int ey = id8(y, hz);
            return preOrder[ex] < preOrder[ey] ? ex : ey;
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

    static class id6 {
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

        public id6(int qNum, int totalCapacity) {
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

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class Node {
        int id;
        Node parent;
        int[] dist;
        id6 heights;
        int depth;
        boolean visited;
        Node[] jump = new Node[20];
        Node chain = this;
        Node cand = null;

        public String toString() {
            return "" + id;
        }

    }

    static class Log2 {
        public static int floorLog(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
        }

    }

    static class Graph {
        public static void id5(List<id3>[] g, int s, int t) {
            id3 toT = new id3(t);
            id3 toS = new id3(s);
            toT.rev = toS;
            toS.rev = toT;
            g[s].add(toT);
            g[t].add(toS);
        }

        public static List<id3>[] id7(int n) {
            List<id3>[] ans = new List[n];
            for (int i = 0; i < n; i++) {
                ans[i] = new ArrayList<>();
            }
            return ans;
        }

    }
}

