import java.util.Scanner;

public class 18f20f132352367297e30e7cbe3d677d_nc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int b = sc.nextInt();
        int d = sc.nextInt();
        String a = sc.next();
        String c = sc.next();
        int[] t = new int[128];
        int s = 0;
        int n = c.length();
        for (int i = 0; i < c.length(); ++i) {
            int k = t[i];
            for (int j = 0; j < a.length(); ++j) {
                if (a.charAt(j) == c.charAt((i + k) % n)) {
                    ++k;
                }
            }
            t[i] = k;
        }
        for (int i = 0; i < b; ++i) {
            s += t[s % n];
        }
        System.out.println(s / n / d);
    }
}
