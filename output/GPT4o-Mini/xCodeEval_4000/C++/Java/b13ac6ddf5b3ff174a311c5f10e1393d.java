import java.util.*;
import java.io.*;

public class b13ac6ddf5b3ff174a311c5f10e1393d_nc {
    static String[] s = new String[50];
    static int N, L;
    static long[] can = new long[1 << 20];

    static double work() {
        Arrays.fill(can, ~0L);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                int same = 0;
                for (int k = 0; k < L; k++) {
                    if (s[i].charAt(k) == s[j].charAt(k)) {
                        same |= 1 << k;
                    }
                }
                can[same] &= ~(1L << i);
            }
        }

        for (int mask = (1 << L) - 1; mask >= 0; mask--) {
            for (int p = 0; p < L; p++) {
                if ((mask & (1 << p)) != 0) {
                    can[mask ^ (1 << p)] &= can[mask];
                }
            }
        }

        double ret = 0;
        double[] cnt = new double[25];
        for (int mask = (1 << L) - 1; mask >= 0; mask--) {
            int l = Long.bitCount(mask);
            for (int p = 0; p < L; p++) {
                if ((mask & (1 << p)) != 0) {
                    long r = can[mask ^ (1 << p)] ^ can[mask];
                    cnt[l] += Long.bitCount(r);
                }
            }
        }

        for (int i = 1; i <= L; i++) {
            double t = cnt[i] * i;

            double c = 1;
            for (int j = 1; j <= i - 1; j++) {
                c *= (L - j + 1);
                c /= j;
            }

            ret += t / c / (L - i + 1);
        }
        return ret / N;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            N = scanner.nextInt();
            for (int i = 0; i < N; i++) {
                s[i] = scanner.next();
            }
            L = s[0].length();
            double ans = work();
            System.out.printf("%.12f\n", ans);
        }
        scanner.close();
    }
}
