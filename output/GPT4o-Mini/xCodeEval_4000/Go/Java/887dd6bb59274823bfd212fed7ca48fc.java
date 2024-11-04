import java.io.*;
import java.util.*;

public class 887dd6bb59274823bfd212fed7ca48fc_nc {
    static final long MOD = 1000 * 1000 * 1000 + 7;

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        long a = Long.parseLong(tokenizer.nextToken());
        long b = Long.parseLong(tokenizer.nextToken());

        long r = 0;
        for (long i = 1; i <= b - 1; i++) {
            r += i;
            if (r >= MOD) {
                r -= MOD;
            }
        }

        long res = (a * r) % MOD;

        long k = 0;
        for (long i = 1; i <= a; i++) {
            k += (i * r) % MOD;
            if (k >= MOD) {
                k -= MOD;
            }
        }

        res += (b * k) % MOD;
        if (res >= MOD) {
            res -= MOD;
        }

        output.write(Long.toString(res));
        output.newLine();
        output.flush();
    }
}
