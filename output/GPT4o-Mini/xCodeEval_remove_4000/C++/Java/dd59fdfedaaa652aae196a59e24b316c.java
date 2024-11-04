import java.util.*;

public class dd59fdfedaaa652aae196a59e24b316cxcodeeval_processed_4000.json {
    static final int MOD = 1000000007;
    static final int INF = 0x3f3f3f3f;

    static int solve() {
        int x, y, k, res = 0;
        char ch = new Scanner(System.in).next().charAt(0);
        if (ch == '0') return 1 << 0;
        if (ch == '1') return 1 << 15;
        if (ch == '?') return (1 << 3) | (1 << 12);

        x = solve();
        ch = new Scanner(System.in).next().charAt(0);
        y = solve();
        new Scanner(System.in).nextLine();

        for (int i = 0; i < 16; i++) {
            if (_1(x, i)) {
                for (int j = 0; j < 16; j++) {
                    if (_1(y, j)) {
                        if (ch == '^') k = i ^ j;
                        if (ch == '&') k = i & j;
                        if (ch == '|') k = i | j;
                        res |= _1(k);
                    }
                }
            }
        }

        return res;
    }

    static boolean _1(int x, int i) {
        return (x & (1 << i)) != 0;
    }

    public static void main(String[] args) {
        new Scanner(System.in).nextInt();
        System.out.println((~0x8421 & solve()) != 0 ? "YES" : "NO");
    }
}