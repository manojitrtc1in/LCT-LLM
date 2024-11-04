import java.util.*;
import java.io.*;

public class e801b107f8ac3e4f87a7a1861568540dxcodeeval_processed_4000.json {
    static final long MOD = (long)1e9 + 7;
    static final int MX = (int)2e5 + 5;
    static final long INF = (long)1e18;
    static final double PI = Math.acos(-1.0);
    static long[] a = new long[200005];

    static long nod(long a, long b) {
        if (b > a) {
            long temp = a;
            a = b;
            b = temp;
        }
        while (b > 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    static long nok(long a, long b) {
        return a * b / nod(a, b);
    }

    static void print(double b, int precision) {
        System.out.printf("%." + precision + "f", b);
    }

    static long binpow(long a, long n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 1) {
            return binpow(a, n - 1) * a;
        } else {
            long b = binpow(a, n / 2);
            return b * b;
        }
    }

    static void read(long[] arr) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
    }

    static void solve() throws IOException {
        Map<Long, Long> m = new HashMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long s = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        long ans = MOD;
        long cnt = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = Long.parseLong(br.readLine());
            if (i >= k) {
                m.put(a[i - k], m.getOrDefault(a[i - k], 0L) - 1);
                if (m.get(a[i - k]) == 0) cnt--;
                m.put(a[i], m.getOrDefault(a[i], 0L) + 1);
                if (m.get(a[i]) == 1) cnt++;
                ans = Math.min(ans, cnt);
            } else {
                m.put(a[i], m.getOrDefault(a[i], 0L) + 1);
                if (m.get(a[i]) == 1) cnt++;
            }
        }
        ans = Math.min(ans, cnt);
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long t = Long.parseLong(br.readLine());
        for (int i = 1; i <= t; i++) {
            solve();
        }
    }
}
