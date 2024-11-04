import java.util.*;

class Bitset<N> {
    private final int n;
    private final int[] data;

    public Bitset() {
        n = (N + 31) / 32;
        data = new int[n];
        reset();
    }

    public Bitset<N> set() {
        Arrays.fill(data, -1);
        return this;
    }

    public Bitset<N> set(int pos) {
        data[pos >> 5] |= 1 << (pos & 31);
        return this;
    }

    public Bitset<N> reset() {
        Arrays.fill(data, 0);
        return this;
    }

    public Bitset<N> reset(int pos) {
        data[pos >> 5] &= ~(1 << (pos & 31));
        return this;
    }

    public Bitset<N> flip(int pos) {
        data[pos >> 5] ^= 1 << (pos & 31);
        return this;
    }

    public boolean test(int pos) {
        return ((data[pos >> 5] >> (pos & 31)) & 1) == 1;
    }

    public Bitset<N> or(Bitset<N> other) {
        Bitset<N> res = new Bitset<>();
        for (int i = 0; i < n; i++) {
            res.data[i] = data[i] | other.data[i];
        }
        return res;
    }

    public Bitset<N> and(Bitset<N> other) {
        Bitset<N> res = new Bitset<>();
        for (int i = 0; i < n; i++) {
            res.data[i] = data[i] & other.data[i];
        }
        return res;
    }

    public Bitset<N> xor(Bitset<N> other) {
        Bitset<N> res = new Bitset<>();
        for (int i = 0; i < n; i++) {
            res.data[i] = data[i] ^ other.data[i];
        }
        return res;
    }

    public Bitset<N> shiftLeft(int shift) {
        Bitset<N> res = new Bitset<>();
        int full = shift >> 5;
        if (full >= n) {
            return res;
        }
        if (full > 0) {
            System.arraycopy(data, full, res.data, 0, n - full);
            Arrays.fill(res.data, n - full, n, 0);
        }

        shift &= 31;
        if (shift > 0) {
            int i = n - 1;
            for (; i >= 1; i--) {
                res.data[i] = (data[i] << shift) | (data[i - 1] >>> (32 - shift));
            }
            res.data[0] = data[0] << shift;
        } else {
            System.arraycopy(data, 0, res.data, 0, n);
        }

        return res;
    }

