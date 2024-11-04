import java.io.*;
import java.util.*;

public class 0c3382fe2106454bce7b28b227a08053_nc {
    static final int MAXN = 3005;
    static int T, N, M;
    static long[] B = new long[MAXN], W = new long[MAXN];
    static Pair[][] dp = new Pair[MAXN][MAXN];
    static Pair[] merged = new Pair[MAXN];
    static List<Integer>[] adj = new ArrayList[MAXN];

    static class Pair {
        long first, second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static int dfs(int v, int prev) {
        int SZV = 1;
        dp[v][0] = new Pair(0, W[v] - B[v]);
        for (int w : adj[v]) {
            if (w != prev) {
                int SZW = dfs(w, v);
                for (int i = SZW; i >= 1; i--) {
                    dp[w][i] = max(dp[w][i], new Pair(dp[w][i - 1].first + (dp[w][i - 1].second > 0 ? 1 : 0), 0));
                }
                Arrays.fill(merged, 0, SZV + SZW, new Pair(Long.MIN_VALUE, Long.MIN_VALUE));
                for (int i = 0; i < SZV; i++) {
                    for (int j = 0; j <= SZW; j++) {
                        merged[i + j] = max(merged[i + j], new Pair(dp[v][i].first + dp[w][j].first, dp[v][i].second + dp[w][j].second));
                    }
                }
                System.arraycopy(merged, 0, dp[v], 0, SZV + SZW);
                SZV += SZW;
            }
        }
        return SZV;
    }

    static Pair max(Pair a, Pair b) {
        return (a.first > b.first) ? a : b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        for (int ti = 0; ti < T; ti++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                B[i] = Long.parseLong(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                W[i] = Long.parseLong(st.nextToken());
            }
            for (int i = 0; i < N - 1; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken()) - 1;
                int b = Integer.parseInt(st.nextToken()) - 1;
                if (adj[a] == null) adj[a] = new ArrayList<>();
                if (adj[b] == null) adj[b] = new ArrayList<>();
                adj[a].add(b);
                adj[b].add(a);
            }
            for (int i = 0; i < N; i++) {
                Arrays.fill(dp[i], new Pair(Long.MIN_VALUE, Long.MIN_VALUE));
            }
            dfs(0, -1);
            System.out.println(dp[0][M - 1].first + (dp[0][M - 1].second > 0 ? 1 : 0));
            for (int i = 0; i < N; i++) {
                adj[i] = null;
            }
        }
    }
}
