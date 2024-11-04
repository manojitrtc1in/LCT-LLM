import java.util.Scanner;

class Barrett {
    private final int m;
    private final long im;

    public Barrett(int m) {
        this.m = m;
        this.im = (long) (-1) / m + 1;
    }

    public int umod() {
        return m;
    }

    public int mul(int a, int b) {
        long z = (long) a * b;
        long x = (z * im) >> 64;
        int v = (int) (z - x * m);
        if (m <= v) v += m;
        return v;
    }
}

class Mint {
    private static Barrett bt;
    private int v;

    public static void setMod(int m) {
        bt = new Barrett(m);
    }

    public Mint() {
        this.v = 0;
    }

    public Mint(int v) {
        long x = (long) (v % bt.umod());
        if (x < 0) x += bt.umod();
        this.v = (int) x;
    }

    public int val() {
        return v;
    }

    public Mint add(Mint rhs) {
        v += rhs.v;
        if (v >= bt.umod()) v -= bt.umod();
        return this;
    }

    public Mint multiply(Mint rhs) {
        v = bt.mul(v, rhs.v);
        return this;
    }

    public Mint pow(long n) {
        Mint x = this, r = new Mint(1);
        while (n > 0) {
            if ((n & 1) == 1) r = r.multiply(x);
            x = x.multiply(x);
            n >>= 1;
        }
        return r;
    }

    public Mint inv() {
        // Implementing the extended Euclidean algorithm for modular inverse
        long a = v, m = bt.umod();
        long m0 = m, t, q;
        long x0 = 0, x1 = 1;

        if (m == 1) return new Mint(0);

        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) x1 += m0;

        return new Mint((int) x1);
    }
}

class TaskB {
    public void solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        Mint.setMod(m);
        Mint[] ways = new Mint[n + 1];
        Mint[] extras = new Mint[n + 1];
        ways[1] = new Mint(1);
        Mint sum = new Mint(0);
        Mint extra = new Mint(0);
        
        for (int i = 1; i <= n; i++) {
            ways[i] = ways[i] != null ? ways[i].add(sum) : new Mint(sum.val());
            extra = extra.add(extras[i]);
            ways[i] = ways[i].add(extra);
            for (int j = 2; i * j <= n; j++) {
                extras[i * j] = extras[i * j] != null ? extras[i * j].add(ways[i]) : new Mint(ways[i].val());
                if ((i + 1) * j <= n)
                    extras[(i + 1) * j] = extras[(i + 1) * j] != null ? extras[(i + 1) * j].add(new Mint(-ways[i].val())) : new Mint(-ways[i].val());
            }
            sum = sum.add(ways[i]);
        }
        System.out.println(ways[n].val());
    }
}

public class 3eb9ab143a8e16fac581e45e0eed8523xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        TaskB solver = new TaskB();
        Scanner in = new Scanner(System.in);
        solver.solve(in);
        in.close();
    }
}
