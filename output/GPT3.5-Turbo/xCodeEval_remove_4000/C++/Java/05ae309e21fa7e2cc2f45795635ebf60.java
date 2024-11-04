import java.util.*;

class Main {
    static int N;
    static int[] A;
    static int[] B;
    static int[] C;
    static wgraph<Integer> g;
    static int[] arr;
    static int as;
    static int r;
    static int[] ok;
    static int[] dp;
    static int[] back;
    static int cnt;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        A = new int[N-1];
        B = new int[N-1];
        C = new int[N-1];
        for (int i = 0; i < N-1; i++) {
            A[i] = sc.nextInt() - 1;
            B[i] = sc.nextInt() - 1;
        }
        g = new wgraph<>();
        g.setEdge(N, N-1, A, B, C);
        for (r = 0; r < N; r++) {
            as = 0;
            for (int i = 0; i < g.es[r]; i++) {
                arr[as++] = dfs2(g.edge[r][i], r);
            }
            dp = new int[N+1];
            back = new int[N+1];
            dp[0] = 1;
            for (int i = 0; i < as; i++) {
                for (int j = N; j >= arr[i]; j--) {
                    if (dp[j] == 0 && dp[j-arr[i]] == 1) {
                        dp[j] = 1;
                        back[j] = i;
                    }
                }
            }
            int p;
            for (p = 0; p < N+1; p++) {
                if (dp[p] == 1 && (p+1) * (N-p) - 1 >= 2*N*N/9) {
                    break;
                }
            }
            if (p == N+1) {
                continue;
            }
            int k = p;
            while (k != 0) {
                ok[back[k]] = 1;
                k -= arr[back[k]];
            }
            cnt = 0;
            dfs(r, -1, 0, 1, 0);
            cnt = 0;
            dfs(r, -1, 0, p+1, 1);
            break;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < g.es[i]; j++) {
                int k = g.edge[i][j];
                int res = g.cost[i][j];
                if (res > 0) {
                    System.out.println((i+1) + " " + (k+1) + " " + res);
                }
            }
        }
    }

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

    static class wgraph<T> {
        T[][] cost;
        graph g;
        int N;
        int[][] edge;
        int[] es;

        void setEdge(int N__, int M, int[] A, int[] B, T[] C) {
            N = N__;
            es = new int[N];
            for (int i = 0; i < N; i++) {
                es[i] = 0;
            }
            edge = new int[N][];
            cost = (T[][]) new Object[N][];
            for (int i = 0; i < N; i++) {
                edge[i] = new int[es[i]];
                cost[i] = (T[]) new Object[es[i]];
            }
            for (int i = 0; i < M; i++) {
                es[A[i]]++;
                es[B[i]]++;
            }
            for (int i = 0; i < N; i++) {
                edge[i] = new int[es[i]];
                cost[i] = (T[]) new Object[es[i]];
            }
            for (int i = 0; i < N; i++) {
                es[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                edge[A[i]][es[A[i]]] = B[i];
                edge[B[i]][es[B[i]]] = A[i];
                cost[A[i]][es[A[i]]++] = C[i];
                cost[B[i]][es[B[i]]++] = C[i];
            }
            g = new graph();
            g.N = N;
            g.es = es;
            g.edge = edge;
        }

        class graph {
            int N;
            int[][] edge;
            int[] es;
        }
    }
}
