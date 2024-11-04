import java.util.*;
import java.io.*;

public class 74b6837a3d04a6f57b5df4915333408c_nc {
    static final int MAXN = 1003;
    static final int MD = 998244353;
    static String s;
    static int it;
    static List<Integer>[] e = new ArrayList[MAXN];
    static int[] id = new int[MAXN];
    static int[] mas = new int[MAXN];
    static int[] deg = new int[MAXN];
    static int[][] seg = new int[MAXN][2];

    static {
        for (int i = 0; i < MAXN; i++) {
            e[i] = new ArrayList<>();
        }
    }

    static boolean can(int n) {
        if (n == 1) return true;
        int x = n / 2, y = (n + 1) / 2;
        if (!can(x) || !can(y)) return false;
        int a = 0, b = 0;
        while (it < s.length()) {
            if (s.charAt(it) == '0') a++;
            else b++;
            it++;
            if (a == x || b == y) break;
        }
        return a == x || b == y;
    }

    static void gen(int l, int r) {
        if (l == r) return;
        int m = (l + r - 1) / 2;
        gen(l, m);
        gen(m + 1, r);
        int a = l, b = m + 1, c = l;
        while (a <= m && b <= r) {
            if (s.charAt(it) == '0') {
                mas[c++] = id[a++];
            } else {
                mas[c++] = id[b++];
            }
            it++;
        }
        while (a <= m) mas[c++] = id[a++];
        while (b <= r) mas[c++] = id[b++];
        for (int i = l; i <= r; i++) {
            id[i] = mas[i];
            if (i > l) {
                e[id[i - 1]].add(id[i]);
            }
        }
    }

    static void go(int n) {
        it = 0;
        if (!can(n) || it != s.length()) return;

        it = 0;
        for (int i = 0; i < n; i++) id[i] = i;
        gen(0, n - 1);
        assert it == s.length();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) p[id[i]] = i;
        System.out.println(n);
        for (int i : p) System.out.print((i + 1) + " ");
        System.out.println();
        System.exit(0);
    }

    static void solve() {
        for (int i = 2; i < MAXN; i++) {
            int x = (i + 1) / 2, y = i - x;
            for (int t = 0; t < 2; t++) {
                seg[i][t] = seg[x][t] + seg[y][t];
            }
            seg[i][0] += x;
            seg[i][1] += y;
        }
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();
        int[] counter = new int[2];
        for (char c : s.toCharArray()) counter[c - '0']++;
        for (int n = MAXN - 1; n > 0; n--) {
            if (seg[n][0] >= counter[0] && seg[n][1] >= counter[1]) {
                go(n);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.setIn(new BufferedInputStream(new FileInputStream("a.in")));
        System.setOut(new PrintStream(new FileOutputStream("a.out")));
        solve();
    }
}
