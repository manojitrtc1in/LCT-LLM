import java.util.Arrays;
import java.util.Scanner;

public class 198e9a6433f704c67588cbb1142b4942_nc {
    static final int N = 84;
    static int n, a, b, c, d, e, g, h, l, p;
    static char[] s = new char[N];
    static int[][][][] f = new int[N][N][N][2];

    static void mi(int[] a, int b) {
        a[0] = Math.min(a[0], b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        s = sc.next().toCharArray();

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                p[i] = p[i - 1] - 1;
                h[i] = h[i - 1] - 1;
                l[i] = l[i - 1] - 1;
            }

            if (s[i] == 'V') {
                d[a++] = i;
                h[i]++;
            } else if (s[i] == 'K') {
                e[b++] = i;
                l[i]++;
            } else {
                g[c++] = i;
                p[i]++;
            }
        }

        int INF = (int) 1e9;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    Arrays.fill(f[i][j][k], INF);
                }
            }
        }

        int[][][] pos = new int[a + 1][b + 1][c + 1];
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int t = 0; t <= 1; t++) {
                        if (i < a) {
                            mi(f[i + 1][j][k][1], f[i][j][k][t] + Math.abs(l[d[i]] - j) + Math.abs(p[d[i]] - k));
                        }
                        if (j < b && t == 0) {
                            mi(f[i][j + 1][k][0], f[i][j][k][t] + Math.abs(h[e[j]] - i) + Math.abs(p[e[j]] - k));
                        }
                        if (k < c) {
                            mi(f[i][j][k + 1][0], f[i][j][k][t] + Math.abs(h[g[k]] - i) + Math.abs(l[g[k]] - j));
                        }
                    }
                }
            }
        }

        System.out.println(Math.min(f[a][b][c][0], f[a][b][c][1]) / 2);
    }
}
