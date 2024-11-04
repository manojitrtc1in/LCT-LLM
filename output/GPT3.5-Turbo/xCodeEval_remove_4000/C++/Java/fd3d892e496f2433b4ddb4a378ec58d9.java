import java.io.*;
import java.util.*;

class Main {
    static final int INF = (int) 1e9 + 7;
    static final int F = 5001;

    static int solve() throws IOException {
        List<List<Integer>> vec = new ArrayList<>();
        vec.add(new ArrayList<>());
        Map<Long, Integer> used = new HashMap<>();
        used.put(0L, 0);
        int[] vid = new int[1010101];
        List<Integer> primes = new ArrayList<>();
        int[] pr = new int[1010101];
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < F * 2; i++) {
            g.add(new ArrayList<>());
        }
        List<List<Integer>> w = new ArrayList<>();
        int[] dc = new int[F * 2];
        int[][] dist = new int[301][F * 2];
        boolean[] vis = new boolean[F * 2];
        int[][] ans = new int[303][303];
        long maxh = 0;

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
            vec.get(i).addAll(vec.get(x));
            vec.get(i).add(cnt);
            long h = calc(vec.get(i));
            maxh = Math.max(maxh, h);
            int id = used.getOrDefault(h, 0);
            if (id == 0) {
                id = w.size();
                w.add(vec.get(i));
                used.put(h, id);
            }
            vid[i] = id;
        }

        int ws = w.size();
        for (int i = 0; i < Math.min(w.size(), F); ++i) {
            List<Integer> cur = new ArrayList<>(w.get(i));
            for (int j = 0; j < cur.size(); ++j) {
                List<Integer> t = new ArrayList<>(cur);
                t.set(j, t.get(j) - 1);
                addUsed(g.get(i), t, used, w);
                t.set(j, t.get(j) + 2);
                addUsed(g.get(i), t, used, w);
            }
            cur.add(1);
            addUsed(g.get(i), cur, used, w);
            Collections.sort(g.get(i));
            reunique(g.get(i));
            dc[i] = calcd(w.get(i));
        }

        for (int i = 0; i < ws; ++i) {
            Arrays.fill(vis, false);
            List<Integer> q = new ArrayList<>();
            q.add(i);
            int[] dp = new int[F * 2];
            Arrays.fill(dp, INF);
            dp[i] = 0;
            for (int j = 0; j < q.size(); ++j) {
                int cur = q.get(j);
                int dcur = dp[cur];
                for (int to : g.get(cur)) {
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

        for (int i = 0; i < ws; ++i) {
            dist[i][0] = INF;
            for (int j = i + 1; j < ws; ++j) {
                int res = INF;
                for (int k = 0; k < F; ++k) {
                    res = Math.min(res, dist[i][k] + dist[j][k]);
                }
                ans[i][j] = res;
            }
        }

        int n = in.nextInt();
        while (n-- > 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            a = vid[a];
            b = vid[b];
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            out.println(ans[a][b]);
        }
        return 0;
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

    static void reunique(List<Integer> v) {
        List<Integer> temp = new ArrayList<>();
        for (int x : v) {
            if (temp.isEmpty() || temp.get(temp.size() - 1) != x) {
                temp.add(x);
            }
        }
        v.clear();
        v.addAll(temp);
    }

    static InputReader in;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
