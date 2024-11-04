import java.util.*;
import java.io.*;

public class c92c27565ddf4f5c66fa315e1c48ce9d_nc {
    static final int maxn = 500007;
    static long t;
    static int n, k;
    static long[] a = new long[maxn];
    static long ans, res = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = -Long.parseLong(st.nextToken());
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
        
        List<Long> tmp = new ArrayList<>();
        tmp.add(res);
        for (int i = j + 1; i < n; i++) {
            tmp.add(-a[i]);
        }

        Collections.sort(tmp);
        long w = 0;
        for (long c : tmp) {
            ans += (w / (k + 1)) * c;
            w++;
        }
        
        System.out.println(ans);
    }
}
