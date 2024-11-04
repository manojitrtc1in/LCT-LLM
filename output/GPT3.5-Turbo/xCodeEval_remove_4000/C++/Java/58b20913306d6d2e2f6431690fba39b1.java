import java.util.*;

class Main {
    static class Pair {
        long first;
        long second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple {
        long first;
        Pair second;

        Triple(long first, Pair second) {
            this.first = first;
            this.second = second;
        }
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    static long modpow(long a, long n, long temp) {
        long res = 1;
        long y = a;
        while (n > 0) {
            if ((n & 1) != 0) {
                res = (res * y) % temp;
            }
            y = (y * y) % temp;
            n /= 2;
        }
        return res % temp;
    }

    static long ison(long mask, long pos) {
        return (mask & (1 << pos));
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

    static long mod = 1000000007;

    static int sgn(long x) {
        return x < 0 ? -1 : (x != 0 ? 1 : 0);
    }

    static double eps = 1e-7;
    static double pi = Math.acos(-1.0);

    static void inc(long[] x, long y) {
        x[0] += y;
        if (x[0] >= mod) {
            x[0] -= mod;
        }
    }

    static void dec(long[] x, long y) {
        x[0] -= y;
        if (x[0] < 0) {
            x[0] += mod;
        }
    }

    static void chmax(long[] x, long y) {
        if (y > x[0]) {
            x[0] = y;
        }
    }

    static void mulm(long[] x, long y) {
        x[0] *= y;
        if (x[0] >= mod) {
            x[0] -= mod;
        }
    }

    static long xo(long i) {
        if ((i & 3) == 0) {
            return i;
        }
        if ((i & 3) == 1) {
            return 1;
        }
        if ((i & 3) == 2) {
            return i + 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long tot = 0;
        List<List<Long>> data = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            long k = sc.nextLong();
            long a = sc.nextLong();
            long x = sc.nextLong();
            long y = sc.nextLong();
            long m = sc.nextLong();
            tot += k;
            List<Long> tmp = new ArrayList<>();
            tmp.add(a);
            for (int j = 2; j <= k; j++) {
                tmp.add((tmp.get(tmp.size() - 1) * x + y) % m);
            }
            data.add(tmp);
        }
        Set<Triple> q = new TreeSet<>(Comparator.comparingLong((Triple t) -> t.first).thenComparingLong((Triple t) -> t.second.first).thenComparingLong((Triple t) -> t.second.second));
        for (int i = 0; i < n; i++) {
            q.add(new Triple(data.get(i).get(0), new Pair(i, 0)));
        }
        List<Long> ans = new ArrayList<>();
        List<Pair> sol = new ArrayList<>();
        long p = 0;
        while (ans.size() < tot) {
            Triple it = q.stream().filter(t -> t.first >= p).findFirst().orElse(q.first());
            long v = it.first;
            p = v;
            Pair o = it.second;
            ans.add(v);
            sol.add(new Pair(v, o.first + 1));
            q.remove(it);
            if (o.second + 1 < data.get(o.first).size()) {
                q.add(new Triple(data.get(o.first).get(o.second + 1), new Pair(o.first, o.second + 1)));
            }
        }
        long bad = 0;
        for (int i = 1; i < ans.size(); i++) {
            if (ans.get(i - 1) > ans.get(i)) {
                bad++;
            }
        }
        System.out.println(bad);
        if (tot <= 200000) {
            for (int i = 0; i < sol.size(); i++) {
                System.out.println(sol.get(i).first + " " + sol.get(i).second);
            }
        }
    }
}
