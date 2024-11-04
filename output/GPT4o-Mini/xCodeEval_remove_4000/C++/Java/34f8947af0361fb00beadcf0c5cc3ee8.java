import java.util.Scanner;

public class 34f8947af0361fb00beadcf0c5cc3ee8xcodeeval_processed_4000.json {
    static int n, a, b, c, d, e, g, h, l, p, f[][][] = new int[100][100][100];
    static char[] s = new char[100];

    static void mi(int a, int b) {
        a = Math.min(a, b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        s = scanner.next().toCharArray();
        
        int i, j;
        for (i = 0; i < n; i++) {
            if (i != 0) {
                p[i] = p[i - 1];
                h[i] = h[i - 1];
                l[i] = l[i - 1];
            }
            if (s[i] == 'V') {
                d = a++;
                h[i]++;
            } else if (s[i] == 'K') {
                e = b++;
                l[i]++;
            } else {
                g = c++;
                p[i]++;
            }
        }

        for (i = 0; i <= a; i++) {
            for (j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int t = 0; t <= 1; t++) {
                        if (i < a) {
                            mi(f[i + 1][j][k][1], f[i][j][k][t] + Math.abs(l[d][i] - j) + Math.abs(p[d][i] - k));
                        }
                        if (j < b && t == 0) {
                            mi(f[i][j + 1][k][0], f[i][j][k][t] + Math.abs(h[e][j] - i) + Math.abs(p[e][j] - k));
                        }
                        if (k < c) {
                            mi(f[i][j][k + 1][0], f[i][j][k][t] + Math.abs(h[g][k] - i) + Math.abs(l[g][k] - j));
                        }
                    }
                }
            }
        }

        System.out.printf("%d\n", Math.min(f[a][b][c][0], f[a][b][c][1]) / 2);
    }
}
