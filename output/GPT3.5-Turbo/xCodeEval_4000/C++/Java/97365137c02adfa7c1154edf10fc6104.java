import java.util.*;
import java.io.*;

class Main {
    static final int INF = 1_000_000_000;
    static final long LINF = 1_000_000_000_000_000_000L;
    static final int M = 1_000_000_007;

    static final int C = 20;
    static List<Integer>[] G = new ArrayList[C];
    static int[] masks = new int[C];
    static boolean[] dp = new boolean[1 << C];
    static boolean[] vis = new boolean[C];
    static int mask;
    static List<Integer> cur;

    static void dfs(int v) {
        vis[v] = true;
        mask |= 1 << v;
        cur.add(v);

        for (int s : G[v]) {
            if (!vis[s]) {
                dfs(s);
            }
        }
    }

    static int count() {
        List<Integer> sub = new ArrayList<>();
        for (int m = mask; m != 0; m = (m - 1) & (mask)) {
            sub.add(m);
        }
        Collections.reverse(sub);

        int res = 0;
        for (int m : sub) {
            for (int v : cur) {
                if ((m & (1 << v)) != 0) {
                    dp[m] |= dp[m ^ (1 << v)] && ((m & masks[v] & mask) == 0);
                }
            }
            if (dp[m]) {
                res = Math.max(res, Integer.bitCount(m));
            }
        }
        return res;
    }

    static int solve() {
        int n = si();
        String s = ss(n);
        String t = ss(n);

        int res = 0;
        Arrays.fill(dp, false);
        Arrays.fill(vis, false);
        Arrays.fill(masks, 0);
        for (int i = 0; i < C; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                int a = s.charAt(i) - 'a';
                int b = t.charAt(i) - 'a';
                G[a].add(b);
                G[b].add(a);
                masks[a] |= 1 << b;
            }
        }

        for (int i = 0; i < C; i++) {
            if (!vis[i]) {
                mask = 0;
                cur = new ArrayList<>();
                dfs(i);
                int tmp = count();
                res += 2 * cur.size() - 1 - tmp;
            }
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            pw.println(solve());
        }

        pw.close();
    }

    static int si() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    static long sl() throws IOException {
        return Long.parseLong(br.readLine());
    }

    static double sd() throws IOException {
        return Double.parseDouble(br.readLine());
    }

    static String ss() throws IOException {
        return br.readLine();
    }

    static int[] ina() throws IOException {
        String[] arr = br.readLine().split(" ");
        int[] a = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            a[i] = Integer.parseInt(arr[i]);
        }
        return a;
    }

    static long[] inl() throws IOException {
        String[] arr = br.readLine().split(" ");
        long[] a = new long[arr.length];
        for (int i = 0; i < arr.length; i++) {
            a[i] = Long.parseLong(arr[i]);
        }
        return a;
    }

    static double[] ind() throws IOException {
        String[] arr = br.readLine().split(" ");
        double[] a = new double[arr.length];
        for (int i = 0; i < arr.length; i++) {
            a[i] = Double.parseDouble(arr[i]);
        }
        return a;
    }

    static String[] ins() throws IOException {
        return br.readLine().split(" ");
    }

    static void print(Object o) {
        pw.print(o);
    }

    static void println(Object o) {
        pw.println(o);
    }

    static void println() {
        pw.println();
    }

    static void flush() {
        pw.flush();
    }

    static void exit() {
        pw.close();
        System.exit(0);
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
}
