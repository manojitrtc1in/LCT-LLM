import java.util.*;
import java.io.*;

public class fd3d892e496f2433b4ddb4a378ec58d9_nc {
    static final int F = 5001;
    static int[][] dist = new int[F * 2][F * 2];
    static boolean[] vis = new boolean[F * 2];
    static int[] dc = new int[F * 2];
    static ArrayList<Integer>[] g = new ArrayList[F * 2];
    static ArrayList<ArrayList<Integer>> w = new ArrayList<>();
    static int[][] ans = new int[303][303];
    static Map<Long, Integer> used = new HashMap<>();
    static long maxh;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        w.add(new ArrayList<>());
        used.put(0L, 0);
        int[] vid = new int[1010101];
        ArrayList<Integer>[] vec = new ArrayList[1010101];
        for (int i = 0; i < 1010101; i++) {
            vec[i] = new ArrayList<>();
        }
        int[] pr = new int[1010101];
        ArrayList<Integer> primes = new ArrayList<>();
        int N = 1000010;
        for (int i = 2; i < N; i++) {
            if (pr[i] == 0) {
                pr[i] = i;
                primes.add(i);
            }
            for (int p : primes) {
                if (p * i >= N || p > pr[i]) {
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
            maxh = Math.max(maxh, h);
            int id = used.getOrDefault(h, 0);
            if (id == 0) {
                id = w.size();
                w.add(vec[i]);
                used.put(h, id);
            }
            vid[i] = id;
        }

        int ws = w.size();
        for (int i = 0; i < Math.min(w.size(), F); i++) {
            ArrayList<Integer> cur = w.get(i);
            for (int j = 0; j < cur.size(); j++) {
                ArrayList<Integer> t = new ArrayList<>(cur);
                t.set(j, t.get(j) - 1);
                addUsed(g[i], t);
                t.set(j, t.get(j) + 2);
                addUsed(g[i], t);
            }
            cur.add(1);
            addUsed(g[i], cur);
            Collections.sort(g[i]);
            dc[i] = calcd(w.get(i));
        }

        for (int i = 0; i < ws; i++) {
            Arrays.fill(vis, false);
            ArrayList<Integer> q = new ArrayList<>();
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
            for (int j = 0; j < i + 1; j++) {
                int res = INF;
                for (int k = 0; k < F; k++) {
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

        pw.close();
    }

    static final int INF = 1011111111;

    static long calc(ArrayList<Integer> v) {
        Collections.sort(v);
        long res = 0;
        for (int x : v) {
            res = res * 30 + x;
        }
        return res;
    }

    static int calcd(ArrayList<Integer> v) {
        int res = 1;
        for (int x : v) {
            res *= x + 1;
        }
        return res;
    }

    static void addUsed(ArrayList<Integer> v, ArrayList<Integer> t) {
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
}
