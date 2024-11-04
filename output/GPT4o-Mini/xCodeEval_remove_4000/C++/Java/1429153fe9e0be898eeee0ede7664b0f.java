import java.util.*;
import java.util.function.Function;

public class 1429153fe9e0be898eeee0ede7664b0fxcodeeval_processed_4000.json {
    public void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (i == n - 1 - i || i == n / 2) {
                idx.add(i);
            }
        }
        
        int sum = 0;
        for (int i : idx) {
            sum += a[i];
        }
        
        System.out.println(sum);
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
