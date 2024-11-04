import java.util.*;
import java.io.*;

public class 19f6457bcce1fbaf538621e84aecf601_nc {
    static final int MOD = 1000000007;

    static long powe(long b, long e) {
        long r = 1;
        while (e > 0) {
            if ((e & 1) == 1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

    static void admul(long[] a, long b, long c) {
        a[0] = (a[0] + b * c) % MOD;
    }

    static void go(int n) {
        long[][] p = new long[n][n];
        long i100 = powe(100, MOD - 2);
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long x = scanner.nextLong();
                p[i][j] = x * i100 % MOD;
            }
        }

        Map<State, Long> x = new HashMap<>();
        State init = new State(n);
        x.put(init, 1L);

        for (int turn = 0; turn < n; turn++) {
            Map<State, Long> newx = new HashMap<>();
            for (int s = 0; s < (1 << n); s++) {
                long mul = 1;
                for (int i = 0; i < n; i++) {
                    if ((s >> i & 1) == 1) {
                        mul = mul * p[i][turn] % MOD;
                    } else {
                        mul = mul * (1 - p[i][turn] + MOD) % MOD;
                    }
                }
                for (Map.Entry<State, Long> c : x.entrySet()) {
                    for (int k = 0; k < (1 << n); k++) {
                        if ((k & s) != 0 && c.getKey().count[k] < Long.bitCount(k)) {
                            c.getKey().count[k]++;
                        }
                    }
                    boolean add = true;
                    for (int k = 0; k < (1 << n); k++) {
                        if (c.getKey().count[k] + (n - turn - 1) < Long.bitCount(k)) {
                            add = false;
                        }
                    }
                    if (add) {
                        admul(newx.computeIfAbsent(c.getKey(), k -> 0L), mul, c.getValue());
                    }
                }
            }
            x = newx;
        }

        State fin = new State(n);
        long ans = x.getOrDefault(fin, 0L);
        ans %= MOD;
        if (ans < 0) ans += MOD;
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n == 1) go(1);
        else if (n == 2) go(2);
        else if (n == 3) go(3);
        else if (n == 4) go(4);
        else if (n == 5) go(5);
        else if (n == 6) go(6);
    }

    static class State {
        int[] count;

        State(int n) {
            count = new int[1 << n];
            Arrays.fill(count, 0);
        }
    }
}
