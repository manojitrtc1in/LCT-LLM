import java.util.*;
import java.io.*;

class Main {
    static final int N = 70;
    static int x, k, n, q;
    static int[] c = new int[N];
    static Pair[] a = new Pair[N];
    static int cnt;
    static long[][] num = new long[1 << 8][N];
    static long[][] cur = new long[N][N];

    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] line = br.readLine().split(" ");
            x = Integer.parseInt(line[0]);
            k = Integer.parseInt(line[1]);
            n = Integer.parseInt(line[2]);
            q = Integer.parseInt(line[3]);
            line = br.readLine().split(" ");
            for (int i = 0; i < k; i++) {
                c[i] = Integer.parseInt(line[i]);
            }
            for (int i = 0; i < q; i++) {
                line = br.readLine().split(" ");
                a[i] = new Pair(Integer.parseInt(line[0]), Integer.parseInt(line[1]));
                a[i].x--;
            }
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    static long[][] multiply(long[][] a, long[][] b) {
        long[][] c = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                c[i][j] = Long.MAX_VALUE;
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
                res[i][j] = i == j ? 0 : Long.MAX_VALUE;
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

    static long[][] get(int pos, int[] mx) {
        mx[0] = n - x - pos;
        int[] pr = new int[k];
        for (int i = 0; i < q; i++) {
            if (pos < a[i].x) {
                if (a[i].x <= pos + k) {
                    pr[a[i].x - pos - 1] = a[i].y;
                    mx[0] = 1;
                } else {
                    mx[0] = Math.min(mx[0], a[i].x - (pos + k));
                }
            }
        }
        long[][] res = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                res[i][j] = Long.MAX_VALUE;
            }
        }
        for (int mask = 0; mask < (1 << k); mask++) {
            if (Integer.bitCount(mask) == x) {
                if ((mask & 1) == 1) {
                    for (int i = 1; i <= k; i++) {
                        if (((mask >> i) & 1) == 0) {
                            res[(int) num[mask]][(int) num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1];
                        }
                    }
                } else {
                    res[(int) num[mask]][(int) num[mask >> 1]] = 0;
                }
            }
        }
        return res;
    }

    static void solve() {
        cnt = 0;
        for (int mask = 0; mask < (1 << k); mask++) {
            if (Integer.bitCount(mask) == x) {
                num[mask][0] = cnt++;
            }
        }

        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                cur[i][j] = i == j ? 0 : Long.MAX_VALUE;
            }
        }
        Arrays.sort(a, 0, q, (p1, p2) -> p1.x - p2.x);
        for (int i = 0; i < n - x;) {
            int[] mx = new int[1];
            long[][] tmp = get(i, mx);
            i += mx[0];
            cur = multiply(cur, binpow(tmp, mx[0]));
        }

        System.out.println(cur[0][0]);
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                StringTokenizer st = new StringTokenizer(line);
                x = Integer.parseInt(st.nextToken());
                k = Integer.parseInt(st.nextToken());
                n = Integer.parseInt(st.nextToken());
                q = Integer.parseInt(st.nextToken());
                st = new StringTokenizer(br.readLine());
                for (int i = 0; i < k; i++) {
                    c[i] = Integer.parseInt(st.nextToken());
                }
                for (int i = 0; i < q; i++) {
                    st = new StringTokenizer(br.readLine());
                    a[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                    a[i].x--;
                }
                solve();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
