import java.util.*;
import java.io.*;

public class 1c35e3639a1765497e8b7f0b829606ba_nc {
    static final long MOD = 998244353;
    static long[] fact, ifact;

    static long mod(long x) {
        return (x % MOD + MOD) % MOD;
    }

    static long choose(int a, int b) {
        if (b < 0 || a < b) return 0;
        return mod(fact[a] * ifact[b] % MOD * ifact[a - b] % MOD);
    }

    static void initFact(int N) {
        fact = new long[N];
        ifact = new long[N];
        fact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = mod(fact[i - 1] * i);
        }
        ifact[N - 1] = modInverse(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--) {
            ifact[i] = mod(ifact[i + 1] * (i + 1));
        }
    }

    static long modInverse(long a) {
        return pow(a, MOD - 2);
    }

    static long pow(long a, long p) {
        long res = 1;
        while (p > 0) {
            if ((p & 1) == 1) {
                res = mod(res * a);
            }
            a = mod(a * a);
            p >>= 1;
        }
        return res;
    }

    static long solve(long N) {
        long res = 0;
        for (int i = 0; i <= N; i++) {
            if (i == 0) {
                for (int j = 1; j <= N; j++) {
                    res = mod(res + mod(pow(-1, i + j) * choose(N, j) * pow(3, j + N * (N - j))));
                }
            } else {
                res = mod(res + mod(pow(-1, i) * choose(N, i) * (mod(pow(3, N - i) - 1) * mod(pow(N, N)) - mod(pow(3, (N - i) * N))) * 3));
                res = mod(res + mod(pow(-1, i) * choose(N, i) * mod(pow(3, i + N * (N - i)))));
            }
        }
        return mod(-res);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        initFact(2000010);
        System.out.println(solve(N));
    }
}
