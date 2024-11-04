import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static class Fraction implements Comparable<Fraction> {
        long a;
        long b;

        public Fraction(long a, long b) {
            this.a = a;
            this.b = b;
        }

        public int compareTo(Fraction rhs) {
            return Long.compare(this.a * rhs.b, rhs.a * this.b);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());

        List<Pair<Fraction, Fraction>> FI = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            Fraction left = new Fraction(-a, b - w);
            Fraction right = new Fraction(-a, b + w);

            int hoge = gcd(Math.abs(left.a), Math.abs(left.b));
            left.a /= hoge;
            left.b /= hoge;

            hoge = gcd(Math.abs(right.a), Math.abs(right.b));
            right.a /= hoge;
            right.b /= hoge;

            if (left.b < 0) {
                left.a *= -1;
                left.b *= -1;
            }
            if (right.b < 0) {
                right.a *= -1;
                right.b *= -1;
            }
            right.a *= -1;
            FI.add(new Pair<>(left, right));
        }

        Collections.sort(FI);

        int ans = 0;
        Compressor<Fraction> zip = new Compressor<>();
        for (Pair<Fraction, Fraction> pair : FI) {
            pair.second.a *= -1;
            zip.add(pair.second);
        }
        zip.exec();

        SegmentTree<Integer> seg = new SegmentTree<>(2 * n, (a, b) -> a + b, 0);
        for (Pair<Fraction, Fraction> pair : FI) {
            int hoge = zip.fetch();
            ans += seg.query(hoge, 2 * n);
            int tmp = seg.get(hoge);
            seg.update(hoge, tmp + 1);
        }

        System.out.println(ans);
    }

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static class Pair<F, S> {
        F first;
        S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Compressor<T> {
        boolean id6;
        Map<T, Long> zipper;
        Map<Long, T> unzipper;
        Queue<T> fetcher;

        public Compressor() {
            id6 = false;
            zipper = new HashMap<>();
            unzipper = new HashMap<>();
            fetcher = new LinkedList<>();
        }

        public void add(T now) {
            assert id6 == false;
            zipper.put(now, 1L);
            fetcher.add(now);
        }

        public void exec() {
            assert id6 == false;
            int cnt = 0;
            for (Map.Entry<T, Long> entry : zipper.entrySet()) {
                entry.setValue((long) cnt);
                unzipper.put((long) cnt, entry.getKey());
                cnt++;
            }
            id6 = true;
        }

        public long fetch() {
            assert id6 == true;
            T hoge = fetcher.poll();
            return zipper.get(hoge);
        }

        public long zip(T now) {
            assert id6 == true;
            assert zipper.containsKey(now);
            return zipper.get(now);
        }

        public T unzip(long a) {
            assert id6 == true;
            assert a < unzipper.size();
            return unzipper.get(a);
        }

        public long next(T now) {
            Map.Entry<T, Long> x = zipper.higherEntry(now);
            if (x == null) return zipper.size();
            return x.getValue();
        }

        public long back(T now) {
            Map.Entry<T, Long> x = zipper.lowerEntry(now);
            if (x == null) return -1;
            return x.getValue();
        }
    }

    static class SegmentTree<T> {
        int sz;
        List<T> seg;
        BiFunction<T, T, T> f;
        T M1;

        public SegmentTree(int n, BiFunction<T, T, T> f, T M1) {
            this.f = f;
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new ArrayList<>(2 * sz + 1);
            for (int i = 0; i < 2 * sz + 1; i++) {
                seg.add(M1);
            }
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
                if ((a & 1) == 1) L = f.apply(L, seg.get(a++));
                if ((b & 1) == 1) R = f.apply(seg.get(--b), R);
            }
            return f.apply(L, R);
        }

        public T get(int k) {
            return seg.get(k + sz);
        }
    }
}
