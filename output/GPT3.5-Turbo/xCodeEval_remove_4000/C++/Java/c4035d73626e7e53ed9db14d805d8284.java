import java.util.Scanner;

public class c4035d73626e7e53ed9db14d805d8284xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long p = scanner.nextLong();
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
