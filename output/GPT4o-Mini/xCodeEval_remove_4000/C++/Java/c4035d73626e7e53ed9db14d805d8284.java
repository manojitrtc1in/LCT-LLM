import java.util.Scanner;

public class c4035d73626e7e53ed9db14d805d8284xcodeeval_processed_4000.json {
    static final long MOD = (long) 1e9 + 7;
    static final double ERROR = 2e-6;
    static final double PI = Math.acos(-1);

    static long MOD(long x, long m) {
        long y = x % m;
        return (y >= 0) ? y : y + m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n = scanner.nextLong();
        long p = scanner.nextLong();
        
        if (p == 0) {
            System.out.println(Long.bitCount(n));
            return;
        }
        
        if (p > 0) {
            for (long i = 1; i <= 35; i++) {
                n -= p;
                if (n < 0) {
                    System.out.println(-1);
                    return;
                }
                if (Long.bitCount(n) <= i && Long.bitCount(n) != 0) {
                    if (Long.bitCount(n) == 1 && i > Math.log(n) / Math.log(2) + 1) {
                        System.out.println(-1);
                        return;
                    }
                    System.out.println(i);
                    return;
                }
            }
            System.out.println(-1);
            return;
        }

        if (p < 0) {
            for (long i = 1; i <= 35; i++) {
                n += -p;
                if (n < 0) {
                    continue;
                }
                if (Long.bitCount(n) <= i && Long.bitCount(n) != 0) {
                    if (Long.bitCount(n) == 1 && i > Math.log(n) / Math.log(2) + 1) {
                        System.out.println(-1);
                        return;
                    }
                    System.out.println(i);
                    return;
                }
            }
            System.out.println(-1);
            return;
        }
    }
}
