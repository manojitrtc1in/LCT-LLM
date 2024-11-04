import java.util.*;
import java.io.*;

class Main {
    static final int MOD = (int) 1e9 + 7;

    static class Ring {
        int value;

        Ring() {
            value = 0;
        }

        Ring(int _value) {
            value = _value;
            value = floorMod(value, MOD);
        }

        Ring(long _value) {
            value = (int) _value;
            value = floorMod(value, MOD);
        }

        Ring pow(long p) {
            Ring r = new Ring(1);
            Ring x = new Ring();
            x.value = value;
            while (p > 0) {
                if ((p & 1) == 1)
                    r.multiply(x);
                x.multiply(x);
                p /= 2;
            }
            return r;
        }

        Ring inv() {
            return pow(MOD - 2);
        }

        void multiply(Ring b) {
            value = (int) ((long) value * b.value % MOD);
        }

        Ring multiply(Ring a, Ring b) {
            Ring res = new Ring();
            res.value = (int) ((long) a.value * b.value % MOD);
            return res;
        }

        void add(Ring b) {
            value += b.value;
            if (value >= MOD)
                value -= MOD;
        }

        Ring add(Ring a, Ring b) {
            Ring res = new Ring();
            res.value = a.value + b.value;
            if (res.value >= MOD)
                res.value -= MOD;
            return res;
        }

        void subtract(Ring b) {
            value -= b.value;
            if (value < 0)
                value += MOD;
        }

        Ring subtract(Ring a, Ring b) {
            Ring res = new Ring();
            res.value = a.value - b.value;
            if (res.value < 0)
                res.value += MOD;
            return res;
        }

        void divide(Ring b) {
            multiply(b.inv());
        }

        Ring divide(Ring a, Ring b) {
            Ring res = new Ring();
            res.value = (int) ((long) a.value * b.inv().value % MOD);
            return res;
        }

        boolean equals(Ring b) {
            return value == b.value;
        }

        boolean notEquals(Ring b) {
            return value != b.value;
        }

        void print() {
            System.out.print(value);
        }

        int floorMod(int a, int b) {
            a %= b;
            if (a < 0)
                a += b;
            return a;
        }
    }

    static List<Ring> fact = new ArrayList<>();

    static Ring binom(int n, int k) {
        if (k > n)
            return new Ring(0);
        return divide(fact.get(n), multiply(fact.get(n - k), fact.get(k)));
    }

    static Ring divide(Ring a, Ring b) {
        return new Ring().divide(a, b);
    }

    static Ring multiply(Ring a, Ring b) {
        return new Ring().multiply(a, b);
    }

    static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n + 100; i++) {
            if (i == 0)
                fact.add(new Ring(1));
            else
                fact.add(multiply(fact.get(i - 1), new Ring(i + 1)));
        }
        String[] vStr = br.readLine().split(" ");
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(vStr[i]);
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
        List<Integer> c = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
            c.add(entry.getValue());
        }
        List<Ring> dp = new ArrayList<>();
        for (int i = 0; i < n + 10; i++) {
            dp.add(new Ring());
        }
        dp.set(0, new Ring(1));
        for (int x : c) {
            List<Ring> ndp = new ArrayList<>();
            for (int i = 0; i < dp.size(); i++) {
                ndp.add(new Ring());
            }
            for (int i = 0; i < dp.size(); i++) {
                if (dp.get(i).value != 0) {
                    for (int j = 0; j < x; j++) {
                        int dist = x - j;
                        ndp.set(i + dist, add(ndp.get(i + dist),
                                multiply(multiply(dp.get(i), binom(x - 1, j)), binom(i + dist, dist))));
                    }
                }
            }
            dp = ndp;
        }
        int conds = n - c.size();
        Ring finalVal = new Ring();
        Ring sign = new Ring(1);
        for (int i = 0; i <= conds; i++) {
            finalVal = add(finalVal, multiply(sign, dp.get(n - i)));
            sign.subtract(new Ring(0));
            sign.subtract(new Ring(1));
        }
        for (int x : c) {
            finalVal.multiply(fact.get(x));
        }
        finalVal.print();
    }

    static Ring add(Ring a, Ring b) {
        return new Ring().add(a, b);
    }
}
