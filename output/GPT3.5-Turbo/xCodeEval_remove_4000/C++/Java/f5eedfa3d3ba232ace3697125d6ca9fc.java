import java.io.*;
import java.util.*;

public class f5eedfa3d3ba232ace3697125d6ca9fcxcodeeval_processed_4000.json {
    static final int fftmod = 1000000007;
    static final int N = 200000;

    static int[] a = new int[1010101];
    static int[] fact = new int[201010];
    static int[] revFact = new int[202020];

    static long cnk(int n, int k) {
        return (fact[n] * 1L * revFact[k] % fftmod * revFact[n - k]) % fftmod;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n, k;
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        a[n] = a[0];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != a[i + 1]) {
                cnt++;
            }
        }

        if (k == 1 || n == 1) {
            pw.println(0);
            pw.flush();
            return;
        }

        long ans = 0;
        int freeChoices = k - 2;
        for (int i = 0; i <= cnt / 2; i++) {
            long cur = cnk(cnt, i) * cnk(cnt - i, i) % fftmod * powmod(freeChoices, cnt - 2 * i, fftmod) % fftmod * powmod(k, n - cnt, fftmod) % fftmod;
            ans += cur;
        }
        ans %= fftmod;
        long tot = powmod(k, n, fftmod) - ans;
        if (tot < 0) {
            tot += fftmod;
        }
        pw.println(tot * powmod(2, fftmod - 2, fftmod) % fftmod);
        pw.flush();
    }

    static long powmod(long x, long n, long m) {
        long r = 1;
        x %= m;
        while (n > 0) {
            if ((n & 1) == 1) {
                r *= x;
                r %= m;
            }
            x *= x;
            x %= m;
            n >>= 1;
        }
        return r;
    }
}
