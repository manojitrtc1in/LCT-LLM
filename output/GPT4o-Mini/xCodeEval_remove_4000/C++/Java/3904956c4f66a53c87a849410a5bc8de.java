import java.util.*;

public class 3904956c4f66a53c87a849410a5bc8dexcodeeval_processed_4000.json {
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
            if (!isBitSet(x, i)) continue;
            for (int j = 0; j < 16; j++) {
                if (!isBitSet(y, j)) continue;
                if (ch == '^') k = i ^ j;
                if (ch == '&') k = i & j;
                if (ch == '|') k = i | j;
                res |= 1 << k;
            }
        }
        System.in.read(); // Consume the newline character
        return res;
    }

    static boolean isBitSet(int x, int i) {
        return (x & (1 << i)) != 0;
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line
        System.out.println((~0x8421 & solve()) != 0 ? "YES" : "NO");
    }
}
