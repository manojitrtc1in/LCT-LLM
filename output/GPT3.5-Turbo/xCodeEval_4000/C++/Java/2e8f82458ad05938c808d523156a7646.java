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
        return 32 - Integer.numberOfLeadingZeros(r);
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

    static ArrayList<Pair<Integer, Integer>> convexHull(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n > 0) {
            int mt = findMinIdx(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                Pair<Integer, Integer> temp = a.get(i);
                temp.first -= d.first;
                temp.second -= d.second;
                a.set(i, temp);
            }

            ArrayList<Integer> idx = new ArrayList<>(n);
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            idx.sort((l, r) -> angdisCmp(a.get(l), a.get(r)));

            ArrayList<Integer> h = new ArrayList<>();
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
                Pair<Integer, Integer> temp = a.get(i);
                temp.first += d.first;
                temp.second += d.second;
                a.set(i, temp);
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    static int findMinIdx(ArrayList<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i).first < v.get(ans).first) {
                ans = i;
            }
        }
        return ans;
    }

    static boolean areParallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.second == a.second * b.first);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean onSegment(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return areCodirected(sub(b, a), sub(c, b));
    }

    static Pair<Integer, Integer> sub(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return new Pair<>(a.first - b.first, a.second - b.second);
    }

    static boolean areCodirected(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (areParallel(a, b) && (a.first * b.first + a.second * b.second >= 0));
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

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        Pair<Integer, Integer> sub = sub(p, c);
        return add(c, rot90(sub));
    }

    static Pair<Integer, Integer> add(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return new Pair<>(a.first + b.first, a.second + b.second);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a, Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> projection(Pair<Pair<Double, Double>, Double> line, Pair<Double, Double> point) {
        Pair<Pair<Double, Double>, Double> temp = perpendicular(line.first, point);
        return ints(line.first, line.second, temp.first, temp.second);
    }

    static Pair<Pair<Double, Double>, Double> perpendicular(Pair<Double, Double> line, Pair<Double, Double> point) {
        return lineWithNormalVectorThroughPoint(rot90(line), point);
    }

    static Pair<Pair<Double, Double>, Double> lineWithNormalVectorThroughPoint(Pair<Double, Double> normal, Pair<Double, Double> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static boolean sharplyDifferentSides(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = sub(b, a);
        double p = x.first * (c.first - b.first) + x.second * (c.second - b.second);
        double q = x.first * (d.first - b.first) + x.second * (d.second - b.second);
        return (((p > 0) && (q < 0)) || ((p < 0) && (q > 0)));
    }

    static boolean sharplyIntersectingSegments(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        return sharplyDifferentSides(a, b, c, d) && sharplyDifferentSides(c, d, a, b);
    }

    static boolean intersectingSegments(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        return differentSides(a, b, c, d) && differentSides(c, d, a, b);
    }

    static boolean differentSides(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = sub(b, a);
        double p = x.first * (c.first - b.first) + x.second * (c.second - b.second);
        double q = x.first * (d.first - b.first) + x.second * (d.second - b.second);
        return (((p >= 0) && (q <= 0)) || ((p <= 0) && (q >= 0)));
    }

    static boolean pocs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) < 0);
    }

    static boolean pocs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        return pocs(sub(a, b), sub(a, c));
    }

    static boolean prcs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) > 0);
    }

    static boolean prcs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        return prcs(sub(a, b), sub(a, c));
    }

    static boolean npocs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) <= 0);
    }

    static boolean npocs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        return npocs(sub(a, b), sub(a, c));
    }

    static boolean nprcs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return ((a.first * c.second - a.second * c.first) >= 0);
    }

    static boolean nprcs(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        return nprcs(sub(a, b), sub(a, c));
    }

    static boolean isConvexPolygon(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = sub(a, b);
        Pair<Double, Double> y = sub(b, c);
        Pair<Double, Double> z = sub(c, d);
        Pair<Double, Double> t = sub(d, a);
        double p = x.first * y.second - x.second * y.first;
        double q = y.first * z.second - y.second * z.first;
        double r = z.first * t.second - z.second * t.first;
        double s = t.first * x.second - t.second * x.first;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) || ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean isTrapezoid(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = sub(a, b);
        Pair<Double, Double> z = sub(d, c);
        return areCodirected(x, z);
    }

    static boolean isParallelogram(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        return sub(a, b).equals(sub(d, c));
    }

    static boolean areCodirected(Pair<Double, Double> a, Pair<Double, Double> b) {
        return (areParallel(a, b) && (a.first * b.first + a.second * b.second >= 0));
    }

    static boolean areOrthogonal(Pair<Double, Double> a, Pair<Double, Double> b) {
        return (a.first * b.first + a.second * b.second == 0);
    }

    static boolean areParallel(Pair<Double, Double> a, Pair<Double, Double> b) {
        return (a.first * b.second == a.second * b.first);
    }

    static boolean isRectangle(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c, Pair<Double, Double> d) {
        Pair<Double, Double> x = sub(a, b);
        Pair<Double, Double> y = sub(b, c);
        Pair<Double, Double> z = sub(c, d);
        Pair<Double, Double> t = sub(d, a);
        return ((x.first * y.first + x.second * y.second == 0) && (y.first * z.first + y.second * z.second == 0) && (z.first * t.first + z.second * t.second == 0) && (t.first * x.first + t.second * x.second == 0));
    }

    static double dist(Pair<Double, Double> p, Pair<Double, Double> q) {
        return len(sub(p, q));
    }

    static double len(Pair<Double, Double> p) {
        return Math.sqrt(sqLen(p));
    }

    static double sqDist(Pair<Double, Double> p, Pair<Double, Double> q) {
        return sqLen(sub(p, q));
    }

    static double sqLen(Pair<Double, Double> p) {
        return p.first * p.first + p.second * p.second;
    }

    static double sqDist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sqLen(sub(p, q));
    }

    static Pair<Integer, Integer> sub(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return new Pair<>(a.first - b.first, a.second - b.second);
    }

    static Pair<Integer, Integer> add(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return new Pair<>(a.first + b.first, a.second + b.second);
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return add(c, rot90(sub(p, c)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return add(c, rot90(sub(p, c)));
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (p.first * (-b) + a * q.first);
        return new Pair<>(Double.valueOf(E / D).intValue(), Double.valueOf(F / D).intValue());
    }

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
