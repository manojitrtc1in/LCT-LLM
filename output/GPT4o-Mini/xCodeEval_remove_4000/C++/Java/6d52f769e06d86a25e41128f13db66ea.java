import java.util.*;
import java.io.*;

public class 6d52f769e06d86a25e41128f13db66eaxcodeeval_processed_4000.json {
    static long INF64 = (long) 1e18;
    static int INF = (int) 1e9;
    static int MOD = (int) 1e9 + 7;
    static double EPS = 1e-9;
    static double PI = Math.acos(-1.0);

    static int l1, r1, l2, r2, k;
    static List<Integer> nums = new ArrayList<>();

    static boolean read(Scanner scanner) {
        if (scanner.hasNextInt()) {
            l1 = scanner.nextInt();
            r1 = scanner.nextInt();
            l2 = scanner.nextInt();
            r2 = scanner.nextInt();
            k = scanner.nextInt();
            return true;
        }
        return false;
    }

    static int calc(int x) {
        String s = Integer.toString(x);
        int cur = 1 << (s.length() - 1);
        int ans = cur * 2 - 1;
        boolean fl = true;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) > '7')
                ans += 2 * cur;
            else if (s.charAt(i) > '4')
                ans += cur;
            if (s.charAt(i) != '7' && s.charAt(i) != '4') {
                fl = false;
                break;
            }
            cur >>= 1;
        }
        ans += fl ? 1 : 0;
        return ans;
    }

    static void brute(int x, int num) {
        nums.add(num);
        if (x == 9) return;
        brute(x + 1, num * 10 + 4);
        brute(x + 1, num * 10 + 7);
    }

    static void solve() {
        nums.clear();
        brute(0, 0);
        Collections.sort(nums);
        long tot = (long) (r1 - l1 + 1) * (r2 - l2 + 1);

        long ok = 0;
        for (int i = 1; i <= nums.size() - k; i++) {
            int l = nums.get(i);
            int r = nums.get(i + k - 1);
            int pl = nums.get(i - 1) + 1;
            int pr = (i + k == nums.size() ? INF + 7 : nums.get(i + k) - 1);
            if (l1 <= l && r <= r2) {
                int ll = Math.max(l1, pl);
                int rr = Math.min(r2, pr);
                ok += Math.max(0, Math.min(l, r1) - ll + 1) * Math.max(0, rr - Math.max(r, l2) + 1);
            }
            if (l2 <= l && r <= r1) {
                int ll = Math.max(l2, pl);
                int rr = Math.min(r1, pr);
                ok += Math.max(0, Math.min(l, r2) - ll + 1) * Math.max(0, rr - Math.max(r, l1) + 1);
            }
        }
        if (k == 1) {
            for (int it : nums)
                ok -= (l1 <= it && it <= r1 && l2 <= it && it <= r2) ? 1 : 0;
        }

        System.out.printf("%.15f\n", (double) ok / tot);
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
