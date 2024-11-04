import java.util.*;

public class 075f823053322f46dfd0a38ad2dd4fcf_nc {
    static long bpow(int a, int b, int mod) {
        long res = a, ret = 1;
        while (b > 0) {
            if (b % 2 == 1)
                ret = (ret * res) % mod;
            res = (res * res) % mod;
            b /= 2;
        }
        return ret % mod;
    }

    static void Random() {
        long seed = System.nanoTime();
        new Random(seed);
    }

    static long fact(long n, int mod) {
        long fuc = 1;
        for (int i = 2; i <= n; ++i) {
            fuc = fuc * i % mod;
        }
        return fuc;
    }

    static long Cnk(long n, long r, int mod) {
        r = Math.min(r, n - r);
        long ans = 1;
        for (long i = n; i >= (n - r + 1); --i) {
            ans = (ans * i) % mod;
        }
        for (int i = 1; i <= r; ++i) {
            ans = (ans * bpow(i, mod - 2, mod)) % mod;
        }
        return ans;
    }

    public static void main(String[] args) {
        Random();
        
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        String a = scanner.next();
        String c = scanner.next();
        
        int s = 0, n = c.length();
        int[] t = new int[128];
        
        for (int i = 0; i < n; ++i) {
            int k = t[i];
            for (int j = 0; j < a.length(); ++j) {
                if (a.charAt(j) == c.charAt((i + k) % n)) {
                    ++k;
                }
            }
            t[i] = k;
        }
        
        for (int i = 0; i < b; ++i) {
            s += t[s % n];
        }
        
        System.out.println(s / n / d);
    }
}
