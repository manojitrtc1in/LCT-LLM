import java.util.*;
import java.io.*;

class Main {
    static final int mod = 998244353;
    static final int B = 15;
    static final int pi = 3;
    static final int C = 1 << B;
    static final int R = 1 << B;
    static final int order = 1;
    static final int deg = 1;

    static int bsr(int x) {
        return 31 - Integer.numberOfLeadingZeros(x);
    }

    static int TEN(int n) {
        return (n == 0) ? 1 : 10 * TEN(n - 1);
    }

    static int modS(int x) {
        return (x < mod) ? x : x - mod;
    }

    static int normS(int x) {
        return (x < mod) ? x : x - mod;
    }

    static int extgcd(int a, int b, int[] x, int[] y) {
        int[] p = { a, 1, 0 };
        int[] q = { b, 0, 1 };
        while (q[0] != 0) {
            int t = p[0] / q[0];
            for (int i = 0; i < 3; i++) {
                int temp = p[i];
                p[i] = p[i] - t * q[i];
                q[i] = temp;
            }
        }
        if (p[0] < 0) {
            for (int i = 0; i < 3; i++) {
                p[i] = -p[i];
            }
        }
        x[0] = p[1];
        y[0] = p[2];
        return p[0];
    }

    static int inv(int v) {
        int[] x = new int[1];
        int[] y = new int[1];
        extgcd(v, mod, x, y);
        return normS(x[0] + mod);
    }

    static int pow(int a, int p) {
        if (p < 0) {
            return inv(pow(a, -p));
        }
        int res = 1;
        int x = a;
        while (p > 0) {
            if ((p & 1) == 1) {
                res = (int) ((long) res * x % mod);
            }
            x = (int) ((long) x * x % mod);
            p >>= 1;
        }
        return res;
    }

    static int[] multiply_ntt(int[] x, int[] y) {
        int N = x.length + y.length - 1;
        int s = bsr(N);
        assert (1 << s) == N;
        int[][] buf = new int[30][];
        for (int t = 0; t < 2; t++) {
            buf[t] = new int[N];
            for (int i = 0; i < x.length; i++) {
                buf[t][i] = x[i];
            }
            ntt(false, buf[t]);
        }
        int[] z = new int[N];
        int[] c = new int[N];
        for (int t = 0; t < 3; t++) {
            Arrays.fill(c, 0);
            for (int xt = Math.max(t - 1, 0); xt <= Math.min(1, t); xt++) {
                int yt = t - xt;
                for (int i = 0; i < N; i++) {
                    c[i] += (int) ((long) buf[xt][i] * buf[yt][i] % mod);
                    if (c[i] >= mod) {
                        c[i] -= mod;
                    }
                }
            }
            ntt(true, c);
            for (int i = 0; i < N; i++) {
                c[i] = (int) ((long) c[i] * inv(N) % mod);
                z[i] += c[i];
                if (z[i] >= mod) {
                    z[i] -= mod;
                }
            }
        }
        return z;
    }

    static void ntt(boolean type, int[] c) {
        int N = c.length;
        int s = bsr(N);
        assert (1 << s) == N;
        int[][] buf = new int[30][];
        for (int i = 0; i < s; i++) {
            int W = 1 << (s - i);
            buf[i] = new int[N];
            for (int y = 0; y < N / 2; y += W) {
                int now = (type ? mod - 1 : 1) * y * (1 << (30 - s));
                for (int x = 0; x < W; x++) {
                    int l = c[y << 1 | x];
                    int r = (int) ((long) now * c[y << 1 | x | W] % mod);
                    buf[i][y | x] = modS(l + r);
                    buf[i][y | x | N >> 1] = modS(l - r);
                }
            }
            int[] temp = c;
            c = buf[i];
            buf[i] = temp;
        }
        if (type) {
            for (int i = 0; i < N; i++) {
                c[i] = (int) ((long) c[i] * inv(N) % mod);
            }
        }
    }

    static int[] multiply_fft(int[] x, int[] y) {
        return multiply_ntt(x, y);
    }

