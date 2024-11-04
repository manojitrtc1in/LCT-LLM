import java.util.Scanner;

public class e1e68be6e0ed98370439e1e660ed4c97xcodeeval_processed_4000.json {
    
    static final int mod = STATIC_MOD;
    
    static int mod;
    
    static class ModInt {
        
        private int x;
        
        public long getX() {
            return x;
        }
        
        public ModInt() {
            x = 0;
        }
        
        public ModInt(int y) {
            x = y;
        }
        
        public ModInt(long y) {
            x = (int)((mod + y % mod) % mod);
        }
        
        public ModInt(ModInt o) {
            this.x = o.getX();
        }
        
        public static ModInt raw(long x) {
            return new ModInt((int)x);
        }
        
        public static ModInt get(long x) {
            return new ModInt(x);
        }
        
        public ModInt assign(int o) {
            this.x = o >= mod ? o - mod : o;
            return this;
        }
        
        public ModInt assign(long o) {
            this.x = (int)((mod + o % mod) % mod);
            return this;
        }
        
        public ModInt assign(ModInt o) {
            this.x = o.getX();
            return this;
        }
        
        public ModInt add(ModInt r) {
            long res = this.x + r.getX();
            return ModInt.raw(res >= mod ? res - mod : res);
        }
        
        public ModInt multiply(ModInt r) {
            return ModInt.raw(this.x * r.getX() % mod);
        }
        
        public ModInt pow(long x) {
            ModInt ret = ModInt.raw(1);
            ModInt a = this;
            while (x > 0) {
                if ((x & 1) == 1) {
                    ret = ret.multiply(a);
                }
                a = a.multiply(a);
                x >>= 1;
            }
            return ret;
        }
        
        public ModInt inverse() {
            long a = this.x, b = mod, u = 1, v = 0;
            while (b != 0) {
                long t = a / b;
                long temp = a - t * b;
                a = b;
                b = temp;
                temp = u - t * v;
                u = v;
                v = temp;
            }
            return ModInt.get(u);
        }
        
        public ModInt negate() {
            return ModInt.raw(mod - this.x);
        }
        
        public ModInt subtract(ModInt r) {
            return this.add(r.negate());
        }
        
        public ModInt add(int r) {
            return this.add(ModInt.raw(r));
        }
        
        public ModInt add(long r) {
            return this.add(ModInt.get(r));
        }
        
        public ModInt multiply(int r) {
            return this.multiply(ModInt.raw(r));
        }
        
        public ModInt multiply(long r) {
            return this.multiply(ModInt.get(r));
        }
        
        public ModInt subtract(int r) {
            return this.add(ModInt.raw(mod - r));
        }
        
        public ModInt subtract(long r) {
            return this.add(ModInt.get(-r));
        }
        
        public ModInt divide(int r) {
            return this.multiply(ModInt.raw(r).inverse());
        }
        
        public ModInt divide(long r) {
            return this.multiply(ModInt.get(r).inverse());
        }
        
        public ModInt power(long r) {
            return this.pow(r);
        }
        
        @Override
        public String toString() {
            return String.valueOf(x);
        }
    }
    
    static class Factorial {
        
        static final int size = 3123456;
        
        static boolean isBuild = false;
        
        static ModInt[] factorial = new ModInt[size];
        
        static ModInt[] inverseFactorial = new ModInt[size];
        
        public static void build() {
            isBuild = true;
            factorial[0] = new ModInt(1);
            for (int i = 1; i < size; i++) {
                factorial[i] = factorial[i - 1].multiply(i);
            }
            inverseFactorial[size - 1] = factorial[size - 1].inverse();
            for (int i = size - 1; i >= 1; i--) {
                inverseFactorial[i - 1] = inverseFactorial[i].multiply(i);
            }
        }
        
        public static ModInt permutation(int n, int k) {
            if (k < 0 || k > n) return new ModInt(0);
            if (!isBuild) build();
            return factorial[n].multiply(inverseFactorial[n - k]);
        }
        
        public static ModInt combination(int n, int k) {
            if (k < 0 || k > n) return new ModInt(0);
            if (!isBuild) build();
            return factorial[n].multiply(inverseFactorial[k]).multiply(inverseFactorial[n - k]);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int p, s, r;
        p = sc.nextInt();
        s = sc.nextInt();
        r = sc.nextInt();
        ModInt ret = new ModInt(0);
        for (int top = r; top <= s; top++) {
            ModInt tot = new ModInt(0);
            for (int q = 0; q < p; q++) {
                if (top * q > s - top) break;
                tot = tot.add(Factorial.combination(p - 1, q)
                        .multiply(Factorial.multiChoose(p - q - 1, s - top - top * q, top - 1))
                        .multiply((q + 1).inverse()));
            }
            ret = ret.add(tot);
        }
        ret = ret.multiply(Factorial.multiChoose(p, s - r).inverse());
        System.out.println(ret);
        
        sc.close();
    }
}
