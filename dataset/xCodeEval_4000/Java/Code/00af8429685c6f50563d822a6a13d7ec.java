import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Random;
import java.util.Stack;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Vector;
import java.util.Collections;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EMomentOfBloom solver = new EMomentOfBloom();
        solver.solve(1, in, out);
        out.close();
    }

    static class EMomentOfBloom {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int i, j, k;

            int N = in.nextInt(), M = in.nextInt();
            ArrayList<Integer>[] graph = new ArrayList[N];
            for (i = 0; i < N; ++i) graph[i] = new ArrayList<>();
            DSU dsu = new DSU(N);

            while (M-- > 0) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                if (dsu.addEdge(a, b)) {
                    graph[a].add(b);
                    graph[b].add(a);
                }
            }

            HLD_LCA hld = new HLD_LCA(graph, N, 0, new long[N]);
            int[] parent = hld.getParent();

            int Q = in.nextInt();
            Pair<Integer, Integer>[] query = new Pair[Q];
            k = 0;
            while (Q-- > 0) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                query[k++] = new Pair<>(a, b);
                hld.pathUpdate(a, b, +1);
            }

            HashSet<Integer>[] newG = new HashSet[N];
            for (i = 0; i < N; ++i) newG[i] = new HashSet<>();
            boolean extraReq = false;
            for (i = 0; i < N; ++i)
                if (parent[i] >= 0) if (hld.pathQuery(i, parent[i]) % 2 == 1) {
                    extraReq = true;
                    newG[i].add(parent[i]);
                    newG[parent[i]].add(i);
                }

            if (extraReq) {
                out.println("NO");
                int count = 0;
                for (i = 0; i < N; ++i)
                    if (newG[i].size() == 1) {
                        remove(i, newG);
                        ++count;
                    }
                out.println(count);
            } else {
                out.println("YES");
                for (Pair<Integer, Integer> q : query) {
                    int a = q.getFirst(), b = q.getSecond(), lca = hld.getLCA(a, b);
                    ArrayList<Integer> pathA = new ArrayList<>(), pathB = new ArrayList<>();
                    while (a != lca) {
                        pathA.add(a + 1);
                        a = parent[a];
                    }
                    while (b != lca) {
                        pathB.add(b + 1);
                        b = parent[b];
                    }
                    Collections.reverse(pathB);
                    pathA.add(lca + 1);
                    pathA.addAll(pathB);

                    out.println(pathA.size());
                    for (int itr : pathA) out.print(itr + " ");
                    out.println();
                }
            }
        }

        void remove(int node, HashSet<Integer>[] newG) {
            if (newG[node].isEmpty()) return;
            int next = newG[node].iterator().next();
            newG[node].remove(next);
            newG[next].remove(node);
            remove(next, newG);
        }

    }

    static class Edge {
        int u;
        int v;
        long weight;

        public Edge(int a, int b, long wt) {
            u = a;
            v = b;
            weight = wt;
        }

        public String toString() {
            return "(" + u + ", " + v + " -> " + weight + ")";
        }

    }

    static class Helper {
        public final long MOD;
        public final int MAXN;
        final Random rnd;

        public Helper() {
            MOD = 1000_000_007;
            MAXN = 1000_006;
            rnd = new Random();
        }

        public Helper(long mod, int maxn) {
            MOD = mod;
            MAXN = maxn;
            rnd = new Random();
        }

        public int compare(Object a, Object b) {
            if (a instanceof Integer) {
                return Integer.compare((Integer) a, (Integer) b);
            } else if (a instanceof Long) {
                return Long.compare((Long) a, (Long) b);
            } else if (a instanceof String) {
                return ((String) a).compareTo((String) b);
            } else if (a instanceof Float) {
                return Float.compare((Float) a, (Float) b);
            } else if (a instanceof Double) {
                return Double.compare((Double) a, (Double) b);
            } else {
                return 5 / 0;
            }
        }

    }

    static class HLD_LCA {
        static final long defaultValue = 0;
        ArrayList<Integer>[] graph;
        int[] depth;
        int[] parent;
        int[] chCount;
        int[] queue;
        int N;
        int root;
        long[] weight;
        SegmentTree st;
        int[] treePos;
        int[] linearTree;
        int[] segRoot;

        public int[] getParent() {
            return parent;
        }

        public int getN() {
            return N;
        }

        public long[] getWeight() {
            return weight;
        }

        public SegmentTree getSt() {
            return st;
        }

        public int[] getLinearTree() {
            return linearTree;
        }

        public void setSt(SegmentTree st) {
            this.st = st;
        }

        public HLD_LCA(ArrayList<Integer>[] g, int[] dep, int[] par, int[] ch,
                       int n, int r, long[] wt) {
            graph = g;
            depth = dep;
            parent = par;
            chCount = ch;
            N = n;
            root = r;
            weight = wt;

            HLDify();
        }

        public HLD_LCA(ArrayList<Integer>[] g, int n, int r, long[] wt) {
            graph = g;
            N = n;
            root = r;
            weight = wt;
            iterativeDFS();

            HLDify();
        }

        public HLD_LCA(Edge[] edges, int n, int r) {
            int i;
            N = n;
            root = r;

            graph = new ArrayList[N];
            for (i = 0; i < N; ++i) graph[i] = new ArrayList<>();

            for (Edge e : edges) {
                graph[e.u].add(e.v);
                graph[e.v].add(e.u);
            }
            iterativeDFS();

            weight = new long[N];
            for (Edge e : edges) {
                int child = depth[e.u] > depth[e.v] ? e.u : e.v;
                weight[child] = e.weight;
            }

            HLDify();
        }

        private void iterativeDFS() {
            parent = new int[N];
            depth = new int[N];
            chCount = new int[N];
            queue = new int[N];
            Arrays.fill(chCount, 1);

            int i, st = 0, end = 0;
            parent[root] = -1;
            depth[root] = 1;
            queue[end++] = root;

            while (st < end) {
                int node = queue[st++], h = depth[node] + 1;
                Iterator<Integer> itr = graph[node].iterator();
                while (itr.hasNext()) {
                    int ch = itr.next();
                    if (depth[ch] > 0) continue;
                    depth[ch] = h;
                    parent[ch] = node;
                    queue[end++] = ch;
                }
            }
            for (i = N - 1; i >= 0; --i)
                if (queue[i] != root)
                    chCount[parent[queue[i]]] += chCount[queue[i]];
        }

        private void HLDify() {
            int i, j, treeRoot = -7;

            treePos = new int[N];
            linearTree = new int[N];
            segRoot = new int[N];

            Stack<Integer> stack = new Stack<>();
            stack.ensureCapacity(N << 1);
            stack.push(root);

            for (i = 0; !stack.isEmpty(); ++i) {
                int node = stack.pop();
                if (i == 0 || linearTree[i - 1] != parent[node])
                    treeRoot = node;
                linearTree[i] = node;
                treePos[node] = i;
                segRoot[node] = treeRoot;

                int bigChild = -7, bigChildPos = -7, lastPos = graph[node].size() - 1;
                for (j = 0; j < graph[node].size(); ++j) {
                    int tempNode = graph[node].get(j);
                    if (tempNode == parent[node]) continue;
                    if (bigChild < 0 || chCount[bigChild] < chCount[tempNode]) {
                        bigChild = tempNode;
                        bigChildPos = j;
                    }
                }
                if (bigChildPos >= 0) {
                    int temp = graph[node].get(lastPos);
                    graph[node].set(lastPos, bigChild);
                    graph[node].set(bigChildPos, temp);
                }

                for (int itr : graph[node])
                    if (parent[node] != itr)
                        stack.push(itr);
            }

            buildSegmentTree();
        }

        public void buildSegmentTree() {
            long[] respectiveWeights = new long[getN()];
            for (int i = 0; i < getN(); ++i)
                respectiveWeights[i] = getWeight()[getLinearTree()[i]];
            setSt(new SegmentTree(respectiveWeights, 0, 0));
        }

        public long operate(long a, long b) {
            return getSt().nodeToNode(a, b);
        }

        public long pathQuery(int node1, int node2) {
            long ret = defaultValue, temp;
            while (segRoot[node1] != segRoot[node2]) {
                if (depth[segRoot[node1]] > depth[segRoot[node2]]) {
                    node1 ^= node2;
                    node2 ^= node1;
                    node1 ^= node2;
                }

                temp = st.rangeQuery(treePos[segRoot[node2]], treePos[node2]);
                ret = operate(ret, temp);
                node2 = parent[segRoot[node2]];
            }

            if (treePos[node1] > treePos[node2]) {
                node1 ^= node2;
                node2 ^= node1;
                node1 ^= node2;
            }
            temp = st.rangeQuery(treePos[node1] + 1, treePos[node2]);   

            ret = operate(ret, temp);

            return ret;
        }

        public void pathUpdate(int node1, int node2, long value) {
            while (segRoot[node1] != segRoot[node2]) {
                if (depth[segRoot[node1]] > depth[segRoot[node2]]) {
                    node1 ^= node2;
                    node2 ^= node1;
                    node1 ^= node2;
                }
                st.rangeUpdate(treePos[segRoot[node2]], treePos[node2], value);
                node2 = parent[segRoot[node2]];
            }
            if (treePos[node1] > treePos[node2]) {
                node1 ^= node2;
                node2 ^= node1;
                node1 ^= node2;
            }
            st.rangeUpdate(treePos[node1] + 1, treePos[node2], value);     

        }

        public int getLCA(int node1, int node2) {
            while (segRoot[node1] != segRoot[node2]) {
                if (depth[segRoot[node1]] > depth[segRoot[node2]]) {
                    node1 ^= node2;
                    node2 ^= node1;
                    node1 ^= node2;
                }
                node2 = parent[segRoot[node2]];
            }
            return (depth[node1] < depth[node2]) ? node1 : node2;
        }

    }

    static class SegmentTree {
        private int N;
        private long[] tree;
        private long[] lazy;
        public final long DEFAULT_NODE;
        public final long DEFAULT_LAZY;

        public SegmentTree(long[] ar, long def_node, long def_lazy) {
            DEFAULT_NODE = def_node;
            DEFAULT_LAZY = def_lazy;
            N = 1;
            while (N < ar.length) N <<= 1;
            tree = new long[N * 2 - 1];
            Arrays.fill(tree, DEFAULT_NODE);
            lazy = new long[N * 2 - 1];
            Arrays.fill(lazy, DEFAULT_LAZY);

            for (int i = 0; i < ar.length; ++i) tree[i + N - 1] = ar[i];
            for (int i = N - 2; i >= 0; --i) {
                tree[i] = nodeToNode(tree[i * 2 + 1], tree[i * 2 + 2]);
            }
        }

        public long nodeToNode(long a, long b) {
            return a + b;
        }

        public long lazyToLazy(long a, long b) {
            return a + b;
        }

        public long lazyToNode(long nv, long lv, int l, int r) {
            return nv + lv * (r - l + 1);
        }

        public void pushDown(int i, int l, int r) {
            tree[i] = lazyToNode(tree[i], lazy[i], l, r);
            if (i * 2 + 1 < tree.length) {
                lazy[i * 2 + 1] = lazyToLazy(lazy[i * 2 + 1], lazy[i]);
                lazy[i * 2 + 2] = lazyToLazy(lazy[i * 2 + 2], lazy[i]);
            }
            lazy[i] = DEFAULT_LAZY;
        }

        public void rangeUpdate(int l, int r, long val) {
            update(0, 0, N - 1, l, r, val);
        }

        public long rangeQuery(int l, int r) {
            return query(0, 0, N - 1, l, r);
        }

        private void update(int i, int l, int r, int ql, int qr, long val) {
            pushDown(i, l, r);
            int mid = l + r >> 1, i2 = i << 1;
            if (l > qr || r < ql) return;
            else if (l >= ql && r <= qr) {
                lazy[i] = lazyToLazy(lazy[i], val);
                pushDown(i, l, r);
            } else {
                update(i2 + 1, l, mid, ql, qr, val);
                update(i2 + 2, mid + 1, r, ql, qr, val);

                

                tree[i] = nodeToNode(tree[i2 + 1], tree[i2 + 2]);
            }
        }

        private long query(int i, int l, int r, int ql, int qr) {
            pushDown(i, l, r);
            int mid = l + r >> 1, i2 = i << 1;
            if (l > qr || r < ql) return DEFAULT_NODE;
            else if (l >= ql && r <= qr) return tree[i];
            else {
                return nodeToNode(query(i2 + 1, l, mid, ql, qr),
                        query(i2 + 2, mid + 1, r, ql, qr));
            }
        }

        public String toString() {
            return "SegTree = " + Arrays.toString(tree) + ", " + Arrays.toString(lazy);
        }

    }

    static class FastReader {
        static final int BUFSIZE = 1 << 20;
        static byte[] buf;
        static int index;
        static int total;
        static InputStream in;

        public FastReader(InputStream is) {
            try {
                in = is;
                buf = new byte[BUFSIZE];
            } catch (Exception e) {
            }
        }

        private int scan() {
            try {
                if (index >= total) {
                    index = 0;
                    total = in.read(buf);
                    if (total <= 0)
                        return -1;
                }
                return buf[index++];
            } catch (Exception | Error e) {
                System.err.println(e.getMessage());
                return 13 / 0;
            }
        }

        public int nextInt() {
            int c, val = 0;
            for (c = scan(); c <= 32; c = scan()) ;
            boolean neg = c == '-';
            if (c == '-' || c == '+')
                c = scan();
            for (; c >= '0' && c <= '9'; c = scan())
                val = (val << 3) + (val << 1) + (c & 15);
            return neg ? -val : val;
        }

    }

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        U first;
        V second;
        Helper hp = new Helper();

        public Pair(U u, V v) {
            first = u;
            second = v;
        }

        public U getFirst() {
            return first;
        }

        public V getSecond() {
            return second;
        }

        public int compareTo(Pair<U, V> p) {
            int cmp = hp.compare(first, p.first);
            if (cmp == 0) {
                cmp = hp.compare(second, p.second);
            }
            return cmp;
        }

        public String toString() {
            return "(" + first + ", " + second + ")";
        }

    }

    static class DSU {
        int N;
        int[] parent;
        int[] size;

        public DSU(int nodeCount) {
            N = nodeCount;
            parent = new int[nodeCount];
            Arrays.fill(parent, -7);
            size = new int[nodeCount];
            Arrays.fill(size, 1);
        }

        public int getParent(int node) {
            if (parent[node] < 0) return node;
            else return parent[node] = getParent(parent[node]);
        }

        public boolean addEdge(int a, int b) {
            a = getParent(a);
            b = getParent(b);
            if (a == b) {
                return false;
            } else if (size[a] > size[b]) {
                a ^= b;
                b ^= a;
                a ^= b;
            }
            parent[a] = b;
            size[b] += size[a];
            size[a] = -7;
            return true;
        }

    }
}

