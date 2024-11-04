import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;
    static int n, k;
    static int[] h;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }
        h = Arrays.copyOf(h, n + 1);
        h[n] = h[0];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] == h[i + 1]) {
                cnt++;
            }
        }
        int d = n - cnt;

        long res = pow(k, cnt);
        long sum = 0;

        long[] f = new long[2 * d + 1];
        f[0] = 1;
        f[1] = k - 2;
        f[2] = 1;
        f = pow(f, d);
        for (int i = d + 1; i <= 2 * d; i++) {
            sum += f[i];
        }

        System.out.println(res * sum % MOD);
    }

    static long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    static long[] pow(long[] a, long b) {
        int n = a.length;
        long[] res = new long[n];
        res[0] = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = multiply(res, a);
            }
            a = multiply(a, a);
            b >>= 1;
        }
        return res;
    }

    static long[] multiply(long[] a, long[] b) {
        int n = a.length;
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                res[i] += a[j] * b[i - j] % MOD;
                res[i] %= MOD;
            }
        }
        return res;
    }
}
