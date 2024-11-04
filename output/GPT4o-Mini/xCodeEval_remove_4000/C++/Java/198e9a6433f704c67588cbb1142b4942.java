import java.util.Arrays;
import java.util.Scanner;

public class 198e9a6433f704c67588cbb1142b4942xcodeeval_processed_4000.json {
    static int n, a, b, c, d, e, g, h, l, p;
    static int[][][] f = new int[100][100][100];
    static char[] s = new char[100];

    static void mi(int[] a, int b) {
        a[0] = Math.min(a[0], b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        s = scanner.next().toCharArray();
        a = b = c = d = e = g = h = l = p = 0;

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                p = p;
                h = h;
                l = l;
            }
            if (s[i] == 'V') {
                d = a++;
                h++;
            }
            if (s[i] == 'K') {
                e = b++;
                l++;
            }
            g = c++;
            p++;
        }

        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    Arrays.fill(f[i][j], Integer.MAX_VALUE);
                }
            }
        }

        for (int i = 0; i < a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int t = 0; t <= 1; t++) {
                        if (i < a) {
                            mi(f[i + 1][j][k], f[i][j][k] + Math.abs(l - d) - j + Math.abs(p - d) - k);
                        }
                        if (j < b && t == 0) {
                            mi(f[i][j + 1][k], f[i][j][k] + Math.abs(h - e) - i + Math.abs(p - e) - k);
                        }
                        if (k < c) {
                            mi(f[i][j][k + 1], f[i][j][k] + Math.abs(h - g) - i + Math.abs(l - g) - j);
                        }
                    }
                }
            }
        }

        System.out.printf("%d\n", Math.min(f[a][b][c], f[a][b][c + 1]) / 2);
    }
}
