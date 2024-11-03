import java.util.*;

class Main {
    static final int MOD = 998244353;
    static final int K = 18;

    static class Mint {
        int n;

        Mint(int n) {
            this.n = n;
        }

        Mint add(Mint other) {
            return new Mint((n + other.n) % MOD);
        }

        Mint subtract(Mint other) {
            return new Mint((n - other.n + MOD) % MOD);
        }

        Mint multiply(Mint other) {
            return new Mint((int) ((long) n * other.n % MOD));
        }

        Mint divide(Mint other) {
            return new Mint((int) ((long) n * inverse(other.n) % MOD));
        }

        Mint pow(int p) {
            Mint result = new Mint(1);
            Mint base = new Mint(n);
            while (p > 0) {
                if ((p & 1) != 0) {
                    result = result.multiply(base);
                }
                base = base.multiply(base);
                p >>= 1;
            }
            return result;
        }

        Mint inverse(int a) {
            return new Mint(a).pow(MOD - 2);
        }
    }

    static class Poly {
        int[] c;

        Poly(int n) {
            c = new int[n + 1];
        }

        int deg() {
            for (int i = c.length - 1; i >= 0; i--) {
                if (c[i] != 0) {
                    return i;
                }
            }
            return -1;
        }

        Mint at(int n) {
            if (n < c.length) {
                return new Mint(c[n]);
            } else {
                return new Mint(0);
            }
        }

        void add(Poly other) {
            int[] d = new int[Math.max(c.length, other.c.length)];
            for (int i = 0; i < c.length; i++) {
                d[i] = c[i];
            }
            for (int i = 0; i < other.c.length; i++) {
                d[i] = (d[i] + other.c[i]) % MOD;
            }
            c = d;
        }

        void subtract(Poly other) {
            int[] d = new int[Math.max(c.length, other.c.length)];
            for (int i = 0; i < c.length; i++) {
                d[i] = c[i];
            }
            for (int i = 0; i < other.c.length; i++) {
                d[i] = (d[i] - other.c[i] + MOD) % MOD;
            }
            c = d;
        }

        void multiply(Poly other) {
            int[] d = new int[c.length + other.c.length - 1];
            for (int i = 0; i < c.length; i++) {
                for (int j = 0; j < other.c.length; j++) {
                    d[i + j] = (d[i + j] + (int) ((long) c[i] * other.c[j] % MOD)) % MOD;
                }
            }
            c = d;
        }

        void divide(Poly other) {
            int dP = deg();
            while (dP >= 0 && c[dP] == 0) {
                dP--;
            }
            if (dP < 0) {
                c = new int[0];
                return;
            }
            int dQ = other.deg();
            while (dQ >= 0 && other.c[dQ] == 0) {
                dQ--;
            }
            if (dQ > dP) {
                c = new int[0];
                return;
            }
            Poly RQ = new Poly(Math.min(dQ, dP - dQ));
            for (int j = 0; j <= Math.min(dQ, dP - dQ); j++) {
                RQ.c[j] = other.c[dQ - j];
            }

            int k = 32 - Integer.numberOfLeadingZeros(dP - dQ);
            int[] rp = new int[1 << k];
            for (int j = 0; j <= dP - dQ; j++) {
                rp[j] = c[dP - j];
            }

            RQ = RQ.inverse(dP - dQ);

            int[] rq = new int[1 << k];
            for (int i = 0; i <= dP - dQ; i++) {
                rq[i] = RQ.c[i];
            }

            fft(rp, k);
            fft(rq, k);

            for (int i = 0; i < (1 << k); i++) {
                rq[i] = (int) ((long) rq[i] * rp[i] % MOD);
            }

            ifft(rq, k);

            Mint im = new Mint((MOD + 1) / 2).pow(k);
            for (int i = 0; i <= dP - dQ; i++) {
                c[i] = (int) ((long) rq[dP - dQ - i] * im.n % MOD);
            }
            c = Arrays.copyOf(c, dP - dQ + 1);
        }

