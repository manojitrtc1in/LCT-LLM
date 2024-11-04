import java.util.ArrayList;
import java.math.*;
import java.util.Arrays;
import java.awt.*;
import java.io.*;
import java.util.Iterator;
import java.util.Stack;
import java.util.*;


public class CP {
    public static void main(String[] args) throws Exception {
        new Solver().solve();
    }
}

class Solver {
    final Helper hp;
    final int MAXN = 1000_006;
    final long MOD = (long) 1e9 + 7;

    Solver() {
        hp = new Helper(MOD, MAXN);
        hp.initIO(System.in, System.out);
    }

    int N, Q;
    ArrayList<Integer>[] graph;

    void solve() throws Exception {
        int i, j, k;

        N = hp.nextInt(); Q = hp.nextInt();
        graph = new ArrayList[N];
        for (i = 0; i < N; ++i) graph[i] = new ArrayList<>();
        for (i = 0; i < N - 1; ++i) {
            int a = hp.nextInt() - 1, b = hp.nextInt() - 1;
            graph[a].add(b); graph[b].add(a);
        }

        vis = new boolean[N];
        parent = new int[N]; Arrays.fill(parent, -7);
        chCount = new int[N];
        buildTree(centroid(0));

        

        


        long[] ar = new long[N]; Arrays.fill(ar, 1);
        id6 hld = new id6(graph, N, 0, ar);


        long[] minDist = new long[N]; Arrays.fill(minDist, Integer.MAX_VALUE >> 2);

        defaultConfig:
        {
            int node = 0, traveller = node;

            while (traveller >= 0) {
                minDist[traveller] = Math.min(minDist[traveller],
                        hld.pathQuery(traveller, node, -7) - 1);
                traveller = parent[traveller];
            }
        }

        for (i = 0; i < Q; ++i) {
            if (hp.nextInt() == 1) {
                int node = hp.nextInt() - 1, traveller = node;

                while (traveller >= 0) {
                    minDist[traveller] = Math.min(minDist[traveller],
                            hld.pathQuery(traveller, node, -7) - 1);
                    traveller = parent[traveller];
                }

            } else {
                int node = hp.nextInt() - 1, traveller = node;
                long ans = minDist[node];

                while (traveller >= 0) {
                    ans = Math.min(ans, minDist[traveller]
                            + hld.pathQuery(node, traveller, -7) - 1);
                    traveller = parent[traveller];
                }

                hp.println(ans);
            }

            

        }

        hp.flush();
    }

    int[] parent;
    boolean[] vis;

    void buildTree(int node) {
        vis[node] = true;

        for (int itr : graph[node]) if (!vis[itr]) {
            int c = centroid(itr);
            parent[c] = node;
            buildTree(c);
        }
    }

    int[] chCount;

    int centroid(int node) {
        dfs(node, -7);
        int target = chCount[node] >> 1, par = -7;

        while (true) {
            boolean again = false;
            for (int itr : graph[node]) if (!vis[itr] && itr != par && chCount[itr] > target) {
                par = node; node = itr; again = true;
                break;
            }
            if (!again) break;
        }

        return node;
    }

    int dfs(int node, int par) {
        chCount[node] = 1;
        for (int itr : graph[node]) if (!vis[itr] && itr != par) {
            chCount[node] += dfs(itr, node);
        }
        return chCount[node];
    }
}
class SegmentTree {
    private int N;
    private long[] tree, lazy;

    public SegmentTree(long[] ar) {
        N = 1;
        while (N < ar.length) N <<= 1;
        tree = new long[N * 2 - 1];
        lazy = new long[N * 2 - 1];

        for (int i = 0; i < ar.length; ++i) tree[i + N - 1] = ar[i];
        for (int i = N - 2; i >= 0; --i) tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
    }

    public void pushDown(int i, int l, int r) {
        tree[i] += lazy[i] * (r - l + 1);
        if (i * 2 + 1 < tree.length) {
            lazy[i * 2 + 1] += lazy[i];
            lazy[i * 2 + 2] += lazy[i];
        }
        lazy[i] = 0;
    }

    public void pointUpdate(int i, long val) {
        i += N - 1;
        while (i >= 0) {
            tree[i] += val;
            i = i - 1 >> 1;
        }
    }

    public void rangeUpdate(int l, int r, long val) {
        update(0, 0, N - 1, l, r, val);
    }

    public long rangeQuery(int l, int r, long key) {
        return query(0, 0, N - 1, l, r, key);
    }


