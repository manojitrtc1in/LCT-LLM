import java.util.*;

public class dedee8cabd3d1fb280a9b14266947606_nc {
    static List<Integer> A = new ArrayList<>();
    static long pl, pr, vl, vr, k;
    static long cnt;

    public static void main(String[] args) {
        dfs(0, 0);
        Collections.sort(A);
        A.add(Integer.MAX_VALUE);

        Scanner sc = new Scanner(System.in);
        pl = sc.nextLong();
        pr = sc.nextLong();
        vl = sc.nextLong();
        vr = sc.nextLong();
        k = sc.nextLong();

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

    static long I(int l, int r, long l_, long r_) {
        l = Math.max(l, (int) l_);
        r = Math.min(r, (int) r_);
        return Math.max(0, r - l + 1);
    }
}
