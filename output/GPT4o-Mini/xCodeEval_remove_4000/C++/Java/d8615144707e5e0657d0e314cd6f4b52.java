import java.util.Arrays;

class Bitset<N> {
    private final int n = (N + 31) / 32;
    private final int[] data;
    
    public Bitset() {
        data = new int[n];
        reset();
    }

    public Bitset<N> assign(Bitset<N> other) {
        System.arraycopy(other.data, 0, data, 0, n);
        return this;
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

    public int count() {
        int count = 0;
        for (int i : data) {
            count += Integer.bitCount(i);
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
        return Arrays.equals(data, other.data);
    }

    public boolean lessThan(Bitset<N> other) {
        for (int i = 0; i < n; i++) {
            if (data[i] != other.data[i]) {
                return data[i] < other.data[i];
            }
        }
        return false;
    }

    public boolean greaterThan(Bitset<N> other) {
        for (int i = 0; i < n; i++) {
            if (data[i] != other.data[i]) {
                return data[i] > other.data[i];
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
        if (a > 0) return a - 1;
        a = -a;
        return n + a - 1;
    }

    private static int neg(int a, int n) {
        if (a < n) return a + n;
        return a - n;
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

    public void printSolutionAndDie(int f1, int f2, int n) {
        int[] num = new int[1004];
        Arrays.fill(num, -1);
        if (f1 != -1) {
            if (f1 < n) {
                num[f1] = 1;
            } else {
                f1 -= n;
                num[f1] = 0;
            }
            select(f1, num);
        }
        if (f2 != -1) {
            if (num[f2 < n ? f2 : f2 - n] == -1) {
                if (f2 < n) {
                    num[f2] = 1;
                } else {
                    f2 -= n;
                    num[f1] = 0;
                }
                select(f2, num);
            }
        }
        for (int i = 0; i < n; i++) {
            if (num[i] != -1) continue;
            num[i] = 0;
            if (!select(i, num)) {
                num[i] = 1;
                select(i, num);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(num[i]);
        }
        System.out.println();
        System.exit(0);
    }

    private boolean select(int v, int[] num) {
        int t = v;
        if (num[v] == 0) t += n;
        if (bv[t]) return false;
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

    public boolean checkBad(int v1, int v2) {
        Bitset<1004> t = good[v1].or(good[v2]).and(bad[v1].or(bad[v2]));
        return t.any();
    }
}

public class d8615144707e5e0657d0e314cd6f4b52xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        int n, m1, m2;
        // Read input values for n, m1, m2
        // Initialize IG instances
        IG g1 = new IG();
        IG g2 = new IG();
        // Read implications and add them to g1 and g2
        // Perform transitive closure
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
        // Solve function calls
        System.out.println("SIMILAR");
    }
}
