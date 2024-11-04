import java.util.*;

public class d3200686aa6c869ac45c66f3583781d1xcodeeval_processed_4000.json {
    static List<Integer> A = new ArrayList<>();
    static long pl, pr, vl, vr, k;
    static long cnt;

    public static void main(String[] args) {
        dfs(0, 0);
        Collections.sort(A);
        A.add(Integer.MAX_VALUE);
        Scanner scanner = new Scanner(System.in);
        pl = scanner.nextLong();
        pr = scanner.nextLong();
        vl = scanner.nextLong();
        vr = scanner.nextLong();
        k = scanner.nextLong();

        for (int i = 0; i < A.size() - k; i++) {
            int l1 = A.get(i - 1) + 1;
            int r1 = A.get(i);
            int l2 = A.get(i + (int) k - 1);
            int r2 = A.get(i + (int) k) - 1;
            long d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr);
            long d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
            cnt += d1 + d2;
            if (d1 != 0 && d2 != 0 && k == 1) {
                cnt--;
            }
        }

        System.out.println((double) cnt / ((pr - pl + 1) * (vr - vl + 1)));
    }

    static void dfs(int k, int n) {
        A.add(n);
        if (k == 9) {
            return;
        } else {
            dfs(k + 1, n * 10 + 4);
            dfs(k + 1, n * 10 + 7);
        }
    }

    static long I(int l, int r, int l_, int r_) {
        l = Math.max(l, l_);
        r = Math.min(r, r_);
        return Math.max(0, r - l + 1);
    }
}
