import java.util.*;
import java.io.*;

class Main {
    static class Pair {
        int fr, sc;
        Pair(int fr, int sc) {
            this.fr = fr;
            this.sc = sc;
        }
    }

    static class Mint {
        static int md = 998244353;
        int value;

        Mint() {
            value = 0;
        }

        Mint(int x) {
            value = normalize(x);
        }

        static int normalize(int x) {
            int v;
            if (-mod() <= x && x < mod()) v = x;
            else v = x % mod();
            if (v < 0) v += mod();
            return v;
        }

        int mod() {
            return md;
        }

        Mint add(Mint other) {
            if ((value += other.value) >= mod()) value -= mod();
            return this;
        }

        Mint subtract(Mint other) {
            if ((value -= other.value) < 0) value += mod();
            return this;
        }

        Mint multiply(Mint other) {
            value = normalize((long)value * other.value);
            return this;
        }

        Mint divide(Mint other) {
            return multiply(inverse(other.value, mod()));
        }

        static int inverse(int a, int m) {
            int u = 0, v = 1;
            while (a != 0) {
                int t = m / a;
                m -= t * a;
                int temp = a;
                a = m;
                m = temp;
                u -= t * v;
                temp = u;
                u = v;
                v = temp;
            }
            assert(m == 1);
            return u;
        }
    }

    static class Hasher {
        int hash(Pair x) {
            return x.fr * 1234567 + x.sc * 7893215;
        }
    }

    static int llinf = (int)1e18 + 100;
    static int maxn = (int)1e5 + 100, maxw = (1 << 20) + 5, inf = (int)1e9 + 100, LG = 18;
    static String s;
    static ArrayList<Integer>[] o = new ArrayList[2];
    static ArrayList<Integer> ind;
    static ArrayList<Pair> nxt;
    static int it;

    static boolean can(int n) {
        if (n == 1)
            return true;

        int IT = it;
        int x = n / 2, y = (n + 1) / 2;
        if (!can(x) || !can(y))
            return false;
        int p0 = nxt.get(it).fr, p1 = nxt.get(it).sc;
        if (p0 == s.length() || ind.get(p0) + x - 1 >= o[0].size())
            p0 = s.length();
        else
            p0 = o[0].get(ind.get(p0) + x - 1);
        if (p1 == s.length() || ind.get(p1) + y - 1 >= o[1].size())
            p1 = s.length();
        else
            p1 = o[1].get(ind.get(p1) + y - 1);
        p0 = Math.min(p0, p1);
        if (p0 == s.length()) {
            return false;
        }
        it = p0 + 1;
        return true;
    }

    static int[] id = new int[maxn];
    static int[] mas = new int[maxn];

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
        }
    }

    static boolean go(int n, boolean cert) {
        it = 0;
        if (!cert)
            return can(n);
        it = 0;
        can(n);
        assert(it == s.length());

        it = 0;
        for (int i = 0; i < n; i++)
            id[i] = i;
        gen(0, n - 1);
        assert(it == s.length());
        int[] p = new int[n];
        for (int i = 0; i < n; i++)
            p[id[i]] = i;
        System.out.println(n);
        for (int i : p)
            System.out.print((i + 1) + " ");
        System.out.println();
        System.exit(0);
        return true;
    }

    static int[][] seg = new int[maxn][2];
    static Pair[] len = new Pair[maxn];

    static void solve() {
        for (int i = 2; i < maxn; i++) {
            int x = i / 2, y = i - x;
            len[i] = new Pair(len[x].fr + len[y].fr + x, len[x].sc + len[y].sc + x + y - 1);
            for (int t = 0; t < 2; t++) {
                seg[i][t] = seg[x][t] + seg[y][t];
            }
            seg[i][0] += x;
            seg[i][1] += y;
        }
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        int[] counter = new int[2];
        nxt = new ArrayList<>();
        ind = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 48;
            counter[c]++;
            ind.add(o[c].size());
            o[c].add(i);
        }
        nxt.add(new Pair(s.length(), s.length()));
        for (int i = s.length() - 1; i >= 0; i--) {
            nxt.add(new Pair(nxt.get(nxt.size() - 1).fr, nxt.get(nxt.size() - 1).sc));
            nxt.get(nxt.size() - 1).fr = (s.charAt(i) - 48 == 0 ? i : nxt.get(nxt.size() - 1).fr);
            nxt.get(nxt.size() - 1).sc = (s.charAt(i) - 48 == 1 ? i : nxt.get(nxt.size() - 1).sc);
        }
        int l = 0, r = 1e5 + 10;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (go(m, false))
                l = m;
            else
                r = m;
        }
        go(l, true);
    }

    public static void main(String[] args) {
        int ts = 1;
        for (int its = 1; its <= ts; its++) {
            solve();
        }
    }
}
