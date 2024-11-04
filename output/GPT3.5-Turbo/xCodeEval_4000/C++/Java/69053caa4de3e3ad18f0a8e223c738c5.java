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
                sp.add(new ArrayList<>(Collections.nCopies(n, new Pair<>(-1, -1))));
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
        return 32 - Integer.numberOfLeadingZeros(r);
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
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static ArrayList<Pair<Integer, Integer>> convex_hull(ArrayList<Pair<Integer, Integer>> a) {
        int n = a.size();
        if (n > 0) {
            int mt = find_min_idx(a);
            Pair<Integer, Integer> d = a.get(mt);
            for (int i = 0; i < n; ++i) {
                a.set(i, new Pair<>(a.get(i).first - d.first, a.get(i).second - d.second));
            }

            ArrayList<Integer> idx = new ArrayList<>(n);
            for (int i = 0; i < n; ++i) {
                idx.add(i);
            }
            Collections.sort(idx, (l, r) -> angdis_cmp(a.get(l), a.get(r)));

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
                a.set(i, new Pair<>(a.get(i).first + d.first, a.get(i).second + d.second));
            }
            return h;
        } else {
            return new ArrayList<>();
        }
    }

    static int find_min_idx(ArrayList<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i).first < v.get(ans).first) {
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

    static boolean angdis_cmp(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = a.first * b.second - a.second * b.first) != 0) {
            return p > 0;
        } else {
            return sq_len(a) < sq_len(b);
        }
    }

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static boolean are_parallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.first * b.second == a.second * b.first;
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return a.first * c.second - a.second * c.first <= 0;
    }

    static int raz(int a, int b, int n) {
        int c = a - b;
        return c < 0 ? c + n : c;
    }

    static int sum(int a, int b, int n) {
        int c = a + b;
        return c >= n ? c - n : c;
    }

    static int count_tro(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
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

    static int raz(int a, int b, int n) {
        int c = a - b;
        return c < 0 ? c + n : c;
    }

    static int sum(int a, int b, int n) {
        int c = a + b;
        return c >= n ? c - n : c;
    }

    static boolean are_parallel(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.first * b.second == a.second * b.first;
    }

    static boolean npocs(Pair<Integer, Integer> a, Pair<Integer, Integer> b, Pair<Integer, Integer> c) {
        return a.first * c.second - a.second * c.first <= 0;
    }

    static int find_min_idx(ArrayList<Pair<Integer, Integer>> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i).first < v.get(ans).first) {
                ans = i;
            }
        }
        return ans;
    }

    static int sq_len(Pair<Integer, Integer> p) {
        return p.first * p.first + p.second * p.second;
    }

    static boolean angdis_cmp(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        int p;
        if ((p = a.first * b.second - a.second * b.first) != 0) {
            return p > 0;
        } else {
            return sq_len(a) < sq_len(b);
        }
    }

    static Pair<Integer, Integer> l_th_2(Pair<Integer, Integer> p, Pair<Integer, Integer> q) {
        return new Pair<>(q.second - p.second, p.first - q.first);
    }

    static Pair<Integer, Integer> rot_90(Pair<Integer, Integer> p) {
        return new Pair<>(-p.second, p.first);
    }

    static Pair<Integer, Integer> rot_90(Pair<Integer, Integer> p, Pair<Integer, Integer> c) {
        return new Pair<>(c.first + rot_90(new Pair<>(p.first - c.first, p.second - c.second)).first,
                c.second + rot_90(new Pair<>(p.first - c.first, p.second - c.second)).second);
    }

    static boolean intersecting_segments(Pair<Integer, Integer> a, Pair<Integer, Integer> b,
                                          Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return different_sides(a, b, c, d) && different_sides(c, d, a, b);
    }

    static boolean sharply_intersecting_segments(Pair<Integer, Integer> a, Pair<Integer, Integer> b,
                                                  Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b);
    }

    static boolean different_sides(Pair<Integer, Integer> a, Pair<Integer, Integer> b,
                                    Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first);
        int q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return ((p >= 0) && (q <= 0)) || ((p <= 0) && (q >= 0));
    }

    static boolean sharply_different_sides(Pair<Integer, Integer> a, Pair<Integer, Integer> b,
                                            Pair<Integer, Integer> c, Pair<Integer, Integer> d) {
        Pair<Integer, Integer> x = new Pair<>(b.first - a.first, b.second - a.second);
        int p = x.first * (c.second - b.second) - x.second * (c.first - b.first);
        int q = x.first * (d.second - b.second) - x.second * (d.first - b.first);
        return ((p > 0) && (q < 0)) || ((p < 0) && (q > 0));
    }

    static Pair<Pair<Integer, Integer>, Integer> line_with_normal_vector_through_point(
            Pair<Integer, Integer> normal, Pair<Integer, Integer> point) {
        return new Pair<>(normal, -(normal.first * point.first + normal.second * point.second));
    }

    static Pair<Pair<Integer, Integer>, Integer> serper(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        Pair<Integer, Integer> p = new Pair<>(b.first - a.first, b.second - a.second);
        return new Pair<>(new Pair<>(p.first + p.first, -(p.first * (a.first + b.first) + p.second * (a.second + b.second))),
                -(p.first * (a.first + b.first) + p.second * (a.second + b.second)));
    }

    static Pair<Double, Double> ints(Pair<Double, Double> p, double a,
                                     Pair<Double, Double> q, double b) {
        double D = p.first * q.second - p.second * q.first;
        double E = (-a * p.second) * (-b * q.first) - (-b * p.first) * (-a * q.second);
        double F = (p.first * (-a * q.second)) - (q.first * (-a * p.second));
        return new Pair<>(E / D, F / D);
    }

    static Pair<Double, Double> circumcenter(Pair<Double, Double> x,
                                              Pair<Double, Double> y, Pair<Double, Double> z) {
        Pair<Pair<Double, Double>, Double> p1 = serper(x, y);
        Pair<Pair<Double, Double>, Double> p2 = serper(x, z);
        return ints(p1.first, p1.second, p2.first, p2.second);
    }

    static Pair<Integer, Integer> projection(Pair<Pair<Double, Double>, Double> line, Pair<Double, Double> point) {
        Pair<Pair<Double, Double>, Double> temp = perpendicular(line.first, point);
        return ints(line.first, line.second, temp.first, temp.second);
    }

    static Pair<Pair<Double, Double>, Double> perpendicular(Pair<Pair<Double, Double>, Double> line,
                                                            Pair<Double, Double> point) {
        return line_with_normal_vector_through_point(rot_90(line.first), point);
    }

    static Pair<Double, Double> height(Pair<Double, Double> a, Pair<Double, Double> b, Pair<Double, Double> c) {
        return projection(l_th_2(a, c), b);
    }

    static <T> ArrayList<Integer> z_function(ArrayList<T> s) {
        int n = s.size();
        ArrayList<Integer> z = new ArrayList<>(Collections.nCopies(n, 0));
        int l = 0, r = 1;
        for (int i = 1; i < n; ++i) {
            z.set(i, Math.max(0, Math.min(r - i, z.get(i - l))));
            while (i + z.get(i) < n && (s.get(i + z.get(i)).equals(s.get(z.get(i))))) {
                z.set(i, z.get(i) + 1);
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

    static int n;
    static ArrayList<Integer> r;
    static int zz;
    static ArrayList<Sparse> v;
    static ArrayList<Pair<Integer, Integer>> prs;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println("0");
            return;
        }
        r = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            r.add(Integer.parseInt(st.nextToken()));
        }
        zz = count_tro(n) + 1;
        v = new ArrayList<>(zz);
        prs = new ArrayList<>(n);

        for (int i = 0; i < n; ++i) {
            if (r.get(i) >= n - 1) {
                prs.add(new Pair<>(-1, -1));
            } else {
                prs.add(unite_seg(new Pair<>(raz(i, r.get(i), n), i), new Pair<>(i, sum(i, r.get(i), n)), n));
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

        StringBuilder sb = new StringBuilder();
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
            sb.append(ans + 1).append(' ');
        }
        System.out.println(sb);
    }
}
