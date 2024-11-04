import java.util.*;
import java.io.*;

class Main {
    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Sparse {
        int n;
        ArrayList<ArrayList<Pair<Integer, Integer>>> sp;

        void construct(ArrayList<Pair<Integer, Integer>> v) {
            n = v.size();
            int r = count_tro(n - 1);
            sp = new ArrayList<>(r);
            for (int i = 0; i < r; ++i) {
                sp.add(new ArrayList<>(Collections.nCopies(n, new Pair<>(0, 0))));
            }
            for (int i = 0; i < n; ++i) {
                sp.get(0).set(i, v.get(i));
            }
            for (int i = 1; i < r; ++i) {
                for (int j = 0; j < n; ++j) {
                    Pair<Integer, Integer> p1 = sp.get(i - 1).get(j);
                    Pair<Integer, Integer> p2 = sp.get(i - 1).get((j + (1 << (i - 1))) % n);
                    sp.get(i).set(j, unite_seg(p1, p2, n));
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
            int g = count_tro(szz) - 1;
            return unite_seg(sp.get(g).get(l), sp.get(g).get(((r + 1 - (1 << g)) % n + n) % n), n);
        }
    }

    static int count_tro(int r) {
        int ans = 0;
        while (r != 0) {
            ++ans;
            r >>= 1;
        }
        return ans;
    }

    static Pair<Integer, Integer> unite_seg(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
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

    static Pair<Integer, Integer> l_th_2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), -p.first * q.second + p.second * q.first);
    }

    static ArrayList<Pair<Double, Double>> circle_intersection(Pair<Pair<Double, Double>, Double> a, Pair<Pair<Double, Double>, Double> b) {
        Pair<Double, Double> c = new Pair<>(b.first.first - a.first.first, b.first.second - a.first.second);
        double rr1 = a.second * a.second, rr2 = b.second * b.second, cc = c.first * c.first + c.second * c.second,
                rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
                D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
        if (D >= 0) {
            double E = (((double) (rr1 - rr2)) / cc + 1) / 2;
            Pair<Double, Double> baza = new Pair<>(a.first.first + c.first * E, a.first.second + c.second * E);
            if (D != 0) {
                double lll = Math.sqrt((double) (D)) / (2 * cc);
                Pair<Double, Double> cr = new Pair<>(-c.second, c.first);
                Pair<Double, Double> pmm = new Pair<>(cr.first * lll, cr.second * lll);
                return new ArrayList<>(Arrays.asList(new Pair<>(baza.first + pmm.first, baza.second + pmm.second),
                        new Pair<>(baza.first - pmm.first, baza.second - pmm.second)));
            } else {
                return new ArrayList<>(Collections.singletonList(baza));
            }
        } else {
            return new ArrayList<>();
        }
    }

