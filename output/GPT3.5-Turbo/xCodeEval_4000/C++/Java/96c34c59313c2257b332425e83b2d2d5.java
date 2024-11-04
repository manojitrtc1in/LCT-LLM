import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static class Fraction implements Comparable<Fraction> {
        long a;
        long b;

        Fraction() {
            a = 0L;
            b = 1L;
        }

        Fraction(long c, long d) {
            long hoge = gcd(Math.abs(c), Math.abs(d));
            c /= hoge;
            d /= hoge;
            if (d < 0) {
                d *= -1;
                c *= -1;
            }
            a = c;
            b = d;
        }

        public int compareTo(Fraction rhs) {
            return Long.compare(a * rhs.b, rhs.a * b);
        }
    }

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
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
            Fraction Left = new Fraction(-a, b - w);
            Fraction Right = new Fraction(-a, b + w);
            Right.a *= -1;
            FI.add(new Pair<>(Left, Right));
        }
        Collections.sort(FI);
        int ans = 0;
        Compressor<Fraction> zip = new Compressor<>();
        for (Pair<Fraction, Fraction> p : FI) {
            p.second.a *= -1;
            zip.add(p.second);
        }
        zip.exec();
        SegmentTree<Integer> seg = new SegmentTree<>(2 * n, Integer::sum, 0);
        for (Pair<Fraction, Fraction> p : FI) {
            int hoge = zip.fetch();
            ans += seg.query(hoge, 2 * n);
            int tmp = seg.get(hoge);
            seg.update(hoge, tmp + 1);
        }
        System.out.println(ans);
    }

    static class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Compressor<A> {
        boolean isZipped;
        Map<A, Long> zipper;
        Map<Long, A> unzipper;
        Queue<A> fetcher;

        Compressor() {
            isZipped = false;
            zipper = new HashMap<>();
            unzipper = new HashMap<>();
            fetcher = new LinkedList<>();
        }

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

        long next(A now) {
            Map.Entry<A, Long> x = zipper.higherEntry(now);
            if (x == null) return zipper.size();
            return x.getValue();
        }

        long back(A now) {
            Map.Entry<A, Long> x = zipper.lowerEntry(now);
            if (x == null) return -1;
            return x.getValue();
        }
    }

    static class SegmentTree<T> {
        int sz;
        List<T> seg;
        BiFunction<T, T, T> f;
        T M1;

        SegmentTree(int n, BiFunction<T, T, T> f, T M1) {
            this.f = f;
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new ArrayList<>(2 * sz);
            for (int i = 0; i < 2 * sz; i++) seg.add(M1);
        }

        void set(int k, T x) {
            seg.set(k + sz, x);
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
            }
        }

        void update(int k, T x) {
            k += sz;
            seg.set(k, x);
            while (k >>= 1) {
                seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
            }
        }

        T query(int a, int b) {
            T L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) L = f.apply(L, seg.get(a++));
                if ((b & 1) == 1) R = f.apply(seg.get(--b), R);
            }
            return f.apply(L, R);
        }

        T get(int k) {
            return seg.get(k + sz);
        }
    }
}
