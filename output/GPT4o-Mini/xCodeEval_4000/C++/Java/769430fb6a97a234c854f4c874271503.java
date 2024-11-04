import java.util.*;
import java.io.*;

public class 769430fb6a97a234c854f4c874271503_nc {
    static long[][][][][] dp = new long[20][2][2][10][10];
    static long[][][][][] memo = new long[20][2][2][10][10];
    static long n;
    static ArrayList<Long> num = new ArrayList<>();
    static long mod = (long) 1e9 + 7;

    static long solve(long ind, long ti, long st, long f, long pd) {
        if (ind == n) {
            return (st > 0 && f == pd) ? 1 : 0;
        }
        if (memo[(int) ind][(int) ti][(int) st][(int) f][(int) pd] != 0) {
            return dp[(int) ind][(int) ti][(int) st][(int) f][(int) pd];
        }
        long res = 0;
        memo[(int) ind][(int) ti][(int) st][(int) f][(int) pd] = 1;
        if (ti == 1) {
            for (long i = 0; i < num.get((int) ind); i++) {
                if (i == 0) res += solve(ind + 1, 0, st, f, i);
                if (i > 0) {
                    if (st == 0) res += solve(ind + 1, 0, 1, i, i);
                    else res += solve(ind + 1, 0, st, f, i);
                }
            }
            if (num.get((int) ind) == 0) res += solve(ind + 1, 1, st, f, 0);
            else {
                if (st == 0) res += solve(ind + 1, 1, 1, num.get((int) ind), num.get((int) ind));
                else res += solve(ind + 1, 1, st, f, num.get((int) ind));
            }
        } else {
            for (long i = 0; i < 10; i++) {
                if (i == 0) res += solve(ind + 1, 0, st, f, i);
                if (i > 0) {
                    if (st == 0) res += solve(ind + 1, 0, 1, i, i);
                    else res += solve(ind + 1, 0, st, f, i);
                }
            }
        }
        return dp[(int) ind][(int) ti][(int) st][(int) f][(int) pd] = res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long l = Long.parseLong(st.nextToken());
        long r = Long.parseLong(st.nextToken());

        while (r > 0) {
            num.add(r % 10);
            r /= 10;
        }
        Collections.reverse(num);
        n = num.size();
        long ans = 0;
        Arrays.fill(dp, new long[2][2][10][10]);
        Arrays.fill(memo, new long[2][2][10][10]);
        ans = solve(0, 1, 0, 0, 0);

        num.clear();
        Arrays.fill(dp, new long[2][2][10][10]);
        Arrays.fill(memo, new long[2][2][10][10]);
        long k = l;
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
        ans += (num.get(0).equals(num.get(num.size() - 1))) ? 1 : 0;
        System.out.println(ans);
    }
}
