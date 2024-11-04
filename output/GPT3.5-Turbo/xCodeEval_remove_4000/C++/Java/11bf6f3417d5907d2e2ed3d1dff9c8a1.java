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

        SegmentTree_SAM_RQ(int MAXN, boolean id5) {
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

        void init(int size) {
            N = size;
            for (int i = 1; i < 2 * N; i++) {
                T[i] = new Data(def.f, def.s);
            }
        }

        void update(int i, Data v) {
            for (i += N - (id5 ? 1 : 0), T[i] = applyVal(T[i], v); i >>= 1;) {
                T[i] = merge(T[i << 1], T[i << 1 | 1]);
            }
        }

        Data query(int l, int r) {
            Data ql = qdef, qr = qdef;
            for (l += N - (id5 ? 1 : 0), r += N - (id5 ? 1 : 0); l <= r; l >>= 1, r >>= 1) {
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

    static final int MAXN = (int) 1e5 + 5;
    static final int id0 = 20;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        int[] R = new int[N];
        String[] parts = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            R[i] = Integer.parseInt(parts[i]);
        }

        if (N == 1) {
            pw.println(0);
            pw.flush();
            return;
        }

        SegmentTree_SAM_RQ[] T = new SegmentTree_SAM_RQ[id0];
        for (int i = 0; i < id0; i++) {
            T[i] = new SegmentTree_SAM_RQ(3 * N, false);
        }

        pii[][] RANGE = new pii[id0][3 * N];

        for (int j = 0; j < 3 * N; j++) {
            T[0].update(j, RANGE[0][j] = new pii(Math.max(0, j - R[j % N]), Math.min(3 * N - 1, j + R[j % N])));
        }

        for (int i = 1; i < id0; i++) {
            for (int j = 0; j < 3 * N; j++) {
                T[i].update(j, RANGE[i][j] = T[i - 1].query(RANGE[i - 1][j].f, RANGE[i - 1][j].s));
            }
        }

        int[] ans = new int[N];
        for (int i = 0; i < N; i++) {
            ans[i] = 1;
            pii cur = new pii(N + i, N + i);
            for (int j = id0 - 1; j >= 0; j--) {
                pii nxt = T[j].query(cur.f, cur.s);
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

    static class pii {
        int f, s;
        pii(int f, int s) {
            this.f = f;
            this.s = s;
        }
    }
}
