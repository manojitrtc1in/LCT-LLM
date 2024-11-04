import java.util.*;

public class 075f823053322f46dfd0a38ad2dd4fcf_nc {
    static int[] t = new int[128];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int b = sc.nextInt();
        int d = sc.nextInt();
        String a = sc.next();
        String c = sc.next();

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
