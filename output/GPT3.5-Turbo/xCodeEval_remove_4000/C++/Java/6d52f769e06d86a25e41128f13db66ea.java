import java.util.*;
import java.io.*;

class Main {
    static int l1, r1, l2, r2;
    static int k;
    static ArrayList<Integer> nums;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        while (tc-- > 0) {
            String[] input = br.readLine().split(" ");
            l1 = Integer.parseInt(input[0]);
            r1 = Integer.parseInt(input[1]);
            l2 = Integer.parseInt(input[2]);
            r2 = Integer.parseInt(input[3]);
            k = Integer.parseInt(input[4]);

            solve();
        }
    }

    static void solve() {
        nums = new ArrayList<>();
        brute(0, 0);
        Collections.sort(nums);
        long tot = (r1 - l1 + 1) * (long) (r2 - l2 + 1);

        long ok = 0;
        for (int i = 1; i < nums.size() - k + 1; i++) {
            int l = nums.get(i);
            int r = nums.get(i + k - 1);
            int pl = nums.get(i - 1) + 1;
            int pr = (i + k == nums.size()) ? Integer.MAX_VALUE + 7 : nums.get(i + k) - 1;
            if (l1 <= l && r <= r2) {
                int ll = Math.max(l1, pl);
                int rr = Math.min(r2, pr);
                ok += Math.max(0, Math.min(l, r1) - ll + 1) * (long) Math.max(0, rr - Math.max(r, l2) + 1);
            }
            if (l2 <= l && r <= r1) {
                int ll = Math.max(l2, pl);
                int rr = Math.min(r1, pr);
                ok += Math.max(0, Math.min(l, r2) - ll + 1) * (long) Math.max(0, rr - Math.max(r, l1) + 1);
            }
        }
        if (k == 1) {
            for (int it : nums) {
                if (l1 <= it && it <= r1 && l2 <= it && it <= r2) {
                    ok--;
                }
            }
        }

        System.out.printf("%.15f\n", ok / (double) tot);
    }

    static void brute(int x, int num) {
        nums.add(num);
        if (x == 9) {
            return;
        }
        brute(x + 1, num * 10 + 4);
        brute(x + 1, num * 10 + 7);
    }
}
