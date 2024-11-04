import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;

    static class ModInt {
        private int x;

        public ModInt() {
            x = 0;
        }

        public ModInt(long x_) {
            if ((x = (int)(x_ % MOD + MOD)) >= MOD) x -= MOD;
        }

        public int val() {
            return x;
        }

        public static int getMod() {
            return MOD;
        }

        public ModInt add(ModInt rhs) {
            if ((x += rhs.x) >= MOD) x -= MOD;
            return this;
        }

        public ModInt subtract(ModInt rhs) {
            if ((x -= rhs.x) < 0) x += MOD;
            return this;
        }

        public ModInt multiply(ModInt rhs) {
            x = (int)((long)x * rhs.x % MOD);
            return this;
        }

        public ModInt divide(ModInt rhs) {
            x = (int)((long)x * rhs.inverse().x % MOD);
            return this;
        }

        public ModInt negate() {
            return new ModInt(-x < 0 ? MOD - x : -x);
        }

        public ModInt increment() {
            return add(new ModInt(1));
        }

        public ModInt decrement() {
            return subtract(new ModInt(1));
        }

        public boolean equals(ModInt rhs) {
            return x == rhs.x;
        }

        public boolean notEquals(ModInt rhs) {
            return x != rhs.x;
        }

        public boolean lessThanOrEqual(ModInt rhs) {
            return x <= rhs.x;
        }

        public boolean greaterThanOrEqual(ModInt rhs) {
            return x >= rhs.x;
        }

        public boolean lessThan(ModInt rhs) {
            return x < rhs.x;
        }

        public boolean greaterThan(ModInt rhs) {
            return x > rhs.x;
        }

        public ModInt inverse() {
            int a = x, b = MOD, u = 1, v = 0, t;
            while (b > 0) {
                t = a / b;
                int temp = a - t * b;
                a = b;
                b = temp;
                u -= t * v;
                int temp2 = u;
                u = v;
                v = temp2;
            }
            return new ModInt(u);
        }

        public ModInt power(long n) {
            ModInt ret = new ModInt(1);
            ModInt mul = new ModInt(x);
            while (n > 0) {
                if ((n & 1) == 1) ret.multiply(mul);
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        public ModInt sqrt() {
            if (x <= 1) return new ModInt(x);
            int v = (MOD - 1) / 2;
            ModInt z = new ModInt(2);
            while (z.power(v).notEquals(new ModInt(MOD - 1))) z.increment();
            ModInt c = z.power((MOD - 1) / 2);
            ModInt t = power((MOD + 1) / 2);
            ModInt r = power((MOD + 1) / 4);
            for (int m = v; m > 1; m--) {
                ModInt tmp = t.power(1 << (m - 2));
                if (tmp.notEquals(new ModInt(1))) {
                    r.multiply(c);
                    t.multiply(c).multiply(c);
                }
                c.multiply(c);
            }
            return new ModInt(Math.min(r.x, MOD - r.x));
        }

        public String toString() {
            return Integer.toString(x);
        }
    }

    static class FormalPowerSeries extends ArrayList<ModInt> {
        public FormalPowerSeries() {
            super();
        }

        public FormalPowerSeries(int n) {
            super(Collections.nCopies(n, new ModInt(0)));
        }

        public FormalPowerSeries(List<ModInt> list) {
            super(list);
        }

        public FormalPowerSeries add(FormalPowerSeries r) {
            int n = Math.max(size(), r.size());
            for (int i = 0; i < n; i++) {
                if (i >= size()) add(new ModInt(0));
                if (i < r.size()) get(i).add(r.get(i));
            }
            return this;
        }

        public FormalPowerSeries add(ModInt v) {
            if (isEmpty()) add(new ModInt(0));
            get(0).add(v);
            return this;
        }

        public FormalPowerSeries subtract(FormalPowerSeries r) {
            int n = Math.max(size(), r.size());
            for (int i = 0; i < n; i++) {
                if (i >= size()) add(new ModInt(0));
                if (i < r.size()) get(i).subtract(r.get(i));
            }
            return this;
        }

        public FormalPowerSeries subtract(ModInt v) {
            if (isEmpty()) add(new ModInt(0));
            get(0).subtract(v);
            return this;
        }

        public FormalPowerSeries multiply(FormalPowerSeries r) {
            if (isEmpty() || r.isEmpty()) {
                clear();
                return this;
            }
            int n = size() + r.size() - 1;
            int m = 1;
            while (m < n) m *= 2;
            resize(m, new ModInt(0));
            FormalPowerSeries ret = new FormalPowerSeries(2 * m);
            for (int i = 0; i < size(); i++) ret.set(i, get(i));
            for (int i = 0; i < r.size(); i++) ret.set(i, ret.get(i).multiply(r.get(i)));
            ret.ntt();
            for (int i = 0; i < size(); i++) ret.set(i, ret.get(i).multiply(r.get(i)));
            ret.intt();
            for (int i = 0; i < size(); i++) set(i, ret.get(i));
            shrink();
            return this;
        }

        public FormalPowerSeries multiply(ModInt v) {
            for (int i = 0; i < size(); i++) get(i).multiply(v);
            return this;
        }

        public FormalPowerSeries divide(FormalPowerSeries r) {
            if (size() < r.size()) {
                clear();
                return this;
            }
            int n = size() - r.size() + 1;
            return this = (reverse().pre(n).multiply(r.reverse().inverse(n))).pre(n).reverse(n);
        }

        public FormalPowerSeries modulo(FormalPowerSeries r) {
            return subtract(divide(r).multiply(r));
        }

        public FormalPowerSeries reverse() {
            Collections.reverse(this);
            return this;
        }

        public FormalPowerSeries pre(int sz) {
            return new FormalPowerSeries(subList(0, Math.min(size(), sz)));
        }

        public FormalPowerSeries shiftRight(int sz) {
            FormalPowerSeries ret = new FormalPowerSeries(this);
            ret.addAll(0, Collections.nCopies(sz, new ModInt(0)));
            return ret;
        }

        public FormalPowerSeries shiftLeft(int sz) {
            FormalPowerSeries ret = new FormalPowerSeries(this);
            ret.addAll(Collections.nCopies(sz, new ModInt(0)));
            return ret;
        }

        public FormalPowerSeries diff() {
            FormalPowerSeries ret = new FormalPowerSeries(Math.max(0, size() - 1));
            for (int i = 1; i < size(); i++) ret.set(i - 1, get(i).multiply(new ModInt(i)));
            return ret;
        }

        public FormalPowerSeries integral() {
            FormalPowerSeries ret = new FormalPowerSeries(size() + 1);
            ret.set(0, new ModInt(0));
            for (int i = 0; i < size(); i++) ret.set(i + 1, get(i).divide(new ModInt(i + 1)));
            return ret;
        }

        public FormalPowerSeries inv() {
            assert get(0).notEquals(new ModInt(0));
            int n = size();
            FormalPowerSeries ret = new FormalPowerSeries(1);
            ret.set(0, get(0).inverse());
            for (int d = 1; d < n; d <<= 1) {
                FormalPowerSeries f = new FormalPowerSeries(2 * d);
                FormalPowerSeries g = new FormalPowerSeries(2 * d);
                for (int j = 0; j < Math.min(n, 2 * d); j++) f.set(j, get(j));
                for (int j = 0; j < d; j++) g.set(j, ret.get(j));
                f.ntt();
                g.ntt();
                for (int j = 0; j < 2 * d; j++) f.set(j, f.get(j).multiply(g.get(j)));
                f.intt();
                for (int j = 0; j < d; j++) {
                    f.set(j, new ModInt(0));
                    f.set(j + d, f.get(j + d).negate());
                }
                f.ntt();
                for (int j = 0; j < 2 * d; j++) f.set(j, f.get(j).multiply(g.get(j)));
                f.intt();
                for (int j = 0; j < d; j++) f.set(j, ret.get(j));
                ret = f;
            }
            return ret.pre(n);
        }

        public FormalPowerSeries log() {
            assert get(0).equals(new ModInt(1));
            int n = size();
            FormalPowerSeries ret = new FormalPowerSeries(n);
            for (int i = 1; i < n; i++) ret.set(i - 1, get(i).multiply(new ModInt(i)).inverse());
            ret = ret.integral();
            ret.resize(n - 1);
            return ret;
        }

        public FormalPowerSeries sqrt() {
            int n = size();
            if (get(0).equals(new ModInt(0))) {
                for (int i = 1; i < n; i++) {
                    if (get(i).notEquals(new ModInt(0))) {
                        if ((i & 1) == 1) return new FormalPowerSeries();
                        FormalPowerSeries ret = shiftRight(i).sqrt(n - i / 2);
                        if (ret.isEmpty()) return ret;
                        ret = ret.shiftLeft(i / 2);
                        if (ret.size() < n) ret.resize(n, new ModInt(0));
                        return ret;
                    }
                }
                return new FormalPowerSeries(n, new ModInt(0));
            }

            FormalPowerSeries ret;
            if (get(0).equals(new ModInt(1))) {
                ret = new FormalPowerSeries(1);
                ret.set(0, new ModInt(1));
            } else {
                ModInt sqr = get(0).sqrt();
                if (sqr.multiply(sqr).notEquals(get(0))) return new FormalPowerSeries();
                ret = new FormalPowerSeries(1);
                ret.set(0, sqr);
            }

            ModInt inv2 = new ModInt(1).divide(new ModInt(2));
            for (int i = 1; i < n; i <<= 1) {
                ret = ret.add(pre(i << 1).multiply(ret.inverse(i << 1))).multiply(inv2);
            }
            ret.resize(n);
            return ret;
        }

        public FormalPowerSeries exp() {
            assert get(0).equals(new ModInt(0));
            int n = size();
            FormalPowerSeries ret = new FormalPowerSeries(1);
            ret.set(0, new ModInt(1));
            for (int i = 1; i < n; i <<= 1) {
                ret = ret.multiply(pre(i << 1).add(new ModInt(1)).subtract(ret.log(i << 1))).pre(i << 1);
            }
            ret.resize(n);
            return ret;
        }

        public FormalPowerSeries pow(long k) {
            int n = size();
            FormalPowerSeries ret = new FormalPowerSeries(n);
            for (int i = 0; i < n; i++) {
                if (get(i).notEquals(new ModInt(0))) {
                    ModInt rev = get(i).inverse();
                    FormalPowerSeries temp = shiftRight(i).pow(k);
                    if (temp.isEmpty()) return new FormalPowerSeries(n, new ModInt(0));
                    temp = temp.shiftLeft(i);
                    if (temp.size() < n) temp.resize(n, new ModInt(0));
                    temp = temp.multiply(rev.power(k));
                    ret = ret.add(temp);
                }
            }
            return ret;
        }

        public ModInt evaluate(ModInt x) {
            ModInt r = new ModInt(0);
            ModInt w = new ModInt(1);
            for (ModInt v : this) {
                r = r.add(w.multiply(v));
                w = w.multiply(x);
            }
            return r;
        }

        public FormalPowerSeries powMod(long n, FormalPowerSeries mod) {
            FormalPowerSeries modinv = mod.reverse().inverse();
            FormalPowerSeries getDiv = new FormalPowerSeries();
            getDiv.clear();
            if (size() >= mod.size()) {
                int n2 = size() - mod.size() + 1;
                getDiv = (reverse().pre(n2).multiply(modinv.pre(n2))).pre(n2).reverse(n2);
            }
            FormalPowerSeries x = new FormalPowerSeries(this);
            FormalPowerSeries ret = new FormalPowerSeries(1);
            ret.set(0, new ModInt(1));
            while (n > 0) {
                if ((n & 1) == 1) {
                    ret = ret.multiply(x);
                    ret = ret.subtract(getDiv.multiply(mod));
                }
                x = x.multiply(x);
                x = x.subtract(getDiv.multiply(mod));
                n >>= 1;
            }
            return ret;
        }

        private void ntt() {
            int n = size();
            assert (n & (n - 1)) == 0;
            int maxBase = 0;
            int temp = MOD - 1;
            while (temp % 2 == 0) {
                temp >>= 1;
                maxBase++;
            }
            ModInt root = new ModInt(2);
            while (root.power((MOD - 1) >> 1).equals(new ModInt(1))) root.increment();
            assert root.power(MOD - 1).equals(new ModInt(1));
            List<ModInt> dw = new ArrayList<>();
            List<ModInt> idw = new ArrayList<>();
            for (int i = 0; i < maxBase; i++) {
                dw.add(root.power((MOD - 1) >> (i + 2)).negate());
                idw.add(dw.get(i).inverse());
            }
            for (int m = n; m >= 2; m >>= 1) {
                ModInt w = new ModInt(1);
                for (int s = 0, k = 0; s < n; s += 2 * m) {
                    for (int i = s, j = s + m; i < s + m; i++, j++) {
                        ModInt x = get(i);
                        ModInt y = get(j).multiply(w);
                        set(i, x.add(y));
                        set(j, x.subtract(y));
                    }
                    w = w.multiply(dw.get(++k));
                }
            }
        }

        private void intt() {
            int n = size();
            assert (n & (n - 1)) == 0;
            int maxBase = 0;
            int temp = MOD - 1;
            while (temp % 2 == 0) {
                temp >>= 1;
                maxBase++;
            }
            ModInt root = new ModInt(2);
            while (root.power((MOD - 1) >> 1).equals(new ModInt(1))) root.increment();
            assert root.power(MOD - 1).equals(new ModInt(1));
            List<ModInt> dw = new ArrayList<>();
            List<ModInt> idw = new ArrayList<>();
            for (int i = 0; i < maxBase; i++) {
                dw.add(root.power((MOD - 1) >> (i + 2)).negate());
                idw.add(dw.get(i).inverse());
            }
            for (int m = 1; m < n; m *= 2) {
                ModInt w = new ModInt(1);
                for (int s = 0, k = 0; s < n; s += 2 * m) {
                    for (int i = s, j = s + m; i < s + m; i++, j++) {
                        ModInt x = get(i);
                        ModInt y = get(j);
                        set(i, x.add(y));
                        set(j, x.subtract(y).multiply(w));
                    }
                    w = w.multiply(idw.get(++k));
                }
            }
            ModInt invN = new ModInt(n).inverse();
            for (int i = 0; i < n; i++) set(i, get(i).multiply(invN));
        }

        private FormalPowerSeries inverse(int deg) {
            assert get(0).notEquals(new ModInt(0));
            int n = size();
            if (deg == -1) deg = n;
            FormalPowerSeries ret = new FormalPowerSeries(1);
            ret.set(0, get(0).inverse());
            for (int d = 1; d < n; d <<= 1) {
                FormalPowerSeries f = new FormalPowerSeries(2 * d);
                FormalPowerSeries g = new FormalPowerSeries(2 * d);
                for (int j = 0; j < Math.min(n, 2 * d); j++) f.set(j, get(j));
                for (int j = 0; j < d; j++) g.set(j, ret.get(j));
                f.ntt();
                g.ntt();
                for (int j = 0; j < 2 * d; j++) f.set(j, f.get(j).multiply(g.get(j)));
                f.intt();
                for (int j = 0; j < d; j++) {
                    f.set(j, new ModInt(0));
                    f.set(j + d, f.get(j + d).negate());
                }
                f.ntt();
                for (int j = 0; j < 2 * d; j++) f.set(j, f.get(j).multiply(g.get(j)));
                f.intt();
                for (int j = 0; j < d; j++) f.set(j, ret.get(j));
                ret = f;
            }
            return ret.pre(deg);
        }

        private FormalPowerSeries log(int deg) {
            assert get(0).equals(new ModInt(1));
            int n = size();
            if (deg == -1) deg = n;
            FormalPowerSeries ret = new FormalPowerSeries(n);
            for (int i = 1; i < n; i++) ret.set(i - 1, get(i).multiply(new ModInt(i)).inverse());
            ret = ret.integral();
            ret.resize(n - 1);
            return ret;
        }

        private FormalPowerSeries sqrt(int deg) {
            int n = size();
            if (deg == -1) deg = n;
            if (get(0).equals(new ModInt(0))) {
                for (int i = 1; i < n; i++) {
                    if (get(i).notEquals(new ModInt(0))) {
                        if ((i & 1) == 1) return new FormalPowerSeries();
                        if (deg - i / 2 <= 0) break;
                        FormalPowerSeries ret = shiftRight(i).sqrt(deg - i / 2);
                        if (ret.isEmpty()) return ret;
                        ret = ret.shiftLeft(i / 2);
                        if (ret.size() < deg) ret.resize(deg, new ModInt(0));
                        return ret;
                    }
                }
                return new FormalPowerSeries(deg, new ModInt(0));
            }

            FormalPowerSeries ret;
            if (get(0).equals(new ModInt(1))) {
                ret = new FormalPowerSeries(1);
                ret.set(0, new ModInt(1));
            } else {
                ModInt sqr = get(0).sqrt();
                if (sqr.multiply(sqr).notEquals(get(0))) return new FormalPowerSeries();
                ret = new FormalPowerSeries(1);
                ret.set(0, sqr);
            }

            ModInt inv2 = new ModInt(1).divide(new ModInt(2));
            for (int i = 1; i < deg; i <<= 1) {
                ret = ret.add(pre(i << 1).multiply(ret.inverse(i << 1))).multiply(inv2);
            }
            return ret.pre(deg);
        }

        private FormalPowerSeries exp(int deg) {
            assert get(0).equals(new ModInt(0));
            int n = size();
            if (deg == -1) deg = n;
            FormalPowerSeries ret = new FormalPowerSeries(1);
            ret.set(0, new ModInt(1));
            for (int i = 1; i < deg; i <<= 1) {
                ret = ret.multiply(pre(i << 1).add(new ModInt(1)).subtract(ret.log(i << 1))).pre(i << 1);
            }
            return ret.pre(deg);
        }

        private FormalPowerSeries powMod(long n, FormalPowerSeries mod, int deg) {
            FormalPowerSeries modinv = mod.reverse().inverse();
            FormalPowerSeries getDiv = new FormalPowerSeries();
            getDiv.clear();
            if (size() >= mod.size()) {
                int n2 = size() - mod.size() + 1;
                getDiv = (reverse().pre(n2).multiply(modinv.pre(n2))).pre(n2).reverse(n2);
            }
            FormalPowerSeries x = new FormalPowerSeries(this);
            FormalPowerSeries ret = new FormalPowerSeries(1);
            ret.set(0, new ModInt(1));
            while (n > 0) {
                if ((n & 1) == 1) {
                    ret = ret.multiply(x);
                    ret = ret.subtract(getDiv.multiply(mod));
                }
                x = x.multiply(x);
                x = x.subtract(getDiv.multiply(mod));
                n >>= 1;
            }
            return ret;
        }
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }
        h = Arrays.copyOf(h, n + 1);
        h[n] = h[0];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] == h[i + 1]) cnt++;
        }
        int d = n - cnt;

        ModInt res = new ModInt(k).power(cnt);
        ModInt sum = new ModInt(0);

        FormalPowerSeries f = new FormalPowerSeries(2 * d + 1);
        f.set(0, new ModInt(1));
        f.set(1, new ModInt(k - 2));
        f.set(2, new ModInt(1));
        f = f.pow(d);
        for (int i = d + 1; i <= 2 * d; i++) {
            sum = sum.add(f.get(i));
        }

        System.out.println(res.multiply(sum));
    }

    public static void main(String[] args) {
        solve();
    }
}
