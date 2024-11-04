import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = -sc.nextInt();
        }
        Arrays.sort(a);
        int ans = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            res -= a[i];
            if (res < 0) {
                ans += res;
                break;
            }
            if (i != n - 1) {
                ans += res;
            }
        }
        if (ans >= 0) {
            System.out.println(ans);
            return;
        }
        List<Integer> tmp = new ArrayList<>();
        tmp.add(res);
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
