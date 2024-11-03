import java.util.Scanner;

public class 13f27feb112fb8d2d3683b7b6706a043xcodeeval_processed_8000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();
        int res = solve(scanner);
        if ((~0x8241 & res) != 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static int solve(Scanner scanner) {
        char ch = scanner.next().charAt(0);
        if (ch == '0') {
            return 1 << 0;
        }
        if (ch == '1') {
            return 1 << 15;
        }
        if (ch == '?') {
            return (1 << 3) | (1 << 12);
        }

        int x = solve(scanner);
        ch = scanner.next().charAt(0);
        int y = solve(scanner);

        int res = 0;
        for (int i = 0; i < 16; i++) {
            if ((~x & (1 << i)) != 0) {
                continue;
            }
            for (int j = 0; j < 16; j++) {
                if ((~y & (1 << j)) != 0) {
                    continue;
                }
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
                res |= 1 << k;
            }
        }
        return res;
    }
}
