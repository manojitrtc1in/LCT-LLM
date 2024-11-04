import java.util.*;

class Main {
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
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
            ans += cnk(n, k - i) * a[k - i];
        }

        System.out.println(ans);
    }
}
