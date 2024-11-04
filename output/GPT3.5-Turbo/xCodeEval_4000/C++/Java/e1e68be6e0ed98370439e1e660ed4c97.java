import java.util.Scanner;

public class e1e68be6e0ed98370439e1e660ed4c97_nc {
    
    static final int mod = 998244353;
    
    static class ModInt {
        
        int x;
        
        ModInt() {
            x = 0;
        }
        
        ModInt(int y) {
            x = y;
        }
        
        ModInt(ModInt o) {
            this.x = o.x;
        }
        
        static ModInt raw(int x) {
            return new ModInt(x);
        }
        
        static ModInt get(long long x) {
            return new ModInt((int)((mod + x % mod) % mod));
        }
        
        ModInt assign(int o) {
            this.x = o >= mod ? o - mod : o;
            return this;
        }
        
        ModInt assign(long long o) {
            this.x = (int)((mod + o % mod) % mod);
            return this;
        }
        
        ModInt assign(ModInt o) {
            this.x = o.x;
            return this;
        }
        
        int getValue() {
            return x;
        }
        
        ModInt add(ModInt o) {
            long long res = (long long)x + o.x;
            return ModInt.raw(res >= mod ? res - mod : res);
        }
        
        ModInt multiply(ModInt o) {
            return ModInt.raw((long long)x * o.x % mod);
        }
        
        ModInt pow(long long x) {
            ModInt ret = ModInt.raw(1);
            ModInt a = new ModInt(this);
            while (x > 0) {
                if ((x & 1) == 1) {
                    ret = ret.multiply(a);
                }
                a = a.multiply(a);
                x >>= 1;
            }
            return ret;
        }
        
        ModInt inverse() {
            long long a = x, b = mod, u = 1, v = 0;
            while (b > 0) {
                long long t = a / b;
                long long temp = a - t * b;
                a = b;
                b = temp;
                temp = u - t * v;
                u = v;
                v = temp;
            }
            return ModInt.get(u);
        }
        
        ModInt negate() {
            return ModInt.raw(mod - x);
        }
        
        ModInt subtract(ModInt o) {
            return this.add(o.negate());
        }
        
        ModInt divide(ModInt o) {
            return this.multiply(o.inverse());
        }
        
        ModInt add(int o) {
            return this.add(ModInt.raw(o));
        }
        
        ModInt add(long long o) {
            return this.add(ModInt.get(o));
        }
        
        ModInt multiply(int o) {
            return this.multiply(ModInt.raw(o));
        }
        
        ModInt multiply(long long o) {
            return this.multiply(ModInt.get(o));
        }
        
        ModInt subtract(int o) {
            return this.subtract(ModInt.raw(o));
        }
        
        ModInt subtract(long long o) {
            return this.subtract(ModInt.get(o));
        }
        
        ModInt divide(int o) {
            return this.divide(ModInt.raw(o));
        }
        
        ModInt divide(long long o) {
            return this.divide(ModInt.get(o));
        }
        
        ModInt power(long long x) {
            return this.pow(x);
        }
        
        ModInt addAssign(ModInt o) {
            return this.assign(this.add(o));
        }
        
        ModInt subtractAssign(ModInt o) {
            return this.assign(this.subtract(o));
        }
        
        ModInt multiplyAssign(ModInt o) {
            return this.assign(this.multiply(o));
        }
        
        ModInt divideAssign(ModInt o) {
            return this.assign(this.divide(o));
        }
        
        ModInt addAssign(int o) {
            return this.assign(this.add(o));
        }
        
        ModInt addAssign(long long o) {
            return this.assign(this.add(o));
        }
        
        ModInt subtractAssign(int o) {
            return this.assign(this.subtract(o));
        }
        
        ModInt subtractAssign(long long o) {
            return this.assign(this.subtract(o));
        }
        
        ModInt multiplyAssign(int o) {
            return this.assign(this.multiply(o));
        }
        
        ModInt multiplyAssign(long long o) {
            return this.assign(this.multiply(o));
        }
        
        ModInt divideAssign(int o) {
            return this.assign(this.divide(o));
        }
        
        ModInt divideAssign(long long o) {
            return this.assign(this.divide(o));
        }
        
        boolean equals(ModInt o) {
            return this.x == o.x;
        }
        
        boolean notEquals(ModInt o) {
            return this.x != o.x;
        }
        
