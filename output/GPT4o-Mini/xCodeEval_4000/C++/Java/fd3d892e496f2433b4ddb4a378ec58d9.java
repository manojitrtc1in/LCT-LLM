import java.io.*;
import java.util.*;

public class fd3d892e496f2433b4ddb4a378ec58d9_nc {
    static final int F = 5001;
    static final int N = 1000010;
    static final int INF = 1011111111;
    static long maxh;
    static int[][] dist = new int[301][F * 2];
    static boolean[] vis = new boolean[F * 2];
    static int[] dc = new int[F * 2];
    static ArrayList<Integer>[] g = new ArrayList[F * 2];
    static ArrayList<int[]> w = new ArrayList<>();
    static int[] vid = new int[1010101];
    static int[] pr = new int[1010101];
    static ArrayList<Integer> primes = new ArrayList<>();
    static Map<Long, Integer> used = new HashMap<>();
    static int[][] ans = new int[303][303];
    static ArrayList<Integer>[] vec = new ArrayList[1010101];

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

    static void solve(BufferedReader br, PrintWriter out) throws IOException {
        w.add(new int[0]);
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
            vec[i].ensureCapacity(vec[x].size() + 1);
            for (int t : vec[x]) vec[i].add(t);
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
        for (int i = 0; i < Math.min(w.size(), F); i++) {
            ArrayList<Integer> cur = new ArrayList<>(Arrays.asList(w.get(i)));
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
            vis = new boolean[F * 2];
            ArrayList<Integer> q = new ArrayList<>();
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

    static void reunique(ArrayList<Integer> v) {
        HashSet<Integer> set = new HashSet<>(v);
        v.clear();
        v.addAll(set);
        Collections.sort(v);
    }
}
