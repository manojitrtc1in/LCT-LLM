import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        a[k - 1] *= -1;

        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > 0) {
                if (!stack.isEmpty() && stack.peek() == a[i]) {
                    stack.pop();
                } else {
                    stack.push(a[i]);
                    a[i] = -a[i];
                }
            } else {
                stack.push(-a[i]);
            }
        }

        if (!stack.isEmpty()) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();
        }
    }
}
