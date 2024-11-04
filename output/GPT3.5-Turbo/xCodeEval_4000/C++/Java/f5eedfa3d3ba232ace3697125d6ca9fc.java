import java.io.*;
import java.util.*;

public class f5eedfa3d3ba232ace3697125d6ca9fc_nc {
    static final int fftmod = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int[] a = new int[1010101];
        int[] fact = new int[201010];
        int[] revFact = new int[202020];

        fact[0] = 1;
        int N = 200000;
        for (int i = 1; i <= N; ++i) {
            fact[i] = (int) ((long) fact[i - 1] * i % fftmod);
        }
        revFact[N] = powmod(fact[N], fftmod - 2, fftmod);
        for (int i = N - 1; i >= 0; --i) {
            revFact[i] = (int) ((long) revFact[i + 1] * (i + 1) % fftmod);
        }

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(input[i]);
        }
        a[n] = a[0];
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != a[i + 1]) {
                cnt++;
            }
        }
        if (k == 1 || n == 1) {
            pw.println(0);
            pw.close();
            return;
        }
        long ans = 0;
        int freeChoices = k - 2;
        for (int i = 0; i <= cnt / 2; ++i) {
            long cur = (long) cnk(cnt, i) * cnk(cnt - i, i) % fftmod * powmod(freeChoices, cnt - 2 * i, fftmod) % fftmod * powmod(k, n - cnt, fftmod) % fftmod;
            ans += cur;
        }
        ans %= fftmod;
        long tot = powmod(k, n, fftmod) - ans;
        if (tot < 0) tot += fftmod;
        pw.println(tot * powmod(2, fftmod - 2, fftmod) % fftmod);
        pw.close();
    }

    static long powmod(long x, long n, long m) {
        long res = 1;
        x %= m;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * x % m;
            }
            x = x * x % m;
            n >>= 1;
        }
        return res;
    }

    static long cnk(int n, int k) {
        long res = 1;
        for (int i = 0; i < k; ++i) {
            res = res * (n - i) % fftmod * powmod(i + 1, fftmod - 2, fftmod) % fftmod;
        }
        return res;
    }
}
