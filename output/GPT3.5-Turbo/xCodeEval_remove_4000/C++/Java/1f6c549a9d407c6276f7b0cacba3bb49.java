import java.util.*;

class Main {
    static final int mod = 998244353;
    static final int K = 18;

    static class Mint {
        int n;

        Mint(int n) {
            this.n = n;
        }

        Mint add(Mint other) {
            int sum = n + other.n;
            if (sum >= mod) {
                sum -= mod;
            }
            return new Mint(sum);
        }

        Mint subtract(Mint other) {
            int diff = n - other.n;
            if (diff < 0) {
                diff += mod;
            }
            return new Mint(diff);
        }

        Mint multiply(Mint other) {
            long prod = (long) n * other.n % mod;
            return new Mint((int) prod);
        }

        Mint pow(int exp) {
            Mint result = new Mint(1);
            Mint base = new Mint(n);
            while (exp > 0) {
                if ((exp & 1) == 1) {
                    result = result.multiply(base);
                }
                base = base.multiply(base);
                exp >>= 1;
            }
            return result;
        }
    }

    static class Poly {
        int[] c;

        Poly(int size) {
            c = new int[size + 1];
        }

        int deg() {
            for (int i = c.length - 1; i >= 0; i--) {
                if (c[i] != 0) {
                    return i;
                }
            }
            return -1;
        }

        Poly add(Poly other) {
            int size = Math.max(deg(), other.deg());
            Poly result = new Poly(size);
            for (int i = 0; i <= size; i++) {
                result.c[i] = c[i] + other.c[i];
                if (result.c[i] >= mod) {
                    result.c[i] -= mod;
                }
            }
            return result;
        }

        Poly subtract(Poly other) {
            int size = Math.max(deg(), other.deg());
            Poly result = new Poly(size);
            for (int i = 0; i <= size; i++) {
                result.c[i] = c[i] - other.c[i];
                if (result.c[i] < 0) {
                    result.c[i] += mod;
                }
            }
            return result;
        }

        Poly multiply(Poly other) {
            int size = deg() + other.deg();
            Poly result = new Poly(size);
            for (int i = 0; i <= deg(); i++) {
                for (int j = 0; j <= other.deg(); j++) {
                    result.c[i + j] += (int) ((long) c[i] * other.c[j] % mod);
                    if (result.c[i + j] >= mod) {
                        result.c[i + j] -= mod;
                    }
                }
            }
            return result;
        }

        Poly divide(Poly other) {
            int size = deg() - other.deg();
            Poly result = new Poly(size);
            for (int i = deg(); i >= other.deg(); i--) {
                if (c[i] != 0) {
                    int factor = (int) ((long) c[i] * other.c[other.deg()] % mod);
                    result.c[i - other.deg()] = factor;
                    for (int j = 0; j <= other.deg(); j++) {
                        c[i - j] -= (int) ((long) factor * other.c[other.deg() - j] % mod);
                        if (c[i - j] < 0) {
                            c[i - j] += mod;
                        }
                    }
                }
            }
            return result;
        }

        Poly log() {
            int size = deg();
            Poly result = new Poly(size);
            Poly derivative = new Poly(size - 1);
            for (int i = 0; i < size; i++) {
                derivative.c[i] = (int) ((long) c[i + 1] * (i + 1) % mod);
            }
            Poly integral = derivative.divide(this);
            for (int i = 0; i < size; i++) {
                result.c[i] = integral.c[i];
                if (result.c[i] != 0) {
                    result.c[i] = (int) ((long) result.c[i] * modInverse(i + 1) % mod);
                }
            }
            return result;
        }

        Poly exp() {
            int size = deg();
            Poly result = new Poly(size);
            result.c[0] = 1;
            Poly power = new Poly(size);
            for (int i = 1; i <= size; i++) {
                power.c[i - 1] = (int) ((long) c[i] * modInverse(i) % mod);
            }
            int k = 1;
            while (k <= size) {
                power = power.multiply(power);
                if (k * 2 <= size) {
                    Poly product = power.multiply(this);
                    for (int i = k; i < Math.min(k * 2, size + 1); i++) {
                        result.c[i] = (result.c[i] + product.c[i]) % mod;
                    }
                }
                k *= 2;
            }
            return result;
        }

        int evaluate(int x) {
            int result = 0;
            for (int i = deg(); i >= 0; i--) {
                result = (int) ((long) result * x % mod + c[i]);
                if (result >= mod) {
                    result -= mod;
                }
            }
            return result;
        }

        static int modInverse(int x) {
            return new Mint(x).pow(mod - 2).n;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] hs = new int[n];
        for (int i = 0; i < n; i++) {
            hs[i] = sc.nextInt();
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (hs[i] == hs[(i + 1) % n]) {
                cnt++;
            }
        }

        if (cnt == n) {
            System.out.println(0);
            return;
        }

        Poly A = new Poly(2 * 200000 + 1000);
        A.c[0] = 1;
        A.c[1] = (k - 2) % mod;
        A.c[2] = 1;

        Poly B = A.log();
        for (int i = 0; i < B.c.length; i++) {
            B.c[i] = (int) ((long) B.c[i] * (n - cnt) % mod);
        }

        Poly C = B.exp();

        Mint ans = new Mint(k).pow(n - cnt);
        for (int i = 0; i <= n - cnt; i++) {
            ans = ans.subtract(new Mint(C.c[i]));
        }

        ans = ans.multiply(new Mint(k).pow(cnt));
        System.out.println(ans.n);
    }
}
