import java.io.*;
import java.util.*;

public class f5eedfa3d3ba232ace3697125d6ca9fcxcodeeval_processed_4000.json {
    static final int id10 = 1000000007;
    static int[] a = new int[1010101];
    static int[] fact = new int[201010];
    static int[] revFact = new int[202020];
    static final int fftmod = id10;

    static long powmod(long x, long n, long m) {
        long r = 1;
        x %= m;
        while (n > 0) {
            if ((n & 1) == 1) r = r * x % m;
            x = x * x % m;
            n /= 2;
        }
        return r;
    }

    static long cnk(int n, int k) {
        return fact[n] * 1L * revFact[k] % fftmod * revFact[n - k] % fftmod;
    }

    static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        a[n] = a[0];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i] != a[i + 1] ? 1 : 0;
        }

        if (k == 1 || n == 1) {
            System.out.println(0);
            return;
        }

        long ans = 0;
        int freeChoices = k - 2;
        for (int i = 0; i <= cnt / 2; i++) {
            long cur = cnk(cnt, i) * cnk(cnt - i, i) % fftmod * powmod(freeChoices, cnt - 2 * i, fftmod) % fftmod * powmod(k, n - cnt, fftmod) % fftmod;
            ans += cur;
        }
        ans %= fftmod;

        long tot = powmod(k, n, fftmod) - ans;
        if (tot < 0) tot += fftmod;
        System.out.println(tot * powmod(2, fftmod - 2, fftmod) % fftmod);
    }

    public static void main(String[] args) throws IOException {
        fact[0] = 1;
        final int N = 200000;
        for (int i = 1; i <= N; i++) {
            fact[i] = (int) (fact[i - 1] * 1L * i % fftmod);
        }
        revFact[N] = (int) powmod(fact[N], fftmod - 2, fftmod);
        for (int i = N - 1; i >= 0; i--) {
            revFact[i] = (int) (revFact[i + 1] * (i + 1L) % fftmod);
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        solve();
    }
}
