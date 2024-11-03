import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;
    static final int K = 18;

    static class Mint {
        int n;

        Mint(int n) {
            this.n = n;
        }

        Mint() {
            this(0);
        }

        Mint add(Mint other) {
            int sum = n + other.n;
            if (sum >= MOD) {
                sum -= MOD;
            }
            return new Mint(sum);
        }

        Mint subtract(Mint other) {
            int diff = n - other.n;
            if (diff < 0) {
                diff += MOD;
            }
            return new Mint(diff);
        }

        Mint multiply(Mint other) {
            long product = (long) n * other.n % MOD;
            return new Mint((int) product);
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

        Mint inverse() {
            return pow(MOD - 2);
        }
    }

    static class Poly {
        int[] c;

        Poly(int n) {
            c = new int[n + 1];
        }

        Poly() {
            this(0);
        }

        int deg() {
            int d = c.length - 1;
            while (d >= 0 && c[d] == 0) {
                d--;
            }
            return d;
        }

        Mint at(int n) {
            if (n < c.length) {
                return new Mint(c[n]);
            } else {
                return new Mint();
            }
        }

        void add(Poly other) {
            int maxDeg = Math.max(deg(), other.deg());
            int[] d = new int[maxDeg + 1];
            for (int i = 0; i <= deg(); i++) {
                d[i] = c[i];
            }
            for (int i = 0; i <= other.deg(); i++) {
                d[i] = d[i].add(other.at(i)).n;
            }
            c = d;
        }

        void subtract(Poly other) {
            int maxDeg = Math.max(deg(), other.deg());
            int[] d = new int[maxDeg + 1];
            for (int i = 0; i <= deg(); i++) {
                d[i] = c[i];
            }
            for (int i = 0; i <= other.deg(); i++) {
                d[i] = d[i].subtract(other.at(i)).n;
            }
            c = d;
        }

        void multiply(Poly other) {
            int maxDeg = deg() + other.deg();
            int k = 32 - Integer.numberOfLeadingZeros(maxDeg);
            int[] d = new int[1 << k];
            int[] e = new int[1 << k];
            for (int i = 0; i <= deg(); i++) {
                d[i] = c[i];
            }
            for (int i = 0; i <= other.deg(); i++) {
                e[i] = other.at(i).n;
            }
            fft(d, k, false);
            fft(e, k, false);
            for (int i = 0; i < (1 << k); i++) {
                d[i] = new Mint(d[i]).multiply(new Mint(e[i])).n;
            }
            fft(d, k, true);
            c = Arrays.copyOf(d, maxDeg + 1);
        }

        Poly quotient(Poly Q) {
            if (Q.deg() > deg()) {
                return new Poly();
            }
            if (Q.deg() < 32) {
                int dQ = Q.deg();
                while (dQ >= 0 && Q.c[dQ] == 0) {
                    dQ--;
                }
                if (dQ < 0) {
                    return new Poly();
                }
                int[] d = Arrays.copyOf(c, c.length);
                for (int i = deg(); i >= dQ; i--) {
                    if (d[i] == 0) {
                        continue;
                    }
                    Mint x = new Mint(d[i]).multiply(new Mint(Q.c[dQ]).inverse());
                    d[i] = 0;
                    for (int j = 1; j <= dQ; j++) {
                        d[i - j] = new Mint(d[i - j]).subtract(new Mint(x.n).multiply(new Mint(Q.c[dQ - j]).n)).n;
                    }
                }
                int dP = dQ - 1;
                while (dP >= 0 && d[dP] == 0) {
                    dP--;
                }
                return new Poly(Arrays.copyOf(d, dP + 1));
            }
            Poly P = quotient(Q);
            int n = deg() - Q.deg();
            int k = 32 - Integer.numberOfLeadingZeros(n);
            int[] v = new int[1 << k];
            int[] w = new int[1 << k];
            for (int i = 0; i <= P.deg(); i++) {
                w[i] = P.c[i];
            }
            fft(w, k, false);
            for (int i = 0; i <= Q.deg(); i++) {
                v[i] = Q.c[i];
            }
            fft(v, k, false);
            for (int i = 0; i < (1 << k); i++) {
                w[i] = new Mint(w[i]).multiply(new Mint(v[i])).n;
            }
            fft(w, k, true);
            Mint im = new Mint((MOD + 1) / 2).pow(k);
            int dR = -1;
            for (int i = 0; i < Q.deg(); i++) {
                w[i] = new Mint(c[i]).subtract(new Mint(w[i]).multiply(im)).n;
                if (w[i] != 0) {
                    dR = i;
                }
            }
            int[] d = Arrays.copyOf(w, dR + 1);
            return new Poly(d);
        }

        void fft(int[] a, int k, boolean invert) {
            int n = 1 << k;
            for (int i = 1, j = 0; i < n; i++) {
                int bit = n >> 1;
                for (; j >= bit; bit >>= 1) {
                    j -= bit;
                }
                j += bit;
                if (i < j) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            for (int len = 2; len <= n; len <<= 1) {
                int wlen = invert ? rootInverse(len) : root(len);
                for (int i = 0; i < n; i += len) {
                    int w = 1;
                    for (int j = 0; j < len / 2; j++) {
                        int u = a[i + j];
                        int v = new Mint(a[i + j + len / 2]).multiply(new Mint(w)).n;
                        a[i + j] = u + v;
                        if (a[i + j] >= MOD) {
                            a[i + j] -= MOD;
                        }
                        a[i + j + len / 2] = u - v;
                        if (a[i + j + len / 2] < 0) {
                            a[i + j + len / 2] += MOD;
                        }
                        w = new Mint(w).multiply(new Mint(wlen)).n;
                    }
                }
            }
            if (invert) {
                int nInv = new Mint(n).inverse().n;
                for (int i = 0; i < n; i++) {
                    a[i] = new Mint(a[i]).multiply(new Mint(nInv)).n;
                }
            }
        }

        int root(int len) {
            int root = 2;
            while (true) {
                int exp = MOD - 1;
                int rem = exp % len;
                exp /= len;
                boolean ok = true;
                while (exp > 0) {
                    if (rem % 2 == 0) {
                        ok = false;
                        break;
                    }
                    rem /= 2;
                    exp /= 2;
                }
                if (ok) {
                    return new Mint(root).pow((MOD - 1) / len).n;
                }
                root++;
            }
        }

        int rootInverse(int len) {
            int root = 2;
            while (true) {
                int exp = MOD - 1;
                int rem = exp % len;
                exp /= len;
                boolean ok = true;
                while (exp > 0) {
                    if (rem % 2 == 0) {
                        ok = false;
                        break;
                    }
                    rem /= 2;
                    exp /= 2;
                }
                if (ok) {
                    return new Mint(root).pow(MOD - 1 - (MOD - 1) / len).n;
                }
                root++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] hs = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            hs[i] = Integer.parseInt(st.nextToken());
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

        Poly A = new Poly((int) 2e5 + 1000);
        A.c[0] = 1;
        A.c[1] = (k - 2) % MOD;
        A.c[2] = 1;

        Poly B = A.log();
        for (int i = 0; i < B.c.length; i++) {
            B.c[i] = new Mint(B.c[i]).multiply(new Mint(n - cnt)).n;
        }

        Poly C = B.exp();

        Mint ans = new Mint(k % MOD).pow(n - cnt);
        for (int i = 0; i <= n - cnt; i++) {
            ans = ans.subtract(new Mint(C.c[i]));
        }

        ans = ans.multiply(new Mint(k % MOD).pow(cnt));
        System.out.println(ans.n);
    }
}
