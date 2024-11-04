import java.util.*;
import java.lang.Math;

class Main {
    static final long M = 1000000007;

    static class PT {
        double x, y;

        PT() {}

        PT(double x, double y) {
            this.x = x;
            this.y = y;
        }

        PT(PT p) {
            this.x = p.x;
            this.y = p.y;
        }

        PT add(PT p) {
            return new PT(this.x + p.x, this.y + p.y);
        }

        PT subtract(PT p) {
            return new PT(this.x - p.x, this.y - p.y);
        }

        PT multiply(double c) {
            return new PT(this.x * c, this.y * c);
        }

        PT divide(double c) {
            return new PT(this.x / c, this.y / c);
        }
    }

    static double dot(PT p, PT q) {
        return p.x * q.x + p.y * q.y;
    }

    static double dist2(PT p, PT q) {
        return dot(p.subtract(q), p.subtract(q));
    }

    static double cross(PT p, PT q) {
        return p.x * q.y - p.y * q.x;
    }

    static double cos_u2v(PT u, PT v) {
        return dot(u, v) / Math.sqrt(dot(u, u) * dot(v, v));
    }

    static double sin_u2v(PT u, PT v) {
        return cross(u, v) / Math.sqrt(dot(u, u) * dot(v, v));
    }

    static double vector2angle(PT v) {
        return Math.atan2(v.y, v.x);
    }

    static class UnionFind {
        long[] C;

        UnionFind(long n) {
            C = new long[(int) n];
            for (int i = 0; i < n; i++) C[i] = i;
        }

        long find(long x) {
            return (C[(int) x] == x) ? x : (C[(int) x] = find(C[(int) x]));
        }

        void merge(long x, long y) {
            C[(int) find(x)] = find(y);
        }
    }

    static long mod(long x, long m) {
        return ((x % m) + m) % m;
    }

    static long gcd(long a, long b) {
        while (b > 0) {
            long temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }

    static long extended_euclid(long a, long b, long[] x, long[] y) {
        long xx = y[0] = 0;
        long yy = x[0] = 1;
        while (b != 0) {
            long q = a / b;
            long t = b; b = a % b; a = t;
            t = xx; xx = x[0] - q * xx; x[0] = t;
            t = yy; yy = y[0] - q * yy; y[0] = t;
        }
        return a;
    }

    static long mod_inverse(long a, long n) {
        long[] x = new long[1], y = new long[1];
        long d = extended_euclid(a, n, x, y);
        if (d > 1) return -1;
        return mod(x[0], n);
    }

    static class LPSolver {
        int m, n;
        List<Long> B, N;
        double[][] D;

        LPSolver(double[][] A, double[] b, double[] c) {
            m = b.length;
            n = c.length;
            N = new ArrayList<>(Collections.nCopies(n + 1, -1L));
            B = new ArrayList<>(Collections.nCopies(m, -1L));
            D = new double[m + 2][n + 2];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    D[i][j] = A[i][j];
                }
            }
            for (int i = 0; i < m; i++) {
                B.set(i, (long) (n + i));
                D[i][n] = -1;
                D[i][n + 1] = b[i];
            }
            for (int j = 0; j < n; j++) {
                N.set(j, (long) j);
                D[m][j] = -c[j];
            }
            N.set(n, -1L);
            D[m + 1][n] = 1;
        }

        void Pivot(int r, int s) {
            for (int i = 0; i < m + 2; i++) {
                if (i != r) {
                    for (int j = 0; j < n + 2; j++) {
                        if (j != s) {
                            D[i][j] -= D[r][j] * D[i][s] / D[r][s];
                        }
                    }
                }
            }
            for (int j = 0; j < n + 2; j++) {
                if (j != s) D[r][j] /= D[r][s];
            }
            for (int i = 0; i < m + 2; i++) {
                if (i != r) D[i][s] /= -D[r][s];
            }
            D[r][s] = 1.0 / D[r][s];
            long temp = B.get(r);
            B.set(r, N.get(s));
            N.set(s, temp);
        }

        boolean Simplex(int phase) {
            int x = phase == 1 ? m + 1 : m;
            while (true) {
                int s = -1;
                for (int j = 0; j <= n; j++) {
                    if (phase == 2 && N.get(j) == -1) continue;
                    if (s == -1 || D[x][j] < D[x][s] || (D[x][j] == D[x][s] && N.get(j) < N.get(s))) {
                        s = j;
                    }
                }
                if (D[x][s] > -1e-9) return true;
                int r = -1;
                for (int i = 0; i < m; i++) {
                    if (D[i][s] < 1e-9) continue;
                    if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
                        (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B.get(i) < B.get(r)) {
                        r = i;
                    }
                }
                if (r == -1) return false;
                Pivot(r, s);
            }
        }

