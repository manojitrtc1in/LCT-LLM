import java.util.*;

public class 08c112ed25bc6fcd222f31458cbb6bf5_nc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n + 2];
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        a[0] = -INF;
        a[n + 1] = INF + INF;
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            int s = a[i];
            for (int j = 2; j <= 50 && i + j - 1 <= n; j++) {
                s ^= a[i + j - 1];
                int z = 0;
                for (int r = 0; r < 50 && i + j + r <= n + 1; r++) {
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
