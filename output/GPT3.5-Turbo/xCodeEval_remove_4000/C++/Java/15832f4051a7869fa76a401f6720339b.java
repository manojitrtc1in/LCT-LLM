import java.util.*;
import java.io.*;

class Main {
    static long pow_mod(long x, long n, int m) {
        assert (0 <= n && 1 <= m);
        if (m == 1) return 0;
        long r = 1, y = (x % m + m) % m;
        while (n > 0) {
            if ((n & 1) == 1) r = r * y % m;
            y = y * y % m;
            n >>= 1;
        }
        return r;
    }

    static long inv_mod(long x, long m) {
        assert (1 <= m);
        long z = id0(x, m);
        assert (z != 0);
        return z;
    }

    static long id0(long a, long b) {
        a = safe_mod(a, b);
        if (a == 0) return b;

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
        return m0;
    }

    static long safe_mod(long x, long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    static long floor_sum(long n, long m, long a, long b) {
        long ans = 0;
        if (a >= m) {
            ans += (n - 1) * n * (a / m) / 2;
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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        long[] hh = new long[2];
        long[] aa = new long[2];
        long[] xx = new long[2];
        long[] yy = new long[2];
        for (int i = 0; i < 2; i++) {
            st = new StringTokenizer(br.readLine());
            hh[i] = Long.parseLong(st.nextToken());
            aa[i] = Long.parseLong(st.nextToken());
            xx[i] = Long.parseLong(st.nextToken());
            yy[i] = Long.parseLong(st.nextToken());
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
                        System.out.println("-1");
                        return;
                    }
                    F[i] = j + 1 - id[(int) h];
                    break;
                } else {
                    id[(int) h] = j + 1;
                    out[(int) h] = f;
                    if (h == a) {
                        f = true;
                    }
                }
            }
        }
        long d1 = F[0], c1 = F[1];
        long d2 = F[2], c2 = F[3];
        for (int i = 0; i < m * 3 + 1; i++) {
            for (int j = 0; j < 2; j++) {
                hh[j] = (hh[j] * xx[j] + yy[j]) % m;
                if (hh[0] == aa[0] && hh[1] == aa[1]) {
                    System.out.println(i + 1);
                    return;
                }
            }
        }
        if (d1 == -1 || d2 == -1) {
            System.out.println("-1");
        } else {
            long[] res = crt(new long[]{c1, c2}, new long[]{d1, d2});
            long x = res[0], y = res[1];
            if (x == 0 && y == 0) {
                System.out.println("-1");
            } else {
                long M = Math.max(c1, c2);
                if (x < M) x += ((M - x - 1) / y + 1) * y;
                System.out.println(x);
            }
        }
    }

    static long[] crt(long[] r, long[] m) {
        int n = r.length;
        long r0 = 0, m0 = 1;
        for (int i = 0; i < n; i++) {
            assert (1 <= m[i]);
            long r1 = safe_mod(r[i], m[i]), m1 = m[i];
            if (m0 < m1) {
                long tmp = r0;
                r0 = r1;
                r1 = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            if (m0 % m1 == 0) {
                if (r0 % m1 != r1) {
                    return new long[]{0, 0};
                }
                continue;
            }
            long g = gcd(m0, m1);
            if ((r1 - r0) % g != 0) {
                return new long[]{0, 0};
            }
            long u1 = m0 / g;
            long x = (r1 - r0) / g % u1 * inv_mod(m1 / g, u1) % u1;
            r0 += x * m0;
            m0 *= u1;
            if (r0 < 0) {
                r0 += m0;
            }
        }
        return new long[]{r0, m0};
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
