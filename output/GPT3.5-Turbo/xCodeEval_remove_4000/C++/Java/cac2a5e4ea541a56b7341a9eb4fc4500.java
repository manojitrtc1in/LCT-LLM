import java.util.*;
import java.io.*;

class Main {
    static class Mint {
        static final int MOD = 998244353;
        int value;

        public Mint(int value) {
            this.value = value;
        }

        public Mint add(Mint other) {
            int res = value + other.value;
            if (res >= MOD) {
                res -= MOD;
            }
            return new Mint(res);
        }

        public Mint subtract(Mint other) {
            int res = value - other.value;
            if (res < 0) {
                res += MOD;
            }
            return new Mint(res);
        }

        public Mint multiply(Mint other) {
            long res = (long) value * other.value % MOD;
            return new Mint((int) res);
        }

        public Mint divide(Mint other) {
            return multiply(other.inverse());
        }

        public Mint inverse() {
            return power(this, MOD - 2);
        }

        public static Mint power(Mint a, int b) {
            Mint res = new Mint(1);
            while (b > 0) {
                if ((b & 1) == 1) {
                    res = res.multiply(a);
                }
                a = a.multiply(a);
                b >>= 1;
            }
            return res;
        }

        @Override
        public String toString() {
            return Integer.toString(value);
        }
    }

    static class Mat {
        Mint[][] m;

        public Mat() {
            m = new Mint[2][2];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    m[i][j] = new Mint(0);
                }
            }
        }

        public Mat multiply(Mat b) {
            Mat c = new Mat();
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        c.m[i][j] = c.m[i][j].add(m[i][k].multiply(b.m[k][j]));
                    }
                }
            }
            return c;
        }
    }

    static class Frac implements Comparable<Frac> {
        int p, q;

        public Frac(int p, int q) {
            this.p = p;
            this.q = q;
        }

        public Mint toMint() {
            return new Mint(p).divide(new Mint(q));
        }

        @Override
        public int compareTo(Frac other) {
            long a = (long) p * other.q;
            long b = (long) q * other.p;
            return Long.compare(a, b);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println(0);
            return;
        }
        int[] x = new int[n];
        int[] v = new int[n];
        Mint[] p = new Mint[n];
        Mint id1 = new Mint(1).divide(new Mint(100));
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
            p[i] = new Mint(Integer.parseInt(st.nextToken())).multiply(id1);
        }

        Mat[] id2 = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            id2[i] = new Mat();
            id2[i].m[0][1] = p[i + 1];
        }

        Mat[] a = new Mat[2 * (n - 1) - 1];
        Frac getProb = new Frac(0, 0);
        for (int i = 0; i < 2 * (n - 1) - 1; i++) {
            a[i] = new Mat();
        }
        int getBit(int a, int i) {
            return (a >> i) & 1;
        }
        int getId(int l, int r) {
            return l + r | (l != r ? 1 : 0);
        }
        int getMid(int l, int r) {
            return l + (r - l) / 2;
        }
        void build(int l, int r) {
            if (l == r) {
                a[2 * l] = id2[l];
                return;
            }
            int mid = getMid(l, r);
            build(l, mid);
            build(mid + 1, r);
            a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid + 1, r)]);
        }
        void modify(int l, int r, int k) {
            if (l == r) {
                a[2 * l] = id2[k];
                return;
            }
            int mid = getMid(l, r);
            if (k <= mid) {
                modify(l, mid, k);
            } else {
                modify(mid + 1, r, k);
            }
            a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid + 1, r)]);
        }
        Frac getProb() {
            Mat mat = a[getId(0, n - 2)];
            return new Frac(mat.m[0][0].add(mat.m[0][1]).toMint().value, mat.m[1][0].add(mat.m[1][1]).toMint().value);
        }
        Frac[] events = new Frac[3 * (n - 1)];
        for (int i = 0; i < n - 1; i++) {
            int d = x[i + 1] - x[i];
            events[i * 3] = new Frac(d, v[i + 1] + v[i]);
            events[i * 3 + 1] = v[i] < v[i + 1] ? new Frac(d, v[i + 1] - v[i]) : new Frac(1, 0);
            events[i * 3 + 2] = v[i] > v[i + 1] ? new Frac(d, v[i] - v[i + 1]) : new Frac(1, 0);
        }
        Arrays.sort(events);
        Mint prevProb = getProb().toMint();
        Mint ans = new Mint(0);
        for (int i = events.length - 1; i >= 0; i--) {
            int idx = events[i].q >> 2;
            int dir1 = getBit(events[i].q, 0);
            int dir2 = getBit(events[i].q, 1);
            id2[idx].m[dir1][dir2] = dir2 == 1 ? p[idx + 1] : new Mint(1).subtract(p[idx + 1]);
            modify(0, n - 2, idx);
            Frac prob = getProb();
            if (events[i].q % 4 != 0) {
                ans = ans.add(prob.toMint().subtract(prevProb).multiply(events[i]));
            }
            prevProb = prob.toMint();
        }
        System.out.println(ans);
    }
}
