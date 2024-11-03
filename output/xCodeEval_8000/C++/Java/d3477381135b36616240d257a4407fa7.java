import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int b = input.nextInt();
        int d = input.nextInt();
        String a = input.next();
        String c = input.next();
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
