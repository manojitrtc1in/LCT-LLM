import java.util.*;

class Main {
    static class DijkstraHeap<T extends Comparable<T>> {
        T[] val;
        boolean[] visited;
        int[] hp, place;
        int size;

        void malloc(int N) {
            hp = new int[N];
            place = new int[N];
            visited = new boolean[N];
            val = (T[]) new Comparable[N];
        }

        void free() {
            hp = null;
            place = null;
            visited = null;
            val = null;
        }

        void walloc(int N) {
            walloc1d(hp, N);
            walloc1d(place, N);
            walloc1d(visited, N);
            walloc1d(val, N);
        }

        void init(int N) {
            size = 0;
            Arrays.fill(place, -1);
            Arrays.fill(visited, false);
        }

        void up(int n) {
            int m;
            while (n > 0) {
                m = (n - 1) / 2;
                if (val[hp[m]].compareTo(val[hp[n]]) <= 0) {
                    break;
                }
                swap(hp, m, n);
                swap(place, hp[m], hp[n]);
                n = m;
            }
        }

        void down(int n) {
            int m;
            while (true) {
                m = 2 * n + 1;
                if (m >= size) {
                    break;
                }
                if (m + 1 < size && val[hp[m]].compareTo(val[hp[m + 1]]) > 0) {
                    m++;
                }
                if (val[hp[m]].compareTo(val[hp[n]]) >= 0) {
                    break;
                }
                swap(hp, m, n);
                swap(place, hp[m], hp[n]);
                n = m;
            }
        }

        void change(int n, T v) {
            if (visited[n] || (place[n] >= 0 && val[n].compareTo(v) <= 0)) {
                return;
            }
            val[n] = v;
            if (place[n] == -1) {
                place[n] = size;
                hp[size++] = n;
                up(place[n]);
            } else {
                up(place[n]);
            }
        }

        int pop() {
            int res = hp[0];
            place[res] = -1;
            size--;
            if (size > 0) {
                hp[0] = hp[size];
                place[hp[0]] = 0;
                down(0);
            }
            visited[res] = true;
            return res;
        }
    }

    static class Graph {
        int N;
        int[][] edge;
        int[] es;

