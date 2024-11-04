import java.util.*;

public class 5355aea6f5deb85bed94fe6e7404f009xcodeeval_processed_4000.json {
    static long mod = 1000000007;

    static void inc(long[] x, long y) {
        x[0] += y;
        if (x[0] >= mod) x[0] -= mod;
    }

    static void dec(long[] x, long y) {
        x[0] -= y;
        if (x[0] < 0) x[0] += mod;
    }

    static void chmax(long[] x, long y) {
        if (y > x[0]) x[0] = y;
    }

    static void mulm(long[] x, long y) {
        x[0] *= y;
        if (x[0] >= mod) x[0] -= mod;
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    static long[] data;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long tot = 0;
        List<List<Long>> data = new ArrayList<>();

        for (long i = 1; i <= n; i++) {
            long k = sc.nextLong();
            long a = sc.nextLong();
            long x = sc.nextLong();
            long y = sc.nextLong();
            long m = sc.nextLong();
            tot += k;
            List<Long> tmp = new ArrayList<>();
            tmp.add(a);
            for (long j = 2; j <= k; j++) {
                tmp.add((tmp.get(tmp.size() - 1) * x + y) % m);
            }
            data.add(tmp);
        }

        TreeSet<Pair<Long, Pair<Long, Long>>> q = new TreeSet<>();
        for (long i = 0; i < n; i++) {
            q.add(new Pair<>(data.get((int) i).get(0), new Pair<>(i, 0)));
        }

        List<Long> ans = new ArrayList<>();
        List<Pair<Long, Long>> sol = new ArrayList<>();
        long p = 0;

        while (ans.size() < tot) {
            Pair<Long, Pair<Long, Long>> it = q.lower(new Pair<>(p, new Pair<>(-1L, -1L)));
            if (it == null) it = q.first();
            long v = it.first;
            p = v;
            Pair<Long, Long> o = it.second;
            ans.add(v);
            sol.add(new Pair<>(v, o.first + 1));
            q.remove(it);
            if (o.second + 1 < data.get(o.first).size()) {
                q.add(new Pair<>(data.get(o.first).get((int) (o.second + 1)), new Pair<>(o.first, o.second + 1)));
            }
        }

        long bad = 0;
        for (int i = 1; i < ans.size(); i++) {
            if (ans.get(i - 1) > ans.get(i)) bad++;
        }
        System.out.println(bad);
        if (tot <= 200000) {
            for (Pair<Long, Long> pair : sol) {
                System.out.println(pair.first + " " + pair.second);
            }
        }
    }

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
