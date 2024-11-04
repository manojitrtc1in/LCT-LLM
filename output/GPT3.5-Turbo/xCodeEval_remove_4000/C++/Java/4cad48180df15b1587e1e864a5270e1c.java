import java.io.*;
import java.util.*;

class Main {
    static final int mod = (int) 1e9 + 7;

    static void add(int[] x, int y) {
        x[0] += y;
        if (x[0] >= mod) x[0] -= mod;
    }

    static void sub(int[] x, int y) {
        x[0] -= y;
        if (x[0] < 0) x[0] += mod;
    }

    static int solve2(int x, int y, int k, int bonus) {
        if (x <= 0 || y <= 0 || k <= 0) return 0;
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        int ty = 1;
        while (ty * 2 <= y) {
            ty *= 2;
        }
        int tx = 1;
        while (tx * 2 <= x) {
            tx *= 2;
        }
        int res;
        int txk = Math.min(tx, k);
        if (tx == ty) {
            res = txk * (txk + 1) % mod * ty + bonus * txk * 2 % mod * ty;
            res %= mod;
            add(new int[]{res}, solve2(x - tx, tx, k - tx, bonus + tx));
            add(new int[]{res}, solve2(y - tx, tx, k - tx, bonus + tx));
            add(new int[]{res}, solve2(x - tx, y - tx, k, bonus));
        } else {
            res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y;
            res %= mod;
            add(new int[]{res}, solve2(x - tx, y, k - tx, bonus + tx));
        }
        return res;
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
            int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            pw.println(ans * powmod(2, mod - 2, mod) % mod);
        }

        pw.close();
    }

    static int powmod(int x, int n, int m) {
        int res = 1;
        while (n > 0) {
            if ((n & 1) == 1) res = (int) ((res * 1L * x) % m);
            x = (int) ((x * 1L * x) % m);
            n >>= 1;
        }
        return res;
    }
}