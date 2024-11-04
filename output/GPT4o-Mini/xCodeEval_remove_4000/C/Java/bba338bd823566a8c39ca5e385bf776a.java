import java.util.Arrays;
import java.util.Scanner;

public class bba338bd823566a8c39ca5e385bf776axcodeeval_processed_4000.json {
    static final int A = 100; // Define A based on your requirements
    static final int B = 100; // Define B based on your requirements
    static final int P = 100; // Define P based on your requirements
    static final int PMAX = 100; // Define PMAX based on your requirements
    static final long P3 = 100; // Define P3 based on your requirements
    static final int L1 = 100; // Define L1 based on your requirements

    static int[] a = new int[A + 1];
    static long[] y = new long[P];
    static long[] b = new long[B];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long n2, n3, bl, bh, ans = 0, k, kl, kh;
        int i, j, b1 = -1, b2, q2, c;

        b[0] = 0; // Initialize b[0] to 0
        // Initialize b array with values as in the original code
        // ...

        int[] p = new int[P];
        p[0] = 2;
        k = 1;

        for (i = 3; i <= PMAX; i += 2) {
            if (a[i] == 0) {
                p[k++] = i;
                if (i <= PMAX / i) {
                    for (j = i * i; j <= PMAX; j += i) {
                        a[j] = 1;
                    }
                }
            }
        }

        for (i = 0; i < P; i++) {
            n2 = n / p[i];
            if (n2 == 0 || n2 < p[i]) break;
            b2 = (int) (n2 / A);
            q2 = (int) (n2 % A);
            if (b1 != b2) {
                Arrays.fill(a, 0);
                b1 = b2;
                bl = 1L * b1 * A;
                bh = bl + q2 + 1;
                c = (b1 == 0 ? 1 : 0);
                y[0] = -1;
                for (j = 1; j < P; j++) {
                    y[j] = Math.max(bl / p[j] * p[j] + p[j], 1L * p[j] * p[j]) - bl;
                    if ((y[j] & 1) == 0) y[j] += p[j];
                }
                for (kl = bl; kl < bh; kl += L1) {
                    kh = Math.min(kl + L1, bh) - bl;
                    for (j = 1; j < P; j++) {
                        for (k = y[j]; k < kh; k += 2L * p[j]) {
                            a[(int) k] = 1;
                        }
                        y[j] = k;
                    }
                    if (kl == 0) {
                        k = 3;
                        a[2] = 1;
                    } else {
                        k = kl - bl + 1;
                    }
                    for (; k < kh; k += 2) {
                        a[(int) k] = a[(int) (k + 1)] = (a[(int) k] == 0 ? ++c : c);
                    }
                }
            }

            ans = ans + b[b1] + a[q2] - (i + 1);
        }

        i = 0;
        j = P;
        for (;;) {
            k = i + (j - i) / 2;
            if (k == i) break;
            if (p[k] > P3) {
                n3 = n + 1;
            } else {
                n3 = (long) p[k] * p[k] * p[k];
            }
            if (n3 > n) {
                j = (int) k;
            } else if (n3 < n) {
                i = (int) k;
            } else {
                break;
            }
        }
        if (p[k] * p[k] * p[k] <= n) ans += k + 1;

        System.out.println(ans);
    }
}
