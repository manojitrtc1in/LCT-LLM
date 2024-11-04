

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            HashMap<Integer, Integer> map = new HashMap<>();

            int n = in.nextInt();

            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                if (map.containsKey(a))
                    map.put(a, map.get(a) + 1);
                else
                    map.put(a, 1);
            }
            boolean at = false;
            for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
                if (entry.getValue() >= 3) {
                    System.out.println(entry.getKey());
                    at = true;
                    break;
                }
            }
            if(!at){
                System.out.println(-1);
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