    private void update(int i, int l, int r, int ql, int qr, long val) {
        pushDown(i, l, r);
        int mid = l + r >> 1, i2 = i << 1;
        if (l > qr || r < ql) return;
        else if (l >= ql && r <= qr) {
            lazy[i] += val;
            pushDown(i, l, r);
        } else {
            update(i2 + 1, l, mid, ql, qr, val);
            update(i2 + 2, mid + 1, r, ql, qr, val);

            

            tree[i] = tree[i2 + 1] + tree[i2 + 2];
        }
    }

    private long query(int i, int l, int r, int ql, int qr, long key) {
        pushDown(i, l, r);
        int mid = l + r >> 1, i2 = i << 1;
        if (l > qr || r < ql) return 0;
        else if (l >= ql && r <= qr) return tree[i];
        else {
            return query(i2 + 1, l, mid, ql, qr, key)
                    + query(i2 + 2, mid + 1, r, ql, qr, key);
        }
    }
}


class id6 {
    static final int MAXN = 1000_006;
    static final long defaultValue = 0;
    ArrayList<Integer>[] graph;
    int[] depth, parent, chCount, queue;
    int N, root;
    long[] weight;

    SegmentTree st;
    int[] treePos, linearTree, segRoot;

    id6(ArrayList<Integer>[] g, int[] dep, int[] par, int[] ch,
            int n, int r, long[] wt) {
        graph = g;
        depth = dep;
        parent = par;
        chCount = ch;
        N = n;
        root = r;
        weight = wt;

        id9();
    }

    id6(ArrayList<Integer>[] g, int n, int r, long[] wt) {
        graph = g;
        N = n;
        root = r;
        weight = wt;
        id3();

        id9();
    }

    id6(Edge[] edges, int n, int r) {
        int i;
        N = n;
        root = r;

        graph = new ArrayList[N];
        for (i = 0; i < N; ++i) graph[i] = new ArrayList<>();

        for (Edge e : edges) {
            graph[e.u].add(e.v);
            graph[e.v].add(e.u);
        }
        id3();

        weight = new long[N];
        for (Edge e : edges) {
            int child = depth[e.u] > depth[e.v] ? e.u : e.v;
            weight[child] = e.weight;
        }

        id9();
    }

    long operate(long a, long b) {
        return a + b;
    }

