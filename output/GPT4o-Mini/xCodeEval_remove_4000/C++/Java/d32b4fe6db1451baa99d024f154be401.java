import java.util.*;
import java.io.*;

public class d32b4fe6db1451baa99d024f154be401xcodeeval_processed_4000.json {
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

    static int sign(long x) {
        return Long.compare(x, 0);
    }

    static boolean id0(int x) {
        return (x != 0 && (x & (x - 1)) == 0);
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
        int res;
        int txk = Math.min(tx, k);
        if (tx == ty) {
            res = (int) (txk * (long) ty % mod * (txk + 1 + bonus * 2L) % mod);
            add(new int[]{res}, solve2(x - tx, tx, k - tx, bonus + tx));
            add(new int[]{res}, solve2(y - tx, tx, k - tx, bonus + tx));
            add(new int[]{res}, solve2(x - tx, y - tx, k, bonus));
        } else {
            res = (int) (txk * (long) y % mod * (txk + 1 + bonus * 2L) % mod);
            add(new int[]{res}, solve2(x - tx, y, k - tx, bonus + tx));
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int q = Integer.parseInt(st.nextToken());
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int ans = solve2(x2, y2, k, 0) - solve2(x1 - 1, y2, k, 0) - solve2(x2, y1 - 1, k, 0) + solve2(x1 - 1, y1 - 1, k, 0);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            out.println(ans * powmod(2L, mod - 2, mod) % mod);
        }
        out.flush();
    }

    static long powmod(long x, long n, long m) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) res = (res * x) % m;
            x = (x * x) % m;
            n >>= 1;
        }
        return res;
    }
}
