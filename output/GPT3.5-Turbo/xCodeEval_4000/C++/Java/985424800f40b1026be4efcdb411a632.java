import java.util.*;
import java.io.*;

public class 985424800f40b1026be4efcdb411a632_nc {
    static long[] a = new long[101010];

    static long cnk(long n, long k) {
        long ret = 1;
        for (long i = n - k + 1; i <= n; i++) {
            ret *= i;
        }
        for (int i = 1; i <= k; i++) {
            ret /= i;
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());

        if (k == 1) {
            System.out.println(1);
            System.exit(0);
        }

        a[2] = 1;
        for (int i = 3; i <= 10; i++) {
            a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
        }

        long ans = 1;
        for (int i = 0; i < k; i++) {
            ans += cnk(n, k - i) * a[(int) (k - i)];
        }

        System.out.println(ans);
    }
}
