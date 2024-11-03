import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        System.out.println((~0x8421 & solve(scanner.nextLine())) != 0 ? "YES" : "NO");
    }

    public static int solve(String s) {
        int x, y, i, j, k = 0, res = 0;
        char ch = s.charAt(0);
        if (ch == '0') return 1 << 0;
        if (ch == '1') return 1 << 15;
        if (ch == '?') return (1 << 3) | (1 << 12);

        x = solve(s.substring(1));
        ch = s.charAt(1);
        y = solve(s.substring(2));

        for (i = 0; i < 16; i++) {
            if ((_1(x, i)) == 0) continue;
            for (j = 0; j < 16; j++) {
                if ((_1(y, j)) == 0) continue;
                if (ch == '^') k = i ^ j;
                if (ch == '&') k = i & j;
                if (ch == '|') k = i | j;
                res |= 1 << k;
            }
        }
        return res;
    }

    public static int _1(int x, int i) {
        return x & (1 << i);
    }
}
