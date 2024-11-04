import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static final long MOD = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        List<List<Integer>> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < t; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                if (row.size() < k) {
                    row.add(tmp);
                }
            }
            a.add(row);
        }

        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a.get(i).size(); j++) {
                w[i] += a.get(i).get(j);
            }
        }

        int ans = 0;
        solve(a, w, k, 0, n, new int[k + 1], new int[k + 1], ans);
        System.out.println(ans);
    }

    static void solve(List<List<Integer>> a, int[] w, int k, int l, int r, int[] dp, int[] dp2, int ans) {
        if (r - l == 1) {
            int sum = 0;
            for (int i = 0; i <= a.get(l).size(); i++) {
                ans = Math.max(ans, dp[k - i] + sum);
                if (i != a.get(l).size()) {
                    sum += a.get(l).get(i);
                }
            }
            return;
        }

        int m = (r + l) / 2;
        System.arraycopy(dp, 0, dp2, 0, k + 1);
        for (int i = m; i < r; i++) {
            for (int j = k - 1; j >= 0; j--) {
                if (a.get(i).size() + j <= k) {
                    dp2[j + a.get(i).size()] = Math.max(dp2[j + a.get(i).size()], dp2[j] + w[i]);
                }
            }
        }
        solve(a, w, k, l, m, dp, dp2, ans);
        for (int i = l; i < m; i++) {
            for (int j = k - 1; j >= 0; j--) {
                if (a.get(i).size() + j <= k) {
                    dp[j + a.get(i).size()] = Math.max(dp[j + a.get(i).size()], dp[j] + w[i]);
                }
            }
        }
        solve(a, w, k, m, r, dp, dp2, ans);
    }
}
