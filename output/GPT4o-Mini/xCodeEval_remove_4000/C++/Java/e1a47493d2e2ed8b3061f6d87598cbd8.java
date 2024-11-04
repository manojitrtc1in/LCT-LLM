import java.io.*;
import java.util.*;

public class e1a47493d2e2ed8b3061f6d87598cbd8xcodeeval_processed_4000.json {
    static long[] b = new long[1010101];
    static int[] a = new int[1010101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("Data/input.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken()) + 1;

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(a, 0, n);
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }

        for (int i = 0; i < n; i++) {
            b[n - 1 - i] = a[n - 1 - i] * (long) (i / Math.max(k, 1));
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
