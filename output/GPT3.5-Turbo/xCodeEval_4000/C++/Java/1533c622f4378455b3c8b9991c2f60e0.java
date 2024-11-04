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
        List<List<Pair<Integer, Integer>>> sp;

        void construct(List<Pair<Integer, Integer>> v) {
            n = v.size();
            int r = countTRO(n - 1);
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
                    sp.get(i).set(j, uniteSeg(p1, p2, n));
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
            int g = countTRO(szz) - 1;
            return uniteSeg(sp.get(g).get(l), sp.get(g).get(((r + 1 - (1 << g)) % n + n) % n), n);
        }
    }

    static int countTRO(int r) {
        int ans = 0;
        while (r > 0) {
            ++ans;
            r >>= 1;
        }
        return ans;
    }

    static Pair<Integer, Integer> uniteSeg(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
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

    static int prod(int a, int b, int M) {
        return ((long) a) * b % M;
    }

    static List<Integer> convexHull(List<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n > 0) {
            int mt = findMinIdx(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            List<Integer> idx = new ArrayList<>(n);
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            idx.sort((l, r) -> angdisCmp(a.get(l), a.get(r)));

            List<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < n; ++i) {
                Pair<Integer, Integer> temp = a.get(idx.get(i));
                if (h.size() >= 2) {
                    if (areParallel(a.get(h.get(h.size() - 1)), temp)) {
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

    static int findMinIdx(List<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i).first < v.get(ans).first) {
                ans = i;
            }
        }
        return ans;
    }

    static boolean areParallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.second - a.second * b.first) == 0;
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean onSegment(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return areCodirected(b.first - a.first, b.second - a.second, c.first - b.first, c.second - b.second);
    }

    static boolean areCodirected(int ax, int ay, int bx, int by) {
        return (ax * by - ay * bx) >= 0;
    }

    static int angdisCmp(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = a.first * b.second - a.second * b.first) != 0) {
            return (p > 0) ? 1 : -1;
        } else {
            return sqLen(a) < sqLen(b) ? -1 : 1;
        }
    }

    static int sqLen(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static int sqDist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sqLen(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Pair<Integer, Integer>, Integer> lineWithNormalVectorThroughPoint(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int findMinIdx(List<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i).first < v.get(ans).first) {
                ans = i;
            }
        }
        return ans;
    }

    static int countTRO(int r) {
        int ans = 0;
        while (r > 0) {
            ++ans;
            r >>= 1;
        }
        return ans;
    }

    static Pair<Integer, Integer> uniteSeg(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
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

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean areCodirected(int ax, int ay, int bx, int by) {
        return (ax * by - ay * bx) >= 0;
    }

    static boolean areParallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.second - a.second * b.first) == 0;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int prod(int a, int b, int M) {
        return ((long) a) * b % M;
    }

    static int sqLen(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static boolean sharplyDifferentSides(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.first - b.first) + x.second * (c.second - b.second);
        int q = x.first * (d.first - b.first) + x.second * (d.second - b.second);
        return (((p > 0) && (q < 0)) || ((p < 0) && (q > 0)));
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + rot90(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + rot90(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static boolean intersectingSegments(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return differentSides(a, b, c, d) && differentSides(c, d, a, b);
    }

    static boolean differentSides(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.first - b.first) + x.second * (c.second - b.second);
        int q = x.first * (d.first - b.first) + x.second * (d.second - b.second);
        return (((p >= 0) && (q <= 0)) || ((p <= 0) && (q >= 0)));
    }

    static Pair<Pair<Integer, Integer>, Integer> perpendicular(Pair<Integer, Integer> line, Pair<Integer, Integer> point) {
        return lineWithNormalVectorThroughPoint(rot90(line), point);
    }

    static Pair<Integer, Integer> projection(Pair<Pair<Integer, Integer>, Integer> line, Pair<Integer, Integer> point) {
        Pair<Pair<Integer, Integer>, Integer> temp = perpendicular(line.first, point);
        return ints(line.first, line.second, temp.first, temp.second);
    }

    static Pair<Integer, Integer> height(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return projection(lTh2(a, c), b);
    }

    static Pair<Double, Double> ints(Pair<Pair<Double, Double>, Double> p, Pair<Pair<Double, Double>, Double> q) {
        double D = p.first.first * q.first.second - p.first.second * q.first.first;
        double E = (-p.second * p.first.second) * (-q.second * q.first.second);
        double F = (p.second * p.first.first) * (q.second * q.first.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static List<Pair<Double, Double>> circleIntersection(Pair<Pair<Integer, Integer>, Integer> a, Pair<Pair<Integer, Integer>, Integer> b) {
        Pair<Integer, Integer> c = new Pair<>(b.first.first - a.first.first, b.first.second - a.first.second);
        int rr1 = a.second * a.second, rr2 = b.second * b.second, cc = c.first * c.first + c.second * c.second,
                rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
                D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
        if (D >= 0) {
            double E = (((double) (rr1 - rr2)) / cc + 1) / 2;
            Pair<Double, Double> baza = new Pair<>(a.first.first + c.first * E, a.first.second + c.second * E);
            if (D > 0) {
                double lll = Math.sqrt((double) (D)) / (2 * cc);
                Pair<Integer, Integer> cr = rot90(c);
                Pair<Double, Double> pmm = new Pair<>((double) (cr.first) * lll, (double) (cr.second) * lll);
                return Arrays.asList(new Pair<>(baza.first + pmm.first, baza.second + pmm.second),
                        new Pair<>(baza.first - pmm.first, baza.second - pmm.second));
            } else {
                return Collections.singletonList(baza);
            }
        } else {
            return Collections.emptyList();
        }
    }

    static List<Integer> zFunction(List<Integer> s) {
        int n = s.size();
        List<Integer> z = new ArrayList<>(Collections.nCopies(n, 0));
        int l = 0, r = 1;
        for (int i = 1; i < n; ++i) {
            z.set(i, Math.max(0, Math.min(r - i, z.get(i - l))));
            while (i + z.get(i) < n && (s.get(i + z.get(i)).equals(s.get(z.get(i))))) {
                ++z.set(i, z.get(i) + 1);
            }
            if (r < i + z.get(i)) {
                l = i;
                r = i + z.get(i);
            }
        }
        return z;
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

    static int pocs(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int prcs(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int npocs(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int nprcs(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static boolean sharplyDifferentSides(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.first - b.first) + x.second * (c.second - b.second);
        int q = x.first * (d.first - b.first) + x.second * (d.second - b.second);
        return (((p > 0) && (q < 0)) || ((p < 0) && (q > 0)));
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + rot90(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + rot90(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static boolean intersectingSegments(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return differentSides(a, b, c, d) && differentSides(c, d, a, b);
    }

    static boolean sharplyIntersectingSegments(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return sharplyDifferentSides(a, b, c, d) && sharplyDifferentSides(c, d, a, b);
    }

    static Pair<Pair<Integer, Integer>, Integer> lineWithNormalVectorThroughPoint(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a, Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), p.first * q.second - p.second * q.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.second);
        double F = (a * p.first) * (b * q.first);
