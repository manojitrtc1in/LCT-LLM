import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static final int mod = 998244353;
    static final int mxN = 2 * 1000000 + 5;
    static long[] fac = new long[mxN];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        fac[0] = 1;
        for (int i = 1; i < mxN; i++) {
            fac[i] = (fac[i - 1] * i) % mod;
        }

        if (k >= n) {
            pw.println(0);
            pw.close();
            return;
        }

        long ans = 0;
        for (int i = 0; i <= n - k; ++i) {
            ans += ((n - k - i) % 2 == 0 ? 1 : -1) * C(n - k, i) * bpow(i, n);
            ans %= mod;
        }

        ans = (1 + (k > 0)) * ans % mod * C(n, n - k) % mod;
        pw.println(ans);
        pw.close();
    }

    static long C(int n, int m) {
        long res = fac[n] * bpow(fac[m], mod - 2) % mod * bpow(fac[n - m], mod - 2) % mod;
        return res;
    }

    static long bpow(long x, int n) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
}
