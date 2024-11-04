



import java.io.IOException;
import java.util.Scanner;

public class C {

    
    private static void fun(long h, long c, long t) {
        if (h == t) {
            System.out.println(1);
            return;
        }
        if (h + c >= 2 * t) {
            System.out.println(2);
            return;
        }
        

        long x = (h - t) / (2 * t - h - c);

        

        long a1 = ((x + 1) * h + x * c);
        long a2 = ((x + 2) * h + (x + 1) * c);
        double abs1 = Math.abs(a1 - t * (2 * x + 1));
        double abs2 = Math.abs(a2 - t * (2 * x + 3));







        if (abs1 * (2 * x + 3) > abs2 * (2 * x + 1)) {
            System.out.println(2 * x + 3);
        } else {
            System.out.println(2 * x + 1);
        }
    }


    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int id0 = sc.nextInt();

        for (int tt = 0; tt < id0; tt++) {
            long h = sc.nextLong();
            long c = sc.nextLong();
            long t = sc.nextLong();

            fun(h, c, t);
        }
    }


}

