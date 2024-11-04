import java.util.*;

class Dijkstra {
    int N;
    List<List<Pair>> E;

    public Dijkstra(int n) {
        N = n;
        E = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            E.add(new ArrayList<>());
        }
    }

    void insert(int u, int v, int w) {
        E.get(u).add(new Pair(v, w));
    }

    int[] dijkstra(int start, int end) {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.weight));
        pq.add(new Pair(start, 0));
        while (!pq.isEmpty()) {
            int w = pq.peek().weight;
            int u = pq.poll().node;
            if (u == end) return dist;
            if (dist[u] < w) continue;
            for (Pair edge : E.get(u)) {
                int v = edge.node;
                int w2 = w + edge.weight;
                if (dist[v] > w2) {
                    dist[v] = w2;
                    pq.add(new Pair(v, w2));
                }
            }
        }
        return dist;
    }

    void g() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int e = scanner.nextInt();
        Dijkstra dk = new Dijkstra(n);
        int s = scanner.nextInt();
        for (int i = 0; i < e; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            dk.insert(u, v, w);
        }
        int[] ans = dk.dijkstra(s, N);
        for (int i = 1; i <= n; i++) {
            if (ans[i] >= Integer.MAX_VALUE) System.out.println("INF");
            else System.out.println(ans[i]);
        }
    }
}

class Prim {
    int N;
    List<List<Pair>> E;

    public Prim(int n) {
        N = n;
        E = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            E.add(new ArrayList<>());
        }
    }

    void insert(int u, int v, int w) {
        E.get(u).add(new Pair(v, w));
    }

    int[] execute(long[] cost) {
        int[] dist = new int[N + 1];
        boolean[] selected = new boolean[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;
        cost[0] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.weight));
        pq.add(new Pair(1, 0));
        for (int k = 0; k < N; k++) {
            int w = pq.peek().weight;
            int u = pq.poll().node;
            if (selected[u]) {
                k--;
                continue;
            }
            cost[0] += w;
            selected[u] = true;
            for (Pair edge : E.get(u)) {
                int v = edge.node;
                int w2 = edge.weight;
                if (!selected[v] && dist[v] > w2) {
                    dist[v] = w2;
                    pq.add(new Pair(v, w2));
                }
            }
        }
        return dist;
    }

    void g() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int e = scanner.nextInt();
        Prim pm = new Prim(n);
        int s = scanner.nextInt();
        for (int i = 0; i < e; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            pm.insert(u, v, w);
        }
        long[] cost = new long[1];
        int[] ans = pm.execute(cost);
        System.out.println(cost[0]);
    }
}

class Floyd {
    int N;
    int[][] E;

    public Floyd(int n) {
        N = n;
        E = new int[N + 1][N + 1];
        for (int i = 0; i <= N; i++) {
            Arrays.fill(E[i], Integer.MAX_VALUE);
        }
    }

    void setRC(int r, int c, int w) {
        E[r][c] = w;
    }

    int getRC(int r, int c) {
        return E[r][c];
    }

    void execute() {
        for (int i = 1; i <= N; i++) E[i][i] = 0;
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    E[i][j] = Math.min(E[i][j], E[i][k] + E[k][j]);
                }
            }
        }
    }
}

class id5 {
    List<List<Pair>> E;
    int[] A;
    int N;

