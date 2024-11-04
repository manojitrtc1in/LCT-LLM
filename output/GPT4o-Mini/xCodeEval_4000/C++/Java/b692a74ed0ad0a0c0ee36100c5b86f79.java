import java.util.*;
import java.io.*;

public class b692a74ed0ad0a0c0ee36100c5b86f79_nc {
    static final int MAXV = 100;
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final PrintWriter out = new PrintWriter(System.out);
    
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for (int i = 0; i < n; i++) {
            a[i]--;
        }

        int ans = 0;
        int fre = -1;

        Map<Integer, Integer> cnt = new HashMap<>();
        for (int e : a) {
            cnt.put(e, cnt.getOrDefault(e, 0) + 1);
        }
        
        int ma = 0;
        for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
            ma = Math.max(ma, entry.getValue());
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

        for (int i = 0; i < MAXV; i++) {
            if (i == fre) continue;
            List<Integer> b = new ArrayList<>();
            b.add(0);
            for (int e : a) {
                int pb = b.get(b.size() - 1);
                if (e == fre) {
                    pb--;
                } else if (e == i) {
                    pb++;
                }
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
            for (int j = 0, j2 = n + 1; j < mi.length; j++) {
                j2 = Math.min(j2, mi[j]);
                ans = Math.max(ans, ma[j] - j2);
            }
        }

        out.println(ans);
        out.flush();
    }
}
