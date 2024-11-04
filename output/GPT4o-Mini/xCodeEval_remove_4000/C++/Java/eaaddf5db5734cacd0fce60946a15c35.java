import java.util.*;
import java.io.*;

class Field<N> {
    private final int MOD;
    private int v;

    public Field(int x, int mod) {
        this.MOD = mod;
        this.v = x % MOD;
    }

    public Field<N> pow(int p) {
        return new Field<>(pow(v, p), MOD);
    }

    private int pow(int a, int p) {
        int r = 1, e = a;
        while (p > 0) {
            if ((p & 1) == 1) {
                r = (int) ((long) r * e % MOD);
            }
            e = (int) ((long) e * e % MOD);
            p >>= 1;
        }
        return r;
    }

    public Field<N> inv() {
        return new Field<>(pow(v, MOD - 2), MOD);
    }

    public Field<N> add(Field<N> o) {
        return new Field<>((v + o.v) % MOD, MOD);
    }

    public Field<N> subtract(Field<N> o) {
        return new Field<>((v - o.v + MOD) % MOD, MOD);
    }

    public Field<N> multiply(Field<N> o) {
        return new Field<>((int) ((long) v * o.v % MOD), MOD);
    }

    public Field<N> divide(Field<N> o) {
        return multiply(o.inv());
    }

    public static Field<Integer>[] fact(int t, int mod) {
        Field<Integer>[] F = new Field[t + 1];
        F[0] = new Field<>(1, mod);
        for (int i = 1; i <= t; i++) {
            F[i] = F[i - 1].multiply(new Field<>(i, mod));
        }
        return F;
    }

    public static Field<Integer>[] invfact(int t, int mod) {
        Field<Integer>[] F = new Field[t + 1];
        F[t] = new Field<>(1, mod);
        Field<Integer> X = new Field<>(1, mod);
        for (int i = 2; i <= t; i++) {
            X = X.multiply(new Field<>(i, mod));
        }
        F[t] = X.inv();
        for (int i = t - 1; i >= 2; i--) {
            F[i] = F[i + 1].multiply(new Field<>(i + 1, mod));
        }
        return F;
    }

    @Override
    public String toString() {
        return String.valueOf(v);
    }
}

class DDostizhimieStroki {
    private static final int MAXN = 200200;
    private int[] st = new int[MAXN];
    private int[] p = new int[MAXN];
    private int[] f = new int[MAXN];
    private String s;
    private StringBuilder t = new StringBuilder();
    private Field<Integer>[] h1 = new Field[MAXN];
    private Field<Integer>[] h2 = new Field[MAXN];
    private Field<Integer> p1 = new Field<>(7, 987655723);
    private Field<Integer> p2 = new Field<>(13, 987656927);

    private void buildHash() {
        Field<Integer> cp = p1;
        h1[0] = new Field<>(t.charAt(0) - '0', 987655723);
        for (int i = 1; i < t.length(); i++) {
            h1[i] = h1[i - 1].add(new Field<>(t.charAt(i) - '0', 987655723).multiply(cp));
            cp = cp.multiply(p1);
        }

        cp = p2;
        h2[0] = new Field<>(t.charAt(0) - '0', 987656927);
        for (int i = 1; i < t.length(); i++) {
            h2[i] = h2[i - 1].add(new Field<>(t.charAt(i) - '0', 987656927).multiply(cp));
            cp = cp.multiply(p2);
        }
    }

    private Pair<Integer, Integer> getH(int l, int r) {
        if (l + f[l] - 1 >= r) return new Pair<>(-1, -1);

        int b = st[l + f[l]];
        int e = st[r - p[r]];

        int len = e - b + 1;

        Field<Integer> hm1 = h1[e].subtract(h1[b - 1]).divide(p1.pow(b));
        if (p[r] % 2 == 1) {
            len++;
            hm1 = hm1.add(p1.pow(e - b + 1));
        }

        if (f[l] % 2 == 1) {
            len++;
            hm1 = new Field<>(1, 987655723).add(hm1.multiply(p1));
        }

        Field<Integer> hm2 = h2[e].subtract(h2[b - 1]).divide(p2.pow(b));
        if (p[r] % 2 == 1) {
            hm2 = hm2.add(p2.pow(e - b + 1));
        }

        if (f[l] % 2 == 1) {
            hm2 = new Field<>(1, 987656927).add(hm2.multiply(p2));
        }

        return new Pair<>(hm1.v, hm2.v);
    }

    private String id6(int l, int r) {
        if (l + f[l] - 1 >= r) return "-1";

        int b = st[l + f[l]];
        int e = st[r - p[r]];

        StringBuilder ans = new StringBuilder(t.substring(b, e + 1));
        if (p[r] % 2 == 1) ans.append('1');
        if (f[l] % 2 == 1) ans.insert(0, '1');
        return ans.toString();
    }

    public void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        PrintWriter writer = new PrintWriter(out);

        int n = Integer.parseInt(reader.readLine());
        s = reader.readLine();
        n = s.length();

        s = '0' + s + '0';

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1' && s.charAt(i + 1) == '1') {
                i++;
                continue;
            }
            t.append(s.charAt(i));
            st[i] = t.length() - 1;
        }

        p[0] = s.charAt(0) == '1' ? 1 : 0;

        for (int i = 1; i < s.length(); i++) {
            p[i] = s.charAt(i) == '0' ? 0 : p[i - 1] + 1;
        }

        f[s.length() - 1] = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            f[i] = s.charAt(i) == '0' ? 0 : f[i + 1] + 1;
        }

        buildHash();

        int q = Integer.parseInt(reader.readLine());

        for (int i = 0; i < q; i++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (getH(a, a + c - 1).equals(getH(b, b + c - 1))) {
                writer.println("Yes");
            } else {
                writer.println("No");
            }
        }

        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        DDostizhimieStroki solver = new DDostizhimieStroki();
        solver.solve(System.in, System.out);
    }
}
