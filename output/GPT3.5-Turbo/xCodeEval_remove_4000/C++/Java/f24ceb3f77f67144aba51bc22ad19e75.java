import java.io.*;
import java.util.*;

class BVerkhnyayaYacheika {
    static int mod = 1000000007;

    static class ModInt {
        int n;

        ModInt(int n) {
            if (n >= 0 && n < mod) {
                this.n = n;
            } else {
                this.n = n % mod;
                if (this.n < 0) {
                    this.n += mod;
                }
            }
        }

        ModInt add(ModInt other) {
            n += other.n;
            if (n >= mod) {
                n -= mod;
            }
            return this;
        }

        ModInt subtract(ModInt other) {
            n -= other.n;
            if (n < 0) {
                n += mod;
            }
            return this;
        }

        ModInt multiply(ModInt other) {
            n = (int) ((long) n * other.n % mod);
            return this;
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt inverse() {
            long x = n;
            long y = mod;
            long a = 0;
            long b = 1;
            while (x != 0) {
                long q = y / x;
                long t = x;
                x = y % x;
                y = t;
                t = a;
                a = b - q * a;
                b = t;
            }
            if (y == 1) {
                return new ModInt((int) b);
            }
            throw new IllegalStateException();
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof ModInt) {
                ModInt other = (ModInt) obj;
                return n == other.n;
            }
            return false;
        }

        @Override
        public int hashCode() {
            return n;
        }

        @Override
        public String toString() {
            return String.valueOf(n);
        }
    }

    static ModInt[] ft;

    static ModInt get(int to) {
        if (to < 0) {
            return new ModInt(0);
        }
        ModInt result = new ModInt(0);
        while (to >= 0) {
            result = result.add(ft[to]);
            to = (to & (to + 1)) - 1;
        }
        return result;
    }

    static void add(int at, ModInt v) {
        while (at < ft.length) {
            ft[at] = ft[at].add(v);
            at |= at + 1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));

        int n = Integer.parseInt(in.readLine());
        int m = Integer.parseInt(in.readLine());

        ft = new ModInt[n + 1];
        for (int i = 0; i <= n; i++) {
            ft[i] = new ModInt(0);
        }
        ft[n] = new ModInt(1);
        for (int i = n - 1; i >= 1; i--) {
            ModInt res = get(i + 1);
            for (int z = 2; z * i <= n; z++) {
                res = res.add(get(z * i).subtract(get(z * i + z)));
            }
            add(i, res);
        }
        out.println(get(1).subtract(get(2)));

        in.close();
        out.close();
    }
}
