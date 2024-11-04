import java.util.*;

public class 05ae309e21fa7e2cc2f45795635ebf60xcodeeval_processed_4000.json {
    static Object wmem;
    static int N;
    static int[] A = new int[1000];
    static int[] B = new int[1000];
    static int[] C = new int[1000];
    static WGraph<Integer> g = new WGraph<>();
    static int[] arr = new int[1001];
    static int as;
    static int r;
    static int[] ok = new int[1001];
    static int[] dp = new int[1001];
    static int[] back = new int[1001];

    static int dfs2(int n, int b) {
        int res = 1;
        for (int i = 0; i < g.es[n]; i++) {
            int k = g.edge[n][i];
            if (k == b) {
                continue;
            }
            res += dfs2(k, n);
        }
        return res;
    }

    static int cnt;

    static void dfs(int n, int b, int d, int m, int dm) {
        for (int i = 0; i < g.es[n]; i++) {
            if (n == r && ok[i] == dm) {
                continue;
            }
            int k = g.edge[n][i];
            if (k == b) {
                continue;
            }
            cnt++;
            g.cost[n][i] = m * (cnt - d);
            dfs(k, n, cnt, m, dm);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        wmem = new Object[96000000];
        N = scanner.nextInt();
        for (int id0 = 0; id0 < N - 1; id0++) {
            A[id0] = scanner.nextInt() - 1;
            B[id0] = scanner.nextInt() - 1;
        }
        g.setEdge(N, N - 1, A, B, C);
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
            int k = p;
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
}

class WGraph<T> {
    T[][] cost;
    Graph g = new Graph();
    int N;
    int[][] edge;
    int[] es;

    void setEdge(int N__, int M, int[] A, int[] B, T[] C) {
        N = N__;
        es = new int[N];
        Arrays.fill(es, 0);
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
            es[B[i]]++;
        }
        edge = new int[N][];
        for (int i = 0; i < N; i++) {
            edge[i] = new int[es[i]];
        }
        cost = (T[][]) new Object[N][];
        for (int i = 0; i < N; i++) {
            cost[i] = (T[]) new Object[es[i]];
        }
        Arrays.fill(es, 0);
        for (int i = 0; i < M; i++) {
            edge[A[i]][es[A[i]]++] = B[i];
            edge[B[i]][es[B[i]]++] = A[i];
            cost[A[i]][es[A[i]] - 1] = C[i];
            cost[B[i]][es[B[i]] - 1] = C[i];
        }
        g.N = N;
        g.es = es;
        g.edge = edge;
    }
}

class Graph {
    int N;
    int[][] edge;
    int[] es;

    // Additional methods and properties for Graph can be added here
}
