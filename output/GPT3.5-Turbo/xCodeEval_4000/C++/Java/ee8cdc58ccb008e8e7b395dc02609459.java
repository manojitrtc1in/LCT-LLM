import java.util.*;

class Main {
    static final int MOD = (int) 1e9 + 7;

    static class Ring {
        int value;

        Ring(int value) {
            this.value = value;
            this.value = floorMod(this.value, MOD);
        }

        Ring pow(int p) {
            Ring r = new Ring(1);
            Ring x = new Ring(this.value);
            while (p > 0) {
                if ((p & 1) == 1) {
                    r = r.multiply(x);
                }
                x = x.multiply(x);
                p /= 2;
            }
            return r;
        }

        Ring inverse() {
            return pow(MOD - 2);
        }

        void multiplyEquals(Ring b) {
            this.value = (int) ((long) this.value * b.value % MOD);
        }

        Ring multiply(Ring b) {
            Ring result = new Ring(this.value);
            result.multiplyEquals(b);
            return result;
        }

        void addEquals(Ring b) {
            this.value += b.value;
            if (this.value >= MOD) {
                this.value -= MOD;
            }
        }

        Ring add(Ring b) {
            Ring result = new Ring(this.value);
            result.addEquals(b);
            return result;
        }

        void subtractEquals(Ring b) {
            this.value -= b.value;
            if (this.value < 0) {
                this.value += MOD;
            }
        }

        Ring subtract(Ring b) {
            Ring result = new Ring(this.value);
            result.subtractEquals(b);
            return result;
        }

        void divideEquals(Ring b) {
            multiplyEquals(b.inverse());
        }

        Ring divide(Ring b) {
            Ring result = new Ring(this.value);
            result.divideEquals(b);
            return result;
        }

        boolean equals(Ring b) {
            return this.value == b.value;
        }

        boolean notEquals(Ring b) {
            return this.value != b.value;
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }

        private int floorMod(int a, int b) {
            a %= b;
            if (a < 0) {
                a += b;
            }
            return a;
        }
    }

    static List<Ring> fact = new ArrayList<>();

    static Ring binom(int n, int k) {
        if (k > n) {
            return new Ring(0);
        }
        return fact.get(n).divide(fact.get(n - k).multiply(fact.get(k)));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n + 100; i++) {
            if (i == 0) {
                fact.add(new Ring(1));
            } else {
                fact.add(fact.get(i - 1).multiply(new Ring(i)));
            }
        }
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= v[i]; j++) {
                while (v[i] % j == 0 && (v[i] / j) % j == 0) {
                    v[i] /= j;
                    v[i] /= j;
                }
            }
        }
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : v) {
            cnt.put(x, cnt.getOrDefault(x, 0) + 1);
        }
        List<Integer> c = new ArrayList<>(cnt.values());
        List<Ring> dp = new ArrayList<>();
        dp.add(new Ring(1));
        for (int x : c) {
            List<Ring> ndp = new ArrayList<>(Collections.nCopies(n + 10, new Ring(0)));
            for (int i = 0; i < dp.size(); i++) {
                if (dp.get(i).value != 0) {
                    for (int j = 0; j < x; j++) {
                        int dist = x - j;
                        ndp.set(i + dist, ndp.get(i + dist).add(dp.get(i).multiply(binom(x - 1, j)).multiply(binom(i + dist, dist))));
                    }
                }
            }
            dp = ndp;
        }
        int conds = n - c.size();
        Ring finalResult = new Ring(0);
        Ring sign = new Ring(1);
        for (int i = 0; i <= conds; i++) {
            finalResult = finalResult.add(sign.multiply(dp.get(n - i)));
            sign = sign.multiply(new Ring(-1));
        }
        for (int x : c) {
            finalResult = finalResult.multiply(fact.get(x));
        }
        System.out.println(finalResult);
    }
}
