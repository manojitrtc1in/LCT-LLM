import java.util.Scanner;

public class 3904956c4f66a53c87a849410a5bc8de_nc {
    static Scanner scanner = new Scanner(System.in);

    static int solve() {
        int x, y, k = 0, res = 0;
        char ch = scanner.next().charAt(0);
        if (ch == '0') return 1 << 0;
        if (ch == '1') return 1 << 15;
        if (ch == '?') return (1 << 3) | (1 << 12);

        x = solve();
        ch = scanner.next().charAt(0);
        y = solve();

        for (int i = 0; i < 16; i++) {
            if (!isBitSet(x, i)) continue;
            for (int j = 0; j < 16; j++) {
                if (!isBitSet(y, j)) continue;
                if (ch == '^') k = i ^ j;
                if (ch == '&') k = i & j;
                if (ch == '|') k = i | j;
                res |= 1 << k;
            }
        }
        return res;
    }

    static boolean isBitSet(int x, int i) {
        return (x & (1 << i)) != 0;
    }

    public static void main(String[] args) {
        int t = scanner.nextInt();
        System.out.println((~0x8421 & solve()) != 0 ? "YES" : "NO");
    }
}
