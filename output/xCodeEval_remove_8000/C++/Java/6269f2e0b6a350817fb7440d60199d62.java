import java.util.Scanner;

public class 6269f2e0b6a350817fb7440d60199d62xcodeeval_processed_8000.json {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while (q-- > 0) {
            long n = sc.nextLong();
            long M = n / 4 + 1;
            long m = M;
            if (n % 4 <= 1) {
                System.out.println((m * m) % 1000000007);
            } else {
                System.out.println((m * (m + 1)) % 1000000007);
            }
        }
        sc.close();
    }
}
