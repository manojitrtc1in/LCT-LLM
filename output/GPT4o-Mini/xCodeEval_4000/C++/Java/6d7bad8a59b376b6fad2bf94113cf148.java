import java.util.*;
import java.io.*;

public class 6d7bad8a59b376b6fad2bf94113cf148_nc {
    static final int N = 70;
    static long INF64 = (long) 1e18;
    static int INF = (int) 1e9;
    static int[] c = new int[N];
    static Pair[] a = new Pair[N];
    static int x, k, n, q;
    static int cnt;
    static int[] num = new int[1 << 8];

    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static long[][][] matMul(long[][] a, long[][] b) {
        long[][] c = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                c[i][j] = INF64;
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                for (int k = 0; k < cnt; k++)
                    c[i][j] = Math.min(c[i][j], a[i][k] + b[k][j]);
        return c;
    }

    static long[][] matPow(long[][] a, int b) {
        long[][] res = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                res[i][j] = (i == j) ? 0 : INF64;
        while (b > 0) {
            if ((b & 1) == 1)
                res = matMul(res, a);
            a = matMul(a, a);
            b >>= 1;
        }
        return res;
    }

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
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                res[i][j] = INF64;
        for (int mask = 0; mask < (1 << k); mask++) {
            if (Integer.bitCount(mask) == x) {
                if ((mask & 1) != 0) {
                    for (int i = 1; i <= k; i++) {
                        if ((mask & (1 << i)) == 0) {
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
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                cur[i][j] = (i == j) ? 0 : INF64;
        Arrays.sort(a, 0, q, Comparator.comparingInt(p -> p.x));
        for (int i = 0; i < n - x; ) {
            int[] mx = new int[1];
            long[][] tmp = get(i, mx);
            i += mx[0];
            cur = matMul(cur, matPow(tmp, mx[0]));
        }
        System.out.println(cur[0][0]);
    }

    static boolean read() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return false;
        x = scanner.nextInt();
        k = scanner.nextInt();
        n = scanner.nextInt();
        q = scanner.nextInt();
        for (int i = 0; i < k; i++) {
            c[i] = scanner.nextInt();
        }
        for (int i = 0; i < q; i++) {
            a[i] = new Pair(scanner.nextInt() - 1, scanner.nextInt());
        }
        return true;
    }

    public static void main(String[] args) {
        while (read()) {
            solve();
        }
    }
}
