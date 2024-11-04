import java.util.*;

public class 3eee11b57b4e5674643a287dd4496341_nc {
    static int[] a = new int[202020];
    static int[][] sum = new int[100][202020];
    static int[] mp = new int[404040];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt() - 1;
        }
        List<List<Integer>> b = new ArrayList<>(100);
        for (int i = 0; i < 100; i++) {
            b.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            sum[a[i]][i + 1]++;
            b.get(a[i]).add(i);
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j + 1] += sum[i][j];
            }
        }
        int i = find();
        int ans = 0;
        Arrays.fill(mp, -1);

        for (int j = 0; j < 100; j++) {
            if (i == j) continue;
            if (b.get(i).isEmpty() || b.get(j).isEmpty()) continue;
            int x = 0, y = 0;
            int now = 202020;
            mp[202020] = 0;
            List<Integer> era = new ArrayList<>();
            while (true) {
                Pair<Integer, Integer> tmp = nex(x, y, b, i, j);
                if (tmp.first == -2) break;
                if (tmp.first == 1) x++;
                else y++;
                now += tmp.first;
                if (mp[now] != -1) {
                    tmp = nex(x, y, b, i, j);
                    if (tmp.first == -2) {
                        ans = Math.max(ans, n - mp[now]);
                    } else {
                        ans = Math.max(ans, tmp.second - mp[now]);
                    }
                } else {
                    mp[now] = tmp.second + 1;
                    era.add(now);
                }
            }
            for (int e : era) mp[e] = -1;
        }
        System.out.println(ans);
    }

    static int find() {
        int mx = 0, ret = -1;
        for (int i = 0; i < 100; i++) {
            if (sum[i][n] > mx) {
                mx = sum[i][n];
                ret = i;
            }
        }
        return ret;
    }

    static Pair<Integer, Integer> nex(int x, int y, List<List<Integer>> b, int i, int j) {
        if (x != b.get(i).size() && y != b.get(j).size()) {
            if (b.get(i).get(x) < b.get(j).get(y)) {
                return new Pair<>(1, b.get(i).get(x));
            } else {
                return new Pair<>(-1, b.get(j).get(y));
            }
        } else if (x != b.get(i).size()) {
            return new Pair<>(1, b.get(i).get(x));
        } else if (y != b.get(j).size()) {
            return new Pair<>(-1, b.get(j).get(y));
        } else {
            return new Pair<>(-2, 0);
        }
    }

    static class Pair<F, S> {
        public F first;
        public S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}
