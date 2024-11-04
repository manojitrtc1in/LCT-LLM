import java.io.*;
import java.util.*;

public class 4cb13d3ee50a53d8e6429ac32557cc19xcodeeval_processed_4000.json {
    static final int MOD = 1000000007;
    static final int MOD1 = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int ans = 3;
        if (a % m == 1) {
            ans--;
        }
        if (b % m == 0 || b == n) {
            ans--;
        }
        if (m == 1) {
            System.out.println(1);
            return;
        } else if ((a - 1) / m == (b - 1) / m) {
            System.out.println(1);
            return;
        } else if ((a % m - b % m) % m == 1) {
            System.out.println(Math.min(2, ans, (b - 1) / m - (a - 1) / m + 1));
            return;
        }
        System.out.println(Math.min(ans, (b - 1) / m - (a - 1) / m + 1));
    }
}
