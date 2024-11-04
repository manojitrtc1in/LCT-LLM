import java.util.*;
import java.io.*;

public class 3829e8b6c997b85e4a4d3b5f1a3d86f8_nc {
    static final int N = 32;
    static final int MOD = (int) (1e9 + 7);
    static long n;
    static int k;

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    static long mul(int a, long b) {
        return a * b % MOD;
    }

    static class Mat {
        int[][] data;

        Mat() {
            data = new int[N][N];
        }

        Mat multiply(Mat b) {
            Mat c = new Mat();
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    c.data[i][j] = 0;
                    for (int t = 0; t <= k; t++) {
                        c.data[i][j] = add(c.data[i][j], mul(data[i][t], b.data[t][j]));
                    }
                }
            }
            return c;
        }
    }

    static Mat[][][] amat = new Mat[62][N];

    static boolean read() {
        try {
            Scanner scanner = new Scanner(System.in);
            n = scanner.nextLong();
            k = scanner.nextInt();
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    static void solve() {
        List<Integer> num = new ArrayList<>();
        while (n > 0) {
            num.add((int) (n % k));
            n /= k;
        }

        for (int d = 0; d < k; d++) {
            amat[0][d] = new Mat();
            for (int i = 0; i <= k; i++) {
                amat[0][d].data[i][i] = 1;
                amat[0][d].data[i][d] = 1;
            }
        }

        for (int r = 1; r < num.size(); r++) {
            List<Mat> pr = new ArrayList<>();
            pr.add(new Mat());
            for (int i = 0; i <= k; i++) {
                pr.get(0).data[i][i] = 1;
            }
            for (int i = 0; i < k; i++) {
                pr.add(pr.get(pr.size() - 1).multiply(amat[r - 1][i]));
            }
            for (int sh = 0; sh < k; sh++) {
                amat[r][sh] = pr.get(0);
                for (int i = 0; i < k - sh; i++) {
                    amat[r][sh] = amat[r][sh].multiply(amat[r - 1][(i + sh) % k]);
                }
                amat[r][sh] = amat[r][sh].multiply(pr.get(sh));
            }
        }

        Mat dp = new Mat();
        dp.data[0][k] = 1;

        int rem = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            while (num.get(i) > 0) {
                dp = dp.multiply(amat[i][rem]);
                rem = (rem + 1) % k;
                num.set(i, num.get(i) - 1);
            }
        }

        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = add(ans, dp.data[0][i]);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        while (read()) {
            solve();
        }
    }
}
