import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        System.out.println((~0x8421 & solve(scanner.nextLine())) != 0 ? "YES" : "NO");
    }

    public static int solve(String s) {
        if (s.equals("0")) {
            return 1 << 0;
        }
        if (s.equals("1")) {
            return 1 << 15;
        }
        if (s.equals("?")) {
            return (1 << 3) | (1 << 12);
        }

        int x = solve(s.substring(0, s.indexOf(' ')));
        char ch = s.charAt(s.indexOf(' ') + 1);
        int y = solve(s.substring(s.indexOf(' ') + 2));

        int res = 0;
        for (int i = 0; i < 16; i++) {
            if ((_1(x, i))) {
                for (int j = 0; j < 16; j++) {
                    if ((_1(y, j))) {
                        int k = 0;
                        if (ch == '^') {
                            k = i ^ j;
                        }
                        if (ch == '&') {
                            k = i & j;
                        }
                        if (ch == '|') {
                            k = i | j;
                        }
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
