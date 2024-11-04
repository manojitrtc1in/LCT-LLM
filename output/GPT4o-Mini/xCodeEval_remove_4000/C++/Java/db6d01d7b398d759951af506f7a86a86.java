import java.util.*;

public class db6d01d7b398d759951af506f7a86a86xcodeeval_processed_4000.json {
    static int[] a = new int[10];
    static int[] A = new int[10];
    static int[] B = new int[10];
    static String s;
    static int S = -1, Sx, Sy, AS = -1, ASx, ASy, ASz;

    static void chk(int x, int y) {
        System.arraycopy(a, 0, A, 0, A.length);
        System.arraycopy(a, 0, B, 0, B.length);
        A[x]--;
        B[y]--;
        if (A[x] < 0 || B[y] < 0) return;
        int T = 0;
        for (int i = 0; i < 10; i++) T += Math.min(A[i], B[9 - i]);
        if (T > S) {
            S = T;
            Sx = x;
            Sy = y;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();
        int n = s.length();
        for (int i = 0; i < n; i++) a[s.charAt(i) - '0']++;

        for (int i = 0; i <= a[0]; i++) {
            a[0] -= i;
            S = -1;
            Sx = Sy = 0;
            chk(1, 9);
            chk(2, 8);
            chk(3, 7);
            chk(4, 6);
            chk(5, 5);
            a[0] += i;

            if (S == -1) {
                if (i >= 1 && i >= AS) {
                    AS = i;
                    Sx = Sy = 0;
                    ASz = i;
                }
                continue;
            }
            if (S + i + 1 > AS) {
                AS = S + i + 1;
                ASx = Sx;
                ASy = Sy;
                ASz = i;
            }
        }

        if (AS <= 0) {
            System.out.println(s);
            System.out.println(s);
            return;
        }

        if (ASx == 0) --ASz;

        a[0] -= ASz;
        System.arraycopy(a, 0, A, 0, A.length);
        System.arraycopy(a, 0, B, 0, B.length);
        A[ASx]--;
        B[ASy]--;

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < A[i] - Math.min(A[i], B[9 - i]); j++)
                System.out.print(i);
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < Math.min(A[i], B[9 - i]); j++)
                System.out.print(i);
        System.out.print(ASx);
        for (int i = 0; i < ASz; i++) System.out.print('0');
        System.out.println();

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < B[9 - i] - Math.min(A[i], B[9 - i]); j++)
                System.out.print(9 - i);
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < Math.min(A[i], B[9 - i]); j++)
                System.out.print(9 - i);
        System.out.print(ASy);
        for (int i = 0; i < ASz; i++) System.out.print('0');
        System.out.println();
    }
}
