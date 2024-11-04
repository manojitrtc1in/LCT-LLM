import java.io.*;
import java.util.*;

class Main {
    static final long MOD = 998244353;
    static final int MAXN = 2 * 100000 + 5;

    static int N;
    static long K;
    static long[] A = new long[MAXN];
    static long[] fact = new long[MAXN];
    static long[] invFact = new long[MAXN];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        A[0] = A[N];

        if (K == 1) {
            pw.println(0);
            pw.flush();
            return;
        }

        initCombinatorics();

        long cnt = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] != A[i + 1]) {
                cnt++;
            }
        }

        long ans = 0;
        for (int i = 0; i * 2 <= cnt; i++) {
            long add = choose(cnt, i) * choose(cnt - i, i) % MOD;
            add = add * powMod(K, N - cnt, MOD) % MOD;
            add = add * powMod(K - 2, cnt - 2 * i, MOD) % MOD;
            ans = (ans + add) % MOD;
        }

        ans = (powMod(K, N, MOD) - ans + MOD) % MOD;
        ans = powMod(ans, 2, MOD);

        pw.println(ans);
        pw.flush();
    }

    static void initCombinatorics() {
        fact[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[MAXN - 1] = powMod(fact[MAXN - 1], MOD - 2, MOD);
        for (int i = MAXN - 2; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

    static long choose(long n, long k) {
        if (k < 0 || k > n) {
            return 0;
        }
        return fact[(int) n] * invFact[(int) k] % MOD * invFact[(int) (n - k)] % MOD;
    }

    static long powMod(long base, long pow, long mod) {
        long x = 1;
        while (pow > 0) {
            if ((pow & 1) == 1) {
                x = x * base % mod;
            }
            base = base * base % mod;
            pow >>= 1;
        }
        return x;
    }
}
