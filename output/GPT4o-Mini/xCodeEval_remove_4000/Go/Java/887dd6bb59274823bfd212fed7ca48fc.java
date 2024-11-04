import java.io.*;
import java.util.*;

public class 887dd6bb59274823bfd212fed7ca48fcxcodeeval_processed_4000.json {
    static final long MOD = 1000 * 1000 * 1000 + 7;
    static Scanner scanner;
    static PrintWriter writer;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        writer = new PrintWriter(System.out);
        solve();
        writer.flush();
    }

    static void solve() {
        int a = readInt();
        int b = readInt();

        long r = 0;
        for (int i = 1; i <= b - 1; i++) {
            r += i;
            if (r >= MOD) {
                r -= MOD;
            }
        }

        long res = (long) a * r % MOD;

        long k = 0;
        for (int i = 1; i <= a; i++) {
            k += (long) i * r % MOD;
            if (k >= MOD) {
                k -= MOD;
            }
        }

        res += (long) b * k % MOD;
        if (res >= MOD) {
            res -= MOD;
        }

        printLong(res);
        printLine();
    }

    static int readInt() {
        return Integer.parseInt(scanner.next());
    }

    static void printLong(long value) {
        writer.print(value);
    }

    static void printLine() {
        writer.println();
    }
}
