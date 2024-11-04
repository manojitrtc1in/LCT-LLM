import java.io.*;
import java.util.*;

public class 8af7e12ef0403b227ac91ce5c7626ca1xcodeeval_processed_4000.json {
    static final int id11 = 1000000007;
    static final int F = 10001;
    static final int N = 1000010;
    static long maxh;
    static int[] vid = new int[N];
    static int[] pr = new int[N];
    static int[] dc = new int[N];
    static int[][] dist = new int[301][F];
    static boolean[] vis = new boolean[F];
    static List<Integer>[] vec = new ArrayList[N];
    static List<Integer> primes = new ArrayList<>();
    static Map<Long, Integer> used = new HashMap<>();
    static List<List<Integer>> w = new ArrayList<>();
    static List<Integer>[] g = new ArrayList[F];

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
            assert w.size() == sz;
            w.add(t);
            dc[sz] = calcd(t);
        }
        v.add(used.get(x));
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
                w.add(vec[i]);
                used.put(h, id);
            }
            vid[i] = id;
        }

        int ws = w.size();
        for (int i = 0; i < Math.min(ws, 7000); i++) {
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
            Arrays.fill(dp, Integer.MAX_VALUE);
            dp[i] = 0;
            for (int j = 0; j < q.size(); j++) {
                int cur = q.get(j);
                int dcur = dp[cur];
                for (int to : g[cur]) {
                    if (dp[to] == Integer.MAX_VALUE) {
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
            int ans = Integer.MAX_VALUE;
            for (int i = 1; i < 3000; i++) {
                ans = Math.min(ans, dist[a][i] + dist[b][i]);
            }
            out.println(ans);
        }
    }

    static void reunique(List<Integer> v) {
        Set<Integer> set = new HashSet<>(v);
        v.clear();
        v.addAll(set);
        Collections.sort(v);
    }
}
