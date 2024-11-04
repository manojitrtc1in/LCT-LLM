import java.util.*;
import java.util.function.*;
import java.io.*;

public class 96c34c59313c2257b332425e83b2d2d5_nc {
    static final long MAX_MOD = 1000000007L;
    static final long GYAKU = 500000004L;
    static final long MOD = 998244353L;
    static final double eps = 1e-12;

    static class Fraction {
        long a;
        long b;

        Fraction() {
            this.a = 0;
            this.b = 1;
        }

        Fraction(long c, long d) {
            long gcd = gcd(Math.abs(c), Math.abs(d));
            c /= gcd;
            d /= gcd;
            if (d < 0) {
                d *= -1;
                c *= -1;
            }
            this.a = c;
            this.b = d;
        }

        boolean lessThan(Fraction rhs) {
            return a * rhs.b < rhs.a * b;
        }
    }

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static class Compressor<A> {
        boolean isZipped = false;
        Map<A, Long> zipper = new HashMap<>();
        Map<Long, A> unzipper = new HashMap<>();
        Queue<A> fetcher = new LinkedList<>();

        void add(A now) {
            assert !isZipped;
            zipper.put(now, 1L);
            fetcher.add(now);
        }

        void exec() {
            assert !isZipped;
            long cnt = 0;
            for (Map.Entry<A, Long> entry : zipper.entrySet()) {
                entry.setValue(cnt);
                unzipper.put(cnt, entry.getKey());
                cnt++;
            }
            isZipped = true;
        }

        long fetch() {
            assert isZipped;
            A hoge = fetcher.poll();
            return zipper.get(hoge);
        }

        long zip(A now) {
            assert isZipped;
            assert zipper.containsKey(now);
            return zipper.get(now);
        }

        A unzip(long a) {
            assert isZipped;
            assert a < unzipper.size();
            return unzipper.get(a);
        }
    }

    static class SegmentTree {
        int sz;
        int[] seg;
        final BiFunction<Integer, Integer, Integer> f;
        final int M1;

        SegmentTree(int n, BiFunction<Integer, Integer, Integer> f, int M1) {
            this.f = f;
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new int[2 * sz + 1];
            Arrays.fill(seg, M1);
        }

        void set(int k, int x) {
            seg[k + sz] = x;
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg[k] = f.apply(seg[2 * k], seg[2 * k + 1]);
            }
        }

        void update(int k, int x) {
            k += sz;
            seg[k] = x;
            while (k >>= 1) {
                seg[k] = f.apply(seg[2 * k], seg[2 * k + 1]);
            }
        }

        int query(int a, int b) {
            int L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if (a % 2 == 1) L = f.apply(L, seg[a++]);
                if (b % 2 == 1) R = f.apply(seg[--b], R);
            }
            return f.apply(L, R);
        }
    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long w = scanner.nextLong();
        List<Pair<Fraction, Fraction>> FI = new ArrayList<>();

        for (long i = 0; i < n; i++) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();
            Fraction Left = new Fraction(-a, b - w);
            Fraction Right = new Fraction(-a, b + w);
            Right.a *= -1;
            FI.add(new Pair<>(Left, Right));
        }

        FI.sort(Comparator.comparing(pair -> pair.getKey().a * pair.getValue().b));

        long ans = 0;
        Compressor<Fraction> zip = new Compressor<>();
        for (Pair<Fraction, Fraction> pair : FI) {
            pair.getValue().a *= -1;
            zip.add(pair.getValue());
        }

        SegmentTree seg = new SegmentTree(2 * (int) n, Integer::sum, 0);
        zip.exec();

        for (Pair<Fraction, Fraction> pair : FI) {
            long hoge = zip.fetch();
            ans += seg.query((int) hoge, 2 * (int) n);
            int tmp = seg.query((int) hoge, (int) hoge + 1);
            seg.update((int) hoge, tmp + 1);
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        solve();
    }

    static class Pair<K, V> {
        private final K key;
        private final V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}
