import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
    static class Statistic {
        int[][] p = new int[2][2];
        int l, r;

        Statistic(double pr, int pos) {
            p[0][0] = (int) (1 - pr);
            p[1][1] = (int) pr;
            l = r = pos;
        }

        void merge(Statistic a, Statistic b) {
            l = a.l;
            r = b.r;
            int m = a.r;
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    p[i][j] = 0;
                    for (int k = 0; k <= 1; k++) {
                        for (int l = 0; l <= 1; l++) {
                            if (k == 0 && l == 1 && policy[m][3] == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            else if (k == 0 && l == 0 && policy[m][0] == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            else if (k == 1 && l == 1 && policy[m][1] == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            else if (k == 1 && l == 0 && policy[m][2] == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                        }
                    }
                }
            }
        }

        double ans() {
            double tmp = 0;
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    tmp += p[i][j];
                }
            }
            return tmp;
        }
    }

    static class Col implements Comparable<Col> {
        int i, tp;
        int t1, t2;

        double ans() {
            return (double) t1 / t2;
        }

        @Override
        public int compareTo(Col other) {
            return Long.compare((long) this.t1 * other.t2, (long) other.t1 * this.t2);
        }
    }

    static int[][] policy;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        policy = new int[n - 1][4];
        for (int i = 0; i < n - 1; i++) {
            Arrays.fill(policy[i], 1);
        }

        List<Statistic> s = new ArrayList<>();
        int[] x = new int[n], v = new int[n], p = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            x[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
            s.add(new Statistic(p[i] / 100.0, i));
        }

        SegmentTree<Statistic> tree = new SegmentTree<>(s);
        double ans = 0;
        List<Col> cols = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            Col tmp = new Col();
            tmp.i = i;
            tmp.t1 = x[i + 1] - x[i];
            tmp.tp = 2;
            tmp.t2 = v[i] + v[i + 1];
            cols.add(tmp);
            if (v[i] > v[i + 1]) {
                tmp.tp = 1;
                tmp.t2 = v[i] - v[i + 1];
                cols.add(tmp);
            }
            if (v[i] < v[i + 1]) {
                tmp.tp = 0;
                tmp.t2 = v[i + 1] - v[i];
                cols.add(tmp);
            }
        }

        Collections.sort(cols);
        for (Col c : cols) {
            int[] old = policy[c.i].clone();
            Arrays.fill(policy[c.i], 0);
            policy[c.i][c.tp] = 1;
            tree.modifySingle(c.i, new Statistic(p[c.i] / 100.0, c.i));
            ans += tree.root.s.ans() * c.ans();
            policy[c.i] = old;
            policy[c.i][c.tp] = 0;
            tree.modifySingle(c.i, new Statistic(p[c.i] / 100.0, c.i));
            if (tree.root.s.ans() == 0) break;
        }

        out.printf("%.12f\n", ans);
        out.flush();
    }
}

class SegmentTree<T> {
    static class Node<T> {
        Node<T>[] c = new Node[2];
        T s;
        int l, r;

        Node(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    Node<T> root;

    SegmentTree(List<T> a) {
        root = build(a, 0, a.size() - 1);
    }

    Node<T> build(List<T> a, int l, int r) {
        Node<T> u = new Node<>(l, r);
        if (l == r) {
            u.s = a.get(l);
        } else {
            int m = (l + r) / 2;
            u.c[0] = build(a, l, m);
            u.c[1] = build(a, m + 1, r);
            // Assuming merge method exists in T
            // u.s.merge(u.c[0].s, u.c[1].s);
        }
        return u;
    }

    void modifySingle(int p, T s) {
        modifySingle(p, s, root);
    }

    void modifySingle(int p, T s, Node<T> u) {
        // Assuming push method exists in T
        // push(u);
        if (u.l == u.r) {
            // Assuming assert method exists
            // assert(p == u.l);
            u.s = s;
        } else {
            modifySingle(p, s, u.c[p > u.c[0].r ? 1 : 0]);
            // Assuming push and merge methods exist in T
            // push(u.c[p <= u.c[0].r ? 0 : 1]);
            // merge(u);
        }
    }
}
