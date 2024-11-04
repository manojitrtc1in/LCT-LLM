import java.util.*;

public class f18bb803b8807aa5e0dedae871ef4247_nc {
    static final int MAXN = 100007;
    static long[] bit = new long[MAXN];
    static double[] x = new double[MAXN];
    static double[] y = new double[MAXN];
    static double[] as = new double[MAXN];
    static int cnta;
    static Pair[] bs = new Pair[MAXN];
    static Map<Double, Integer> cnt = new HashMap<>();

    static class Pair implements Comparable<Pair> {
        double first;
        int second;

        Pair(double first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return Double.compare(this.first, o.first);
        }
    }

    static void add(int djg, int x) {
        while (djg < MAXN) {
            bit[djg] += x;
            djg += (djg & -djg);
        }
    }

    static long sum(int djg) {
        long s0m = 0;
        while (djg > 0) {
            s0m += bit[djg];
            djg -= (djg & -djg);
        }
        return s0m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int w = scanner.nextInt();
        
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            x[i] = 1.0 * a / (b + w);
            y[i] = 1.0 * a / (b - w);
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
        Arrays.sort(bs, 0, n);

        int now = 0;
        for (int i = 0; i < n; i++) {
            while (now < n && bs[now].first < bs[i].first) {
                int id = Arrays.binarySearch(as, 0, cnta, x[(int) bs[now].second]);
                if (id < 0) id = -id - 1;
                add(MAXN - 1 - id, 1);
                now++;
            }
            int id = Arrays.binarySearch(as, 0, cnta, x[(int) bs[i].second]);
            if (id < 0) id = -id - 1;
            ans += sum(MAXN - 1 - id);
        }

        System.out.println(ans);
    }
}
