import java.util.*;
import java.io.*;

public class 4cad48180df15b1587e1e864a5270e1c_nc {
    static final long mod = 1000000007;

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
            add(new long[]{res}, solve2(x - tx, tx, k - tx, bonus + tx));
            add(new long[]{res}, solve2(y - tx, tx, k - tx, bonus + tx));
            add(new long[]{res}, solve2(x - tx, y - tx, k, bonus));
        } else {
            res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y;
            res %= mod;
            add(new long[]{res}, solve2(x - tx, y, k - tx, bonus + tx));
        }
        return res;
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

            long ans = solve2(x2, y2, k, 0) - solve2(x1 - 1, y2, k, 0) - solve2(x2, y1 - 1, k, 0) + solve2(x1 - 1, y1 - 1, k, 0);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            out.println(ans * powmod(2L, mod - 2, mod) % mod);
        }
        out.flush();
    }
}
