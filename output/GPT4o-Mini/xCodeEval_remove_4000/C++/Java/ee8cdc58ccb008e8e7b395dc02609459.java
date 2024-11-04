import java.util.*;
import java.io.*;

class Main {
    static final long MOD = 1000000007;
    static long[] fact = new long[200010];

    static class Ring {
        long value;

        Ring() {
            this.value = 0;
        }

        Ring(long _value) {
            this.value = floorMod(_value, MOD);
        }

        Ring pow(long p) {
            Ring r = new Ring(1);
            Ring x = new Ring(value);
            while (p > 0) {
                if ((p & 1) == 1) r = r.mul(x);
                x = x.mul(x);
                p /= 2;
            }
            return r;
        }

        Ring inv() {
            return pow(MOD - 2);
        }

        Ring mul(Ring b) {
            value = floorMod(value * b.value, MOD);
            return this;
        }

        Ring add(Ring b) {
            value += b.value;
            if (value >= MOD) value -= MOD;
            return this;
        }

        Ring sub(Ring b) {
            value -= b.value;
            if (value < 0) value += MOD;
            return this;
        }

        Ring div(Ring b) {
            return mul(b.inv());
        }

        static long floorMod(long a, long b) {
            a %= b;
            if (a < 0) a += b;
            return a;
        }

        @Override
        public String toString() {
            return Long.toString(value);
        }
    }

    static Ring binom(int n, int k) {
        if (k > n) return new Ring(0);
        return new Ring(fact[n]).div(new Ring(fact[n - k]).mul(new Ring(fact[k])));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n + 100; i++) {
            fact[i] = (i == 0) ? 1 : (fact[i - 1] * i) % MOD;
        }
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = scanner.nextInt();
        }

        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : v) {
            for (int j = 2; j * j <= x; j++) {
                while (x % j == 0 && (x / j) % j == 0) {
                    x /= j;
                    x /= j;
                }
            }
            cnt.put(x, cnt.getOrDefault(x, 0) + 1);
        }

        List<Integer> c = new ArrayList<>(cnt.values());
        long[] dp = new long[n + 10];
        dp[0] = 1;

        for (int x : c) {
            long[] ndp = new long[n + 10];
            for (int i = 0; i < dp.length; i++) {
                if (dp[i] != 0) {
                    for (int j = 0; j < x; j++) {
                        int dist = x - j;
                        ndp[i + dist] = (ndp[i + dist] + dp[i] * binom(x - 1, j).value * binom(i + dist, dist).value) % MOD;
                    }
                }
            }
            dp = ndp;
        }

        int conds = n - c.size();
        Ring finalResult = new Ring(0);
        Ring sign = new Ring(1);
        for (int i = 0; i <= conds; i++) {
            finalResult = finalResult.add(sign.mul(new Ring(dp[n - i])));
            sign = new Ring(-1).mul(sign);
        }
        for (int x : c) {
            finalResult = finalResult.mul(new Ring(fact[x]));
        }
        System.out.println(finalResult);
    }
}
