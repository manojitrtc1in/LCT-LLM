import java.util.Arrays;
import java.util.Scanner;

public class 5dacb02799ce15fa48daa7b7f90c0a13_nc {
    static int n, m;
    static int[] a = new int[55];
    static int[] b = new int[55];
    static int[][][] dp = new int[55][55][55];
    static final int Mod = 998244353;
    static int[] nii = new int[5555];

    static int ksmii(int a, int b) {
        if (b == 0) {
            return 1;
        }
        int x = ksmii(a, b >> 1);
        x = (int) ((1L * x * x) % Mod);
        if ((b & 1) == 1) {
            x = (int) ((1L * x * a) % Mod);
        }
        return x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        for (int i = 1; i < 5555; i++) {
            nii[i] = ksmii(i, Mod - 2);
        }
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            b[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 55; j++) {
                for (int k = 0; k < 55; k++) {
                    Arrays.fill(dp[j][k], 0);
                }
            }
            int proba = 0, probb = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j] == 0) {
                    probb += b[j];
                } else {
                    proba += b[j];
                }
            }
            dp[0][0][0]++;
            for (int j = 0; j < m; j++) {
                for (int l = 0; l <= j; l++) {
                    int m = j - l;
                    for (int n = 0; n < 55; n++) {
                        if (a[i] != 0) {
                            dp[j + 1][l + 1][n + 1] += (int) ((1L * dp[j][l][n] * (n + b[i]) % Mod * nii[proba + probb + l - m]) % Mod);
                            if (dp[j + 1][l + 1][n + 1] >= Mod) {
                                dp[j + 1][l + 1][n + 1] -= Mod;
                            }
                        } else {
                            dp[j + 1][l][n + 1] += (int) ((1L * dp[j][l][n] * (b[i] - n) % Mod * nii[proba + probb + l - m]) % Mod);
                            if (dp[j + 1][l][n + 1] >= Mod) {
                                dp[j + 1][l][n + 1] -= Mod;
                            }
                        }

                        if (a[i] != 0) {
                            dp[j + 1][l + 1][n] += (int) ((1L * dp[j][l][n] * (proba + l - n - b[i]) % Mod * nii[proba + probb + l - m]) % Mod);
                            if (dp[j + 1][l + 1][n] >= Mod) {
                                dp[j + 1][l + 1][n] -= Mod;
                            }
                            dp[j + 1][l][n] += (int) ((1L * dp[j][l][n] * (probb - m) % Mod * nii[proba + probb + l - m]) % Mod);
                            if (dp[j + 1][l][n] >= Mod) {
                                dp[j + 1][l][n] -= Mod;
                            }
                        } else {
                            dp[j + 1][l + 1][n] += (int) ((1L * dp[j][l][n] * (proba + l) % Mod * nii[proba + probb + l - m]) % Mod);
                            if (dp[j + 1][l + 1][n] >= Mod) {
                                dp[j + 1][l + 1][n] -= Mod;
                            }
                            dp[j + 1][l][n] += (int) ((1L * dp[j][l][n] * (probb - m - b[i] + n) % Mod * nii[proba + probb + l - m]) % Mod);
                            if (dp[j + 1][l][n] >= Mod) {
                                dp[j + 1][l][n] -= Mod;
                            }
                        }
                    }
                }
            }
            int all = 0;
            for (int j = 0; j < 52; j++) {
                for (int k = 0; k < 52; k++) {
                    all += (int) ((1L * dp[m][j][k] * (a[i] != 0 ? b[i] + k : b[i] - k) % Mod) % Mod);
                    if (all >= Mod) {
                        all -= Mod;
                    }
                }
            }
            System.out.println(all);
        }
        scanner.close();
    }
}
