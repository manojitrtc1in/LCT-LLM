import java.io.*;
import java.util.*;

class Main {
    static final long MOD = 998244353;
    static final int MAXN = 2 * 100000 + 5;

    static int N;
    static long K;
    static long[] A = new long[MAXN];
    static Combinatorics comb = new Combinatorics();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Long.parseLong(input[1]);

        input = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            A[i] = Long.parseLong(input[i - 1]);
        }
        A[0] = A[N];

        if (K == 1) {
            pw.println(0);
            pw.flush();
            return;
        }

        comb.init(N, MOD);
        long cnt = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] != A[i + 1]) {
                cnt++;
            }
        }

        long ans = 0;
        for (int i = 0; i * 2 <= cnt; i++) {
            long add = comb.choose(cnt, i, MOD);
            add = comb.choose(cnt - i, i, MOD);
            add = comb.powMod(K, N - cnt, MOD);
            add = comb.powMod(K - 2, cnt - 2 * i, MOD);
            ans = comb.addMod(ans, add, MOD);
        }

        ans = comb.subMod(comb.powMod(K, N, MOD), ans, MOD);
        ans = comb.divModPrime(ans, 2, MOD);

        pw.println(ans);
        pw.flush();
    }
}

class Combinatorics {
    long[] fact;
    long[] invFact;

    void init(int N) {
        fact = new long[N + 1];
        invFact = new long[N + 1];

        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
    }

    void init(int N, long P) {
        assert (N < P);
        fact = new long[N + 1];
        invFact = new long[N + 1];

        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % P;
        }

        invFact[N] = mulInvPrime(fact[N], P);
        for (int i = N - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % P;
        }
    }

    long factorial(int N) {
        return fact[N];
    }

    long invFactorial(int N) {
        return invFact[N];
    }

    long permute(int N, int K) {
        return fact[N] * invFact[N - K] % MOD;
    }

    long permute(int N, int K, long P) {
        return fact[N] * invFact[N - K] % P;
    }

    long choose(int N, int K) {
        return fact[N] * invFact[K] % MOD * invFact[N - K] % MOD;
    }

    long choose(int N, int K, long P) {
        return fact[N] * invFact[K] % P * invFact[N - K] % P;
    }

    long multiChoose(int N, int K) {
        return choose(N + K - 1, K);
    }

    long multiChoose(int N, int K, long P) {
        return choose(N + K - 1, K, P);
    }

    long mulInvPrime(long i, long p) {
        return powMod(i, p - 2, p);
    }

    long divModPrime(long i, long j, long p) {
        return i * mulInvPrime(j, p) % p;
    }

    long powMod(long base, long pow, long mod) {
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
