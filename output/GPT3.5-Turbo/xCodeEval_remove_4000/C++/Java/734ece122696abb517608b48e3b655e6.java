import java.util.Scanner;

public class 734ece122696abb517608b48e3b655e6xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        l--;
        int L = l / 100000;
        int R = r / 100000;
        int sum1 = 0;
        for (int i = 0; i <= L; i++) {
            sum1 += ans[i];
        }
        sum1 += solve(L * 100000 + 1, l);
        if (l >= 2 && l < 100000) sum1++;
        int sum2 = 0;
        for (int i = 0; i <= R; i++) {
            sum2 += ans[i];
        }
        sum2 += solve(R * 100000 + 1, r);
        if (r >= 2 && r < 100000) sum2++;
        System.out.println(sum2 - sum1);
    }

    public static int solve(int l, int r) {
        if (l > r) return 0;
        int sum = 0;
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0 || i % 3 == 0 || i % 7 == 0 || !isPrime(i)) continue;
            if (i % 4 == 1) sum++;
        }
        return sum;
    }

    public static boolean isPrime(int n) {
        if (n < 2) return false;
        if (n < 4) return true;
        if (id0(n, 2) == 0) return false;
        if (id0(n, 3) == 0) return false;
        if (n < 1373653) return true;
        if (id0(n, 5) == 0) return false;
        if (n < 25326001) return true;
        if (id0(n, 7) == 0) return false;
        if (n == 3215031751L) return false;
        if (n < 25000000000L) return true;
        if (id0(n, 11) == 0) return false;
        if (n < 2152302898747L) return true;
        if (id0(n, 13) == 0) return false;
        if (id0(n, 17) == 0) return false;
        if (n < 341550071728321L) return true;
        if (id0(n, 19) == 0) return false;
        if (id0(n, 23) == 0) return false;
        if (id0(n, 29) == 0) return false;
        if (id0(n, 31) == 0) return false;
        if (id0(n, 37) == 0) return false;
        return true;
    }

    public static int id0(int n, int base) {
        long n2 = n - 1;
        long res;
        int s = 0;
        while ((n2 & 1) == 0) {
            n2 >>= 1;
            s++;
        }
        res = powmod(base, n2, n);
        if (res == 1 || res == n - 1) return 1;
        s--;
        while (s >= 0) {
            res = mod_mul(res, res, n);
            if (res == n - 1) return 1;
            s--;
        }
        return 0;
    }

    public static long mod_mul(long x, long y, long n) {
        long d = (long) ((double) x * y / n);
        d = x * y - n * d;
        while (d < 0) d += n;
        while (d >= n) d -= n;
        return d;
    }

    public static long powmod(long x, long t, long base) {
        long res = 1;
        while (t > 0) {
            if ((t & 1) == 1) res = mod_mul(res, x, base);
            x = mod_mul(x, x, base);
            t >>= 1;
        }
        return res;
    }

