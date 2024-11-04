import java.util.*;

public class 08c112ed25bc6fcd222f31458cbb6bf5xcodeeval_processed_4000.json {
    static final int INF = Integer.MAX_VALUE;
    static int[] a = new int[1010101];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; ++i) {
            a[i + 1] = scanner.nextInt();
        }
        a[0] = -INF;
        a[n + 1] = INF + INF;
        int ans = INF;
        for (int i = 1; i <= n; ++i) {
            int s = a[i];
            for (int j = 2; j <= 50 && i + j - 1 <= n; ++j) {
                s ^= a[i + j - 1];
                int z = 0;
                for (int r = 0; r < 50 && i + j + r <= n + 1; ++r) {
                    z ^= a[i + j + r];
                    if (a[i - 1] > s || s > z) {
                        ans = Math.min(ans, j + r);
                        break;
                    }
                }
            }
        }
        if (ans == INF) {
            ans = 0;
        }
        System.out.println(ans - 1);
    }
}
