import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 11bf6f3417d5907d2e2ed3d1dff9c8a1xcodeeval_processed_4000.json {
    static final int MAXN = (int) 1e5 + 5, id0 = 20;
    static int N;
    static int[] R = new int[MAXN];
    static int[] ans = new int[MAXN];
    static SegmentTree_SAM_RQ[] T = new SegmentTree_SAM_RQ[id0];
    static Pair[] RANGE = new Pair[id0][MAXN * 3];

    static {
        for (int i = 0; i < id0; i++) {
            T[i] = new SegmentTree_SAM_RQ(3 * MAXN);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            R[i] = Integer.parseInt(st.nextToken());
        }
        if (N == 1) {
            System.out.println(0);
            return;
        }

        for (int j = 0; j < 3 * N; j++) {
            T[0].update(j, RANGE[0][j] = new Pair(Math.max(0, j - R[j % N]), Math.min(3 * N - 1, j + R[j % N])));
        }

        for (int i = 1; i < id0; i++) {
            for (int j = 0; j < 3 * N; j++) {
                T[i].update(j, RANGE[i][j] = T[i - 1].query(RANGE[i - 1][j].f, RANGE[i - 1][j].s));
            }
        }

        for (int i = 0; i < N; i++) {
            ans[i] = 1;
            Pair cur = new Pair(N + i, N + i);
            for (int j = id0 - 1; j >= 0; j--) {
                Pair nxt = T[j].query(cur.f, cur.s);
                if (nxt.s - nxt.f + 1 < N) {
                    ans[i] += 1 << j;
                    cur = nxt;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(ans[i]).append(" ");
        }
        System.out.println(sb.toString().trim());
    }

    static class Pair {
        int f, s;

        Pair(int f, int s) {
            this.f = f;
            this.s = s;
        }
    }

    static class SegmentTree_SAM_RQ {
        Pair[] T;
        Pair def = new Pair(Integer.MAX_VALUE, Integer.MIN_VALUE);
        Pair qdef = new Pair(Integer.MAX_VALUE, Integer.MIN_VALUE);
        int N;

        SegmentTree_SAM_RQ(int size) {
            T = new Pair[2 * size];
            Arrays.fill(T, def);
        }

        Pair merge(Pair l, Pair r) {
            return new Pair(Math.min(l.f, r.f), Math.max(l.s, r.s));
        }

        Pair applyVal(Pair l, Pair r) {
            return r;
        }

        void update(int i, Pair v) {
            for (i += N - 1; T[i] = applyVal(T[i], v); i >>= 1) {
                T[i] = merge(T[i << 1], T[i << 1 | 1]);
            }
        }

        void init(int size) {
            N = size;
            Arrays.fill(T, def);
        }

        Pair query(int l, int r) {
            Pair ql = qdef, qr = qdef;
            for (l += N - 1, r += N - 1; l <= r; l >>= 1, r >>= 1) {
                if (l % 2 == 1) ql = merge(ql, T[l++]);
                if (r % 2 == 0) qr = merge(T[r--], qr);
            }
            return merge(ql, qr);
        }
    }
}
