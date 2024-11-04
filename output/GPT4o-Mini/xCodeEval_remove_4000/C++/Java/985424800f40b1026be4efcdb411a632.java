import java.util.*;

public class 985424800f40b1026be4efcdb411a632xcodeeval_processed_4000.json {
    static final long MOD = 1000000007;
    static final long MAX = 510000;
    static long[] fac = new long[(int) MAX];
    static long[] finv = new long[(int) MAX];
    static long[] inv = new long[(int) MAX];
    static long[] a = new long[101010];

    static void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (long i = 2; i < MAX; i++) {
            fac[(int) i] = fac[(int) (i - 1)] * i % MOD;
            inv[(int) i] = MOD - inv[(int) (MOD % i)] * (MOD / i) % MOD;
            finv[(int) i] = finv[(int) (i - 1)] * inv[(int) i] % MOD;
        }
    }

    static long cnk(long n, long k) {
        long ret = 1;
        for (long i = n - k + 1; i <= n; i++) {
            ret *= i;
        }
        for (int i = 1; i <= k; i++) {
            ret /= i;
        }
        return ret;
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        if (k == 1) {
            System.out.println(1);
            return;
        }
        a[2] = 1;
        for (int i = 3; i <= 10; i++) {
            a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
        }

        long ans = 1;
        for (int i = 0; i < k; i++) {
            ans += cnk(n, k - i) * a[k - i];
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        System.out.printf("%.10f\n", 0.0);
        COMinit();
        solve();
    }
}
