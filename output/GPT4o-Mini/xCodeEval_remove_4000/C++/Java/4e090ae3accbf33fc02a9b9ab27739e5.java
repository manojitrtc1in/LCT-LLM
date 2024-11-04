import java.util.Scanner;

public class 4e090ae3accbf33fc02a9b9ab27739e5xcodeeval_processed_4000.json {
    static final int MS = 3001;
    static long[] pw = new long[MS];
    static int[] t = new int[3001];
    static int[] pr = {2, 7, 61};

    public static void count() {
        pw[0] = 1;
        for (int c = 1; c < MS; c++)
            pw[c] = pw[c - 1] * 2;
    }

    static long square(long x) {
        return x * x;
    }

    static long bigmod(long b, long p, long m) {
        if (p == 0)
            return 1;
        else if (p % 2 == 0)
            return square(bigmod(b, p / 2, m)) % m;
        else
            return ((b % m) * bigmod(b, p - 1, m)) % m;
    }

    static boolean mr(int n) {
        if ((!(n % 2) && n != 2) || n == 1)
            return true;
        int s = 0, d = n - 1;
        while (d > 1 && !(d % 2)) {
            s++;
            d /= 2;
        }
        for (int c = 0; c < 3 && pr[c] < n; c++) {
            if (bigmod(pr[c], d, n) != 1) {
                int l = 0;
                for (int r = 0; r < s; r++)
                    if ((bigmod(pr[c], pw[r] * d, n) + 1) % n != 0)
                        l++;
                    else
                        break;
                if (l == s)
                    return true;
            }
        }
        return false;
    }

    static int sqr(int x) {
        return x * x;
    }

    static boolean ok(int x) {
        if (x == 1)
            return false;
        if (mr(x))
            return false;
        int v = (int) Math.sqrt(1.0 * x);
        for (int i = 1; i <= v; i++) {
            int j = sqr(i);
            if (x > j && sqr((int) Math.sqrt(1.0 * x - j)) + j == x)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        count();

        for (int i = 1; i < 3001; i++)
            t[i] += t[i - 1];
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int res = 0;
        while (l % 100000 != 0 && l <= r)
            res += ok(l++);
        while (r % 100000 != 0 && l <= r)
            res += ok(r--);
        if (l <= r)
            res += t[r / 100000] - t[l / 100000];
        System.out.println(res);
    }
}
