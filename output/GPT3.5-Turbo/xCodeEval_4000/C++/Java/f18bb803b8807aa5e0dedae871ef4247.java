import java.util.*;

class Main {
    static int n;
    static double[] x, y;
    static int w;
    static Map<Double, Integer> cnt;
    static double[] as;
    static int cnta;
    static Pair[] bs;
    static BIT bit;

    static class BIT {
        static final int N = 100007;
        long[] bit = new long[N];

        void add(int djg, int x) {
            while (djg <= N) {
                bit[djg] += x;
                djg += (djg & -djg);
            }
        }

        long sum(int djg) {
            long s0m = 0;
            while (djg > 0) {
                s0m += bit[djg];
                djg -= (djg & -djg);
            }
            return s0m;
        }
    }

    static class Pair implements Comparable<Pair> {
        double first;
        int second;

        Pair(double first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair p) {
            if (this.first < p.first) {
                return -1;
            } else if (this.first > p.first) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        w = sc.nextInt();
        x = new double[n];
        y = new double[n];
        cnt = new HashMap<>();
        as = new double[n];
        bs = new Pair[n];
        bit = new BIT();

        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
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
            bs[i] = new Pair(y[i], i);
        }
        Arrays.sort(bs);

        int now = 0;
        for (int i = 0; i < n; i++) {
            while (bs[now].first < bs[i].first) {
                int id = Arrays.binarySearch(as, 0, cnta, x[bs[now].second]);
                bit.add(100006 - id, 1);
                now++;
            }
            int id = Arrays.binarySearch(as, 0, cnta, x[bs[i].second]);
            ans += bit.sum(100006 - id);
        }

        System.out.println(ans);
    }
}
