import java.util.*;
import java.io.*;

public class 9c5901eae3b739bcb095f3a3a6d4b8b0xcodeeval_processed_4000.json {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = 998244353;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);
    static final int N = 300 * 1000 + 13;

    static int n;
    static List<Integer>[] g = new ArrayList[N];
    static int[][] dp = new int[N][3];

    static {
        for (int i = 0; i < N; i++) {
            g[i] = new ArrayList<>();
        }
    }

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            for (int i = 0; i < n; i++) {
                g[i].clear();
            }
            for (int i = 0; i < n - 1; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int v = Integer.parseInt(st.nextToken()) - 1;
                int u = Integer.parseInt(st.nextToken()) - 1;
                g[v].add(u);
                g[u].add(v);
            }
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        if (a < 0) a += MOD;
        return a;
    }

    static int mul(int a, int b) {
        return (int) ((1L * a * b) % MOD);
    }

    static void dfs(int v, int p) {
        dp[v][0] = 1;
        dp[v][1] = 1;
        List<Integer> vals = new ArrayList<>();
        List<Integer> init = new ArrayList<>();
        for (int u : g[v]) {
            if (u != p) {
                dfs(u, v);
                vals.add(add(dp[u][1], add(dp[u][2], dp[u][2])));
                init.add(add(dp[u][0], dp[u][1]));
                dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])));
                dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]));
            }
        }
        dp[v][0] = add(dp[v][0], -dp[v][1]);

        List<Integer> pr = new ArrayList<>(Collections.singletonList(1));
        List<Integer> su = new ArrayList<>(Collections.singletonList(1));
        for (int it : vals) {
            pr.add(mul(pr.get(pr.size() - 1), it));
        }
        Collections.reverse(vals);
        for (int it : vals) {
            su.add(mul(su.get(su.size() - 1), it));
        }
        Collections.reverse(vals);
        Collections.reverse(su);

        dp[v][2] = 0;
        for (int i = 0; i < vals.size(); i++) {
            dp[v][2] = add(dp[v][2], mul(init.get(i), mul(pr.get(i), su.get(i + 1))));
        }
    }

    static void solve() {
        dfs(0, -1);
        System.out.println(add(dp[0][1], dp[0][2]));
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
            System.setOut(out);
            long tt = System.currentTimeMillis();

            while (read()) {
                solve();
                System.err.println("TIME = " + (System.currentTimeMillis() - tt));
                tt = System.currentTimeMillis();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
