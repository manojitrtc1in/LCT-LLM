import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 887dd6bb59274823bfd212fed7ca48fcxcodeeval_processed_4000.json {
    private static final int MOD = 1000 * 1000 * 1000 + 7;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solve(br);
    }

    private static void solve(BufferedReader br) throws IOException {
        int a = readInt(br);
        int b = readInt(br);

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

        System.out.println(res);
    }

    private static int readInt(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine());
    }
}
