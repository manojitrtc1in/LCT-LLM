import java.util.*;
import java.io.*;

class ModInt {
    private int x;
    private static final int MOD = 998244353;

    public ModInt() {
        this.x = 0;
    }

    public ModInt(long x_) {
        this.x = (int) ((x_ % MOD + MOD) % MOD);
    }

    public int val() {
        return x;
    }

    public ModInt add(ModInt rhs) {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return this;
    }

    public ModInt subtract(ModInt rhs) {
        x -= rhs.x;
        if (x < 0) x += MOD;
        return this;
    }

    public ModInt multiply(ModInt rhs) {
        x = (int) ((1L * x * rhs.x) % MOD);
        return this;
    }

    public ModInt divide(ModInt rhs) {
        return multiply(rhs.inv());
    }

    public ModInt inv() {
        int a = x, b = MOD, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            a -= t * b; 
            int temp = u; 
            u -= t * v; 
            v = temp;
            int temp2 = a; 
            a = b; 
            b = temp2;
        }
        return new ModInt(u);
    }

    public ModInt pow(long n) {
        ModInt ret = new ModInt(1);
        ModInt mul = new ModInt(x);
        while (n > 0) {
            if ((n & 1) == 1) ret = ret.multiply(mul);
            mul = mul.multiply(mul);
            n >>= 1;
        }
        return ret;
    }

    @Override
    public String toString() {
        return String.valueOf(x);
    }
}

class NumberTheoreticTransform {
    private List<ModInt> dw, idw;
    private int maxBase;
    private ModInt root;

    public NumberTheoreticTransform() {
        int mod = 998244353;
        assert mod >= 3 && mod % 2 == 1;
        int tmp = mod - 1;
        maxBase = 0;
        while (tmp % 2 == 0) {
            tmp >>= 1;
            maxBase++;
        }
        root = new ModInt(2);
        while (root.pow((mod - 1) >> 1).val() == 1) {
            root = root.add(new ModInt(1));
        }
        assert root.pow(mod - 1).val() == 1;
        dw = new ArrayList<>(Collections.nCopies(maxBase, new ModInt(0)));
        idw = new ArrayList<>(Collections.nCopies(maxBase, new ModInt(0)));
        for (int i = 0; i < maxBase; i++) {
            dw.set(i, root.pow((mod - 1) >> (i + 2)).multiply(new ModInt(-1)));
            idw.set(i, new ModInt(1).divide(dw.get(i)));
        }
    }

    public void ntt(List<ModInt> a) {
        int n = a.size();
        assert (n & (n - 1)) == 0;
        assert Integer.bitCount(n) <= maxBase;
        for (int m = n; m >>= 1; ) {
            ModInt w = new ModInt(1);
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; i++, j++) {
                    ModInt x = a.get(i), y = a.get(j).multiply(w);
                    a.set(i, x.add(y));
                    a.set(j, x.subtract(y));
                }
                w = w.multiply(dw.get(Integer.numberOfTrailingZeros(++k)));
            }
        }
    }

    public void intt(List<ModInt> a, boolean f) {
        int n = a.size();
        assert (n & (n - 1)) == 0;
        assert Integer.bitCount(n) <= maxBase;
        for (int m = 1; m < n; m *= 2) {
            ModInt w = new ModInt(1);
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; i++, j++) {
                    ModInt x = a.get(i), y = a.get(j);
                    a.set(i, x.add(y));
                    a.set(j, x.subtract(y).multiply(w));
                }
                w = w.multiply(idw.get(Integer.numberOfTrailingZeros(++k)));
            }
        }
        if (f) {
            ModInt invSz = new ModInt(1).divide(new ModInt(n));
            for (int i = 0; i < n; i++) a.set(i, a.get(i).multiply(invSz));
        }
    }

    public List<ModInt> multiply(List<ModInt> a, List<ModInt> b) {
        int need = a.size() + b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need) nbase++;
        int sz = 1 << nbase;
        a.addAll(Collections.nCopies(sz - a.size(), new ModInt(0)));
        b.addAll(Collections.nCopies(sz - b.size(), new ModInt(0)));
        ntt(a);
        ntt(b);
        ModInt invSz = new ModInt(1).divide(new ModInt(sz));
        for (int i = 0; i < sz; i++) a.set(i, a.get(i).multiply(b.get(i)).multiply(invSz));
        intt(a, false);
        a = a.subList(0, need);
        return a;
    }
}

class FormalPowerSeries extends ArrayList<ModInt> {
    public FormalPowerSeries(int size) {
        super(size);
        for (int i = 0; i < size; i++) {
            this.add(new ModInt(0));
        }
    }

    public FormalPowerSeries add(FormalPowerSeries r) {
        FormalPowerSeries result = new FormalPowerSeries(Math.max(this.size(), r.size()));
        for (int i = 0; i < this.size(); i++) {
            result.set(i, result.get(i).add(this.get(i)));
        }
        for (int i = 0; i < r.size(); i++) {
            result.set(i, result.get(i).add(r.get(i)));
        }
        return result;
    }

    public FormalPowerSeries subtract(FormalPowerSeries r) {
        FormalPowerSeries result = new FormalPowerSeries(Math.max(this.size(), r.size()));
        for (int i = 0; i < this.size(); i++) {
            result.set(i, result.get(i).add(this.get(i)));
        }
        for (int i = 0; i < r.size(); i++) {
            result.set(i, result.get(i).subtract(r.get(i)));
        }
        return result;
    }

    public FormalPowerSeries multiply(FormalPowerSeries r) {
        NumberTheoreticTransform ntt = new NumberTheoreticTransform();
        return new FormalPowerSeries(ntt.multiply(this, r));
    }

    public ModInt eval(ModInt x) {
        ModInt r = new ModInt(0);
        ModInt w = new ModInt(1);
        for (ModInt v : this) {
            r = r.add(w.multiply(v));
            w = w.multiply(x);
        }
        return r;
    }
}

public class f99a12495b2728af4769f86cc0d7abf7_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        List<Integer> h = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            h.add(scanner.nextInt());
        }
        h.add(h.get(0));

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (h.get(i).equals(h.get(i + 1))) cnt++;
        }
        int d = n - cnt;

        ModInt res = new ModInt(k).pow(cnt);
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
}
