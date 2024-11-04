import java.util.*;
import java.io.*;

public class 3c1638298e1e3db4c0fcd2d432b062fe_nc {
    static final int mxN = 2000005;
    static long[] fac = new long[mxN];

    static class Modular {
        static final int MOD = 998244353;
        long r;

        Modular() {
            r = 0;
        }

        Modular(long rr) {
            r = rr % MOD;
            if (r < 0) r += MOD;
        }

        Modular inv() {
            return bpow(this, MOD - 2);
        }

        Modular multiply(Modular t) {
            return new Modular((r * t.r) % MOD);
        }

        Modular divide(Modular t) {
            return multiply(t.inv());
        }

        static Modular bpow(Modular x, long n) {
            Modular res = new Modular(1);
            while (n > 0) {
                if (n % 2 == 1) res = res.multiply(x);
                x = x.multiply(x);
                n /= 2;
            }
            return res;
        }

        public String toString() {
            return Long.toString(r);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        fac[0] = 1;
        for (int i = 1; i < mxN; i++) {
            fac[i] = (fac[i - 1] * i) % Modular.MOD;
        }
        int n = sc.nextInt();
        int k = sc.nextInt();
        if (k >= n) {
            System.out.println(0);
            return;
        }
        Modular ans = new Modular(0);
        for (int i = 0; i <= n - k; i++) {
            Modular C = C(n - k, i);
            ans = ans.add(new Modular((n - k - i) % 2 == 0 ? 1 : -1).multiply(C).multiply(bpow(new Modular(i), n)));
        }
        System.out.println(new Modular(1 + (k > 0 ? 1 : 0)).multiply(ans).multiply(C(n, n - k)));
    }

    static Modular C(int n, int m) {
        return new Modular(fac[n]).divide(new Modular(fac[m])).divide(new Modular(fac[n - m]));
    }

    static Modular bpow(Modular x, int n) {
        Modular res = new Modular(1);
        while (n > 0) {
            if (n % 2 == 1) res = res.multiply(x);
            x = x.multiply(x);
            n /= 2;
        }
        return res;
    }
}