        boolean lessThan(ModInt o) {
            return this.x < o.x;
        }
        
        boolean lessThanOrEquals(ModInt o) {
            return this.x <= o.x;
        }
        
        boolean greaterThan(ModInt o) {
            return this.x > o.x;
        }
        
        boolean greaterThanOrEquals(ModInt o) {
            return this.x >= o.x;
        }
        
        boolean equals(int o) {
            return this.x == o;
        }
        
        boolean notEquals(int o) {
            return this.x != o;
        }
        
        boolean lessThan(int o) {
            return this.x < o;
        }
        
        boolean lessThanOrEquals(int o) {
            return this.x <= o;
        }
        
        boolean greaterThan(int o) {
            return this.x > o;
        }
        
        boolean greaterThanOrEquals(int o) {
            return this.x >= o;
        }
        
        boolean equals(long long o) {
            return this.x == o;
        }
        
        boolean notEquals(long long o) {
            return this.x != o;
        }
        
        boolean lessThan(long long o) {
            return this.x < o;
        }
        
        boolean lessThanOrEquals(long long o) {
            return this.x <= o;
        }
        
        boolean greaterThan(long long o) {
            return this.x > o;
        }
        
        boolean greaterThanOrEquals(long long o) {
            return this.x >= o;
        }
    }
    
    static ModInt add(ModInt l, ModInt r) {
        return l.add(r);
    }
    
    static ModInt multiply(ModInt l, ModInt r) {
        return l.multiply(r);
    }
    
    static ModInt pow(ModInt a, long long x) {
        return a.pow(x);
    }
    
    static ModInt inv(ModInt x) {
        return x.inverse();
    }
    
    static ModInt subtract(ModInt l, ModInt r) {
        return l.subtract(r);
    }
    
    static ModInt divide(ModInt l, ModInt r) {
        return l.divide(r);
    }
    
    static ModInt add(ModInt l, int r) {
        return l.add(r);
    }
    
    static ModInt add(ModInt l, long long r) {
        return l.add(r);
    }
    
    static ModInt multiply(ModInt l, int r) {
        return l.multiply(r);
    }
    
    static ModInt multiply(ModInt l, long long r) {
        return l.multiply(r);
    }
    
    static ModInt subtract(ModInt l, int r) {
        return l.subtract(r);
    }
    
    static ModInt subtract(ModInt l, long long r) {
        return l.subtract(r);
    }
    
    static ModInt divide(ModInt l, int r) {
        return l.divide(r);
    }
    
    static ModInt divide(ModInt l, long long r) {
        return l.divide(r);
    }
    
    static ModInt power(ModInt l, long long x) {
        return l.pow(x);
    }
    
    static ModInt addAssign(ModInt l, ModInt r) {
        return l.addAssign(r);
    }
    
    static ModInt subtractAssign(ModInt l, ModInt r) {
        return l.subtractAssign(r);
    }
    
    static ModInt multiplyAssign(ModInt l, ModInt r) {
        return l.multiplyAssign(r);
    }
    
    static ModInt divideAssign(ModInt l, ModInt r) {
        return l.divideAssign(r);
    }
    
    static ModInt addAssign(ModInt l, int r) {
        return l.addAssign(r);
    }
    
    static ModInt addAssign(ModInt l, long long r) {
        return l.addAssign(r);
    }
    
    static ModInt subtractAssign(ModInt l, int r) {
        return l.subtractAssign(r);
    }
    
    static ModInt subtractAssign(ModInt l, long long r) {
        return l.subtractAssign(r);
    }
    
    static ModInt multiplyAssign(ModInt l, int r) {
        return l.multiplyAssign(r);
    }
    
    static ModInt multiplyAssign(ModInt l, long long r) {
        return l.multiplyAssign(r);
    }
    
    static ModInt divideAssign(ModInt l, int r) {
        return l.divideAssign(r);
    }
    
    static ModInt divideAssign(ModInt l, long long r) {
        return l.divideAssign(r);
    }
    
    static boolean equals(ModInt l, ModInt r) {
        return l.equals(r);
    }
    
    static boolean notEquals(ModInt l, ModInt r) {
        return l.notEquals(r);
    }
    
    static boolean lessThan(ModInt l, ModInt r) {
        return l.lessThan(r);
    }
    
    static boolean lessThanOrEquals(ModInt l, ModInt r) {
        return l.lessThanOrEquals(r);
    }
    