    static Pair<Pair<Double, Double>, Double> line_with_normal_vector_through_point(Pair<Double, Double> normal, Pair<Double, Double> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a,
                                    Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.second * q.first - q.second * p.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y),
                p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Double, Double>, Double> serper(Pair<Double, Double> a, Pair<Double, Double> b) {
        Pair<Double, Double> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * a.first + p.second * a.second)), -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> euc(int m, int n) {
        if (n == 0) {
            return new Pair<>((m >= 0) ? 1 : -1, 0);
        }
        int t = m / n;
        Pair<Integer, Integer> ans1 = euc(n, m - t * n);
        return new Pair<>(ans1.second, ans1.first - ans1.second * t);
    }

    static int prod(int a, int b, int M) {
        return ((long) (a)) * b % M;
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static boolean angdis_cmp(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = a.first * b.second - a.second * b.first) != 0) {
            return (p > 0);
        } else {
            return sq_len(a) < sq_len(b);
        }
    }

    static <T> int find_min_idx(ArrayList<T> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i) < v.get(ans)) {
                ans = i;
            }
        }
        return ans;
    }

    static <A> ArrayList<Integer> convex_hull(ArrayList<Pair<A, A>> a) {
        int n = a.size();
        if (n != 0) {
            int mt = find_min_idx(a);
            Pair<A, A> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>(n);
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            idx.sort((l, r) -> angdis_cmp(a.get(l), a.get(r)) ? -1 : 1);

            ArrayList<Integer> h = new ArrayList<>(Collections.singletonList(idx.get(0)));
            for (int i = 1; i < idx.size(); ++i) {
                Pair<A, A> temp = a.get(idx.get(i));
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

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static boolean are_parallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.second - a.second * b.first == 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean on_segment(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return are_codirected(b.first - a.first, b.second - a.second, c.first - b.first, c.second - b.second);
    }

    static boolean are_codirected(int ax, int ay, int bx, int by) {
        return (ax * by - ay * bx >= 0);
    }

    static boolean sharply_different_sides(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0)));
    }

    static boolean sharply_intersecting_segments(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b);
    }

    static Pair<Integer, Integer> rot_90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot_90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + rot_90(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + rot_90(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static boolean intersecting_segments(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return different_sides(a, b, c, d) && different_sides(c, d, a, b);
    }

    static boolean different_sides(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0)));
    }

    static Pair<Pair<Integer, Integer>, Integer> perpendicular(Pair<Integer, Integer> line, Pair<Integer, Integer> point) {
        return line_with_normal_vector_through_point(rot_90(line), point);
    }

    static Pair<Double, Double> projection(Pair<Pair<Double, Double>, Double> line, Pair<Double, Double> point) {
        Pair<Pair<Double, Double>, Double> temp = perpendicular(line.first, point);
        return ints(line.first, line.second, temp.first, temp.second);
    }

    static Pair<Double, Double> height(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return projection(l_th_2(a, c), b);
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

    static boolean is_rhombus(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        int x = sq_dist(a, b);
        int y = sq_dist(b, c);
        int z = sq_dist(c, d);
        int t = sq_dist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean is_rectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(b.first - c.first, b.second - c.second),
                z = new Pair<>(c.first - d.first, c.second - d.second),
                t = new Pair<>(d.first - a.first, d.second - a.second);
        return ((x.first * y.first + x.second * y.second == 0) && (y.first * z.first + y.second * z.second == 0) &&
                (z.first * t.first + z.second * t.second == 0) && (t.first * x.first + t.second * x.second == 0));
    }

    static boolean are_orthogonal(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.first + a.second * b.second == 0);
    }

    static boolean are_codirected(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (are_parallel(a, b) && (a.first * b.first + a.second * b.second >= 0));
    }

    static boolean is_parallelogram(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(d.first - c.first, d.second - c.second);
        return ((x.first == y.first) && (x.second == y.second));
    }

    static boolean is_trapezoid(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                z = new Pair<>(d.first - c.first, d.second - c.second);
        return are_codirected(x.first, x.second, z.first, z.second);
    }

    static boolean is_convex_polygon(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(b.first - c.first, b.second - c.second),
                z = new Pair<>(c.first - d.first, c.second - d.second),
                t = new Pair<>(d.first - a.first, d.second - a.second);
        int p = x.first * y.second - x.second * y.first, q = y.first * z.second - y.second * z.first,
                r = z.first * t.second - z.second * t.first, s = t.first * x.second - t.second * x.first;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
                ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean nprcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) >= 0);
    }

    static boolean nprcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return nprcs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) > 0);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) < 0);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static int sq_dist(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static int sq_dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sq_dist(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static double len(Pair<Double, Double> p) {
        return Math.sqrt(sq_len(p));
    }

    static double dist(Pair<Double, Double> p, Pair<Double, Double> q) {
        return len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static boolean is_rhombus(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        double x = sq_dist(a, b);
        double y = sq_dist(b, c);
        double z = sq_dist(c, d);
        double t = sq_dist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean is_rectangle(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(b.first - c.first, b.second - c.second),
                z = new Pair<>(c.first - d.first, c.second - d.second),
                t = new Pair<>(d.first - a.first, d.second - a.second);
        return ((x.first * y.first + x.second * y.second == 0) && (y.first * z.first + y.second * z.second == 0) &&
                (z.first * t.first + z.second * t.second == 0) && (t.first * x.first + t.second * x.second == 0));
    }

    static boolean are_orthogonal(Pair<Double, Double> a, Pair<Double, Double> b) {
        return (a.first * b.first + a.second * b.second == 0);
    }

    static boolean are_codirected(Pair<Double, Double> a, Pair<Double, Double> b) {
        return (are_parallel(a, b) && (a.first * b.first + a.second * b.second >= 0));
    }

    static boolean is_parallelogram(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(d.first - c.first, d.second - c.second);
        return ((x.first == y.first) && (x.second == y.second));
    }

    static boolean is_trapezoid(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(a.first - b.first, a.second - b.second),
                z = new Pair<>(d.first - c.first, d.second - c.second);
        return are_codirected(x.first, x.second, z.first, z.second);
    }

    static boolean is_convex_polygon(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(b.first - c.first, b.second - c.second),
                z = new Pair<>(c.first - d.first, c.second - d.second),
                t = new Pair<>(d.first - a.first, d.second - a.second);
        int p = x.first * y.second - x.second * y.first, q = y.first * z.second - y.second * z.first,
                r = z.first * t.second - z.second * t.first, s = t.first * x.second - t.second * x.first;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
                ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean nprcs(Pair<Double, Double> a, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) >= 0);
    }

    static boolean nprcs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return nprcs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean npocs(Pair<Double, Double> a, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean npocs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return npocs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean prcs(Pair<Double, Double> a, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) > 0);
    }

    static boolean prcs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return prcs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean pocs(Pair<Double, Double> a, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) < 0);
    }

    static boolean pocs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return pocs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static int sq_len(Pair<Double, Double> p) {
        return p.first * p.first + p.second * p.second;
    }

    static int sq_dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sq_len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static double len(Pair<Integer, Integer> p) {
        return Math.sqrt(sq_len(p));
    }

    static double len(Pair<Double, Double> p) {
        return Math.sqrt(sq_len(p));
    }

    static double dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static double dist(Pair<Double, Double> p, Pair<Double, Double> q) {
        return len(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static boolean is_rhombus(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        int x = sq_dist(a, b);
        int y = sq_dist(b, c);
        int z = sq_dist(c, d);
        int t = sq_dist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean is_rectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(b.first - c.first, b.second - c.second),
                z = new Pair<>(c.first - d.first, c.second - d.second),
                t = new Pair<>(d.first - a.first, d.second - a.second);
        return ((x.first * y.first + x.second * y.second == 0) && (y.first * z.first + y.second * z.second == 0) &&
                (z.first * t.first + z.second * t.second == 0) && (t.first * x.first + t.second * x.second == 0));
    }

    static boolean are_orthogonal(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.first + a.second * b.second == 0);
    }

    static boolean are_codirected(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (are_parallel(a, b) && (a.first * b.first + a.second * b.second >= 0));
    }

    static boolean is_parallelogram(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(d.first - c.first, d.second - c.second);
        return ((x.first == y.first) && (x.second == y.second));
    }

    static boolean is_trapezoid(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                z = new Pair<>(d.first - c.first, d.second - c.second);
        return are_codirected(x.first, x.second, z.first, z.second);
    }

    static boolean is_convex_polygon(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second),
                y = new Pair<>(b.first - c.first, b.second - c.second),
                z = new Pair<>(c.first - d.first, c.second - d.second),
                t = new Pair<>(d.first - a.first, d.second - a.second);
        int p = x.first * y.second - x.second * y.first, q = y.first * z.second - y.second * z.first,
                r = z.first * t.second - z.second * t.first, s = t.first * x.second - t.second * x.first;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
                ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean nprcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) >= 0);
    }

    static boolean nprcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return nprcs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) > 0);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) < 0);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(new Pair<>(a.first - b.first, a.second - b.second),
                new Pair<>(a.first - c.first, a.second - c.second));
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = new Pair<>(b.first - a.first, b.second - a.second);
        double p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p >= 0) && (q <= 0)) ||
                ((p <= 0) && (q >= 0))) ? 1 : 0;
    }

    static int sq_dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first),
                q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0))) ? 1 : 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println("0");
            return;
        }
        int[] r = new int[n];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            r[i] = Integer.parseInt(input[i]);
        }
        int zz = count_tro(n) + 1;
        ArrayList<Sparse> v = new ArrayList<>(zz);
        ArrayList<Pair<Integer, Integer>> prs = new ArrayList<>(n);

        for (int i = 0; i < n; ++i) {
            if (r[i] >= n - 1) {
                prs.add(new Pair<>(-1, -1));
            } else {
                prs.add(unite_seg(new Pair<>(raz(i, r[i], n), i), new Pair<>(i, sum(i, r[i], n)), n));
            }
        }

        v.add(new Sparse());
        v.get(0).construct(prs);

        for (int i = 1; i < zz; ++i) {
            ArrayList<Pair<Integer, Integer>> new_prs = new ArrayList<>(n);
            for (int j = 0; j < n; ++j) {
                Pair<Integer, Integer> pairr = v.get(i - 1).segment(j, j);
                new_prs.add(v.get(i - 1).segment(pairr.first, pairr.second));
            }
            v.add(new Sparse());
            v.get(i).construct(new_prs);
        }

        for (int i = 0; i < n; ++i) {
            Pair<Integer, Integer> my_pr = new Pair<>(i, i);
            int ans = 0;
            for (int j = zz - 1; j >= 0; --j) {
                Pair<Integer, Integer> new_pr = v.get(j).segment(my_pr.first, my_pr.second);
                if (new_pr.first != -1) {
                    ans += (1 << j);
                    my_pr = new_pr;
                }
            }
            System.out.print(ans + 1 + " ");
        }
        System.out.println();
    }
}
