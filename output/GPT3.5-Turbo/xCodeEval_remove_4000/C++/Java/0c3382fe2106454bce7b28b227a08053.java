import java.io.*;
import java.util.*;

class Main {
    static final int MAXN = 3005;

    static int T, N, M;
    static int[] B = new int[MAXN];
    static int[] W = new int[MAXN];
    static Pair<Integer, Long>[][] dp = new Pair[MAXN][MAXN];
    static List<Integer>[] adj = new ArrayList[MAXN];

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static void MAX(Pair<Integer, Long> a, Pair<Integer, Long> b) {
        if (b.first > a.first || (b.first == a.first && b.second > a.second)) {
            a.first = b.first;
            a.second = b.second;
        }
    }

    static int dfs(int v, int prev) {
        int SZV = 1;
        dp[v][0] = new Pair<>(0, (long) W[v] - B[v]);
        for (int w : adj[v]) {
            if (w != prev) {
                int SZW = dfs(w, v);
                for (int i = SZW; i >= 1; i--) {
                    MAX(dp[w][i], new Pair<>(dp[w][i - 1].first + (dp[w][i - 1].second > 0 ? 1 : 0), 0L));
                }
                Pair<Integer, Long>[] merged = new Pair[SZV + SZW];
                Arrays.fill(merged, new Pair<>(-Integer.MAX_VALUE, -Long.MAX_VALUE));
                for (int i = 0; i < SZV; i++) {
                    for (int j = 0; j <= SZW; j++) {
                        MAX(merged[i + j], new Pair<>(dp[v][i].first + dp[w][j].first, dp[v][i].second + dp[w][j].second));
                    }
                }
                System.arraycopy(merged, 0, dp[v], 0, SZV + SZW);
                SZV += SZW;
            }
        }
        return SZV;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        T = Integer.parseInt(br.readLine());
        for (int ti = 0; ti < T; ti++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                B[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                W[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 0; i < N; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < N - 1; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken()) - 1;
                int b = Integer.parseInt(st.nextToken()) - 1;
                adj[a].add(b);
                adj[b].add(a);
            }
            for (int i = 0; i < N; i++) {
                Arrays.fill(dp[i], new Pair<>(-Integer.MAX_VALUE, -Long.MAX_VALUE));
            }
            dfs(0, -1);
            pw.println(dp[0][M - 1].first + (dp[0][M - 1].second > 0 ? 1 : 0));
            for (int i = 0; i < N; i++) {
                adj[i].clear();
            }
        }

        pw.close();
    }
}
