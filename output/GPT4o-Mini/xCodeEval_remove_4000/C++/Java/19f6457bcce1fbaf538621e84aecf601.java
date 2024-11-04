import java.util.*;
import java.util.stream.*;

public class 19f6457bcce1fbaf538621e84aecf601xcodeeval_processed_4000.json {
    static final int MOD = (int) 1e9 + 7;

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

        Map<String, Long> x = new HashMap<>();
        String init = new String(new char[1 << n]).replace("\0", "0");
        x.put(init, 1L);

        for (int turn = 0; turn < n; turn++) {
            Map<String, Long> newx = new HashMap<>();
            for (int s = 0; s < (1 << n); s++) {
                long mul = 1;
                for (int i = 0; i < n; i++) {
                    if ((s >> i & 1) == 1) {
                        mul = mul * p[i][turn] % MOD;
                    } else {
                        mul = mul * (1 - p[i][turn]) % MOD;
                    }
                }
                for (Map.Entry<String, Long> c : x.entrySet()) {
                    String key = c.getKey();
                    long value = c.getValue();
                    for (int k = 0; k < (1 << n); k++) {
                        if ((k & s) != 0 && key.charAt(k) < Integer.bitCount(k)) {
                            key = key.substring(0, k) + (key.charAt(k) + 1) + key.substring(k + 1);
                        }
                    }
                    boolean add = true;
                    for (int k = 0; k < (1 << n); k++) {
                        if (key.charAt(k) + (n - turn - 1) < Integer.bitCount(k)) {
                            add = false;
                        }
                    }
                    if (add) {
                        admul(newx.computeIfAbsent(key, k -> 0L), mul, value);
                    }
                }
            }
            x = newx;
        }

        StringBuilder fin = new StringBuilder();
        for (int i = 0; i < (1 << n); i++) {
            fin.append(Integer.bitCount(i));
        }
        long ans = x.getOrDefault(fin.toString(), 0L);
        ans %= MOD;
        if (ans < 0) ans += MOD;
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        go(n);
    }
}
