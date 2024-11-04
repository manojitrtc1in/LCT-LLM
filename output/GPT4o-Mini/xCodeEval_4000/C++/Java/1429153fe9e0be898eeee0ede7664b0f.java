import java.util.*;
import java.io.*;

public class 1429153fe9e0be898eeee0ede7664b0f_nc {
    public static void main(String[] args) {
        new Solution().solve();
    }

    void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        List<Integer> idx = new ArrayList<>();
        for (int f = 0; f < n; f++) {
            for (int s = 0; s < n; s++) {
                if (f == s || f == n - 1 - s || f == n / 2 || s == n / 2) {
                    idx.add(f);
                }
            }
        }

        int sum = 0;
        for (int i : idx) {
            sum += a[i];
        }
        System.out.println(sum);
    }
}
