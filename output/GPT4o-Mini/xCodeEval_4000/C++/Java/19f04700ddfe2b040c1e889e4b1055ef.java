import java.io.*;
import java.util.*;

public class 19f04700ddfe2b040c1e889e4b1055ef_nc {
    static final long MOD = 998244353;
    static final int MAXN = 200005;
    static long[] A = new long[MAXN];
    static Combinatorics comb = new Combinatorics();

    static class Combinatorics {
        long[] fact = new long[MAXN];
        long[] invFact = new long[MAXN];

        void init(int N) {
            fact[0] = 1;
            for (int i = 1; i <= N; i++) {
                fact[i] = fact[i - 1] * i;
            }
        }

        void init(int N, long P) {
            assert N < P;
            fact[0] = 1;
            for (int i = 1; i <= N; i++) {
                fact[i] = mulMod(fact[i - 1], i, P);
            }
            invFact[N] = mulInvPrime(fact[N], P);
            for (int i = N - 1; i >= 0; i--) {
                invFact[i] = mulMod(invFact[i + 1], i + 1, P);
            }
        }

        long factorial(int N) {
            return fact[N];
        }

        long invFactorial(int N) {
            return invFact[N];
        }

        long permute(int N, int K) {
            return fact[N] / fact[N - K];
        }

        long permute(int N, int K, long P) {
            return mulMod(fact[N], invFact[N - K], P);
        }

        long choose(int N, int K) {
            return fact[N] / (fact[K] * fact[N - K]);
        }

        long choose(int N, int K, long P) {
            return mulMod(mulMod(fact[N], invFact[K], P), invFact[N - K], P);
        }

        long multiChoose(int N, int K) {
            return choose(N + K - 1, K);
        }

        long multiChoose(int N, int K, long P) {
            return choose(N + K - 1, K, P);
        }

        long mulMod(long a, long b, long mod) {
            return (a * b) % mod;
        }

        long powMod(long base, long pow, long mod) {
            long x = 1;
            while (pow > 0) {
                if ((pow & 1) == 1) {
                    x = mulMod(x, base, mod);
                }
                base = mulMod(base, base, mod);
                pow >>= 1;
            }
            return x;
        }

        long mulInvPrime(long i, long p) {
            return powMod(i, p - 2, p);
        }

        long divModPrime(long i, long j, long p) {
            return mulMod(i, mulInvPrime(j, p), p);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        A[0] = A[N];
        if (K == 1) {
            System.out.println(0);
            return;
        }
        comb.init(N, MOD);
        long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += A[i] != A[i + 1] ? 1 : 0;
        }
        long ans = 0;
        for (int i = 0; i * 2 <= cnt; i++) {
            long add = mulMod(comb.choose((int) cnt, i, MOD), comb.choose((int) (cnt - i), i, MOD), MOD);
            add = mulMod(add, comb.powMod(K, N - cnt, MOD), MOD);
            add = mulMod(add, comb.powMod(K - 2, cnt - 2 * i, MOD), MOD);
            ans = (ans + add) % MOD;
        }
        ans = (comb.powMod(K, N, MOD) - ans + MOD) % MOD;
        ans = divModPrime(ans, 2, MOD);
        System.out.println(ans);
    }
}