        Poly inverse(int n) {
            if (c[0] == 0) {
                throw new IllegalArgumentException("Cannot compute inverse of polynomial with constant term 0");
            }
            if (n == -1) {
                n = deg();
            }
            if (n == -1) {
                return this;
            }
            int k = 32 - Integer.numberOfLeadingZeros(n);
            int[] d = new int[1 << k];
            int[] ee = new int[1 << k];
            Poly r = new Poly(n);
            r.c[0] = new Mint(c[0]).inverse().n;
            int y = (MOD + 1) / 2;
            if ((y & 1) != 0) {
                y += MOD;
            }
            y /= 2;
            Mint im = new Mint(MOD - y);
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < (1 << i + 1); j++) {
                    d[j] = at(j).n;
                }
                fft(d, i + 1);
                for (int j = 0; j < (1 << i); j++) {
                    ee[j] = r.c[j];
                }
                fft(ee, i + 1);
                for (int j = 0; j < (1 << i + 1); j++) {
                    d[j] = (int) ((long) d[j] * ee[j] % MOD);
                }
                ifft(d, i + 1);
                for (int j = 0; j < (1 << i); j++) {
                    d[j] = d[j + (1 << i)];
                    d[j + (1 << i)] = 0;
                }
                fft(d, i + 1);
                for (int j = 0; j < (1 << i + 1); j++) {
                    d[j] = (int) ((long) d[j] * ee[j] % MOD);
                }
                ifft(d, i + 1);
                for (int j = 1 << i; j < Math.min(1 << i + 1, n + 1); j++) {
                    r.c[j] = (int) ((long) d[j] * im.n % MOD);
                }

