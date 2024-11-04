import java.io.*;
import java.util.*;

public class f512d483d0ce56dde6a1f203b130fbaf_nc {
    static final int USUAL_MOD = 1000000007;
    static final int F = 1001;
    static final int N = 1000010;
    static final int INF = 1011111111;
    static long maxh;
    static int[][] dist = new int[301][F * 2];
    static boolean[] vis = new boolean[F * 2];
    static int[] dc = new int[F * 2];
    static List<Integer>[] g = new ArrayList[F * 2];
    static List<List<Integer>> w = new ArrayList<>();
    static int[] vid = new int[1010101];
    static int[] pr = new int[1010101];
    static List<Integer> primes = new ArrayList<>();
    static Map<Long, Integer> used = new HashMap<>();
    static int[][] ans = new int[303][303];
    static List<Integer>[] vec = new ArrayList[1010101];

    static {
        for (int i = 0; i < g.length; i++) {
            g[i] = new ArrayList<>();
            vec[i] = new ArrayList<>();
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
        used.put(0L, 0);
        
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
            int id = used.getOrDefault(h, -1);
            if (id == -1) {
                id = w.size();
                used.put(h, id);
                w.add(new ArrayList<>(vec[i]));
            }
            vid[i] = id;
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
            Arrays.fill(dist[i], INF);
            vis = new boolean[F * 2];
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

    static void reunique(List<Integer> v) {
        Set<Integer> set = new HashSet<>(v);
        v.clear();
        v.addAll(set);
    }
}
