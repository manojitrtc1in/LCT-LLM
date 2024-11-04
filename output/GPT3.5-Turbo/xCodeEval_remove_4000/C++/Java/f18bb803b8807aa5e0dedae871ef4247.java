import java.util.*;

class Main {
    static int n;
    static double[] x, y;
    static int w;
    static Map<Double, Integer> cnt;
    static double[] as;
    static int cnta;
    static Pair<Double, Integer>[] bs;
    static B1T bit;

    static class B1T {
        long[] bit;
        final int n = 100007;

        B1T() {
            bit = new long[n];
        }

        void add(int djg, int x) {
            while (djg <= n) {
                bit[djg] += x;
                djg += (djg & -djg);
            }
        }

        long sum(int djg) {
            long id0 = 0;
            while (djg > 0) {
                id0 += bit[djg];
                djg -= (djg & -djg);
            }
            return id0;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        w = scanner.nextInt();
        x = new double[n];
        y = new double[n];
        cnt = new HashMap<>();
        as = new double[n];
        bs = new Pair[n];
        bit = new B1T();

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            x[i] = 1.00 * a / (b + w);
            y[i] = 1.00 * a / (b - w);
            cnt.put(y[i], cnt.getOrDefault(y[i], 0) + 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cnt.get(y[i]) - 1;
        }
        ans /= 2;

        for (int i = 0; i < n; i++) {
            as[i] = x[i];
        }
        Arrays.sort(as);
        cnta = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || as[i] != as[i - 1]) {
                as[cnta++] = as[i];
            }
        }

        for (int i = 0; i < n; i++) {
            bs[i] = new Pair<>(y[i], i);
        }
        Arrays.sort(bs, (a, b) -> Double.compare(a.getKey(), b.getKey()));

        int now = 0;
        for (int i = 0; i < n; i++) {
            while (bs[now].getKey() < bs[i].getKey()) {
                int id = Arrays.binarySearch(as, 0, cnta, x[bs[now].getValue()]);
                bit.add(100006 - id, 1);
                now++;
            }
            int id = Arrays.binarySearch(as, 0, cnta, x[bs[i].getValue()]);
            ans += bit.sum(100006 - id);
        }

        System.out.println(ans);
    }
}

class Pair<K, V> {
    private K key;
    private V value;

    Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }
}
