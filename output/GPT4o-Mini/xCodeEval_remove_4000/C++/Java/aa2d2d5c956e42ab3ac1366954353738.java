import java.util.*;
import java.io.*;

public class aa2d2d5c956e42ab3ac1366954353738xcodeeval_processed_4000.json {
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
    static int[] t = new int[N];

    static boolean read(Scanner scanner) {
        s = scanner.next();
        n = s.length();
        m = scanner.nextInt();
        for (int i = 0; i < m; i++) {
            String tmp = scanner.next();
            int x = 0;
            for (char c : tmp.toCharArray()) {
                x |= (1 << (c - 'a'));
            }
            t[i] = x;
        }
        return true;
    }

    static int[][] nxt = new int[N][AL];
    static int[] cnt = new int[N];
    static int[] mx = new int[N];
    static HashMap<Integer, Integer> masks = new HashMap<>();

    static void solve() {
        for (int i = 0; i < AL; i++) nxt[n][i] = n;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < AL; j++) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s.charAt(i) - 'a'] = i;
        }

        masks.clear();
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
                    if (!((cur >> j) & 1)) {
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

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("input.txt"));

        while (read(scanner)) {
            solve();
        }
        scanner.close();
    }
}