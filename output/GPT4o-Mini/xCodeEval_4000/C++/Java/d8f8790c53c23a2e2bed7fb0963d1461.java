import java.util.*;
import java.util.function.Function;

public class d8f8790c53c23a2e2bed7fb0963d1461_nc {
    static final long MAX_MOD = 1000000007L;
    static final long GYAKU = 500000004L;
    static final long MOD = 998244353L;
    static final double eps = 1e-12;

    static class Fraction {
        long a;
        long b;

        public boolean lessThan(Fraction rhs) {
            return a * rhs.b < rhs.a * b;
        }
    }

    static class Compressor<A> {
        boolean isZipped = false;
        Map<A, Long> zipper = new HashMap<>();
        Map<Long, A> unzipper = new HashMap<>();
        Queue<A> fetcher = new LinkedList<>();

        public void add(A now) {
            assert !isZipped;
            zipper.put(now, 1L);
            fetcher.add(now);
        }

        public void exec() {
            assert !isZipped;
            long cnt = 0;
            for (Map.Entry<A, Long> entry : zipper.entrySet()) {
                entry.setValue(cnt);
                unzipper.put(cnt, entry.getKey());
                cnt++;
            }
            isZipped = true;
        }

        public long fetch() {
            assert isZipped;
            A hoge = fetcher.poll();
            return zipper.get(hoge);
        }

        public long zip(A now) {
            assert isZipped;
            assert zipper.containsKey(now);
            return zipper.get(now);
        }

        public A unzip(long a) {
            assert isZipped;
            assert a < unzipper.size();
            return unzipper.get(a);
        }
    }

    static class SegmentTree {
        int sz;
        int[] seg;
        Function<Integer, Integer> f;
        int M1;

        public SegmentTree(int n, Function<Integer, Integer> f, int M1) {
            this.f = f;
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new int[2 * sz + 1];
            Arrays.fill(seg, M1);
        }

        public void set(int k, int x) {
            seg[k + sz] = x;
        }

        public void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg[k] = f.apply(seg[2 * k + 0]) + seg[2 * k + 1];
            }
        }

        public void update(int k, int x) {
            k += sz;
            seg[k] = x;
            while (k >>= 1) {
                seg[k] = f.apply(seg[2 * k + 0]) + seg[2 * k + 1];
            }
        }

        public int query(int a, int b) {
            int L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if (a % 2 == 1) L += seg[a++];
                if (b % 2 == 1) R += seg[--b];
            }
            return L + R;
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
            Fraction Left = new Fraction();
            Left.a = -a;
            Left.b = b - w;

            Fraction Right = new Fraction();
            Right.a = -a;
            Right.b = b + w;

            long gcdLeft = gcd(Math.abs(Left.a), Math.abs(Left.b));
            Left.a /= gcdLeft;
            Left.b /= gcdLeft;

            long gcdRight = gcd(Math.abs(Right.a), Math.abs(Right.b));
            Right.a /= gcdRight;
            Right.b /= gcdRight;

            if (Left.b < 0) {
                Left.a *= -1;
                Left.b *= -1;
            }
            if (Right.b < 0) {
                Right.a *= -1;
                Right.b *= -1;
            }
            Right.a *= -1;
            FI.add(new Pair<>(Left, Right));
        }

        FI.sort(Comparator.comparing(pair -> pair.first.a * pair.first.b));

        long ans = 0;
        Compressor<Fraction> zip = new Compressor<>();
        for (Pair<Fraction, Fraction> pair : FI) {
            pair.second.a *= -1;
            zip.add(pair.second);
        }

        SegmentTree seg = new SegmentTree(2 * (int) n, a -> a, 0);
        zip.exec();
        for (Pair<Fraction, Fraction> pair : FI) {
            long hoge = zip.fetch();
            ans += seg.query((int) hoge, 2 * (int) n);
            int tmp = seg.seg[(int) hoge];
            seg.update((int) hoge, tmp + 1);
        }
        System.out.println(ans);
    }

    public static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        solve();
    }

    static class Pair<A, B> {
        A first;
        B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
