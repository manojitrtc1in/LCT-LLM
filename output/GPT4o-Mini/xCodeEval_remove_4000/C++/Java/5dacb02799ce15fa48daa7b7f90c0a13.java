import java.util.Scanner;

public class 5dacb02799ce15fa48daa7b7f90c0a13xcodeeval_processed_4000.json {
    static final int Mod = 998244353;
    static int[] a = new int[55];
    static int[] b = new int[55];
    static int[][][] dp = new int[55][55][55];
    static int[] nii = new int[5555];

    static int id0(int a, int b) {
        if (b == 0) {
            return 1;
        }
        int x = id0(a, b >> 1);
        x = (int) ((1L * x * x) % Mod);
        if ((b & 1) == 1) {
            x = (int) ((1L * x * a) % Mod);
        }
        return x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

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
            for (int j = 0; j < 55; j++) {
                for (int k = 0; k < 55; k++) {
                    for (int l = 0; l < 55; l++) {
                        dp[j][k][l] = 0;
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
                    int mIndex = j - l;
                    for (int nIndex = 0; nIndex < 55; nIndex++) {
                        if (a[i] != 0) {
                            dp[j + 1][l + 1][nIndex + 1] += (int) ((1L * dp[j][l][nIndex] * (nIndex + b[i])) % Mod * nii[proba + probb + l - mIndex] % Mod);
                            if (dp[j + 1][l + 1][nIndex + 1] >= Mod) {
                                dp[j + 1][l + 1][nIndex + 1] -= Mod;
                            }
                        } else {
                            dp[j + 1][l][nIndex + 1] += (int) ((1L * dp[j][l][nIndex] * (b[i] - nIndex)) % Mod * nii[proba + probb + l - mIndex] % Mod);
                            if (dp[j + 1][l][nIndex + 1] >= Mod) {
                                dp[j + 1][l][nIndex + 1] -= Mod;
                            }
                        }

                        if (a[i] != 0) {
                            dp[j + 1][l + 1][nIndex] += (int) ((1L * dp[j][l][nIndex] * (proba + l - nIndex - b[i])) % Mod * nii[proba + probb + l - mIndex] % Mod);
                            if (dp[j + 1][l + 1][nIndex] >= Mod) {
                                dp[j + 1][l + 1][nIndex] -= Mod;
                            }
                            dp[j + 1][l][nIndex] += (int) ((1L * dp[j][l][nIndex] * (probb - mIndex)) % Mod * nii[proba + probb + l - mIndex] % Mod);
                            if (dp[j + 1][l][nIndex] >= Mod) {
                                dp[j + 1][l][nIndex] -= Mod;
                            }
                        } else {
                            dp[j + 1][l + 1][nIndex] += (int) ((1L * dp[j][l][nIndex] * (proba + l)) % Mod * nii[proba + probb + l - mIndex] % Mod);
                            if (dp[j + 1][l + 1][nIndex] >= Mod) {
                                dp[j + 1][l + 1][nIndex] -= Mod;
                            }
                            dp[j + 1][l][nIndex] += (int) ((1L * dp[j][l][nIndex] * (probb - mIndex - b[i] + nIndex)) % Mod * nii[proba + probb + l - mIndex] % Mod);
                            if (dp[j + 1][l][nIndex] >= Mod) {
                                dp[j + 1][l][nIndex] -= Mod;
                            }
                        }
                    }
                }
            }
            int all = 0;
            for (int j = 0; j < 52; j++) {
                for (int k = 0; k < 52; k++) {
                    all += (int) ((1L * dp[m][j][k] * (a[i] != 0 ? b[i] + k : b[i] - k)) % Mod);
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
