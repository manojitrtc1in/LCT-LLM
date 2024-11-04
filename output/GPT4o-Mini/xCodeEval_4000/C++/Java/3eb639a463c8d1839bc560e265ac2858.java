import java.util.*;
import java.io.*;

public class 3eb639a463c8d1839bc560e265ac2858_nc {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = INF + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);
    static final int N = 100 * 1000 + 13;

    static int n;
    static Pair<Point, Point>[] a = new Pair[N];

    static boolean read() {
        try {
            n = Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(new BufferedReader(new InputStreamReader(System.in)).readLine());
                int type = Integer.parseInt(st.nextToken());
                a[i] = new Pair<>(new Point(type, 0), new Point(0, 0));
                if (type == 1) {
                    a[i].x.y = Integer.parseInt(st.nextToken());
                    a[i].y.x = Integer.parseInt(st.nextToken());
                } else if (type == 2) {
                    a[i].x.y = Integer.parseInt(st.nextToken());
                } else if (type == 3) {
                    a[i].x.y = Integer.parseInt(st.nextToken());
                    a[i].y.x = Integer.parseInt(st.nextToken());
                    a[i].y.y = Integer.parseInt(st.nextToken());
                }
            }
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    static List<Integer> vals = new ArrayList<>();

    static class Node {
        int s;
        long sum, minsum;

        Node() {}

        Node(int s, int len) {
            this.s = s;
            this.sum = s * (long) len;
            this.minsum = s < 0 ? s * (long) len : 0;
        }
    }

    static Node[] t = new Node[4 * N];

    static Node merge(Node a, Node b) {
        Node c = new Node(0, 0);
        c.sum = a.sum + b.sum;
        c.minsum = Math.min(a.minsum, a.sum + b.minsum);
        return c;
    }

    static void build(int v, int l, int r) {
        if (l == r - 1) {
            if (l == 0)
                t[v] = new Node(0, INF + 1);
            else
                t[v] = new Node(0, 0);
            return;
        }
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m, r);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }

    static void upd(int v, int l, int r, int pos, Point val) {
        if (l == r - 1) {
            t[v] = new Node(val.x, val.y);
            return;
        }
        int m = (l + r) / 2;
        if (pos < m)
            upd(v * 2, l, m, pos, val);
        else
            upd(v * 2 + 1, m, r, pos, val);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }

    static int[] val = new int[N];
    static int[] len = new int[N];

    static double ask(int v, int l, int r, int L, int R, long[] x) {
        if (L >= R)
            return 2 * INF;
        if (l == L && r == R) {
            if (t[v].minsum + x[0] > 0) {
                x[0] += t[v].sum;
                return 2 * INF;
            }

            while (l < r - 1) {
                int m = (l + r) / 2;

                if (t[v * 2].minsum + x[0] <= 0) {
                    r = m;
                    v = v * 2;
                } else {
                    x[0] += t[v * 2].sum;
                    l = m;
                    v = v * 2 + 1;
                }
            }
            if (x[0] == 0)
                return vals.get(l);

            assert t[v].minsum + x[0] <= 0;
            assert t[v].s < 0;
            double res = vals.get(l) + (double) x[0] / -t[v].s;
            x[0] = 0;
            return res;
        }
        int m = (l + r) / 2;
        double tmp = ask(v * 2, l, m, L, Math.min(m, R), x);
        if (x[0] == 0) return tmp;
        assert x[0] > 0;
        return ask(v * 2 + 1, m, r, Math.max(m, L), R, x);
    }

    static void solve() {
        vals.clear();
        for (int i = 0; i < n; i++) if (a[i].x.x == 1)
            vals.add(a[i].x.y);
        vals.add(0);
        vals.add(INF + 1);
        Collections.sort(vals);
        vals = new ArrayList<>(new HashSet<>(vals));
        Collections.sort(vals);
        Set<Integer> cur = new TreeSet<>();
        build(1, 0, vals.size());

        val[0] = 0;
        len[0] = INF + 1;

        cur.add(0);
        cur.add(vals.size() - 1);

        for (int i = 0; i < n; i++) {
            if (a[i].x.x == 1) {
                int pos = Collections.binarySearch(vals, a[i].x.y);
                if (pos < 0) pos = -pos - 1;
                Iterator<Integer> pos2 = cur.iterator();
                while (pos2.hasNext()) {
                    int p = pos2.next();
                    if (p >= pos) break;
                }
                val[pos] = a[i].y.x;
                --pos2;
                len[(Integer) pos2] = vals.get(pos) - vals.get((Integer) pos2);
                upd(1, 0, vals.size(), (Integer) pos2, new Point(val[(Integer) pos2], len[(Integer) pos2]));
                ++pos2;
                len[pos] = vals.get((Integer) pos2) - vals.get(pos);
                upd(1, 0, vals.size(), pos, new Point(val[pos], len[pos]));
                cur.add(pos);
            } else if (a[i].x.x == 2) {
                int pos = Collections.binarySearch(vals, a[i].x.y);
                if (pos < 0) pos = -pos - 1;
                Iterator<Integer> pos2 = cur.iterator();
                while (pos2.hasNext()) {
                    int p = pos2.next();
                    if (p >= pos) break;
                }
                val[(Integer) pos2] = len[(Integer) pos2] = 0;
                upd(1, 0, vals.size(), (Integer) pos2, new Point(val[(Integer) pos2], len[(Integer) pos2]));
                pos2 = cur.iterator();
                pos2.remove();
                int l = vals.get((Integer) pos2);
                --pos2;
                l -= vals.get((Integer) pos2);
                len[(Integer) pos2] = l;
                upd(1, 0, vals.size(), (Integer) pos2, new Point(val[(Integer) pos2], len[(Integer) pos2]));
            } else {
                int l = Collections.binarySearch(vals, a[i].x.y);
                if (l < 0) l = -l - 1;
                Iterator<Integer> lit = cur.iterator();
                while (lit.hasNext()) {
                    int p = lit.next();
                    if (p >= l) break;
                }
                int r = a[i].y.x;
                long[] x = new long[]{a[i].y.y};
                if (x[0] == 0) {
                    System.out.printf("%.15f\n", (double) a[i].x.y);
                    continue;
                }

                double res = ask(1, 0, vals.size(), (Integer) lit, vals.size(), x);
                if (x[0] == 0 && res < r + EPS)
                    System.out.printf("%.15f\n", res);
                else
                    System.out.println("-1");
            }
        }
    }

    public static void main(String[] args) {
        while (read()) {
            solve();
        }
    }

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Pair<X, Y> {
        X x;
        Y y;

        Pair(X x, Y y) {
            this.x = x;
            this.y = y;
        }
    }
}
