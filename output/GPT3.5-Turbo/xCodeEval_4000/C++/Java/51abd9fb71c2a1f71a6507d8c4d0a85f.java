import java.util.*;
import java.io.*;

public class 51abd9fb71c2a1f71a6507d8c4d0a85f_nc {
    static final long Mod = 1000000007L, INF = 1_000_000_000L, LINF = 1_000_000_000_000_000_000L;
    static final double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+Math.sqrt(5))/2);
    static long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static int keyCount = keymod.length;

    static long Pow(long a, long b) {
        if (b == 0) return 1;
        long tmp = Pow(a, b/2);
        if (b % 2 == 0) return (tmp * tmp);
        return (tmp * tmp * a);
    }

    static long n, Min = LINF, Max = -LINF;
    static List<Pair<Long, Long>> A;

    static void Try(int id, long x1, long x2, long x3) {
        if (id == A.size()) {
            Min = Math.min(Min, (x1+1)*(x2+2)*(x3+2));
            Min = Math.min(Min, (x1+2)*(x2+1)*(x3+2));
            Min = Math.min(Min, (x1+2)*(x2+2)*(x3+1));
            Max = Math.max(Max, (x1+1)*(x2+2)*(x3+2));
            Max = Math.max(Max, (x1+2)*(x2+1)*(x3+2));
            Max = Math.max(Max, (x1+2)*(x2+2)*(x3+1));
            return;
        }
        long key = A.get(id).getKey(), v = A.get(id).getValue();
        for (long i=0; i<=v; i++) {
            for (long j=0; j<=v; j++) {
                for (long k=0; k<=v; k++) {
                    if (i + j + k != v) continue;
                    Try(id+1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k));
                }
            }
        }
    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Long.parseLong(br.readLine());
    }

    static void Solve() {
        Map<Long, Long> Map = new HashMap<>();
        long N = n;
        for (long i=2; i<=Math.sqrt(n); i++) {
            while (n % i == 0) {
                Map.put(i, Map.getOrDefault(i, 0L) + 1);
                n /= i;
            }
        }
        if (n > 1) Map.put(n, Map.getOrDefault(n, 0L) + 1);
        for (Map.Entry<Long, Long> entry : Map.entrySet()) {
            long k = entry.getKey(), v = entry.getValue();
            A.add(new Pair<>(k, v));
        }
        Try(0, 1, 1, 1);
        System.out.println((Min - N) + " " + (Max - N));
    }

    public static void main(String[] args) throws IOException {
        Input();
        Solve();
    }
}
