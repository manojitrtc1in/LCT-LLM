import java.util.*;

public class dedee8cabd3d1fb280a9b14266947606_nc {
    static final int MOD = 1000000007;
    static final int INF = Integer.MAX_VALUE;
    static List<Integer> A = new ArrayList<>();
    static long pl, pr, vl, vr, k;
    static long cnt;

    static void dfs(int k, int n) {
        A.add(n);
        if (k == 9) return;
        else {
            dfs(k + 1, n * 10 + 4);
            dfs(k + 1, n * 10 + 7);
        }
    }

    static long I(long l, long r, long l_, long r_) {
        l = Math.max(l, l_);
        r = Math.min(r, r_);
        return Math.max(0, r - l + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        dfs();
        Collections.sort(A);
        A.add(INF);
        
        pl = scanner.nextLong();
        pr = scanner.nextLong();
        vl = scanner.nextLong();
        vr = scanner.nextLong();
        k = scanner.nextLong();

        for (int i = 0; i < A.size() - k; i++) {
            int l1 = A.get(i - 1) + 1, r1 = A.get(i);
            int l2 = A.get(i + (int) k - 1), r2 = A.get(i + (int) k) - 1;
            long d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr);
            long d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
            cnt += d1 + d2;
            if (d2 > 0 && k == 1) --cnt;
        }

        System.out.printf("%.12f\n", (double) cnt / ((pr - pl + 1) * (vr - vl + 1)));
    }
}
