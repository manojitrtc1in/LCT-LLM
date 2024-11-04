import java.util.*;

public class 0b1a54afd90ac7191f4cccd573d4648cxcodeeval_processed_4000.json {
    static long N;
    static long[] a;
    static long[] b;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextLong();
        a = new long[(int) N];
        Map<Long, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextLong();
            mp.put(a[i], mp.getOrDefault(a[i], 0) + 1);
        }
        
        b = new long[(int) N];
        for (int i = 0; i < N; i++) {
            b[i] = scanner.nextLong();
        }

        List<Long> vs = new ArrayList<>();
        for (Map.Entry<Long, Integer> elem : mp.entrySet()) {
            if (elem.getValue() > 1) {
                vs.add(elem.getKey());
            }
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            boolean isok = false;
            for (Long elem : vs) {
                if ((elem & a[i]) == a[i]) {
                    isok = true;
                    break;
                }
            }

            if (isok) {
                ans += b[i];
            }
        }

        System.out.println(ans);
    }
}