                if ((im.n & 1) != 0) {
                    im.n += MOD;
                }
                im.n /= 2;
                if ((im.n & 1) != 0) {
                    im.n += MOD;
                }
                im.n /= 2;
            }
            return r;
        }

        Poly sqrt(int n) {
            if (n == -1) {
                n = deg();
            }
            if (n == -1) {
                return this;
            }
            if (c[0] == 1) {
                int k = 32 - Integer.numberOfLeadingZeros(n);
                int[] d = new int[1 << k + 1];
                int[] ee = new int[1 << k + 1];
                int[] f = new int[1 << k];
                int[] gg = new int[1 << k + 1];
                int[] G = new int[1 << k + 1];
                f[0] = 1;
                f[1] = c[1];
                gg[0] = 1;
                G[0] = G[1] = 1;
                int y = (MOD + 1) / 2;
                if ((y & 1) != 0) {
                    y += MOD;
                }
                y /= 2;
                if ((y & 1) != 0) {
                    y += MOD;
                }
                y /= 2;
                Mint im = new Mint(MOD - y);
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < 1 << i + 1; j++) {
                        ee[j] = f[j] * im.n % MOD;
                    }
                    fft(ee, i + 2);
                    for (int j = 0; j < 1 << i; j++) {
                        gg[j] = G[j];
                    }
                    for (int j = 0; j < 1 << i - 1; j++) {
                        gg[j + (1 << i)] = fft.v[j << K - i] * gg[j];
                    }
                    fft(ee, i + 2);
                    fft(gg, i + 2);
                    for (int j = 0; j < 1 << i + 2; j++) {
                        ee[j] = (int) ((long) ee[j] * gg[j] % MOD);
                    }
                    ifft(ee, i + 2);
                    for (int j = 1 << i; j < Math.min(1 << i + 1, n + 1); j++) {
                        c[j] = ee[j] * im.n % MOD;
                    }
                    if ((im.n & 1) != 0) {
                        im.n += MOD;
                    }
                    im.n /= 2;
                }
                Poly r = new Poly(n);
                for (int i = 0; i <= n; i++) {
                    r.c[i] = c[i];
                }
                return r;
            } else {
                throw new IllegalArgumentException("Cannot compute square root of polynomial without constant term 1");
            }
        }

        Poly exp(int n) {
            if (n == -1) {
                n = deg();
            }
            if (n == -1) {
                return this;
            }
            if (c[0] == 0) {
                throw new IllegalArgumentException("Cannot compute exponential of polynomial with constant term 0");
            }
            int k = 32 - Integer.numberOfLeadingZeros(n);
            int[] d = new int[1 << k];
            int[] e = new int[1 << k];
            int[] f = new int[1 << k];
            int[] gg = new int[1 << k];
            int[] G = new int[1 << k];
            int[] FT = new int[1 << k + 1];
            d[0] = 1;
            d[1] = c[0];
            e[0] = 1;
            G[0] = G[1] = 1;
            int y = (MOD + 1) / 2;
            if ((y & 1) != 0) {
                y += MOD;
            }
            y /= 2;
            Mint im = new Mint(y);
            for (int i = 1; i <= k; i++) {
                for (int j = 0; j < 1 << k - i; j++) {
                    int t = 1 << k - i + 1 + 2 * j + 1;
                    f[j] = d[j] + 1;
                    for (int l = 0; l < 1 << i - 1; l++) {
                        FT[2 * t + l] = f[j] * f[j] - 1;
                    }
                    ifft(d, i - 1);
                    for (int l = 0; l < 1 << i - 1; l++) {
                        d[l] = d[l] * im.n % MOD;
                    }
                    for (int l = 0; l < 1 << i - 1; l++) {
                        FT[2 * t + (1 << i - 1) + l] = d[l] * fft.v[l << K - i + 1] % MOD;
                    }
                    FT[2 * t + (1 << i - 1)]--;
                    fft(FT, i - 1);
                    for (int l = 0; l < 1 << i; l++) {
                        FT[2 * t + l] = FT[2 * t + l] * FT[2 * t + l] % MOD - 1;
                    }
                    for (int l = 0; l < 1 << i; l++) {
                        gg[l] = G[l];
                    }
                    fft(FT, i);
                    fft(gg, i);
                    for (int l = 0; l < 1 << i + 1; l++) {
                        FT[l] = FT[l] * gg[l] % MOD;
                    }
                    ifft(FT, i + 1);
                    for (int l = 0; l < 1 << i; l++) {
                        FT[l] = FT[l + (1 << i)];
                        FT[l + (1 << i)] = 0;
                    }
                    fft(FT, i);
                    for (int l = 0; l < 1 << i + 1; l++) {
                        FT[l] = FT[l] * gg[l] % MOD;
                    }
                    ifft(FT, i + 1);
                    for (int l = 1 << i; l < Math.min(1 << i + 1, n + 1); l++) {
                        c[l] = FT[l] * im.n % MOD;
                    }
                    if ((im.n & 1) != 0) {
                        im.n += MOD;
                    }
                    im.n /= 2;
                }
                for (int j = 0; j < 1 << i; j++) {
                    int t = 1 << k - i + 1 + 2 * j;
                    for (int l = 0; l < 1 << i; l++) {
                        FT[2 * t + l] = e[j] + 1;
                    }
                    ifft(e, i - 1);
                    for (int l = 0; l < 1 << i - 1; l++) {
                        e[l] = e[l] * im.n % MOD;
                    }
                    for (int l = 0; l < 1 << i - 1; l++) {
                        FT[2 * t + (1 << i - 1) + l] = e[l] * fft.v[l << K - i + 1] % MOD;
                    }
                    FT[2 * t + (1 << i - 1)]--;
                    fft(FT, i - 1);
                    for (int l = 0; l < 1 << i; l++) {
                        FT[2 * t + l] = FT[2 * t + l] * FT[2 * t + l] % MOD - 1;
                    }
                    for (int l = 0; l < 1 << i; l++) {
                        gg[l] = G[l];
                    }
                    fft(FT, i);
                    fft(gg, i);
                    for (int l = 0; l < 1 << i + 1; l++) {
                        FT[l] = FT[l] * gg[l] % MOD;
                    }
                    ifft(FT, i + 1);
                    for (int l = 0; l < 1 << i; l++) {
                        FT[l] = FT[l + (1 << i)];
                        FT[l + (1 << i)] = 0;
                    }
                    fft(FT, i);
                    for (int l = 0; l < 1 << i + 1; l++) {
                        FT[l] = FT[l] * gg[l] % MOD;
                    }
                    ifft(FT, i + 1);
                    for (int l = 0; l < 1 << i; l++) {
                        e[l] = c[l + (1 << i)] - FT[l] * im.n % MOD;
                    }
                    for (int l = 1 << i; l < Math.min(1 << i + 1, n + 1); l++) {
                        c[l] = 0;
                    }
                }
                for (int j = 0; j < 1 << i; j++) {
                    int t = 1 << k - i + 1 + 2 * j;
                    for (int l = 0; l < 1 << i; l++) {
                        FT[2 * t + l] = c[l] * (2 * l + 2);
                    }
                    FT[2 * t + (1 << i)] = 0;
                    fft(FT, i);
                    for (int l = 0; l < 1 << i; l++) {
                        FT[2 * t + l] = FT[2 * t + l] - FT[2 * t + l + 1];
                    }
                    FT[2 * t] = FT[2 * t] * im.n % MOD;
                    for (int l = 1 << i; l < Math.min(1 << i + 1, n + 1); l++) {
                        c[l] = c[l] - FT[2 * t + l - 1];
                    }
                    for (int l = 1 << i; l < Math.min(1 << i + 1, n + 1); l++) {
                        FT[2 * t + l] = 0;
                    }
                    fft(FT, i + 1);
                    for (int l = 0; l < 1 << i; l++) {
                        FT[2 * t + l] = FT[2 * t + l] * gg[l] % MOD;
                    }
                    ifft(FT, i + 1);
                    for (int l = 0; l < 1 << i; l++) {
                        FT[2 * t + l] = c[l + (1 << i)] - FT[2 * t + l] * minv[(1 << i) + l] * im.n % MOD;
                    }
                    for (int l = 1 << i; l < Math.min(1 << i + 1, n + 1); l++) {
                        FT[2 * t + l] = 0;
                    }
                    fft(FT, i + 1);
                    for (int l = 0; l < 1 << i + 1; l++) {
                        FT[l] = FT[l] * gg[l] % MOD;
                    }
                    ifft(FT, i + 1);
                    for (int l = 0; l < 1 << i; l++) {
                        c[l + (1 << i)] = FT[l];
                    }
                }
            }
            Poly r = new Poly(n);
            for (int i = 0; i <= n; i++) {
                r.c[i] = c[i];
            }
            return r;
        }

        Poly quotient(Poly Q) {
            int dP = deg();
            while (dP >= 0 && c[dP] == 0) {
                dP--;
            }
            if (dP < 0) {
                return new Poly(0);
            }
            int dQ = Q.deg();
            while (dQ >= 0 && Q.c[dQ] == 0) {
                dQ--;
            }
            if (dQ > dP) {
                return new Poly(0);
            }
            Poly RQ = new Poly(Math.min(dQ, dP - dQ));
            for (int j = 0; j <= Math.min(dQ, dP - dQ); j++) {
                RQ.c[j] = Q.c[dQ - j];
            }

            int k = 32 - Integer.numberOfLeadingZeros(dP - dQ);
            int[] rp = new int[1 << k];
            for (int j = 0; j <= dP - dQ; j++) {
                rp[j] = c[dP - j];
            }

            RQ.divide(rp, k);

            int[] rq = new int[1 << k];
            for (int i = 0; i <= dP - dQ; i++) {
                rq[i] = RQ.c[i];
            }

            fft(rp, k);
            fft(rq, k);

            for (int i = 0; i < (1 << k); i++) {
                rq[i] = (int) ((long) rq[i] * inverse(rp[i]) % MOD);
            }

            ifft(rq, k);

            Mint im = new Mint((MOD + 1) / 2).pow(k);
            int dR = -1;
            for (int i = 0; i < Q.deg(); i++) {
                rq[i] = c[i] - (int) ((long) rq[i] * im.n % MOD);
                if (rq[i] != 0) {
                    dR = i;
                }
            }
            c = Arrays.copyOf(rq, dR + 1);
            return this;
        }

        Mint eval(Mint x) {
            Mint r = new Mint(0);
            for (int i = deg(); i >= 0; i--) {
                r = r.multiply(x).add(new Mint(c[i]));
            }
            return r;
        }

        int[] eval2(int[] P) {
            int m = P.length;
            if (m <= (1 << _ls)) {
                int[] v = new int[m];
                for (int i = 0; i < m; i++) {
                    v[i] = eval(new Mint(P[i])).n;
                }
                return v;
            }
            int k = 32 - Integer.numberOfLeadingZeros(m - 1);
            int[] v = new int[m];
            int[] w = new int[m];
            for (int i = 0; i < m; i++) {
                w[i] = P[i];
            }
            fft(w, _ls);
            if (_ls == 0) {
                w[0] = 1;
            }

            for (int i = 0; i < (1 << k); i++) {
                v[i] = eval(new Mint(w[i])).n;
            }

            return v;
        }

        Poly interpolation(int[] a, int[] b) {
            int m = a.length;
            if (b.length != m) {
                throw new IllegalArgumentException("Input arrays must have the same length");
            }

            return new Poly(0);
        }

        private static final int _ls = 0;

        private static void fft(int[] a, int k) {
            int n = 1 << k;
            for (int i = 0; i < n; i++) {
                int j = Integer.reverse(i) >>> 32 - k;
                if (i < j) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            for (int s = 1; s <= k; s++) {
                int m = 1 << s;
                int[] wm = new int[m / 2];
                for (int j = 0; j < m / 2; j++) {
                    wm[j] = new Mint(3).pow((MOD - 1) / m * j).n;
                }
                for (int j = 0; j < n; j += m) {
                    for (int k1 = 0; k1 < m / 2; k1++) {
                        int u = a[j + k1];
                        int v = (int) ((long) a[j + k1 + m / 2] * wm[k1] % MOD);
                        a[j + k1] = (u + v) % MOD;
                        a[j + k1 + m / 2] = (u - v + MOD) % MOD;
                    }
                }
            }
        }

        private static void ifft(int[] a, int k) {
            fft(a, k);
            int n = 1 << k;
            int inv = new Mint(n).inverse().n;
            for (int i = 0; i < n; i++) {
                a[i] = (int) ((long) a[i] * inv % MOD);
            }
            for (int i = 0; i < n / 2; i++) {
                int temp = a[i];
                a[i] = a[n - 1 - i];
                a[n - 1 - i] = temp;
            }
        }

        private static int inverse(int a) {
            return new Mint(a).inverse().n;
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
            B.c[i] = B.c[i].multiply(new Mint(n - cnt));
        }

        Poly C = B.exp();

        Mint ans = new Mint(k % MOD).pow(n - cnt);
        for (int i = 0; i <= n - cnt; i++) {
            ans = ans.subtract(C.c[i]);
        }

        ans = ans.multiply(new Mint(k % MOD).pow(cnt));
        System.out.println(ans.n);
    }
}
