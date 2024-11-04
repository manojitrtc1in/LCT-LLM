import java.util.*;

public class e8d116875019dc09a381057b75b4891dxcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] a = new int[10];
        for (int i = 0; i < s.length(); i++) {
            a[s.charAt(i) - '0']++;
        }

        int r = 0, x = s.charAt(0) - '0', y = s.charAt(0) - '0';
        int zero = 0;
        for (int i = 0; i <= a[0]; i++) {
            a[0] -= i;
            int rr = 0, xx = s.charAt(0) - '0', yy = s.charAt(0) - '0';
            calc(a, rr, xx, yy, 1);
            calc(a, rr, xx, yy, 2);
            calc(a, rr, xx, yy, 3);
            calc(a, rr, xx, yy, 4);
            calc(a, rr, xx, yy, 5);
            if (rr + i > r) {
                r = rr + i;
                zero = i;
                x = xx;
                y = yy;
            }
            a[0] += i;
        }

        if (x == 0) {
            zero--;
        }
        a[0] -= zero;
        int[] b = Arrays.copyOf(a, a.length);
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
        if (a[x] >= 0) {
            System.out.print(x);
        }
        for (int i = 0; i < zero; i++) {
            System.out.print(0);
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
        if (b[y] >= 0) {
            System.out.print(y);
        }
        for (int i = 0; i < zero; i++) {
            System.out.print(0);
        }
        System.out.println();
    }

    public static void calc(int[] a, int r, int x, int y, int i) {
        int j = 10 - i;
        if (a[i] == 0 || a[j] == 0) {
            return;
        }
        int rr = 1;
        for (int k = 0; k < 10; k++) {
            rr += Math.min(a[k] - (k == i ? 1 : 0), a[9 - k] - (9 - k == j ? 1 : 0));
        }
        if (rr > r) {
            r = rr;
            x = i;
            y = j;
        }
    }
}
