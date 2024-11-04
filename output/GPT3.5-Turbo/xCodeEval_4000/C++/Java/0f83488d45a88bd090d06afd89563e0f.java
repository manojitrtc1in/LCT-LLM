import java.io.*;
import java.util.*;

public class 0f83488d45a88bd090d06afd89563e0f_nc {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple<T1, T2, T3> {
        T1 first;
        T2 second;
        T3 third;

        public Triple(T1 first, T2 second, T3 third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Quadruple<T1, T2, T3, T4> {
        T1 first;
        T2 second;
        T3 third;
        T4 fourth;

        public Quadruple(T1 first, T2 second, T3 third, T4 fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }
    }

    static final int USUAL_MOD = 1000000007;

    static int solve() {
        List<List<Integer>> vec = new ArrayList<>();
        int[] vid = new int[1010101];
        int[] pr = new int[1010101];
        List<Integer> primes = new ArrayList<>();
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
            vec.add(new ArrayList<>(vec.get(x)));
            vec.get(i).add(cnt);
            int h = calc(vec.get(i));
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
            List<Integer> cur = w.get(i);
            for (int j = 0; j < cur.size(); ++j) {
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
                for (int to : g[cur]) {
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
            for (int j = 0; j < i + 1; ++j) {
                int res = INF;
                for (int k = 0; k < F; ++k) {
                    res = Math.min(res, dist[i][k] + dist[j][k]);
                }
                ans[i][j] = res;
            }
        }
        int n = fs.nextInt();
        while (n-- > 0) {
            int a = fs.nextInt();
            int b = fs.nextInt();
            a = vid[a];
            b = vid[b];
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            System.out.println(ans[a][b]);
        }
        return 0;
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

    static Map<Integer, Integer> used = new HashMap<>();
    static final int F = 1001;
    static int[][] dist = new int[301][F * 2];
    static boolean[] vis = new boolean[F * 2];
    static int[] dc = new int[F * 2];
    static List<Integer>[] g = new List[F * 2];
    static List<List<Integer>> w = new ArrayList<>();
    static int[][] ans = new int[303][303];

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

    static FastScanner fs = new FastScanner(System.in);

    public static void main(String[] args) {
        solve();
    }
}
