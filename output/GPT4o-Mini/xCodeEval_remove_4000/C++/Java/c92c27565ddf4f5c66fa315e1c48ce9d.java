import java.util.*;

public class c92c27565ddf4f5c66fa315e1c48ce9dxcodeeval_processed_4000.json {
    static final int maxn = 500007;
    static int t;
    static int n, k;
    static int[] a = new int[maxn];
    static long ans, res = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = -sc.nextInt();
        }
        Arrays.sort(a, 0, n);
        int j = -1;
        for (int i = 0; i < n; i++) {
            res -= a[i];
            if (res < 0) {
                j = i;
                break;
            }
            if (i != n - 1) ans += res;
        }
        if (j == -1) {
            System.out.println(ans);
            return;
        }
        List<Integer> tmp = new ArrayList<>();
        tmp.clear();
        tmp.add((int) res);
        for (int i = j + 1; i < n; i++) {
            tmp.add(-a[i]);
        }

        Collections.sort(tmp);
        int w = 0;
        for (int c : tmp) {
            ans += (w / (k + 1)) * c;
            w++;
        }
        System.out.println(ans);
    }
}
