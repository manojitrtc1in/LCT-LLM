import java.io.*;
import java.util.*;

public class 60d63af5e45f7347a8ef9d8047020cb7xcodeeval_processed_4000.json {
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

    static int gcd(int a, int b) {
        while (b != 0) {
            int t = a;
            a = b;
            b = t % b;
        }
        return a;
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
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
        int ty = id3(y);
        int tx = id3(x);
        long res;
        int txk = Math.min(tx, k);
        if (tx == ty) {
            res = txk * (long) ty % mod * (txk + 1 + bonus * 2L) + solve2(x - tx, tx, k - tx, bonus + tx)
                    + solve2(y - tx, tx, k - tx, bonus + tx) + solve2(x - tx, y - tx, k, bonus);
        } else {
            res = txk * (long) y % mod * (txk + 1 + bonus * 2L) + solve2(x - tx, y, k - tx, bonus + tx);
        }
        return (int) (res % mod);
    }

    static int id3(int v) {
        return 1 << (31 - Integer.numberOfLeadingZeros(v));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            String[] tokens = br.readLine().split(" ");
            int x1 = Integer.parseInt(tokens[0]);
            int y1 = Integer.parseInt(tokens[1]);
            int x2 = Integer.parseInt(tokens[2]);
            int y2 = Integer.parseInt(tokens[3]);
            int k = Integer.parseInt(tokens[4]);

            int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            ans = (int) (ans * 1L * powmod(2, mod - 2, mod) % mod);
            pw.println(ans);
        }

        pw.close();
    }
}
