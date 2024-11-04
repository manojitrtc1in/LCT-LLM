import java.util.*;
import java.io.*;

public class 4231521706ae58155410ff7613c0cd41_nc {
    static final int mod = 1000000007;

    static void add(int[] x, int y) {
        x[0] += y;
        if (x[0] >= mod) x[0] -= mod;
    }

    static int powlog2(int v) {
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        ++v;
        return v / 2;
    }

    static int solve2(int x, int y, int k, int bonus) {
        if (x <= 0 || y <= 0 || k <= 0) return 0;
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if ((x & (x - 1)) == 0 && (y & (y - 1)) == 0) {
            k = Math.min(k, x);
            return k * (long) y % mod * (k + 1 + bonus * 2L) % mod;
        }
        int ty = powlog2(y);
        int tx = powlog2(x);
        int res;
        int txk = Math.min(tx, k);
        if (tx == ty) {
            res = txk * (long) ty % mod * (txk + 1 + bonus * 2L) % mod;
            add(res, solve2(x - tx, tx, k - tx, bonus + tx));
            add(res, solve2(y - tx, tx, k - tx, bonus + tx));
            add(res, solve2(x - tx, y - tx, k, bonus));
        } else {
            res = txk * (long) y % mod * (txk + 1 + bonus * 2L) % mod;
            add(res, solve2(x - tx, y, k - tx, bonus + tx));
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            String[] input = br.readLine().split(" ");
            int x1 = Integer.parseInt(input[0]);
            int y1 = Integer.parseInt(input[1]);
            int x2 = Integer.parseInt(input[2]);
            int y2 = Integer.parseInt(input[3]);
            int k = Integer.parseInt(input[4]);
            int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            System.out.println(ans * powmod(2L, mod - 2, mod) % mod);
        }
    }

    static long powmod(long x, long n, long m) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = (res * x) % m;
            }
            x = (x * x) % m;
            n /= 2;
        }
        return res;
    }
}
