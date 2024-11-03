import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static class Pair {
        long first;
        long second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static long Mod = 1000000007L;
    static long INF = 1000000000L;
    static double Pi = 3.141592653589793116;
    static double EPS = 1e-9;
    static double Gold = (1 + Math.sqrt(5)) / 2;

    static long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static int keyCount = keymod.length;

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

    static long Pow(long a, long b) {
        if (b == 0) return 1;
        long tmp = Pow(a, b / 2);
        if (b % 2 == 0) return (tmp * tmp);
        return (tmp * tmp * a);
    }

    static long n, Min = INF, Max = -INF;
    static ArrayList<Pair> A;

    static void Try(int id, long x1, long x2, long x3) {
        if (id == A.size()) {
            Min = Math.min(Min, (x1 + 1) * (x2 + 2) * (x3 + 2));
            Min = Math.min(Min, (x1 + 2) * (x2 + 1) * (x3 + 2));
            Min = Math.min(Min, (x1 + 2) * (x2 + 2) * (x3 + 1));
            Max = Math.max(Max, (x1 + 1) * (x2 + 2) * (x3 + 2));
            Max = Math.max(Max, (x1 + 2) * (x2 + 1) * (x3 + 2));
            Max = Math.max(Max, (x1 + 2) * (x2 + 2) * (x3 + 1));
            return;
        }
        long key = A.get(id).first;
        long v = A.get(id).second;
        for (long i = 0; i <= v; i++) {
            for (long j = 0; j <= v; j++) {
                for (long k = 0; k <= v; k++) {
                    if (i + j + k != v) continue;
                    Try(id + 1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k));
                }
            }
        }
    }

    static void Input() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
    }

    static void Solve() {
        HashMap<Long, Long> Map = new HashMap<>();
        long N = n;
        for (long i = 2; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                if (!Map.containsKey(i)) {
                    Map.put(i, 0L);
                }
                Map.put(i, Map.get(i) + 1);
                n /= i;
            }
        }
        if (n > 1) {
            if (!Map.containsKey(n)) {
                Map.put(n, 0L);
            }
            Map.put(n, Map.get(n) + 1);
        }
        for (Map.Entry<Long, Long> entry : Map.entrySet()) {
            long k = entry.getKey();
            long v = entry.getValue();
            A.add(new Pair(k, v));
        }
        Try(0, 1, 1, 1);
        System.out.println((Min - N) + " " + (Max - N));
    }

    public static void main(String[] args) {
        Input();
        Solve();
    }
}
