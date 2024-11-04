import java.util.*;

public class fc8417b105c84cf8d2d99d8b0554ab73xcodeeval_processed_4000.json {
    static final int INF = 0x3f3f3f3f;
    static final int MAXN = 2 * 100000 + 99;
    static final int MAXP = 10000;
    static final long HASHprime = 1333331;

    public static void main(String[] args) {
        int ans = INF;
        int n, k;
        HashMap<Integer, Boolean> t = new HashMap<>();
        ArrayList<Integer>[] a = new ArrayList[MAXN];
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        for (int i = 0, temp, cnt = 0; i < n; ++i, cnt = 0) {
            temp = scanner.nextInt();
            while (temp != 0) {
                a[temp].add(cnt++);
                t.put(temp, true);
                temp /= 2;
            }
        }
        for (Map.Entry<Integer, Boolean> entry : t.entrySet()) {
            int i = entry.getKey();
            if (a[i].size() < k)
                continue;
            Collections.sort(a[i]);
            ans = Math.min(ans, a[i].subList(0, k).stream().mapToInt(Integer::intValue).sum());
        }
        System.out.println(ans);
    }
}
