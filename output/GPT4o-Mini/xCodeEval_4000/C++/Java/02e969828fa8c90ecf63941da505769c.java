import java.util.*;
import java.io.*;

public class 02e969828fa8c90ecf63941da505769c_nc {
    static long n, m;
    static final long Mod = 1000000007L;

    static long modPow(long a, long b, long M) {
        if (b == 0) return 1;
        long tmp = modPow(a, b / 2, M);
        if (b % 2 == 0) return (tmp * tmp) % M;
        return (((tmp * tmp) % M) * a) % M;
    }

    static void input(Scanner scanner) {
        n = scanner.nextLong();
        m = scanner.nextLong();
    }

    static void solve() {
        long A = (modPow(3, n, m) + m - 1) % m;
        System.out.print(A);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (args.length > 0) {
            try {
                System.setIn(new FileInputStream(args[0]));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        if (args.length > 1) {
            try {
                System.setOut(new PrintStream(new FileOutputStream(args[1])));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        if (args.length == 0) {
            input(scanner);
            solve();
        } else {
            int T = scanner.nextInt();
            while (T-- > 0) {
                input(scanner);
                solve();
            }
        }
        scanner.close();
    }
}
