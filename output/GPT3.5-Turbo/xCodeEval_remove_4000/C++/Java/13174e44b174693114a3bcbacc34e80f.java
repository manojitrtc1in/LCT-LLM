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

    static int id2(int p, int q) {
        return (p - q + 1000000007) % 1000000007;
    }

    static int id3(int a, int b, int c, int d) {
        return id21(a, b, c, d) && id21(c, d, a, b) ? 1 : 0;
    }

    static int id4(int a, int b, int c) {
        return id4(a - b, a - c) ? 1 : 0;
    }

    static int id4(int a, int c) {
        return a % c >= 0 ? 1 : 0;
    }

    static int id5(int a, int b, int c, int d) {
        return id5(a, b, c, d) ? 1 : 0;
    }

    static int id5(int a, int b, int c, int d) {
        return id5(a - b, a - c, a - d) && id5(c - d, c - a, c - b) ? 1 : 0;
    }

    static int id8(int a, int b, int c, int d) {
        return id8(a, b, c, d) ? 1 : 0;
    }

    static int id8(int a, int b, int c, int d) {
        return id8(a - b, a - c, a - d, a - a) ? 1 : 0;
    }

    static int id9(int a, int b, int c, int d) {
        return id9(a, b, c, d) ? 1 : 0;
    }

    static int id9(int a, int b, int c, int d) {
        return id9(a - b, a - c, a - d, a - a) ? 1 : 0;
    }

    static int id10(int a, int b) {
        return id10(a, b) ? 1 : 0;
    }

    static int id10(int a, int b) {
        return id10(a - b, a - a) ? 1 : 0;
    }

    static int id12(int a, int b, int c, int d) {
        return id12(a, b, c, d) ? 1 : 0;
    }

    static int id12(int a, int b, int c, int d) {
        return id15(a - b, a - c, a - d, a - a) ? 1 : 0;
    }

    static int id13(int a, int b, int c, int d) {
        return id13(a, b, c, d) ? 1 : 0;
    }

    static int id13(int a, int b, int c, int d) {
        return id5(a, b, c, d) && id5(c, d, a, b) ? 1 : 0;
    }

    static int id15(int a, int b) {
        return id15(a, b) ? 1 : 0;
    }

    static int id15(int a, int b) {
        return id15(a - b, a - a) ? 1 : 0;
    }

    static int id15(int a, int b, int c, int d) {
        return id15(a - b, a - c, a - d, a - a) ? 1 : 0;
    }

    static int id16(int p) {
        return id16(p, 0);
    }

    static int id16(int p, int c) {
        return c + id16(p - c);
    }

    static int id20(int a, int b, int c, int d) {
        return id20(a, b, c, d) ? 1 : 0;
    }

    static int id20(int a, int b, int c, int d) {
        return id20(a - b, a - c, a - d, a - a) ? 1 : 0;
    }

    static int id21(int a, int b, int c, int d) {
        return id21(a, b, c, d) ? 1 : 0;
    }

    static int id21(int a, int b, int c, int d) {
        return id21(a - b, a - c, a - d, a - a) ? 1 : 0;
    }

    static int sq_dist(int p1, int p2, int q1, int q2) {
        return sq_dist(p1 - q1, p2 - q2);
    }

    static int sq_dist(int p, int q) {
        return p * p + q * q;
    }

    static int sq_len(int p, int q) {
        return sq_len(p - p, q - q);
    }

    static int sq_len(int p, int q) {
        return p * p + q * q;
    }

    static int len(int p, int q) {
        return (int) Math.sqrt(sq_len(p, q));
    }

    static int dist(int p1, int p2, int q1, int q2) {
        return len(p1 - q1, p2 - q2);
    }

    static int dist(int p, int q) {
        return len(p - p, q - q);
    }

    static boolean id4(int a, int b, int c) {
        return id4(a - b, a - c);
    }

    static boolean id4(int a, int c) {
        return a % c >= 0;
    }

    static boolean npocs(int a, int b, int c) {
        return npocs(a - b, a - c);
    }

    static boolean npocs(int a, int c) {
        return a % c <= 0;
    }

    static boolean prcs(int a, int b, int c) {
        return prcs(a - b, a - c);
    }

    static boolean prcs(int a, int c) {
        return a % c > 0;
    }

    static boolean pocs(int a, int b, int c) {
        return pocs(a - b, a - c);
    }

    static boolean pocs(int a, int c) {
        return a % c < 0;
    }

    static int id5(int a, int b, int c, int d) {
        return id5(a, b, c, d) ? 1 : 0;
    }

    static int id5(int a, int b, int c, int d) {
        return id5(a - b, a - c, a - d) && id5(c - d, c - a, c - b) ? 1 : 0;
    }

    static Pair<Integer, Integer> id16(int p1, int p2) {
        return new Pair<>(-p2, p1);
    }

    static Pair<Integer, Integer> id16(int p1, int p2, int c1, int c2) {
        return new Pair<>(c1 + id16(p1 - c1), c2 + id16(p2 - c2));
    }

    static boolean id21(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
        return id21(a1, a2, b1, b2) && id21(c1, c2, d1, d2);
    }

    static boolean id21(int a1, int a2, int b1, int b2) {
        return id21(a1 - b1, a2 - b2);
    }

    static boolean id21(int a, int b) {
        return a * b == 0;
    }

    static boolean id12(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
        return id12(a1, a2, b1, b2) && id12(c1, c2, d1, d2);
    }

    static boolean id12(int a1, int a2, int b1, int b2) {
        return id15(a1 - b1, a2 - b2);
    }

    static boolean is_rectangle(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
        return is_rectangle(a1, a2, b1, b2) && is_rectangle(c1, c2, d1, d2);
    }

    static boolean is_rectangle(int a1, int a2, int b1, int b2) {
        int x = a1 - b1;
        int y = a2 - b2;
        int z = b1 - a1;
        int t = b2 - a2;
        return ((x * y == 0) && (y * z == 0) && (z * t == 0) && (t * x == 0));
    }

    static boolean id15(int a1, int a2, int b1, int b2) {
        return id15(a1 - b1, a2 - b2);
    }

    static boolean id15(int a, int b) {
        return id15(a - b, a - a);
    }

    static boolean id15(int a, int b, int c, int d) {
        return id15(a - b, a - c, a - d, a - a);
    }

    static boolean id20(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
        return id20(a1, a2, b1, b2) && id20(c1, c2, d1, d2);
    }

    static boolean id20(int a1, int a2, int b1, int b2) {
        return id20(a1 - b1, a2 - b2);
    }

    static boolean id20(int a, int b) {
        return id20(a - b, a - a);
    }

    static boolean id21(int a, int b) {
        return (a % b == 0);
    }

    static boolean id15(int a, int b) {
        return (a * b == 0);
    }

    static boolean id8(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
        return id8(a1, a2, b1, b2) && id8(c1, c2, d1, d2);
    }

    static boolean id8(int a1, int a2, int b1, int b2) {
        int x = a1 - b1;
        int y = a2 - b2;
        int z = b1 - a1;
        int t = b2 - a2;
        int p = x % y;
        int q = y % z;
        int r = z % t;
        int s = t % x;
        return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
                ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
    }

    static boolean id5(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
        return id5(a1, a2, b1, b2) && id5(c1, c2, d1, d2);
    }

    static boolean id5(int a1, int a2, int b1, int b2) {
        int x = a1 - b1;
        int y = a2 - b2;
        int z = b1 - a1;
        int t = b2 - a2;
        int p = x % y;
        int q = y % z;
        int r = z % t;
        int s = t % x;
        return (((p > 0) && (q < 0)) ||
                ((p < 0) && (q > 0)));
    }

    static Pair<Integer, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Integer, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))), -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a, Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second + p.first * q.second);
        double F = (a * q.first - p.first * q.first);
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> id18(Pair<Double, Double> x, Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Double, Double> p1 = serper(x, y);
        Pair<Double, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Pair<Integer, Integer>, Integer> id2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(new Pair<>(q.second - p.second, p.first - q.first), -p.first * q.second + p.second * q.first);
    }

    static ArrayList<Pair<Double, Double>> id11(Pair<Pair<Integer, Integer>, Integer> a, Pair<Pair<Integer, Integer>, Integer> b) {
        Pair<Integer, Integer> c = new Pair<>(b.first.first - a.first.first, b.first.second - a.first.second);
        int rr1 = a.second * a.second;
        int rr2 = b.second * b.second;
        int cc = c.first * c.first + c.second * c.second;
        int rrrr1 = rr1 * rr1;
        int rrrr2 = rr2 * rr2;
        int cccc = cc * cc;
        int D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
        if (D >= 0) {
            double E = (((double) (rr1 - rr2)) / cc + 1) / 2;
            Pair<Double, Double> baza = new Pair<>(a.first.first + c.first * E, a.first.second + c.second * E);
            if (D != 0) {
                double lll = Math.sqrt((double) (D)) / (2 * cc);
                Pair<Integer, Integer> cr = id16(c.first, c.second);
                Pair<Double, Double> pmm = new Pair<>((double) (cr.first) * lll, (double) (cr.second) * lll);
                return new ArrayList<>(Arrays.asList(new Pair<>(baza.first + pmm.first, baza.second + pmm.second), new Pair<>(baza.first - pmm.first, baza.second - pmm.second)));
            } else {
                return new ArrayList<>(Collections.singletonList(baza));
            }
        } else {
            return new ArrayList<>();
        }
    }

    static Pair<Integer, Integer> id0(Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Integer, Integer> perpendicular(Pair<Integer, Integer> line, Pair<Integer, Integer> point) {
        return id0(id16(line.first, line.second), point);
    }

    static Pair<Double, Double> projection(Pair<Pair<Double, Double>, Double> line, Pair<Double, Double> point) {
        Pair<Pair<Double, Double>, Double> temp = perpendicular(line.first, point);
        return ints(line.first.first, line.first.second, temp.first.first, temp.first.second);
    }

    static Pair<Double, Double> height(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return projection(id2(a.first, a.second), b);
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
        for (int i = 0; i < n; i++) {
            r.add(Integer.parseInt(st.nextToken()));
        }
        int zz = id17(n);
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
                if (!new_pr.equals(new Pair<>(-1, -1))) {
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
