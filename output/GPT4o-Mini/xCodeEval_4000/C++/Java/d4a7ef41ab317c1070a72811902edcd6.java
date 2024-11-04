import java.io.*;
import java.util.*;

class Bitset<N> {
    private final int n = (N + 31) / 32;
    private final int[] data = new int[n];
    
    public Bitset() {
        reset();
    }

    public void set() {
        Arrays.fill(data, -1);
    }

    public void set(int pos) {
        data[pos >> 5] |= 1 << (pos & 31);
    }

    public void reset() {
        Arrays.fill(data, 0);
    }

    public void reset(int pos) {
        data[pos >> 5] &= ~(1 << (pos & 31));
    }

    public void flip(int pos) {
        data[pos >> 5] ^= 1 << (pos & 31);
    }

    public boolean test(int pos) {
        return (data[pos >> 5] >> (pos & 31) & 1) != 0;
    }

    public Bitset<N> or(Bitset<N> other) {
        Bitset<N> res = new Bitset<>();
        for (int i = 0; i < n; i++) {
            res.data[i] = this.data[i] | other.data[i];
        }
        return res;
    }

    public Bitset<N> and(Bitset<N> other) {
        Bitset<N> res = new Bitset<>();
        for (int i = 0; i < n; i++) {
            res.data[i] = this.data[i] & other.data[i];
        }
        return res;
    }

    public Bitset<N> xor(Bitset<N> other) {
        Bitset<N> res = new Bitset<>();
        for (int i = 0; i < n; i++) {
            res.data[i] = this.data[i] ^ other.data[i];
        }
        return res;
    }

    public int count() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += Integer.bitCount(data[i]);
        }
        return count;
    }

    public boolean none() {
        for (int i : data) {
            if (i != 0) return false;
        }
        return true;
    }

    public boolean any() {
        return !none();
    }

    public boolean equals(Bitset<N> other) {
        return Arrays.equals(this.data, other.data);
    }

    public boolean lessThan(Bitset<N> other) {
        for (int i = 0; i < n; i++) {
            if (this.data[i] != other.data[i]) {
                return this.data[i] < other.data[i];
            }
        }
        return false;
    }
}

class IG {
    private final Bitset<1004>[] good = new Bitset[2004];
    private final Bitset<1004>[] bad = new Bitset[2004];
    private final boolean[] bv = new boolean[2004];

    public IG() {
        for (int i = 0; i < 2004; i++) {
            good[i] = new Bitset<>();
            bad[i] = new Bitset<>();
        }
        Arrays.fill(bv, false);
    }

    private static int getNum(int a, int n) {
        return a > 0 ? a - 1 : n + -a - 1;
    }

    private static int neg(int a, int n) {
        return a < n ? a + n : a - n;
    }

    public void addImplication(int a, int b, int n) {
        a = getNum(a, n);
        b = getNum(b, n);
        if (b < n) {
            good[a].set(b);
        } else {
            bad[a].set(b - n);
        }
    }

    public void add(int a, int b, int n) {
        addImplication(-a, b, n);
        addImplication(-b, a, n);
    }

    public void transitiveClosure(int n) {
        for (int i = 0; i < 2 * n; i++) {
            if (i < n) {
                good[i].set(i);
            } else {
                bad[i].set(i - n);
            }
        }
        for (int mid = 0; mid < 2 * n; mid++) {
            for (int i = 0; i < 2 * n; i++) {
                boolean ok = false;
                if (mid < n) {
                    if (good[i].test(mid)) {
                        ok = true;
                    }
                } else {
                    if (bad[i].test(mid - n)) {
                        ok = true;
                    }
                }
                if (ok) {
                    good[i] = good[i].or(good[mid]);
                    bad[i] = bad[i].or(bad[mid]);
                }
            }
        }

        for (int i = 0; i < 2 * n; i++) {
            if (i < n) {
                if (bad[i].test(i)) bv[i] = true;
            } else {
                if (good[i].test(i - n)) bv[i] = true;
            }
        }

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                if (!bv[j]) continue;
                if (j < n) {
                    if (good[i].test(j)) bv[i] = true;
                } else {
                    if (bad[i].test(j - n)) bv[i] = true;
                }
            }
        }
    }

    public boolean hasSolution(int n) {
        for (int i = 0; i < n; i++) {
            if (bad[i].test(i) && good[i + n].test(i)) {
                return false;
            }
        }
        return true;
    }

    private final int[] num = new int[1004];
    private final int[] sof = new int[1004];

    public boolean select(int v, int n) {
        int t = v;
        if (num[v] == 0) t += n;
        if (bv[t]) return false;
        int k = 0;
        sof[k++] = v;
        boolean ok = true;
        for (int i = 0; i < n; i++) {
            if (good[t].test(i)) {
                if (num[i] == 0) {
                    ok = false;
                    break;
                }
                if (num[i] == -1) {
                    num[i] = 1;
                    sof[k++] = i;
                }
            }
            if (bad[t].test(i)) {
                if (num[i] == 1) {
                    ok = false;
                    break;
                }
                if (num[i] == -1) {
                    num[i] = 0;
                    sof[k++] = i;
                }
            }
        }

        if (!ok) {
            for (int i = 0; i < k; i++) {
                num[sof[i]] = -1;
            }
            return false;
        }
        return true;
    }

    public void printSolutionAndDie(int f1, int f2, int n) {
        Arrays.fill(num, -1);
        if (f1 != -1) {
            if (f1 < n) {
                num[f1] = 1;
            } else {
                f1 -= n;
                num[f1] = 0;
            }
            select(f1, n);
        }
        if (f2 != -1) {
            if (num[f2 < n ? f2 : f2 - n] == -1) {
                if (f2 < n) {
                    num[f2] = 1;
                } else {
                    f2 -= n;
                    num[f2] = 0;
                }
                select(f2, n);
            }
        }
        for (int i = 0; i < n; i++) {
            if (num[i] != -1) continue;
            num[i] = 0;
            if (!select(i, n)) {
                num[i] = 1;
                select(i, n);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(num[i]);
        }
        System.out.println();
        System.exit(0);
    }

    public boolean checkBad(int v1, int v2) {
        Bitset<1004> t = good[v1].or(good[v2]).and(bad[v1].or(bad[v2]));
        return t.any();
    }
}

