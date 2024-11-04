import java.util.*;

class Main {
    static final int INF = Integer.MAX_VALUE;
    static final int MASK(int k) { return (1 << k) - 1; }
    
    static class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    static class Matrix {
        int[][] mat;
        
        Matrix() {
            mat = new int[77][77];
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
    
    static Matrix id0(Matrix x, int y) {
        if (y == 1) return x;
        Matrix mat2 = id0(x, y / 2);
        mat2 = mat2.multiply(mat2);
        if (y % 2 == 1) mat2 = mat2.multiply(x);
        return mat2;
    }
    
    static Matrix zyj, id1;
    
    static int x, k, n, q;
    
    static int[] c;
    static int[] dy;
    static int cntdy;
    static int[] yd;
    static int[] p;
    static int[] wp;
    static Map<Integer, Integer> wpp;
    static Pair[] ws_;
    
    public static void main(String[] args) {
        id1 = new Matrix();
        id1.mat[0][0] = 0;
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();
        k = scanner.nextInt();
        n = scanner.nextInt();
        q = scanner.nextInt();
        c = new int[15];
        for (int i = 1; i <= k; i++) {
            c[i] = scanner.nextInt();
        }
        ws_ = new Pair[q];
        for (int i = 0; i < q; i++) {
            int first = scanner.nextInt();
            int second = scanner.nextInt();
            ws_[i] = new Pair(first, second);
        }
        Arrays.sort(ws_, (a, b) -> a.first - b.first);
        dy = new int[257];
        cntdy = 0;
        yd = new int[77];
        p = new int[27];
        wp = new int[27];
        wpp = new HashMap<>();
        for (int i = 0; i < q; i++) {
            p[i] = ws_[i].first;
            wp[i] = ws_[i].second;
            wpp.put(p[i], wp[i]);
        }
        for (int i = 0; i < MASK(k); i++) {
            if (Integer.bitCount(i) == x) {
                yd[cntdy] = i;
                dy[i] = cntdy++;
            }
        }
        zyj = new Matrix();
        for (int ii = 0; ii < cntdy; ii++) {
            int j = yd[ii];
            if ((j & 1) != 0) {
                for (int l = 1; l <= k; l++) {
                    if ((j & (1 << l)) == 0) {
                        zyj.mat[ii][dy[(j + MASK(l)) >> 1]] = c[l];
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
            Matrix nm = zyj;
            for (int j = Math.max(nowpos, to); j < Math.min(n - x + 1, p[i]); j++) {
                for (int ii = 0; ii < cntdy; ii++) {
                    int jj = yd[ii];
                    if ((jj & 1) != 0) {
                        for (int l = 1; l <= k; l++) {
                            if ((jj & (1 << l)) == 0) {
                                nm.mat[ii][dy[(jj + MASK(l)) >> 1]] += wpp.get(j + l);
                            }
                        }
                    }
                }
                id1 = id1.multiply(nm);
                nm = zyj;
            }
            nowpos = Math.min(n - x + 1, p[i]);
        }
        if (n - x + 1 - nowpos > 0) {
            id1 = id1.multiply(id0(zyj, n - x + 1 - nowpos));
        }
        System.out.println(id1.mat[0][0]);
    }
}