    public Bitset<N> shiftRight(int shift) {
        Bitset<N> res = new Bitset<>();
        int full = shift >> 5;
        if (full >= n) {
            return res;
        }
        if (full > 0) {
            System.arraycopy(data, 0, res.data, full, n - full);
            Arrays.fill(res.data, 0, full, 0);
        }

        shift &= 31;
        if (shift > 0) {
            int i = 0;
            for (; i < n - 1; i++) {
                res.data[i] = (data[i] >>> shift) | (data[i + 1] << (32 - shift));
            }
            res.data[n - 1] = data[n - 1] >>> shift;
        } else {
            System.arraycopy(data, 0, res.data, 0, n);
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
        for (int i = 0; i < n; i++) {
            if (data[i] != 0) {
                return false;
            }
        }
        return true;
    }

    public boolean any() {
        return !none();
    }

    public int ctz() {
        for (int i = 0; i < n; i++) {
            if (data[i] != 0) {
                return Integer.numberOfTrailingZeros(data[i]) + (i << 5);
            }
        }
        return n << 5;
    }

    public int clz() {
        for (int i = n - 1; i >= 0; i--) {
            if (data[i] != 0) {
                return Integer.numberOfLeadingZeros(data[i]) + ((n - 1 - i) << 5);
            }
        }
        return n << 5;
    }

    public boolean equals(Bitset<N> other) {
        for (int i = 0; i < n; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    public boolean lessThan(Bitset<N> other) {
        for (int i = n - 1; i >= 0; i--) {
            if (data[i] != other.data[i]) {
                return data[i] < other.data[i];
            }
        }
        return false;
    }

    public boolean greaterThan(Bitset<N> other) {
        for (int i = n - 1; i >= 0; i--) {
            if (data[i] != other.data[i]) {
                return data[i] > other.data[i];
            }
        }
        return false;
    }

    public boolean lessThanOrEqual(Bitset<N> other) {
        return !greaterThan(other);
    }

    public boolean greaterThanOrEqual(Bitset<N> other) {
        return !lessThan(other);
    }

    public boolean notEquals(Bitset<N> other) {
        return !equals(other);
    }
}

class IG {
    private final Bitset<1004>[] good;
    private final Bitset<1004>[] bad;
    private final boolean[] bv;

    public IG() {
        good = new Bitset[2004];
        bad = new Bitset[2004];
        bv = new boolean[2004];
        for (int i = 0; i < 2004; i++) {
            good[i] = new Bitset<>();
            bad[i] = new Bitset<>();
        }
    }

    public void addImplication(int a, int b) {
        int v1 = getNum(a);
        int v2 = getNum(b);
        if (v2 < n) {
            good[v1].set(v2);
        } else {
            bad[v1].set(v2 - n);
        }
    }

    public void add(int a, int b) {
        addImplication(-a, b);
        addImplication(-b, a);
    }

    public void transitiveClosure() {
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
                if (bad[i].test(i)) {
                    bv[i] = true;
                }
            } else {
                if (good[i].test(i - n)) {
                    bv[i] = true;
                }
            }
        }

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                if (!bv[j]) {
                    continue;
                }
                if (j < n) {
                    if (good[i].test(j)) {
                        bv[i] = true;
                    }
                } else {
                    if (bad[i].test(j - n)) {
                        bv[i] = true;
                    }
                }
            }
        }
    }

    public boolean hasSolution() {
        for (int i = 0; i < n; i++) {
            if (bad[i].test(i) && good[i + n].test(i)) {
                return false;
            }
        }
        return true;
    }

    public void printSolutionAndDie(int f1, int f2) {
        int[] num = new int[1004];
        Arrays.fill(num, -1);
        if (f1 != -1) {
            if (f1 < n) {
                num[f1] = 1;
            } else {
                f1 -= n;
                num[f1] = 0;
            }
            select(num, f1);
        }
        if (f2 != -1) {
            if (num[f2 < n ? f2 : f2 - n] == -1) {
                if (f2 < n) {
                    num[f2] = 1;
                } else {
                    f2 -= n;
                    num[f2] = 0;
                }
                select(num, f2);
            }
        }
        for (int i = 0; i < n; i++) {
            if (num[i] == -1) {
                num[i] = 0;
                select(num, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(num[i]);
        }
        System.out.println();
        System.exit(0);
    }

    private boolean select(int[] num, int v) {
        int t = v;
        if (num[v] == 0) {
            t += n;
        }
        if (bv[t]) {
            return false;
        }
        int k = 0;
        int[] sof = new int[1004];
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

    private int getNum(int a) {
        if (a > 0) {
            return a - 1;
        } else {
            a = -a;
            return n + a - 1;
        }
    }

    private int neg(int a) {
        if (a < n) {
            return a + n;
        } else {
            return a - n;
        }
    }
}

public class d4a7ef41ab317c1070a72811902edcd6_nc {
    private static int n, m1, m2;
    private static int[][] cl1, cl2;
    private static IG g1, g2;
    private static boolean[][] used;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m1 = scanner.nextInt();
        m2 = scanner.nextInt();
        cl1 = new int[m1][2];
        cl2 = new int[m2][2];
        g1 = new IG();
        g2 = new IG();
        used = new boolean[2002][2002];

        for (int i = 0; i < m1; i++) {
            cl1[i][0] = scanner.nextInt();
            cl1[i][1] = scanner.nextInt();
            g1.add(cl1[i][0], cl1[i][1]);
        }

        for (int i = 0; i < m2; i++) {
            cl2[i][0] = scanner.nextInt();
            cl2[i][1] = scanner.nextInt();
            g2.add(cl2[i][0], cl2[i][1]);
        }

        g1.transitiveClosure();
        g2.transitiveClosure();

        boolean r1 = g1.hasSolution();
        boolean r2 = g2.hasSolution();

        if (!r1 && !r2) {
            System.out.println("SIMILAR");
            return;
        }

        if (!r1) {
            g2.printSolutionAndDie(-1, -1);
        }

        if (!r2) {
            g1.printSolutionAndDie(-1, -1);
        }

        solve(cl1, cl2, g1, g2, m1, m2);
        solve(cl2, cl1, g2, g1, m2, m1);

        System.out.println("SIMILAR");
    }

    private static void solve(int[][] cl1, int[][] cl2, IG g1, IG g2, int m1, int m2) {
        for (int i = 0; i < m1; i++) {
            int v1 = IG.getNum(cl1[i][0]);
            int v2 = IG.getNum(cl1[i][1]);
            v1 = IG.neg(v1);
            v2 = IG.neg(v2);
            if (v1 > v2) {
                int temp = v1;
                v1 = v2;
                v2 = temp;
            }
            if (used[v1][v2]) {
                continue;
            }
            used[v1][v2] = true;

            if (g2.bv[v1] || g2.bv[v2]) {
                continue;
            }

            if (g2.checkBad(v1, v2)) {
                continue;
            }

            g2.printSolutionAndDie(v1, v2);
        }
    }
}
