import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int b = input.nextInt();
        int d = input.nextInt();
        String a = input.next();
        String c = input.next();
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
