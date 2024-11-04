import java.util.*;

public class 58b20913306d6d2e2f6431690fba39b1_nc {
    static long mod = (long) 1e9 + 7;

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    static long modpow(long a, long n, long temp) {
        long res = 1, y = a;
        while (n > 0) {
            if ((n & 1) != 0) res = (res * y) % temp;
            y = (y * y) % temp;
            n /= 2;
        }
        return res % temp;
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

    static class Pair<A, B> implements Comparable<Pair<A, B>> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair<A, B> o) {
            return ((Comparable<A>) this.first).compareTo(o.first);
        }
    }
}
