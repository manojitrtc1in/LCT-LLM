import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println((~0x8421 & solve(scanner)) != 0 ? "YES" : "NO");
    }

    public static int solve(Scanner scanner) {
        int x, y, k, res = 0;
        char ch = scanner.next().charAt(0);
        if (ch == '0') return 1 << 0;
        if (ch == '1') return 1 << 15;
        if (ch == '?') return (1 << 3) | (1 << 12);

        x = solve(scanner);
        ch = scanner.next().charAt(0);
        y = solve(scanner);
        scanner.nextLine();

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

    public static boolean _1(int x, int i) {
        return (x & (1 << i)) != 0;
    }
}
