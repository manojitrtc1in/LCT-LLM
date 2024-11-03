import java.util.Arrays;

public class 40ca10a54463a16f6c0559d2d974fdc5_nc {
    static final int N = 18000;
    static final int M = 18000;
    static boolean[] is = new boolean[N];
    static int[] prm = new int[M];
    static int cntp;

    public static void main(String[] args) {
        cntp = getprm(N);
        int l, r;
        while (true) {
            // Read input for l and r
            // Break the loop if input is not available
            // Print the result using get(l, r) method
        }
    }

    static int getprm(int n) {
        int k = 0;
        int e = (int) (Math.sqrt(0.0 + n) + 1);
        Arrays.fill(is, true);
        prm[k++] = 2;
        is[0] = is[1] = false;
        for (int i = 4; i < n; i += 2) {
            is[i] = false;
        }
        for (int i = 3; i < e; i += 2) {
            if (is[i]) {
                prm[k++] = i;
                for (int s = i * 2, j = i * i; j < n; j += s) {
                    is[j] = false;
                }
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (is[i]) {
                prm[k++] = i;
            }
        }
        return k;
    }

    static int getr(int l, int r) {
        boolean[] isp = new boolean[r - l + 1];
        Arrays.fill(isp, true);
        for (int i = 0; prm[i] * prm[i] <= r; i++) {
            int j = l / prm[i] * prm[i];
            if (j < l) {
                j += prm[i];
            }
            if (j <= prm[i] * prm[i]) {
                j = prm[i] * prm[i];
            }
            for (; j <= r; j += prm[i]) {
                isp[j - l] = false;
            }
        }
        int ret = 0;
        for (int i = l; i <= r; i++) {
            if (isp[i - l] && i % 4 == 1) {
                ret++;
            }
        }
        return ret;
    }

    static int get(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 100000 == 0) {
            return f[n / 100000] + (n >= 2 ? 1 : 0);
        } else {
            return f[n / 100000] + (n > 100000 ? 1 : 0) + getr(n / 100000 * 100000 + 1, n);
        }
    }

