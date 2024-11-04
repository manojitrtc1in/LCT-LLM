import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static final int md = (int) 1e9 + 7;

    static class Mint {
        static int mod() {
            return md;
        }

        static int normalize(int x) {
            int v;
            if (-mod() <= x && x < mod()) {
                v = x;
            } else {
                v = x % mod();
            }
            if (v < 0) {
                v += mod();
            }
            return v;
        }

        int value;

        Mint() {
            value = 0;
        }

        Mint(int x) {
            value = normalize(x);
        }

        int get() {
            return value;
        }

        Mint add(Mint other) {
            value = normalize(value + other.value);
            return this;
        }

        Mint subtract(Mint other) {
            value = normalize(value - other.value);
            return this;
        }

        Mint multiply(Mint other) {
            value = normalize((int) (1L * value * other.value % mod()));
            return this;
        }

        Mint divide(Mint other) {
            return multiply(inverse(other.value, mod()));
        }

        Mint increment() {
            return add(new Mint(1));
        }

        Mint decrement() {
            return subtract(new Mint(1));
        }

        Mint negate() {
            return new Mint(-value);
        }

        static Mint inverse(int a, int m) {
            int u = 0, v = 1;
            while (a != 0) {
                int t = m / a;
                m -= t * a;
                int temp = a;
                a = m;
                m = temp;
                u -= t * v;
                temp = u;
                u = v;
                v = temp;
            }
            assert m == 1;
            return new Mint(u);
        }

        static Mint power(Mint a, long b) {
            assert b >= 0;
            Mint x = a, res = new Mint(1);
            long p = b;
            while (p > 0) {
                if ((p & 1) == 1) {
                    res.multiply(x);
                }
                x.multiply(x);
                p >>= 1;
            }
            return res;
        }

        static Mint[] generate(int n, Mint v) {
            Mint[] a = new Mint[n];
            for (int i = 0; i < n; i++) {
                a[i] = v;
            }
            return a;
        }

        static Mint[] factorial(int n) {
            Mint[] a = generate(n, new Mint(1));
            for (int i = 1; i < n; i++) {
                a[i].multiply(a[i - 1]);
            }
            return a;
        }

        static Mint[] inverseFactorial(int n) {
            Mint[] a = generate(n, new Mint(1));
            Mint[] b = generate(n, new Mint(1));
            for (int i = 1; i < n; i++) {
                a[i].multiply(a[i - 1]);
            }
            b[n - 1] = inverse(a[n - 1].value, mod());
            for (int i = n - 2; i >= 0; i--) {
                b[i] = b[i + 1].multiply(a[i]);
            }
            return b;
        }

        static Mint binomial(int n, int m) {
            if (m < 0 || m > n) {
                return new Mint(0);
            }
            Mint[] a = generate(n + 1, new Mint(1));
            for (int i = 1; i <= n; i++) {
                a[i].multiply(a[i - 1]);
            }
            return a[n].divide(a[m]).divide(a[n - m]);
        }
    }

    static class SegTree {
        static class Node {
            long w = 0;
            Mint Wp = new Mint(0);
            Mint fp = new Mint(0);
            Mint tp = new Mint(0);

            void apply(int l, int r, int v, int id, int rid, int a) {
                w = v;
                Wp = new Mint(v).multiply(new Mint(a));
                fp = new Mint(v).multiply(new Mint(id));
                tp = new Mint(v).multiply(new Mint(rid));
            }
        }

        Node unite(Node a, Node b) {
            Node res = new Node();
            res.w = a.w + b.w;
            res.Wp = a.Wp.add(b.Wp);
            res.fp = a.fp.add(b.fp);
            res.tp = a.tp.add(b.tp);
            return res;
        }

        void push(int x, int l, int r) {

        }

        void pull(int x, int z) {
            tree[x] = unite(tree[x + 1], tree[z]);
        }

        int n;
        Node[] tree;

        void build(int x, int l, int r) {
            if (l == r) {
                return;
            }
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            build(x + 1, l, y);
            build(z, y + 1, r);
            pull(x, z);
        }

        <M> void build(int x, int l, int r, M[] v, M[] a) {
            if (l == r) {
                tree[x].apply(l, r, v[l], l, n - 1 - r, a[l]);
                return;
            }
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            build(x + 1, l, y, v, a);
            build(z, y + 1, r, v, a);
            pull(x, z);
        }

        <M> SegTree(M[] v, M[] t) {
            n = v.length;
            assert n > 0;
            tree = new Node[2 * n - 1];
            for (int i = 0; i < 2 * n - 1; i++) {
                tree[i] = new Node();
            }
            build(0, 0, n - 1, v, t);
        }

        Node get(int x, int l, int r, int ll, int rr) {
            if (ll <= l && r <= rr) {
                return tree[x];
            }
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            push(x, l, r);
            Node res = new Node();
            if (rr <= y) {
                res = get(x + 1, l, y, ll, rr);
            } else {
                if (ll > y) {
                    res = get(z, y + 1, r, ll, rr);
                } else {
                    res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
                }
            }
            pull(x, z);
            return res;
        }

        Node get(int ll, int rr) {
            assert 0 <= ll && ll <= rr && rr <= n - 1;
            return get(0, 0, n - 1, ll, rr);
        }

        Node get(int p) {
            assert 0 <= p && p <= n - 1;
            return get(0, 0, n - 1, p, p);
        }

        void modify(int x, int l, int r, int ll, int rr, int v, int id, int rid, int a) {
            if (ll <= l && r <= rr) {
                tree[x].apply(l, r, v, id, rid, a);
                return;
            }
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            push(x, l, r);
            if (ll <= y) {
                modify(x + 1, l, y, ll, rr, v, id, rid, a);
            }
            if (rr > y) {
                modify(z, y + 1, r, ll, rr, v, id, rid, a);
            }
            pull(x, z);
        }

        void modify(int ll, int rr, int v, int id, int rid, int a) {
            assert 0 <= ll && ll <= rr && rr <= n - 1;
            modify(0, 0, n - 1, ll, rr, v, id, rid, a);
        }

        int findFirstKnowingly(int x, int l, int r, Node node, Node node1, Node node2) {
            if (l == r) {
                return l;
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res;
            if (node1.w + node2.w >= node.w * 2) {
                res = findFirstKnowingly(x + 1, l, y, node1, node2, tree[x + 1]);
            } else {
                res = findFirstKnowingly(z, y + 1, r, node1, node2, tree[z]);
            }
            pull(x, z);
            return res;
        }

        int findFirst(int x, int l, int r, int ll, int rr, Node node, Node node1, Node node2) {
            if (ll <= l && r <= rr) {
                if (node.w * 2 <= node1.w + node2.w) {
                    return findFirstKnowingly(x, l, r, node, node1, node2);
                }
                return -1;
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res = -1;
            if (ll <= y) {
                res = findFirst(x + 1, l, y, ll, rr, node, node1, node2);
            }
            if (rr > y && res == -1) {
                res = findFirst(z, y + 1, r, ll, rr, node, node1, node2);
            }
            pull(x, z);
            return res;
        }

        int findFirst(int ll, int rr, Node node, Node node1, Node node2) {
            assert 0 <= ll && ll <= rr && rr <= n - 1;
            return findFirst(0, 0, n - 1, ll, rr, node, node1, node2);
        }

        int findLastKnowingly(int x, int l, int r, Node node, Node node1, Node node2) {
            if (l == r) {
                return l;
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res;
            if (node2.w >= node.w * 2) {
                res = findLastKnowingly(z, y + 1, r, node, node1, node2);
            } else {
                res = findLastKnowingly(x + 1, l, y, node, tree[x + 1], node2);
            }
            pull(x, z);
            return res;
        }

        int findLast(int x, int l, int r, int ll, int rr, Node node, Node node1, Node node2) {
            if (ll <= l && r <= rr) {
                if (node.w * 2 <= node1.w + node2.w) {
                    return findLastKnowingly(x, l, r, node, node1, node2);
                }
                return -1;
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res = -1;
            if (rr > y) {
                res = findLast(z, y + 1, r, ll, rr, node, node1, node2);
            }
            if (ll <= y && res == -1) {
                res = findLast(x + 1, l, y, ll, rr, node, node1, node2);
            }
            pull(x, z);
            return res;
        }

        int findLast(int ll, int rr, Node node, Node node1, Node node2) {
            assert 0 <= ll && ll <= rr && rr <= n - 1;
            return findLast(0, 0, n - 1, ll, rr, node, node1, node2);
        }

        int n;

        SegTree(int _n) {
            n = _n;
            assert n > 0;
            tree = new Node[2 * n - 1];
            for (int i = 0; i < 2 * n - 1; i++) {
                tree[i] = new Node();
            }
            build(0, 0, n - 1);
        }

        <M> SegTree(M[] v, M[] t) {
            n = v.length;
            assert n > 0;
            tree = new Node[2 * n - 1];
            for (int i = 0; i < 2 * n - 1; i++) {
                tree[i] = new Node();
            }
            build(0, 0, n - 1, v, t);
        }
    }

    static FastReader sc = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }
        SegTree st = new SegTree(w, a);
        while (q-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (x < 0) {
                x = -x;
                x--;
                st.modify(x, x, y, x, n - 1 - x, a[x]);
            } else {
                x--;
                y--;
                long v = 0;
                long sum = st.get(x, y).w;
                int pos = st.findFirst(x, y, st.get(x, x), st.get(y, y), st.get(x, y));
                assert pos != -1;
                SegTree.Node l = st.get(x, pos);
                SegTree.Node r = st.get(pos, y);
                Mint res = new Mint(0);
                res.add(r.Wp).subtract(r.fp).subtract(new Mint(a[pos] - pos).multiply(r.w));
                res.add(new Mint(a[pos] - pos).multiply(l.w)).add(l.fp).subtract(l.Wp);
                out.println(res.get());
            }
        }
        out.close();
    }
}
