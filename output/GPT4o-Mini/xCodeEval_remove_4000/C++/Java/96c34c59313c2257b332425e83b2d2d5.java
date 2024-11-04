import java.util.*;
import java.util.function.Function;

class Fraction {
    long a;
    long b;

    public Fraction() {
        this.a = 0;
        this.b = 1;
    }

    public Fraction(long c, long d) {
        int gcdValue = gcd(Math.abs(c), Math.abs(d));
        c /= gcdValue;
        d /= gcdValue;
        if (d < 0) {
            d *= -1;
            c *= -1;
        }
        this.a = c;
        this.b = d;
    }

    public boolean lessThan(Fraction rhs) {
        return a * rhs.b < rhs.a * b;
    }

    private long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
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
        int cnt = 0;
        for (Map.Entry<A, Long> entry : zipper.entrySet()) {
            entry.setValue((long) cnt);
            unzipper.put((long) cnt, entry.getKey());
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
}

class SegmentTree {
    int sz;
    int[] seg;
    final Function<Integer, Integer> f;
    final int M1;

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
            if (a & 1) L += seg[a++];
            if (b & 1) R += seg[--b];
        }
        return L + R;
    }

    public int get(int k) {
        return seg[k + sz];
    }
}

public class 96c34c59313c2257b332425e83b2d2d5xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        init();
        solve();
    }

    static void init() {
        Scanner scanner = new Scanner(System.in);
        System.out.printf("%.200f%n", 0.0);
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int w = scanner.nextInt();
        List<Pair<Fraction, Fraction>> FI = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            Fraction Left = new Fraction(-a, b - w);
            Fraction Right = new Fraction(-a, b + w);
            Right.a *= -1;
            FI.add(new Pair<>(Left, Right));
        }

        FI.sort(Comparator.comparing(pair -> pair.first.a));

        int ans = 0;
        Compressor<Fraction> zip = new Compressor<>();
        for (Pair<Fraction, Fraction> pair : FI) {
            pair.second.a *= -1;
            zip.add(pair.second);
        }

        SegmentTree seg = new SegmentTree(2 * n, (a, b) -> a + b, 0);
        zip.exec();

        for (Pair<Fraction, Fraction> pair : FI) {
            int hoge = (int) zip.fetch();
            ans += seg.query(hoge, 2 * n);
            int tmp = seg.get(hoge);
            seg.update(hoge, tmp + 1);
        }

        System.out.println(ans);
    }
}

class Pair<A, B> {
    A first;
    B second;

    public Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }
}
