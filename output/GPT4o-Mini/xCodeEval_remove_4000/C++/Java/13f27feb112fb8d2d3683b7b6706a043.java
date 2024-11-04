import java.util.*;

class Matrix {
    int[][] d = new int[2][2];

    void init() {
        for (int i = 0; i < 2; i++)
            Arrays.fill(d[i], 0);
    }

    Matrix() {
        init();
    }

    int sum() {
        int res = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                res += d[i][j];
        return res;
    }
}

public class 13f27feb112fb8d2d3683b7b6706a043xcodeeval_processed_4000.json {
    static final int N = 1000009;
    static final int l = 2;

    static Matrix multiply(Matrix a, Matrix b) {
        Matrix c = new Matrix();
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++) {
                long tmp = 0;
                for (int k = 0; k < l; k++)
                    tmp += (long) (a.d[i][k]) * b.d[k][j];
                c.d[i][j] = (int) tmp;
            }
        return c;
    }

    static Matrix pow(Matrix a, int b) {
        Matrix c = new Matrix();
        for (int i = 0; i < l; i++)
            c.d[i][i] = 1;

        while (b > 0) {
            if ((b & 1) == 1)
                c = multiply(c, a);
            a = multiply(a, a);
            b /= 2;
        }
        return c;
    }

    static int solve() {
        int x, y, k = 0, res = 0;
        char ch = (char) System.in.read();
        if (ch == '0') return 1 << 0;
        if (ch == '1') return 1 << 15;
        if (ch == '?') return (1 << 3) | (1 << 12);

        x = solve();
        ch = (char) System.in.read();
        y = solve();

        for (int i = 0; i < 16; i++) {
            if ((~x & (1 << i)) != 0) continue;
            for (int j = 0; j < 16; j++) {
                if ((~y & (1 << j)) != 0) continue;
                if (ch == '^') k = i ^ j;
                if (ch == '&') k = i & j;
                if (ch == '|') k = i | j;
                res |= 1 << k;
            }
        }
        System.in.read(); // Consume newline
        return res;
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println((~0x8241 & solve()) != 0 ? "YES" : "NO");
    }
}