        double solve(double[] x) {
            int r = 0;
            for (int i = 1; i < m; i++) {
                if (D[i][n + 1] < D[r][n + 1]) r = i;
            }
            if (D[r][n + 1] < -1e-9) {
                Pivot(r, n);
                if (!Simplex(1) || D[m + 1][n + 1] < -1e-9) return Double.NEGATIVE_INFINITY;
                for (int i = 0; i < m; i++) {
                    if (B.get(i) == -1) {
                        int s = -1;
                        for (int j = 0; j <= n; j++) {
                            if (s == -1 || D[i][j] < D[i][s] || (D[i][j] == D[i][s] && N.get(j) < N.get(s))) {
                                s = j;
                            }
                        }
                        Pivot(i, s);
                    }
                }
            }
            if (!Simplex(2)) return Double.POSITIVE_INFINITY;
            Arrays.fill(x, 0);
            for (int i = 0; i < m; i++) {
                if (B.get(i) < n) x[B.get(i).intValue()] = D[i][n + 1];
            }
            return D[m][n + 1];
        }
    }

    static void edgelist2adjlists(long n, List<Long> froms, List<Long> tos, List<Long> v2e0, List<Long> e2n) {
        v2e0.clear();
        Collections.fill(v2e0, -1L);
        long en = froms.size();
        e2n.clear();
        e2n.addAll(Collections.nCopies((int) en, 0L));
        for (int i = 0; i < en; i++) {
            long f = froms.get(i);
            long t = tos.get(i);
            e2n.set(i, v2e0.get((int) f));
            v2e0.set((int) f, (long) i);
        }
    }

    static class FordFulk {
        List<Long> v2e0, e2f, e2t, e2c, e2n;
        long s, t;

        FordFulk(List<Long> _v2e0, List<Long> _e2f, List<Long> _e2t, List<Long> _e2c, List<Long> _e2n, long _s, long _t) {
            s = _s;
            t = _t;
            v2e0 = _v2e0;
            e2f = _e2f;
            e2t = _e2t;
            e2c = _e2c;
            e2n = _e2n;
        }

        long _find_aug_path(List<Long> v2e0, List<Long> e2f, List<Long> e2t, List<Long> e2c, List<Long> e2n, long s, long t, List<Long> epath) {
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
                    if (inq[(int) to]) continue;
                    if (rem <= 0) continue;
                    q2v.add(to);
                    q2p.add((long) i);
                    q2e.add(j);
                    q2f.add(Math.min(f, rem));
                    inq[(int) to] = true;
                }
            }

            for (int i = 0; i < q2v.size(); i++) {
                if (q2v.get(i) != t) continue;
                Stack<Long> stk = new Stack<>();
                for (long j = i; j > 0; j = q2p.get((int) j)) {
                    stk.push(q2e.get((int) j));
                }
                while (!stk.isEmpty()) {
                    epath.add(stk.pop());
                }
                return q2f.get((int) i);
            }
            return 0;
        }

        long eval() {
            long en = e2f.size();
            Map<Pair<Long, Long>, Long> rsd = new HashMap<>();
            for (long i = 0; i < en; i++) {
                long f = e2f.get((int) i);
                long t = e2t.get((int) i);
                rsd.put(new Pair<>(f, t), rsd.getOrDefault(new Pair<>(f, t), 0L) + e2c.get((int) i));
                rsd.put(new Pair<>(t, f), rsd.getOrDefault(new Pair<>(t, f), 0L));
            }

            Map<Pair<Long, Long>, Long> nei = new HashMap<>();
            long ren = 0;
            for (Map.Entry<Pair<Long, Long>, Long> er : rsd.entrySet()) {
                nei.put(er.getKey(), ren++);
            }

            long rvn = v2e0.size();
            List<Long> rv2e0 = new ArrayList<>(Collections.nCopies((int) rvn, -1L));
            List<Long> re2f = new ArrayList<>(Collections.nCopies((int) ren, 0L));
            List<Long> re2t = new ArrayList<>(Collections.nCopies((int) ren, 0L));
            List<Long> re2c = new ArrayList<>(Collections.nCopies((int) ren, 0L));
            List<Long> re2n = new ArrayList<>(Collections.nCopies((int) ren, 0L));
            List<Long> re2p = new ArrayList<>(Collections.nCopies((int) ren, 0L));

            long rei = 0;
            for (Map.Entry<Pair<Long, Long>, Long> er : rsd.entrySet()) {
                long f = er.getKey().getKey();
                long t = er.getKey().getValue();
                long c = er.getValue();
                re2f.set((int) rei, f);
                re2t.set((int) rei, t);
                re2c.set((int) rei, c);
                re2p.set((int) rei, nei.get(new Pair<>(t, f)));
                re2n.set((int) rei, rv2e0.get((int) f));
                rv2e0.set((int) f, rei);
                rei++;
            }

            long sol = 0;
            List<Long> epath = new ArrayList<>();
            while (true) {
                epath.clear();
                long res = _find_aug_path(rv2e0, re2f, re2t, re2c, re2n, s, t, epath);
                if (res == 0) break;
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
        BiFunction<Long, T, T> fnx;
        BiFunction<T, T, T> fab;

        LazySegTree1D(long _l, long _r, T _v, BiFunction<Long, T, T> _fnx, BiFunction<T, T, T> _fab) {
            v = new ArrayList<>(Collections.nCopies(1, null));
            opr = new ArrayList<>(Collections.nCopies(1, 0L));
            opd = new ArrayList<>(Collections.nCopies(1, null));
            nxt = new ArrayList<>(Collections.nCopies(1, -1L));
            LEFT = _l;
            RGHT = _r;
            fnx = _fnx;
            fab = _fab;
            v.set(0, fnx.apply(RGHT - LEFT + 1, _v));
            opr.set(0, 0L);
            opd.set(0, _v);
        }

        void _split(long i, long l0, long r0) {
            assert (nxt.get((int) i) == -1);
            assert (opr.get((int) i) == 0);
            assert (l0 < r0);
            long n = v.size();
            nxt.set((int) i, n);
            long m0 = (l0 + r0) / 2;
            v.add(fnx.apply(m0 - l0 + 1, opd.get((int) i)));
            v.add(fnx.apply(r0 - m0, opd.get((int) i)));
            opr.add(0L);
            opr.add(0L);
            opd.add(opd.get((int) i));
            opd.add(opd.get((int) i));
            nxt.add(-1L);
            nxt.add(-1L);
        }

        void _pushdown(long i, long l0, long r0) {
            if (opr.get((int) i) == -1) return;
            long m0 = (l0 + r0) / 2;
            if (nxt.get((int) i) == -1) {
                _split(i, l0, r0);
            } else if (opr.get((int) i) >= 0) {
                _set(nxt.get((int) i), l0, m0, l0, m0, opr.get((int) i), opd.get((int) i));
                _set(nxt.get((int) i) + 1, m0 + 1, r0, m0 + 1, r0, opr.get((int) i), opd.get((int) i));
            }
            opr.set((int) i, -1L);
        }

        void _set(long i, long l0, long r0, long l1, long r1, long o1, T v1) {
            assert (l1 >= l0 && r1 <= r0);
            if (l0 == l1 && r0 == r1) {
                if (o1 == 0) {
                    v.set((int) i, fnx.apply(r0 - l0 + 1, v1));
                    opr.set((int) i, 0L);
                    opd.set((int) i, v1);
                } else if (o1 == 1) {
                    v.set((int) i, fab.apply(v.get((int) i), fnx.apply(r0 - l0 + 1, v1)));
                    if (opr.get((int) i) == -1) {
                        opr.set((int) i, 1L);
                        opd.set((int) i, v1);
                    } else if (opr.get((int) i) == 0) {
                        opr.set((int) i, 0L);
                        opd.set((int) i, fab.apply(opd.get((int) i), v1));
                    } else if (opr.get((int) i) == 1) {
                        opr.set((int) i, 1L);
                        opd.set((int) i, fab.apply(opd.get((int) i), v1));
                    }
                }
                return;
            }
            long m0 = (l0 + r0) / 2;
            _pushdown(i, l0, r0);
            if (l1 <= m0) _set(nxt.get((int) i), l0, m0, l1, Math.min(r1, m0), o1, v1);
            if (r1 > m0) _set(nxt.get((int) i) + 1, m0 + 1, r0, Math.max(l1, m0 + 1), r1, o1, v1);
            v.set((int) i, fab.apply(v.get((int) nxt.get((int) i)), v.get((int) nxt.get((int) i) + 1)));
        }

        T _get(long i, long l0, long r0, long l1, long r1) {
            assert (l0 <= l1 && r1 <= r0);
            if (l0 == l1 && r1 == r0) return v.get((int) i);
            _pushdown(i, l0, r0);
            long m0 = (l0 + r0) / 2;
            if (r1 <= m0) return _get(nxt.get((int) i), l0, m0, l1, r1);
            if (m0 + 1 <= l1) return _get(nxt.get((int) i) + 1, m0 + 1, r0, l1, r1);
            T lv = _get(nxt.get((int) i), l0, m0, l1, m0);
            T rv = _get(nxt.get((int) i) + 1, m0 + 1, r0, m0 + 1, r1);
            return fab.apply(lv, rv);
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
        return (a == 'W' && b == 'E') || (a == 'E' && b == 'W') || (a == 'S' && b == 'N') || (a == 'N' && b == 'S');
    }

    static char ccinv(char x) {
        switch (x) {
            case 'N': return 'S';
            case 'S': return 'N';
            case 'W': return 'E';
            case 'E': return 'W';
        }
        return 'W';
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random rand = new Random();
        rand.setSeed(System.currentTimeMillis());

        String r = scanner.next();
        String a = scanner.next();
        String b = scanner.next();
        long n = a.length();
        StringBuilder ar = new StringBuilder(a).reverse();
        for (int i = 0; i < n; i++) {
            ar.setCharAt(i, ccinv(ar.charAt(i)));
        }
        long va = 0;
        long vb = 0;
        long p = 1;
        for (int i = 0, j = (int) (n - 1); i < n; i++, j--) {
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
