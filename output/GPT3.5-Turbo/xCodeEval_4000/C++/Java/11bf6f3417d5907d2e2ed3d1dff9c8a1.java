import java.io.*;
import java.util.*;

class Main {
    static class SegmentTree_SAM_RQ {
        static class Data {
            int f, s;
            Data(int f, int s) {
                this.f = f;
                this.s = s;
            }
        }

        int N;
        Data[] T;
        final Data def = new Data(Integer.MAX_VALUE, -Integer.MAX_VALUE);
        final Data qdef = new Data(Integer.MAX_VALUE, -Integer.MAX_VALUE);

        SegmentTree_SAM_RQ(int MAXN, boolean ONE_INDEXED) {
            N = MAXN;
            T = new Data[2 * N];
            for (int i = 0; i < 2 * N; i++) {
                T[i] = new Data(def.f, def.s);
            }
        }

        Data merge(Data l, Data r) {
            return new Data(Math.min(l.f, r.f), Math.max(l.s, r.s));
        }

        Data applyVal(Data l, Data r) {
            return r;
        }

        void init(int[] arr) {
            for (int i = 0; i < N; i++) {
                T[N + i] = new Data(arr[i].f, arr[i].s);
            }
            for (int i = N - 1; i > 0; i--) {
                T[i] = merge(T[i << 1], T[i << 1 | 1]);
            }
        }

        void update(int i, Data v) {
            for (i += N - 1; i > 0; i >>= 1) {
                T[i] = applyVal(T[i], v);
            }
        }

        Data query(int l, int r) {
            Data ql = qdef, qr = qdef;
            for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
                if ((l & 1) == 1) {
                    ql = merge(ql, T[l++]);
                }
                if ((r & 1) == 0) {
                    qr = merge(T[r--], qr);
                }
            }
            return merge(ql, qr);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int MAXN = 100005, MAXLGN = 20;
        int N = Integer.parseInt(br.readLine());
        int[] R = new int[N];
        int[] ans = new int[N];
        SegmentTree_SAM_RQ[] T = new SegmentTree_SAM_RQ[MAXLGN];
        SegmentTree_SAM_RQ.Data[][] RANGE = new SegmentTree_SAM_RQ.Data[MAXLGN][3 * MAXN];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            R[i] = Integer.parseInt(st.nextToken());
        }

        if (N == 1) {
            pw.println(0);
            pw.flush();
            return;
        }

        for (int i = 0; i < MAXLGN; i++) {
            T[i] = new SegmentTree_SAM_RQ(3 * N, false);
        }

        for (int j = 0; j < 3 * N; j++) {
            T[0].update(j, RANGE[0][j] = new SegmentTree_SAM_RQ.Data(Math.max(0, j - R[j % N]), Math.min(3 * N - 1, j + R[j % N])));
        }

        for (int i = 1; i < MAXLGN; i++) {
            for (int j = 0; j < 3 * N; j++) {
                T[i].update(j, RANGE[i][j] = T[i - 1].query(RANGE[i - 1][j].f, RANGE[i - 1][j].s));
            }
        }

        for (int i = 0; i < N; i++) {
            ans[i] = 1;
            SegmentTree_SAM_RQ.Data cur = new SegmentTree_SAM_RQ.Data(N + i, N + i);
            for (int j = MAXLGN - 1; j >= 0; j--) {
                SegmentTree_SAM_RQ.Data nxt = T[j].query(cur.f, cur.s);
                if (nxt.s - nxt.f + 1 < N) {
                    ans[i] += 1 << j;
                    cur = nxt;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            pw.print(ans[i] + " ");
        }
        pw.println();
        pw.flush();
    }
}
