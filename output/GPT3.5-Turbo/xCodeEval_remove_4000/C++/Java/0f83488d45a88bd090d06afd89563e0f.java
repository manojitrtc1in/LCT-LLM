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
        Map<Integer, Integer> used = new HashMap<>();
        used.put(0, 0);

        List<Integer>[] g = new List[ws];
        for (int i = 0; i < ws; i++) {
            g[i] = new ArrayList<>();
        }

        int[][] dist = new int[ws][F * 2];
        boolean[] vis = new boolean[F * 2];
        int[] dc = new int[F * 2];

        for (int i = 0; i < ws; i++) {
            Arrays.fill(dist[i], INF);
        }

        for (int i = 0; i < Math.min(w.size(), F); i++) {
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

        for (int i = 0; i < ws; i++) {
            Arrays.fill(vis, false);
            List<Integer> q = new ArrayList<>();
            q.add(i);
            int[] dp = new int[F * 2];
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
                if (dc[j] < F) {
                    dist[i][dc[j]] = Math.min(dist[i][dc[j]], dp[j]);
                }
            }
        }

        for (int i = 0; i < ws; i++) {
            dist[i][0] = INF;
            for (int j = i + 1; j < ws; j++) {
                int res = INF;
                for (int k = 0; k < F; k++) {
                    res = Math.min(res, dist[i][k] + dist[j][k]);
                }
                ans[i][j] = res;
            }
        }

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            int a = Integer.parseInt(br.readLine());
            int b = Integer.parseInt(br.readLine());
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
    }

    static void addUsed(List<Integer> v, List<Integer> t, Map<Integer, Integer> used, List<List<Integer>> w) {
        int x = calc(t);
        if (!used.containsKey(x)) {
            int sz = used.size();
            used.put(x, sz);
            w.add(t);
            dc[sz] = calcd(t);
        }
        v.add(used.get(x));
    }

    static int calc(List<Integer> v) {
        Collections.sort(v);
        int res = 0;
        for (int x : v) {
            res = res * 24 + x;
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

    static List<Integer> reunique(List<Integer> list) {
        List<Integer> uniqueList = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if (i == 0 || !list.get(i).equals(list.get(i - 1))) {
                uniqueList.add(list.get(i));
            }
        }
        return uniqueList;
    }
}
