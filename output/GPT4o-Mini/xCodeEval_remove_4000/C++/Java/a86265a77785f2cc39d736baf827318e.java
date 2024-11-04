import java.io.*;
import java.util.*;

public class a86265a77785f2cc39d736baf827318excodeeval_processed_4000.json {
    static final int maxn = 200005;
    static final int mod = 998244353;
    static long[] fac = new long[maxn];
    static long[] inv = new long[maxn];
    static int[] aa = new int[maxn];
    static int[] bb = new int[maxn];
    static int n, k;

    static int nxt(int x) {
        x++;
        if (x > n) {
            x = 1;
        }
        return x;
    }

    static int pre(int x) {
        x--;
        if (x < 1) {
            x = n;
        }
        return x;
    }

    static void add(long[] x, long y) {
        x[0] += y;
        if (x[0] >= mod) {
            x[0] -= mod;
        }
    }

    static long ksm(long a, long b) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    static long C(int n, int m) {
        return (fac[n] * inv[m] % mod * inv[n - m] % mod);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i) {
            aa[i] = Integer.parseInt(st.nextToken());
            bb[pre(i)] = aa[i];
        }

        fac[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fac[i] = (fac[i - 1] * i) % mod;
        }
        inv[n] = ksm(fac[n], mod - 2);
        for (int i = n - 1; i >= 0; --i) {
            inv[i] = (inv[i + 1] * (i + 1)) % mod;
        }

        long ans = 1;
        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            if (aa[i] == bb[i]) {
                ans = (ans * k) % mod;
            } else {
                cnt++;
            }
        }

        long tmpans = 0;
        for (int i = 0; i <= cnt; i += 2) {
            long anss = (ksm(k - 2, cnt - i) * C(i, i >> 1) % mod * C(cnt, i) % mod);
            add(new long[]{tmpans}, anss);
        }
        ans = (tmpans * ans) % mod;

        long Ans = ksm(k, n);
        Ans -= ans;
        if (Ans < 0) {
            Ans += mod;
        }
        System.out.println((Ans * ksm(2, mod - 2)) % mod);
    }
}
