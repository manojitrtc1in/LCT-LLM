import java.util.*;
import java.io.*;

public class 1dd8c71fc6620128bda2ac2940bcee8fxcodeeval_processed_4000.json {

    static final int MOD = 1_000_000_007; // 998'244'353
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.);
    static long LLINF = 18_E + 10;
    static int INF = 9_E + 10;

    static final int MAXN = 6_E + 6;
    static final int N = 5_E + 5;

    static int[] cnt = new int[MAXN];

    static class Fenwick {
        private int[] fw;

        Fenwick(int n) {
            fw = new int[n + 1];
        }

        void update(int i, int d) {
            while (i < fw.length) {
                fw[i] = Math.max(fw[i], d);
                i = (i | (i + 1));
            }
        }

        int get(int n) {
            int result = 0;
            while (n >= 0) {
                result = Math.max(result, fw[n]);
                n = (n & (n + 1)) - 1;
            }
            return result;
        }

        int get(int l, int r) {
            return get(r) - get(l - 1);
        }
    }

    static void solution(Scanner cin, PrintWriter cout) {
        int n = cin.nextInt();
        int m = cin.nextInt();
        for (int i = 1; i <= n; i++) {
            int l = cin.nextInt();
            int r = cin.nextInt();
            cnt[l]++;
            cnt[r + 1]--;
        }

        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }

        Fenwick fw_l = new Fenwick(100001);
        int[] l = new int[MAXN];
        for (int i = 1; i <= m; i++) {
            l[i] = fw_l.get(cnt[i]) + 1;
            fw_l.update(cnt[i], l[i]);
        }

        Fenwick fw_r = new Fenwick(100001);
        int[] r = new int[MAXN];
        for (int i = m; i >= 1; i--) {
            r[i] = fw_r.get(cnt[i]) + 1;
            fw_r.update(cnt[i], r[i]);
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = Math.max(ans, l[i] + r[i] - 1);
        }

        cout.println(ans);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out);

        int queries = 1;

        for (int test_case = 1; test_case <= queries; test_case++) {
            solution(cin, cout);
        }

        cout.flush();
        cin.close();
    }
}
