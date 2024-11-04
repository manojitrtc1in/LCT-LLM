import java.util.*;
import java.io.*;

public class dc3ea40aaafb4e0e49bb8a0e0a7e1f9e_nc {
    static final long INF = 0x3f3f3f3f3f3f3f3fL;
    static final int MAX = 77;
    static final int MAX_C = 15;
    static final int MAX_Q = 27;
    
    static class Matrix {
        long[][] mat = new long[MAX][MAX];

        Matrix() {
            for (int i = 0; i < MAX; i++)
                Arrays.fill(mat[i], INF);
        }

        Matrix multiply(Matrix ma) {
            Matrix mat2 = new Matrix();
            for (int i = 0; i < MAX; i++)
                for (int j = 0; j < MAX; j++)
                    for (int k = 0; k < MAX; k++)
                        mat2.mat[i][k] = Math.min(mat2.mat[i][k], mat[i][j] + ma.mat[j][k]);
            return mat2;
        }
    }

    static Matrix ksmii(Matrix x, int y) {
        if (y == 1) return x;
        Matrix mat2 = ksmii(x, y / 2);
        mat2 = mat2.multiply(mat2);
        if (y % 2 != 0) mat2 = mat2.multiply(x);
        return mat2;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        Matrix zyj = new Matrix();
        Matrix zyj2 = new Matrix();
        zyj2.mat[0][0] = 0;

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int[] c = new int[MAX_C];
        for (int i = 1; i <= k; i++)
            c[i] = Integer.parseInt(br.readLine());

        Pair[] ws = new Pair[q];
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            ws[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(ws);
        int[] p = new int[q];
        int[] wp = new int[q];
        Map<Integer, Integer> wpp = new HashMap<>();

        for (int i = 0; i < q; i++) {
            p[i] = ws[i].first;
            wp[i] = ws[i].second;
            wpp.put(p[i], wp[i]);
        }

        int[] yd = new int[257];
        int cntdy = 0;
        for (int i = 0; i < (1 << k); i++) {
            if (Integer.bitCount(i) == x) {
                yd[cntdy] = i;
                cntdy++;
            }
        }

        for (int ii = 0; ii < cntdy; ii++) {
            int j = yd[ii];
            if ((j & 1) != 0) {
                for (int l = 1; l <= k; l++) {
                    if ((j & (1 << l)) == 0) {
                        zyj.mat[ii][Integer.bitCount(j) >> 1] = c[l];
                    }
                }
            } else {
                zyj.mat[ii][Integer.bitCount(j) >> 1] = 0;
            }
        }

        int nowpos = 1;
        for (int i = 0; i < q; i++) {
            int to = Math.min(n - x + 1, p[i] - k - 1);
            if (to - nowpos > 0) zyj2 = zyj2.multiply(ksmii(zyj, to - nowpos));

            Matrix nm = zyj;
            for (int j = Math.max(nowpos, to); j < Math.min(n - x + 1, p[i]); j++) {
                for (int ii = 0; ii < cntdy; ii++) {
                    int jj = yd[ii];
                    if ((jj & 1) != 0) {
                        for (int l = 1; l <= k; l++) {
                            if ((jj & (1 << l)) == 0) {
                                nm.mat[ii][Integer.bitCount(jj) >> 1] += wpp.get(j + l);
                            }
                        }
                    }
                }
                zyj2 = zyj2.multiply(nm);
                nm = zyj;
            }
            nowpos = Math.min(n - x + 1, p[i]);
        }

        if (n - x + 1 - nowpos > 0) zyj2 = zyj2.multiply(ksmii(zyj, n - x + 1 - nowpos));

        System.out.println(zyj2.mat[0][0]);
    }

    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return Integer.compare(this.first, o.first);
        }
    }
}