    static boolean greaterThan(ModInt l, ModInt r) {
        return l.greaterThan(r);
    }
    
    static boolean greaterThanOrEquals(ModInt l, ModInt r) {
        return l.greaterThanOrEquals(r);
    }
    
    static boolean equals(ModInt l, int r) {
        return l.equals(r);
    }
    
    static boolean notEquals(ModInt l, int r) {
        return l.notEquals(r);
    }
    
    static boolean lessThan(ModInt l, int r) {
        return l.lessThan(r);
    }
    
    static boolean lessThanOrEquals(ModInt l, int r) {
        return l.lessThanOrEquals(r);
    }
    
    static boolean greaterThan(ModInt l, int r) {
        return l.greaterThan(r);
    }
    
    static boolean greaterThanOrEquals(ModInt l, int r) {
        return l.greaterThanOrEquals(r);
    }
    
    static boolean equals(ModInt l, long long r) {
        return l.equals(r);
    }
    
    static boolean notEquals(ModInt l, long long r) {
        return l.notEquals(r);
    }
    
    static boolean lessThan(ModInt l, long long r) {
        return l.lessThan(r);
    }
    
    static boolean lessThanOrEquals(ModInt l, long long r) {
        return l.lessThanOrEquals(r);
    }
    
    static boolean greaterThan(ModInt l, long long r) {
        return l.greaterThan(r);
    }
    
    static boolean greaterThanOrEquals(ModInt l, long long r) {
        return l.greaterThanOrEquals(r);
    }
    
    static class Factorial {
        
        static final int size = 3123456;
        static boolean isBuild = false;
        static ModInt[] factorial = new ModInt[size];
        static ModInt[] inverseFactorial = new ModInt[size];
        
        static void build() {
            isBuild = true;
            factorial[0] = ModInt.raw(1);
            for (int i = 1; i < size; i++) {
                factorial[i] = factorial[i - 1].multiply(i);
            }
            inverseFactorial[size - 1] = factorial[size - 1].inverse();
            for (int i = size - 1; i >= 1; i--) {
                inverseFactorial[i - 1] = inverseFactorial[i].multiply(i);
            }
        }
        
        static ModInt permutation(int n, int k) {
            if (k < 0 || k > n) return ModInt.raw(0);
            if (!isBuild) build();
            return factorial[n].multiply(inverseFactorial[n - k]);
        }
        
        static ModInt combination(int n, int k) {
            if (k < 0 || k > n) return ModInt.raw(0);
            if (!isBuild) build();
            return factorial[n].multiply(inverseFactorial[k]).multiply(inverseFactorial[n - k]);
        }
    }
    
    static ModInt multiChoose(int n, int r) {
        if (n == 0) {
            return ModInt.raw(r == 0 ? 1 : 0);
        }
        if (r == 0) {
            return ModInt.raw(1);
        }
        return Factorial.combination(n + r - 1, r);
    }
    
    static ModInt multiChoose(int n, int r, int lim) {
        if (n == 0) {
            return ModInt.raw(r == 0 ? 1 : 0);
        }
        if (lim <= 0 && r > 0) {
            return ModInt.raw(0);
        }
        if (r == 0) {
            return ModInt.raw(lim < 0 ? 0 : 1);
        }
        ModInt ret = ModInt.raw(0);
        for (int i = 0; i <= n; i++) {
            if (i * (lim + 1) > r) break;
            ret = ret.add(((i & 1) == 1 ? mod - 1 : 1).multiply(Factorial.combination(n, i))
                          .multiply(multiChoose(n, r - i * (lim + 1))));
        }
        return ret;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int p = sc.nextInt();
        int s = sc.nextInt();
        int r = sc.nextInt();
        ModInt ret = ModInt.raw(0);
        for (int top = r; top <= s; top++) {
            ModInt tot = ModInt.raw(0);
            for (int q = 0; q < p; q++) {
                if (top * q > s - top) break;
                tot = tot.add(Factorial.combination(p - 1, q)
                                  .multiply(Factorial.multiChoose(p - q - 1, s - top - top * q, top - 1))
                                  .multiply(inv(q + 1)));
            }
            ret = ret.add(tot);
        }
        ret = ret.multiply(inv(Factorial.multiChoose(p, s - r)));
        System.out.println(ret.getValue());
        
        sc.close();
    }
}
