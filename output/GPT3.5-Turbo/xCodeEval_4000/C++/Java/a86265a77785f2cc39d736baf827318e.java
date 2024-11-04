import java.io.*;
import java.util.*;

public class a86265a77785f2cc39d736baf827318e_nc {
    static final int maxn = 200005;
    static final int jd = 200005;
    static final int mod = 998244353;

    static int n, k;
    static int[] aa = new int[maxn];
    static int[] bb = new int[maxn];

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

    static void add(int[] x, int y) {
        x[0] += y;
        if (x[0] >= mod) {
            x[0] -= mod;
        }
    }

    static int ksm(int a, int b) {
        int ans = 1;
        for (; b > 0; b >>= 1, a = (int) ((long) a * a % mod)) {
            if ((b & 1) == 1) {
                ans = (int) ((long) a * ans % mod);
            }
        }
        return ans;
    }

    static int[] fac = new int[maxn];
    static int[] inv = new int[maxn];

    static int C(int n, int m) {
        return (int) ((long) fac[n] * inv[m] % mod * inv[n - m] % mod);
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
            fac[i] = (int) ((long) fac[i - 1] * i % mod);
        }
        inv[n] = ksm(fac[n], mod - 2);
        for (int i = n - 1; i >= 0; --i) {
            inv[i] = (int) ((long) inv[i + 1] * (i + 1) % mod);
        }
        int ans = 1;
        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            if (aa[i] == bb[i]) {
                ans = (int) ((long) ans * k % mod);
            } else {
                cnt++;
            }
        }


        int tmpans = 0;
        for (int i = 0; i <= cnt; i += 2) {
            int anss = (int) ((long) ksm(k - 2, cnt - i) * C(i, i >> 1) % mod * C(cnt, i) % mod);


            add(tmpans, anss);
        }
        ans = (int) ((long) tmpans * ans % mod);


        int Ans = ksm(k, n);
        Ans -= ans;
        if (Ans < 0) {
            Ans += mod;
        }
        System.out.println((long) Ans * ksm(2, mod - 2) % mod);
    }
}
