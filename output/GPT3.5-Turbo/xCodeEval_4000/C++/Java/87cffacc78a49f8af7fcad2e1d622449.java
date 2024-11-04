import java.util.*;

class Main {
    static final long M = 1000000007;

    static long mod(long x, long m) {
        return ((x % m) + m) % m;
    }

    static long gcd(long a, long b) {
        for (; b > 0; a %= b, swap(a, b))
            ;
        return a;
    }

    static long extended_euclid(long a, long b, long[] x, long[] y) {
        long xx = y[0] = 0;
        long yy = x[0] = 1;
        while (b != 0) {
            long q = a / b;
            long t = b;
            b = a % b;
            a = t;
            t = xx;
            xx = x[0] - q * xx;
            x[0] = t;
            t = yy;
            yy = y[0] - q * yy;
            y[0] = t;
        }
        return a;
    }

    static long mod_inverse(long a, long n) {
        long[] x = new long[1];
        long[] y = new long[1];
        long d = extended_euclid(a, n, x, y);
        if (d > 1)
            return -1;
        return mod(x[0], n);
    }

    static class PT {
        double x, y;

        PT() {
        }

        PT(double x, double y) {
            this.x = x;
            this.y = y;
        }

        PT(final PT p) {
            x = p.x;
            y = p.y;
        }

        PT operator+(final PT p) {
            return new PT(x + p.x, y + p.y);
        }

        PT operator-(final PT p) {
            return new PT(x - p.x, y - p.y);
        }

        PT operator*(double c) {
            return new PT(x * c, y * c);
        }

        PT operator/(double c) {
            return new PT(x / c, y / c);
        }
    }

    static double dot(PT p, PT q) {
        return p.x * q.x + p.y * q.y;
    }

    static double dist2(PT p, PT q) {
        return dot(p - q, p - q);
    }

    static double cross(PT p, PT q) {
        return p.x * q.y - p.y * q.x;
    }

    static double cos_u2v(final PT u, final PT v) {
        return dot(u, v) / Math.sqrt(dot(u, u) * dot(v, v));
    }

    static double sin_u2v(final PT u, final PT v) {
        return cross(u, v) / Math.sqrt(dot(u, u) * dot(v, v));
    }

    static double vector2angle(final PT v) {
        return Math.atan2(v.y, v.x);
    }

    static class UnionFind {
        List<Long> C;

        UnionFind(long n) {
            C = new ArrayList<>();
            for (int i = 0; i < n; i++)
                C.add((long) i);
        }

        long find(long x) {
            return (C.get(x) == x) ? x : C.set(x, find(C.get(x)));
        }

        void merge(long x, long y) {
            C.set(find(x), find(y));
        }
    }

    static class LPSolver {
        int m, n;
        List<Long> B, N;
        List<List<Double>> D;

