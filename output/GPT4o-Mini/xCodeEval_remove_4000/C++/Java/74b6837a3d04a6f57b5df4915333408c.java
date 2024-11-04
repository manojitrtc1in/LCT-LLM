import java.util.*;
import java.io.*;

class Modular<T> {
    private long value;
    private static final int MOD = 998244353;

    public Modular() {
        this.value = 0;
    }

    public Modular(long x) {
        this.value = normalize(x);
    }

    private long normalize(long x) {
        if (x < 0) x += MOD;
        return x % MOD;
    }

    public long getValue() {
        return value;
    }

    public Modular<T> add(Modular<T> other) {
        return new Modular<>(normalize(this.value + other.value));
    }

    public Modular<T> subtract(Modular<T> other) {
        return new Modular<>(normalize(this.value - other.value));
    }

    public Modular<T> multiply(Modular<T> other) {
        return new Modular<>(normalize(this.value * other.value));
    }

    public Modular<T> divide(Modular<T> other) {
        return multiply(new Modular<>(inverse(other.value)));
    }

    private long inverse(long a) {
        long m0 = MOD, y = 0, x = 1;
        if (MOD == 1) return 0;
        while (a > 1) {
            long q = a / MOD;
            long t = MOD;
            MOD = a % MOD;
            a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;
        return x;
    }

    @Override
    public String toString() {
        return Long.toString(value);
    }
}

public class 74b6837a3d04a6f57b5df4915333408cxcodeeval_processed_4000.json {
    static final int maxn = 1100;
    static String s;
    static int it;
    static int[] id = new int[maxn];
    static int[] mas = new int[maxn];
    static int[][] seg = new int[maxn][2];
    static List<Integer>[] e = new ArrayList[maxn];

    static {
        for (int i = 0; i < maxn; i++) {
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
        while (a <= m) {
            mas[c++] = id[a++];
        }
        while (b <= r) {
            mas[c++] = id[b++];
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
        if (!can(n) || it != s.length()) return;

        it = 0;
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
        gen(0, n - 1);
        assert it == s.length();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[id[i]] = i;
        }
        System.out.println(n);
        for (int i : p) {
            System.out.print((i + 1) + " ");
        }
        System.out.println();
        System.exit(0);
    }

    static void solve() {
        for (int i = 2; i < maxn; i++) {
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
        for (char c : s.toCharArray()) {
            counter[c - '0']++;
        }
        for (int n = maxn - 1; n > 0; n--) {
            if (seg[n][0] >= counter[0] && seg[n][1] >= counter[1]) {
                go(n);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        solve();
        out.flush();
    }
}
