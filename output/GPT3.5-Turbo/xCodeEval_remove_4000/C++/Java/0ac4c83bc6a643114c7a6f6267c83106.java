import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Sparse {
        int n;
        ArrayList<ArrayList<Pair<Integer, Integer>>> sp;

        void construct(ArrayList<Pair<Integer, Integer>> v) {
            n = v.size();
            int r = id17(n - 1);
            sp = new ArrayList<>(r);
            for (int i = 0; i < r; ++i) {
                sp.add(new ArrayList<>(Collections.nCopies(n, new Pair<>(-1, -1))));
            }
            for (int i = 0; i < n; ++i) {
                sp.get(0).set(i, v.get(i));
            }
            for (int i = 1; i < r; ++i) {
                for (int j = 0; j < n; ++j) {
                    Pair<Integer, Integer> p1 = sp.get(i - 1).get(j);
                    Pair<Integer, Integer> p2 = sp.get(i - 1).get((j + (1 << (i - 1))) % n);
                    sp.get(i).set(j, id1(p1, p2, n));
                }
            }
        }

        Pair<Integer, Integer> segment(int l, int r) {
            if ((l == -1) || (r == -1)) {
                return new Pair<>(-1, -1);
            }
            int szz = raz(r, l, n);
            if (l == r) {
                return sp.get(0).get(l);
            }
            int g = id17(szz) - 1;
            return id1(sp.get(g).get(l), sp.get(g).get(((r + 1 - (1 << g)) % n + n) % n), n);
        }
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static Pair<Integer, Integer> id1(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
        if ((p1.first == -1) || (p2.first == -1)) {
            return new Pair<>(-1, -1);
        }
        Pair<Integer, Integer> np1 = new Pair<>(0, raz(p1.second, p1.first, n));
        Pair<Integer, Integer> np2 = new Pair<>(raz(p2.first, p1.first, n), raz(p2.second, p1.first, n));
        if (np2.first <= np2.second) {
            if (np2.second == n - 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np1.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        } else {
            if (np2.first <= np1.second + 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np2.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        }
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int id9(ArrayList<Integer> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i) < v.get(ans)) {
                ans = i;
            }
        }
        return ans;
    }

    static int prod(int a, int b, int M) {
        return (int) (((long) (a)) * b % M);
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return p.first * q.second - p.second * q.first;
    }

    static boolean id15(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (are_parallel(a, b) && (id2(a, b) >= 0));
    }

    static boolean are_parallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (id2(a, b) == 0);
    }

    static boolean id20(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return ((a.first - b.first) == (d.first - c.first)) && ((a.second - b.second) == (d.second - c.second));
    }

    static boolean id12(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> z = new Pair<>(d.first - c.first, d.second - c.second);
        return id15(x, z);
    }

    static boolean id8(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        int p = id2(x, y), q = id2(y, z), r = id2(z, t), s = id2(t, x);
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
                ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) >= 0);
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return id4(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) > 0);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) < 0);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean id21(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = id2(x, new Pair<>(c.first - b.first, c.second - b.second));
        int q = id2(x, new Pair<>(d.first - b.first, d.second - b.second));
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0)));
    }

    static boolean id5(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = id2(x, new Pair<>(c.first - b.first, c.second - b.second));
        int q = id2(x, new Pair<>(d.first - b.first, d.second - b.second));
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0)));
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + id16(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + id16(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static boolean id3(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id21(a, b, c, d) && id21(c, d, a, b);
    }

    static boolean id13(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id5(a, b, c, d) && id5(c, d, a, b);
    }

    static Pair<Pair<Integer, Integer>, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))),
                -(p.first * (a.second + b.second) - p.second * (a.first + b.first)));
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a, Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second) * (-b * p.second + p.first * q.second);
        double F = (a * p.first - p.second * q.first) * (b * p.first - p.second * q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> id18(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> id2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), -p.first * q.second + p.second * q.first);
    }

    static ArrayList<Pair<Double, Double>> id11(Pair<Pair<Integer, Integer>, Integer> a, Pair<Pair<Integer, Integer>, Integer> b) {
        Pair<Integer, Integer> c = new Pair<>(b.first.first - a.first.first, b.first.second - a.first.second);
        int rr1 = a.second * a.second, rr2 = b.second * b.second, cc = c.first * c.first + c.second * c.second,
                rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
                D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
        if (D >= 0) {
            double E = (((double) (rr1 - rr2)) / cc + 1) / 2;
            Pair<Double, Double> baza = new Pair<>(a.first.first + c.first * E, a.first.second + c.second * E);
            if (D != 0) {
                double lll = Math.sqrt((double) (D)) / (2 * cc);
                Pair<Integer, Integer> cr = id16(c);
                Pair<Double, Double> pmm = new Pair<>((double) (cr.first) * lll, (double) (cr.second) * lll);
                return new ArrayList<>(Arrays.asList(new Pair<>(baza.first + pmm.first, baza.second + pmm.second),
                        new Pair<>(baza.first - pmm.first, baza.second - pmm.second)));
            } else {
                return new ArrayList<>(Collections.singletonList(baza));
            }
        } else {
            return new ArrayList<>();
        }
    }

    static Pair<Integer, Integer> id1(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
        if ((p1.first == -1) || (p2.first == -1)) {
            return new Pair<>(-1, -1);
        }
        Pair<Integer, Integer> np1 = new Pair<>(0, raz(p1.second, p1.first, n));
        Pair<Integer, Integer> np2 = new Pair<>(raz(p2.first, p1.first, n), raz(p2.second, p1.first, n));
        if (np2.first <= np2.second) {
            if (np2.second == n - 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np1.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        } else {
            if (np2.first <= np1.second + 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np2.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        }
    }

    static int id9(ArrayList<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (id10(v.get(i), v.get(ans))) {
                ans = i;
            }
        }
        return ans;
    }

    static boolean id10(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = id2(a, b)) != 0) {
            return (p > 0);
        } else {
            return sq_len(a) < sq_len(b);
        }
    }

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static int sq_dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sq_len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static double len(Pair<Integer, Integer> p) {
        return Math.sqrt(sq_len(p));
    }

    static double dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static boolean id6(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        int x = sq_dist(a, b);
        int y = sq_dist(b, c);
        int z = sq_dist(c, d);
        int t = sq_dist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean is_rectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        return ((id2(x, y) == 0) && (id2(y, z) == 0) && (id2(z, t) == 0) && (id2(t, x) == 0));
    }

    static boolean are_parallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (id2(a, b) == 0);
    }

    static boolean id7(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (id2(a, b) == 0);
    }

    static boolean id15(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (are_parallel(a, b) && (id2(a, b) >= 0));
    }

    static boolean id20(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return ((a.first - b.first) == (d.first - c.first)) && ((a.second - b.second) == (d.second - c.second));
    }

    static boolean id12(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> z = new Pair<>(d.first - c.first, d.second - c.second);
        return id15(x, z);
    }

    static boolean id8(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        int p = id2(x, y), q = id2(y, z), r = id2(z, t), s = id2(t, x);
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
                ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) >= 0);
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return id4(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) > 0);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) < 0);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean id21(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = id2(x, new Pair<>(c.first - b.first, c.second - b.second));
        int q = id2(x, new Pair<>(d.first - b.first, d.second - b.second));
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0)));
    }

    static boolean id5(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = id2(x, new Pair<>(c.first - b.first, c.second - b.second));
        int q = id2(x, new Pair<>(d.first - b.first, d.second - b.second));
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0)));
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + id16(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + id16(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static boolean id3(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id21(a, b, c, d) && id21(c, d, a, b);
    }

    static boolean id13(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id5(a, b, c, d) && id5(c, d, a, b);
    }

    static Pair<Pair<Integer, Integer>, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))),
                -(p.first * (a.second + b.second) - p.second * (a.first + b.first)));
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a, Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second) * (-b * p.second + p.first * q.second);
        double F = (a * p.first - p.second * q.first) * (b * p.first - p.second * q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> id18(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> id2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), -p.first * q.second + p.second * q.first);
    }

    static ArrayList<Pair<Double, Double>> id11(Pair<Pair<Integer, Integer>, Integer> a, Pair<Pair<Integer, Integer>, Integer> b) {
        Pair<Integer, Integer> c = new Pair<>(b.first.first - a.first.first, b.first.second - a.first.second);
        int rr1 = a.second * a.second, rr2 = b.second * b.second, cc = c.first * c.first + c.second * c.second,
                rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
                D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
        if (D >= 0) {
            double E = (((double) (rr1 - rr2)) / cc + 1) / 2;
            Pair<Double, Double> baza = new Pair<>(a.first.first + c.first * E, a.first.second + c.second * E);
            if (D != 0) {
                double lll = Math.sqrt((double) (D)) / (2 * cc);
                Pair<Integer, Integer> cr = id16(c);
                Pair<Double, Double> pmm = new Pair<>((double) (cr.first) * lll, (double) (cr.second) * lll);
                return new ArrayList<>(Arrays.asList(new Pair<>(baza.first + pmm.first, baza.second + pmm.second),
                        new Pair<>(baza.first - pmm.first, baza.second - pmm.second)));
            } else {
                return new ArrayList<>(Collections.singletonList(baza));
            }
        } else {
            return new ArrayList<>();
        }
    }

    static int id19(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n != 0) {
            int mt = id9(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> id10(a.get(l), a.get(r)) ? -1 : 1);

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < idx.size(); ++i) {
                Pair<Integer, Integer> temp = a.get(idx.get(i));
                if (h.size() >= 2) {
                    if (are_parallel(a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                    while ((h.size() >= 3) && npocs(a.get(h.get(h.size() - 2)), a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                }
                h.add(idx.get(i));
            }

            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first + d.first, a.get(i).second + d.second));
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static Pair<Integer, Integer> id1(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
        if ((p1.first == -1) || (p2.first == -1)) {
            return new Pair<>(-1, -1);
        }
        Pair<Integer, Integer> np1 = new Pair<>(0, raz(p1.second, p1.first, n));
        Pair<Integer, Integer> np2 = new Pair<>(raz(p2.first, p1.first, n), raz(p2.second, p1.first, n));
        if (np2.first <= np2.second) {
            if (np2.second == n - 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np1.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        } else {
            if (np2.first <= np1.second + 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np2.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        }
    }

    static int id9(ArrayList<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (id10(v.get(i), v.get(ans))) {
                ans = i;
            }
        }
        return ans;
    }

    static boolean id10(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = id2(a, b)) != 0) {
            return (p > 0);
        } else {
            return sq_len(a) < sq_len(b);
        }
    }

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static int sq_dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sq_len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static double len(Pair<Integer, Integer> p) {
        return Math.sqrt(sq_len(p));
    }

    static double dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static boolean id6(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        int x = sq_dist(a, b);
        int y = sq_dist(b, c);
        int z = sq_dist(c, d);
        int t = sq_dist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean is_rectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        return ((id2(x, y) == 0) && (id2(y, z) == 0) && (id2(z, t) == 0) && (id2(t, x) == 0));
    }

    static boolean are_parallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (id2(a, b) == 0);
    }

    static boolean id7(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (id2(a, b) == 0);
    }

    static boolean id15(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (are_parallel(a, b) && (id2(a, b) >= 0));
    }

    static boolean id20(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return ((a.first - b.first) == (d.first - c.first)) && ((a.second - b.second) == (d.second - c.second));
    }

    static boolean id12(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> z = new Pair<>(d.first - c.first, d.second - c.second);
        return id15(x, z);
    }

    static boolean id8(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        int p = id2(x, y), q = id2(y, z), r = id2(z, t), s = id2(t, x);
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
                ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) >= 0);
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return id4(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) > 0);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) < 0);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(new Pair<>(a.first - b.first, a.second - b.second), new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean id21(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = id2(x, new Pair<>(c.first - b.first, c.second - b.second));
        int q = id2(x, new Pair<>(d.first - b.first, d.second - b.second));
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0)));
    }

    static boolean id5(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = id2(x, new Pair<>(c.first - b.first, c.second - b.second));
        int q = id2(x, new Pair<>(d.first - b.first, d.second - b.second));
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0)));
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + id16(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + id16(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static boolean id3(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id21(a, b, c, d) && id21(c, d, a, b);
    }

    static boolean id13(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id5(a, b, c, d) && id5(c, d, a, b);
    }

    static Pair<Pair<Integer, Integer>, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))),
                -(p.first * (a.second + b.second) - p.second * (a.first + b.first)));
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a, Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second) * (-b * p.second + p.first * q.second);
        double F = (a * p.first - p.second * q.first) * (b * p.first - p.second * q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> id18(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> id2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), -p.first * q.second + p.second * q.first);
    }

    static ArrayList<Pair<Double, Double>> id11(Pair<Pair<Integer, Integer>, Integer> a, Pair<Pair<Integer, Integer>, Integer> b) {
        Pair<Integer, Integer> c = new Pair<>(b.first.first - a.first.first, b.first.second - a.first.second);
        int rr1 = a.second * a.second, rr2 = b.second * b.second, cc = c.first * c.first + c.second * c.second,
                rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
                D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
        if (D >= 0) {
            double E = (((double) (rr1 - rr2)) / cc + 1) / 2;
            Pair<Double, Double> baza = new Pair<>(a.first.first + c.first * E, a.first.second + c.second * E);
            if (D != 0) {
                double lll = Math.sqrt((double) (D)) / (2 * cc);
                Pair<Integer, Integer> cr = id16(c);
                Pair<Double, Double> pmm = new Pair<>((double) (cr.first) * lll, (double) (cr.second) * lll);
                return new ArrayList<>(Arrays.asList(new Pair<>(baza.first + pmm.first, baza.second + pmm.second),
                        new Pair<>(baza.first - pmm.first, baza.second - pmm.second)));
            } else {
                return new ArrayList<>(Collections.singletonList(baza));
            }
        } else {
            return new ArrayList<>();
        }
    }

    static int id19(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n != 0) {
            int mt = id9(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> id10(a.get(l), a.get(r)) ? -1 : 1);

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < idx.size(); ++i) {
                Pair<Integer, Integer> temp = a.get(idx.get(i));
                if (h.size() >= 2) {
                    if (are_parallel(a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                    while ((h.size() >= 3) && npocs(a.get(h.get(h.size() - 2)), a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                }
                h.add(idx.get(i));
            }

            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first + d.first, a.get(i).second + d.second));
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    static int id19(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n != 0) {
            int mt = id9(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> id10(a.get(l), a.get(r)) ? -1 : 1);

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < idx.size(); ++i) {
                Pair<Integer, Integer> temp = a.get(idx.get(i));
                if (h.size() >= 2) {
                    if (are_parallel(a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                    while ((h.size() >= 3) && npocs(a.get(h.get(h.size() - 2)), a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                }
                h.add(idx.get(i));
            }

            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first + d.first, a.get(i).second + d.second));
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    static int id19(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n != 0) {
            int mt = id9(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> id10(a.get(l), a.get(r)) ? -1 : 1);

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < idx.size(); ++i) {
                Pair<Integer, Integer> temp = a.get(idx.get(i));
                if (h.size() >= 2) {
                    if (are_parallel(a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                    while ((h.size() >= 3) && npocs(a.get(h.get(h.size() - 2)), a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                }
                h.add(idx.get(i));
            }

            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first + d.first, a.get(i).second + d.second));
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    static int id19(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n != 0) {
            int mt = id9(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> id10(a.get(l), a.get(r)) ? -1 : 1);

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < idx.size(); ++i) {
                Pair<Integer, Integer> temp = a.get(idx.get(i));
                if (h.size() >= 2) {
                    if (are_parallel(a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                    while ((h.size() >= 3) && npocs(a.get(h.get(h.size() - 2)), a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
                }
                h.add(idx.get(i));
            }

            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first + d.first, a.get(i).second + d.second));
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    static int id19(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n != 0) {
            int mt = id9(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> id10(a.get(l), a.get(r)) ? -1 : 1);

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < idx.size(); ++i) {
                Pair<Integer, Integer> temp = a.get(idx.get(i));
                if (h.size() >= 2) {
                    if (are_parallel(a.get(h.get(h.size() - 1)), temp)) {
                        h.remove(h.size() - 1);
                    }
