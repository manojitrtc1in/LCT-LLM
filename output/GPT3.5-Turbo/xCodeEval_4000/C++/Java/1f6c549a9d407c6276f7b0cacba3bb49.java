import java.util.*;

class Main {
    static final int mod = 998244353;
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

        Mint pow(int p) {
            Mint result = new Mint(1);
            Mint base = new Mint(n);
            while (p > 0) {
                if ((p & 1) == 1) {
                    result = result.multiply(base);
                }
                base = base.multiply(base);
                p >>= 1;
            }
            return result;
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
            for (int i = 0; i <= maxDeg; i++) {
                d[i] = at(i).add(other.at(i)).n;
            }
            c = d;
        }

        void subtract(Poly other) {
            int maxDeg = Math.max(deg(), other.deg());
            int[] d = new int[maxDeg + 1];
            for (int i = 0; i <= maxDeg; i++) {
                d[i] = at(i).subtract(other.at(i)).n;
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
                e[i] = other.c[i];
            }
            fft(d, k, false);
            fft(e, k, false);
            for (int i = 0; i < (1 << k); i++) {
                d[i] = (int) ((long) d[i] * e[i] % mod);
            }
            fft(d, k, true);
            c = d;
        }

        void divide(Poly other) {
            if (other.deg() > deg()) {
                c = new int[0];
                return;
            }
            int[] d = new int[c.length];
            for (int i = 0; i < c.length; i++) {
                d[i] = c[i];
            }
            int[] q = new int[c.length - other.deg()];
            int[] r = new int[other.deg()];
            for (int i = 0; i < q.length; i++) {
                q[i] = 0;
            }
            for (int i = 0; i < r.length; i++) {
                r[i] = 0;
            }
            int inv = new Mint(other.c[other.deg()]).pow(mod - 2).n;
            for (int i = c.length - 1; i >= other.deg(); i--) {
                int coef = (int) ((long) d[i] * inv % mod);
                q[i - other.deg()] = coef;
                for (int j = 0; j < other.deg(); j++) {
                    d[i - other.deg() + j] -= (int) ((long) coef * other.c[j] % mod);
                    if (d[i - other.deg() + j] < 0) {
                        d[i - other.deg() + j] += mod;
                    }
                }
            }
            c = q;
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
                int wlen = invert ? rootInverse[k] : root[k];
                for (int i = len; i < rootPower[k]; i <<= 1) {
                    wlen = (int) ((long) wlen * wlen % mod);
                }
                for (int i = 0; i < n; i += len) {
                    int w = 1;
                    for (int j = 0; j < len / 2; j++) {
                        int u = a[i + j];
                        int v = (int) ((long) a[i + j + len / 2] * w % mod);
                        a[i + j] = u + v;
                        if (a[i + j] >= mod) {
                            a[i + j] -= mod;
                        }
                        a[i + j + len / 2] = u - v;
                        if (a[i + j + len / 2] < 0) {
                            a[i + j + len / 2] += mod;
                        }
                        w = (int) ((long) w * wlen % mod);
                    }
                }
            }
            if (invert) {
                int nInv = new Mint(n).pow(mod - 2).n;
                for (int i = 0; i < n; i++) {
                    a[i] = (int) ((long) a[i] * nInv % mod);
                }
            }
        }
    }

