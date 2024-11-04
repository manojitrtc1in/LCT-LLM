import java.util.Scanner;

public class 34f8947af0361fb00beadcf0c5cc3ee8_nc {
    static final int N = 84;
    static int[] f = new int[N];
    static int n, a, b, c, d, e, g, h, l, p;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        String s = scanner.next();
        
        a = b = c = d = e = g = h = l = p = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'V') {
                d++;
                a = i;
                h++;
            }
            if (s.charAt(i) == 'K') {
                e++;
                b = i;
                l++;
            }
            if (s.charAt(i) == 'H') {
                g++;
                c = i;
                p++;
            }
        }

        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int t = 0; t <= 1; t++) {
                        if (i < a) {
                            min(f[i + 1][j][k][t], f[i][j][k][t] + Math.abs(l - d - i) + Math.abs(p - d - j));
                        }
                        if (j < b && !t) {
                            min(f[i][j + 1][k][t], f[i][j][k][0] + Math.abs(h - e - j) + Math.abs(p - e - i));
                        }
                        if (k < c) {
                            min(f[i][j][k + 1][t], f[i][j][k][0] + Math.abs(h - g - k) + Math.abs(l - g - j));
                        }
                    }
                }
            }
        }

        System.out.printf("%d\n", Math.min(f[a][b][c][0], f[a][b][c][1]) / 2);
    }

    static void min(int a, int b) {
        return Math.min(a, b);
    }
}
