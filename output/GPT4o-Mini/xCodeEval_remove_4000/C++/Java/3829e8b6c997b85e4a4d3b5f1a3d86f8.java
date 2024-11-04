import java.util.*;
import java.io.*;

public class 3829e8b6c997b85e4a4d3b5f1a3d86f8xcodeeval_processed_4000.json {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = (int) 1e9 + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);
    static final int N = 32;

    static long n;
    static int k;

    static boolean read(Scanner scanner) {
        if (scanner.hasNextLong()) {
            n = scanner.nextLong();
            k = scanner.nextInt();
            return true;
        }
        return false;
    }

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

    static void solve() {
        List<Integer> num = new ArrayList<>();
        while (n > 0) {
            num.add((int) (n % k));
            n /= k;
        }

        for (int d = 0; d < k; d++) {
            amat[0][d] = new Mat();
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    amat[0][d].data[i][j] = 0;
                }
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
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                dp.data[i][j] = 0;
            }
        }
        dp.data[0][k] = 1;

        int rem = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
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

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("input.txt"));

        int tc = scanner.nextInt();
        while (tc-- > 0) {
            if (read(scanner)) {
                solve();
            }
        }
        scanner.close();
    }
}
