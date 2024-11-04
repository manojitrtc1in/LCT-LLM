import java.util.*;

public class dc3ea40aaafb4e0e49bb8a0e0a7e1f9excodeeval_processed_4000.json {
    static final int INF = Integer.MAX_VALUE;
    static final int MAX_SIZE = 77;
    static final int MAX_K = 15;
    static final int MAX_Q = 257;

    static class Matrix {
        long[][] mat = new long[MAX_SIZE][MAX_SIZE];

        Matrix() {
            for (int i = 0; i < MAX_SIZE; i++) {
                Arrays.fill(mat[i], INF);
            }
        }

        Matrix multiply(Matrix ma) {
            Matrix mat2 = new Matrix();
            for (int i = 0; i < MAX_SIZE; i++) {
                for (int j = 0; j < MAX_SIZE; j++) {
                    for (int k = 0; k < MAX_SIZE; k++) {
                        mat2.mat[i][k] = Math.min(mat2.mat[i][k], mat[i][j] + ma.mat[j][k]);
                    }
                }
            }
            return mat2;
        }
    }

    static Matrix id0(Matrix x, int y) {
        if (y == 1) return x;
        Matrix mat2 = id0(x, y / 2);
        mat2 = mat2.multiply(mat2);
        if (y % 2 != 0) mat2 = mat2.multiply(x);
        return mat2;
    }

    static Matrix zyj = new Matrix();
    static Matrix id1 = new Matrix();

    static int x, k, n, q;
    static int[] c = new int[MAX_K + 1];
    static int[] dy = new int[256];
    static int cntdy = 0;
    static int[] yd = new int[77];
    static int[] p = new int[27];
    static int[] wp = new int[27];
    static Map<Integer, Integer> wpp = new HashMap<>();
    static int[][] ws_ = new int[27][2];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        id1.mat[0][0] = 0;
        x = scanner.nextInt();
        k = scanner.nextInt();
        n = scanner.nextInt();
        q = scanner.nextInt();

        for (int i = 1; i <= k; i++) {
            c[i] = scanner.nextInt();
        }

        for (int i = 0; i < q; i++) {
            ws_[i][0] = scanner.nextInt();
            ws_[i][1] = scanner.nextInt();
        }

        Arrays.sort(ws_, 0, q, Comparator.comparingInt(a -> a[0]));

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
                    if ((j & (1 << (l - 1))) == 0) {
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
                id1 = id1.multiply(id0(zyj, to - nowpos));
            }

            Matrix nm = new Matrix();
            for (int j = 0; j < MAX_SIZE; j++) {
                System.arraycopy(zyj.mat[j], 0, nm.mat[j], 0, MAX_SIZE);
            }

            for (int j = Math.max(nowpos, to); j < Math.min(n - x + 1, p[i]); j++) {
                for (int ii = 0; ii < cntdy; ii++) {
                    int jj = yd[ii];
                    if ((jj & 1) != 0) {
                        for (int l = 1; l <= k; l++) {
                            if ((jj & (1 << (l - 1))) == 0) {
                                nm.mat[ii][dy[(jj + (1 << l)) >> 1]] += wpp.get(j + l);
                            }
                        }
                    }
                }
                id1 = id1.multiply(nm);
                nm = new Matrix();
                for (int j1 = 0; j1 < MAX_SIZE; j1++) {
                    System.arraycopy(zyj.mat[j1], 0, nm.mat[j1], 0, MAX_SIZE);
                }
            }
            nowpos = Math.min(n - x + 1, p[i]);
        }

        if (n - x + 1 - nowpos > 0) {
            id1 = id1.multiply(id0(zyj, n - x + 1 - nowpos));
        }

        System.out.println(id1.mat[0][0]);
        scanner.close();
    }
}
