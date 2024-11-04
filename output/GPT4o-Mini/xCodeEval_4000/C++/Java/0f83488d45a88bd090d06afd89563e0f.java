import java.io.*;
import java.util.*;

public class 0f83488d45a88bd090d06afd89563e0f_nc {
    static final int USUAL_MOD = 1000000007;
    static final int F = 1001;
    static final int N = 1000010;
    static final int INF = 1011111111;
    static final int[][] dist = new int[301][F * 2];
    static final boolean[] vis = new boolean[F * 2];
    static final int[] dc = new int[F * 2];
    static final List<List<Integer>> g = new ArrayList[F * 2];
    static final List<List<Integer>> w = new ArrayList<>();
    static final int[] pr = new int[N];
    static final int[] vid = new int[N];
    static final int[][] ans = new int[303][303];
    static final List<Integer> primes = new ArrayList<>();
    static final Map<Integer, Integer> used = new HashMap<>();
    static List<Integer>[] vec = new ArrayList[N];

    static {
        for (int i = 0; i < N; i++) {
            vec[i] = new ArrayList<>();
            g[i] = new ArrayList<>();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(br, out);
        out.close();
    }

    static void solve(BufferedReader br, PrintWriter out) throws IOException {
        w.add(new ArrayList<>());
        used.put(0, 0);
        
        for (int i = 2; i < N; i++) {
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
            vec[i].addAll(vec[x]);
            vec[i].add(cnt);
            int h = calc(vec[i]);
            used.putIfAbsent(h, w.size());
            if (!used.containsKey(h)) {
                used.put(h, w.size());
                w.add(new ArrayList<>(vec[i]));
            }
            vid[i] = used.get(h);
        }

        int ws = w.size();
        for (int i = 0; i < Math.min(ws, F); i++) {
            List<Integer> cur = w.get(i);
            for (int j = 0; j < cur.size(); j++) {
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

        for (int i = 0; i < ws; i++) {
            Arrays.fill(vis, false);
            List<Integer> q = new ArrayList<>();
            q.add(i);
            int[] dp = new int[used.size()];
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
            for (int j = 0; j <= i; j++) {
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
            out.println(ans[a][b]);
        }
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

    static void addUsed(List<Integer> v, List<Integer> t) {
        int x = calc(t);
        if (!used.containsKey(x)) {
            int sz = used.size();
            used.put(x, sz);
            w.add(t);
            dc[sz] = calcd(t);
        }
        v.add(used.get(x));
    }

    static void reunique(List<Integer> v) {
        Set<Integer> set = new HashSet<>(v);
        v.clear();
        v.addAll(set);
        Collections.sort(v);
    }
}
