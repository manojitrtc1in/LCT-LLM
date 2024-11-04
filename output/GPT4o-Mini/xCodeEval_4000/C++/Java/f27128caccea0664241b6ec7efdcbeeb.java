import java.util.*;
import java.util.function.Function;

class Modular<T> {
    private long value;
    private static final int MOD = (int) 1e9 + 7;

    public Modular() {
        this.value = 0;
    }

    public Modular(long x) {
        value = normalize(x);
    }

    private long normalize(long x) {
        if (x < 0) x += MOD;
        return x % MOD;
    }

    public long getValue() {
        return value;
    }

    public Modular<T> add(Modular<T> other) {
        value = normalize(value + other.value);
        return this;
    }

    public Modular<T> subtract(Modular<T> other) {
        value = normalize(value - other.value);
        return this;
    }

    public Modular<T> multiply(Modular<T> other) {
        value = normalize(value * other.value);
        return this;
    }

    public Modular<T> divide(Modular<T> other) {
        return multiply(new Modular<>(inverse(other.value)));
    }

    private long inverse(long a) {
        long m = MOD, u = 0, v = 1;
        while (a != 0) {
            long t = m / a;
            m -= t * a; 
            long temp = a; 
            a = m; 
            m = temp;
            u -= t * v; 
            temp = u; 
            u = v; 
            v = temp;
        }
        return normalize(u);
    }

    @Override
    public String toString() {
        return Long.toString(value);
    }
}

class SegmentTree {
    static class Node {
        long w = 0;
        Modular<Long> Wp = new Modular<>();
        Modular<Long> fp = new Modular<>();
        Modular<Long> tp = new Modular<>();

        void apply(int l, int r, int v, int id, int rid, int a) {
            w = v;
            Wp = new Modular<>(v).multiply(a);
            fp = new Modular<>(v).multiply(id);
            tp = new Modular<>(v).multiply(rid);
        }
    }

    private Node[] tree;
    private int n;

    public SegmentTree(int n) {
        this.n = n;
        tree = new Node[2 * n - 1];
        for (int i = 0; i < tree.length; i++) {
            tree[i] = new Node();
        }
    }

    public SegmentTree(int[] v, int[] a) {
        this(v.length);
        build(0, 0, n - 1, v, a);
    }

    private void build(int x, int l, int r, int[] v, int[] a) {
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

    private void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }

    private Node unite(Node a, Node b) {
        Node res = new Node();
        res.w = a.w + b.w;
        res.Wp = a.Wp.add(b.Wp);
        res.fp = a.fp.add(b.fp);
        res.tp = a.tp.add(b.tp);
        return res;
    }

    public Node get(int ll, int rr) {
        return get(0, 0, n - 1, ll, rr);
    }

    private Node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1;
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

    public void modify(int ll, int rr, int v, int id, int rid, int a) {
        modify(0, 0, n - 1, ll, rr, v, id, rid, a);
    }

    private void modify(int x, int l, int r, int ll, int rr, int v, int id, int rid, int a) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v, id, rid, a);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v, id, rid, a);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v, id, rid, a);
        }
        pull(x, z);
    }
}

public class f27128caccea0664241b6ec7efdcbeeb_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }
        SegmentTree st = new SegmentTree(w, a);
        while (q-- > 0) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x < 0) {
                x = -x - 1;
                st.modify(x, x, y, x, n - 1 - x, a[x]);
            } else {
                x--; y--;
                long v = 0;
                long sum = st.get(x, y).w;
                int pos = st.findFirst(x, y, a, v, sum);
                assert pos != -1;
                SegmentTree.Node l = st.get(x, pos);
                SegmentTree.Node r = st.get(pos, y);
                Modular<Long> res = new Modular<>(0);
                res.add(r.Wp.subtract(r.fp).subtract(new Modular<>(a[pos] - pos).multiply(r.w)));
                res.add(new Modular<>(a[pos] - pos).multiply(l.w).add(l.fp).subtract(l.Wp));
                System.out.println(res);
            }
        }
        scanner.close();
    }
}
