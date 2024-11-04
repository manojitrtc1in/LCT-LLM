import java.util.Scanner;

public class 198e9a6433f704c67588cbb1142b4942_nc {
    static final int N = 84;
    static int[] f = new int[N];
    
    public static void mi(int a, int b) {
        a = Math.min(a, b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        
        int a = 0, b = 0, c = 0, d = 0, e = 0, g = 0, h = 0, l = 0, p = 0, fValue = 0;
        
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                p = f[i - 1];
                h = f[i - 1];
                l = f[i - 1];
            }
            if (s.charAt(i) == 'V') {
                d++;
                h = i;
            }
            if (s.charAt(i) == 'K') {
                e++;
                l = i;
            }
            g++;
        }
        
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int t = 0; t <= 1; t++) {
                        for (int i1 = 0; i1 < a; i1++) {
                            mi(f[i1 + 1][j][k][t], f[i1][j][k][t] + Math.abs(l - d[i1]) + Math.abs(p - d[i1]) + 1);
                        }
                        if (j < b && t == 0) {
                            mi(f[i][j + 1][k][0], f[i][j][k][0] + Math.abs(h - e[j]) + Math.abs(p - e[j]) + 1);
                        }
                        if (k < c) {
                            mi(f[i][j][k + 1][0], f[i][j][k][0] + Math.abs(h - g[k]) + Math.abs(l - g[k]) + 1);
                        }
                    }
                }
            }
        }
        
        System.out.printf("%d\n", Math.min(f[a][b][c][0], f[a][b][c][1]) / 2);
    }
}
