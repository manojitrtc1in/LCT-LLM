import java.util.*;
import java.util.function.Function;

class Modular<T> {
    private long value;
    private static final int MOD = (int) 1e9 + 7;

    public Modular() {
        this.value = 0;
    }

    public Modular(long x) {
        this.value = normalize(x);
    }

    private long normalize(long x) {
        long v;
        if (-mod() <= x && x < mod()) v = x;
        else v = x % mod();
        if (v < 0) v += mod();
        return v;
    }

    public long getValue() {
        return value;
    }

    public static int mod() {
        return MOD;
    }

    public Modular<T> add(Modular<T> other) {
        value += other.value;
        if (value >= mod()) value -= mod();
        return this;
    }

    public Modular<T> subtract(Modular<T> other) {
        value -= other.value;
        if (value < 0) value += mod();
        return this;
    }

    public Modular<T> multiply(Modular<T> other) {
        value = normalize(value * other.value);
        return this;
    }

    public Modular<T> divide(Modular<T> other) {
        return multiply(new Modular<>(inverse(other.value, mod())));
    }

    private long inverse(long a, long m) {
        long u = 0, v = 1;
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
        assert m == 1;
        return u;
    }

    public static Modular<T> power(Modular<T> a, long b) {
        assert b >= 0;
        Modular<T> x = a, res = new Modular<>(1);
        while (b > 0) {
            if ((b & 1) == 1) res = res.multiply(x);
            x = x.multiply(x);
            b >>= 1;
        }
        return res;
    }

    @Override
    public String toString() {
        return Long.toString(value);
    }
}

class Id0 {
    static class Node {
        long w = 0;
        Modular<Long> Wp = new Modular<>(0);
        Modular<Long> fp = new Modular<>(0);
        Modular<Long> tp = new Modular<>(0);

        void apply(int l, int r, int v, int id, int rid, int a) {
            w = v;
            Wp = new Modular<>(v).multiply(new Modular<>(a));
            fp = new Modular<>(v).multiply(new Modular<>(id));
            tp = new Modular<>(v).multiply(new Modular<>(rid));
        }
    }

    private int n;
    private List<Node> tree;

    public Id0(List<Integer> weights, List<Integer> values) {
        n = values.size();
        assert n > 0;
        tree = new ArrayList<>(Collections.nCopies(2 * n - 1, new Node()));
        build(0, 0, n - 1, values, weights);
    }

    private void build(int x, int l, int r, List<Integer> v, List<Integer> a) {
        if (l == r) {
            tree.get(x).apply(l, r, v.get(l), l, n - 1 - r, a.get(l));
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v, a);
        build(z, y + 1, r, v, a);
        pull(x, z);
    }

    private void pull(int x, int z) {
        tree.set(x, unite(tree.get(x + 1), tree.get(z)));
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
        assert 0 <= ll && ll <= rr && rr <= n - 1;
        return get(0, 0, n - 1, ll, rr);
    }

    private Node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree.get(x);
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
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
        assert 0 <= ll && ll <= rr && rr <= n - 1;
        modify(0, 0, n - 1, ll, rr, v, id, rid, a);
    }

    private void modify(int x, int l, int r, int ll, int rr, int v, int id, int rid, int a) {
        if (ll <= l && r <= rr) {
            tree.get(x).apply(l, r, v, id, rid, a);
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) a.add(scanner.nextInt());
        List<Integer> w = new ArrayList<>();
        for (int i = 0; i < n; i++) w.add(scanner.nextInt());
        Id0 st = new Id0(w, a);
        while (q-- > 0) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x < 0) {
                x = -x - 1;
                st.modify(x, x, y, x, n - 1 - x, a.get(x));
            } else {
                x--; y--;
                long v = 0;
                long sum = st.get(x, y).w;
                int pos = st.findFirst(x, y, a, v, sum);
                assert pos >= 0;
                Node l = st.get(x, pos);
                Node r = st.get(pos, y);
                Modular<Long> res = new Modular<>(0);
                res = res.add(r.Wp.subtract(r.fp).subtract(new Modular<>(a.get(pos) - pos).multiply(r.w)));
                res = res.add(new Modular<>(a.get(pos) - pos).multiply(l.w).add(l.fp).subtract(l.Wp));
                System.out.println(res);
            }
        }
        scanner.close();
    }

    private int findFirst(int x, int y, List<Integer> a, long v, long sum) {
        for (int i = x; i <= y; i++) {
            if ((v + tree.get(i).w) * 2 >= sum) return i;
            v += tree.get(i).w;
        }
        return -1;
    }
}
