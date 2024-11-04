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

    static Pair<Integer, Integer> lTh2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static ArrayList<Pair<Integer, Integer>> convexHull(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n > 0) {
            int mt = findMinIdx(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> angdisCmp(a.get(l), a.get(r)));

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < idx.size(); ++i) {
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

    static int findMinIdx(ArrayList<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i).first < v.get(ans).first) {
                ans = i;
            }
        }
        return ans;
    }

    static int angdisCmp(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = a.first * b.second - a.second * b.first) != 0) {
            return p > 0 ? 1 : -1;
        } else {
            return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second ? -1 : 1;
        }
    }

    static boolean areParallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.first * b.second == a.second * b.first;
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return a.first * c.second - a.second * c.first <= 0;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(p.first + p.first, p.second + p.second);
    }

    static int sqDist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sqLen(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static int sqLen(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + rot90(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + rot90(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static Pair<Integer, Integer> projection(Pair<Pair<Integer, Integer>, Integer> line, Pair<Integer, Integer> point) {
        Pair<Pair<Integer, Integer>, Integer> temp = perpendicular(line.first, point);
        return ints(line.first, line.second, temp.first, temp.second);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Pair<Integer, Integer>, Integer> perpendicular(Pair<Integer, Integer> line, Pair<Integer, Integer> point) {
        return lineWithNormalVectorThroughPoint(rot90(line), point);
    }

    static Pair<Pair<Integer, Integer>, Integer> lineWithNormalVectorThroughPoint(Pair<Integer, Integer> normal,
            Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static int sqDist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sqLen(new Pair<>(p.first - q.first, p.second - q.second));
    }

    static double dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return Math.sqrt(sqDist(p, q));
    }

    static boolean intersectingSegments(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        return differentSides(a, b, c, d) && differentSides(c, d, a, b);
    }

    static boolean sharplyIntersectingSegments(Pair<Integer, Integer> a, Pair<Integer, Integer> b,
            Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return sharplyDifferentSides(a, b, c, d) && sharplyDifferentSides(c, d, a, b);
    }

    static boolean differentSides(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second), q = x.second * (c.first - b.first);
        return ((p >= 0) && (q <= 0)) || ((p <= 0) && (q >= 0));
    }

    static boolean sharplyDifferentSides(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second), q = x.second * (c.first - b.first);
        return ((p > 0) && (q < 0)) || ((p < 0) && (q > 0));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> circumcenter(Pair<Integer, Integer> x, Pair<Integer, Integer> y,
            Pair<Integer, Integer> z) {
        Pair<Pair<Integer, Integer>, Integer> p1 = serper(x, y);
        Pair<Pair<Integer, Integer>, Integer> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static boolean isConvexPolygon(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        Pair<Integer, Integer> y = new Pair<>(c.first - b.first, c.second - b.second);
        Pair<Integer, Integer> z = new Pair<>(d.first - c.first, d.second - c.second);
        Pair<Integer, Integer> t = new Pair<>(a.first - d.first, a.second - d.second);
        int p = x.first * y.second - x.second * y.first, q = y.first * z.second - y.second * z.first,
                r = z.first * t.second - z.second * t.first, s = t.first * x.second - t.second * x.first;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0))
                || ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean isTrapezoid(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        Pair<Integer, Integer> z = new Pair<>(d.first - c.first, d.second - c.second);
        return areCodirected(x, z);
    }

    static boolean areCodirected(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return areParallel(a, b) && (a.first * b.first + a.second * b.second >= 0);
    }

    static boolean isParallelogram(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        return (a.first - b.first == d.first - c.first) && (a.second - b.second == d.second - c.second);
    }

    static boolean isRectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        return (x.first * y.first + x.second * y.second == 0) && (y.first * z.first + y.second * z.second == 0)
                && (z.first * t.first + z.second * t.second == 0) && (t.first * x.first + t.second * x.second == 0);
    }

    static boolean isRhombus(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        int x = sqDist(a, b);
        int y = sqDist(b, c);
        int z = sqDist(c, d);
        int t = sqDist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean isOrthogonal(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.first * b.first + a.second * b.second == 0;
    }

    static boolean isRhombus(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        int x = sqDist(a, b);
        int y = sqDist(b, c);
        int z = sqDist(c, d);
        int t = sqDist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean isRectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        return (x.first * y.first + x.second * y.second == 0) && (y.first * z.first + y.second * z.second == 0)
                && (z.first * t.first + z.second * t.second == 0) && (t.first * x.first + t.second * x.second == 0);
    }

    static boolean areParallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.first * b.second == a.second * b.first;
    }

    static boolean areOrthogonal(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.first * b.first + a.second * b.second == 0;
    }

    static boolean areCodirected(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return areParallel(a, b) && (a.first * b.first + a.second * b.second >= 0);
    }

    static boolean isParallelogram(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        return (a.first - b.first == d.first - c.first) && (a.second - b.second == d.second - c.second);
    }

    static boolean isTrapezoid(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        return areCodirected(x, z);
    }

    static boolean isConvexPolygon(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c,
            Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(a.first - b.first, a.second - b.second);
        Pair<Integer, Integer> y = new Pair<>(b.first - c.first, b.second - c.second);
        Pair<Integer, Integer> z = new Pair<>(c.first - d.first, c.second - d.second);
        Pair<Integer, Integer> t = new Pair<>(d.first - a.first, d.second - a.second);
        int p = x.first * y.second - x.second * y.first, q = y.first * z.second - y.second * z.first,
                r = z.first * t.second - z.second * t.first, s = t.first * x.second - t.second * x.first;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0))
                || ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + rot90(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + rot90(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static Pair<Integer, Integer> height(Pair<Integer, Integer> a, Pair<Integer, Integer> b,
            Pair<Integer, Integer> c) {
        return projection(lTh2(a, c), b);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = -a * p.second + b * q.second;
        int F = a * q.first - b * p.first;
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
