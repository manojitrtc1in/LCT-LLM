import java.util.Arrays;
import java.util.Scanner;

class FastIO {
    FastIO() {
        Scanner scanner = new Scanner(System.in);
        scanner.useDelimiter("\\n");
    }
}

class Mint {
    int n;
    static final int MOD = 998244353;

    Mint(int n) {
        this.n = n % MOD;
        if (this.n < 0) this.n += MOD;
    }

    Mint() {
        this(0);
    }

    Mint neg() {
        return new Mint(n == 0 ? 0 : MOD - n);
    }

    Mint add(Mint rhs) {
        return new Mint(n + rhs.n);
    }

    Mint sub(Mint rhs) {
        return add(rhs.neg());
    }

    Mint mul(Mint rhs) {
        return new Mint((long) n * rhs.n % MOD);
    }

    Mint inv() {
        return pow(MOD - 2);
    }

    Mint div(Mint rhs) {
        return mul(rhs.inv());
    }

    Mint pow(int exp) {
        Mint result = new Mint(1);
        Mint base = this;
        while (exp > 0) {
            if ((exp & 1) == 1) result = result.mul(base);
            base = base.mul(base);
            exp >>= 1;
        }
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Mint)) return false;
        Mint other = (Mint) obj;
        return n == other.n;
    }

    @Override
    public int hashCode() {
        return n;
    }
}

class Poly {
    Mint[] c;
    static final int MOD = 998244353;
    static final int K = 18;

    Poly(int n) {
        c = new Mint[n + 1];
        Arrays.fill(c, new Mint());
    }

    int deg() {
        return c.length - 1;
    }

    Mint at(int n) {
        if (n < c.length) return c[n];
        return new Mint();
    }

    void add(Poly rhs) {
        if (rhs.deg() > deg()) {
            Mint[] d = Arrays.copyOf(rhs.c, rhs.c.length);
            for (int i = 0; i <= deg(); i++) d[i] = d[i].add(c[i]);
            c = d;
        } else if (rhs.deg() < deg()) {
            for (int i = 0; i <= rhs.deg(); i++) c[i] = c[i].add(rhs.c[i]);
        } else {
            for (int i = 0; i < c.length; i++) c[i] = c[i].add(rhs.c[i]);
        }
    }

    void sub(Poly rhs) {
        if (rhs.deg() > deg()) {
            Mint[] d = Arrays.copyOf(rhs.c, rhs.c.length);
            for (int i = 0; i <= deg(); i++) d[i] = d[i].sub(c[i]);
            c = d;
        } else if (rhs.deg() < deg()) {
            for (int i = 0; i <= rhs.deg(); i++) c[i] = c[i].sub(rhs.c[i]);
        } else {
            for (int i = 0; i < c.length; i++) c[i] = c[i].sub(rhs.c[i]);
        }
    }

    void mul(Poly rhs) {
        if (deg() < 0 || rhs.deg() < 0) {
            c = new Mint[0];
            return;
        }
        int rdeg = deg() + rhs.deg();
        Mint[] d = new Mint[1 << (32 - Integer.numberOfLeadingZeros(rdeg))];
        Arrays.fill(d, new Mint());
        for (int i = 0; i <= deg(); i++) d[i] = c[i];
        for (int i = 0; i <= rhs.deg(); i++) d[i] = d[i].mul(rhs.c[i]);
        c = Arrays.copyOf(d, rdeg + 1);
    }

    Poly log() {
        assert c[0].equals(new Mint(1));
        int n = deg();
        Poly g = new Poly(n - 1);
        for (int i = 0; i < n; i++) g.c[i] = c[i];
        return g;
    }

    Poly exp() {
        assert c[0].equals(new Mint(0));
        Poly r = new Poly(0);
        r.c[0] = new Mint(1);
        return r;
    }

    Mint eval(Mint x) {
        Mint r = new Mint(0);
        for (int i = deg(); i >= 0; i--) {
            r = r.mul(x).add(c[i]);
        }
        return r;
    }
}

public class 1f6c549a9d407c6276f7b0cacba3bb49xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        FastIO io = new FastIO();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] hs = new int[n];
        for (int i = 0; i < n; i++) hs[i] = scanner.nextInt();

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (hs[i] == hs[(i + 1) % n]) cnt++;

        if (cnt == n) {
            System.out.println(0);
            return;
        }

        Poly A = new Poly(200000 + 1000);
        A.c[0] = new Mint(1);
        A.c[1] = new Mint((k - 2) % Mint.MOD);
        A.c[2] = new Mint(1);

        Poly B = A.log();
        for (int i = 0; i < B.c.length; i++)
            B.c[i] = B.c[i].mul(new Mint(n - cnt));

        Poly C = B.exp();

        Mint ans = new Mint(k % Mint.MOD).pow(n - cnt);
        for (int i = 0; i <= n - cnt; i++) ans = ans.sub(C.c[i]);

        ans = ans.mul(new Mint(k % Mint.MOD).pow(cnt);
        System.out.println(ans.n);
    }
}
