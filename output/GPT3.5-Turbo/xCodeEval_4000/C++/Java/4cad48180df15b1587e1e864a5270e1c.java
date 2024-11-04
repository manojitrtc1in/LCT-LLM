import java.util.*;
import java.io.*;

class Main {
    static final int mod = 1000000007;

    static void add(long[] x, long y) {
        x[0] += y;
        if (x[0] >= mod) x[0] -= mod;
    }

    static void sub(long[] x, long y) {
        x[0] -= y;
        if (x[0] < 0) x[0] += mod;
    }

    static long solve2(long x, long y, long k, long bonus) {
        if (x <= 0 || y <= 0 || k <= 0) return 0;
        if (x < y) {
            long temp = x;
            x = y;
            y = temp;
        }
        long ty = 1;
        while (ty * 2 <= y) {
            ty *= 2;
        }
        long tx = 1;
        while (tx * 2 <= x) {
            tx *= 2;
        }
        long res;
        long txk = Math.min(tx, k);
        if (tx == ty) {
            res = txk * (txk + 1) % mod * ty + bonus * txk * 2 % mod * ty;
            res %= mod;
            add(res, solve2(x - tx, tx, k - tx, bonus + tx));
            add(res, solve2(y - tx, tx, k - tx, bonus + tx));
            add(res, solve2(x - tx, y - tx, k, bonus));
        } else {
            res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y;
            res %= mod;
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
            long ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            System.out.println(ans * powmod(2, mod - 2, mod) % mod);
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
