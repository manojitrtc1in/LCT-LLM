import java.util.*;
import java.util.stream.*;

public class 15832f4051a7869fa76a401f6720339b_nc {
    static long safeMod(long x, long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    static class Barrett {
        int m;
        long im;

        Barrett(int m) {
            this.m = m;
            this.im = (long) (-1) / m + 1;
        }

        int umod() {
            return m;
        }

        int mul(int a, int b) {
            long z = (long) a * b;
            long x = (z * im) >> 64;
            int v = (int) (z - x * m);
            if (m <= v) v += m;
            return v;
        }
    }

    static long powMod(long x, long n, int m) {
        if (m == 1) return 0;
        Barrett bt = new Barrett(m);
        int r = 1, y = (int) safeMod(x, m);
        while (n > 0) {
            if ((n & 1) == 1) r = bt.mul(r, y);
            y = bt.mul(y, y);
            n >>= 1;
        }
        return r;
    }

    static long invMod(long x, long m) {
        long[] gcd = invGcd(x, m);
        return gcd[1];
    }

    static long[] invGcd(long a, long b) {
        a = safeMod(a, b);
        if (a == 0) return new long[]{b, 0};

        long s = b, t = a;
        long m0 = 0, m1 = 1;

        while (t != 0) {
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

    static long[] crt(List<Long> r, List<Long> m) {
        int n = r.size();
        long r0 = 0, m0 = 1;
        for (int i = 0; i < n; i++) {
            long r1 = safeMod(r.get(i), m.get(i)), m1 = m.get(i);
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

            long[] gcd = invGcd(m0, m1);
            long g = gcd[0], im = gcd[1];

            long u1 = m1 / g;

            if ((r1 - r0) % g != 0) return new long[]{0, 0};

            long x = (r1 - r0) / g % u1 * im % u1;

            r0 += x * m0;
            m0 *= u1;

            if (r0 < 0) r0 += m0;
        }
        return new long[]{r0, m0};
    }

    static long floorSum(long n, long m, long a, long b) {
        long ans = 0;
        if (a >= m) {
            ans += (n - 1) * n * (a / m) / 2;
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        long yMax = (a * n + b) / m, xMax = (yMax * m - b);
        if (yMax == 0) return ans;
        ans += (n - (xMax + a - 1) / a) * yMax;
        ans += floorSum(yMax, a, m, (a - xMax % a + a) % a);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long m = sc.nextLong();
        long[] hh = new long[2], aa = new long[2], xx = new long[2], yy = new long[2];
        for (int i = 0; i < 2; i++) {
            hh[i] = sc.nextLong();
            aa[i] = sc.nextLong();
            xx[i] = sc.nextLong();
            yy[i] = sc.nextLong();
        }

        Function<Integer, long[]> F = (i) -> {
            long h = hh[i], a = aa[i], x = xx[i], y = yy[i];
            int[] id = new int[(int) m];
            Arrays.fill(id, -1);
            boolean f = false;
            id[(int) h] = 0;
            for (int j = 0; j < m + 2; j++) {
                h = (h * x + y) % m;
                if (id[(int) h] != -1) {
                    if (!f || id[(int) h] == -1) return new long[]{-1, -1};
                    return new long[]{j + 1 - id[(int) h], id[(int) a]};
                } else {
                    id[(int) h] = j + 1;
                    if (h == a) {
                        f = true;
                    }
                }
            }
            return new long[]{-1, -1};
        };

        long[] res1 = F.apply(0);
        long[] res2 = F.apply(1);
        for (int i = 0; i < m * 3 + 1; i++) {
            for (int j = 0; j < 2; j++) {
                hh[j] = (hh[j] * xx[j] + yy[j]) % m;
            }
            if (hh[0] == aa[0] && hh[1] == aa[1]) {
                System.out.println(i + 1);
                return;
            }
        }

        if (res1[0] == -1 || res2[0] == -1) {
            System.out.println(-1);
        } else {
            long[] crtRes = crt(Arrays.asList(res2[1], res1[1]), Arrays.asList(res2[0], res1[0]));
            if (crtRes[0] == 0 && crtRes[1] == 0) {
                System.out.println(-1);
            } else {
                long M = Math.max(res1[1], res2[1]);
                if (crtRes[0] < M) {
                    crtRes[0] += ((M - crtRes[0] - 1) / crtRes[1] + 1) * crtRes[1];
                }
                System.out.println(crtRes[0]);
            }
        }
    }
}
