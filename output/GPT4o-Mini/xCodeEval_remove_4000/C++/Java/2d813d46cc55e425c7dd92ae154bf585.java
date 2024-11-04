import java.util.*;

class Scanner {
    private final java.util.Scanner scanner;

    public Scanner() {
        scanner = new java.util.Scanner(System.in);
    }

    public void nextBoolean(boolean[] var) {
        var[0] = scanner.nextInt() != 0;
    }

    public void nextInt(int[] var) {
        var[0] = scanner.nextInt();
    }

    public void nextLong(long[] var) {
        var[0] = scanner.nextLong();
    }

    public void nextDouble(double[] var) {
        var[0] = scanner.nextDouble();
    }

    public void nextChar(char[] var) {
        var[0] = scanner.next().charAt(0);
    }

    public void nextString(String[] var) {
        var[0] = scanner.next();
    }
}

class Printer {
    public void print(boolean var) {
        System.out.print(var ? 1 : 0);
    }

    public void print(int var) {
        System.out.print(var);
    }

    public void print(long var) {
        System.out.print(var);
    }

    public void print(double var) {
        System.out.print(var);
    }

    public void print(char var) {
        System.out.print(var);
    }

    public void print(String var) {
        System.out.print(var);
    }
}

public class 2d813d46cc55e425c7dd92ae154bf585xcodeeval_processed_4000.json {
    static int n, k, p, c = 0, ans, best = 0;
    static int[][] a = new int[505][505];
    static int[] out = new int[125005];
    static boolean[] chk = new boolean[125005];
    static char x;
    static int[] di = {1, 0, -1, 0};
    static int[] dj = {0, 1, 0, -1};
    static Queue<Pos> q = new LinkedList<>();

    static class Pos {
        int i, j;

        Pos(int ii, int jj) {
            i = ii;
            j = jj;
        }
    }

    public static void solve() {
        Scanner scanner = new Scanner();
        scanner.nextInt(new int[]{n});
        scanner.nextInt(new int[]{k});

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanner.nextChar(new char[]{x});
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
                for (int j = 0; j < k - 1; j++) {
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
                    if (p != 0 && !chk[p]) {
                        chk[p] = true;
                        ans += out[p];
                    }
                    p = a[i][addj + k + 1];
                    if (p != 0 && !chk[p]) {
                        chk[p] = true;
                        ans += out[p];
                    }
                }
                for (int j = addj + 1; j < addj + k; j++) {
                    int p = a[addi][j];
                    if (p != 0 && !chk[p]) {
                        chk[p] = true;
                        ans += out[p];
                    }
                    p = a[addi + k + 1][j];
                    if (p != 0 && !chk[p]) {
                        chk[p] = true;
                        ans += out[p];
                    }
                }
                for (int i = addi + 1; i <= addi + k; i++) {
                    chk[a[i][addj]] = false;
                    chk[a[i][addj + k + 1]] = false;
                }
                for (int j = addj + 1; j < addj + k; j++) {
                    chk[a[addi][j]] = false;
                    chk[a[addi + k + 1][j]] = false;
                }
                best = Math.max(best, ans);
            }
            for (int i = addi + 1; i <= addi + k; i++) {
                for (int j = n - k + 1; j <= n; j++) {
                    out[a[i][j]]++;
                }
            }
        }
        Printer printer = new Printer();
        printer.print(best);
    }

    public static void main(String[] args) {
        solve();
    }
}