    public id5(int n) {
        N = n;
        E = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            E.add(new ArrayList<>());
        }
        A = new int[N + 1];
    }

    void insert(int u, int v, int w) {
        E.get(u).add(new Pair(v, w));
    }

    void insert_fb(int u, int v, int w) {
        E.get(u).add(new Pair(v, w));
        E.get(v).add(new Pair(u, w));
    }

    int dfsAll(int start, int end) {
        boolean[] visited = new boolean[N + 1];
        return dfs(start, end, visited);
    }

    int dfs(int start, int end, boolean[] visited) {
        if (start == end) return 1;
        visited[start] = true;
        for (Pair edge : E.get(start)) {
            int v = edge.node;
            if (!visited[v]) {
                if (dfs(v, end, visited) == 1) return 1;
            }
        }
        return 0;
    }

    void setA(int a, int b) {
        A[a] = b;
    }

    int dfsAll2() {
        int[] visited = new int[N + 1];
        int seq = 0, ret = 0;
        for (int i = 1; i <= N; i++) dfs2(i, visited, ++seq);
        for (int i = 1; i <= N; i++) {
            int a = 0;
            for (Pair edge : E.get(i)) {
                a += edge.weight;
            }
            if (ret < a) ret = a;
        }
        return ret;
    }

    int dfs2(int start, int[] visited, long seq) {
        visited[start] = (int) seq;
        int ret = A[start];
        for (Pair edge : E.get(start)) {
            int v = edge.node;
            if (visited[v] < seq) {
                if (edge.weight == -1) edge.weight = dfs2(v, visited, seq);
                if (ret < edge.weight) ret = edge.weight;
            }
        }
        return ret;
    }

    void g() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        id5 dg = new id5(n);
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            dg.insert(a, b, 0);
        }
        m = scanner.nextInt();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c;
            if (dg.dfsAll(a, b) == 1) c = -1;
            else if (dg.dfsAll(b, a) == 1) c = 1;
            else c = 0;
            System.out.println(c);
        }
    }
}

class DFS_Map {
    int R, C;
    int[][] E;

    public DFS_Map(int r, int c) {
        R = r;
        C = c;
        E = new int[R + 2][C + 2];
    }

    void setRC(int r, int c, int w) {
        E[r][c] = w;
    }

    int getRC(int r, int c) {
        return E[r][c];
    }

    void dfs(int rr, int cc, boolean[][] visited) {
        visited[rr][cc] = true;
        for (int i = 0; i < 4; i++) {
            int r = rr + dr[i];
            int c = cc + dc[i];
            if (E[r][c] != 0 && !visited[r][c]) {
                dfs(r, c, visited);
            }
        }
    }

    void dfsAll() {
        boolean[][] visited = new boolean[R + 2][C + 2];
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                if (!visited[r][c]) dfs(r, c, visited);
            }
        }
    }
}

class id7 {
    List<List<Pair>> E;
    int[] IN;
    int N;

    public id7(int n) {
        N = n;
        E = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            E.add(new ArrayList<>());
        }
        IN = new int[N + 1];
    }

    int is_cycle() {
        for (int i = 1; i <= N; i++) if (IN[i] > 0) return 1;
        return 0;
    }

    void insert(int u, int v, int w) {
        E.get(u).add(new Pair(v, w));
        IN[v]++;
    }

    void insert_fb(int u, int v, int w) {
        E.get(u).add(new Pair(v, w));
        E.get(v).add(new Pair(u, w));
    }

    long[] bfs(int start, int end, int min_weight) {
        boolean[] visited = new boolean[N + 1];
        long[] weight = new long[N + 1];
        Arrays.fill(weight, Long.MAX_VALUE);
        Queue<Integer> Q = new LinkedList<>();
        visited[start] = true;
        weight[start] = 0;
        Q.add(start);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            long w = weight[u];
            if (u == end) break;
            for (Pair edge : E.get(u)) {
                int v = edge.node;
                int c = edge.weight;
                if (c >= min_weight && !visited[v]) {
                    Q.add(v);
                    weight[v] = w + c;
                    visited[v] = true;
                }
            }
        }
        return weight;
    }

    List<Integer> topologicalSort() {
        List<Integer> order = new ArrayList<>();
        Queue<Integer> Q = new LinkedList<>();
        for (int i = 1; i <= N; i++) if (IN[i] == 0) Q.add(i);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            order.add(u);
            for (Pair edge : E.get(u)) {
                int v = edge.node;
                if (IN[v] > 0) {
                    IN[v]--;
                    if (IN[v] == 0) Q.add(v);
                }
            }
        }
        return order;
    }

    List<Integer> topologicalSortPQ() {
        List<Integer> order = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 1; i <= N; i++) if (IN[i] == 0) pq.add(i);
        while (!pq.isEmpty()) {
            int u = pq.poll();
            order.add(u);
            for (Pair edge : E.get(u)) {
                int v = edge.node;
                if (IN[v] > 0) {
                    IN[v]--;
                    if (IN[v] == 0) pq.add(v);
                }
            }
        }
        return order;
    }

    int f() {
        for (int u = 1; u <= N; u++) {
            for (Pair edge : E.get(u)) {
                int v = edge.node;
                if (IN[v] == 1) {
                    int[] IN2 = Arrays.copyOf(IN, IN.length);
                    IN[v]--;
                    topologicalSort();
                    if (is_cycle() == 0) return 1;
                    IN = IN2;
                }
            }
        }
        return 0;
    }

    void g() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        id7 bg = new id7(n);
        List<Tuple> X = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            X.add(new Tuple(a, b, -c));
        }
        int start = scanner.nextInt();
        int end = scanner.nextInt();
        Collections.sort(X);
        bg.insert_fb(X.get(0).a, X.get(0).b, -X.get(0).c);
        for (int i = 1; i < m; i++) {
            int a = X.get(i - 1).a;
            int b = X.get(i - 1).b;
            int c = X.get(i - 1).c;
            int a2 = X.get(i).a;
            int b2 = X.get(i).b;
            int c2 = X.get(i).c;
            if (a == a2 && b == b2) continue;
            bg.insert_fb(a2, b2, -c2);
        }
        int lo = 1, hi = Integer.MAX_VALUE;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            long[] y = bg.bfs(start, end, mid);
            if (y[end] < Long.MAX_VALUE) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        System.out.println(lo);
    }
}

