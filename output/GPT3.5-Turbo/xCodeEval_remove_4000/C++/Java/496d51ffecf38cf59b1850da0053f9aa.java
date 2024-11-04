import java.util.*;

public class 496d51ffecf38cf59b1850da0053f9aaxcodeeval_processed_4000.json {
    static double eps = 0.0000001;
    static double pi = Math.acos(-1);

    static long fastpower(long b, long p) {
        long ans = 1;
        while (p != 0) {
            if (p % 2 != 0) {
                ans = (ans * b);
            }
            b = b * b;
            p /= 2;
        }
        return ans;
    }

    static long id0(long b, long p, long m) {
        long ans = 1;
        while (p != 0) {
            if (p % 2 != 0) {
                ans = ((ans % m) * (b % m)) % m;
            }
            b = ((b % m) * (b % m)) % m;
            p /= 2;
        }
        return ans % m;
    }

    static String id1(long n) {
        String ans = "";
        boolean ch = false;
        if (n < 0) {
            n *= -1;
            ch = true;
        }
        if (n == 0) {
            ans = "0";
        }
        while (n != 0) {
            long mo = n % 10;
            mo += 48;
            char m = (char) mo;
            ans = m + ans;
            n /= 10;
        }
        if (ch) {
            ans = '-' + ans;
        }
        return ans;
    }

    static boolean compare(double f, double s) {
        return (Math.abs(f - s) < eps);
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long a2 = a;
            a = b;
            b = a2 % b;
        }
        return a;
    }

    static final int N = (int) 1e2 + 1;

    static long[] powcnt = new long[N];
    static long ans;

    static void preprocess(long num) {
        for (int i = 30; i >= 0; i--) {
            if (num >= (1 << i)) {
                num -= (1 << i);
                powcnt[i]++;
            }
        }
    }

    static void solve(long curp) {
        for (long i = curp; i <= 30; i++) {
            if (powcnt[(int) i] > 0) {
                powcnt[(int) i]--;
                ans++;
                for (long j = curp; j < i; j++) {
                    powcnt[(int) j]++;
                }
                break;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Long> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            long x = scanner.nextLong();
            preprocess(x);
        }
        for (int i = 0; i < m; i++) {
            long x = scanner.nextLong();
            v.add(x);
        }
        Collections.sort(v);
        for (int i = 0; i < v.size(); i++) {
            solve(v.get(i));
        }
        System.out.println(ans);
    }
}
