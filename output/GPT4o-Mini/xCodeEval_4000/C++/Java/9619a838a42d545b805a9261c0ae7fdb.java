import java.util.Scanner;

public class 9619a838a42d545b805a9261c0ae7fdb_nc {
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
            if ((~x & (1 << i)) != 0) continue;
            for (int j = 0; j < 16; j++) {
                if ((~y & (1 << j)) != 0) continue;
                if (ch == '^') k = i ^ j;
                if (ch == '&') k = i & j;
                if (ch == '|') k = i | j;
                res |= 1 << k;
            }
        }
        scanner.nextLine(); // Consume the newline character
        return res;
    }

    public static void main(String[] args) {
        scanner.nextInt(); // Read the input
        System.out.println((~0x8421 & solve()) != 0 ? "YES" : "NO");
    }
}
