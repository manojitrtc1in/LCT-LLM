import java.util.*;
import java.io.*;

class Main {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = INF + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);

    static final int N = 1000 * 1000 + 13;
    static final int AL = 26;

    static int n;
    static String s;
    static int m;
    static int[] t;

    static boolean read() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNext()) return false;
        s = sc.next();
        n = s.length();
        m = sc.nextInt();
        t = new int[m];
        for (int i = 0; i < m; i++) {
            String tmp = sc.next();
            int x = 0;
            for (int j = 0; j < tmp.length(); j++) {
                x |= (1 << (tmp.charAt(j) - 'a'));
            }
            t[i] = x;
        }
        return true;
    }

    static int[][] nxt;
    static int[] cnt, mx;
    static HashMap<Integer, Integer> masks;

    static void solve() {
        nxt = new int[n + 1][AL];
        for (int i = 0; i < AL; i++) nxt[n][i] = n;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < AL; j++) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s.charAt(i) - 'a'] = i;
        }

        masks = new HashMap<>();
        cnt = new int[N];
        mx = new int[N];

        for (int i = 0; i < m; i++) {
            if (!masks.containsKey(t[i])) {
                int k = masks.size();
                masks.put(t[i], k);
            }
        }

        Arrays.fill(cnt, 0);
        Arrays.fill(mx, -1);

        for (int i = 0; i < n; i++) {
            int lst = i;
            int cur = (1 << (s.charAt(lst) - 'a'));
            while (true) {
                int mn = n;
                for (int j = 0; j < AL; j++) {
                    if (((cur >> j) & 1) == 0) {
                        mn = Math.min(mn, nxt[lst][j]);
                    }
                }
                if (masks.containsKey(cur)) {
                    int x = masks.get(cur);
                    if (mx[x] != mn - 1) {
                        mx[x] = mn - 1;
                        cnt[x]++;
                    }
                }
                if (mn == n) break;
                lst = mn;
                cur |= (1 << (s.charAt(lst) - 'a'));
            }
        }

        for (int i = 0; i < m; i++) {
            System.out.println(cnt[masks.get(t[i])]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (read()) {
            solve();
        }
    }
}
