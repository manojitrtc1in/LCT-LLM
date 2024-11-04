import java.io.*;
import java.util.*;

class Main {
    static final int INF = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int ws = 1;
        List<List<Integer>> w = new ArrayList<>();
        w.add(new ArrayList<>());
        Map<Long, Integer> used = new HashMap<>();
        used.put(0L, 0);
        int[] dc = new int[1001];
        List<Integer>[] g = new List[1001];
        for (int i = 0; i < 1001; i++) {
            g[i] = new ArrayList<>();
        }

        int maxh = 0;
        int[] vec = new int[1000010];
        int[] vid = new int[1000010];
        int[] pr = new int[1000010];
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i < 1000010; i++) {
            if (pr[i] == 0) {
                pr[i] = i;
                primes.add(i);
            }
            for (int p : primes) {
                if (p * i >= 1000010 || p > pr[i]) {
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
            for (int t : vec) {
                vec[i] = t;
            }
            vec[i] = cnt;
            long h = calc(vec);
            maxh = Math.max(maxh, h);
            int id = used.getOrDefault(h, 0);
            if (id == 0) {
                id = w.size();
                w.add(new ArrayList<>(Arrays.asList(vec)));
                used.put(h, id);
            }
            vid[i] = id;
        }

        for (int i = 0; i < Math.min(w.size(), 1001); i++) {
            List<Integer> cur = w.get(i);
            for (int j = 0; j < cur.size(); j++) {
                List<Integer> t = new ArrayList<>(cur);
                t.set(j, t.get(j) - 1);
                addUsed(g[i], t, used, w);
                t.set(j, t.get(j) + 2);
                addUsed(g[i], t, used, w);
            }
            cur.add(1);
            addUsed(g[i], cur, used, w);
            Collections.sort(g[i]);
            g[i] = reunique(g[i]);
            dc[i] = calcd(w.get(i));
        }

        int[][] dist = new int[1001][2002];
        boolean[] vis = new boolean[2002];
        for (int i = 0; i < 1001; i++) {
            Arrays.fill(dist[i], INF);
        }

        for (int i = 0; i < ws; i++) {
            Arrays.fill(vis, false);
            List<Integer> q = new ArrayList<>();
            q.add(i);
            int[] dp = new int[2002];
            Arrays.fill(dp, INF);
            dp[i] = 0;
            for (int j = 0; j < q.size(); j++) {
                int cur = q.get(j);
                int dcur = dp[cur];
                for (int to : g[cur]) {
                    if (dp[to] == INF) {
                        dp[to] = dcur + 1;
                        q.add(to);
                    }
                }
            }
            for (int j = 0; j < used.size(); j++) {
                if (dc[j] < 1001) {
                    dist[i][dc[j]] = Math.min(dist[i][dc[j]], dp[j]);
                }
            }
        }

        int[][] ans = new int[1003][1003];
        for (int i = 0; i < ws; i++) {
            dist[i][0] = INF;
            for (int j = i + 1; j < ws; j++) {
                int res = INF;
                for (int k = 0; k < 1001; k++) {
                    res = Math.min(res, dist[i][k] + dist[j][k]);
                }
                ans[i][j] = res;
            }
        }

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String[] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);
            a = vid[a];
            b = vid[b];
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            pw.println(ans[a][b]);
        }

        pw.flush();
        pw.close();
        br.close();
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

    static List<Integer> reunique(List<Integer> list) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if (i == 0 || !list.get(i).equals(list.get(i - 1))) {
                result.add(list.get(i));
            }
        }
        return result;
    }
}
