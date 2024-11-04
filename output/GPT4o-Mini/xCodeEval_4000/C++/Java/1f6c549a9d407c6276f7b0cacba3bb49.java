import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;
    static final int K = 18;

    static class Mint {
        int n;

        Mint(int n) {
            this.n = n % MOD;
            if (this.n < 0) this.n += MOD;
        }

        Mint() {
            this(0);
        }

        Mint inv() {
            return pow(MOD - 2);
        }

        Mint pow(int exp) {
            Mint result = new Mint(1);
            Mint base = new Mint(n);
            while (exp > 0) {
                if ((exp & 1) == 1) result = result.mul(base);
                base = base.mul(base);
                exp >>= 1;
            }
            return result;
        }

        Mint mul(Mint other) {
            return new Mint((int) ((long) n * other.n % MOD));
        }

        Mint add(Mint other) {
            return new Mint(n + other.n);
        }

        Mint sub(Mint other) {
            return new Mint(n - other.n);
        }

        @Override
        public String toString() {
            return String.valueOf(n);
        }
    }

    static class Poly {
        Mint[] c;

        Poly(int n) {
            c = new Mint[n + 1];
            Arrays.fill(c, new Mint());
        }

        int deg() {
            return c.length - 1;
        }

        Poly log() {
            assert c[0].n == 1;
            int n = deg();
            Poly g = new Poly(n);
            for (int i = 0; i < n; i++) {
                g.c[i] = new Mint(i + 1).mul(c[i + 1]);
            }
            return g;
        }

        Poly exp() {
            assert c[0].n == 0;
            int n = deg();
            Poly result = new Poly(n);
            result.c[0] = new Mint(1);
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    result.c[i] = result.c[i].add(new Mint(c[j].n).mul(result.c[i - j - 1]));
                }
            }
            return result;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] hs = new int[n];
        for (int i = 0; i < n; i++) {
            hs[i] = scanner.nextInt();
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (hs[i] == hs[(i + 1) % n]) cnt++;
        }

        if (cnt == n) {
            System.out.println(0);
            return;
        }

        Poly A = new Poly(200000 + 1000);
        A.c[0] = new Mint(1);
        A.c[1] = new Mint((k - 2) % MOD);
        A.c[2] = new Mint(1);

        Poly B = A.log();
        for (int i = 0; i < B.c.length; i++) {
            B.c[i] = new Mint(B.c[i].n * (n - cnt) % MOD);
        }

        Poly C = B.exp();

        Mint ans = new Mint((int) Math.pow(k % MOD, n - cnt));
        for (int i = 0; i <= n - cnt; i++) {
            ans = ans.sub(C.c[i]);
        }

        ans = ans.mul(new Mint((int) Math.pow(k % MOD, cnt)));
        System.out.println(ans);
    }
}
