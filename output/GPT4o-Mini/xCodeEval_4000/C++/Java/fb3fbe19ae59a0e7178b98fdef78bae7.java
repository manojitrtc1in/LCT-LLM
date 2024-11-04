import java.util.*;

public class fb3fbe19ae59a0e7178b98fdef78bae7_nc {
    static final int Maxn = 100005;
    static int[] l = new int[Maxn];
    static int[] r = new int[Maxn];
    static int[] sum = new int[Maxn];
    static int[] dp1 = new int[Maxn];
    static int[] dp2 = new int[Maxn];
    static int[] bit = new int[Maxn];

    static void modify(int pos, int val) {
        while (pos < Maxn) {
            bit[pos] = Math.max(bit[pos], val);
            pos += pos & -pos;
        }
    }

    static int query(int pos) {
        int ans = 0;
        while (pos > 0) {
            ans = Math.max(ans, bit[pos]);
            pos -= pos & -pos;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
            r[i] = scanner.nextInt();
            sum[l[i]]++;
            sum[r[i] + 1]--;
        }
        
        for (int i = 1; i <= m; i++) {
            sum[i] += sum[i - 1];
        }
        
        dp1[0] = 0;
        for (int i = 1; i <= m; i++) {
            dp1[i] = query(sum[i] + 1) + 1;
            modify(sum[i] + 1, dp1[i]);
        }
        
        Arrays.fill(bit, 0);
        for (int i = m; i >= 1; i--) {
            dp2[i] = query(sum[i] + 1) + 1;
            modify(sum[i] + 1, dp2[i]);
        }
        
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = Math.max(ans, dp1[i] + dp2[i] - 1);
        }
        
        System.out.println(ans);
    }
}
