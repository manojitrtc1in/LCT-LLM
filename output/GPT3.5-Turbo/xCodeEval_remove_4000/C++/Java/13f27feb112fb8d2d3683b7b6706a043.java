import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        int res = solve(sc);
        if ((~0x8241 & res) != 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static int solve(Scanner sc) {
        String line = sc.nextLine();
        if (line.equals("0")) {
            return 1 << 0;
        }
        if (line.equals("1")) {
            return 1 << 15;
        }
        if (line.equals("?")) {
            return (1 << 3) | (1 << 12);
        }

        int x = solve(sc);
        char ch = line.charAt(0);
        int y = solve(sc);

        int k = 0;
        int res = 0;

        for (int i = 0; i < 16; i++) {
            if ((~x & (1 << i)) == 0) {
                continue;
            }
            for (int j = 0; j < 16; j++) {
                if ((~y & (1 << j)) == 0) {
                    continue;
                }
                if (ch == '^') {
                    k = i ^ j;
                }
                if (ch == '&') {
                    k = i & j;
                }
                if (ch == '|') {
                    k = i | j;
                }
                res |= 1 << k;
            }
        }
        return res;
    }
}
