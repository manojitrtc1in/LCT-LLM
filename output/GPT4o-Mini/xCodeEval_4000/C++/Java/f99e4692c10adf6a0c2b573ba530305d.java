import java.util.*;

public class f99e4692c10adf6a0c2b573ba530305d_nc {
    static final int N = (int) 1e6 + 9;
    static int[] a = new int[N];
    static int[] s = new int[N];
    static int n, top;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        int idx = scanner.nextInt() - 1;
        a[idx] *= -1;

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > 0) {
                if (top > 0 && s[top] == a[i]) {
                    top--;
                } else {
                    s[++top] = a[i];
                    a[i] = -a[i];
                }
            } else {
                s[++top] = -a[i];
            }
        }

        if (top > 0) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
            }
        }
    }
}