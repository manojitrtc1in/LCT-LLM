import java.util.*;
import java.io.*;

class Main {
    static long Mod = 1000000007L;
    static long INF = 1000000000L;
    static double Pi = 3.141592653589793116;
    static double EPS = 1e-9;
    static double Gold = (1 + Math.sqrt(5)) / 2;

    static long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static int keyCount = keymod.length;

    static long x;

    static class Pair {
        long first;
        long second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static Pair func(long m, long n, long s) {
        if (m == 0) return new Pair(n, s);
        long k = (long) Math.cbrt(m);
        long x = k * k * k, y = (k - 1) * (k - 1) * (k - 1);
        return max(func(m - x, n + 1, s + x), func(x - y - 1, n + 1, s + y));
    }

    static Pair max(Pair p1, Pair p2) {
        if (p1.first > p2.first) return p1;
        else if (p1.first < p2.first) return p2;
        else {
            if (p1.second > p2.second) return p1;
            else return p2;
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        x = Long.parseLong(br.readLine());
    }

    static void solve() {
        Pair token = func(x, 0, 0);
        System.out.println(token.first + " " + token.second);
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }
}
