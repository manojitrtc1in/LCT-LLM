import java.util.*;
import java.io.*;

class Main {
    static long pow_mod(long x, long n, int m) {
        assert (0 <= n && 1 <= m);
        if (m == 1) return 0;
        long r = 1;
        long y = x % m;
        while (n > 0) {
            if ((n & 1) == 1) r = (r * y) % m;
            y = (y * y) % m;
            n >>= 1;
        }
        return r;
    }

    static long inv_mod(long x, long m) {
        assert (1 <= m);
        long[] z = inv_gcd(x, m);
        assert (z[0] == 1);
        return z[1];
    }

    static long[] inv_gcd(long a, long b) {
        a = safe_mod(a, b);
        if (a == 0) return new long[]{b, 0};

        long s = b, t = a;
        long m0 = 0, m1 = 1;

        while (t > 0) {
            long u = s / t;
            s -= t * u;
            m0 -= m1 * u;

            long tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }

        if (m0 < 0) m0 += b / s;
        return new long[]{s, m0};
    }

    static int primitive_root(int m) {
        if (m == 2) return 1;
        if (m == 167772161) return 3;
        if (m == 469762049) return 3;
        if (m == 754974721) return 11;
        if (m == 998244353) return 3;
        int[] divs = new int[20];
        divs[0] = 2;
        int cnt = 1;
        int x = (m - 1) / 2;
        while (x % 2 == 0) x /= 2;
        for (int i = 3; (long) (i) * i <= x; i += 2) {
            if (x % i == 0) {
                divs[cnt++] = i;
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) divs[cnt++] = x;
        for (int g = 2; ; g++) {
            boolean ok = true;
            for (int i = 0; i < cnt; i++) {
                if (pow_mod(g, (m - 1) / divs[i], m) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) return g;
        }
    }

    static long safe_mod(long x, long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    static long floor_sum(long n, long m, long a, long b) {
        long ans = 0;
        if (a >= m) {
            ans += (n - 1) * n / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        long y_max = (a * n + b) / m, x_max = (y_max * m - b);
        if (y_max == 0) return ans;
        ans += (n - (x_max + a - 1) / a) * y_max;
        ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());
        long[] hh = new long[2];
        long[] aa = new long[2];
        long[] xx = new long[2];
        long[] yy = new long[2];
        for (int i = 0; i < 2; i++) {
            String[] input = br.readLine().split(" ");
            hh[i] = Long.parseLong(input[0]);
            aa[i] = Long.parseLong(input[1]);
            xx[i] = Long.parseLong(input[2]);
            yy[i] = Long.parseLong(input[3]);
        }

        long[] F = new long[2];
        for (int i = 0; i < 2; i++) {
            long h = hh[i], a = aa[i], x = xx[i], y = yy[i];
            int[] id = new int[m];
            boolean[] out = new boolean[m];
            boolean f = false;
            id[(int) h] = 0;
            for (int j = 0; j < m + 2; j++) {
                h = (h * x + y) % m;
                if (id[(int) h] != 0) {
                    if (!f || out[(int) h]) {
                        System.out.println(-1);
                        return;
                    }
                    F[i] = j + 1 - id[(int) h];
                    break;
                } else {
                    id[(int) h] = j + 1;
                    out[(int) h] = f;
                    if (h == a) f = true;
                }
            }
        }

        long d1 = F[0];
        long c1 = aa[0];
        long d2 = F[1];
        long c2 = aa[1];

        long[] res = crt(new long[]{c1, c2}, new long[]{d1, d2});
        long x = res[0];
        long y = res[1];
        if (x == 0 && y == 0) {
            System.out.println(-1);
        } else {
            long M = Math.max(c1, c2);
            if (x < M) x += ((M - x - 1) / y + 1) * y;
            System.out.println(x);
        }
    }

    static long[] crt(long[] r, long[] m) {
        assert (r.length == m.length);
        int n = r.length;

        long r0 = 0, m0 = 1;
        for (int i = 0; i < n; i++) {
            assert (1 <= m[i]);
            long r1 = r[i] % m[i], m1 = m[i];
            if (m0 < m1) {
                long tmp = r0;
                r0 = r1;
                r1 = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            if (m0 % m1 == 0) {
                if (r0 % m1 != r1) return new long[]{0, 0};
                continue;
            }

            long g, im;
            long[] invGcd = inv_gcd(m0, m1);
            g = invGcd[0];
            im = invGcd[1];

            long u1 = (m1 / g);

            if ((r1 - r0) % g != 0) return new long[]{0, 0};

            long x = (r1 - r0) / g % u1 * im % u1;

            r0 += x * m0;
            m0 *= u1;

            if (r0 < 0) r0 += m0;
        }
        return new long[]{r0, m0};
    }
}
