

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            int arr[] = new int[x];
            int min = 1000000000;
            for(int i = 0; i < x; i++){
                arr[i] = in.nextInt();
                if(arr[i] < min){
                    min = arr[i];
                }
            }
            int cout = 0;
            for (int i = 0; i < x; i++) {
                if(arr[i]!=min){
                    cout++;
                }
            }
            System.out.println(cout);
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}


