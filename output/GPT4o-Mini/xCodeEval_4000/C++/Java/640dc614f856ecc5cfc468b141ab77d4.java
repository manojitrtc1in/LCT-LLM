import java.util.*;
import java.io.*;

public class 640dc614f856ecc5cfc468b141ab77d4_nc {
    static long x;

    static class Pair {
        long fi, se;
        Pair(long fi, long se) {
            this.fi = fi;
            this.se = se;
        }
    }

    static Pair func(long m, long n, long s) {
        if (m == 0) return new Pair(n, s);
        long k = (long) Math.cbrt(m);
        long x = k * k * k;
        long y = (k - 1) * (k - 1) * (k - 1);
        return max(func(m - x, n + 1, s + x), func(x - y - 1, n + 1, s + y));
    }

    static Pair max(Pair a, Pair b) {
        return (a.fi > b.fi || (a.fi == b.fi && a.se > b.se)) ? a : b;
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        x = Long.parseLong(br.readLine());
    }

    static void solve() {
        Pair token = func(x, 0, 0);
        System.out.println(token.fi + " " + token.se);
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }
}
