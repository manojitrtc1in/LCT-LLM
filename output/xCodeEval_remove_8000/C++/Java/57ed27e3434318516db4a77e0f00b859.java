import java.util.Scanner;

public class 57ed27e3434318516db4a77e0f00b859xcodeeval_processed_8000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        long res = 1;
        boolean[] use = new boolean[1200];
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
                    if (use[str.charAt(i)]) {
                        continue;
                    }
                    use[str.charAt(i)] = true;
                    res *= all;
                    all--;
                } else if (str.charAt(i) == '?') {
                    zero++;
                }
            }
        }

        System.out.print(res);
        for (int i = 0; i < zero; i++) {
            System.out.print("0");
        }
        System.out.println();
    }
}
