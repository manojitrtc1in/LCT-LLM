import java.util.*;

public class e1a47493d2e2ed8b3061f6d87598cbd8_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt() + 1;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            b[n - 1 - i] = a[n - 1 - i] * (i / Math.max(k, 1));
        }
        for (int i = n - 1; i >= 0; i--) {
            b[i] += b[i + 1];
        }
        long cum = 0;
        long sum = 0;
        long ans = b[0];
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                long res = sum + b[i];
                int longest = (n - i - 1) / k + 1;
                ans = Math.max(ans, res + cum * longest);
                sum += cum;
                cum += a[i];
            }
        }
        System.out.println(ans);
    }
}
