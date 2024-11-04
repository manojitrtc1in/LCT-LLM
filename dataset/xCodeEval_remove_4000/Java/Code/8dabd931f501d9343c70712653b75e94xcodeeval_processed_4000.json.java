



import java.io.IOException;
import java.util.Scanner;


public class D {

    public static void fun(long x, long[] array) {

        long[] sumDays = new long[array.length + 1];
        long[] id0 = new long[array.length + 1];

        for (int i = 0; i < array.length; i++) {
            sumDays[i + 1] = sumDays[i] + array[i];
            id0[i + 1] = id0[i] + array[i] * (array[i] + 1) / 2;
        }
        long ans = 0;

        

        

        int left = array.length;
        int right = array.length;

        while (left > 0) {
            while (sumDays[right] - sumDays[left] < x && left > 0) {
                left--;
            }
            if (sumDays[right] - sumDays[left] >= x) {
                long dec = sumDays[right] - sumDays[left] - x;
                long res = id0[right] - id0[left] - dec * (dec + 1) / 2;
                ans = Math.max(ans, res);
            }
            right--;
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long x = sc.nextLong();
        

        long[] array = new long[2 * n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
            array[n + i] = array[i];
        }
        fun(x, array);

    }


}

