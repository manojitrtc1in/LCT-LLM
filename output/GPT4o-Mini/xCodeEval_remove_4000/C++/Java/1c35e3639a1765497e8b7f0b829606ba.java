import java.util.*;
import java.math.*;

class Main {
    static class ModInt {
        static final int MOD = 998244353;
        long v;

        ModInt() {
            this.v = 0;
        }

        ModInt(long _v) {
            this.v = normS(_v % MOD + MOD);
        }

        static long normS(long x) {
            return (x < MOD) ? x : x - MOD;
        }

        ModInt add(ModInt b) {
            return new ModInt(normS(this.v + b.v));
        }

        ModInt sub(ModInt b) {
            return new ModInt(normS(this.v + MOD - b.v));
        }

        ModInt mul(ModInt b) {
            return new ModInt((this.v * b.v) % MOD);
        }

        ModInt inv() {
            long x = 0, y = 0;
            extgcd(this.v, MOD, x, y);
            return new ModInt(normS(x + MOD));
        }

        static long extgcd(long a, long b, long[] x, long[] y) {
            long[] p = {a, 1, 0}, q = {b, 0, 1};
            while (q[0] != 0) {
                long t = p[0] / q[0];
                for (int i = 0; i < 3; i++) {
                    long temp = p[i];
                    p[i] -= t * q[i];
                    q[i] = temp;
                }
            }
            if (p[0] < 0) {
                for (int i = 0; i < 3; i++) {
                    p[i] = -p[i];
                }
            }
            x[0] = p[1];
            y[0] = p[2];
            return p[0];
        }

        ModInt pow(long p) {
            if (p < 0) return inv().pow(-p);
            ModInt a = new ModInt(1);
            ModInt x = this;
            while (p > 0) {
                if ((p & 1) == 1) a = a.mul(x);
                x = x.mul(x);
                p >>= 1;
            }
            return a;
        }

        public String toString() {
            return Long.toString(v);
        }
    }

    static ModInt[] fact, ifact;

    static void InitFact(int N) {
        fact = new ModInt[N];
        ifact = new ModInt[N];
        fact[0] = new ModInt(1);
        for (int i = 1; i < N; i++) {
            fact[i] = fact[i - 1].mul(new ModInt(i));
        }
        ifact[N - 1] = fact[N - 1].inv();
        for (int i = N - 2; i >= 0; i--) {
            ifact[i] = ifact[i + 1].mul(new ModInt(i + 1));
        }
    }

    static ModInt Choose(int a, int b) {
        if (b < 0 || a < b) return new ModInt(0);
        return fact[a].mul(ifact[b]).mul(ifact[a - b]);
    }

    static ModInt solve(long N) {
        ModInt res = new ModInt(0);
        for (int i = 0; i <= N; i++) {
            if (i == 0) {
                for (int j = 1; j <= N; j++) {
                    res = res.add(new ModInt(-1).pow(i + j).mul(Choose((int) N, j)).mul(new ModInt(3).pow(j + N * (N - j))));
                }
            } else {
                res = res.add(new ModInt(-1).pow(i).mul(Choose((int) N, i)).mul(((new ModInt(3).pow(N - i).sub(new ModInt(1))).pow(N)).sub(new ModInt(3).pow((N - i) * N))).mul(new ModInt(3)));
                res = res.add(new ModInt(-1).pow(i).mul(Choose((int) N, i)).mul(new ModInt(3).pow(i + N * (N - i))));
            }
        }
        return res.mul(new ModInt(-1));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        InitFact(2000010);
        long N = scanner.nextLong();
        System.out.println(solve(N));
    }
}
