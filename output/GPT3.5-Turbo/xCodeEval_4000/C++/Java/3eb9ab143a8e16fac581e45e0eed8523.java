import java.util.*;
import java.io.*;

class TaskB {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        int m = in.nextInt();
        Mint.setMod(m);
        Mint[] ways = new Mint[n + 1];
        Mint[] extras = new Mint[n + 1];
        ways[1] = new Mint(1);
        Mint sum = new Mint(0);
        Mint extra = new Mint(0);
        for (int i = 1; i <= n; ++i) {
            ways[i] = ways[i].add(sum);
            extra = extra.add(extras[i]);
            ways[i] = ways[i].add(extra);
            for (int j = 2; i * j <= n; ++j) {
                extras[i * j] = extras[i * j].add(ways[i]);
                if ((i + 1) * j <= n)
                    extras[(i + 1) * j] = extras[(i + 1) * j].subtract(ways[i]);
            }
            sum = sum.add(ways[i]);
        }
        out.println(ways[n].val());
        out.close();
    }

    static class Mint {
        static int mod;
        int val;

        public Mint(int val) {
            this.val = val;
        }

        public static void setMod(int m) {
            mod = m;
        }

        public int val() {
            return val;
        }

        public Mint add(Mint other) {
            int res = val + other.val;
            if (res >= mod)
                res -= mod;
            return new Mint(res);
        }

        public Mint subtract(Mint other) {
            int res = val - other.val;
            if (res < 0)
                res += mod;
            return new Mint(res);
        }

        public Mint multiply(Mint other) {
            return new Mint((int) ((long) val * other.val % mod));
        }
    }
}