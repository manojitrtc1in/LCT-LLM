import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();

        long g = gcd(a, b);
        a /= g;
        b /= g;

        long k = Math.min(m / b, n / a);
        long width = k * a;
        long height = k * b;

        long x1 = Math.max(x - (width + 1) / 2, 0);
        long x2 = Math.min(x1 + width, n);
        x1 = x2 - width;

        long y1 = Math.max(y - (height + 1) / 2, 0);
        long y2 = Math.min(y1 + height, m);
        y1 = y2 - height;

        System.out.println(x1 + " " + y1 + " " + x2 + " " + y2);
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
