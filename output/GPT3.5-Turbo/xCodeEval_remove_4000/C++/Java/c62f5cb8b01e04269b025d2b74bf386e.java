import java.util.*;

public class c62f5cb8b01e04269b025d2b74bf386excodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        String a = scanner.next();
        String c = scanner.next();
        int[] t = new int[128];
        int s = 0;
        int n = c.length();
        for (int i = 0; i < c.length(); i++) {
            int k = t[i];
            for (int j = 0; j < a.length(); j++) {
                if (a.charAt(j) == c.charAt((i + k) % n)) {
                    k++;
                }
            }
            t[i] = k;
        }
        for (int i = 0; i < b; i++) {
            s += t[s % n];
        }
        System.out.println(s / n / d);
    }
}