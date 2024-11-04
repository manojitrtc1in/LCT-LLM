import java.util.*;
import java.io.*;

class Main {
    static final long MOD = 1000000007;

    static class Ring {
        long value;

        Ring() {
            this.value = 0;
        }

        Ring(int _value) {
            this.value = _value % MOD;
        }

        Ring(long _value) {
            this.value = _value % MOD;
        }

        Ring pow(long p) {
            Ring r = new Ring(1);
            Ring x = new Ring(value);
            while (p > 0) {
                if ((p & 1) == 1) r = r.mul(x);
                x = x.mul(x);
                p >>= 1;
            }
            return r;
        }

        Ring inv() {
            return pow(MOD - 2);
        }

        Ring mul(Ring b) {
            value = (value * b.value) % MOD;
            return this;
        }

        static Ring multiply(Ring a, Ring b) {
            return a.mul(b);
        }

        Ring add(Ring b) {
            value = (value + b.value) % MOD;
            return this;
        }

        static Ring add(Ring a, Ring b) {
            return a.add(b);
        }

        Ring sub(Ring b) {
            value = (value - b.value + MOD) % MOD;
            return this;
        }

        static Ring subtract(Ring a, Ring b) {
            return a.sub(b);
        }

        Ring div(Ring b) {
            return this.mul(b.inv());
        }

        static Ring divide(Ring a, Ring b) {
            return a.div(b);
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }
    }

    static List<Ring> fact = new ArrayList<>(Collections.singletonList(new Ring(1)));

    static Ring binom(int n, int k) {
        if (k > n) return new Ring(0);
        return divide(fact.get(n), multiply(fact.get(n - k), fact.get(k)));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n + 100; i++) {
            fact.add(multiply(fact.get(fact.size() - 1), new Ring(i + 1)));
        }
        List<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            v.add(scanner.nextInt());
        }

        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= v.get(i); j++) {
                while (v.get(i) % j == 0 && (v.get(i) / j) % j == 0) {
                    v.set(i, v.get(i) / j);
                    v.set(i, v.get(i) / j);
                }
            }
        }

        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : v) {
            cnt.put(x, cnt.getOrDefault(x, 0) + 1);
        }

        List<Integer> c = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
            c.add(entry.getValue());
        }

        List<Ring> dp = new ArrayList<>(Collections.nCopies(n + 10, new Ring(0)));
        dp.set(0, new Ring(1));

        for (int x : c) {
            List<Ring> ndp = new ArrayList<>(Collections.nCopies(n + 10, new Ring(0)));
            for (int i = 0; i < dp.size(); i++) {
                if (dp.get(i).value != 0) {
                    for (int j = 0; j < x; j++) {
                        int dist = x - j;
                        ndp.set(i + dist, add(ndp.get(i + dist), multiply(dp.get(i), multiply(binom(x - 1, j), binom(i + dist, dist)))));
                    }
                }
            }
            dp = ndp;
        }

        int conds = n - c.size();
        Ring finalResult = new Ring(0);
        Ring sign = new Ring(1);
        for (int i = 0; i <= conds; i++) {
            finalResult = add(finalResult, multiply(sign, dp.get(n - i)));
            sign = new Ring(-1).mul(sign);
        }
        for (int x : c) {
            finalResult = multiply(finalResult, fact.get(x));
        }
        System.out.println(finalResult);
    }
}
