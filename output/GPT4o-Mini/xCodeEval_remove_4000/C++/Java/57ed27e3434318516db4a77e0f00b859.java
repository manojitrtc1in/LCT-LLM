import java.util.*;

public class 57ed27e3434318516db4a77e0f00b859xcodeeval_processed_4000.json {
    static final int N = (int) 1e6 + 9;
    static long last_res;
    static int Case;
    static long res = 1;
    static boolean[] use = new boolean[1200];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        Arrays.fill(use, false);
        long zero = 0, all = 10;
        int n = str.length();

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (str.charAt(i) >= 'A' && str.charAt(i) <= 'J') {
                    res *= 9;
                    all--;
                    use[str.charAt(i)] = true;
                } else if (str.charAt(i) == '?') {
                    res *= 9;
                }
            } else {
                if (str.charAt(i) >= 'A' && str.charAt(i) <= 'J') {
                    if (use[str.charAt(i)]) continue;
                    use[str.charAt(i)] = true;
                    res *= all;
                    all--;
                } else if (str.charAt(i) == '?') {
                    zero++;
                }
            }
        }
        System.out.print(res);
        for (long i = 0; i < zero; i++) {
            System.out.print('0');
        }
        System.out.println();
    }
}
