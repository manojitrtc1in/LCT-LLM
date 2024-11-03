import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        System.out.println(solve(n));
    }

    public static String solve(int n) {
        int x, y, k, res = 0;
        char ch = getchar();
        if(ch == '0') return "1";
        if(ch == '1') return "32768";
        if(ch == '?') return "4104";

        x = solve(n), ch = getchar(), y = solve(n); getchar();

        for(int i=0; i<16; i++) {
            if(_1(x, i)) {
                for(int j=0; j<16; j++) {
                    if(_1(y, j)) {
                        if(ch == '^') k = i ^ j;
                        if(ch == '&') k = i & j;
                        if(ch == '|') k = i | j;
                        res |= _1(k);
                    }
                }
            }
        }

        return res;
    }

    public static int _1(int x, int i) {
        return x & (1 << i);
    }
}
