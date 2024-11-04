import java.util.*;
import java.io.*;

class ModInt {
    private int x;
    private static int mod;

    public ModInt() {
        x = 0;
    }

    public ModInt(int y) {
        x = y;
    }

    public ModInt(long y) {
        x = (int) ((mod + y % mod) % mod);
    }

    public static void setMod(int m) {
        mod = m;
    }

    public long value() {
        return x;
    }

    public ModInt add(ModInt r) {
        long sum = this.value() + r.value();
        return new ModInt(sum >= mod ? sum - mod : sum);
    }

    public ModInt multiply(ModInt r) {
        return new ModInt((this.value() * r.value()) % mod);
    }

    public ModInt pow(long exp) {
        ModInt ret = new ModInt(1);
        ModInt base = this;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                ret = ret.multiply(base);
            }
            base = base.multiply(base);
            exp >>= 1;
        }
        return ret;
    }

    public ModInt inv() {
        long a = this.value(), b = mod, u = 1, v = 0;
        while (b > 0) {
            long t = a / b;
            long temp = a; a = b; b = temp - t * b;
            temp = u; u = v; v = temp - t * v;
        }
        return new ModInt(u);
    }

    public ModInt subtract(ModInt r) {
        return this.add(new ModInt(mod - r.value()));
    }

    public ModInt divide(ModInt r) {
        return this.multiply(r.inv());
    }

    public static ModInt combination(int n, int k) {
        if (k < 0 || k > n) return new ModInt(0);
        return factorial[n].multiply(inverseFactorial[k]).multiply(inverseFactorial[n - k]);
    }

    private static ModInt[] factorial = new ModInt[3123456];
    private static ModInt[] inverseFactorial = new ModInt[3123456];
    private static boolean isBuilt = false;

    public static void build() {
        isBuilt = true;
        factorial[0] = new ModInt(1);
        for (int i = 1; i < factorial.length; i++) {
            factorial[i] = factorial[i - 1].multiply(new ModInt(i));
        }
        inverseFactorial[factorial.length - 1] = factorial[factorial.length - 1].inv();
        for (int i = factorial.length - 1; i >= 1; i--) {
            inverseFactorial[i - 1] = inverseFactorial[i].multiply(new ModInt(i));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int p = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        ModInt.setMod(1000000007); // Set your mod value here
        if (!isBuilt) build();

        ModInt ret = new ModInt(0);
        for (int top = r; top <= s; top++) {
            ModInt tot = new ModInt(0);
            for (int q = 0; q < p; q++) {
                if (top * q > s - top) break;
                tot = tot.add(factorial[p - 1].divide(factorial[q]).multiply(multiChoose(p - q - 1, s - top - top * q, top - 1)).divide(new ModInt(q + 1)));
            }
            ret = ret.add(tot);
        }
        ret = ret.multiply(inv(multiChoose(p, s - r)));
        System.out.println(ret.value());
    }

    public static ModInt multiChoose(int n, int r, int lim) {
        if (n == 0) {
            return new ModInt(r == 0 ? 1 : 0);
        }
        if (lim <= 0 && r > 0) {
            return new ModInt(0);
        }
        if (r == 0) {
            return new ModInt(lim < 0 ? 0 : 1);
        }
        ModInt ret = new ModInt(0);
        for (int i = 0; i <= n; i++) {
            if (i * (lim + 1) > r) break;
            ret = ret.add(((i & 1) == 1 ? mod - 1 : 1) * combination(n, i).multiply(multiChoose(n, r - i * (lim + 1)));
        }
        return ret;
    }
}
