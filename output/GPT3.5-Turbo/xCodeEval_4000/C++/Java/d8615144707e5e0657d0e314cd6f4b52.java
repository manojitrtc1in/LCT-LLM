import java.util.*;

class Bitset<N> {
    private int n;
    private int[] data;

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
        Bitset<N> result = new Bitset<>();
        for (int i = 0; i < n; i++) {
            result.data[i] = this.data[i] | other.data[i];
        }
        return result;
    }

    public Bitset<N> and(Bitset<N> other) {
        Bitset<N> result = new Bitset<>();
        for (int i = 0; i < n; i++) {
            result.data[i] = this.data[i] & other.data[i];
        }
        return result;
    }

    public Bitset<N> xor(Bitset<N> other) {
        Bitset<N> result = new Bitset<>();
        for (int i = 0; i < n; i++) {
            result.data[i] = this.data[i] ^ other.data[i];
        }
        return result;
    }

    public Bitset<N> shiftLeft(int shift) {
        int full = shift >> 5;
        if (full >= n) {
            reset();
            return this;
        }
        if (full > 0) {
            System.arraycopy(data, full, data, 0, n - full);
            Arrays.fill(data, n - full, n, 0);
        }

        shift &= 31;
        if (shift > 0) {
            int i = n - 1;
            for (; i >= 1; i--) {
                data[i] = (data[i] << shift) | (data[i - 1] >>> (32 - shift));
            }
            data[0] <<= shift;
        }

        return this;
    }

    public Bitset<N> shiftRight(int shift) {
        int full = shift >> 5;
        if (full >= n) {
            reset();
            return this;
        }
        if (full > 0) {
            System.arraycopy(data, 0, data, full, n - full);
            Arrays.fill(data, 0, full, 0);
        }

        shift &= 31;
        if (shift > 0) {
            int i = 0;
            for (; i < n - 1; i++) {
                data[i] = (data[i] >>> shift) | (data[i + 1] << (32 - shift));
            }
            data[n - 1] >>>= shift;
        }

        return this;
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
                return 31 - Integer.numberOfLeadingZeros(data[i]) + (i << 5);
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
    private Bitset<1004>[] good;
    private Bitset<1004>[] bad;
    private boolean[] bv;

    public IG() {
        good = new Bitset[2004];
        bad = new Bitset[2004];
        bv = new boolean[2004];
        for (int i = 0; i < 2004; i++) {
            good[i] = new Bitset<>();
            bad[i] = new Bitset<>();
        }
    }

    public static int getNum(int a, int n) {
        if (a > 0) {
            return a - 1;
        } else {
            return n + a - 1;
        }
    }

    public static int neg(int a, int n) {
        if (a < n) {
            return a + n;
        } else {
            return a - n;
        }
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

    public boolean hasSolution(int n) {
        for (int i = 0; i < n; i++) {
            if (bad[i].test(i) && good[i + n].test(i)) {
                return false;
            }
        }
        return true;
    }

    public void select(int v, int n) {
        int t = v;
        if (num[v] == 0) {
            t += n;
        }
        if (bv[t]) {
            return;
        }
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
            return;
        }
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
            if (num[i] != -1) {
                continue;
            }
            num[i] = 0;
            if (!select(i, n)) {
                num[i] = 1;
                select(i, n);
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

    public boolean checkBad(int v1, int v2, int n) {
        Bitset<1004> t = good[v1].or(good[v2]).and(bad[v1].or(bad[v2]));
        return t.any();
    }
}

public class d8615144707e5e0657d0e314cd6f4b52_nc {
    private static int[] num;
    private static int[] sof;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m1 = sc.nextInt();
        int m2 = sc.nextInt();

        IG g1 = new IG();
        IG g2 = new IG();

        for (int i = 0; i < m1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            g1.add(a, b, n);
        }

        for (int i = 0; i < m2; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            g2.add(a, b, n);
        }

        g1.transitiveClosure(n);
        g2.transitiveClosure(n);

        boolean r1 = g1.hasSolution(n);
        boolean r2 = g2.hasSolution(n);

        if (!r1 && !r2) {
            System.out.println("SIMILAR");
            return;
        }

        if (!r1) {
            g2.printSolutionAndDie(-1, -1, n);
        }

        if (!r2) {
            g1.printSolutionAndDie(-1, -1, n);
        }

        solve(g1, g2, m1, m2, n);
        solve(g2, g1, m2, m1, n);

        System.out.println("SIMILAR");
    }

    private static void solve(IG g1, IG g2, int m1, int m2, int n) {
        boolean[][] used = new boolean[2002][2002];
        for (int i = 0; i < m1; i++) {
            int v1 = IG.getNum(cl1[i].x, n);
            int v2 = IG.getNum(cl1[i].y, n);
            v1 = IG.neg(v1, n);
            v2 = IG.neg(v2, n);
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

            if (g2.checkBad(v1, v2, n)) {
                continue;
            }

            g2.printSolutionAndDie(v1, v2, n);
        }
    }
}
