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
            int r = id17(n - 1);
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

    static Pair<Integer, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
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

    static boolean id21(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = b - a;
        int p = id2(x, c - b), q = id2(x, d - b);
        return (((p >= 0) && (q <= 0)) || ((p <= 0) && (q >= 0)));
    }

    static boolean id5(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = b - a;
        int p = id2(x, c - b), q = id2(x, d - b);
        return (((p > 0) && (q < 0)) || ((p < 0) && (q > 0)));
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) >= 0);
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return id4(b - a, c - a);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) <= 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(b - a, c - a);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) > 0);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(b - a, c - a);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) < 0);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(b - a, c - a);
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, double a, Pair<Integer, Integer> q, double b) {
        double D = id2(p, q);
        double E = id2(new Pair<>(-a, p.second), new Pair<>(-b, q.second));
        double F = id2(new Pair<>(p.first, -a), new Pair<>(q.first, -b));
        return new Pair<>((int) (E / D), (int) (F / D));
    }

    static Pair<Integer, Integer> id18(Pair<Integer, Integer> x, Pair<Integer, Integer> y, Pair<Integer, Integer> z) {
        Pair<Integer, Integer> p1 = serper(x, y), p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = b - a;
        return new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
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

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static int sq_dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return sq_len(p - q);
    }

    static double len(Pair<Integer, Integer> p) {
        return Math.sqrt(sq_len(p));
    }

    static double dist(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return len(p - q);
    }

    static boolean id6(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        int x = sq_dist(a, b);
        int y = sq_dist(b, c);
        int z = sq_dist(c, d);
        int t = sq_dist(d, a);
        return ((x == y) && (y == z) && (z == t));
    }

    static boolean is_rectangle(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = a - b, y = b - c, z = c - d, t = d - a;
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
        return ((a - b).equals(d - c));
    }

    static boolean id12(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = a - b, z = d - c;
        return id15(x, z);
    }

    static boolean id8(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = a - b, y = b - c, z = c - d, t = d - a;
        int p = id2(x, y), q = id2(y, z), r = id2(z, t), s = id2(t, x);
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) || ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) >= 0);
    }

    static boolean id4(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return id4(a - b, a - c);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) <= 0);
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return npocs(a - b, a - c);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) > 0);
    }

    static boolean prcs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return prcs(a - b, a - c);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> c) {
        return ((id2(a, c)) < 0);
    }

    static boolean pocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return pocs(a - b, a - c);
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
        Pair<Integer, Integer> p = b - a;
        return new Pair<>(p + p, -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Integer, Integer> ints(Pair<Integer, Integer> p, int a, Pair<Integer, Integer> q, int b) {
        int D = id2(p, q);
        int E = id2(new Pair<>(-a, p.second), new Pair<>(-b, q.second));
        int F = id2(new Pair<>(p.first, -a), new Pair<>(q.first, -b));
        return new Pair<>(E / D, F / D);
    }

    static Pair<Integer, Integer> id18(Pair<Integer, Integer> x, Pair<Integer, Integer> y, Pair<Integer, Integer> z) {
        Pair<Integer, Integer> p1 = serper(x, y), p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> id2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), -p.first * q.second + p.second * q.first);
    }

    static ArrayList<Pair<Integer, Integer>> id11(Pair<Pair<Integer, Integer>, Integer> a, Pair<Pair<Integer, Integer>, Integer> b) {
        Pair<Integer, Integer> c = b.first - a.first;
        int rr1 = a.second * a.second, rr2 = b.second * b.second, cc = c.first * c.first + c.second * c.second,
                rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
                D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
        if (D >= 0) {
            double E = (((double) (rr1 - rr2)) / cc + 1) / 2;
            Pair<Integer, Integer> baza = new Pair<>(a.first.first, a.first.second);
            baza.first += c.first * E;
            baza.second += c.second * E;
            if (D != 0) {
                double lll = Math.sqrt((double) (D)) / (2 * cc);
                Pair<Integer, Integer> cr = id16(c);
                Pair<Integer, Integer> pmm = new Pair<>(cr.first * lll, cr.second * lll);
                return new ArrayList<>(Arrays.asList(new Pair<>(baza.first + pmm.first, baza.second + pmm.second),
                        new Pair<>(baza.first - pmm.first, baza.second - pmm.second)));
            } else {
                return new ArrayList<>(Collections.singletonList(baza));
            }
        } else {
            return new ArrayList<>();
        }
    }

    static ArrayList<Integer> z_function(ArrayList<Integer> s) {
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
                if (!new_pr.first.equals(-1)) {
                    ans += (1 << j);
                    my_pr = new_pr;
                }
            }
            pw.print(ans + 1 + " ");
        }
        pw.println();
        pw.close();
    }
}
