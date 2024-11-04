import java.util.Scanner;

public class 18f20f132352367297e30e7cbe3d677dxcodeeval_processed_4000.json {
    static long[] t = new long[128];
    static char[] a = new char[128];
    static char[] c = new char[128];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        scanner.next(a);
        scanner.next(c);
        
        long s = 0;
        int n = c.length;
        
        for (int i = 0; i < n; i++) {
            int k = 0;
            for (int j = 0; a[j] != 0; j++) {
                if (a[j] == c[(i + k) % n]) {
                    k++;
                }
            }
            t[i] = k;
        }
        
        for (int i = 0; i < b; i++) {
            s += t[(int)(s % n)];
        }
        
        System.out.println(s / n / d);
    }
}
