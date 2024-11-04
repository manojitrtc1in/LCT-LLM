import java.util.*;
import java.util.function.Function;

class Fraction {
    long a;
    long b;

    public boolean lessThan(Fraction rhs) {
        return a * rhs.b < rhs.a * b;
    }
}

class Compressor<A> {
    boolean id6 = false;
    Map<A, Long> zipper = new HashMap<>();
    Map<Long, A> unzipper = new HashMap<>();
    Queue<A> fetcher = new LinkedList<>();

    public void add(A now) {
        assert !id6;
        zipper.put(now, 1L);
        fetcher.add(now);
    }

    public void exec() {
        assert !id6;
        long cnt = 0;
        for (Map.Entry<A, Long> entry : zipper.entrySet()) {
            entry.setValue(cnt);
            unzipper.put(cnt, entry.getKey());
            cnt++;
        }
        id6 = true;
    }

    public long fetch() {
        assert id6;
        A hoge = fetcher.poll();
        return zipper.get(hoge);
    }

    public long zip(A now) {
        assert id6;
        assert zipper.containsKey(now);
        return zipper.get(now);
    }

    public A unzip(long a) {
        assert id6;
        assert a < unzipper.size();
        return unzipper.get(a);
    }

    public long next(A now) {
        var x = zipper.entrySet().stream().filter(e -> e.getKey().equals(now)).findFirst();
        if (x.isEmpty()) return zipper.size();
        return x.get().getValue();
    }

    public long back(A now) {
        var x = zipper.entrySet().stream().filter(e -> e.getKey().equals(now)).findFirst();
        if (x.isEmpty()) return -1;
        return x.get().getValue();
    }
}

class SegmentTree<T> {
    private final Function<T, T> f;
    private final T M1;
    private final int sz;
    private final List<T> seg;

    public SegmentTree(int n, Function<T, T> f, T M1) {
        this.f = f;
        this.M1 = M1;
        sz = 1;
        while (sz < n) sz <<= 1;
        seg = new ArrayList<>(Collections.nCopies(2 * sz + 1, M1));
    }

    public void set(int k, T x) {
        seg.set(k + sz, x);
    }

    public void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
        }
    }

    public void update(int k, T x) {
        k += sz;
        seg.set(k, x);
        while (k >>= 1) {
            seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
        }
    }

    public T query(int a, int b) {
        T L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if ((a & 1) != 0) L = f.apply(L, seg.get(a++));
            if ((b & 1) != 0) R = f.apply(seg.get(--b), R);
        }
        return f.apply(L, R);
    }

    public T get(int k) {
        return seg.get(k + sz);
    }
}

public class d8f8790c53c23a2e2bed7fb0963d1461xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        init();
        solve();
    }

    static void init() {
        // Set up any necessary configurations
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int w = scanner.nextInt();
        List<Pair<Fraction, Fraction>> FI = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            Fraction Left = new Fraction();
            Left.a = -a;
            Left.b = b - w;

            Fraction Right = new Fraction();
            Right.a = -a;
            Right.b = b + w;

            simplifyFraction(Left);
            simplifyFraction(Right);

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

        FI.sort(Comparator.comparing(pair -> pair.first.a * pair.second.b));

        int ans = 0;
        Compressor<Fraction> zip = new Compressor<>();
        for (Pair<Fraction, Fraction> pair : FI) {
            pair.second.a *= -1;
            zip.add(pair.second);
        }

        SegmentTree<Integer> seg = new SegmentTree<>(2 * n, Integer::sum, 0);
        zip.exec();

        for (Pair<Fraction, Fraction> pair : FI) {
            int hoge = (int) zip.fetch();
            ans += seg.query(hoge, 2 * n);
            int tmp = seg.get(hoge);
            seg.update(hoge, tmp + 1);
        }

        System.out.println(ans);
    }

    static void simplifyFraction(Fraction fraction) {
        long gcd = gcd(Math.abs(fraction.a), Math.abs(fraction.b));
        fraction.a /= gcd;
        fraction.b /= gcd;
    }

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}
