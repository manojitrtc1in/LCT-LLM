import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 81cde294d18625d210496b13e682ac47_nc {
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = fs.nextInt();
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

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
