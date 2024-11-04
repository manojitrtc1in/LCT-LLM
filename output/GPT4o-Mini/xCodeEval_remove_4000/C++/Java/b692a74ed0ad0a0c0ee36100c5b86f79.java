import java.util.*;
import java.util.stream.*;

public class b692a74ed0ad0a0c0ee36100c5b86f79xcodeeval_processed_4000.json {
    static final String eol = "\n";
    static int caseid = 1;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int totalCases = cases(scanner);
        while (caseid <= totalCases) {
            mainCase(scanner);
            caseid++;
        }
        scanner.close();
    }

    static int cases(Scanner scanner) {
        return 1; // Modify this if you want to handle multiple cases
    }

    static void mainCase(Scanner scanner) {
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt() - 1;
        }

        int ans = 0;
        int fre = -1;

        {
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int e : a) {
                cnt.put(e, cnt.getOrDefault(e, 0) + 1);
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
            if (mac > 1) ans = n;
        }

        final int maxv = 100;
        for (int i = 0; i < maxv; i++) {
            if (i == fre) continue;
            List<Integer> b = new ArrayList<>();
            b.add(0);
            for (int e : a) {
                int pb = b.get(b.size() - 1);
                if (e == fre)
                    pb--;
                else if (e == i)
                    pb++;
                b.add(pb);
            }
            int[] mi = new int[2 * n + 1];
            int[] ma = new int[2 * n + 1];
            Arrays.fill(mi, n + 1);
            Arrays.fill(ma, -1);
            for (int j = 0; j <= n; j++) {
                int va = n + b.get(j);
                mi[va] = Math.min(mi[va], j);
                ma[va] = Math.max(ma[va], j);
            }
            for (int j = 0, jMax = n + 1; j < mi.length; j++) {
                jMax = Math.min(jMax, mi[j]);
                ans = Math.max(ans, ma[j] - jMax);
            }
        }

        System.out.print(ans + eol);
    }
}