    static int[] multiply_fft2(int[] x, int[] y) {
        int N = x.length + y.length - 1;
        int s = bsr(N);
        assert (1 << s) == N;
        int[][] buf = new int[30][];
        for (int t = 0; t < 2; t++) {
            buf[t] = new int[N];
            for (int i = 0; i < x.length; i++) {
                buf[t][i] = x[i];
            }
            ntt(false, buf[t]);
        }
        int[] z = new int[N];
        int[] c = new int[N];
        for (int t = 0; t < 3; t++) {
            Arrays.fill(c, 0);
            for (int xt = Math.max(t - 1, 0); xt <= Math.min(1, t); xt++) {
                int yt = t - xt;
                for (int i = 0; i < N; i++) {
                    c[i] += (int) ((long) buf[xt][i] * buf[yt][i] % mod);
                    if (c[i] >= mod) {
                        c[i] -= mod;
                    }
                }
            }
            ntt(true, c);
            for (int i = 0; i < N; i++) {
                c[i] = (int) ((long) c[i] * inv(N) % mod);
                z[i] += c[i];
                if (z[i] >= mod) {
                    z[i] -= mod;
                }
            }
        }
        return z;
    }

    static int[] multiply_fft(int[] x, int[] y) {
        return multiply_fft2(x, y);
    }

    static int[] multiply_fft(int[] x, int y) {
        int N = x.length;
        int[] z = new int[N];
        for (int i = 0; i < N; i++) {
            z[i] = (int) ((long) x[i] * y % mod);
        }
        return z;
    }

    static int[] multiply_fft(int x, int[] y) {
        return multiply_fft(y, x);
    }

    static int[] multiply_fft(int[] x, int[] y, int B) {
        int N = x.length + y.length - 1;
        int s = bsr(N);
        assert (1 << s) == N;
        int[][] buf = new int[30][];
        for (int t = 0; t < 2; t++) {
            buf[t] = new int[N];
            for (int i = 0; i < x.length; i++) {
                buf[t][i] = (x[i] >> (t * B)) & ((1 << B) - 1);
            }
            ntt(false, buf[t]);
        }
        int[] z = new int[N];
        int[] c = new int[N];
        int base = 1;
        for (int t = 0; t < 3; t++) {
            Arrays.fill(c, 0);
            for (int xt = Math.max(t - 1, 0); xt <= Math.min(1, t); xt++) {
                int yt = t - xt;
                for (int i = 0; i < N; i++) {
                    c[i] += (int) ((long) buf[xt][i] * buf[yt][i] % mod);
                    if (c[i] >= mod) {
                        c[i] -= mod;
                    }
                }
            }
            ntt(true, c);
            for (int i = 0; i < N; i++) {
                c[i] = (int) ((long) c[i] * inv(N) % mod);
                z[i] += (int) ((long) c[i] * base % mod);
                if (z[i] >= mod) {
                    z[i] -= mod;
                }
            }
            base *= 1 << B;
        }
        return z;
    }

    static int[] multiply_fft(int[] x, int[] y, int B) {
        return multiply_fft(x, y, B);
    }

