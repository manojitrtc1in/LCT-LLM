

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int arr[]= new int[7];
            HashSet<Integer> set = new HashSet<>();
            for(int i = 0; i < arr.length; i++){
                arr[i] = in.nextInt();
            }
            System.out.println(arr[0]+" "+arr[1]+" "+(arr[6]-arr[0]-arr[1]));
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}


