import java.util.*;

class Main {
    static final long M = 1000000007;

    static boolean opp(char a, char b) {
        return a == 'W' && b == 'E' || a == 'E' && b == 'W' || a == 'S' && b == 'N' || a == 'N' && b == 'S';
    }

    static char ccinv(char x) {
        switch (x) {
            case 'N':
                return 'S';
            case 'S':
                return 'N';
            case 'W':
                return 'E';
            case 'E':
                return 'W';
        }
        return 'W';
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String r = scanner.next();
        String a = scanner.next();
        String b = scanner.next();
        int n = a.length();
        StringBuilder ar = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            ar.append(ccinv(a.charAt(i)));
        }
        long va = 0;
        long vb = 0;
        long p = 1;
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            va = (va * 131 + ar.charAt(i)) % M;
            vb = (vb + b.charAt(j) * p) % M;
            p = (p * 131) % M;
            if (vb == va) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
