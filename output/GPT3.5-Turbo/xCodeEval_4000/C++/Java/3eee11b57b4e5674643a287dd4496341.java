import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt() - 1;
        }
        int[][] b = new int[100][];
        int[][] sum = new int[100][n + 1];
        for (int i = 0; i < 100; i++) {
            b[i] = new int[0];
        }
        for (int i = 0; i < n; i++) {
            sum[a[i]][i + 1]++;
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if (a[j] == i) {
                    list.add(j);
                }
            }
            b[i] = new int[list.size()];
            for (int j = 0; j < list.size(); j++) {
                b[i][j] = list.get(j);
            }
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j + 1] += sum[i][j];
            }
        }
        int i = find(sum, n);
        int ans = 0;
        int[] mp = new int[404040];
        for (int j = 0; j < 404040; j++) {
            mp[j] = -1;
        }
        for (int j = 0; j < 100; j++) {
            if (i == j) {
                continue;
            }
            if (b[i].length == 0 || b[j].length == 0) {
                continue;
            }
            int x = 0, y = 0;
            int now = 202020;
            mp[202020] = 0;
            List<Integer> era = new ArrayList<>();
            while (true) {
                int[] tmp = nex(x, y, b[i], b[j]);
                if (tmp[0] == -2) {
                    break;
                }
                if (tmp[0] == 1) {
                    x++;
                } else {
                    y++;
                }
                now += tmp[0];
                if (mp[now] != -1) {
                    tmp = nex(x, y, b[i], b[j]);
                    if (tmp[0] == -2) {
                        ans = Math.max(ans, n - mp[now]);
                    } else {
                        ans = Math.max(ans, tmp[1] - mp[now]);
                    }
                } else {
                    mp[now] = tmp[1] + 1;
                    era.add(now);
                }
            }
            for (int e : era) {
                mp[e] = -1;
            }
        }
        System.out.println(ans);
    }

    static int find(int[][] sum, int n) {
        int mx = 0, ret = -1;
        for (int i = 0; i < 100; i++) {
            if (chmax(mx, sum[i][n])) {
                ret = i;
            }
        }
        return ret;
    }

    static int[] nex(int x, int y, int[] b1, int[] b2) {
        if (x != b1.length && y != b2.length) {
            if (b1[x] < b2[y]) {
                return new int[]{1, b1[x]};
            } else {
                return new int[]{-1, b2[y]};
            }
        } else if (x != b1.length) {
            return new int[]{1, b1[x]};
        } else if (y != b2.length) {
            return new int[]{-1, b2[y]};
        } else {
            return new int[]{-2, 0};
        }
    }

    static boolean chmax(int a, int b) {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }
}
