

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            if(x%7==0){
                System.out.println(x);
            }else {
                for(int i = 1; i < 100; i++){
                    if((x-x%10+i)%7==0){
                        System.out.println(x-x%10+i);
                        break;
                    }
                }
            }
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}