class id4 {
    int R, C;
    int[][] E;

    public id4(int r, int c) {
        R = r;
        C = c;
        E = new int[R + 2][C + 2];
    }

    void setRC(int r, int c, int w) {
        E[r][c] = w;
    }

    int getRC(int r, int c) {
        return E[r][c];
    }

    int bfsAll() {
        int ret = 0;
        boolean[][] visited = new boolean[R + 2][C + 2];
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                if (E[r][c] != 0 && !visited[r][c]) {
                    ret++;
                    bfs(r, c, visited);
                }
            }
        }
        return ret;
    }

    int bfsAll(List<Pair> Q) {
        int ret = 0;
        boolean[][] visited = new boolean[R + 2][C + 2];
        for (Pair pair : Q) {
            int r = pair.node;
            int c = pair.weight;
            if (!visited[r][c]) {
                ret++;
                bfs(r, c, visited);
            }
        }
        return ret;
    }

    void bfs(int rr, int cc, boolean[][] visited) {
        Queue<Pair> Q = new LinkedList<>();
        Q.add(new Pair(rr, cc));
        visited[rr][cc] = true;
        while (!Q.isEmpty()) {
            int r = Q.peek().node;
            int c = Q.peek().weight;
            Q.poll();
            for (int i = 0; i < 4; i++) {
                int r2 = r + dr[i];
                int c2 = c + dc[i];
                if (E[r2][c2] != 0 && !visited[r2][c2]) {
                    Q.add(new Pair(r2, c2));
                    visited[r2][c2] = true;
                }
            }
        }
    }

    void g() {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        id4 bm = new id4(R, C);
        List<Pair>[] Q = new ArrayList[2];
        Q[0] = new ArrayList<>();
        Q[1] = new ArrayList<>();
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                int a = scanner.nextInt();
                bm.setRC(r, c, a);
                if (a != 0) Q[0].add(new Pair(r, c));
            }
        }
        int ans = 0;
        int idx = 0;
        while (true) {
            int a = bm.bfsAll(Q[idx]);
            if (a > 1) break;
            else if (a == 0) {
                ans = 0;
                break;
            }
            ans++;
            List<Integer> X = new ArrayList<>();
            Q[1 - idx].clear();
            for (Pair pair : Q[idx]) {
                int r = pair.node;
                int c = pair.weight;
                a = 0;
                for (int j = 0; j < 4; j++) {
                    int r2 = r + dr[j];
                    int c2 = c + dc[j];
                    if (bm.getRC(r2, c2) == 0) a++;
                }
                X.add(a);
            }
            for (int i = 0; i < Q[idx].size(); i++) {
                int r = Q[idx].get(i).node;
                int c = Q[idx].get(i).weight;
                a = bm.getRC(r, c) - X.get(i);
                if (a <= 0) {
                    a = 0;
                } else {
                    Q[1 - idx].add(new Pair(r, c));
                }
                bm.setRC(r, c, a);
            }
            idx = 1 - idx;
        }
        System.out.println(ans);
    }
}

