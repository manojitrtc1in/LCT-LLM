import java.util.Scanner;

public class 04d2416a6e1a2b507447d1da12867e39xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();
            if (ss(Math.min(a, b), Math.max(a, b))) {
                System.out.println("First");
            } else {
                System.out.println("Second");
            }
        }
    }

    public static boolean win(long a, long b) {
        if (a % 2 != 0) {
            long cnt = 0;
            while (b != 0) {
                cnt += b % a;
                b /= a;
            }
            return cnt % 2 == 0;
        } else {
            return b % (a + 1) % 2 == 0;
        }
    }

    public static boolean ss(long a, long b) {
        if (a == 0) {
            return false;
        }
        if (!ss(b % a, a)) {
            return true;
        }
        return win(a, b / a);
    }
}
