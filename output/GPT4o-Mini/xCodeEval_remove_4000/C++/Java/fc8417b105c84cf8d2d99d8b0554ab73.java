import java.util.*;

public class fc8417b105c84cf8d2d99d8b0554ab73xcodeeval_processed_4000.json {
    static final long MAXN = (long) 2e5 + 99, INF = 0x3f3f3f3f, MAXP = (long) 1e4;
    static long HASHprime = 1333331;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ans = (int) INF, n, k;
        Map<Integer, Boolean> t = new HashMap<>();
        List<List<Integer>> a = new ArrayList<>((int) MAXN);
        
        for (int i = 0; i < MAXN; i++) {
            a.add(new ArrayList<>());
        }

        n = scanner.nextInt();
        k = scanner.nextInt();
        
        for (int i = 0; i < n; i++) {
            int temp = scanner.nextInt();
            int cnt = 0;
            while (temp > 0) {
                a.get(temp).add(cnt++);
                t.put(temp, true);
                temp /= 2;
            }
        }

        for (Map.Entry<Integer, Boolean> it : t.entrySet()) {
            int i = it.getKey();
            if (a.get(i).size() < k) {
                continue;
            }
            Collections.sort(a.get(i));
            ans = Math.min(ans, a.get(i).subList(0, k).stream().mapToInt(Integer::intValue).sum());
        }
        
        System.out.println(ans);
    }
}
