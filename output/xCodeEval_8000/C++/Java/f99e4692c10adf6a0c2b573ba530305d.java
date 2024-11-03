import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int m = scanner.nextInt();
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            if (x > 0) {
                for (int j = 0; j < n; j++) {
                    if (a[j] == x) {
                        a[j] = -x;
                        break;
                    }
                }
            } else {
                x = -x;
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (a[j] == x) {
                        a[j] = -x;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
