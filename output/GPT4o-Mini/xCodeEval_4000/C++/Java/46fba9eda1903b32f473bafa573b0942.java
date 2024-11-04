import java.util.Scanner;

public class 46fba9eda1903b32f473bafa573b0942_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long a = scanner.nextLong();
        long n = (long) 1e17;
        n *= 18;

        n %= a;
        long k = n;

        for (int i = 0; i < 44; i++) {
            n = (n + k) % a;
        }

        if (n < 0) {
            n += a;
        }
        long c = a - n;
        long d = c + (long) 1e18 - 1;

        System.out.println(c + " " + d);
    }
}
