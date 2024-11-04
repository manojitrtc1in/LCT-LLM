import java.util.Scanner;

public class 198e9a6433f704c67588cbb1142b4942xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String s = input.next();
        int a = 0, b = 0, c = 0;
        int[] d = new int[n];
        int[] e = new int[n];
        int[] g = new int[n];
        int[] h = new int[n];
        int[] l = new int[n];
        int[] p = new int[n];
        int[][][] f = new int[a + 1][b + 1][c + 1];

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                p[i] = p[i - 1];
                h[i] = h[i - 1];
                l[i] = l[i - 1];
            }
            if (s.charAt(i) == 'V') {
                d[a++] = i;
                h[i]++;
            } else if (s.charAt(i) == 'K') {
                e[b++] = i;
                l[i]++;
            } else {
                g[c++] = i;
                p[i]++;
            }
        }

        int[][][] minDist = new int[a + 1][b + 1][c + 1];
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int t = 0; t <= 1; t++) {
                        if (i < a) {
                            minDist[i + 1][j][k][1] = Math.min(minDist[i + 1][j][k][1], minDist[i][j][k][t] + Math.abs(l[d[i]] - j) + Math.abs(p[d[i]] - k));
                        }
                        if (j < b && t == 0) {
                            minDist[i][j + 1][k][0] = Math.min(minDist[i][j + 1][k][0], minDist[i][j][k][t] + Math.abs(h[e[j]] - i) + Math.abs(p[e[j]] - k));
                        }
                        if (k < c) {
                            minDist[i][j][k + 1][0] = Math.min(minDist[i][j][k + 1][0], minDist[i][j][k][t] + Math.abs(h[g[k]] - i) + Math.abs(l[g[k]] - j));
                        }
                    }
                }
            }
        }

        System.out.println(minDist[a][b][c][0] + minDist[a][b][c][1] / 2);
    }
}
