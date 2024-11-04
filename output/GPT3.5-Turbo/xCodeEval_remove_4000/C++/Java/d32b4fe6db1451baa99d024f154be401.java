import java.io.*;
import java.util.*;

class Main {
    static final int mod = (int) 1e9 + 7;

    static int powmod(int x, int n, int m) {
        int res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = (int) ((res * 1L * x) % m);
            }
            x = (int) ((x * 1L * x) % m);
            n >>= 1;
        }
        return res;
    }

    static void add(int[] x, int y) {
        x[0] += y;
        if (x[0] >= mod) {
            x[0] -= mod;
        }
    }

    static int solve2(int x, int y, int k, int bonus) {
        if (x <= 0 || y <= 0 || k <= 0) {
            return 0;
        }
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if ((x & (x - 1)) == 0) {
            k = Math.min(k, x);
            return (int) ((k * 1L * y % mod * (k + 1 + bonus * 2L)) % mod);
        }
        int ty = Integer.highestOneBit(y);
        int tx = Integer.highestOneBit(x);
        int res;
        int txk = Math.min(tx, k);
        if (tx == ty) {
            res = (int) ((txk * 1L * ty % mod * (txk + 1 + bonus * 2L)) % mod);
            add(new int[]{res}, solve2(x - tx, tx, k - tx, bonus + tx));
            add(new int[]{res}, solve2(y - tx, tx, k - tx, bonus + tx));
            add(new int[]{res}, solve2(x - tx, y - tx, k, bonus));
        } else {
            res = (int) ((txk * 1L * y % mod * (txk + 1 + bonus * 2L)) % mod);
            add(new int[]{res}, solve2(x - tx, y, k - tx, bonus + tx));
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            String[] input = br.readLine().split(" ");
            int x1 = Integer.parseInt(input[0]);
            int y1 = Integer.parseInt(input[1]);
            int x2 = Integer.parseInt(input[2]);
            int y2 = Integer.parseInt(input[3]);
            int k = Integer.parseInt(input[4]);

            int ans = solve2(x2, y2, k, 0) - solve2(x1 - 1, y2, k, 0) - solve2(x2, y1 - 1, k, 0) + solve2(x1 - 1, y1 - 1, k, 0);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            ans = (int) ((ans * 1L * powmod(2, mod - 2, mod)) % mod);
            pw.println(ans);
        }

        pw.close();
    }
}
