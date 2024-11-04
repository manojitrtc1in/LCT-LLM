import java.util.*;

class Main {
    static class ModInt {
        static int mod = 0;
        int value;

        public ModInt(int value) {
            this.value = value;
        }

        public static void setMod(int m) {
            mod = m;
        }

        public static ModInt raw(int v) {
            return new ModInt(v);
        }

        public int val() {
            return value;
        }

        public ModInt add(ModInt other) {
            value += other.value;
            if (value >= mod) value -= mod;
            return this;
        }

        public ModInt subtract(ModInt other) {
            value += mod - other.value;
            if (value >= mod) value -= mod;
            return this;
        }

        public ModInt multiply(ModInt other) {
            value = (int) ((long) value * other.value % mod);
            return this;
        }

        public ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        public ModInt increment() {
            value++;
            if (value == mod) value = 0;
            return this;
        }

        public ModInt decrement() {
            if (value == 0) value = mod;
            value--;
            return this;
        }

        public ModInt inverse() {
            long a = value, b = mod, u = 1, v = 0;
            while (b != 0) {
                long t = a / b;
                a -= t * b;
                long tmp1 = a;
                a = b;
                b = tmp1;
                u -= t * v;
                long tmp2 = u;
                u = v;
                v = tmp2;
            }
            if (u < 0) u += mod / a;
            return new ModInt((int) u);
        }

        public ModInt pow(long n) {
            ModInt x = new ModInt(value), r = new ModInt(1);
            while (n > 0) {
                if ((n & 1) == 1) r.multiply(x);
                x.multiply(x);
                n >>= 1;
            }
            return r;
        }

        public static ModInt operatorPlus(ModInt a, ModInt b) {
            return new ModInt(a.value).add(b);
        }

        public static ModInt operatorMinus(ModInt a, ModInt b) {
            return new ModInt(a.value).subtract(b);
        }

        public static ModInt operatorMultiply(ModInt a, ModInt b) {
            return new ModInt(a.value).multiply(b);
        }

        public static ModInt operatorDivide(ModInt a, ModInt b) {
            return new ModInt(a.value).divide(b);
        }

        public static boolean operatorEquals(ModInt a, ModInt b) {
            return a.value == b.value;
        }

        public static boolean operatorNotEquals(ModInt a, ModInt b) {
            return a.value != b.value;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        ModInt.setMod(m);

        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p = new ModInt[n + 1];

        dp[n] = ModInt.raw(1);
        p[n] = ModInt.raw(1);
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i].add(p[i + 1]);

            for (int z = 2; z * i <= n; z++) {
                int r = i * z + z;
                int l = z * i;
                dp[i] = dp[i].add(p[l]);
                if (r <= n) dp[i] = dp[i].subtract(p[r]);
            }

            p[i] = p[i + 1].add(dp[i]);
        }

        System.out.println(dp[1].val());
    }
}
