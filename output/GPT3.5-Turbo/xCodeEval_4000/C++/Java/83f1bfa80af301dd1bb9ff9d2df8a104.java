import java.io.*;
import java.util.*;

public class 83f1bfa80af301dd1bb9ff9d2df8a104_nc {
    static ArrayList<Integer>[] vec = new ArrayList[1010101];
    static int[] vid = new int[1010101];
    static int[] pr = new int[1010101];
    static ArrayList<Integer>[] primes;
    static long maxh;
    static int[][] dist;
    static boolean[] vis;
    static int[] dc;
    static ArrayList<Integer>[] g;
    static ArrayList<ArrayList<Integer>> w;
    static int[][] ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        w = new ArrayList<>();
        w.add(new ArrayList<>());
        HashMap<Long, Integer> used = new HashMap<>();
        used.put(0L, 0);
        int N = 1000010;
        primes = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            primes[i] = new ArrayList<>();
        }
        for (int i = 2; i < N; i++) {
            if (pr[i] == 0) {
                pr[i] = i;
                primes[i].add(i);
            }
            for (int p : primes[i]) {
                if (p * i >= N || p > pr[i]) {
                    break;
                }
                pr[p * i] = p;
                primes[p * i].add(p);
            }
            int cnt = 1;
            int x = i;
            while (pr[x] == pr[x / pr[x]]) {
                cnt++;
                x /= pr[x];
            }
            x /= pr[x];
            vec[i] = new ArrayList<>();
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
        g = new ArrayList[F * 2];
        for (int i = 0; i < F * 2; i++) {
            g[i] = new ArrayList<>();
        }
        dc = new int[F * 2];
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
            g[i] = reunique(g[i]);
            dc[i] = calcd(w.get(i));
        }
        dist = new int[301][F * 2];
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

    static ArrayList<Integer> reunique(ArrayList<Integer> v) {
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < v.size(); i++) {
            if (i == 0 || !v.get(i).equals(v.get(i - 1))) {
                res.add(v.get(i));
            }
        }
        return res;
    }

    static final int USUAL_MOD = 1000000007;
    static final int INF = 1011111111;
    static final int F = 3001;

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }
}
