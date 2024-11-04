import java.util.*;
import java.io.*;

public class 15832f4051a7869fa76a401f6720339bxcodeeval_processed_4000.json {
    static long[] hh = new long[2];
    static long[] aa = new long[2];
    static long[] xx = new long[2];
    static long[] yy = new long[2];
    static int m;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextLong();
        for (int i = 0; i < 2; i++) {
            hh[i] = scanner.nextLong();
            aa[i] = scanner.nextLong();
            xx[i] = scanner.nextLong();
            yy[i] = scanner.nextLong();
        }

        Pair<Long, Long> result1 = F(0);
        Pair<Long, Long> result2 = F(1);

        for (int i = 0; i < m * 3 + 1; i++) {
            for (int j = 0; j < 2; j++) {
                hh[j] = (hh[j] * xx[j] + yy[j]) % m;
            }
            if (hh[0] == aa[0] && hh[1] == aa[1]) {
                System.out.println(i + 1);
                return;
            }
        }

        if (result1.first == -1 || result2.first == -1) {
            System.out.println(-1);
        } else {
            Pair<Long, Long> crtResult = crt(Arrays.asList(result2.second, result1.second), Arrays.asList(result2.first, result1.first));
            if (crtResult.first == 0 && crtResult.second == 0) {
                System.out.println(-1);
            } else {
                long M = Math.max(result1.second, result2.second);
                if (crtResult.first < M) {
                    crtResult.first += ((M - crtResult.first - 1) / crtResult.second + 1) * crtResult.second;
                }
                System.out.println(crtResult.first);
            }
        }
    }

    static Pair<Long, Long> F(int i) {
        long h = hh[i], a = aa[i], x = xx[i], y = yy[i];
        long[] id = new long[m];
        Arrays.fill(id, -1);
        long[] out = new long[m];
        boolean f = false;
        id[(int) h] = 0;

        for (int j = 0; j < m + 2; j++) {
            h = (h * x + y) % m;
            if (id[(int) h] != -1) {
                if (!f || out[(int) h] != 0) return new Pair<>(-1L, -1L);
                return new Pair<>((long) (j + 1 - id[(int) h]), id[(int) a]);
            } else {
                id[(int) h] = j + 1;
                out[(int) h] = f ? 1 : 0;
                if (h == a) {
                    f = true;
                }
            }
        }
        return new Pair<>(-1L, -1L);
    }

    static Pair<Long, Long> crt(List<Long> r, List<Long> m) {
        int n = r.size();
        long r0 = 0, m0 = 1;

        for (int i = 0; i < n; i++) {
            long r1 = safeMod(r.get(i), m.get(i)), m1 = m.get(i);
            if (m0 < m1) {
                long temp = r0;
                r0 = r1;
                r1 = temp;
                temp = m0;
                m0 = m1;
                m1 = temp;
            }
            if (m0 % m1 == 0) {
                if (r0 % m1 != r1) return new Pair<>(0L, 0L);
                continue;
            }

            long g = gcd(m0, m1);
            long u1 = m1 / g;

            if ((r1 - r0) % g != 0) return new Pair<>(0L, 0L);

            long x = (r1 - r0) / g % u1 * modInverse(m0 / g, u1) % u1;

            r0 += x * m0;
            m0 *= u1;

            if (r0 < 0) r0 += m0;
        }
        return new Pair<>(r0, m0);
    }

    static long safeMod(long x, long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long modInverse(long a, long m) {
        long m0 = m, t, q;
        long x0 = 0, x1 = 1;

        if (m == 1) return 0;

        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) x1 += m0;

        return x1;
    }

    static class Pair<F, S> {
        public F first;
        public S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}
