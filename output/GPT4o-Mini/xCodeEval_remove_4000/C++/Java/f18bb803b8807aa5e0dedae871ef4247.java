import java.util.*;

public class f18bb803b8807aa5e0dedae871ef4247xcodeeval_processed_4000.json {
    static int n;
    static long[] bit = new long[100007];
    static final int MAX_N = 100007;
    static double[] x = new double[MAX_N], y = new double[MAX_N];
    static int w;
    static Map<Double, Integer> cnt = new HashMap<>();
    static double[] as = new double[MAX_N];
    static int cnta;
    static Pair[] bs = new Pair[MAX_N];

    static class Pair {
        double first;
        int second;

        Pair(double first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static void add(int djg, int x) {
        while (djg <= MAX_N) {
            bit[djg] += x;
            djg += (djg & -djg);
        }
    }

    static long sum(int djg) {
        long id0 = 0;
        while (djg > 0) {
            id0 += bit[djg];
            djg -= (djg & -djg);
        }
        return id0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        w = scanner.nextInt();
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
        Arrays.sort(as, 0, n);
        cnta = (int) Arrays.stream(as).distinct().count();
        for (int i = 0; i < n; i++) {
            bs[i] = new Pair(y[i], i);
        }
        Arrays.sort(bs, 0, n, Comparator.comparingDouble(p -> p.first));
        int now = 0;
        for (int i = 0; i < n; i++) {
            while (now < n && bs[now].first < bs[i].first) {
                int id = Arrays.binarySearch(as, 0, cnta, x[(int) bs[now].second]);
                if (id < 0) id = -(id + 1);
                add(100006 - id, 1);
                now++;
            }
            int id = Arrays.binarySearch(as, 0, cnta, x[(int) bs[i].second]);
            if (id < 0) id = -(id + 1);
            ans += sum(100006 - id);
        }

        System.out.println(ans);
        System.out.println(ans);
    }
}
