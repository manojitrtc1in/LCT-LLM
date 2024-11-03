import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt() - 1;
        }
        
        int ans = 0;
        int fre = -1;
        
        {
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int i = 0; i < n; i++) {
                cnt.put(a[i], cnt.getOrDefault(a[i], 0) + 1);
            }
            int ma = 0;
            for (int y : cnt.values()) {
                ma = Math.max(ma, y);
            }
            int mac = 0;
            for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
                if (entry.getValue() == ma) {
                    mac++;
                    fre = entry.getKey();
                }
            }
            if (mac > 1) {
                ans = n;
            }
        }
        
        final int maxv = 100;
        for (int i = 0; i < maxv; i++) {
            if (i == fre) {
                continue;
            }
            int[] b = new int[n + 1];
            b[0] = 0;
            for (int j = 0; j < n; j++) {
                int pb = b[j];
                if (a[j] == fre) {
                    pb--;
                } else if (a[j] == i) {
                    pb++;
                }
                b[j + 1] = pb;
            }
            int[] mi = new int[2 * n + 1];
            int[] ma = new int[2 * n + 1];
            Arrays.fill(mi, n + 1);
            Arrays.fill(ma, -1);
            for (int j = 0; j <= n; j++) {
                int va = n + b[j];
                mi[va] = Math.min(mi[va], j);
                ma[va] = Math.max(ma[va], j);
            }
            int j = n + 1;
            for (int i = 0; i < mi.length; i++) {
                j = Math.min(j, mi[i]);
                ans = Math.max(ans, ma[i] - j);
            }
        }
        
        System.out.println(ans);
    }
}
