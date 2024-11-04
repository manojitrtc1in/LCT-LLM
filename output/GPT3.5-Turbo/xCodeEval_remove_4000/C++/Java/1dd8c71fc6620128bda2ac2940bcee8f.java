import java.io.*;
import java.util.*;

class Main {

    static final int MOD = 1_000_000_007;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.);
    static final long LLINF = 18_000_000_000_000_000L;
    static final int INF = 900_000_000;

    static final int MAXN = 600_006;
    static final int N = 500_005;

    static int[] cnt = new int[MAXN];
    static int[] l = new int[MAXN];
    static int[] r = new int[MAXN];

    static class Fenwick {

        int[] fw;

        Fenwick(int n) {
            fw = new int[n + 1];
        }

        void update(int i, int d) {
            while (i < fw.length) {
                fw[i] = Math.max(fw[i], d);
                i |= (i + 1);
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

    static void solution(BufferedReader br, PrintWriter pw) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            cnt[l]++;
            cnt[r + 1]--;
        }

        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }

        Fenwick fw_l = new Fenwick(100_001);
        for (int i = 1; i <= m; i++) {
            l[i] = fw_l.get(cnt[i]) + 1;
            fw_l.update(cnt[i], l[i]);
        }

        Fenwick fw_r = new Fenwick(100_001);
        for (int i = m; i >= 1; i--) {
            r[i] = fw_r.get(cnt[i]) + 1;
            fw_r.update(cnt[i], r[i]);
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = Math.max(ans, l[i] + r[i] - 1);
        }

        pw.println(ans);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int queries = 1;

        for (int test_case = 1; test_case <= queries; test_case++) {
            solution(br, pw, test_case);
        }

        pw.close();
        br.close();
    }
}
