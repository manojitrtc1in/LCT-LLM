import java.util.Scanner;

public class d3477381135b36616240d257a4407fa7_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        String a = scanner.next();
        String c = scanner.next();
        int an = a.length();
        int cn = c.length();
        int[] t = new int[cn];
        for (int i = 0; i < cn; i++) {
            int k = 0;
            for (int j = 0; j < an; j++) {
                if (a.charAt(j) == c.charAt((i + k) % cn)) {
                    k++;
                }
            }
            t[i] = k;
        }
        int s = 0;
        for (int i = 0; i < b; i++) {
            s += t[s % cn];
        }
        s /= cn * d;
        System.out.println(s);
    }
}
