import java.util.*;
import java.io.*;

public class 8af7e12ef0403b227ac91ce5c7626ca1xcodeeval_processed_4000.json {
    static final int INF = (int) 1e9;
    static final int F = 10001;
    static int[][] dist = new int[301][F];
    static boolean[] vis = new boolean[F];
    static int[] dc = new int[F];
    static List<Integer>[] g = new List[F];
    static List<List<Integer>> w = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        w.add(new ArrayList<>());
        Map<Long, Integer> used = new HashMap<>();
        used.put(0L, 0);
        int maxh = 0;

        List<Integer>[] vec = new List[1010101];
        int[] vid = new int[1010101];
        int[] pr = new int[1010101];
        List<Integer> primes = new ArrayList<>();

        for (int i = 2; i < 1010101; ++i) {
            if (pr[i] == 0) {
                pr[i] = i;
                primes.add(i);
            }
            for (int p : primes) {
                if (p * i >= 1010101 || p > pr[i]) {
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
            vec[i] = new ArrayList<>();
            vec[i].addAll(vec[x]);
            vec[i].add(cnt);
            long h = calc(vec[i]);
            maxh = Math.max(maxh, (int) h);
            int id = used.getOrDefault(h, 0);
            if (id == 0) {
                id = w.size();
                w.add(vec[i]);
                used.put(h, id);
            }
            vid[i] = id;
        }

        int ws = w.size();
        for (int i = 0; i < Math.min(w.size(), 7000); ++i) {
            List<Integer> cur = w.get(i);
            for (int j = 0; j < cur.size(); ++j) {
                List<Integer> t = new ArrayList<>(cur);
                t.set(j, t.get(j) - 1);
                addUsed(g[i], t, used, w);
                t.set(j, t.get(j) + 2);
                addUsed(g[i], t, used, w);
            }
            cur.add(1);
            addUsed(g[i], cur, used, w);
            Collections.sort(g[i]);
            reunique(g[i]);
            dc[i] = calcd(w.get(i));
        }

        for (int i = 0; i < ws; ++i) {
            Arrays.fill(vis, false);
            List<Integer> q = new ArrayList<>();
            q.add(i);
            int[] dp = new int[F];
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

        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
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
            sb.append(ans).append("\n");
        }
        System.out.print(sb);
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

    static void addUsed(List<Integer> v, List<Integer> t, Map<Long, Integer> used, List<List<Integer>> w) {
        long x = calc(t);
        if (!used.containsKey(x)) {
            int sz = used.size();
            used.put(x, sz);
            assert w.size() == sz;
            w.add(t);
            dc[sz] = calcd(t);
        }
        v.add(used.get(x));
    }

    static void reunique(List<Integer> v) {
        int j = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (i == 0 || !v.get(i).equals(v.get(i - 1))) {
                v.set(j++, v.get(i));
            }
        }
        while (v.size() > j) {
            v.remove(v.size() - 1);
        }
    }
}
