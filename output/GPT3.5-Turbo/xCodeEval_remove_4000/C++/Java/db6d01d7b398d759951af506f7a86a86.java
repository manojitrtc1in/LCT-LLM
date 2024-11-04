import java.util.Arrays;
import java.util.Scanner;

public class db6d01d7b398d759951af506f7a86a86xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[] s = scanner.next().toCharArray();
        int n = s.length;
        int[] a = new int[10];
        for (int i = 0; i < n; i++) {
            a[s[i] - '0']++;
        }
        int[] A = new int[10];
        int[] B = new int[10];
        int S = -1, Sx = 0, Sy = 0, AS = -1, ASx = 0, ASy = 0, ASz = 0;
        for (int i = 0; i <= a[0]; i++) {
            a[0] -= i;
            S = -1;
            Sx = Sy = 0;
            chk(a, A, B, 1, 9);
            chk(a, A, B, 2, 8);
            chk(a, A, B, 3, 7);
            chk(a, A, B, 4, 6);
            chk(a, A, B, 5, 5);
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
            System.out.println(new String(s));
            System.out.println(new String(s));
            return;
        }
        if (ASx == 0) {
            --ASz;
        }
        a[0] -= ASz;
        A = Arrays.copyOf(a, a.length);
        B = Arrays.copyOf(a, a.length);
        A[ASx]--;
        B[ASy]--;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < A[i] - Math.min(A[i], B[9 - i]); j++) {
                System.out.print(i);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < Math.min(A[i], B[9 - i]); j++) {
                System.out.print(i);
            }
        }
        System.out.print(ASx);
        for (int i = 0; i < ASz; i++) {
            System.out.print(0);
        }
        System.out.println();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < B[9 - i] - Math.min(A[i], B[9 - i]); j++) {
                System.out.print(9 - i);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < Math.min(A[i], B[9 - i]); j++) {
                System.out.print(9 - i);
            }
        }
        System.out.print(ASy);
        for (int i = 0; i < ASz; i++) {
            System.out.print(0);
        }
        System.out.println();
    }

    public static void chk(int[] a, int[] A, int[] B, int x, int y) {
        System.arraycopy(a, 0, A, 0, A.length);
        System.arraycopy(a, 0, B, 0, B.length);
        A[x]--;
        B[y]--;
        if (A[x] < 0 || B[y] < 0) {
            return;
        }
        int T = 0;
        for (int i = 0; i < 10; i++) {
            T += Math.min(A[i], B[9 - i]);
        }
        if (T > S) {
            S = T;
            Sx = x;
            Sy = y;
        }
    }
}
