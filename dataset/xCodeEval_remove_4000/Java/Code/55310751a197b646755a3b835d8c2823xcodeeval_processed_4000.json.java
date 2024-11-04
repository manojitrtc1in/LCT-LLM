

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            long r = in.nextLong(),c = in.nextLong(),x = in.nextLong();
            long R = 0;
            long C = 0;
            if(x%r==0){
                C=x/r;
                R=r;
            }else {
                C = x/r +1;
                R = x%r;
            }
            long res = 0;
            res = c*(R-1)+C;
            System.out.println(res);
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}


