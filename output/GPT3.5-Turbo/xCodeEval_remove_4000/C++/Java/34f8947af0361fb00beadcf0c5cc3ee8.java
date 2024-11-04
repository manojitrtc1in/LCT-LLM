import java.util.Scanner;

public class 34f8947af0361fb00beadcf0c5cc3ee8xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String s = input.next();

        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        int[] d = new int[2];

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                a[i] = a[i - 1];
                b[i] = b[i - 1];
                c[i] = c[i - 1];
            }

            if (s.charAt(i) == 'V') {
                d[0] = i;
                a[i]++;
            } else if (s.charAt(i) == 'K') {
                d[1] = i;
                b[i]++;
            } else {
                c[i]++;
            }
        }

        int[][][][] f = new int[a[n - 1] + 1][b[n - 1] + 1][c[n - 1] + 1][2];

        for (int i = 0; i <= a[n - 1]; i++) {
            for (int j = 0; j <= b[n - 1]; j++) {
                for (int k = 0; k <= c[n - 1]; k++) {
                    for (int t = 0; t <= 1; t++) {
                        if (i < a[n - 1]) {
                            f[i + 1][j][k][1] = Math.min(f[i + 1][j][k][1], f[i][j][k][t] + Math.abs(d[0] - j) + Math.abs(d[1] - k));
                        }
                        if (j < b[n - 1] && t == 0) {
                            f[i][j + 1][k][0] = Math.min(f[i][j + 1][k][0], f[i][j][k][t] + Math.abs(d[0] - i) + Math.abs(d[1] - k));
                        }
                        if (k < c[n - 1]) {
                            f[i][j][k + 1][0] = Math.min(f[i][j][k + 1][0], f[i][j][k][t] + Math.abs(d[0] - i) + Math.abs(d[1] - j));
                        }
                    }
                }
            }
        }

        System.out.println(Math.min(f[a[n - 1]][b[n - 1]][c[n - 1]][0], f[a[n - 1]][b[n - 1]][c[n - 1]][1]) / 2);
    }
}
