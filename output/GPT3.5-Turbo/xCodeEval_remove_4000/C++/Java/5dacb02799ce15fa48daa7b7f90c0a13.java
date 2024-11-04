import java.util.Scanner;

public class 5dacb02799ce15fa48daa7b7f90c0a13xcodeeval_processed_4000.json {
    static int n, m;
    static int[] a = new int[55];
    static int[] b = new int[55];
    static int[][][] dp = new int[55][55][55];
    static final int Mod = 998244353;
    static int[] nii = new int[5555];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        for (int i = 1; i < 5555; i++) {
            nii[i] = id0(i, Mod - 2);
        }
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            b[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            for (int[][] row : dp) {
                for (int[] col : row) {
                    for (int k = 0; k < col.length; k++) {
                        col[k] = 0;
                    }
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
                    int mm = j - l;
                    for (int nn = 0; nn < 55; nn++) {
                        if (a[i] != 0) {
                            dp[j + 1][l + 1][nn + 1] += (long) dp[j][l][nn] * (nn + b[i]) % Mod * nii[proba + probb + l - mm] % Mod;
                            if (dp[j + 1][l + 1][nn + 1] >= Mod) {
                                dp[j + 1][l + 1][nn + 1] -= Mod;
                            }
                        } else {
                            dp[j + 1][l][nn + 1] += (long) dp[j][l][nn] * (b[i] - nn) % Mod * nii[proba + probb + l - mm] % Mod;
                            if (dp[j + 1][l][nn + 1] >= Mod) {
                                dp[j + 1][l][nn + 1] -= Mod;
                            }
                        }
                        if (a[i] != 0) {
                            dp[j + 1][l + 1][nn] += (long) dp[j][l][nn] * (proba + l - nn - b[i]) % Mod * nii[proba + probb + l - mm] % Mod;
                            if (dp[j + 1][l + 1][nn] >= Mod) {
                                dp[j + 1][l + 1][nn] -= Mod;
                            }
                            dp[j + 1][l][nn] += (long) dp[j][l][nn] * (probb - mm) % Mod * nii[proba + probb + l - mm] % Mod;
                            if (dp[j + 1][l][nn] >= Mod) {
                                dp[j + 1][l][nn] -= Mod;
                            }
                        } else {
                            dp[j + 1][l + 1][nn] += (long) dp[j][l][nn] * (proba + l) % Mod * nii[proba + probb + l - mm] % Mod;
                            if (dp[j + 1][l + 1][nn] >= Mod) {
                                dp[j + 1][l + 1][nn] -= Mod;
                            }
                            dp[j + 1][l][nn] += (long) dp[j][l][nn] * (probb - mm - b[i] + nn) % Mod * nii[proba + probb + l - mm] % Mod;
                            if (dp[j + 1][l][nn] >= Mod) {
                                dp[j + 1][l][nn] -= Mod;
                            }
                        }
                    }
                }
            }
            int all = 0;
            for (int j = 0; j < 52; j++) {
                for (int k = 0; k < 52; k++) {
                    all += (long) dp[m][j][k] * (a[i] != 0 ? b[i] + k : b[i] - k) % Mod;
                    if (all >= Mod) {
                        all -= Mod;
                    }
                }
            }
            System.out.println(all);
        }
    }

    static int id0(int a, int b) {
        if (b == 0) {
            return 1;
        }
        int x = id0(a, b >> 1);
        x = (int) ((long) x * x % Mod);
        if ((b & 1) != 0) {
            x = (int) ((long) x * a % Mod);
        }
        return x;
    }
}