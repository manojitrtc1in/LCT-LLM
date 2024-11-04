import java.util.*;
import java.io.*;

public class c5127f5691b4754aa4e976d93cb6a983_nc {
    static final int md = 998244353;
    static final long llinf = 1e18 + 100;
    static final int maxn = (int) 1e5 + 100;
    static final int inf = (int) 1e9 + 100;

    static String s;
    static List<Integer>[] o = new ArrayList[2];
    static List<Integer> ind = new ArrayList<>();
    static int[][] nxt;
    static int it;
    static int[] id = new int[maxn];
    static int[] mas = new int[maxn];
    static int[][] seg = new int[maxn][2];
    static Pair[] len = new Pair[maxn];

    static {
        o[0] = new ArrayList<>();
        o[1] = new ArrayList<>();
        nxt = new int[maxn][2];
        for (int i = 0; i < maxn; i++) {
            len[i] = new Pair(0, 0);
        }
    }

    static class Pair {
        int fr, sc;

        Pair(int fr, int sc) {
            this.fr = fr;
            this.sc = sc;
        }
    }

    static boolean can(int n) {
        if (n == 1) return true;

        int IT = it;
        int x = n / 2, y = (n + 1) / 2;
        if (!can(x) || !can(y)) return false;

        int p0 = nxt[it][0], p1 = nxt[it][1];
        if (p0 == s.length() || ind.get(p0) + x - 1 >= o[0].size())
            p0 = s.length();
        else
            p0 = o[0].get(ind.get(p0) + x - 1);
        if (p1 == s.length() || ind.get(p1) + y - 1 >= o[1].size())
            p1 = s.length();
        else
            p1 = o[1].get(ind.get(p1) + y - 1);
        p0 = Math.min(p0, p1);
        if (p0 == s.length()) return false;

        it = p0 + 1;
        return true;
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
        while (a <= m) {
            mas[c++] = id[a++];
        }
        while (b <= r) {
            mas[c++] = id[b++];
        }
        for (int i = l; i <= r; i++) {
            id[i] = mas[i];
        }
    }

    static boolean go(int n, boolean cert) {
        it = 0;
        if (!cert) return can(n);
        it = 0;
        can(n);
        assert it == s.length();

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
        return true;
    }

    static void solve() {
        for (int i = 2; i < maxn; i++) {
            int x = i / 2, y = i - x;
            len[i].fr = len[x].fr + len[y].fr + x;
            len[i].sc = len[x].sc + len[y].sc + x + y - 1;
            seg[i][0] = seg[x][0] + seg[y][0] + x;
            seg[i][1] = seg[x][1] + seg[y][1] + y;
        }
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();
        int[] counter = new int[2];
        nxt = new int[s.length() + 1][2];
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - '0';
            counter[c]++;
            ind.add(o[c].size());
            o[c].add(i);
        }
        nxt[s.length()][0] = nxt[s.length()][1] = s.length();
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int t = 0; t < 2; t++)
                nxt[i][t] = nxt[i + 1][t];
            nxt[i][s.charAt(i) - '0'] = i;
        }
        int l = 0, r = (int) 1e5 + 10;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (go(m, false)) l = m;
            else r = m;
        }
        go(l, true);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ts = 1;
        for (int its = 1; its <= ts; its++) {
            solve();
        }
    }
}
