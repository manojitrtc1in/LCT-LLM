import java.util.*;

public class fc8417b105c84cf8d2d99d8b0554ab73_nc {
    static final long MAXN = 200000 + 99;
    static final int INF = 0x3f3f3f3f;
    static final long HASHprime = 1333331;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ans = INF, n, k;
        Map<Integer, Boolean> t = new HashMap<>();
        List<Integer>[] a = new ArrayList[(int) MAXN];
        for (int i = 0; i < a.length; i++) {
            a[i] = new ArrayList<>();
        }

        n = scanner.nextInt();
        k = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int temp = scanner.nextInt();
            int cnt = 0;
            while (temp > 0) {
                a[temp].add(cnt++);
                t.put(temp, true);
                temp /= 2;
            }
        }

        for (Map.Entry<Integer, Boolean> it : t.entrySet()) {
            int i = it.getKey();
            if (a[i].size() < k) {
                continue;
            }
            Collections.sort(a[i]);
            ans = Math.min(ans, a[i].subList(0, k).stream().mapToInt(Integer::intValue).sum());
        }

        System.out.println(ans);
    }
}
