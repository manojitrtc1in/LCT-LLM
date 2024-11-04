import java.util.*;
import java.io.*;

class Main {
    static final int N = 70;
    static int x, k, n, q;
    static int[] c = new int[N];
    static int[][] a = new int[N][2];

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] input = br.readLine().split(" ");
            x = Integer.parseInt(input[0]);
            k = Integer.parseInt(input[1]);
            n = Integer.parseInt(input[2]);
            q = Integer.parseInt(input[3]);

            input = br.readLine().split(" ");
            for (int i = 0; i < k; i++) {
                c[i] = Integer.parseInt(input[i]);
            }

            for (int i = 0; i < q; i++) {
                input = br.readLine().split(" ");
                a[i][0] = Integer.parseInt(input[0]);
                a[i][1] = Integer.parseInt(input[1]);
                a[i][0]--;
            }

            return true;
        } catch (Exception e) {
            return false;
        }
    }

    static class Pair<A, B> {
        A x;
        B y;

        Pair(A x, B y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static <A, B> String toString(Pair<A, B> a) {
        return a.toString();
    }

    static <A> String toString(ArrayList<A> v) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < v.size(); i++) {
            if (i > 0)
                sb.append(", ");
            sb.append(v.get(i));
        }
        sb.append("]");
        return sb.toString();
    }

    static Random rnd = new Random();

    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = INF + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);

    static int cnt;

    static long[][] multiply(long[][] a, long[][] b) {
        long[][] c = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                c[i][j] = INF64;
            }
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                for (int k = 0; k < cnt; k++) {
                    c[i][j] = Math.min(c[i][j], a[i][k] + b[k][j]);
                }
            }
        }
        return c;
    }

    static long[][] binpow(long[][] a, int b) {
        long[][] res = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                res[i][j] = i == j ? 0 : INF64;
            }
        }
        while (b > 0) {
            if ((b & 1) == 1) {
                res = multiply(res, a);
            }
            a = multiply(a, a);
            b >>= 1;
        }
        return res;
    }

    static int[] num = new int[1 << 8];

    static long[][] get(int pos, int[] mx) {
        mx[0] = n - x - pos;
        int[] pr = new int[k];
        for (int i = 0; i < q; i++) {
            if (pos < a[i][0]) {
                if (a[i][0] <= pos + k) {
                    pr[a[i][0] - pos - 1] = a[i][1];
                    mx[0] = 1;
                } else {
                    mx[0] = Math.min(mx[0], a[i][0] - (pos + k));
                }
            }
        }
        long[][] res = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                res[i][j] = INF64;
            }
        }
        for (int mask = 0; mask < (1 << k); mask++) {
            if (Integer.bitCount(mask) == x) {
                if ((mask & 1) == 1) {
                    for (int i = 1; i <= k; i++) {
                        if (((mask >> i) & 1) == 0) {
                            res[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1];
                        }
                    }
                } else {
                    res[num[mask]][num[mask >> 1]] = 0;
                }
            }
        }
        return res;
    }

    static void solve() {
        cnt = 0;
        for (int mask = 0; mask < (1 << k); mask++) {
            if (Integer.bitCount(mask) == x) {
                num[mask] = cnt++;
            }
        }

        long[][] cur = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                cur[i][j] = i == j ? 0 : INF64;
            }
        }
        Arrays.sort(a, 0, q, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) {
                    return a[0] - b[0];
                }
                return a[1] - b[1];
            }
        });
        for (int i = 0; i < n - x;) {
            int[] mx = new int[1];
            long[][] tmp = get(i, mx);
            i += mx[0];
            cur = multiply(cur, binpow(tmp, mx[0]));
        }

        System.out.println(cur[0][0]);
    }

    public static void main(String[] args) throws Exception {
        // Uncomment the below line to read from input.txt
        // System.setIn(new FileInputStream("input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (read()) {
            solve();
        }
    }
}
