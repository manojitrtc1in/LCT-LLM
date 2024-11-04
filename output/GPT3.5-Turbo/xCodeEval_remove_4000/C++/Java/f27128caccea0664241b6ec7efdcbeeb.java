import java.util.*;
import java.io.*;

class Main {
    static class Modular<T> {
        private T value;

        public Modular() {
            value = null;
        }

        public Modular(T x) {
            value = normalize(x);
        }

        public T getValue() {
            return value;
        }

        public static <U> U normalize(U x) {
            return x;
        }

        public Modular<T> add(Modular<T> other) {
            return new Modular<>(value + other.value);
        }

        public Modular<T> subtract(Modular<T> other) {
            return new Modular<>(value - other.value);
        }

        public Modular<T> multiply(Modular<T> other) {
            return new Modular<>(value * other.value);
        }

        public Modular<T> divide(Modular<T> other) {
            return new Modular<>(value / other.value);
        }

        public boolean equals(Modular<T> other) {
            return value.equals(other.value);
        }

        public boolean lessThan(Modular<T> other) {
            return value < other.value;
        }

        public String toString() {
            return value.toString();
        }
    }

    static class id0 {
        static class Node {
            long w;
            Modular<Long> Wp;
            Modular<Long> fp;
            Modular<Long> tp;

            public Node() {
                w = 0;
                Wp = new Modular<>(0L);
                fp = new Modular<>(0L);
                tp = new Modular<>(0L);
            }

            public void apply(int l, int r, int v, int id, int rid, int a) {
                w = v;
                Wp = new Modular<>(v).multiply(new Modular<>(a));
                fp = new Modular<>(v).multiply(new Modular<>(id));
                tp = new Modular<>(v).multiply(new Modular<>(rid));
            }
        }

        private int n;
        private List<Node> tree;

        private Node unite(Node a, Node b) {
            Node res = new Node();
            res.w = a.w + b.w;
            res.Wp = a.Wp.add(b.Wp);
            res.fp = a.fp.add(b.fp);
            res.tp = a.tp.add(b.tp);
            return res;
        }

        private void push(int x, int l, int r) {

        }

        private void pull(int x, int z) {
            tree.set(x, unite(tree.get(x + 1), tree.get(z)));
        }

        public id0(int _n) {
            n = _n;
            tree = new ArrayList<>();
            for (int i = 0; i < 2 * n - 1; i++) {
                tree.add(new Node());
            }
            build(0, 0, n - 1);
        }

        private void build(int x, int l, int r) {
            if (l == r) {
                return;
            }
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            build(x + 1, l, y);
            build(z, y + 1, r);
            pull(x, z);
        }

        public id0(List<Integer> v, List<Integer> t) {
            n = v.size();
            assert(n > 0);
            tree = new ArrayList<>();
            for (int i = 0; i < 2 * n - 1; i++) {
                tree.add(new Node());
            }
            build(0, 0, n - 1, v, t);
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

        public Node get(int x, int l, int r, int ll, int rr) {
            if (ll <= l && r <= rr) {
                return tree.get(x);
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

        public Node get(int ll, int rr) {
            assert(0 <= ll && ll <= rr && rr <= n - 1);
            return get(0, 0, n - 1, ll, rr);
        }

        public Node get(int p) {
            assert(0 <= p && p <= n - 1);
            return get(0, 0, n - 1, p, p);
        }

        public void modify(int x, int l, int r, int ll, int rr, int v, int id, int rid, int a) {
            if (ll <= l && r <= rr) {
                tree.get(x).apply(l, r, v, id, rid, a);
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

        public void modify(int ll, int rr, int v, int id, int rid, int a) {
            assert(0 <= ll && ll <= rr && rr <= n - 1);
            modify(0, 0, n - 1, ll, rr, v, id, rid, a);
        }

        public int find_first_knowingly(int x, int l, int r, Function<Node, Boolean> f) {
            if (l == r) {
                return l;
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res;
            if (f.apply(tree.get(x + 1))) {
                res = find_first_knowingly(x + 1, l, y, f);
            } else {
                res = find_first_knowingly(z, y + 1, r, f);
            }
            pull(x, z);
            return res;
        }

        public int find_first(int x, int l, int r, int ll, int rr, Function<Node, Boolean> f) {
            if (ll <= l && r <= rr) {
                if (!f.apply(tree.get(x))) {
                    return -1;
                }
                return find_first_knowingly(x, l, r, f);
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res = -1;
            if (ll <= y) {
                res = find_first(x + 1, l, y, ll, rr, f);
            }
            if (rr > y && res == -1) {
                res = find_first(z, y + 1, r, ll, rr, f);
            }
            pull(x, z);
            return res;
        }

        public int find_first(int ll, int rr, Function<Node, Boolean> f) {
            assert(0 <= ll && ll <= rr && rr <= n - 1);
            return find_first(0, 0, n - 1, ll, rr, f);
        }

        public int find_last_knowingly(int x, int l, int r, Function<Node, Boolean> f) {
            if (l == r) {
                return l;
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res;
            if (f.apply(tree.get(z))) {
                res = find_last_knowingly(z, y + 1, r, f);
            } else {
                res = find_last_knowingly(x + 1, l, y, f);
            }
            pull(x, z);
            return res;
        }

        public int find_last(int x, int l, int r, int ll, int rr, Function<Node, Boolean> f) {
            if (ll <= l && r <= rr) {
                if (!f.apply(tree.get(x))) {
                    return -1;
                }
                return find_last_knowingly(x, l, r, f);
            }
            push(x, l, r);
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            int res = -1;
            if (rr > y) {
                res = find_last(z, y + 1, r, ll, rr, f);
            }
            if (ll <= y && res == -1) {
                res = find_last(x + 1, l, y, ll, rr, f);
            }
            pull(x, z);
            return res;
        }

        public int find_last(int ll, int rr, Function<Node, Boolean> f) {
            assert(0 <= ll && ll <= rr && rr <= n - 1);
            return find_last(0, 0, n - 1, ll, rr, f);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        List<Integer> a = new ArrayList<>();
        List<Integer> w = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w.add(Integer.parseInt(st.nextToken()));
        }
        id0 st = new id0(w, a);
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (x < 0) {
                x = -x;
                x--;
                st.modify(x, x, y, x, n - 1 - x, a.get(x));
            } else {
                x--;
                y--;
                long v = 0;
                long sum = st.get(x, y).w;
                int pos = st.find_first(x, y, (Node a) -> {
                    if ((v + a.w) * 2 >= sum) return true;
                    v += a.w;
                    return false;
                });
                assert (pos != -1);
                id0.Node l = st.get(x, pos);
                id0.Node r = st.get(pos, y);
                Modular<Long> res = new Modular<>(0L);

                res = res.add(r.Wp).subtract(r.fp).subtract(new Modular<>(a.get(pos) - pos).multiply(r.w));

                res = res.add(new Modular<>(a.get(pos) - pos).multiply(l.w)).add(l.fp).subtract(l.Wp);
                System.out.println(res);
            }
        }
    }
}
