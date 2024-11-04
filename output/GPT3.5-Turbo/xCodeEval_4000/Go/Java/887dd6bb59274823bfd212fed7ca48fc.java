import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 887dd6bb59274823bfd212fed7ca48fc_nc {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final long MOD = 1000 * 1000 * 1000 + 7;

    public static void main(String[] args) throws IOException {
        solve();
    }

    public static void solve() throws IOException {
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

        printInt64(res);
        printLine();
    }

    public static String readString() throws IOException {
        return br.readLine();
    }

    public static int readInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    public static long readInt64() throws IOException {
        return Long.parseLong(br.readLine());
    }

    public static float readFloat64() throws IOException {
        return Float.parseFloat(br.readLine());
    }

    public static void printString(String value) {
        System.out.print(value);
    }

    public static void printLine() {
        System.out.println();
    }

    public static void printSpace() {
        System.out.print(" ");
    }

    public static void printInt(int value) {
        System.out.print(Integer.toString(value));
    }

    public static void printInt64(long value) {
        System.out.print(Long.toString(value));
    }

    public static void printFloat64(float value) {
        System.out.print(Float.toString(value));
    }
}
