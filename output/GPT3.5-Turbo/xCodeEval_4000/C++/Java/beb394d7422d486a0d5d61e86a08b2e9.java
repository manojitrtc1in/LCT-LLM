import java.util.*;
import java.io.*;

class Main {
    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class SegmentTree<T> {
        static class Node<T> {
            Node<T>[] c;
            T s;
            int l, r;

            Node(int l, int r) {
                this.c = new Node[2];
                this.s = null;
                this.l = l;
                this.r = r;
            }
        }

        Node<T> root;

        Node<T> build(List<T> a, int l, int r) {
            Node<T> u = new Node<>(l, r);
            if (l == r) {
                u.c[0] = u.c[1] = null;
                u.s = a.get(l);
            } else {
                int m = (l + r) / 2;
                u.c[0] = build(a, l, m);
                u.c[1] = build(a, m + 1, r);
                u.s.merge(u.c[0].s, u.c[1].s);
            }
            return u;
        }

        SegmentTree(List<T> a) {
            this.root = build(a, 0, a.size() - 1);
        }

        void destroy(Node<T> u) {
            if (u != null) {
                destroy(u.c[0]);
                destroy(u.c[1]);
            }
        }

        void push(Node<T> u) {
            if (u.c[0] != null) {
                u.c[0].s.tag(u.s.tag());
                u.c[1].s.tag(u.s.tag());
            }
            u.s.push();
        }

        void merge(Node<T> u) {
            u.s.merge(u.c[0].s, u.c[1].s);
        }

        void modifySingle(int p, T s, Node<T> u) {
            if (u == null) {
                u = root;
            }
            push(u);
            if (u.l == u.r) {
                assert p == u.l;
                u.s = s;
            } else {
                modifySingle(p, s, u.c[p > u.c[0].r ? 1 : 0]);
                push(u.c[p <= u.c[0].r ? 1 : 0]);
                merge(u);
            }
        }

        void modifySegment(int l, int r, int t, Node<T> u) {
            if (u == null) {
                u = root;
            }
            assert (u != root || (u.l <= l && u.r >= r)) && l <= r;
            push(u);
            if (l <= u.l && r >= u.r) {
                u.s.tag(t);
                push(u);
            } else {
                if (l <= u.c[0].r) {
                    modifySegment(l, r, t, u.c[0]);
                } else {
                    push(u.c[0]);
                }
                if (r >= u.c[1].l) {
                    modifySegment(l, r, t, u.c[1]);
                } else {
                    push(u.c[1]);
                }
                merge(u);
            }
        }

        T querySingle(int p, Node<T> u) {
            if (u == null) {
                u = root;
            }
            push(u);
            if (u.l == u.r) {
                assert p == u.l;
                return u.s;
            } else {
                return querySingle(p, u.c[p > u.c[0].r ? 1 : 0]);
            }
        }

        T querySegment(int l, int r, Node<T> u) {
            if (u == null) {
                u = root;
            }
            assert (u != root || (u.l <= l && u.r >= r)) && l <= r;
            push(u);
            if (l <= u.l && r >= u.r) {
                return u.s;
            } else {
                if (r <= u.c[0].r) {
                    return querySegment(l, r, u.c[0]);
                }
                if (l >= u.c[1].l) {
                    return querySegment(l, r, u.c[1]);
                }
                T t = new T();
                t.merge(querySegment(l, r, u.c[0]), querySegment(l, r, u.c[1]));
                return t;
            }
        }
    }

    static class Statistic {
        int[][] p;
        int l, r;

        Statistic(int pr, int pos) {
            p = new int[2][2];
            p[0][0] = 1 - pr;
            p[1][1] = pr;
            l = r = pos;
        }

        void merge(Statistic a, Statistic b) {
            l = a.l;
            r = b.r;
            int m = a.r;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    p[i][j] = 0;
                    for (int k = 0; k < 2; k++) {
                        for (int l = 0; l < 2; l++) {
                            if (k == 0 && l == 1 && policy[m][3]) {
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            } else if (k == 0 && l == 0 && policy[m][0]) {
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            } else if (k == 1 && l == 1 && policy[m][1]) {
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            } else if (k == 1 && l == 0 && policy[m][2]) {
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            }
                        }
                    }
                }
            }
        }

        int ans() {
            int tmp = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tmp += p[i][j];
                }
            }
            return tmp;
        }
    }

    static class Col implements Comparable<Col> {
        int i, tp, t1, t2;

        Col(int i, int tp, int t1, int t2) {
            this.i = i;
            this.tp = tp;
            this.t1 = t1;
            this.t2 = t2;
        }

        int ans() {
            return t1 / t2;
        }

        public int compareTo(Col other) {
            return Long.compare((long) t1 * other.t2, (long) other.t1 * t2);
        }
    }

    static int[][] policy;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        policy = new int[n - 1][4];
        List<Statistic> s = new ArrayList<>();
        int[] x = new int[n];
        int[] v = new int[n];
        int[] p = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            x[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(st.nextToken());
            s.add(new Statistic(p[i] / 100, i));
        }
        SegmentTree<Statistic> tree = new SegmentTree<>(s);
        long ans = 0;
        List<Col> cols = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            Col tmp = new Col(i, 2, x[i + 1] - x[i], v[i] + v[i + 1]);
            cols.add(tmp);
            if (v[i] > v[i + 1]) {
                tmp = new Col(i, 1, x[i + 1] - x[i], v[i] - v[i + 1]);
                cols.add(tmp);
            }
            if (v[i] < v[i + 1]) {
                tmp = new Col(i, 0, x[i + 1] - x[i], v[i + 1] - v[i]);
                cols.add(tmp);
            }
        }
        Collections.sort(cols);
        for (Col c : cols) {
            int[] old = policy[c.i];
            Arrays.fill(policy[c.i], 0);
            policy[c.i][c.tp] = 1;
            tree.modifySingle(c.i, new Statistic(p[c.i] / 100, c.i), tree.root);
            ans += tree.root.s.ans() * c.ans();
            policy[c.i] = old;
            policy[c.i][c.tp] = 0;
            tree.modifySingle(c.i, new Statistic(p[c.i] / 100, c.i), tree.root);
            if (tree.root.s.ans() == 0) {
                break;
            }
        }
        System.out.println(ans);
    }
}