    static int[] multiply_naive(int[] x, int[] y) {
        int N = x.length;
        int M = y.length;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                z[i + j] += (int) ((long) x[i] * y[j] % mod);
                if (z[i + j] >= mod) {
                    z[i + j] -= mod;
                }
            }
        }
        return z;
    }

    static int[] multiply_naive(int[] x, int y) {
        int N = x.length;
        int[] z = new int[N];
        for (int i = 0; i < N; i++) {
            z[i] = (int) ((long) x[i] * y % mod);
        }
        return z;
    }

    static int[] multiply_naive(int x, int[] y) {
        return multiply_naive(y, x);
    }

    static int[] multiply_naive(int[] x, int[] y, int B) {
        int N = x.length;
        int M = y.length;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                z[i + j] += (int) ((long) (x[i] >> (B * j)) & ((1 << B) - 1)) * y[j] % mod;
                if (z[i + j] >= mod) {
                    z[i + j] -= mod;
                }
            }
        }
        return z;
    }

    static int[] multiply_naive(int[] x, int[] y, int B) {
        return multiply_naive(x, y, B);
    }

    static int[] multiply(int[] x, int[] y) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y);
        }
        int B = 15;
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int y) {
        int N = x.length;
        int[] z = new int[N];
        for (int i = 0; i < N; i++) {
            z[i] = (int) ((long) x[i] * y % mod);
        }
        return z;
    }

    static int[] multiply(int x, int[] y) {
        return multiply(y, x);
    }

    static int[] multiply(int[] x, int[] y, int B) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B) {
        return multiply(x, y, B);
    }

    static int[] multiply(int[] x, int[] y, int B, int C) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C) {
        return multiply(x, y, B, C);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R) {
        return multiply(x, y, B, C, R);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg) {
        return multiply(x, y, B, C, R, order, deg);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi) {
        return multiply(x, y, B, C, R, order, deg, pi);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            int[] a = new int[t];
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] c = multiply(x, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < c.length) {
                    z[j] = (z[j] + c[j]) % mod;
                }
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] d = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < d.length) {
                    c[j] = d[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] e = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < e.length) {
                    c[j] = (c[j] + e[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - e[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf, a, b, c);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] f = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < f.length) {
                    c[j] = f[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] g = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < g.length) {
                    c[j] = (c[j] + g[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - g[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf, a, b, c, d, e);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] g = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < g.length) {
                    c[j] = g[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] h = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < h.length) {
                    c[j] = (c[j] + h[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - h[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf, a, b, c, d, e, f);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] h = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < h.length) {
                    c[j] = h[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] i = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < i.length) {
                    c[j] = (c[j] + i[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - i[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf, a, b, c, d, e, f, g);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g, int[] h) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] i = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < i.length) {
                    c[j] = i[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] j = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < j.length) {
                    c[j] = (c[j] + j[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - j[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g, int[] h) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf, a, b, c, d, e, f, g, h);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g, int[] h, int[] i) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] j = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < j.length) {
                    c[j] = j[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] k = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < k.length) {
                    c[j] = (c[j] + k[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - k[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g, int[] h, int[] i) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf, a, b, c, d, e, f, g, h, i);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g, int[] h, int[] i, int[] j) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] k = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < k.length) {
                    c[j] = k[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] m = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < m.length) {
                    c[j] = (c[j] + m[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - m[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g, int[] h, int[] i, int[] j) {
        return multiply(x, y, B, C, R, order, deg, pi, fact, ifact, buf, a, b, c, d, e, f, g, h, i, j);
    }

    static int[] multiply(int[] x, int[] y, int B, int C, int R, int order, int deg, int pi, int[] fact, int[] ifact, int[] buf, int[] a, int[] b, int[] c, int[] d, int[] e, int[] f, int[] g, int[] h, int[] i, int[] j, int[] k) {
        int N = x.length;
        int M = y.length;
        if (Math.max(N, M) <= 100) {
            return multiply_naive(x, y, B);
        }
        int s = (N + B - 1) / B;
        int t = (M + B - 1) / B;
        int[] z = new int[N + M - 1];
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            for (int j = 0; j < N; j++) {
                b[j] = x[j];
            }
            int[] k = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < k.length) {
                    c[j] = k[j];
                } else {
                    c[j] = 0;
                }
            }
            for (int j = 0; j < t; j++) {
                int l = j * B;
                int r = Math.min(l + B, M);
                for (int k = l; k < r; k++) {
                    a[j] = (a[j] << B) + y[k];
                }
            }
            int[] m = multiply(b, a);
            for (int j = 0; j < N + M - 1; j++) {
                if (j < m.length) {
                    c[j] = (c[j] + m[j]) % mod;
                }
                if (j + t < c.length) {
                    c[j + t] = (c[j + t] + mod - m[j]) % mod;
                }
            }
            for (int j = 0; j < N + M - 1; j++) {
                z[j] = (z[j] + c[j]) % mod;
                if (j + t < z.length) {
                    z[j + t] = (z[j + t] + mod - c[j]) % mod;
                }
            }
        }
        return z;
    }

