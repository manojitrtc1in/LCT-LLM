import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskC.id10.Edge[] es = new TaskC.id10.Edge[m];
            boolean[] used = new boolean[3 * n];
            Map<Long, Integer> edges = new HashMap<>();

            for (int i = 0; i < m; ++i) {
                int u = in.nextInt();
                int v = in.nextInt();
                if (u > v) {
                    int t = u;
                    u = v;
                    v = t;
                }
                es[i] = new TaskC.id10.Edge(u, v);
                edges.put(((long) u << 32) + v, i + 1);
            }

            TaskC.id10 mm = new TaskC.id10(3 * n, es);
            int ans = mm.maximum_matching();
            for (int i = 1; i <= 3 * n; i++)
                if (mm.mate[i] > i) {
                    used[i - 1] = used[mm.mate[i] - 1] = true;
                }

            if (ans >= n) {
                out.println("Matching");
                for (int i = 1, cnt = 0; cnt < n; i++)
                    if (mm.mate[i] > i) {
                        out.print(edges.get(((long) i << 32) + mm.mate[i]) + " ");
                        ++cnt;
                    }
            } else {
                out.println("IndSet");
                for (int i = 0, cnt = 0; cnt < n; ++i) {
                    if (!used[i]) {
                        ++cnt;
                        out.print((i + 1) + " ");
                    }
                }
            }
            out.println();
        }

        static class id10 {
            static final int Inf = 1 << 30;
            static final int kInner = -1;
            static final int kFree = 0;
            int N;
            int NH;
            int[] ofs;
            TaskC.id10.Edge[] edges;
            TaskC.id10.Queue que;
            int[] mate;
            int[] potential;
            int[] label;
            TaskC.id10.Link[] link;
            TaskC.id10.Log[] id4;
            int id14;
            int id8;
            TaskC.id10.id6 dsu;
            TaskC.id10.LinkedList list;
            TaskC.id10.LinkedList id12;
            int[] stack;
            int id3;
            int id13;
            int id16;
            int id7;
            int id11;

            public id10(int N, TaskC.id10.Edge[] in) {
                this.N = N;
                NH = N >> 1;
                ofs = new int[N + 2];
                edges = new TaskC.id10.Edge[in.length * 2];
                for (TaskC.id10.Edge e : in) {
                    ofs[e.from + 1] += 1;
                    ofs[e.to + 1] += 1;
                }
                for (int i = 1; i <= N + 1; ++i) ofs[i] += ofs[i - 1];
                for (TaskC.id10.Edge e : in) {
                    edges[ofs[e.from]++] = e;
                    edges[ofs[e.to]++] = new TaskC.id10.Edge(e.to, e.from);
                }
                for (int i = N + 1; i > 0; --i) ofs[i] = ofs[i - 1];
                ofs[0] = 0;
            }

            public int maximum_matching() {
                initialize();
                int match = 0;
                while (match * 2 + 1 < N) {
                    reset_count();
                    boolean id15 = id5();
                    if (!id15) break;
                    match += id9();
                    clear();
                }
                return match;
            }

            void reset_count() {
                id13 = 0;
                id16 = Inf;
                id7 = 0;
                id11 = 1;
                id8 = id14 = 0;
            }

            void clear() {
                que.clear();
                for (int u = 1; u <= N; ++u) potential[u] = 1;
                for (int u = 1; u <= N; ++u) dsu.par[u] = u;
                for (int t = id13; t <= N / 2; ++t) list.head[t] = -1;
                for (int u = 1; u <= N; ++u) id12.head[u] = -1;
            }

            void grow(int x, int y, int z) {
                label[y] = kInner;
                potential[y] = id13; 

                link[z] = new TaskC.id10.Link(x, y);
                label[z] = label[x];
                potential[z] = id13 + 1;
                que.enqueue(z);
            }

            void contract(int x, int y) {
                int bx = dsu.find(x), by = dsu.find(y);
                final int h = -(++id7) + kInner;
                label[mate[bx]] = label[mate[by]] = h;
                int lca = -1;
                while (true) {
                    if (mate[by] != 0) {
                        int t = bx;
                        bx = by;
                        by = t;
                    }
                    bx = lca = dsu.find(link[bx].from);
                    if (label[mate[bx]] == h) break;
                    label[mate[bx]] = h;
                }
                for (int bv : new int[]{dsu.par[x], dsu.par[y]}) {
                    for (; bv != lca; bv = dsu.par[link[bv].from]) {
                        int mv = mate[bv];
                        link[mv] = new TaskC.id10.Link(x, y);
                        label[mv] = label[x];
                        potential[mv] = 1 + (id13 - potential[mv]) + id13;
                        que.enqueue(mv);
                        dsu.par[bv] = dsu.par[mv] = lca;
                        id4[id14++] = new TaskC.id10.Log(bv, lca);
                        id4[id14++] = new TaskC.id10.Log(mv, lca);
                    }
                }
            }

            boolean id1() {
                while (!que.empty()) {
                    int x = que.dequeue(), lx = label[x], px = potential[x], bx = dsu.find(x);
                    for (int eid = ofs[x]; eid < ofs[x + 1]; ++eid) {
                        int y = edges[eid].to;
                        if (label[y] > 0) { 

                            int time_next = (px + potential[y]) >> 1;
                            if (lx != label[y]) {
                                if (time_next == id13) return true;
                                id16 = Math.min(time_next, id16);
                            } else {
                                if (bx == dsu.find(y)) continue;
                                if (time_next == id13) {
                                    contract(x, y);
                                    bx = dsu.find(x);
                                } else if (time_next <= NH) list.push(time_next, eid);
                            }
                        } else if (label[y] == kFree) { 

                            int time_next = px + 1;
                            if (time_next == id13) grow(x, y, mate[y]);
                            else if (time_next <= NH) list.push(time_next, eid);
                        }
                    }
                }
                return false;
            }

            boolean id2() {
                

                int time_lim = Math.min(NH + 1, id16);
                for (++id13; id13 <= time_lim; ++id13) {
                    id8 = id14;
                    if (id13 == time_lim) break;
                    boolean updated = false;
                    for (int h = list.head[id13]; h >= 0; h = list.next[h]) {
                        TaskC.id10.Edge e = edges[h];
                        int x = e.from, y = e.to;
                        if (label[y] > 0) {
                            

                            if (potential[x] + potential[y] != (id13 << 1)) continue;
                            if (dsu.find(x) == dsu.find(y)) continue;
                            if (label[x] != label[y]) {
                                id16 = id13;
                                return false;
                            }
                            contract(x, y);
                            updated = true;
                        } else if (label[y] == kFree) {
                            grow(x, y, mate[y]);
                            updated = true;
                        }
                    }
                    list.head[id13] = -1;
                    if (updated) return false;
                }
                return id13 > NH;
            }

            boolean id5() {
                label[0] = kFree;
                for (int u = 1; u <= N; ++u) {
                    if (mate[u] == 0) {
                        que.enqueue(u);
                        label[u] = u; 

                    } else label[u] = kFree;
                }
                while (true) {
                    if (id1()) break;
                    boolean maximum = id2();
                    if (maximum) return false;
                    if (id13 == id16) break;
                }
                for (int u = 1; u <= N; ++u) {
                    if (label[u] > 0) potential[u] -= id13;
                    else if (label[u] < 0) potential[u] = 1 + (id13 - potential[u]);
                }
                return true;
            }

            void rematch(int v, int w) {
                int t = mate[v];
                mate[v] = w;
                if (mate[t] != v) return;
                if (link[v].to == dsu.find(link[v].to)) {
                    mate[t] = link[v].from;
                    rematch(mate[t], t);
                } else {
                    int x = link[v].from, y = link[v].to;
                    rematch(x, y);
                    rematch(y, x);
                }
            }

            boolean id17(int x, int bx) {
                int px = potential[x], lx = label[bx];
                for (int eid = ofs[x]; eid < ofs[x + 1]; ++eid) {
                    int y = edges[eid].to;
                    if (px + potential[y] != 0) continue;
                    int by = dsu.find(y), ly = label[by];
                    if (ly > 0) { 

                        if (lx >= ly) continue;
                        int id0 = id3;
                        for (int bv = by; bv != bx; bv = dsu.find(link[bv].from)) {
                            int bw = dsu.find(mate[bv]);
                            stack[id3++] = bw;
                            link[bw] = new TaskC.id10.Link(x, y);
                            dsu.par[bv] = dsu.par[bw] = bx;
                        }
                        while (id3 > id0) {
                            int bv = stack[--id3];
                            for (int v = id12.head[bv]; v >= 0; v = id12.next[v]) {
                                if (!id17(v, bx)) continue;
                                id3 = id0;
                                return true;
                            }
                        }
                    } else if (ly == kFree) {
                        label[by] = kInner;
                        int z = mate[by];
                        if (z == 0) {
                            rematch(x, y);
                            rematch(y, x);
                            return true;
                        }
                        int bz = dsu.find(z);
                        link[bz] = new TaskC.id10.Link(x, y);
                        label[bz] = id11++;
                        for (int v = id12.head[bz]; v >= 0; v = id12.next[v]) {
                            if (id17(v, bz)) return true;
                        }
                    }
                }
                return false;
            }

            int id9() {
                

                for (int u = 1; u <= N; ++u) dsu.par[u] = u;
                for (int i = 0; i < id8; ++i) {
                    dsu.par[id4[i].v] = id4[i].par;
                }
                for (int u = 1; u <= N; ++u) {
                    label[u] = kFree;
                    id12.push(dsu.find(u), u);
                }
                int ret = 0;
                for (int u = 1; u <= N; ++u)
                    if (mate[u] == 0) {
                        int bu = dsu.par[u];
                        if (label[bu] != kFree) continue;
                        label[bu] = id11++;
                        for (int v = id12.head[bu]; v >= 0; v = id12.next[v]) {
                            if (!id17(v, bu)) continue;
                            ret += 1;
                            break;
                        }
                    }
                assert (ret >= 1);
                return ret;
            }

            void initialize() {
                que = new TaskC.id10.Queue(N);

                mate = new int[N + 1];
                potential = new int[N + 1];
                Arrays.fill(potential, 1);
                label = new int[N + 1];
                Arrays.fill(label, kFree);
                link = new TaskC.id10.Link[N + 1];
                for (int i = 0; i < link.length; i++)
                    link[i] = new TaskC.id10.Link(0, 0);

                id4 = new TaskC.id10.Log[N];

                dsu = new TaskC.id10.id6(N + 1);
                list = new TaskC.id10.LinkedList(NH + 1, edges.length);

                id12 = new TaskC.id10.LinkedList(N + 1, N + 1);
                stack = new int[N];
                id3 = 0;
            }

            public static class Edge {
                int from;
                int to;

                public Edge(int from, int to) {
                    this.from = from;
                    this.to = to;
                }

            }

            static class Link {
                int from;
                int to;

                Link(int from, int to) {
                    this.from = from;
                    this.to = to;
                }

            }

            static class Log {
                int v;
                int par;

                Log(int v, int par) {
                    this.v = v;
                    this.par = par;
                }

            }

            static class LinkedList {
                int N;
                int[] head;
                int[] next;

                LinkedList() {
                }

                LinkedList(int N, int M) {
                    this.N = N;
                    next = new int[M];
                    head = new int[N];
                    clear();
                }

                void clear() {
                    Arrays.fill(head, -1);
                }

                void push(int h, int u) {
                    next[u] = head[h];
                    head[h] = u;
                }

            }

            static class Queue {
                int qh;
                int qt;
                int[] data;

                Queue() {
                }

                Queue(int N) {
                    qh = 0;
                    qt = 0;
                    data = new int[N];
                }

                void enqueue(int u) {
                    data[qt++] = u;
                }

                int dequeue() {
                    return data[qh++];
                }

                boolean empty() {
                    return qh == qt;
                }

                void clear() {
                    qh = qt = 0;
                }

            }

            static class id6 {
                int[] par;

                id6() {
                }

                id6(int N) {
                    par = new int[N];
                    for (int i = 0; i < N; ++i) par[i] = i;
                }

                int find(int u) {
                    return par[u] == u ? u : (par[u] = find(par[u]));
                }

            }

        }

    }

    static class InputReader {
        final InputStream is;
        final byte[] buf = new byte[1024];
        int pos;
        int size;

        public InputReader(InputStream is) {
            this.is = is;
        }

        public int nextInt() {
            int c = read();
            while (isWhitespace(c))
                c = read();
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = res * 10 + c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sign;
        }

        public String next() {
            int c = read();
            while (isWhitespace(c))
                c = read();
            StringBuilder sb = new StringBuilder();
            do {
                sb.append((char) c);
                c = read();
            } while (!isWhitespace(c));
            return sb.toString();
        }

        int read() {
            if (size == -1)
                throw new InputMismatchException();
            if (pos >= size) {
                pos = 0;
                try {
                    size = is.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (size <= 0)
                    return -1;
            }
            return buf[pos++] & 255;
        }

        static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}

