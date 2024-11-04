import java.io.*;
import java.util.*;

class Main {
    static final int INF = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int ws = 1;
        Map<Long, Integer> used = new HashMap<>();
        List<List<Integer>> w = new ArrayList<>();
        w.add(new ArrayList<>());
        used.put(0L, 0);
        int[] pr = new int[1000010];
        List<Integer> primes = new ArrayList<>();
        List<Integer>[] vec = new List[1000010];
        for (int i = 0; i < 1000010; i++) {
            vec[i] = new ArrayList<>();
        }
        int maxh = 0;
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
            vec[i].addAll(vec[x]);
            vec[i].add(cnt);
            long h = calc(vec[i]);
            maxh = Math.max(maxh, (int) h);
            int id = used.getOrDefault(h, 0);
            if (id == 0) {
                id = ws++;
                used.put(h, id);
                w.add(vec[i]);
            }
            vid[i] = id;
        }

        List<Integer>[] g = new List[ws];
        for (int i = 0; i < ws; i++) {
            g[i] = new ArrayList<>();
        }
        int[] dc = new int[ws];
        for (int i = 0; i < Math.min(w.size(), 3001); i++) {
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

        int[][] dist = new int[301][3001 * 2];
        boolean[] vis = new boolean[3001 * 2];
        for (int i = 0; i < ws; i++) {
            Arrays.fill(vis, false);
            List<Integer> q = new ArrayList<>();
            q.add(i);
            int[] dp = new int[3001 * 2];
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
                if (dc[j] < 3001) {
                    dist[i][dc[j]] = Math.min(dist[i][dc[j]], dp[j]);
                }
            }
        }

        for (int i = 0; i < ws; i++) {
            dist[i][0] = INF;
            for (int j = i + 1; j < ws; j++) {
                int res = INF;
                for (int k = 0; k < 3001; k++) {
                    res = Math.min(res, dist[i][k] + dist[j][k]);
                }
                ans[i][j] = res;
            }
        }

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
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

    static int[][] ans = new int[303][303];
    static int[] vid = new int[1000010];

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
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if (i == 0 || !list.get(i).equals(list.get(i - 1))) {
                res.add(list.get(i));
            }
        }
        return res;
    }
}
