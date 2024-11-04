import java.util.*;

public class 980770e7a017f49149b45e925e6fa9d6xcodeeval_processed_4000.json {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long a = -1, b = -1;

        int tttt = (int) Math.sqrt(n);

        for (int i = 1; i <= tttt + 9; i++) {
            if (n % i == 0) {
                int t = n / i;
                int zt = (int) Math.sqrt(t);

                for (int j = 1; j <= zt + 9; j++) {
                    if (t % j == 0) {
                        long tt = t / j;
                        if (tt >= 1) {
                            long ttt = (tt + 2) * (i + 1) * (j + 2);

                            if (a == -1) a = ttt;
                            else if (ttt < a) a = ttt;

                            if (b == -1) b = ttt;
                            else if (ttt > b) b = ttt;
                        }
                    }
                }

                int zz = i;
                i = n / i;

                t = n / i;
                zt = (int) Math.sqrt(t);

                for (int j = 1; j <= zt + 9; j++) {
                    if (t % j == 0) {
                        long tt = t / j;
                        if (tt >= 1) {
                            long ttt = (tt + 2) * (i + 1) * (j + 2);

                            if (a == -1) a = ttt;
                            else if (ttt < a) a = ttt;

                            if (b == -1) b = ttt;
                            else if (ttt > b) b = ttt;
                        }
                    }
                }

                i = zz;
            }
        }

        System.out.println((a - n) + " " + (b - n));
    }
}
