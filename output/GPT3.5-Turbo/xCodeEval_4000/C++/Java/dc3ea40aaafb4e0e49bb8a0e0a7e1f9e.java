import java.util.*;

class Main {
    static final long INF = (long) 0x3f3f3f3f3f3f3f3fL;

    static class Matrix {
        long[][] mat;

        Matrix() {
            mat = new long[77][77];
            for (int i = 0; i < 77; i++) {
                for (int j = 0; j < 77; j++) {
                    mat[i][j] = INF;
                }
            }
        }

        Matrix multiply(Matrix ma) {
            Matrix mat2 = new Matrix();
            for (int i = 0; i < 77; i++) {
                for (int j = 0; j < 77; j++) {
                    for (int k = 0; k < 77; k++) {
                        mat2.mat[i][k] = Math.min(mat2.mat[i][k], mat[i][j] + ma.mat[j][k]);
                    }
                }
            }
            return mat2;
        }
    }

    static Matrix ksmii(Matrix x, int y) {
        if (y == 1) {
            return x;
        }
        Matrix mat2 = ksmii(x, y / 2);
        mat2 = mat2.multiply(mat2);
        if (y % 2 == 1) {
            mat2 = mat2.multiply(x);
        }
        return mat2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Matrix zyj = new Matrix();
        Matrix zyj2 = new Matrix();

        zyj2.mat[0][0] = 0;
        int x = sc.nextInt();
        int k = sc.nextInt();
        int n = sc.nextInt();
        int q = sc.nextInt();

        int[] c = new int[15];
        for (int i = 1; i <= k; i++) {
            c[i] = sc.nextInt();
        }

        int[] dy = new int[257];
        int cntdy = 0;
        int[] yd = new int[77];
        int[] p = new int[27];
        int[] wp = new int[27];
        Map<Integer, Integer> wpp = new HashMap<>();
        int[][] ws_ = new int[27][2];

        for (int i = 0; i < q; i++) {
            ws_[i][0] = sc.nextInt();
            ws_[i][1] = sc.nextInt();
        }
        Arrays.sort(ws_, (a, b) -> Integer.compare(a[0], b[0]));

        for (int i = 0; i < q; i++) {
            p[i] = ws_[i][0];
            wp[i] = ws_[i][1];
            wpp.put(p[i], wp[i]);
        }

        for (int i = 0; i < (1 << k); i++) {
            if (Integer.bitCount(i) == x) {
                yd[cntdy] = i;
                dy[i] = cntdy++;
            }
        }

        for (int ii = 0; ii < cntdy; ii++) {
            int j = yd[ii];
            if ((j & 1) != 0) {
                for (int l = 1; l <= k; l++) {
                    if ((j & (1 << l)) == 0) {
                        zyj.mat[ii][dy[(j + (1 << l)) >> 1]] = c[l];
                    }
                }
            } else {
                zyj.mat[ii][dy[j >> 1]] = 0;
            }
        }

        int nowpos = 1;
        for (int i = 0; i < q; i++) {
            int to = Math.min(n - x + 1, p[i] - k - 1);
            if (to - nowpos > 0) {
                zyj2 = zyj2.multiply(ksmii(zyj, to - nowpos));
            }

            Matrix nm = zyj;
            for (int j = Math.max(nowpos, to); j < Math.min(n - x + 1, p[i]); j++) {
                for (int ii = 0; ii < cntdy; ii++) {
                    int jj = yd[ii];
                    if ((jj & 1) != 0) {
                        for (int l = 1; l <= k; l++) {
                            if ((jj & (1 << l)) == 0) {
                                nm.mat[ii][dy[(jj + (1 << l)) >> 1]] += wpp.get(j + l);
                            }
                        }
                    }
                }
                zyj2 = zyj2.multiply(nm);
                nm = zyj;
            }
            nowpos = Math.min(n - x + 1, p[i]);
        }

        if (n - x + 1 - nowpos > 0) {
            zyj2 = zyj2.multiply(ksmii(zyj, n - x + 1 - nowpos));
        }

        System.out.println(zyj2.mat[0][0]);
    }
}
