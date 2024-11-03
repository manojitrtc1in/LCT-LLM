import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.time.*;

class Main {
    static final long Mod = 1000000007L, INF = 1_000_000_000L, LINF = 1_000_000_000_000_000_000L;
    static final double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + Math.sqrt(5)) / 2);
    static final long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static final int keyCount = keymod.length;

    static long getbit(long s, int i) {
        return (s >> i) & 1;
    }

    static long onbit(long s, int i) {
        return s | (1L << i);
    }

    static long offbit(long s, int i) {
        return s & (~(1L << i));
    }

    static int cntbit(long s) {
        return Long.bitCount(s);
    }

    static long x;

    static class Pair {
        long first, second;

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

    static void input() {
        Scanner sc = new Scanner(System.in);
        x = sc.nextLong();
        sc.close();
    }

    static void solve() {
        Pair token = func(x, 0, 0);
        System.out.println(token.first + " " + token.second);
    }

    public static void main(String[] args) {
        input();
        solve();
    }
}
