import java.io.*;
import java.util.*;

class Main {
    static final int mod = (int)1e9 + 7;

    static int powmod(int x, int n, int m) {
        int res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = (int)((1L * res * x) % m);
            }
            x = (int)((1L * x * x) % m);
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

    static int id3(int v) {
        return 1 << (31 - Integer.numberOfLeadingZeros(v));
    }

    static void add(int[] x, int y) {
        x[0] += y;
        if (x[0] >= mod) {
            x[0] -= mod;
        }
    }

    static void sub(int[] x, int y) {
        x[0] -= y;
        if (x[0] < 0) {
            x[0] += mod;
        }
    }

    static int solve2(int x, int y, int k, int bonus) {
        if (x <= 0 || y <= 0 || k <= 0) {
            return 0;
        }
        if (x < y) {
            int t = x;
            x = y;
            y = t;
        }
        int ty = id3(y);
        int tx = id3(x);
        int[] res = new int[1];
        int txk = Math.min(tx, k);
        if (tx == ty) {
            res[0] = (int)((1L * txk * ty % mod) * (txk + 1 + bonus * 2L) % mod);
            add(res, solve2(x - tx, tx, k - tx, bonus + tx));
            add(res, solve2(y - tx, tx, k - tx, bonus + tx));
            add(res, solve2(x - tx, y - tx, k, bonus));
        } else {
            res[0] = (int)((1L * txk * y % mod) * (txk + 1 + bonus * 2L) % mod);
            add(res, solve2(x - tx, y, k - tx, bonus + tx));
        }
        return res[0];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
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
            ans = (int)((1L * ans * powmod(2, mod - 2, mod)) % mod);
            pw.println(ans);
        }

        pw.close();
    }
}
