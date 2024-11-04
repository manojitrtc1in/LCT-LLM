import java.util.*;

class Bitset<N> {
    private int n;
    private int[] data;
    private int[] arr_;

    public Bitset() {
        n = (N + 31) / 32;
        arr_ = new int[n];
        data = arr_;
        reset();
    }

    public Bitset<N> operator=(Bitset<N> other) {
        arr_ = other.arr_;
        data = arr_.data();
        return this;
    }

    public Bitset<N>(Bitset<N> other) {
        arr_ = other.arr_;
        data = arr_.data();
    }

    public Bitset<N> operator=(Bitset<N> other) {
        arr_ = other.arr_;
        data = arr_.data();
        return this;
    }

    public Bitset<N>(Bitset<N> other) {
        arr_ = other.arr_;
        data = arr_.data();
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
        return ((data[pos >> 5] >> (pos & 31)) & 1) == 1;
    }

    public Bitset<N> operator |=(Bitset<N> other) {
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            int C = A | B;
            data[i] = C;
        }
        for (; i < n; ++i) {
            data[i] |= other.data[i];
        }
        return this;
    }

    public Bitset<N> operator |(Bitset<N> other) {
        Bitset<N> res = new Bitset<N>();
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            int C = A | B;
            res.data[i] = C;
        }
        for (; i < n; ++i) {
            res.data[i] = data[i] | other.data[i];
        }
        return res;
    }

    public Bitset<N> operator &=(Bitset<N> other) {
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            int C = A & B;
            data[i] = C;
        }
        for (; i < n; ++i) {
            data[i] &= other.data[i];
        }
        return this;
    }

    public Bitset<N> operator &(Bitset<N> other) {
        Bitset<N> res = new Bitset<N>();
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            int C = A & B;
            res.data[i] = C;
        }
        for (; i < n; ++i) {
            res.data[i] = data[i] & other.data[i];
        }
        return res;
    }

    public Bitset<N> operator ^=(Bitset<N> other) {
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            int C = A ^ B;
            data[i] = C;
        }
        for (; i < n; ++i) {
            data[i] ^= other.data[i];
        }
        return this;
    }

    public Bitset<N> operator ^(Bitset<N> other) {
        Bitset<N> res = new Bitset<N>();
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            int C = A ^ B;
            res.data[i] = C;
        }
        for (; i < n; ++i) {
            res.data[i] = data[i] ^ other.data[i];
        }
        return res;
    }

    public Bitset<N> operator <<=(int shift) {
        int full = shift >> 5;
        if (full >= n) {
            reset();
            return this;
        }
        if (full != 0) {
            System.arraycopy(data, 0, data, full, n - full);
            Arrays.fill(data, 0, full, 0);
        }

        shift &= 31;
        if (shift != 0) {
            int i = n - 1;
            for (; i >= 4; i -= 4) {
                int P = data[i - 4];
                int A = data[i - 3];
                P = P >>> (32 - shift);
                A = A << shift;
                A = A | P;
                data[i - 3] = A;
            }
            for (; i >= 1; --i) {
                data[i] = (data[i] << shift) | (data[i - 1] >>> (32 - shift));
            }
            data[0] = data[0] << shift;
        }

        return this;
    }

    public Bitset<N> operator <<(int shift) {
        Bitset<N> res = new Bitset<N>();
        int full = shift >> 5;
        if (full >= n) {
            return res;
        }
        if (full != 0) {
            System.arraycopy(data, 0, res.data, full, n - full);
            Arrays.fill(res.data, 0, full, 0);
            return res <<= shift & 31;
        }

        shift &= 31;
        if (shift != 0) {
            int i = n - 1;
            for (; i >= 4; i -= 4) {
                int P = data[i - 4];
                int A = data[i - 3];
                P = P >>> (32 - shift);
                A = A << shift;
                A = A | P;
                res.data[i - 3] = A;
            }
            for (; i >= 1; --i) {
                res.data[i] = (data[i] << shift) | (data[i - 1] >>> (32 - shift));
            }
            res.data[0] = data[0] << shift;
        } else {
            System.arraycopy(data, 0, res.data, 0, n);
        }

        return res;
    }

    public Bitset<N> operator >>=(int shift) {
        int full = shift >> 5;
        if (full >= n) {
            reset();
            return this;
        }
        if (full != 0) {
            System.arraycopy(data, full, data, 0, n - full);
            Arrays.fill(data, n - full, n, 0);
        }

        shift &= 31;
        if (shift != 0) {
            int u = (1 << shift) - 1;
            int i = 0;
            for (; i + 4 < n - 1; i += 4) {
                int NX = data[i + 1];
                int A = data[i];
                NX = NX & u;
                NX = NX << (32 - shift);
                A = A >>> shift;
                A = A | NX;
                data[i] = A;
            }
            for (; i < n - 1; ++i) {
                data[i] = (data[i] >>> shift) | ((data[i + 1] & u) << (32 - shift));
            }
            data[n - 1] = data[n - 1] >>> shift;
        }

        return this;
    }

    public Bitset<N> operator >>(int shift) {
        Bitset<N> res = new Bitset<N>();
        int full = shift >> 5;
        if (full >= n) {
            return res;
        }
        if (full != 0) {
            System.arraycopy(data, full, res.data, 0, n - full);
            Arrays.fill(res.data, n - full, n, 0);
            return res >>= shift & 31;
        }

        shift &= 31;
        if (shift != 0) {
            int u = (1 << shift) - 1;
            int i = 0;
            for (; i + 4 < n - 1; i += 4) {
                int NX = data[i + 1];
                int A = data[i];
                NX = NX & u;
                NX = NX << (32 - shift);
                A = A >>> shift;
                A = A | NX;
                res.data[i] = A;
            }
            for (; i < n - 1; ++i) {
                res.data[i] = (data[i] >>> shift) | ((data[i + 1] & u) << (32 - shift));
            }
            res.data[n - 1] = data[n - 1] >>> shift;
        } else {
            System.arraycopy(data, 0, res.data, 0, n);
        }

        return res;
    }

    public int count() {
        return count(0, N);
    }

    public int count(int l, int r) {
        if ((l >> 5) == (r >> 5)) {
            return _popcnt((data[l >> 5] >> (l & 31)) & ((1 << (r - l)) - 1));
        }
        int ans = 0;
        if ((l & 31) != 0) {
            ans += _popcnt(data[l >> 5] >> (l & 31));
            l += 32 - (l & 31);
        }
        l >>= 5;
        if ((r & 31) != 0) {
            ans += _popcnt(data[r >> 5] & ((1 << (r & 31)) - 1));
            r -= r & 31;
        }
        r >>= 5;
        for (; l + 16 < r; l += 16) {
            ans += _popcnt(data[l]);
            ans += _popcnt(data[l + 1]);
            ans += _popcnt(data[l + 2]);
            ans += _popcnt(data[l + 3]);
            ans += _popcnt(data[l + 4]);
            ans += _popcnt(data[l + 5]);
            ans += _popcnt(data[l + 6]);
            ans += _popcnt(data[l + 7]);
            ans += _popcnt(data[l + 8]);
            ans += _popcnt(data[l + 9]);
            ans += _popcnt(data[l + 10]);
            ans += _popcnt(data[l + 11]);
            ans += _popcnt(data[l + 12]);
            ans += _popcnt(data[l + 13]);
            ans += _popcnt(data[l + 14]);
            ans += _popcnt(data[l + 15]);
        }
        for (; l + 8 < r; l += 8) {
            ans += _popcnt(data[l]);
            ans += _popcnt(data[l + 1]);
            ans += _popcnt(data[l + 2]);
            ans += _popcnt(data[l + 3]);
            ans += _popcnt(data[l + 4]);
            ans += _popcnt(data[l + 5]);
            ans += _popcnt(data[l + 6]);
            ans += _popcnt(data[l + 7]);
        }
        for (; l + 4 < r; l += 4) {
            ans += _popcnt(data[l]);
            ans += _popcnt(data[l + 1]);
            ans += _popcnt(data[l + 2]);
            ans += _popcnt(data[l + 3]);
        }
        for (; l < r; ++l) {
            ans += _popcnt(data[l]);
        }
        return ans;
    }

    public boolean none() {
        return none(0, N);
    }

    public boolean none(int l, int r) {
        if ((l >> 5) == (r >> 5)) {
            return ((data[l >> 5] >> (l & 31)) & ((1 << (r - l)) - 1)) == 0;
        }
        if ((l & 31) != 0) {
            if ((data[l >> 5] >> (l & 31)) != 0) return false;
            l += 32 - (l & 31);
        }
        l >>= 5;
        if ((r & 31) != 0) {
            if ((data[r >> 5] & ((1 << (r & 31)) - 1)) != 0) return false;
            r -= r & 31;
        }
        r >>= 5;
        for (; l + 4 < r; l += 4) {
            if (data[l] != 0) return false;
            if (data[l + 1] != 0) return false;
            if (data[l + 2] != 0) return false;
            if (data[l + 3] != 0) return false;
        }
        for (; l < r; ++l) {
            if (data[l] != 0) return false;
        }
        return true;
    }

    public boolean any() {
        return !none();
    }

    public boolean any(int l, int r) {
        return !none(l, r);
    }

    public int ctz() {
        return ctz(0, N);
    }

    public int ctz(int l, int r) {
        if ((l >> 5) == (r >> 5)) {
            int ans = _ctz((data[l >> 5] >> (l & 31)) & ((1 << (r - l)) - 1));
            if (ans > r - l) ans = r - l;
            return ans;
        }
        int ans = 0;
        if ((l & 31) != 0) {
            int t = data[l >> 5] >> (l & 31);
            if (t != 0) return _ctz(t);
            ans += 32 - (l & 31);
            l += 32 - (l & 31);
        }
        l >>= 5;
        int rr = r & 31;
        r >>= 5;
        for (; l + 4 < r; l += 4) {
            if (data[l] != 0) {
                break;
            }
            ans += 128;
        }
        for (; l < r; ++l) {
            if (data[l] != 0) {
                ans += _ctz(data[l]);
                return ans;
            }
            ans += 32;
        }

        if (rr != 0) {
            int cur = _ctz(data[r] & ((1 << rr) - 1));
            if (cur > rr) ans += rr; else
                ans += cur;
        }
        return ans;
    }

    public int clz() {
        return clz(0, N);
    }

    public int clz(int l, int r) {
        if ((l >> 5) == (r >> 5)) {
            int ans = _clz((data[l >> 5] >> (l & 31)) & ((1 << (r - l)) - 1)) - 32 + r - l;
            return ans;
        }
        int ans = 0;
        if ((r & 31) != 0) {
            int t = data[r >> 5] & ((1 << (r & 31)) - 1);
            if (t != 0) return _clz(t) - 32 + (r & 31);
            ans += r & 31;
            r -= r & 31;
        }
        r >>= 5;
        int cl = l & 31;
        if (cl != 0) {
            l += 32 - cl;
        }
        l >>= 5;
        for (; r - 4 >= l; r -= 4) {
            if (data[r - 4] != 0) {
                break;
            }
            ans += 128;
        }
        for (; r - 1 >= l; --r) {
            if (data[r - 1] != 0) {
                ans += _clz(data[r - 1]);
                return ans;
            }
            ans += 32;
        }
        if (cl != 0) {
            int cur = _clz(data[l - 1]);
            if (cur > 32 - cl) ans += 32 - cl; else
                ans += cur;
        }
        return ans;
    }

    public boolean operator ==(Bitset<N> other) {
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            if (A != B) {
                return false;
            }
        }
        for (; i < n; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    public boolean operator <(Bitset<N> other) {
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            if (A != B) {
                break;
            }
        }
        for (; i < n; ++i) {
            if (data[i] != other.data[i]) {
                return data[i] < other.data[i];
            }
        }
        return false;
    }

    public boolean operator >(Bitset<N> other) {
        int i = 0;
        for (; i + 4 < n; i += 4) {
            int A = data[i];
            int B = other.data[i];
            if (A != B) {
                break;
            }
        }
        for (; i < n; ++i) {
            if (data[i] != other.data[i]) {
                return data[i] > other.data[i];
            }
        }
        return false;
    }

    public boolean operator <=(Bitset<N> other) {
        return !operator>(other);
    }

    public boolean operator >=(Bitset<N> other) {
        return !operator<(other);
    }

    public boolean operator !=(Bitset<N> other) {
        return !operator==(other);
    }

    private int _popcnt(int a) {
        return Integer.bitCount(a);
    }

    private int _ctz(int a) {
        return Integer.numberOfTrailingZeros(a);
    }

    private int _clz(int a) {
        return Integer.numberOfLeadingZeros(a);
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
            good[i] = new Bitset<1004>();
            bad[i] = new Bitset<1004>();
        }
    }

    public void addImplication(int a, int b) {
        a = getNum(a);
        b = getNum(b);
        if (b < n) {
            good[a].set(b);
        } else {
            bad[a].set(b - n);
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
                    good[i] |= good[mid];
                    bad[i] |= bad[mid];
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
                if (!bv[j]) continue;
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

    public int num[];
    public int sof[];

    public void printSolutionAndDie(int f1, int f2) {
        num = new int[1004];
        sof = new int[1004];
        Arrays.fill(num, -1);
        if (f1 != -1) {
            if (f1 < n) {
                num[f1] = 1;
            } else {
                f1 -= n;
                num[f1] = 0;
            }
            select(f1);
        }
        if (f2 != -1) {
            if (num[f2 < n ? f2 : f2 - n] == -1) {
                if (f2 < n) {
                    num[f2] = 1;
                } else {
                    f2 -= n;
                    num[f2] = 0;
                }
                select(f2);
            }
        }
        for (int i = 0; i < n; i++) {
            if (num[i] == -1) {
                num[i] = 0;
                if (!select(i)) {
                    num[i] = 1;
                    select(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                System.out.print(" ");
            }
            System.out.print(num[i]);
        }
        System.out.println();
        System.exit(0);
    }

    public boolean select(int v) {
        int t = v;
        if (num[v] == 0) {
            t += n;
        }
        if (bv[t]) {
            return false;
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
            return false;
        }
        return true;
    }

    public int getNum(int a) {
        if (a > 0) {
            return a - 1;
        } else {
            a = -a;
            return n + a - 1;
        }
    }

    public int neg(int a) {
        if (a < n) {
            return a + n;
        } else {
            return a - n;
        }
    }

    public boolean checkBad(int v1, int v2) {
        Bitset<1004> t = (good[v1] | good[v2]) & (bad[v1] | bad[v2]);
        return t.any();
    }
}

public class 3f1bf7023dfd3a9069a458a0339df56f_nc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m1 = sc.nextInt();
        int m2 = sc.nextInt();
        int[][] cl1 = new int[m1][2];
        int[][] cl2 = new int[m2][2];
        for (int i = 0; i < m1; i++) {
            cl1[i][0] = sc.nextInt();
            cl1[i][1] = sc.nextInt();
        }
        for (int i = 0; i < m2; i++) {
            cl2[i][0] = sc.nextInt();
            cl2[i][1] = sc.nextInt();
        }
        IG g1 = new IG();
        IG g2 = new IG();
        for (int i = 0; i < m1; i++) {
            g1.add(cl1[i][0], cl1[i][1]);
        }
        for (int i = 0; i < m2; i++) {
            g2.add(cl2[i][0], cl2[i][1]);
        }
        g1.transitiveClosure();
        g2.transitiveClosure();
        boolean r1 = g1.hasSolution();
        boolean r2 = g2.hasSolution();
        if (!r1 && !r2) {
            System.out.println("SIMILAR");
            System.exit(0);
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
        boolean[][] used = new boolean[2002][2002];
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
