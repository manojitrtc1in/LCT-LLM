import java.util.Scanner;

public class 6269f2e0b6a350817fb7440d60199d62xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while (q-- > 0) {
            long n = sc.nextLong();
            long M = n / 4 + 1;
            long mod = 1000000007;
            long m = M % mod;
            if (n % 4 <= 1) {
                System.out.println((m * m) % mod);
            } else {
                System.out.println((m * (m + 1)) % mod);
            }
        }
        sc.close();
    }
}
