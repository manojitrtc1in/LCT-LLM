import java.util.*;
import java.io.*;

public class 6d7bad8a59b376b6fad2bf94113cf148xcodeeval_processed_4000.json {
    static final long INF64 = (long) 1e18;
    static final int N = 70;
    static int x, k, n, q;
    static int[] c = new int[N];
    static Pair[] a = new Pair[N];
    static int cnt;
    static long[][][] mat = new long[N][N][N];

    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static boolean read() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        if (st.countTokens() < 4) return false;
        x = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            c[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            a[i] = new Pair(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()));
        }
        return true;
    }

    static long[][] multiply(long[][] a, long[][] b) {
        long[][] c = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            Arrays.fill(c[i], INF64);
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                for (int k = 0; k < cnt; k++) {
                    c[i][j] = Math.min(c[i][j], a[i][k] + b[k][j]);
                }
            }
        }
        return c;
    }

    static long[][] binpow(long[][] a, int b) {
        long[][] res = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            Arrays.fill(res[i], INF64);
            res[i][i] = 0;
        }
        while (b > 0) {
            if ((b & 1) == 1) {
                res = multiply(res, a);
            }
            a = multiply(a, a);
            b >>= 1;
        }
        return res;
    }

    static int[] num = new int[1 << 8];

    static long[][] get(int pos, int[] mx) {
        mx[0] = n - x - pos;
        int[] pr = new int[k];
        for (int i = 0; i < q; i++) {
            if (pos < a[i].x) {
                if (a[i].x <= pos + k) {
                    pr[a[i].x - pos - 1] = a[i].y;
                    mx[0] = 1;
                } else {
                    mx[0] = Math.min(mx[0], a[i].x - (pos + k));
                }
            }
        }
        long[][] res = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            Arrays.fill(res[i], INF64);
        }
        for (int mask = 0; mask < (1 << k); mask++) {
            if (Integer.bitCount(mask) == x) {
                if ((mask & 1) != 0) {
                    for (int i = 1; i <= k; i++) {
                        if (((mask >> i) & 1) == 0) {
                            res[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1];
                        }
                    }
                } else {
                    res[num[mask]][num[mask >> 1]] = 0;
                }
            }
        }
        return res;
    }

    static void solve() {
        cnt = 0;
        for (int mask = 0; mask < (1 << k); mask++) {
            if (Integer.bitCount(mask) == x) {
                num[mask] = cnt++;
            }
        }

        long[][] cur = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            Arrays.fill(cur[i], INF64);
            cur[i][i] = 0;
        }
        Arrays.sort(a, 0, q, Comparator.comparingInt(p -> p.x));
        for (int i = 0; i < n - x; ) {
            int[] mx = new int[1];
            long[][] tmp = get(i, mx);
            i += mx[0];
            cur = multiply(cur, binpow(tmp, mx[0]));
        }

        System.out.println(cur[0][0]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (read()) {
            solve();
        }
    }
}
