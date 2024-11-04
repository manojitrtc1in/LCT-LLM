import java.io.*;
import java.util.*;

class Main {
    static class Mint {
        static final int MOD = 998244353;
        int value;

        Mint(int value) {
            this.value = value;
        }

        Mint add(Mint other) {
            int sum = value + other.value;
            if (sum >= MOD) {
                sum -= MOD;
            }
            return new Mint(sum);
        }

        Mint subtract(Mint other) {
            int diff = value - other.value;
            if (diff < 0) {
                diff += MOD;
            }
            return new Mint(diff);
        }

        Mint multiply(Mint other) {
            long prod = (long) value * other.value % MOD;
            return new Mint((int) prod);
        }

        Mint divide(Mint other) {
            return multiply(other.inverse());
        }

        Mint inverse() {
            int a = value, b = MOD, u = 0, v = 1;
            while (a != 0) {
                int t = b / a;
                b -= t * a;
                int temp = a;
                a = b;
                b = temp;
                u -= t * v;
                temp = u;
                u = v;
                v = temp;
            }
            assert b == 1;
            if (u < 0) {
                u += MOD;
            }
            return new Mint(u);
        }

        @Override
        public String toString() {
            return Integer.toString(value);
        }
    }

    static class Mat {
        Mint[][] m;

        Mat() {
            m = new Mint[2][2];
        }

        Mat multiply(Mat other) {
            Mat result = new Mat();
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        result.m[i][j] = result.m[i][j].add(m[i][k].multiply(other.m[k][j]));
                    }
                }
            }
            return result;
        }
    }

    static class Frac implements Comparable<Frac> {
        int p, q;

        Frac(int p, int q) {
            this.p = p;
            this.q = q;
        }

        @Override
        public int compareTo(Frac other) {
            long prod1 = (long) p * other.q;
            long prod2 = (long) other.p * q;
            return Long.compare(prod1, prod2);
        }
    }

    static int n;
    static int[] x, v;
    static Mint[] p;
    static Mat[] id2;
    static Mat[] a;
    static Mint prevProb;

    static Mint getProb() {
        return prevProb.multiply(a[0].m[1][0].add(a[0].m[1][1])).add(Mint.subtract(Mint.ONE).multiply(a[0].m[0][0].add(a[0].m[0][1])));
    }

    static void build(int l, int r) {
        if (l == r) {
            a[2 * l] = id2[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid);
        build(mid + 1, r);
        a[get_id(l, r)] = a[get_id(l, mid)].multiply(a[get_id(mid + 1, r)]);
    }

    static void modify(int l, int r, int k) {
        if (l == r) {
            a[2 * l] = id2[k];
            return;
        }
        int mid = (l + r) / 2;
        if (k <= mid) {
            modify(l, mid, k);
        } else {
            modify(mid + 1, r, k);
        }
        a[get_id(l, r)] = a[get_id(l, mid)].multiply(a[get_id(mid + 1, r)]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(in.readLine());
        if (n == 1) {
            System.out.println(0);
            return;
        }
        x = new int[n];
        v = new int[n];
        p = new Mint[n];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            x[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            p[i] = new Mint(Integer.parseInt(st.nextToken())).divide(new Mint(100));
        }

        id2 = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            id2[i] = new Mat();
            id2[i].m[0][1] = p[i + 1];
        }

        a = new Mat[2 * (n - 1) - 1];
        build(0, n - 2);

        Frac[] events = new Frac[3 * (n - 1)];
        for (int i = 0; i < n - 1; i++) {
            int d = x[i + 1] - x[i];
            events[i * 3] = new Frac(d, v[i + 1] + v[i]);
            events[i * 3 + 1] = v[i] < v[i + 1] ? new Frac(d, v[i + 1] - v[i]) : new Frac(1, 0);
            events[i * 3 + 2] = v[i] > v[i + 1] ? new Frac(d, v[i] - v[i + 1]) : new Frac(1, 0);
        }

        Arrays.sort(events);

        prevProb = getProb();
        Mint ans = Mint.ZERO;

        for (int i = events.length - 1; i >= 0; i--) {
            int idx = events[i].q >> 2;
            int dir1 = (events[i].q & 1) != 0 ? 1 : 0;
            int dir2 = (events[i].q & 2) != 0 ? 1 : 0;

            id2[idx].m[dir1][dir2] = dir2 == 1 ? p[idx + 1] : Mint.subtract(Mint.ONE, p[idx + 1]);
            modify(0, n - 2, idx);
            Mint prob = getProb();
            if (events[i].q != 0) {
                ans = ans.add(prob.subtract(prevProb).multiply(events[i]));
            }
            prevProb = prob;
        }

        System.out.println(ans);
    }
}