        void setEdge(int N__, int M, int[] A, int[] B) {
            N = N__;
            es = new int[N];
            for (int i = 0; i < N; i++) {
                es[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                es[A[i]]++;
                es[B[i]]++;
            }
            edge = new int[N][];
            for (int i = 0; i < N; i++) {
                edge[i] = new int[es[i]];
            }
            for (int i = 0; i < N; i++) {
                es[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                edge[A[i]][es[A[i]]++] = B[i];
                edge[B[i]][es[B[i]]++] = A[i];
            }
        }

        void setDirectEdge(int N__, int M, int[] A, int[] B) {
            N = N__;
            es = new int[N];
            for (int i = 0; i < N; i++) {
                es[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                es[A[i]]++;
            }
            edge = new int[N][];
            for (int i = 0; i < N; i++) {
                edge[i] = new int[es[i]];
            }
            for (int i = 0; i < N; i++) {
                es[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                edge[A[i]][es[A[i]]++] = B[i];
            }
        }

        Graph reverse() {
            Graph g = new Graph();
            g.N = N;
            g.es = new int[N];
            g.edge = new int[N][];
            for (int i = 0; i < N; i++) {
                g.es[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < es[i]; j++) {
                    g.es[edge[i][j]]++;
                }
            }
            for (int i = 0; i < N; i++) {
                g.edge[i] = new int[g.es[i]];
            }
            for (int i = 0; i < N; i++) {
                g.es[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < es[i]; j++) {
                    int k = edge[i][j];
                    g.edge[k][g.es[k]++] = i;
                }
            }
            return g;
        }

        Graph reduce(int tn, int[] ind, int self_e, int dep_e) {
            Graph g = new Graph();
            int M = 0;
            int[] A = new int[N];
            int[] B = new int[N];
            for (int i = 0; i < N; i++) {
                M += es[i];
            }
            Pair[] arr = new Pair[M];
            M = 0;
            for (int i = 0; i < N; i++) {
                int x = ind[i];
                if (x < 0) {
                    continue;
                }
                for (int j = 0; j < es[i]; j++) {
                    int y = ind[edge[i][j]];
                    if (y < 0) {
                        continue;
                    }
                    if (self_e == 0 && x == y) {
                        continue;
                    }
                    arr[M++] = new Pair(x, y);
                }
            }
            if (dep_e == 0) {
                Arrays.sort(arr, 0, M);
                int k = 0;
                for (int i = 0; i < M; i++) {
                    if (k > 0 && arr[k - 1].equals(arr[i])) {
                        continue;
                    }
                    arr[k++] = arr[i];
                }
                M = k;
            }
            g.N = tn;
            g.es = new int[tn];
            g.edge = new int[tn][];
            g.edge[0] = new int[M];
            for (int i = 0; i < tn; i++) {
                g.es[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                g.es[arr[i].first]++;
            }
            for (int i = 1; i < tn; i++) {
                g.edge[i] = new int[g.es[i]];
            }
            for (int i = 0; i < tn; i++) {
                g.es[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                int j = arr[i].first;
                int k = arr[i].second;
                g.edge[j][g.es[j]++] = k;
            }
            return g;
        }

        void getDist(int root, int[] res) {
            int[] q = new int[N];
            for (int i = 0; i < N; i++) {
                res[i] = -1;
            }
            res[root] = 0;
            int s = 0;
            int z = 1;
            q[0] = root;
            while (z > 0) {
                int i = q[s++];
                z--;
                for (int j = 0; j < es[i]; j++) {
                    int k = edge[i][j];
                    if (res[k] >= 0) {
                        continue;
                    }
                    res[k] = res[i] + 1;
                    q[s + z++] = k;
                }
            }
        }

        int sccDFS(int[] num, int st, int mx) {
            num[st] = -2;
            for (int i = 0; i < es[st]; i++) {
                int j = edge[st][i];
                if (num[j] == -1) {
                    mx = sccDFS(num, j, mx);
                }
            }
            num[st] = mx;
            return mx + 1;
        }

        int scc(int[] res) {
            Graph r = reverse();
            int[] nrv = new int[N];
            int[] num = new int[N];
            int ret = 0;
            int[] st = new int[N];
            int st_size;
            r = reverse();
            for (int i = 0; i < N; i++) {
                res[i] = num[i] = -1;
            }
            int k = 0;
            for (int i = 0; i < N; i++) {
                if (num[i] == -1) {
                    k = sccDFS(num, i, k);
                }
            }
            for (int i = 0; i < N; i++) {
                nrv[num[i]] = i;
            }
            for (int k = N - 1; k >= 0; k--) {
                int i = nrv[k];
                if (res[i] >= 0) {
                    continue;
                }
                res[i] = ret;
                st_size = 0;
                st[st_size++] = i;
                while (st_size > 0) {
                    i = st[--st_size];
                    for (int j = 0; j < r.es[i]; j++) {
                        if (res[r.edge[i][j]] == -1) {
                            res[r.edge[i][j]] = ret;
                            st[st_size++] = r.edge[i][j];
                        }
                    }
                }
                ret++;
            }
            return ret;
        }

        void bccDFS(int v, int u, int[] res, int[] rt, int[] rts, int[] S, int[] Ss, int[] inS, int[] num, int[] tm) {
            num[v] = ++tm[0];
            S[Ss[0]++] = v;
            inS[v] = 1;
            rt[rts[0]++] = v;
            for (int i = 0; i < es[v]; i++) {
                int w = edge[v][i];
                if (num[w] == 0) {
                    bccDFS(w, v, res, rt, rts, S, Ss, inS, num, tm);
                } else if (u != w && inS[w] != 0) {
                    while (num[rt[rts[0] - 1]] > num[w]) {
                        rts[0]--;
                    }
                }
            }
            if (v == rt[rts[0] - 1]) {
                int k = S[Ss[0] - 1];
                while (true) {
                    int w = S[--Ss[0]];
                    inS[w] = 0;
                    res[w] = k;
                    if (v == w) {
                        break;
                    }
                }
                rts[0]--;
            }
        }

        int bcc(int[] res) {
            int[] S = new int[N];
            int[] Ss = new int[1];
            int[] inS = new int[N];
            int[] num = new int[N];
            int[] rt = new int[N];
            int[] rts = new int[1];
            int[] tm = new int[1];
            Pair[] arr = new Pair[N];
            for (int i = 0; i < N; i++) {
                num[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                if (num[i] == 0) {
                    bccDFS(i, N, res, rt, rts, S, Ss, inS, num, tm);
                }
            }
            for (int i = 0; i < N; i++) {
                arr[i] = new Pair(res[i], i);
            }
            Arrays.sort(arr, 0, N);
            int k = 0;
            for (int i = 0; i < N; i++) {
                if (i > 0 && arr[i].first != arr[i - 1].first) {
                    k++;
                }
                res[arr[i].second] = k;
            }
            return k + 1;
        }

        void bccDFS(int v, int u, int[] res, int[] rt, int[] rts, int[] S, int[] Ss, int[] inS, int[] num, int[] tm, int[] low) {
            num[v] = low[v] = ++tm[0];
            S[Ss[0]++] = v;
            inS[v] = 1;
            rt[rts[0]++] = v;
            for (int i = 0; i < es[v]; i++) {
                int w = edge[v][i];
                if (num[w] == 0) {
                    bccDFS(w, v, res, rt, rts, S, Ss, inS, num, tm, low);
                    low[v] = Math.min(low[v], low[w]);
                } else if (u != w && inS[w] != 0) {
                    low[v] = Math.min(low[v], num[w]);
                }
            }
            if (v == rt[rts[0] - 1]) {
                int k = S[Ss[0] - 1];
                while (true) {
                    int w = S[--Ss[0]];
                    inS[w] = 0;
                    res[w] = k;
                    if (v == w) {
                        break;
                    }
                }
                rts[0]--;
            }
        }

        int bcc(int[] res, int[] low) {
            int[] S = new int[N];
            int[] Ss = new int[1];
            int[] inS = new int[N];
            int[] num = new int[N];
            int[] rt = new int[N];
            int[] rts = new int[1];
            int[] tm = new int[1];
            Pair[] arr = new Pair[N];
            for (int i = 0; i < N; i++) {
                num[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                if (num[i] == 0) {
                    bccDFS(i, N, res, rt, rts, S, Ss, inS, num, tm, low);
                }
            }
            for (int i = 0; i < N; i++) {
                arr[i] = new Pair(res[i], i);
            }
            Arrays.sort(arr, 0, N);
            int k = 0;
            for (int i = 0; i < N; i++) {
                if (i > 0 && arr[i].first != arr[i - 1].first) {
                    k++;
                }
                res[arr[i].second] = k;
            }
            return k + 1;
        }

        void getDist(int root, int[] res, int unreachable) {
            boolean[] r = new boolean[N];
            int[] q = new int[N];
            for (int i = 0; i < N; i++) {
                r[i] = false;
                res[i] = unreachable;
            }
            res[root] = 0;
            int s = 0;
            int z = 1;
            q[0] = root;
            while (z > 0) {
                int i = q[s++];
                z--;
                for (int j = 0; j < es[i]; j++) {
                    int k = edge[i][j];
                    if (r[k]) {
                        continue;
                    }
                    res[k] = res[i] + 1;
                    r[k] = true;
                    q[s + z++] = k;
                }
            }
        }

        int shortestPath(int s, int t, int[] res) {
            int[] b = new int[N];
            int[] q = new int[N];
            int qe = 0;
            int qs = 0;
            Arrays.fill(b, -1);
            b[s] = -2;
            q[qe++] = s;
            while (qe > qs) {
                int i = q[qs++];
                for (int j = 0; j < es[i]; j++) {
                    int k = edge[i][j];
                    if (b[k] != -1) {
                        continue;
                    }
                    b[k] = i;
                    q[qe++] = k;
                }
                if (b[t] != -1) {
                    break;
                }
            }
            if (b[t] == -1) {
                return -1;
            }
            int k = 0;
            res[k] = t;
            while (t != s) {
                res[++k] = (t = b[t]);
            }
            for (int i = 0; i <= k / 2; i++) {
                int tmp = res[i];
                res[i] = res[k - i];
                res[k - i] = tmp;
            }
            return k;
        }

        int TopologicalSort(int[] res) {
            int[] deg = new int[N];
            int[] q = new int[N];
            int qe = 0;
            int qs = 0;
            int rs;
            for (int i = 0; i < N; i++) {
                deg[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < es[i]; j++) {
                    deg[edge[i][j]]++;
                }
            }
            for (int i = 0; i < N; i++) {
                if (deg[i] == 0) {
                    q[qe++] = i;
                }
            }
            rs = 0;
            while (qs < qe) {
                int i = q[qs++];
                res[rs++] = i;
                for (int j = 0; j < es[i]; j++) {
                    int k = edge[i][j];
                    deg[k]--;
                    if (deg[k] == 0) {
                        q[qe++] = k;
                    }
                }
            }
            if (rs == N) {
                return 1;
            }
            return 0;
        }
    }

    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair other) {
            return Integer.compare(first, other.first);
        }
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N - 1];
        int[] B = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            A[i] = sc.nextInt() - 1;
            B[i] = sc.nextInt() - 1;
        }
        Graph g = new Graph();
        g.setEdge(N, N - 1, A, B);
        int[] arr = new int[N + 1];
        int as;
        int r;
        int[] ok = new int[N + 1];
        int[] dp = new int[N + 1];
        int[] back = new int[N + 1];
        int cnt;
        for (r = 0; r < N; r++) {
            as = 0;
            for (int i = 0; i < g.es[r]; i++) {
                arr[as++] = dfs2(g.edge[r][i], r);
            }
            Arrays.fill(dp, 0);
            dp[0] = 1;
            for (int i = 0; i < as; i++) {
                for (int j = N; j >= arr[i]; j--) {
                    if (dp[j] == 0 && dp[j - arr[i]] == 1) {
                        dp[j] = 1;
                        back[j] = i;
                    }
                }
            }
            int p;
            for (p = 0; p < N + 1; p++) {
                if (dp[p] == 1 && (p + 1) * (N - p) - 1 >= 2 * N * N / 9) {
                    break;
                }
            }
            if (p == N + 1) {
                continue;
            }
            k = p;
            while (k > 0) {
                ok[back[k]] = 1;
                k -= arr[back[k]];
            }
            cnt = 0;
            dfs(r, -1, 0, 1, 0);
            cnt = 0;
            dfs(r, -1, 0, p + 1, 1);
            break;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < g.es[i]; j++) {
                int k = g.edge[i][j];
                int r = g.cost[i][j];
                if (r > 0) {
                    System.out.println((i + 1) + " " + (k + 1) + " " + r);
                }
            }
        }
    }

    static int dfs2(int n, int b, Graph g) {
        int res = 1;
        for (int i = 0; i < g.es[n]; i++) {
            int k = g.edge[n][i];
            if (k == b) {
                continue;
            }
            res += dfs2(k, n, g);
        }
        return res;
    }

    static void dfs(int n, int b, int d, int m, int dm, Graph g, int[] cnt) {
        for (int i = 0; i < g.es[n]; i++) {
            if (n == r && ok[i] == dm) {
                continue;
            }
            int k = g.edge[n][i];
            if (k == b) {
                continue;
            }
            cnt[0]++;
            g.cost[n][i] = m * (cnt[0] - d);
            dfs(k, n, cnt[0], m, dm, g, cnt);
        }
    }
}
