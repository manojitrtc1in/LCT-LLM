import java.util.*;
import java.io.*;

class Main {
    static final int maxn = 1000 + 100;
    static final int maxw = (1 << 20) + 5;
    static final int inf = 1_000_000_100;
    static final int LG = 18;

    static String s;
    static int it;

    static boolean can(int n) {
        if (n == 1)
            return true;
        int x = n / 2, y = (n + 1) / 2;
        if (!can(x) || !can(y))
            return false;
        int a = 0, b = 0;
        while (it < s.length()) {
            if (s.charAt(it) == '0')
                a++;
            else
                b++;
            it++;
            if (a == x || b == y)
                break;
        }
        if (a != x && b != y)
            return false;
        return true;
    }

    static ArrayList<Integer>[] e = new ArrayList[maxn];
    static int[] id = new int[maxn];
    static int[] mas = new int[maxn];
    static int[] deg = new int[maxn];

    static void gen(int l, int r) {
        if (l == r)
            return;
        int m = (l + r - 1) / 2;
        gen(l, m);
        gen(m + 1, r);
        int a = l, b = m + 1, c = l;
        while (a <= m && b <= r) {
            if (s.charAt(it) == '0') {
                mas[c++] = id[a];
                a++;
            } else {
                mas[c++] = id[b];
                b++;
            }
            it++;
        }
        while (a <= m) {
            mas[c++] = id[a];
            a++;
        }
        while (b <= r) {
            mas[c++] = id[b];
            b++;
        }
        for (int i = l; i <= r; i++) {
            id[i] = mas[i];
            if (i > l) {
                e[id[i - 1]].add(id[i]);
            }
        }
    }

    static void go(int n) {
        it = 0;
        if (!can(n) || it != s.length())
            return;

        it = 0;
        for (int i = 0; i < n; i++)
            id[i] = i;
        gen(0, n - 1);
        assert it == s.length();
        int[] p = new int[n];
        for (int i = 0; i < n; i++)
            p[id[i]] = i;
        System.out.println(n);
        for (int i : p)
            System.out.print((i + 1) + " ");
        System.out.println();
        System.exit(0);
    }

    static int[][] seg = new int[maxn][2];

    static void solve() {
        for (int i = 2; i < maxn; i++) {
            int x = (i + 1) / 2, y = i - x;
            for (int t = 0; t < 2; t++) {
                seg[i][t] = seg[x][t] + seg[y][t];
            }
            seg[i][0] += x;
            seg[i][1] += y;
        }
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        int[] counter = new int[2];
        for (char c : s.toCharArray())
            counter[c - '0']++;
        for (int n = maxn - 1; n > 0; n--)
            if (seg[n][0] >= counter[0] && seg[n][1] >= counter[1]) {
                go(n);
            }
    }

    public static void main(String[] args) {
        solve();
    }
}
