import java.util.*;
import java.io.*;

class Main {
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

    static int id9(ArrayList<Pair<Integer, Integer>> v) {
        int ans = 0;
        int n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i).second < v.get(ans).second) {
                ans = i;
            }
        }
        return ans;
    }

    static int id10(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = a.first % b.first) != 0) {
            return (p > 0) ? 1 : 0;
        } else {
            return sq_len(a.first) < sq_len(b.first) ? 1 : 0;
        }
    }

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static int sq_dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sq_len(sub(p, q));
    }

    static Pair<Integer, Integer> sub(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return new Pair<>(a.first - b.first, a.second - b.second);
    }

    static boolean are_parallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.second - a.second * b.first) == 0;
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return (a.first * c.second - a.second * c.first) <= 0;
    }

    static boolean id21(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = sub(b, a);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first);
        int q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return ((p >= 0) && (q <= 0)) || ((p <= 0) && (q >= 0));
    }

    static boolean id5(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = sub(b, a);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first);
        int q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return ((p > 0) && (q < 0)) || ((p < 0) && (q > 0));
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return add(c, id16(sub(p, c)));
    }

    static Pair<Integer, Integer> add(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return new Pair<>(a.first + b.first, a.second + b.second);
    }

    static Pair<Integer, Integer> id2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Integer, Integer> id18(Pair<Integer, Integer> x, Pair<Integer, Integer> y, Pair<Integer, Integer> z) {
        Pair<Pair<Integer, Integer>, Integer> p1 = serper(x, y);
        Pair<Pair<Integer, Integer>, Integer> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = p.first * q.second - p.second * q.first;
        int E = (-a * p.second) * (-b * q.second);
        int F = (a * p.first) * (b * q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(add(p, p), -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static boolean id3(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id21(a, b, c, d) && id21(c, d, a, b);
    }

    static boolean id13(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id5(a, b, c, d) && id5(c, d, a, b);
    }

    static boolean on_segment(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return id15(sub(b, a), sub(c, b));
    }

    static boolean id15(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (a.first * b.second - a.second * b.first) == 0;
    }

    static boolean id15(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return id15(sub(b, a), sub(c, b)) && id15(sub(d, c), sub(a, d));
    }

    static boolean id20(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return sub(a, b).equals(sub(d, c));
    }

    static boolean id12(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = sub(a, b), z = sub(d, c);
        return id15(x, z);
    }

    static boolean id8(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = sub(a, b);
        Pair<Integer, Integer> y = sub(b, c);
        Pair<Integer, Integer> z = sub(c, d);
        Pair<Integer, Integer> t = sub(d, a);
        int p = x.first * y.second - x.second * y.first;
        int q = y.first * z.second - y.second * z.first;
        int r = z.first * t.second - z.second * t.first;
        int s = t.first * x.second - t.second * x.first;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) || ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean id6(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        int x = sq_dist(a, b);
        int y = sq_dist(b, c);
        int z = sq_dist(c, d);
        int t = sq_dist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean is_rectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = sub(a, b);
        Pair<Integer, Integer> y = sub(b, c);
        Pair<Integer, Integer> z = sub(c, d);
        Pair<Integer, Integer> t = sub(d, a);
        return ((x.first * y.first + x.second * y.second == 0) && (y.first * z.first + y.second * z.second == 0) && (z.first * t.first + z.second * t.second == 0) && (t.first * x.first + t.second * x.second == 0));
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return (a.first * c.first + a.second * c.second) >= 0;
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return id4(sub(a, b), sub(a, c));
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return (a.first * c.first + a.second * c.second) <= 0;
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(sub(a, b), sub(a, c));
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return (a.first * c.first + a.second * c.second) > 0;
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(sub(a, b), sub(a, c));
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return (a.first * c.first + a.second * c.second) < 0;
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(sub(a, b), sub(a, c));
    }

    static Pair<Integer, Integer> id11(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = sub(b, a);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first);
        int q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return (((p > 0) && (q < 0)) || ((p < 0) && (q > 0))) ? null : ints(sub(a, b), sub(c, b));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        int D = p.first * q.second - p.second * q.first;
        int E = (-p.second) * (-q.second);
        int F = (p.first) * (q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> id16(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Pair<Integer, Integer>, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = sub(b, a);
        return new Pair<>(add(p, p), -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> projection(Pair<Pair<Integer, Integer>, Integer> line, Pair<Integer, Integer> point) {
        Pair<Pair<Integer, Integer>, Integer> temp = perpendicular(line.first, point);
        return ints(line.first, line.second, temp.first, temp.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> perpendicular(Pair<Integer, Integer> line, Pair<Integer, Integer> point) {
        return id0(id16(line), point);
    }

    static Pair<Integer, Integer> height(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return projection(id2(a, c), b);
    }

    static <T> ArrayList<Integer> z_function(ArrayList<T> s) {
        int n = s.size();
        ArrayList<Integer> z = new ArrayList<>(Collections.nCopies(n, 0));
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
        return ((long) a * b) % M;
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int id19(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n > 0) {
            int mt = id9(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, sub(a.get(i), d));
            }
            ArrayList<Integer> idx = new ArrayList<>(n);
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> id10(a.get(l), a.get(r)));

            ArrayList<Integer> h = new ArrayList<>();
            h.add(idx.get(0));
            for (int i = 1; i < n; ++i) {
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
                a.set(i, add(a.get(i), d));
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            pw.println("0");
            pw.close();
            return;
        }
        ArrayList<Integer> r = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            r.add(Integer.parseInt(st.nextToken()));
        }
        int zz = id17(n) + 1;
        ArrayList<Sparse> v = new ArrayList<>(zz);
        ArrayList<Pair<Integer, Integer>> prs = new ArrayList<>(n);

        for (int i = 0; i < n; ++i) {
            if (r.get(i) >= n - 1) {
                prs.add(new Pair<>(-1, -1));
            } else {
                prs.add(id1(new Pair<>(raz(i, r.get(i), n), i), new Pair<>(i, sum(i, r.get(i), n)), n));
            }
        }

        v.add(new Sparse());
        v.get(0).construct(prs);

        for (int i = 1; i < zz; ++i) {
            ArrayList<Pair<Integer, Integer>> id14 = new ArrayList<>(n);
            for (int j = 0; j < n; ++j) {
                Pair<Integer, Integer> pairr = v.get(i - 1).segment(j, j);
                id14.add(v.get(i - 1).segment(pairr.first, pairr.second));
            }
            v.add(new Sparse());
            v.get(i).construct(id14);
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
            pw.print(ans + 1);
            pw.print(' ');
        }
        pw.println();
        pw.close();
    }
}
