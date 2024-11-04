import java.util.Arrays;
import java.util.Scanner;

public class c18debea521ff603da71936c6b77525axcodeeval_processed_4000.json {
    static int k, m;

    public static void res(int s, int n) {
        int dem = 10;
        if (s > k)
            return;
        if (k - s < 10) {
            while (m > 0 && dem < 100) {
                System.out.print(dem + "0" + (k - s));
                if (n < 10)
                    System.out.print("000");
                else if (n < 100)
                    System.out.print("00");
                else if (n < 1000)
                    System.out.print("0");
                System.out.println(n);
                m--;
                dem++;
            }
            return;
        } else if (k - s < 100)
            System.out.print("00" + (k - s));
        else if (k - s < 1000)
            System.out.print("0" + (k - s));
        else if (k - s < 10000)
            System.out.print(k - s);
        if (n < 10)
            System.out.print("000");
        else if (n < 100)
            System.out.print("00");
        else if (n < 1000)
            System.out.print("0");
        System.out.println(n);
        m--;
    }

    public static void process() {
        int a, b, c, d, s;
        for (int i = 0; i < 9999; i++) {
            boolean[] x = new boolean[10000];
            a = i;
            d = a % 10;
            a /= 10;
            c = a % 10;
            a /= 10;
            b = a % 10;
            a /= 10;
            s = a * b * c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a - b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a - b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a - b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b - c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b - c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b - c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a - b - c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * b - c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a * b - c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a * b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a * b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a * b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -(a + b * c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -(-a + b * c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -(a + b * c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -(-a + b * c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b * c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a + b * c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b * c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a + b * c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b + c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b - c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b + c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b - c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b + c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b - c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a - b + c * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = 10 * a + b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -10 * a - b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = 10 * a + b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = 10 * a + b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = 10 * a + b - c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = 10 * a + b + 10 * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = 10 * a + b - 10 * c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -10 * a - b + 10 * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b + 10 * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b - 10 * c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b + 10 * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b + 10 * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a - b + 10 * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + 10 * b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - 10 * b - c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + 10 * b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + 10 * b + c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + 10 * b + c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b + c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a + b + c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a - b + c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b - c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a - b + c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a + b - c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a - b - c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b + c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (-b + c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b - c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b + c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (-b - c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b - c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (-b + c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b) * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b) * c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a + b) * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a + b) * c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a - b) * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a - b) * c - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a - b) * c + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b * (c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b * (c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b * (c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + b * (-c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a - b * (-c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + b * (-c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b) * (c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a - b) * (c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b) * (c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a - b) * (c - d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (-a + b) * (c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = (a + b) * (-c + d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b + c) + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b + c) - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b - c) + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (b - c) - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (-b + c) + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (-b + c) - d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a * (-b - c) + d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + (b + c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + (b + c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + (b - c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + (b - c) * d;
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + (b + c) * (-d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = -a + (b + c) * (-d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
            s = a + (b - c) * (-d);
            if (s > 0 && !x[s]) {
                x[s] = true;
                res(s, i);
            }
            if (m == 0)
                return;
        }
    }

    public static void process1() {
        for (int i = 0; i < m; i++) {
            if (i < 10)
                System.out.println("0000000" + i);
            else if (i < 100)
                System.out.println("000000" + i);
            else if (i < 1000)
                System.out.println("00000" + i);
            else if (i < 10000)
                System.out.println("0000" + i);
            else if (i < 100000)
                System.out.println("000" + i);
            else if (i < 1000000)
                System.out.println("00" + i);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        k = scanner.nextInt();
        m = scanner.nextInt();
        if (k == 0)
            process1();
        else
            process();
    }
}
