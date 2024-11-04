import java.util.*;

class Main {
    static long[][][][][] dp;
    static int[][][][][] memo;
    static int n;
    static List<Integer> num;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();

        num = new ArrayList<>();
        while (r > 0) {
            num.add(r % 10);
            r /= 10;
        }
        Collections.reverse(num);
        n = num.size();
        long ans = 0;
        dp = new long[20][2][2][10][10];
        memo = new int[20][2][2][10][10];
        ans = solve(0, 1, 0, 0, 0);

        num.clear();
        dp = new long[20][2][2][10][10];
        memo = new int[20][2][2][10][10];
        int k = l;
        while (l > 0) {
            num.add(l % 10);
            l /= 10;
        }
        Collections.reverse(num);
        n = num.size();
        ans -= solve(0, 1, 0, 0, 0);

        num.clear();
        while (k > 0) {
            num.add(k % 10);
            k /= 10;
        }
        ans += (num.get(0) == num.get(num.size() - 1)) ? 1 : 0;
        System.out.println(ans);
    }

    static long solve(int ind, int ti, int st, int f, int pd) {
        if (ind == n) {
            return ((st > 0) && (f == pd)) ? 1 : 0;
        }
        if (memo[ind][ti][st][f][pd] == 1) return dp[ind][ti][st][f][pd];
        long res = 0;
        memo[ind][ti][st][f][pd] = 1;
        if (ti == 1) {
            for (int i = 0; i < num.get(ind); i++) {
                if (i == 0) res += solve(ind + 1, 0, st, f, i);
                if (i > 0) {
                    if (st == 0) res += solve(ind + 1, 0, 1, i, i);
                    else res += solve(ind + 1, 0, st, f, i);
                }
            }
            if (num.get(ind) == 0) res += solve(ind + 1, 1, st, f, 0);
            else {
                if (st == 0) res += solve(ind + 1, 1, 1, num.get(ind), num.get(ind));
                else res += solve(ind + 1, 1, st, f, num.get(ind));
            }
        } else {
            for (int i = 0; i < 10; i++) {
                if (i == 0) res += solve(ind + 1, 0, st, f, i);
                if (i > 0) {
                    if (st == 0) res += solve(ind + 1, 0, 1, i, i);
                    else res += solve(ind + 1, 0, st, f, i);
                }
            }
        }
        return dp[ind][ti][st][f][pd] = res;
    }
}
