import java.io.*;
import java.util.*;

public class 339e7a8648fa4279b8a5a0675affaedbxcodeeval_processed_4000.json {
    static final int INF = Integer.MAX_VALUE;
    static final int __BS = 4096;
    static final long id10 = 1000000007;
    static Node[] nodes = new Node[101010 * 32];
    static Node lastn = new Node();
    static Node root;

    static class Node {
        Node lp;
        Node rp;
        long sum = 0;
        long minVal = 0;
        int s = 0;
        int free = 0;

        void update(int tl, int tr) {
            assert lp != null || rp != null;
            if (lp == null) {
                this.sum = rp.sum;
                this.minVal = rp.minVal;
                this.s = rp.s;
                this.free = rp.free;
                free += tl;
                return;
            }
            if (rp == null) {
                this.sum = lp.sum;
                this.minVal = lp.minVal;
                this.s = lp.s;
                this.free = lp.free;
                sum += lp.s * 1L * tr;
                minVal = Math.min(minVal, sum);
                return;
            }
            sum = lp.sum + rp.free * 1L * lp.s + rp.sum;
            minVal = Math.min(lp.minVal, lp.sum + rp.free * 1L * lp.s + rp.minVal);
            s = rp.s;
            free = lp.free;
        }
    }

    static void update(Node[] cur, int l, int r, int pos, int val) {
        if (cur[0] == null) {
            cur[0] = lastn;
            lastn = new Node();
        }
        if (l == r) {
            cur[0].s = val;
            cur[0].free = 0;
            cur[0].minVal = Math.min(0, cur[0].s);
            cur[0].sum = val;
        } else {
            int m = (l + r) / 2;
            if (pos <= m) {
                update(new Node[]{cur[0].lp}, l, m, pos, val);
            } else {
                update(new Node[]{cur[0].rp}, m + 1, r, pos, val);
            }
            cur[0].update(m - l + 1, r - m);
        }
    }

    static void del(Node[] cur, int l, int r, int pos) {
        if (l == r) {
            cur[0] = null;
        } else {
            int m = (l + r) / 2;
            if (pos <= m) {
                del(new Node[]{cur[0].lp}, l, m, pos);
            } else {
                del(new Node[]{cur[0].rp}, m + 1, r, pos);
            }
            if (cur[0].lp == null && cur[0].rp == null) {
                cur[0] = null;
                return;
            }
            cur[0].update(m - l + 1, r - m);
        }
    }

    static double ans = 1e20;

    static void getAns(Node cur, int l, int r, int x, int y, long[] v, int[] s) {
        if (y < l) return;
        if (x > r) return;

        if (cur == null || l == r) {
            if (cur != null) s[0] = cur.s;
            long tot = s[0] * (y - x + 1L);
            if (tot + v[0] > 0) {
                v[0] += tot;
                return;
            }
            ans = x + v[0] * 1.0 / -s[0];
            v[0] = 0;
            return;
        }
        int m = (l + r) / 2;
        if (x <= l && r <= y) {
            long minVal = cur.minVal + cur.free * 1L * s[0];

            if (minVal + v[0] > 0) {
                v[0] += cur.sum + cur.free * 1L * s[0];
                s[0] = cur.s;
                return;
            } else {
                getAns(cur.lp, l, m, x, m, v, s);
                if (v[0] == 0) return;
                getAns(cur.rp, m + 1, r, m + 1, y, v, s);
                return;
            }
        }
        if (x <= m) {
            getAns(cur.lp, l, m, x, Math.min(y, m), v, s);
            if (v[0] == 0) return;
        }
        getAns(cur.rp, m + 1, r, Math.max(x, m + 1), y, v, s);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            if (t == 1) {
                int w = Integer.parseInt(st.nextToken());
                int s = Integer.parseInt(st.nextToken());
                update(new Node[]{root}, 0, INF, w, s);
            } else if (t == 2) {
                int w = Integer.parseInt(st.nextToken());
                del(new Node[]{root}, 0, INF, w);
            } else {
                int l = Integer.parseInt(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
                long v = Long.parseLong(st.nextToken());

                ans = 1e20;
                if (v == 0) {
                    ans = l;
                }
                if (l < r && v != 0) {
                    int[] s = new int[1];
                    getAns(root, 0, INF, l, r - 1, new long[]{v}, s);
                }
                if (v != 0) {
                    out.println(-1);
                } else {
                    out.printf("%.8f\n", ans);
                }
            }
        }
        out.flush();
    }
}
