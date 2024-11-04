import java.util.Scanner;

public class 81cde294d18625d210496b13e682ac47xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        if (n >= 100) {
            System.out.println(1);
            System.exit(0);
        }
        int ans = n * n;
        int[] cur = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cur[i] = cur[i - 1] ^ l[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if ((cur[j] ^ cur[i - 1]) > (cur[k] ^ cur[j])) {
                        ans = Math.min(ans, k - i - 1);
                    }
                }
            }
        }
        if (ans == n * n) {
            ans = -1;
        }
        System.out.println(ans);
    }
}
