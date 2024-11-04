import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;

    static class ModInt {
        private int x;

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
            x = (int) ((long) x * rhs.x % MOD);
            return this;
        }

        public ModInt divide(ModInt rhs) {
            x = (int) ((long) x * rhs.inv().x % MOD);
            return this;
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
            ModInt ret = new ModInt(1), mul = new ModInt(x);
            while (n > 0) {
                if ((n & 1) == 1) ret.multiply(mul);
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        @Override
        public String toString() {
            return String.valueOf(x);
        }
    }

    static class FormalPowerSeries extends ArrayList<ModInt> {
        public FormalPowerSeries(int size) {
            super(size);
            for (int i = 0; i < size; i++) {
                this.add(new ModInt());
            }
        }

        public FormalPowerSeries multiply(FormalPowerSeries b) {
            int n = this.size() + b.size() - 1;
            int sz = 1;
            while (sz < n) sz <<= 1;
            FormalPowerSeries a = new FormalPowerSeries(sz);
            for (int i = 0; i < this.size(); i++) a.set(i, this.get(i));
            FormalPowerSeries result = new FormalPowerSeries(sz);
            for (int i = 0; i < b.size(); i++) result.set(i, b.get(i));

            // NTT or FFT multiplication can be implemented here
            // For simplicity, we will use naive multiplication
            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < result.size(); j++) {
                    if (i + j < n) {
                        a.set(i + j, a.get(i + j).add(a.get(i).multiply(result.get(j))));
                    }
                }
            }
            return a;
        }

        public FormalPowerSeries pow(int exp) {
            FormalPowerSeries ret = new FormalPowerSeries(1);
            ret.set(0, new ModInt(1));
            for (int i = 0; i < exp; i++) {
                ret = ret.multiply(this);
            }
            return ret;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> h = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            h.add(sc.nextInt());
        }
        h.add(h.get(0));

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (h.get(i).equals(h.get(i + 1))) cnt++;
        }
        int d = n - cnt;

        ModInt res = new ModInt((long) Math.pow(k, cnt));
        ModInt sum = new ModInt(0);

        FormalPowerSeries f = new FormalPowerSeries(2 * d + 1);
        f.set(0, new ModInt(1));
        f.set(1, new ModInt(k - 2));
        f.set(2, new ModInt(1));
        f = f.pow(d);
        for (int i = d + 1; i <= 2 * d; i++) {
            sum.add(f.get(i));
        }

        System.out.println(res.multiply(sum));
    }
}
