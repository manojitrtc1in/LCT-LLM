import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 19f04700ddfe2b040c1e889e4b1055efxcodeeval_processed_4000.json {
    static final long MOD = 998244353;
    static final int MAXN = 200005;

    static int N;
    static long K;
    static long[] A = new long[MAXN];
    static Combinatorics comb = new Combinatorics();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());
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
            if (A[i] != A[i + 1]) cnt++;
        }

        long ans = 0;
        for (int i = 0; i * 2 <= cnt; i++) {
            long add = mulMod(comb.choose(cnt, i, MOD), comb.choose(cnt - i, i, MOD), MOD);
            add = mulMod(add, powMod(K, N - cnt, MOD), MOD);
            add = mulMod(add, powMod(K - 2, cnt - 2 * i, MOD), MOD);
            ans = addMod(ans, add, MOD);
        }
        ans = subMod(powMod(K, N, MOD), ans, MOD);
        ans = id1(ans, 2L, MOD);
        System.out.println(ans);
    }

    static long mulMod(long a, long b, long mod) {
        return (a * b) % mod;
    }

    static long addMod(long a, long b, long mod) {
        long ret = a + b;
        return ret < mod ? ret : ret - mod;
    }

    static long subMod(long a, long b, long mod) {
        long ret = a - b;
        return ret >= 0 ? ret : ret + mod;
    }

    static long powMod(long base, long pow, long mod) {
        long x = 1;
        while (pow > 0) {
            if ((pow & 1) == 1) x = mulMod(x, base, mod);
            base = mulMod(base, base, mod);
            pow >>= 1;
        }
        return x;
    }

    static long id6(long i, long p) {
        return powMod(i, p - 2, p);
    }

    static long id1(long i, long j, long p) {
        return mulMod(i, id6(j, p), p);
    }

    static class Combinatorics {
        long[] fact = new long[MAXN];
        long[] invFact = new long[MAXN];

        void init(int N, long P) {
            assert N < P;
            fact[0] = 1;
            for (int i = 1; i <= N; i++) {
                fact[i] = mulMod(fact[i - 1], i, P);
            }
            invFact[N] = id6(fact[N], P);
            for (int i = N - 1; i >= 0; i--) {
                invFact[i] = mulMod(invFact[i + 1], i + 1, P);
            }
        }

        long choose(int N, int K, long P) {
            return mulMod(mulMod(fact[N], invFact[K], P), invFact[N - K], P);
        }
    }
}
