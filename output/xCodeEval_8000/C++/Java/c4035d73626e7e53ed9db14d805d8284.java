import java.util.*;
import java.io.*;

public class c4035d73626e7e53ed9db14d805d8284_nc {
    static final long mod = 1000000007;
    static final double error = 2e-6;
    static final double PI = Math.acos(-1);

    static long MOD(long x, long m) {
        long y = x % m;
        return (y >= 0) ? y : y + m;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long p = Long.parseLong(st.nextToken());

        if (p == 0) {
            System.out.println(Long.bitCount(n));
            System.exit(0);
        }

        if (p > 0) {
            for (int i = 1; i <= 35; i++) {
                n -= p;
                if (n < 0) {
                    System.out.println(-1);
                    System.exit(0);
                }
                if (Long.bitCount(n) <= i && Long.bitCount(n) != 0) {
                    if (Long.bitCount(n) == 1 && i > Math.log(n) / Math.log(2) + 1) {
                        System.out.println(-1);
                        System.exit(0);
                    }
                    System.out.println(i);
                    System.exit(0);
                }
            }
            System.out.println(-1);
            System.exit(0);
        }

        if (p < 0) {
            for (int i = 1; i <= 35; i++) {
                n += -p;
                if (n < 0) {
                    continue;
                }
                if (Long.bitCount(n) <= i && Long.bitCount(n) != 0) {
                    if (Long.bitCount(n) == 1 && i > Math.log(n) / Math.log(2) + 1) {
                        System.out.println(-1);
                        System.exit(0);
                    }
                    System.out.println(i);
                    System.exit(0);
                }
            }
            System.out.println(-1);
            System.exit(0);
        }
    }
}
