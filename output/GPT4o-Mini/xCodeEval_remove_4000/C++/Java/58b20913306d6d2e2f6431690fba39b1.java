import java.util.*;

public class 58b20913306d6d2e2f6431690fba39b1xcodeeval_processed_4000.json {
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

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    static long[] modpow(long a, long n, long temp) {
        long[] res = {1}, y = {a};
        while (n > 0) {
            if ((n & 1) == 1) res[0] = (res[0] * y[0]) % temp;
            y[0] = (y[0] * y[0]) % temp;
            n /= 2;
        }
        return new long[]{res[0] % temp};
    }

    static long cbit(long n) {
        long k = 0;
        while (n != 0) {
            n &= (n - 1);
            k++;
        }
        return k;
    }

    static long nbit(long n) {
        long k = 0;
        while (n != 0) {
            n /= 2;
            k++;
        }
        return k;
    }

    static int sgn(long x) {
        return x < 0 ? -1 : (x == 0 ? 0 : 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long tot = 0;
        List<List<Long>> data = new ArrayList<>();
        
        for (long i = 1; i <= n; i++) {
            long k = scanner.nextLong();
            long a = scanner.nextLong();
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            long m = scanner.nextLong();
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
            Iterator<Pair<Long, Pair<Long, Long>>> it = q.lowerBound(new Pair<>(p, new Pair<>(-1L, -1L)));
            if (!it.hasNext()) it = q.iterator();
            Pair<Long, Pair<Long, Long>> current = it.next();
            long v = current.first;
            p = v;
            Pair<Long, Long> o = current.second;
            ans.add(v);
            sol.add(new Pair<>(v, o.first + 1));
            q.remove(current);
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
