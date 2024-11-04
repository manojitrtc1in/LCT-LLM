import java.util.*;

public class 13e717a742cf0191d4edddce8f6e6bce_nc {
    static int[] a = new int[10];
    static int[] b = new int[10];
    static String s;
    static int r, rr, x, y, xx, yy, zero;

    static void calc(int x) {
        int y = 10 - x;
        if (a[x] == 0 || a[y] == 0) return;
        int r = 1;
        for (int i = 0; i < 10; i++) {
            r += Math.min(a[i] - (i == x ? 1 : 0), a[9 - i] - (9 - i == y ? 1 : 0));
        }
        if (r > rr) {
            rr = r;
            xx = x;
            yy = y;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();
        for (int i = 0; i < s.length(); i++) {
            a[s.charAt(i) - '0']++;
        }

        r = -1;
        x = y = s.charAt(0) - '0';
        for (int i = 0; i <= a[0]; i++) {
            a[0] -= i;
            rr = 0;
            xx = yy = s.charAt(0) - '0';
            calc(1);
            calc(2);
            calc(3);
            calc(4);
            calc(5);
            if (rr + i > r) {
                r = rr + i;
                zero = i;
                x = xx;
                y = yy;
            }
            a[0] += i;
        }

        if (x == 0) zero--;
        a[0] -= zero;
        System.arraycopy(a, 0, b, 0, a.length);
        a[x]--;
        b[y]--;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < a[i] - Math.min(a[i], b[9 - i]); j++) {
                System.out.print(i);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < Math.min(a[i], b[9 - i]); j++) {
                System.out.print(i);
            }
        }
        if (a[x] >= 0) System.out.print(x);
        for (int i = 0; i < zero; i++) {
            System.out.print('0');
        }
        System.out.println();

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < b[9 - i] - Math.min(a[i], b[9 - i]); j++) {
                System.out.print(9 - i);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < Math.min(a[i], b[9 - i]); j++) {
                System.out.print(9 - i);
            }
        }
        if (b[y] >= 0) System.out.print(y);
        for (int i = 0; i < zero; i++) {
            System.out.print('0');
        }
        System.out.println();
    }
}
