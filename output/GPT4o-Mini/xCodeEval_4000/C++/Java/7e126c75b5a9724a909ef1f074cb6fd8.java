import java.util.*;

public class 7e126c75b5a9724a909ef1f074cb6fd8_nc {
    static final int N1 = (int) 1e5;
    static final int B = (int) 1e5;
    static final int N = (int) 3e8;

    static int[] lp = new int[N1 + 1];
    static List<Integer> prime = new ArrayList<>();
    static int[] csum = new int[10000]; // Adjust size as needed

    static void seive() {
        for (int i = 2; i <= N1; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                prime.add(i);
            }
            for (int j : prime) {
                if (j > lp[i] || i * j > N1) break;
                lp[i * j] = j;
            }
        }
    }

    static int l, r;

    static int calsum(int l, int r) {
        if (l > r) return 0;
        if (l == 0) return csum[r];
        return csum[r] - csum[l - 1];
    }

    static int inrange(int l, int r) {
        boolean[] isp = new boolean[r - l + 1];
        Arrays.fill(isp, true);
        for (int i : prime) {
            if (i * i > r) break;
            int st = (l / i) * i;
            if (st < l) st += i;
            if (st == i) st += i;
            for (int cur = st; cur <= r; cur += i) {
                isp[cur - l] = false;
            }
        }
        int ans = 0;
        for (int i = 0, j = l; j <= r; ++i, ++j) {
            if (isp[i] && j % 4 == 1) ++ans;
        }
        if (2 >= l && 2 <= r) ++ans;
        return ans;
    }

