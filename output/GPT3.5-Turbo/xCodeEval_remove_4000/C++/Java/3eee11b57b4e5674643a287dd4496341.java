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
                sum[a[i]][j + 1] += sum[a[i]][j];
                list.add(j);
            }
            b[a[i]] = list.stream().mapToInt(Integer::intValue).toArray();
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

    private static int find(int[][] sum, int n) {
        int mx = 0, ret = -1;
        for (int i = 0; i < 100; i++) {
            if (chmax(mx, sum[i][n])) {
                ret = i;
            }
        }
        return ret;
    }

    private static int[] nex(int x, int y, int[] b_i, int[] b_j) {
        if (x != b_i.length && y != b_j.length) {
            if (b_i[x] < b_j[y]) {
                return new int[]{1, b_i[x]};
            } else {
                return new int[]{-1, b_j[y]};
            }
        } else if (x != b_i.length) {
            return new int[]{1, b_i[x]};
        } else if (y != b_j.length) {
            return new int[]{-1, b_j[y]};
        } else {
            return new int[]{-2, 0};
        }
    }

    private static boolean chmax(int a, int b) {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }
}
