import java.util.*;
import java.io.*;

public class e1a47493d2e2ed8b3061f6d87598cbd8xcodeeval_processed_4000.json {
    static int[] a;
    static long[] b;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        k++;
        a = new int[n];
        b = new long[n];
        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(a);
        for (int i = 0; i < n; i++) {
            b[n - 1 - i] = a[n - 1 - i] * 1L * (i / Math.max(k, 1));
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