        LPSolver(final List<List<Double>> A, final List<Double> b, final List<Double> c) {
            m = b.size();
            n = c.size();
            N = new ArrayList<>();
            B = new ArrayList<>();
            D = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                List<Double> row = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    row.add(A.get(i).get(j));
                }
                D.add(row);
            }
            for (int i = 0; i < m; i++) {
                B.add((long) n + i);
                D.get(i).add(-1.0);
                D.get(i).add(b.get(i));
            }
            for (int j = 0; j < n; j++) {
                N.add((long) j);
                D.get(m).add(-c.get(j));
            }
            N.add(-1L);
            D.get(m + 1).add(1.0);
        }

        void Pivot(int r, int s) {
            for (int i = 0; i < m + 2; i++)
                if (i != r)
                    for (int j = 0; j < n + 2; j++)
                        if (j != s)
                            D.get(i).set(j, D.get(i).get(j) - D.get(r).get(j) * D.get(i).get(s) / D.get(r).get(s));
            for (int j = 0; j < n + 2; j++)
                if (j != s)
                    D.get(r).set(j, D.get(r).get(j) / D.get(r).get(s));
            for (int i = 0; i < m + 2; i++)
                if (i != r)
                    D.get(i).set(s, D.get(i).get(s) / -D.get(r).get(s));
            D.get(r).set(s, 1.0 / D.get(r).get(s));
            Collections.swap(B, r, s);
        }

        boolean Simplex(int phase) {
            int x = phase == 1 ? m + 1 : m;
            while (true) {
                int s = -1;
                for (int j = 0; j <= n; j++) {
                    if (phase == 2 && N.get(j) == -1)
                        continue;
                    if (s == -1 || D.get(x).get(j) < D.get(x).get(s)
                            || D.get(x).get(j) == D.get(x).get(s) && N.get(j) < N.get(s))
                        s = j;
                }
                if (D.get(x).get(s) > -EPS)
                    return true;
                int r = -1;
                for (int i = 0; i < m; i++) {
                    if (D.get(i).get(s) < EPS)
                        continue;
                    if (r == -1 || D.get(i).get(n + 1) / D.get(i).get(s) < D.get(r).get(n + 1) / D.get(r).get(s)
                            || (D.get(i).get(n + 1) / D.get(i).get(s)) == (D.get(r).get(n + 1) / D.get(r).get(s))
                                    && B.get(i) < B.get(r))
                        r = i;
                }
                if (r == -1)
                    return false;
                Pivot(r, s);
            }
        }

        double solve(List<Double> x) {
            int r = 0;
            for (int i = 1; i < m; i++)
                if (D.get(i).get(n + 1) < D.get(r).get(n + 1))
                    r = i;
            if (D.get(r).get(n + 1) < -EPS) {
                Pivot(r, n);
                if (!Simplex(1) || D.get(m + 1).get(n + 1) < -EPS)
                    return -Double.MAX_VALUE;
                for (int i = 0; i < m; i++)
                    if (B.get(i) == -1) {
                        int s = -1;
                        for (int j = 0; j <= n; j++)
                            if (s == -1 || D.get(i).get(j) < D.get(i).get(s)
                                    || D.get(i).get(j) == D.get(i).get(s) && N.get(j) < N.get(s))
                                s = j;
                        Pivot(i, s);
                    }
            }
            if (!Simplex(2))
                return Double.MAX_VALUE;
            x = new ArrayList<>();
            for (int i = 0; i < m; i++)
                if (B.get(i) < n)
                    x.set(B.get(i), D.get(i).get(n + 1));
            return D.get(m).get(n + 1);
        }
    }

    static void edgelist2adjlists(long n, final List<Long> froms, final List<Long> tos, List<Long> v2e0,
            List<Long> e2n) {
        v2e0 = new ArrayList<>();
        v2e0.addAll(Collections.nCopies((int) n, -1L));
        long en = froms.size();
        e2n = new ArrayList<>();
        for (int i = 0; i < en; i++) {
            long f = froms.get(i);
            long t = tos.get(i);
            e2n.set(i, v2e0.get((int) f));
            v2e0.set((int) f, i);
        }
    }

    static class FordFulk {
        final List<Long> v2e0;
        final List<Long> e2f;
        final List<Long> e2t;
        final List<Long> e2c;
        final List<Long> e2n;
        long s, t;

        FordFulk(final List<Long> _v2e0, final List<Long> _e2f, final List<Long> _e2t, final List<Long> _e2c,
                final List<Long> _e2n, long _s, long _t) {
            s = _s;
            t = _t;
            v2e0 = new ArrayList<>();
            v2e0.addAll(_v2e0);
            e2f = new ArrayList<>();
            e2f.addAll(_e2f);
            e2t = new ArrayList<>();
            e2t.addAll(_e2t);
            e2c = new ArrayList<>();
            e2c.addAll(_e2c);
            e2n = new ArrayList<>();
            e2n.addAll(_e2n);
        }

        long _find_aug_path(final List<Long> v2e0, final List<Long> e2f, final List<Long> e2t, final List<Long> e2c,
                final List<Long> e2n, long s, long t, List<Long> epath) {
            List<Long> q2v = new ArrayList<>();
            List<Long> q2p = new ArrayList<>();
            List<Long> q2e = new ArrayList<>();
            List<Long> q2f = new ArrayList<>();
            boolean[] inq = new boolean[v2e0.size()];

            q2v.add(s);
            q2p.add(-1L);
            q2e.add(-1L);
            q2f.add(Long.MAX_VALUE);
            inq[(int) s] = true;
            for (int i = 0; i < q2v.size(); i++) {
                long crt = q2v.get(i);
                long f = q2f.get(i);
                for (long j = v2e0.get((int) crt); j != -1; j = e2n.get((int) j)) {
                    long to = e2t.get((int) j);
                    long rem = e2c.get((int) j);
                    if (inq[(int) to])
                        continue;
                    if (rem <= 0)
                        continue;
                    q2v.add(to);
                    q2p.add(i);
                    q2e.add(j);
                    q2f.add(Math.min(f, rem));
                    inq[(int) to] = true;
                }
            }

            for (int i = 0; i < q2v.size(); i++) {
                if (q2v.get(i) != t)
                    continue;
                Stack<Long> stk = new Stack<>();
                for (long j = i; j > 0; j = q2p.get((int) j)) {
                    stk.push(q2e.get((int) j));
                }
                while (!stk.empty()) {
                    epath.add(stk.peek());
                    stk.pop();
                }
                return q2f.get((int) i);
            }
            return 0;
        }

        long eval() {
            long en = e2f.size();
            Map<Pair<Long, Long>, Long> rsd = new HashMap<>();
            for (int i = 0; i < en; i++) {
                long f = e2f.get(i);
                long t = e2t.get(i);
                rsd.put(new Pair<>(f, t), rsd.getOrDefault(new Pair<>(f, t), 0L) + e2c.get(i));
                rsd.put(new Pair<>(t, f), rsd.getOrDefault(new Pair<>(t, f), 0L) + 0);
            }
            Map<Pair<Long, Long>, Long> nei = new HashMap<>();
            long ren = 0;
            for (Map.Entry<Pair<Long, Long>, Long> er : rsd.entrySet()) {
                nei.put(er.getKey(), ren++);
            }
            long rvn = v2e0.size();
            List<Long> rv2e0 = new ArrayList<>();
            rv2e0.addAll(Collections.nCopies((int) rvn, -1L));
            List<Long> re2f = new ArrayList<>();
            List<Long> re2t = new ArrayList<>();
            List<Long> re2c = new ArrayList<>();
            List<Long> re2n = new ArrayList<>();
            List<Long> re2p = new ArrayList<>();
            long rei = 0;
            for (Map.Entry<Pair<Long, Long>, Long> er : rsd.entrySet()) {
                long f = er.getKey().first;
                long t = er.getKey().second;
                long c = er.getValue();
                re2f.add(f);
                re2t.add(t);
                re2c.add(c);
                re2p.add(nei.get(new Pair<>(t, f)));
                re2n.add(rv2e0.get((int) f));
                rv2e0.set((int) f, rei);
                ++rei;
            }

            long sol = 0;
            List<Long> epath = new ArrayList<>();
            while (true) {
                epath.clear();
                long res = _find_aug_path(rv2e0, re2f, re2t, re2c, re2n, s, t, epath);
                if (res == 0)
                    break;
                for (long ei : epath) {
                    re2c.set((int) ei, re2c.get((int) ei) - res);
                    re2c.set((int) re2p.get((int) ei), re2c.get((int) re2p.get((int) ei)) + res);
                }
                sol += res;
            }
            return sol;
        }
    }

    static class LazySegTree1D<T> {
        List<T> v;
        List<Long> opr;
        List<T> opd;
        List<Long> nxt;
        long LEFT;
        long RGHT;
        T (*fnx)(long, T);
        T (*fab)(T, T);

        LazySegTree1D(long _l, long _r, T _v, T (*_fnx)(long, T), T (*_fab)(T, T)) {
            v = new ArrayList<>();
            opr = new ArrayList<>();
            opd = new ArrayList<>();
            nxt = new ArrayList<>();
            LEFT = _l;
            RGHT = _r;
            fnx = _fnx;
            fab = _fab;
            v.add(fnx(RGHT - LEFT + 1, _v));
            opr.add(0L);
            opd.add(_v);
            nxt.add(-1L);
        }

        void _split(long i, long l0, long r0) {
            assert (nxt.get((int) i) == -1);
            assert (opr.get((int) i) == 0);
            assert (l0 < r0);
            long n = v.size();
            nxt.set((int) i, n);
            long m0 = (l0 + r0) / 2;
            v.add(fnx(m0 - l0 + 1, opd.get((int) i)));
            v.add(fnx(r0 - m0, opd.get((int) i)));
            opr.add(0L);
            opr.add(0L);
            opd.add(opd.get((int) i));
            opd.add(opd.get((int) i));
            nxt.add(-1L);
            nxt.add(-1L);
        }

        void _pushdown(long i, long l0, long r0) {
            if (opr.get((int) i) == -1)
                return;
            long m0 = (l0 + r0) / 2;
            if (nxt.get((int) i) == -1)
                _split(i, l0, r0);
            else if (opr.get((int) i) >= 0) {
                _set(nxt.get((int) i), l0, m0, l0, m0, opr.get((int) i), opd.get((int) i));
                _set(nxt.get((int) i) + 1, m0 + 1, r0, m0 + 1, r0, opr.get((int) i), opd.get((int) i));
            }
            opr.set((int) i, -1L);
        }

        void _set(long i, long l0, long r0, long l1, long r1, long o1, T v1) {
            assert (l1 >= l0 && r1 <= r0);
            if (l0 == l1 && r0 == r1) {
                if (o1 == 0) {
                    v.set((int) i, fnx(r0 - l0 + 1, v1));
                    opr.set((int) i, 0L);
                    opd.set((int) i, v1);
                } else if (o1 == 1) {
                    v.set((int) i, fab(v.get((int) i), fnx(r0 - l0 + 1, v1)));
                    if (opr.get((int) i) == -1) {
                        opr.set((int) i, 1L);
                        opd.set((int) i, v1);
                    } else if (opr.get((int) i) == 0) {
                        opr.set((int) i, 0L);
                        opd.set((int) i, fab(opd.get((int) i), v1));
                    } else if (opr.get((int) i) == 1) {
                        opr.set((int) i, 1L);
                        opd.set((int) i, fab(opd.get((int) i), v1));
                    }
                }
                return;
            }
            long m0 = (l0 + r0) / 2;
            _pushdown(i, l0, r0);
            if (l1 <= m0)
                _set(nxt.get((int) i), l0, m0, l1, Math.min(r1, m0), o1, v1);
            if (r1 > m0)
                _set(nxt.get((int) i) + 1, m0 + 1, r0, Math.max(l1, m0 + 1), r1, o1, v1);
            v.set((int) i, fab(v.get(nxt.get((int) i)), v.get(nxt.get((int) i) + 1)));
        }

        T _get(long i, long l0, long r0, long l1, long r1) {
            assert (l0 <= l1 && r1 <= r0);
            if (l0 == l1 && r1 == r0)
                return v.get((int) i);
            _pushdown(i, l0, r0);
            long m0 = (l0 + r0) / 2;
            if (r1 <= m0)
                return _get(nxt.get((int) i), l0, m0, l1, r1);
            if (m0 + 1 <= l1)
                return _get(nxt.get((int) i) + 1, m0 + 1, r0, l1, r1);
            T lv = _get(nxt.get((int) i), l0, m0, l1, m0);
            T rv = _get(nxt.get((int) i) + 1, m0 + 1, r0, m0 + 1, r1);
            return fab(lv, rv);
        }

        void updres(long l1, long r1, T v1) {
            _set(0, LEFT, RGHT, l1, r1, 1, v1);
        }

        void setval(long l1, long r1, T v1) {
            _set(0, LEFT, RGHT, l1, r1, 0, v1);
        }

        T get(long l1, long r1) {
            return _get(0, LEFT, RGHT, l1, r1);
        }
    }

    static boolean opp(char a, char b) {
        return a == 'W' && b == 'E' || a == 'E' && b == 'W' || a == 'S' && b == 'N' || a == 'N' && b == 'S';
    }

    static char ccinv(char x) {
        switch (x) {
            case 'N':
                return 'S';
            case 'S':
                return 'N';
            case 'W':
                return 'E';
            case 'E':
                return 'W';
        }
        return 'W';
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String r = sc.next();
        String a = sc.next();
        String b = sc.next();
        long n = a.length();
        StringBuilder ar = new StringBuilder(a).reverse().toString();
        for (int i = 0; i < n; i++) {
            ar.setCharAt(i, ccinv(ar.charAt(i)));
        }
        long va = 0;
        long vb = 0;
        long p = 1;
        for (int i = 0, j = (int) n - 1; i < n; i++, j--) {
            va = (va * 131 + ar.charAt(i)) % M;
            vb = (vb + b.charAt(j) * p) % M;
            p = (p * 131) % M;
            if (vb == va) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
