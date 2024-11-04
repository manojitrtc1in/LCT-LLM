import java.io.*;
import java.util.*;

public class 686573fe8b70933c918837dfd603ba97_nc {
    static final int MOD = 1000000007;
    static final int MOD1 = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<int[]> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray());
        }
        if (n >= 50) {
            System.out.println(0);
            return;
        }
        if (n <= 2) {
            System.out.println(n);
            for (int i = 0; i < n; i++) {
                System.out.println(i + 1);
            }
            return;
        }
        Set<Integer> er = new HashSet<>();
        for (int i = 0; i < n; i++) {
            boolean f = false;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || i == k || j == k) {
                        continue;
                    }
                    int w = 0;
                    for (int d = 0; d < 5; d++) {
                        w += (l.get(i)[d] - l.get(j)[d]) * (l.get(i)[d] - l.get(k)[d]);
                    }
                    if (w > 0) {
                        f = true;
                        break;
                    }
                }
                if (f) {
                    break;
                }
            }
            if (!f) {
                er.add(i + 1);
            }
        }
        System.out.println(er.size());
        for (int num : er) {
            System.out.println(num);
        }
    }
}
