import java.util.*;

class Main {
    static int solve(Scanner sc) {
        int x, y, i, j, k = 0, res = 0;
        char ch = sc.next().charAt(0);
        if(ch == '0') return 1 << 0;
        if(ch == '1') return 1 << 15;
        if(ch == '?') return (1 << 3) | (1 << 12);

        x = solve(sc);
        ch = sc.next().charAt(0);
        y = solve(sc);

        for(i = 0; i < 16; i++) {
            if(~x & 1 << i) continue;
            for(j = 0; j < 16; j++) {
                if(~y & 1 << j) continue;
                if(ch == '^') k = i ^ j;
                if(ch == '&') k = i & j;
                if(ch == '|') k = i | j;
                res |= 1 << k;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int e;
        System.out.println((~0x8241 & solve(sc)) != 0 ? "YES" : "NO");
    }
}