import java.io.*;
import java.util.*;

public class 8af7e12ef0403b227ac91ce5c7626ca1_nc {
    static final int USUAL_MOD = 1000000007;
    static final int F = 10001;
    static final int INF = 1011111111;
    static final int N = 1000010;
    static long maxh;
    static int[] pr = new int[N];
    static int[] vid = new int[N];
    static int[] dc = new int[F];
    static int[][] dist = new int[301][F];
    static boolean[] vis = new boolean[F];
    static List<Integer>[] g = new ArrayList[F];
    static List<List<Integer>> w = new ArrayList<>();
    static Map<Long, Integer> used = new HashMap<>();
    static List<Integer> primes = new ArrayList<>();
    static List<List<Integer>> vec = new ArrayList<>(N);

    static {
        for (int i = 0; i < N; i++) {
            vec.add(new ArrayList<>());
            g[i] = new ArrayList<>();
        }
    }

    static long calc(List<Integer> v) {
        Collections.sort(v);
        long res = 0;
        for (int x : v) {
            res = res * 30 + x;
        }
        return res;
    }

    static int calcd(List<Integer> v) {
        int res = 1;
        for (int x : v) {
            res *= x + 1;
        }
        return res;
    }

    static void addUsed(List<Integer> v, List<Integer> t) {
        long x = calc(t);
        if (!used.containsKey(x)) {
            int sz = used.size();
            used.put(x, sz);
            w.add(t);
            dc[sz] = calcd(t);
        }
        v.add(used.get(x));
    }

    static int solve() {
        w.add(new ArrayList<>());
        used.put(0L, 0);
        for (int i = 2; i < N; ++i) {
            if (pr[i] == 0) {
                pr[i] = i;
                primes.add(i);
            }
            for (int p : primes) {
                if (p * i > N || p > pr[i]) {
                    break;
                }
                pr[p * i] = p;
            }
            int cnt = 1;
            int x = i;
            while (pr[x] == pr[x / pr[x]]) {
                cnt++;
                x /= pr[x];
            }
            x /= pr[x];
            vec.get(i).addAll(vec.get(x));
            vec.get(i).add(cnt);
            long h = calc(vec.get(i));
            maxh = Math.max(maxh, h);
            int id = used.getOrDefault(h, -1);
            if (id == -1) {
                id = w.size();
                w.add(vec.get(i));
            }
            vid[i] = id;
        }

        int ws = w.size();
        for (int i = 0; i < Math.min(ws, 7000); ++i) {
            List<Integer> cur = w.get(i);
            for (int j = 0; j < cur.size(); ++j) {
                List<Integer> t = new ArrayList<>(cur);
                t.set(j, t.get(j) - 1);
                addUsed(g[i], t);
                t.set(j, t.get(j) + 2);
                addUsed(g[i], t);
            }
            cur.add(1);
            addUsed(g[i], cur);
            Collections.sort(g[i]);
            reunique(g[i]);
            dc[i] = calcd(w.get(i));
        }

        for (int i = 0; i < ws; ++i) {
            Arrays.fill(vis, false);
            List<Integer> q = new ArrayList<>();
            q.add(i);
            int[] dp = new int[used.size()];
            Arrays.fill(dp, INF);
            dp[i] = 0;
            for (int j = 0; j < q.size(); ++j) {
                int cur = q.get(j);
                int dcur = dp[cur];
                for (int to : g[cur]) {
                    if (dp[to] == INF) {
                        dp[to] = dcur + 1;
                        q.add(to);
                    }
                }
            }
            for (int j = 0; j < used.size(); ++j) {
                if (dc[j] < F) {
                    dist[i][dc[j]] = Math.min(dist[i][dc[j]], dp[j]);
                }
            }
        }

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        while (n-- > 0) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            a = vid[a];
            b = vid[b];
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            int ans = INF;
            for (int i = 1; i < 3000; ++i) {
                ans = Math.min(ans, dist[a][i] + dist[b][i]);
            }
            System.out.println(ans);
        }
        return 0;
    }

    public static void main(String[] args) {
        solve();
    }

    static void reunique(List<Integer> v) {
        Set<Integer> set = new LinkedHashSet<>(v);
        v.clear();
        v.addAll(set);
    }
}
