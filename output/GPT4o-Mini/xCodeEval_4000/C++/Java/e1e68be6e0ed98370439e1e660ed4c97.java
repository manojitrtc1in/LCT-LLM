import java.util.*;
import java.util.function.Function;

public class e1e68be6e0ed98370439e1e660ed4c97_nc {
    static final int DECIMAL_DIGITS = 10;
    static final int STATIC_MOD = 998244353;
    static int mod = STATIC_MOD;

    static class ModInt {
        private int x;

        public ModInt() {
            x = 0;
        }

        public ModInt(int y) {
            x = y;
        }

        public ModInt(long y) {
            x = (int) ((mod + y % mod) % mod);
        }

        public long value() {
            return x;
        }

        public static ModInt raw(long x) {
            return new ModInt((int) x);
        }

        public static ModInt get(long x) {
            return new ModInt(x);
        }

        public ModInt assign(int o) {
            this.x = o >= mod ? o - mod : o;
            return this;
        }

        public ModInt assign(long o) {
            this.x = (int) ((mod + o % mod) % mod);
            return this;
        }

        public ModInt assign(ModInt o) {
            this.x = o.value();
            return this;
        }

        public static ModInt add(ModInt l, ModInt r) {
            long x = l.value() + r.value();
            return ModInt.raw(x >= mod ? x - mod : x);
        }

        public static ModInt mul(ModInt l, ModInt r) {
            return ModInt.raw(l.value() * r.value() % mod);
        }

        public static ModInt pow(ModInt a, long x) {
            ModInt ret = ModInt.raw(1);
            while (x > 0) {
                if ((x & 1) == 1) {
                    ret = mul(ret, a);
                }
                a = mul(a, a);
                x >>= 1;
            }
            return ret;
        }

        public static ModInt inv(ModInt x) {
            long a = x.value(), b = mod, u = 1, v = 0;
            while (b > 0) {
                long t = a / b;
                a -= t * b;
                long temp = b;
                b = a;
                a = temp;
                u -= t * v;
                temp = v;
                v = u;
                u = temp;
            }
            return ModInt.get(u);
        }

        public static ModInt operatorMinus(ModInt x) {
            return add(mod, -x);
        }

        public static ModInt operatorPlus(ModInt l, ModInt r) {
            return add(l, r);
        }

        public static ModInt operatorMinus(ModInt l, ModInt r) {
            return add(l, operatorMinus(r));
        }

        public static ModInt operatorPlus(ModInt l, int r) {
            return add(l, ModInt.raw(r));
        }

        public static ModInt operatorPlus(ModInt l, long r) {
            return add(l, ModInt.get(r));
        }

        public static ModInt operatorMinus(ModInt l, int r) {
            return add(l, ModInt.raw(mod - r));
        }

        public static ModInt operatorMinus(ModInt l, long r) {
            return add(l, -ModInt.get(r));
        }

        public static ModInt operatorDiv(ModInt l, int r) {
            return mul(l, inv(ModInt.raw(r)));
        }

        public static ModInt operatorDiv(ModInt l, long r) {
            return mul(l, inv(ModInt.get(r)));
        }

        public static ModInt operatorPow(ModInt l, long r) {
            return pow(l, r);
        }
    }

    static class Factorial {
        static final int size = 3123456;
        static boolean isBuild = false;
        static ModInt[] factorial = new ModInt[size];
        static ModInt[] inverseFactorial = new ModInt[size];

        static void build() {
            isBuild = true;
            factorial[0] = new ModInt(1);
            for (int i = 1; i < size; i++) {
                factorial[i] = ModInt.mul(factorial[i - 1], new ModInt(i));
            }
            inverseFactorial[size - 1] = ModInt.inv(factorial[size - 1]);
            for (int i = size - 1; i >= 1; i--) {
                inverseFactorial[i - 1] = ModInt.mul(inverseFactorial[i], new ModInt(i));
            }
        }

        public static ModInt combination(int n, int k) {
            if (k < 0 || k > n) return ModInt.raw(0);
            if (!isBuild) build();
            return ModInt.mul(factorial[n], ModInt.mul(inverseFactorial[k], inverseFactorial[n - k]));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int p = scanner.nextInt();
        int s = scanner.nextInt();
        int r = scanner.nextInt();
        ModInt ret = new ModInt(0);
        for (int top = r; top <= s; top++) {
            ModInt tot = new ModInt(0);
            for (int q = 0; q < p; q++) {
                if (top * q > s - top) break;
                tot = ModInt.add(tot,
                        ModInt.mul(Factorial.combination(p - 1, q),
                                ModInt.mul(Factorial.multiChoose(p - q - 1, s - top - top * q, top - 1),
                                        ModInt.inv(q + 1))));
            }
            ret = ModInt.add(ret, tot);
        }
        ret = ModInt.mul(ret, ModInt.inv(Factorial.multiChoose(p, s - r)));
        System.out.println(ret.value());
    }
}
