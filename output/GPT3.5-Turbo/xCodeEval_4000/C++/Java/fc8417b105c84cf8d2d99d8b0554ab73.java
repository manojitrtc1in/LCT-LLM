import java.util.*;

public class fc8417b105c84cf8d2d99d8b0554ab73_nc {
    public static void main(String[] args) {
        int ans = Integer.MAX_VALUE;
        int n, k;
        Map<Integer, Boolean> t = new HashMap<>();
        List<Integer>[] a = new ArrayList[200099];
        for (int i = 0; i < 200099; i++) {
            a[i] = new ArrayList<>();
        }
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        for (int i = 0, temp, cnt = 0; i < n; i++, cnt = 0) {
            temp = scanner.nextInt();
            while (temp != 0) {
                a[temp].add(cnt++);
                t.put(temp, true);
                temp /= 2;
            }
        }
        for (Map.Entry<Integer, Boolean> entry : t.entrySet()) {
            int i = entry.getKey();
            if (a[i].size() < k) {
                continue;
            }
            Collections.sort(a[i]);
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += a[i].get(j);
            }
            ans = Math.min(ans, sum);
        }
        System.out.println(ans);
    }
}
