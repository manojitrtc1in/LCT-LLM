import java.util.*;

class Main {
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
        int[] tt = new int[c.length()];
        Arrays.fill(tt, -1);
        int s = 0;
        boolean bj = false;
        for (int i = 0; i < b; i++) {
            s += t[s % c.length()];
            if (bj) {
                continue;
            }
            if (tt[s % c.length()] == -1) {
                tt[s % c.length()] = i;
            } else {
                int r = i - tt[s % c.length()];
                s += (s - tt[s % c.length()]) * ((b - i) / r);
                i += ((b - i) / r) * r;
                bj = true;
            }
        }
        s /= c.length() * d;
        System.out.println(s);
    }
}