class Number {
    public Number() {}

    int getDigitNum(long xx) {
        long x;
        int ret = 0;
        for (x = 1; x < xx; x *= 10, ret++);
        return ret;
    }

    int getDigitSum(int xx) {
        int x, a = 0;
        for (x = xx; x != 0; x /= 10) a += (x % 10);
        return a;
    }

    int getMSB(long xx) {
        int i;
        for (i = 0; (1L << i) <= xx; i++);
        return i - 1;
    }

    long convertBinaryToBase(long x, int base) {
        if (x == 0) return 0;
        return base * convertBinaryToBase(x / 2, base) + (x % 2);
    }

    long findFactor(long k) {
        for (long d = 2; d * d <= k; d++) if (k % d == 0) return d;
        return 0;
    }
}

class Palindrome {
    public Palindrome() {}

    int isPalindrome(long xx) {
        long x;
        int i, n;
        List<Integer> v = new ArrayList<>();
        for (x = xx; x > 0; x /= 10) {
            v.add((int) (x % 10));
        }
        n = v.size();
        for (i = 0; i < n / 2; i++) {
            if (v.get(i) != v.get(n - i - 1)) return 0;
        }
        return 1;
    }
}

class BigNumber {
    public BigNumber() {}

    String add(String s1, String s2) {
        int i, j, n1, n2, a;
        StringBuilder s3 = new StringBuilder();
        List<Integer> v = new ArrayList<>();
        n1 = s1.length();
        n2 = s2.length();
        for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
            a = s1.charAt(i) - '0' + s2.charAt(j) - '0';
            v.add(a);
        }
        while (i >= 0) {
            a = s1.charAt(i) - '0';
            v.add(a);
            i--;
        }
        while (j >= 0) {
            a = s2.charAt(j) - '0';
            v.add(a);
            j--;
        }
        for (i = 0, a = 0; i < v.size(); i++) {
            a += v.get(i);
            if (a >= 10) {
                v.set(i, a - 10);
                a = 1;
            } else {
                v.set(i, a);
                a = 0;
            }
        }
        if (a != 0) v.add(a);
        for (i = v.size() - 1; i >= 0; i--) s3.append((char) (v.get(i) + '0'));
        s3.append('\n');
        return s3.toString();
    }
}

class PrimeNumber {
    int N;
    List<Integer> NP, P;

    public PrimeNumber() {}

    public PrimeNumber(int n) {
        N = n;
        NP = new ArrayList<>(Collections.nCopies(N + 4, 0));
        P = new ArrayList<>();
        for (int i = 2; i * i <= N; i++) {
            if (NP.get(i) != 0) continue;
            for (int j = i * i; j <= N; j += i) NP.set(j, 1);
        }
        for (int i = 2; i <= N; i++) if (NP.get(i) == 0) P.add(i);
    }

    long gcd(long x, long y) {
        long z;
        while (x != 0) {
            z = y % x;
            y = x;
            x = z;
        }
        return y;
    }

    long powermod(long p, long q) {
        long g = gcd(p, q);
        p /= g;
        q /= g;
        return p * powmod(q, MOD - 2) % MOD;
    }

    List<Integer> factorization(int x) {
        List<Integer> ret = new ArrayList<>();
        if (x == 1) {
            ret.add(1);
            return ret;
        }
        ret.add(1);
        ret.add(x);
        for (int i = 2; i * i < x; i++) {
            if (x % i == 0) {
                ret.add(i);
                ret.add(x / i);
            }
        }
        if (i * i == x) ret.add(i);
        return ret;
    }

    int factorization2(int x) {
        int ret = 0;
        if (x == 1) {
