import java.util.*;
import java.io.*;

public class 60d63af5e45f7347a8ef9d8047020cb7xcodeeval_processed_4000.json {
    static long mod = 1000000007;

    static class Triple<T1, T2, T3> {
        T1 a;
        T2 b;
        T3 c;

        Triple() {
            this.a = null;
            this.b = null;
            this.c = null;
        }

        Triple(T1 _a, T2 _b, T3 _c) {
            this.a = _a;
            this.b = _b;
            this.c = _c;
        }
    }

    static int bitsCount(int v) {
        v = v - ((v >> 1) & 0x55555555);
        v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
        return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
    }

    static int bitsCount(long v) {
        int t = (int) (v >> 32);
        int p = (int) (v & ((1L << 32) - 1));
        return bitsCount(t) + bitsCount(p);
    }

    static int sign(int x) {
        return Integer.compare(x, 0);
    }

    static boolean id0(int x) {
        return (x != 0 && (x & (x - 1)) == 0);
    }

    static long id5() {
        // Placeholder for id5 functionality
        return 0;
    }

    static void printArray(int[] a, int sz, int beg) {
        for (int i = beg; i < sz; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    static boolean isPrime(long x) {
        if (x < 2) return false;
        for (long i = 2; i * i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }

    static void normmod(long[] x, long m) {
        x[0] %= m;
        if (x[0] < 0) x[0] += m;
    }

    static long id6(long x, long y, long m) {
        long res = x + y;
        if (res >= m) res -= m;
        return res;
    }

    static int id6(int x, int y, int m) {
        int res = x + y;
        if (res >= m) res -= m;
        return res;
    }

    static void id4(long[] x, long y, long m) {
        x[0] += y;
        if (x[0] >= m) x[0] -= m;
    }

    static void id4(int[] x, int y, int m) {
        x[0] += y;
        if (x[0] >= m) x[0] -= m;
    }

    static void id2(long[] x, long y, long m) {
        x[0] -= y;
        if (x[0] < 0) x[0] += m;
    }

    static void id2(int[] x, int y, int m) {
        x[0] -= y;
        if (x[0] < 0) x[0] += m;
    }

    static long mulmod(long x, long n, long m) {
        long res = 0;
        normmod(new long[]{x}, m);
        normmod(new long[]{n}, m);
        while (n > 0) {
            if ((n & 1) != 0) res = id6(res, x, m);
            x = id6(x, x, m);
            n >>= 1;
        }
        return res;
    }

    static long powmod(long x, long n, long m) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) != 0) res = (res * x) % m;
            x = (x * x) % m;
            n >>= 1;
        }
        return res;
    }

    static long gcd(long a, long b) {
        long t;
        while (b != 0) {
            a = a % b;
            t = a;
            a = b;
            b = t;
        }
        return a;
    }

    static int gcd(int a, int b) {
        int t;
        while (b != 0) {
            a = a % b;
            t = a;
            a = b;
            b = t;
        }
        return a;
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    static long id1(long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0;
            y[0] = 1;
            return b;
        }
        long[] y1 = new long[1];
        long d = id1(b % a, a, x, y1);
        x[0] = y1[0] - (b / a) * y[0];
        return d;
    }

    static void add(int[] x, int y) {
        x[0] += y;
        if (x[0] >= mod) x[0] -= mod;
    }

    static int id3(int v) {
        return 1 << (31 - Integer.numberOfLeadingZeros(v));
    }

    static int solve2(int x, int y, int k, int bonus) {
        if (x <= 0 || y <= 0 || k <= 0) return 0;
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if ((x & (x - 1)) == 0) {
            k = Math.min(k, x);
            return (int) (k * (long) y % mod * (k + 1 + bonus * 2L) % mod);
        }
        int ty = id3(y);
        int tx = id3(x);
        long res;
        int txk = Math.min(tx, k);
        if (tx == ty) {
            res = txk * (long) ty % mod * (txk + 1 + bonus * 2L) +
                    solve2(x - tx, tx, k - tx, bonus + tx) +
                    solve2(y - tx, tx, k - tx, bonus + tx) +
                    solve2(x - tx, y - tx, k, bonus);
        } else {
            res = txk * (long) y % mod * (txk + 1 + bonus * 2L) +
                    solve2(x - tx, y, k - tx, bonus + tx);
        }
        return (int) (res % mod);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            out.println((int) (ans * powmod(2L, mod - 2, mod) % mod));
        }
        out.flush();
    }
}
