import java.io.*;
import java.util.*;

public class 83f1bfa80af301dd1bb9ff9d2df8a104_nc {
    static final int USUAL_MOD = 1000000007;
    static final int F = 3001;
    static final int N = 1000010;
    static final int INF = 1011111111;

    static ArrayList<Integer>[] vec = new ArrayList[N];
    static int[] vid = new int[N];
    static int[] pr = new int[N];
    static ArrayList<Integer> primes = new ArrayList<>();
    static long maxh;
    static int[][] dist = new int[303][F * 2];
    static boolean[] vis = new boolean[F * 2];
    static int[] dc = new int[F * 2];
    static ArrayList<Integer>[] g = new ArrayList[F * 2];
    static ArrayList<ArrayList<Integer>> w = new ArrayList<>();
    static int[][] ans = new int[303][303];
    static Map<Long, Integer> used = new HashMap<>();

    static {
        for (int i = 0; i < N; i++) {
            vec[i] = new ArrayList<>();
            g[i] = new ArrayList<>();
        }
        w.add(new ArrayList<>());
        used.put(0L, 0);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

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
            long h = calc(vec[i]);

            maxh = Math.max(maxh, h);
            used.putIfAbsent(h, used.size());
            vid[i] = used.get(h);
            if (vid[i] == used.size() - 1) {
                w.add(vec[i]);
            }
        }

        int ws = w.size();
        for (int i = 0; i < Math.min(ws, F); i++) {
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
            reunique(g[i]);
            dc[i] = calcd(w.get(i));
        }

        for (int i = 0; i < ws; i++) {
            Arrays.fill(dist[i], INF);
            Arrays.fill(vis, false);
            Queue<Integer> q = new LinkedList<>();
            q.add(i);
            int[] dp = new int[used.size()];
            Arrays.fill(dp, INF);
            dp[i] = 0;

            while (!q.isEmpty()) {
                int cur = q.poll();
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
            System.out.println(ans[a][b]);
        }
    }

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
            w.add(t);
            dc[sz] = calcd(t);
        }
        v.add(used.get(x));
    }

    static void reunique(ArrayList<Integer> v) {
        Set<Integer> set = new HashSet<>(v);
        v.clear();
        v.addAll(set);
        Collections.sort(v);
    }
}