public class d4a7ef41ab317c1070a72811902edcd6_nc {
    private static final int MAX_SIZE = 65537;
    private static final char[] buf = new char[MAX_SIZE];
    private static int index = 0;

    private static char getChar(InputStreamReader reader) throws IOException {
        if (index == 0) {
            index = reader.read(buf);
        }
        return buf[--index];
    }

    private static void nextInt(InputStreamReader reader, int[] ans) throws IOException {
        ans[0] = 0;
        char ch;
        while (((ch = getChar(reader)) < '0' || ch > '9') && ch != '-');
        boolean neg = false;
        if (ch == '-') {
            neg = true;
            ch = getChar(reader);
        }
        do {
            ans[0] = ans[0] * 10 + ch - '0';
        } while ((ch = getChar(reader)) >= '0' && ch <= '9');
        if (neg) ans[0] = -ans[0];
    }

    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in);
        int n, m1, m2;
        nextInt(reader, new int[]{n});
        nextInt(reader, new int[]{m1});
        nextInt(reader, new int[]{m2});

        IG g1 = new IG();
        IG g2 = new IG();
        Pair<Integer, Integer>[] cl1 = new Pair[1000002];
        Pair<Integer, Integer>[] cl2 = new Pair[1000002];

        for (int i = 0; i < m1; i++) {
            int a, b;
            nextInt(reader, new int[]{a});
            nextInt(reader, new int[]{b});
            cl1[i] = new Pair<>(a, b);
            g1.add(a, b, n);
        }

        for (int i = 0; i < m2; i++) {
            int a, b;
            nextInt(reader, new int[]{a});
            nextInt(reader, new int[]{b});
            cl2[i] = new Pair<>(a, b);
            g2.add(a, b, n);
        }

        g1.transitiveClosure(n);
        g2.transitiveClosure(n);

        boolean r1 = g1.hasSolution(n);
        boolean r2 = g2.hasSolution(n);
        if (!r1 && !r2) {
            System.out.println("SIMILAR");
            System.exit(0);
        }
        if (!r1) {
            g2.printSolutionAndDie(-1, -1, n);
        }
        if (!r2) {
            g1.printSolutionAndDie(-1, -1, n);
        }
        solve(cl1, cl2, g1, g2, m1, m2, n);
        solve(cl2, cl1, g2, g1, m2, m1, n);
        System.out.println("SIMILAR");
    }

    private static void solve(Pair<Integer, Integer>[] cl1, Pair<Integer, Integer>[] cl2, IG g1, IG g2, int m1, int m2, int n) {
        boolean[][] used = new boolean[2002][2002];
        for (int i = 0; i < m1; i++) {
            int v1 = IG.getNum(cl1[i].getKey(), n);
            int v2 = IG.getNum(cl1[i].getValue(), n);
            v1 = IG.neg(v1, n);
            v2 = IG.neg(v2, n);
            if (v1 > v2) {
                int temp = v1;
                v1 = v2;
                v2 = temp;
            }
            if (used[v1][v2]) continue;
            used[v1][v2] = true;

            if (g2.bv[v1] || g2.bv[v2]) continue;
            if (g2.checkBad(v1, v2)) continue;
            g2.printSolutionAndDie(v1, v2, n);
        }
    }
}

class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}
