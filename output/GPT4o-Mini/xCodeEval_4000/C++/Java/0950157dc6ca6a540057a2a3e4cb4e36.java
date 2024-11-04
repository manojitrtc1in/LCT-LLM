import java.util.*;
import java.util.stream.*;

class Main {
    static final int MOD = 10007;
    static final int N = 202;
    static Field[][][] dp = new Field[N][N][10 * N];
    static boolean[][][] ok = new boolean[N][N][10 * N];
    static String s;

    static Field go(int left, int right, int i) {
        if (i < 0) return new Field(0);
        if (i == 0 && left >= right) return new Field(1);
        Field res = dp[left][right][i];
        if (ok[left][right][i]) return res;

        res = new Field(0);
        if (left >= right) {
            res = res.add(go(left, right, Math.max(i - 2, 0)).multiply(26));
        } else if (left + 1 == right) {
            if (i == 0) res = res.add(go(left + 1, right - 1, i));
            else res = res.add(go(left + 1, right, i - 1));
            res = res.add(go(left, right, i - 2).multiply(25));
        } else {
            if (s.charAt(left) == s.charAt(right - 1)) {
                res = res.add(go(left + 1, right - 1, i));
                res = res.add(go(left, right, i - 2).multiply(25));
            } else {
                res = res.add(go(left + 1, right, i - 1));
                res = res.add(go(left, right - 1, i - 1));
                res = res.add(go(left, right, i - 2).multiply(24));
            }
        }

        ok[left][right][i] = true;
        dp[left][right][i] = res;
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();
        int n = scanner.nextInt();

        List<Field> base = new ArrayList<>();
        for (int i = 0; i < 10 * s.length(); i++) {
            base.add(go(0, s.length(), i));
        }

        BMSolver<Poly> solver = new BMSolver<>();
        solver.solve(base);
        System.out.println(solver.compute(n));
    }
}

class Field {
    private int value;

    public Field(int value) {
        this.value = value % Main.MOD;
        if (this.value < 0) this.value += Main.MOD;
    }

    public Field add(Field other) {
        return new Field(this.value + other.value);
    }

    public Field multiply(int factor) {
        return new Field(this.value * factor);
    }

    public Field multiply(Field other) {
        return new Field(this.value * other.value);
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }
}

class Poly {
    // Implement Polynomial class as needed
}

class BMSolver<P> {
    private List<Field> base;
    private List<Field> T;

    public void solve(List<Field> container) {
        // Implement the solve method
    }

    public Field compute(long K) {
        // Implement the compute method
        return new Field(0); // Placeholder
    }
}