    private void id3() {
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

    private void id9() {
        int i, j, treeRoot = -7;

        treePos = new int[N];
        linearTree = new int[N];
        segRoot = new int[N];

        Stack<Integer> stack = new Stack<>();
        stack.ensureCapacity(MAXN);
        stack.push(root);
        for (i = 0; !stack.isEmpty(); ++i) {
            int node = stack.pop();
            if (i == 0 || linearTree[i - 1] != parent[node])
                treeRoot = node;
            linearTree[i] = node;
            treePos[node] = i;
            segRoot[node] = treeRoot;

            int bigChild = -7, id7 = -7, lastPos = graph[node].size() - 1;
            for (j = 0; j < graph[node].size(); ++j) {
                int tempNode = graph[node].get(j);
                if (tempNode == parent[node]) continue;
                if (bigChild < 0 || chCount[bigChild] < chCount[tempNode]) {
                    bigChild = tempNode;
                    id7 = j;
                }
            }
            if (id7 >= 0) {
                int temp = graph[node].get(lastPos);
                graph[node].set(lastPos, bigChild);
                graph[node].set(id7, temp);
            }

            for (int itr : graph[node])
                if (parent[node] != itr)
                    stack.push(itr);
        }

        long[] id12 = new long[N];
        for (i = 0; i < N; ++i)
            id12[i] = weight[linearTree[i]];
        st = new SegmentTree(id12);
    }

    long pathQuery(int node1, int node2, long key) {
        long ret = defaultValue, temp;
        while (segRoot[node1] != segRoot[node2]) {
            if (depth[segRoot[node1]] > depth[segRoot[node2]]) {
                node1 ^= node2;
                node2 ^= node1;
                node1 ^= node2;
            }

            temp = st.rangeQuery(treePos[segRoot[node2]], treePos[node2], key);
            ret = operate(ret, temp);
            node2 = parent[segRoot[node2]];
        }

        if (treePos[node1] > treePos[node2]) {
            node1 ^= node2;
            node2 ^= node1;
            node1 ^= node2;
        }
        temp = st.rangeQuery(treePos[node1], treePos[node2], key);   

        ret = operate(ret, temp);

        return ret;
    }

    void pathUpdate(int node1, int node2, long value) {
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
        st.rangeUpdate(treePos[node1], treePos[node2], value);     

    }

    long id1(int node, long key) {
        int pos = treePos[node];
        return st.rangeQuery(pos, pos + chCount[node] - 1, key); 

    }

    void id0(int node, long value) {
        int pos = treePos[node];
        st.rangeUpdate(pos, pos + chCount[node] - 1, value);    

    }

    int id13(int node1, int node2) {
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

    int id4(int node, int targetDepth) 

    {
        if (depth[node] < targetDepth)
            return -7;

        while (depth[segRoot[node]] > targetDepth)
            node = parent[segRoot[node]];
        node = linearTree[treePos[node] - depth[node] + targetDepth];

        return node;
    }
}

class Edge {
    int u, v;
    long weight;

    Edge(int a, int b, int wt) {
        u = a;
        v = b;
        weight = wt;
    }

    public String toString() {
        return "(" + u + ", " + v + " -> " + weight + ")";
    }
}

class Helper {
    final long MOD;
    final int MAXN;
    final Random rnd;

    public Helper(long mod, int maxn) {
        MOD = mod;
        MAXN = maxn;
        rnd = new Random();
    }


    public static int[] sieve;
    public static ArrayList<Integer> primes;

    public void id5() {
        primes = new ArrayList<>();
        sieve = new int[MAXN];
        int i, j;
        for (i = 2; i < MAXN; ++i)
            if (sieve[i] == 0) {
                primes.add(i);
                for (j = i; j < MAXN; j += i) {
                    sieve[j] = i;
                }
            }
    }


    public static long[] factorial;

    public void id10() {
        factorial = new long[MAXN];
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) factorial[i] = factorial[i - 1] * i % MOD;
    }

    public long id2(int n) {
        if (factorial == null) id10();
        return factorial[n];
    }

    public long ncr(int n, int r) {
        if (r > n) return 0;
        if (factorial == null) id10();
        long numerator = factorial[n];
        long denominator = factorial[r] * factorial[n - r] % MOD;
        return numerator * pow(denominator, MOD - 2, MOD) % MOD;
    }


    public long[] id8(int size) throws Exception {
        long[] ar = new long[size];
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    public int[] id11(int size) throws Exception {
        int[] ar = new int[size];
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    public String[] id14(int size) throws Exception {
        String[] ar = new String[size];
        for (int i = 0; i < size; ++i) ar[i] = next();
        return ar;
    }

    public String joinElements(long[] ar) {
        StringBuilder sb = new StringBuilder();
        for (long itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }


    public String joinElements(int[] ar) {
        StringBuilder sb = new StringBuilder();
        for (int itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(String[] ar) {
        StringBuilder sb = new StringBuilder();
        for (String itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(Object[] ar) {
        StringBuilder sb = new StringBuilder();
        for (Object itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }


    public long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }


    public long max(long[] ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.max(ret, itr);
        return ret;
    }

    public int max(int[] ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.max(ret, itr);
        return ret;
    }

    public long min(long[] ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.min(ret, itr);
        return ret;
    }

    public int min(int[] ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.min(ret, itr);
        return ret;
    }


    public long sum(long[] ar) {
        long sum = 0;
        for (long itr : ar) sum += itr;
        return sum;
    }

    public long sum(int[] ar) {
        long sum = 0;
        for (int itr : ar) sum += itr;
        return sum;
    }

    public void shuffle(int[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length);
            if (r != i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void shuffle(long[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length);
            if (r != i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public long pow(long base, long exp, long MOD) {
        base %= MOD;
        long ret = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) ret = ret * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }


    static byte[] buf = new byte[2048];
    static int index, total;
    static InputStream in;
    static BufferedWriter bw;


    public void initIO(InputStream is, OutputStream os) {
        try {
            in = is;
            bw = new BufferedWriter(new OutputStreamWriter(os));
        } catch (Exception e) {
        }
    }

    public void initIO(String inputFile, String outputFile) {
        try {
            in = new FileInputStream(inputFile);
            bw = new BufferedWriter(new OutputStreamWriter(
                    new FileOutputStream(outputFile)));
        } catch (Exception e) {
        }
    }

    private int scan() throws Exception {
        if (index >= total) {
            index = 0;
            total = in.read(buf);
            if (total <= 0)
                return -1;
        }
        return buf[index++];
    }

    public String next() throws Exception {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan())
            sb.append((char) c);
        return sb.toString();
    }

    public int nextInt() throws Exception {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    public long nextLong() throws Exception {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    public void print(Object a) throws Exception {
        bw.write(a.toString());
    }

    public void printsp(Object a) throws Exception {
        print(a);
        print(" ");
    }

    public void println() throws Exception {
        bw.write("\n");
    }

    public void println(Object a) throws Exception {
        print(a);
        println();
    }

    public void flush() throws Exception {
        bw.flush();
    }
}
