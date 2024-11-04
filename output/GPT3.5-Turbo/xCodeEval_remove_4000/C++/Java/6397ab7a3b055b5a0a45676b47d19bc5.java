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

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Complex {
        double real;
        double imag;

        public Complex(double real, double imag) {
            this.real = real;
            this.imag = imag;
        }
    }

    static final double eps = 1e-9;
    static final double INFD = Double.POSITIVE_INFINITY;
    static final double PI = 3.14159265358979323846;

    static boolean id6(double x, double y) {
        return Math.abs(x - y) < eps;
    }

    static boolean inrange(long x, long t) {
        return x >= 0 && x < t;
    }

    static boolean inrange(List<Long> xs, long t) {
        for (long x : xs) {
            if (!(x >= 0 && x < t))
                return false;
        }
        return true;
    }

    static int id5(long x) {
        int ret = 0;
        x--;
        while (x > 0) {
            ret++;
            x >>= 1;
        }
        return ret;
    }

    static long rndf(double x) {
        return (long) (x + (x >= 0 ? 0.5 : -0.5));
    }

    static long id2(long x) {
        long m = (long) Math.sqrt((double) x);
        return m + (m * m <= x ? 0 : -1);
    }

    static long id8(long x) {
        long m = (long) Math.sqrt((double) x);
        return m + (x <= m * m ? 0 : 1);
    }

    static long rnddiv(long a, long b) {
        return (a / b + (a % b * 2 >= b ? 1 : 0));
    }

    static long ceildiv(long a, long b) {
        return (a / b + (a % b == 0 ? 0 : 1));
    }

    static long gcd(long m, long n) {
        if (n == 0)
            return m;
        else
            return gcd(n, m % n);
    }

    static long lcm(long m, long n) {
        return m * n / gcd(m, n);
    }

    static class SegTree<T> {
        protected int n, N;

        int base;
        List<T> nodes;

        int left_of(int index) {
            if (index >= base)
                return -1;
            else
                return index * 2 + 1;
        }

        int right_of(int index) {
            if (index >= base)
                return -1;
            else
                return index * 2 + 2;
        }

        int parent_of(int index) {
            if (index == 0)
                return -1;
            else
                return (index - 1) >> 1;
        }

        void update_rec(int s, int t, int l, int r, int index, T v) {
            if (s == l && t == r) {
                nodes.set(index, v);
            } else {
                int mid = (l + r) / 2;
                int index_l = left_of(index);
                int index_r = right_of(index);
                if (s < mid && mid < t) {
                    update_rec(s, mid, l, mid, index_l, v);
                    update_rec(mid, t, mid, r, index_r, v);
                } else if (s < mid) {
                    update_rec(s, t, l, mid, index_l, v);
                } else if (mid < t) {
                    update_rec(s, t, mid, r, index_r, v);
                }
                nodes.set(index, nodes.get(index_l) + nodes.get(index_r));
            }
        }

        T add_rec(int s, int t, int l, int r, int index) {
            if (s == l && t == r) {
                return nodes.get(index);
            } else {
                int mid = (l + r) / 2;
                int index_l = left_of(index);
                int index_r = right_of(index);
                T v0 = null, v1 = null;
                if (s < mid && mid < t) {
                    v0 = add_rec(s, mid, l, mid, index_l);
                    v1 = add_rec(mid, t, mid, r, index_r);
                } else if (s < mid) {
                    v0 = add_rec(s, t, l, mid, index_l);
                } else if (mid < t) {
                    v1 = add_rec(s, t, mid, r, index_r);
                }
                return v0 + v1;
            }
        }

        public SegTree(int n, T init) {
            this.n = n;
            N = (int) Math.pow(2, Math.ceil(Math.log(n) / Math.log(2)));
            base = N - 1;
            nodes = new ArrayList<>(Collections.nCopies(base + N, init));
        }

        List<Integer> get_index_above(int index, boolean from_base) {
            if (from_base)
                index += base;
            List<Integer> ret = new ArrayList<>();
            while (index >= 0) {
                ret.add(index);
                index = parent_of(index);
            }
            return ret;
        }

        int cover_size(int index) {
            int cnt = 1;
            while (left_of(index) != -1) {
                index = left_of(index);
                cnt *= 2;
            }
            int l = index - base;
            int r = Math.min(l + cnt, n);
            return Math.max(0, r - l);
        }

        void update(int k, T v) {
            update_rec(k, k + 1, 0, N, 0, v);
        }

        T sum(int s, int t) {
            return add_rec(s, t, 0, N, 0);
        }
    }

    static class bsargv_t {
        SegTree<Long> st;
        int s;
        long sum;

        public bsargv_t(SegTree<Long> st, int s, long sum) {
            this.st = st;
            this.s = s;
            this.sum = sum;
        }
    }

    static boolean evalfunc(int val, bsargv_t v) {
        long buf = v.st.sum(v.s, val + 1);
        if (buf <= v.sum / 2)
            return true;
        else
            return false;
    }

    static class modll {
        static final long MOD = (long) 1e9 + 7;

        long val;

        long modify(long x) {
            long ret = x % MOD;
            if (ret < 0)
                ret += MOD;
            return ret;
        }

        long inv(long x) {
            if (x == 0)
                return 1 / x;
            else if (x == 1)
                return 1;
            else
                return modify(inv(MOD % x) * modify(-MOD / x));
        }

        public modll(long init) {
            val = modify(init);
        }

        public modll(modll another) {
            val = another.val;
        }

        modll add(modll x) {
            return modify(val + x.val);
        }

        modll subtract(modll x) {
            return modify(val - x.val);
        }

        modll multiply(modll x) {
            return modify(val * x.val);
        }

        modll divide(modll x) {
            return modify(val * inv(x.val));
        }

        modll addAssign(modll x) {
            val = modify(val + x.val);
            return this;
        }

        modll subtractAssign(modll x) {
            val = modify(val - x.val);
            return this;
        }

        modll multiplyAssign(modll x) {
            val = modify(val * x.val);
            return this;
        }

        modll divideAssign(modll x) {
            val = modify(val * inv(x.val));
            return this;
        }

        boolean equals(modll x) {
            return val == x.val;
        }

        boolean notEquals(modll x) {
            return val != x.val;
        }

        long getVal() {
            return val;
        }

        @Override
        public String toString() {
            return Long.toString(val);
        }
    }

    static modll pow(modll n, long p) {
        modll ret;
        if (p == 0)
            ret = new modll(1);
        else if (p == 1)
            ret = n;
        else {
            ret = pow(n, p / 2);
            ret.multiplyAssign(ret);
            if (p % 2 == 1)
                ret.multiplyAssign(n);
        }
        return ret;
    }

    static List<modll> facts;

    static void id7(int n) {
        if (facts.isEmpty())
            facts.add(new modll(1));
        for (int i = facts.size(); i <= n; ++i)
            facts.add(new modll(facts.get(facts.size() - 1).multiply(i)));
    }

    static List<modll> ifacts;
    static List<modll> invs;

    static void id1(int n) {
        if (invs.isEmpty()) {
            invs.add(new modll(0));
            invs.add(new modll(1));
        }
        for (int i = invs.size(); i <= n; ++i) {
            invs.add(invs.get((int) (MOD % i)).multiply(new modll(MOD - MOD / i)));
        }
    }

    static void id0(int n) {
        id1(n);
        if (ifacts.isEmpty())
            ifacts.add(new modll(1));
        for (int i = ifacts.size(); i <= n; ++i)
            ifacts.add(ifacts.get(ifacts.size() - 1).multiply(invs.get(i)));
    }

    static modll combination(long n, long r) {
        if (n >= r && r >= 0) {
            modll ret;
            id7((int) n);
            id0((int) n);
            ret = facts.get((int) n).multiply(ifacts.get((int) r)).multiply(ifacts.get((int) (n - r)));
            return ret;
        } else
            return new modll(0);
    }

    static modll getFact(long n) {
        id7((int) n);
        return facts.get((int) n);
    }

    static modll id3(long n) {
        id0((int) n);
        return ifacts.get((int) n);
    }

    static long disc_log(modll a, modll b) {
        long ret = -1;
        long m = id8(MOD);
        Map<Long, Long> mp = new HashMap<>();
        modll x = new modll(1);
        for (int i = 0; i < m; i++) {
            mp.put(x.getVal(), (long) i);
            x.multiplyAssign(a);
        }
        x = new modll(1).divide(pow(a, m));
        modll k = b;
        for (int i = 0; i < m; i++) {
            if (!mp.containsKey(k.getVal()))
                k.multiplyAssign(x);
            else {
                ret = i * m + mp.get(k.getVal());
                break;
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int q = sc.nextInt();
        List<Long> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextLong());
        }
        SegTree<Long> st = new SegTree<>(n, 0L);
        SegTree<modll> ast = new SegTree<>(n, new modll(0));
        SegTree<modll> lst = new SegTree<>(n, new modll(0));
        SegTree<modll> rst = new SegTree<>(n, new modll(0));
        for (int i = 0; i < n; i++) {
            long w = sc.nextLong();
            st.update(i, w);
            ast.update(i, new modll(w).multiply(a.get(i)));
            lst.update(i, new modll(w).multiply(n - 1 - i));
            rst.update(i, new modll(w).multiply(i));
        }
        List<modll> ans = new ArrayList<>();
        for (int unused = 0; unused < q; unused++) {
            int x = sc.nextInt();
            if (x < 0) {
                x++;
                long y = sc.nextLong();
                st.update(-x, y);
                ast.update(-x, new modll(y).multiply(a.get(-x)));
                lst.update(-x, new modll(y).multiply(n - 1 - (-x)));
                rst.update(-x, new modll(y).multiply(-x));
            } else {
                int y = sc.nextInt();
                x--;
                y--;
                if (x == y) {
                    ans.add(new modll(0));
                } else {
                    int halfid;
                    if (y - x == 1) {
                        halfid = x;
                    } else {
                        bsargv_t v = new bsargv_t(st, x, st.sum(x, y + 1));
                        halfid = id4(x + 1, y, v, Main::evalfunc);
                    }
                    long cand0 = st.sum(x, halfid + 1);
                    long cand1 = st.sum(halfid + 1, y + 1);
                    long dst;
                    int dstid;
                    if (cand0 <= cand1) {
                        dst = a.get(halfid + 1);
                        dstid = halfid + 1;
                    } else {
                        dst = a.get(halfid);
                        dstid = halfid;
                    }
                    modll buf = new modll(0);
                    buf.addAssign(new modll(dst).multiply(st.sum(x, dstid)));
                    buf.subtractAssign(ast.sum(x, dstid));
                    buf.subtractAssign(lst.sum(x, dstid).subtract(new modll(st.sum(x, dstid)).multiply(n - 1 - dstid)));
                    buf.addAssign(ast.sum(dstid, y + 1));
                    buf.subtractAssign(new modll(dst).multiply(st.sum(dstid, y + 1)));
                    buf.subtractAssign(rst.sum(dstid, y + 1).subtract(new modll(st.sum(dstid, y + 1)).multiply(dstid)));
                    ans.add(buf);
                }
            }
        }
        for (modll val : ans) {
            System.out.println(val);
        }
    }
}
