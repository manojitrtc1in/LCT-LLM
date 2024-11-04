import java.util.*;

public class 2d813d46cc55e425c7dd92ae154bf585_nc {
    static int n, k, p, c = 0;
    static int[][] a = new int[505][505];
    static int[] out = new int[125005];
    static int[] chk = new int[125005];
    static int ans, best = 0;
    static int[] di = {1, 0, -1, 0};
    static int[] dj = {0, 1, 0, -1};
    static char x;
    static Queue<Pos> q = new LinkedList<>();

    static class Pos {
        int i, j;

        Pos(int ii, int jj) {
            i = ii;
            j = jj;
        }
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        for (int i = 1; i <= n; i++) {
            String line = scanner.nextLine();
            for (int j = 1; j <= n; j++) {
                x = line.charAt(j - 1);
                a[i][j] = (x == '.') ? -1 : 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == -1) {
                    c++;
                    a[i][j] = c;
                    q.add(new Pos(i, j));
                    while (!q.isEmpty()) {
                        Pos t = q.poll();
                        for (int k = 0; k < 4; k++) {
                            if (a[t.i + di[k]][t.j + dj[k]] == -1) {
                                a[t.i + di[k]][t.j + dj[k]] = c;
                                q.add(new Pos(t.i + di[k], t.j + dj[k]));
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                out[a[i][j]]++;
            }
        }

        for (int addi = 0; addi <= n - k; addi++) {
            for (int i = addi + 1; i <= addi + k; i++) {
                for (int j = 0; j < k; j++) {
                    out[a[i][j]]--;
                }
            }
            for (int addj = 0; addj <= n - k; addj++) {
                ans = k * k;
                for (int i = addi + 1; i <= addi + k; i++) {
                    out[a[i][addj]]++;
                    out[a[i][addj + k]]--;
                }
                for (int i = addi + 1; i <= addi + k; i++) {
                    int p = a[i][addj];
                    if (p != 0 && chk[p] == 0) {
                        chk[p] = 1;
                        ans += out[p];
                    }
                    p = a[i][addj + k + 1];
                    if (p != 0 && chk[p] == 0) {
                        chk[p] = 1;
                        ans += out[p];
                    }
                }
                for (int j = addj + 1; j <= addj + k; j++) {
                    int p = a[addi][j];
                    if (p != 0 && chk[p] == 0) {
                        chk[p] = 1;
                        ans += out[p];
                    }
                    p = a[addi + k + 1][j];
                    if (p != 0 && chk[p] == 0) {
                        chk[p] = 1;
                        ans += out[p];
                    }
                }
                for (int i = addi + 1; i <= addi + k; i++) {
                    chk[a[i][addj]] = 0;
                    chk[a[i][addj + k + 1]] = 0;
                }
                for (int j = addj + 1; j <= addj + k; j++) {
                    chk[a[addi][j]] = 0;
                    chk[a[addi + k + 1][j]] = 0;
                }
                best = Math.max(best, ans);
            }
            for (int i = addi + 1; i <= addi + k; i++) {
                for (int j = n - k + 1; j <= n; j++) {
                    out[a[i][j]]++;
                }
            }
        }
        System.out.println(best);
    }

    static void prep() {
        // Preparation code if needed
    }

    public static void main(String[] args) {
        prep();
        solve();
    }
}
