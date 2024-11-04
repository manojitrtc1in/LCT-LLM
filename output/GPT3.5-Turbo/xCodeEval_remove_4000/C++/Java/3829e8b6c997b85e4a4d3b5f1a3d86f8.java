import java.util.*;
import java.io.*;

class Main {
    static final int N = 32;
    static final int MOD = (int)1e9 + 7;

    static long n;
    static int k;

    static boolean read() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextLong()) {
            return false;
        }
        n = sc.nextLong();
        k = sc.nextInt();
        return true;
    }

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) {
            a -= MOD;
        }
        return a;
    }

    static int mul(int a, int b) {
        return (int)((long)a * b % MOD);
    }

    static class Mat {
        int[][] arr;

        Mat() {
            arr = new int[N][N];
        }

        Mat multiply(Mat other) {
            Mat res = new Mat();
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    for (int t = 0; t <= k; t++) {
                        res.arr[i][j] = add(res.arr[i][j], mul(arr[i][t], other.arr[t][j]));
                    }
                }
            }
            return res;
        }
    }

    static Mat[][] amat = new Mat[62][N];

    static void solve() {
        List<Integer> num = new ArrayList<>();
        while (n > 0) {
            num.add((int)(n % k));
            n /= k;
        }

        for (int d = 0; d < k; d++) {
            amat[0][d] = new Mat();
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    amat[0][d].arr[i][j] = 0;
                }
            }
            for (int i = 0; i <= k; i++) {
                amat[0][d].arr[i][i] = 1;
            }
            for (int i = 0; i <= k; i++) {
                amat[0][d].arr[i][d] = 1;
            }
        }

        for (int r = 1; r < num.size(); r++) {
            List<Mat> pr = new ArrayList<>();
            pr.add(new Mat());
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    pr.get(0).arr[i][j] = (i == j) ? 1 : 0;
                }
            }
            for (int i = 0; i < k; i++) {
                pr.add(pr.get(pr.size() - 1).multiply(amat[r - 1][i]));
            }
            for (int sh = 0; sh < k; sh++) {
                amat[r][sh] = pr.get(0);
                for (int i = 0; i <= k - sh; i++) {
                    amat[r][sh] = amat[r][sh].multiply(amat[r - 1][(i + sh) % k]);
                }
                amat[r][sh] = amat[r][sh].multiply(pr.get(sh));
            }
        }

        Mat dp = new Mat();
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                dp.arr[i][j] = 0;
            }
        }
        dp.arr[0][k] = 1;

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
            ans = add(ans, dp.arr[0][i]);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            read();
            solve();
        }
    }
}
