import java.util.*;

public class 980770e7a017f49149b45e925e6fa9d6xcodeeval_processed_4000.json {
    static long a = -1, b = -1;
    static int MOD = 1000000007;
    static int INF = 0x7fffffff;
    static double PI = Math.acos(-1.0);
    static double EPS = 1e-12;
    static double OO = 1e15;

    static void checkMin(long[] a, long b) {
        if (b < a[0]) a[0] = b;
    }

    static void checkMax(long[] a, long b) {
        if (b > a[1]) a[1] = b;
    }

    static long countBits(int x) {
        x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
        x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
        x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
        x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
        x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
        return x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int tttt = (int) Math.sqrt(n);

        for (int i = 1; i <= tttt + 9; i++) {
            if (n % i == 0) {
                int t = n / i;
                int zt = (int) Math.sqrt(t);

                for (int j = 1; j <= zt + 9; j++) {
                    if (t % j == 0) {
                        long tt = t / j;
                        if (tt >= 1) {
                            long ttt = (tt + 2) * (i + 1) * (j + 2);
                            if (a == -1) a = ttt;
                            checkMin(new long[]{a}, ttt);
                            if (b == -1) b = ttt;
                            checkMax(new long[]{b}, ttt);
                        }
                    }
                }

                int zz = i;
                i = n / i;
                t = n / i;
                zt = (int) Math.sqrt(t);

                for (int j = 1; j <= zt + 9; j++) {
                    if (t % j == 0) {
                        long tt = t / j;
                        if (tt >= 1) {
                            long ttt = (tt + 2) * (i + 1) * (j + 2);
                            if (a == -1) a = ttt;
                            checkMin(new long[]{a}, ttt);
                            if (b == -1) b = ttt;
                            checkMax(new long[]{b}, ttt);
                        }
                    }
                }
                i = zz;
            }
        }

        System.out.println((a - n) + " " + (b - n));
    }
}
