import java.util.*;
import java.io.*;

public class 0b1a54afd90ac7191f4cccd573d4648c_nc {
    static long INF = 1000000007;
    static long MOD = 1000000007;
    static long[] a, b;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        a = new long[N];
        b = new long[N];
        Map<Long, Integer> mp = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            a[i] = Long.parseLong(st.nextToken());
            mp.put(a[i], mp.getOrDefault(a[i], 0) + 1);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            b[i] = Long.parseLong(st.nextToken());
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
