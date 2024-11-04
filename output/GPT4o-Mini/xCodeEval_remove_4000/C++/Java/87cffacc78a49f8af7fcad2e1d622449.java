import java.util.*;

public class 87cffacc78a49f8af7fcad2e1d622449xcodeeval_processed_4000.json {
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
            return new PT(x + p.x, y + p.y);
        }

        PT subtract(PT p) {
            return new PT(x - p.x, y - p.y);
        }

        PT multiply(double c) {
            return new PT(x * c, y * c);
        }

        PT divide(double c) {
            return new PT(x / c, y / c);
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

    static double id22(PT u, PT v) {
        return dot(u, v) / Math.sqrt(dot(u, u) * dot(v, v));
    }

    static double id6(PT u, PT v) {
        return cross(u, v) / Math.sqrt(dot(u, u) * dot(v, v));
    }

    static double id17(PT v) {
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

    static long id11(long a, long b, long[] x, long[] y) {
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
        long[] x = new long[1], y = new long[1];
        long d = id11(a, n, x, y);
        if (d > 1) return -1;
        return mod(x[0], n);
    }

    static void id8(long n, List<Long> froms, List<Long> tos, List<Long> id16, List<Long> id4) {
        id16.clear();
        for (long i = 0; i < n; i++) id16.add(-1L);
        long en = froms.size();
        id4.clear();
        for (int i = 0; i < en; i++) {
            long f = froms.get(i);
            long t = tos.get(i);
            id4.add(id16.get((int) f));
            id16.set((int) f, (long) i);
        }
    }

    static class id18 {
        List<Long> id16, id13, id7, id9, id4;
        long s, t;

        id18(List<Long> id23, List<Long> id2, List<Long> id26, List<Long> id14, List<Long> id5, long _s, long _t) {
            s = _s;
            t = _t;
            id16 = id23;
            id13 = id2;
            id7 = id26;
            id9 = id14;
            id4 = id5;
        }

        long _find_aug_path(List<Long> id16, List<Long> id13, List<Long> id7, List<Long> id9, List<Long> id4, long s, long t, List<Long> epath) {
            List<Long> id24 = new ArrayList<>();
            List<Long> id0 = new ArrayList<>();
            List<Long> id21 = new ArrayList<>();
            List<Long> id27 = new ArrayList<>();
            boolean[] inq = new boolean[id16.size()];

            id24.add(s);
            id0.add(-1L);
            id21.add(-1L);
            id27.add(Long.MAX_VALUE);
            inq[(int) s] = true;

            for (long i = 0; i < id24.size(); i++) {
                long crt = id24.get((int) i);
                long f = id27.get((int) i);
                for (long j = id16.get((int) crt); j != -1; j = id4.get((int) j).intValue()) {
                    long to = id7.get((int) j);
                    long rem = id9.get((int) j);
                    if (inq[(int) to]) continue;
                    if (rem <= 0) continue;
                    id24.add(to);
                    id0.add(i);
                    id21.add(j);
                    id27.add(Math.min(f, rem));
                    inq[(int) to] = true;
                }
            }

            for (long i = 0; i < id24.size(); i++) {
                if (id24.get((int) i) != t) continue;
                Stack<Long> stk = new Stack<>();
                for (long j = i; j > 0; j = id0.get((int) j)) {
                    stk.push(id21.get((int) j));
                }
                while (!stk.isEmpty()) {
                    epath.add(stk.pop());
                }
                return id27.get((int) i);
            }
            return 0;
        }

        long eval() {
            long en = id13.size();
            Map<Pair<Long, Long>, Long> rsd = new HashMap<>();
            for (long i = 0; i < en; i++) {
                long f = id13.get((int) i);
                long t = id7.get((int) i);
                rsd.put(new Pair<>(f, t), rsd.getOrDefault(new Pair<>(f, t), 0L) + id9.get((int) i));
                rsd.put(new Pair<>(t, f), rsd.getOrDefault(new Pair<>(t, f), 0L));
            }
            Map<Pair<Long, Long>, Long> nei = new HashMap<>();
            long ren = 0;
            for (Map.Entry<Pair<Long, Long>, Long> er : rsd.entrySet()) {
                nei.put(er.getKey(), ren++);
            }
            long rvn = id16.size();
            List<Long> id12 = new ArrayList<>(Collections.nCopies((int) rvn, -1L));
            List<Long> id20 = new ArrayList<>(Collections.nCopies((int) ren, 0L));

            List<Long> id1 = new ArrayList<>(Collections.nCopies((int) ren, 0L));
            List<Long> id10 = new ArrayList<>(Collections.nCopies((int) ren, 0L));
            List<Long> id15 = new ArrayList<>(Collections.nCopies((int) ren, 0L));
            List<Long> id25 = new ArrayList<>(Collections.nCopies((int) ren, 0L));

            long rei = 0;
            for (Map.Entry<Pair<Long, Long>, Long> er : rsd.entrySet()) {
                long f = er.getKey().getKey();
                long t = er.getKey().getValue();
                long c = er.getValue();
                id20.set((int) rei, f);
                id1.set((int) rei, t);
                id10.set((int) rei, c);
                id25.set((int) rei, nei.get(new Pair<>(t, f)));
                id15.set((int) rei, id12.get((int) f));
                id12.set((int) f, rei);
                rei++;
            }

            long sol = 0;
            List<Long> epath = new ArrayList<>();
            while (true) {
                epath.clear();
                long res = _find_aug_path(id12, id20, id1, id10, id15, s, t, epath);
                if (res == 0) break;
                for (long ei : epath) {
                    id10.set((int) ei, id10.get((int) ei) - res);
                    id10.set((int) id25.get((int) ei), id10.get((int) id25.get((int) ei)) + res);
                }
                sol += res;
            }
            return sol;
        }
    }

    static class id19<T> {
        List<T> v;
        List<Long> opr;
        List<T> opd;
        List<Long> nxt;
        long LEFT;
        long RGHT;
        BiFunction<Long, T, T> fnx;
        BiFunction<T, T, T> fab;

        id19(long _l, long _r, T _v, BiFunction<Long, T, T> _fnx, BiFunction<T, T, T> _fab) {
            v = new ArrayList<>(Collections.singletonList(_fnx.apply(_r - _l + 1, _v)));
            opr = new ArrayList<>(Collections.singletonList(0L));
            opd = new ArrayList<>(Collections.singletonList(_v));
            nxt = new ArrayList<>(Collections.singletonList(-1L));
            LEFT = _l;
            RGHT = _r;
            fnx = _fnx;
            fab = _fab;
        }

        void _split(long i, long l0, long r0) {
            assert nxt.get((int) i) == -1;
            assert opr.get((int) i) == 0;
            assert l0 < r0;
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
            if (nxt.get((int) i) == -1)
                _split(i, l0, r0);
            else if (opr.get((int) i) >= 0) {
                _set(nxt.get((int) i), l0, m0, l0, m0, opr.get((int) i), opd.get((int) i));
                _set(nxt.get((int) i) + 1, m0 + 1, r0, m0 + 1, r0, opr.get((int) i), opd.get((int) i));
            }
            opr.set((int) i, -1L);
        }

        void _set(long i, long l0, long r0, long l1, long r1, long o1, T v1) {
            assert l1 >= l0 && r1 <= r0;
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
            assert l0 <= l1 && r1 <= r0;
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
        for (long i = 0; i < n; i++) {
            ar.setCharAt((int) i, ccinv(ar.charAt((int) i)));
        }
        long va = 0;
        long vb = 0;
        long p = 1;
        for (long i = 0, j = n - 1; i < n; i++, j--) {
            va = (va * 131 + ar.charAt((int) i)) % M;
            vb = (vb + b.charAt((int) j) * p) % M;
            p = (p * 131) % M;
            if (vb == va) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
