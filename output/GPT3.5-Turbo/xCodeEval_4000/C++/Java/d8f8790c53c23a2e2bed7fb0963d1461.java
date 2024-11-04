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

        public boolean compareTo(Fraction rhs) {
            return this.a * rhs.b < rhs.a * this.b;
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

        Collections.sort(FI, new Comparator<Pair<Fraction, Fraction>>() {
            @Override
            public int compare(Pair<Fraction, Fraction> p1, Pair<Fraction, Fraction> p2) {
                return p1.first.compareTo(p2.first);
            }
        });

        int ans = 0;
        Map<Fraction, Integer> zip = new HashMap<>();
        for (int i = 0; i < FI.size(); i++) {
            FI.get(i).second.a *= -1;
            zip.put(FI.get(i).second, 0);
        }

        int[] seg = new int[2 * n];
        Arrays.fill(seg, 0);

        int idx = 0;
        for (Fraction key : zip.keySet()) {
            zip.put(key, idx++);
        }

        for (int i = 0; i < FI.size(); i++) {
            int hoge = zip.get(FI.get(i).second);
            ans += query(seg, hoge, 2 * n);
            int tmp = seg[hoge];
            update(seg, hoge, tmp + 1);
        }

        System.out.println(ans);
    }

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static int query(int[] seg, int a, int b) {
        int L = 0, R = 0;
        for (a += seg.length, b += seg.length; a < b; a >>= 1, b >>= 1) {
            if ((a & 1) == 1) L += seg[a++];
            if ((b & 1) == 1) R += seg[--b];
        }
        return L + R;
    }

    static void update(int[] seg, int k, int x) {
        k += seg.length;
        seg[k] = x;
        while (k > 1) {
            k >>= 1;
            seg[k] = seg[2 * k] + seg[2 * k + 1];
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        public Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }
}
