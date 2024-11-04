import java.util.*;
import java.io.*;

public class 3829e8b6c997b85e4a4d3b5f1a3d86f8_nc {
    static final int N = 32;
    static final int MOD = (int)1e9 + 7;

    static long n;
    static int k;

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] input = br.readLine().split(" ");
            n = Long.parseLong(input[0]);
            k = Integer.parseInt(input[1]);
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    static int add(int a, int b) {
        a += b;
        if (a >= MOD)
            a -= MOD;
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
        ArrayList<Integer> num = new ArrayList<>();
        while (n > 0) {
            num.add((int)(n % k));
            n /= k;
        }

        Mat[][] pr = new Mat[k + 1][k + 1];
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                pr[i][j] = new Mat();
                pr[i][j].arr[i][j] = 1;
            }
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
            pr[0][0] = new Mat();
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    pr[0][0].arr[i][j] = (i == j) ? 1 : 0;
                }
            }
            for (int i = 1; i <= k; i++) {
                pr[i][0] = pr[i - 1][0].multiply(amat[r - 1][(i + k - 1) % k]);
            }
            for (int i = 0; i < k; i++) {
                for (int j = 1; j <= k; j++) {
                    pr[i][j] = pr[i][j - 1].multiply(amat[r - 1][(i + j) % k]);
                }
            }
            for (int sh = 0; sh < k; sh++) {
                amat[r][sh] = pr[0][sh];
                for (int i = 0; i <= k - sh; i++) {
                    amat[r][sh] = amat[r][sh].multiply(amat[r - 1][(i + sh) % k]);
                }
                amat[r][sh] = amat[r][sh].multiply(pr[sh][sh]);
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
        for (int i = num.size() - 1; i >= 0; --i) {
            while (num.get(i) > 0) {
                dp = dp.multiply(amat[i][rem]);
                rem = (rem + 1) % k;
                --num.set(i, num.get(i) - 1);
            }
        }

        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = add(ans, dp.arr[0][i]);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] input = br.readLine().split(" ");
            int tc = Integer.parseInt(input[0]);
            while (tc-- > 0) {
                read();
                solve();
            }
        } catch (IOException e) {
            return;
        }
    }
}
