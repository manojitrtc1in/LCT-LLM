import java.util.Scanner;

public class d3477381135b36616240d257a4407fa7xcodeeval_processed_8000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        String a = scanner.next();
        String c = scanner.next();
        int[] t = new int[c.length()];
        for (int i = 0; i < c.length(); i++) {
            int k = 0;
            for (int j = 0; j < a.length(); j++) {
                if (a.charAt(j) == c.charAt((i + k) % c.length())) {
                    k++;
                }
            }
            t[i] = k;
        }
        int s = 0;
        for (int i = 0; i < b; i++) {
            s += t[s % c.length()];
        }
        s /= c.length() * d;
        System.out.println(s);
    }
}
