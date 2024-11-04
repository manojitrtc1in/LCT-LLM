import java.util.*;
import java.io.*;

public class 2a503f72fb23a1b541ad35379533f609xcodeeval_processed_4000.json {
    static final int N = 65536, M = (int) (1e6) + 9;
    static int[] D = new int[N], hd = new int[N], suc = new int[M], to = new int[M], cap = new int[M], cst = new int[M];
    static int n, m, s, t;
    static long flow, cost;
    static int mask = 65535;
    static final int INF = Integer.MAX_VALUE;

    static void addEdge(int x, int y, int c, int w) {
        suc[m] = hd[x];
        to[m] = y;
        cap[m] = c;
        cst[m] = w;
        hd[x] = m++;
        suc[m] = hd[y];
        to[m] = x;
        cap[m] = 0;
        cst[m] = -w;
        hd[y] = m++;
    }

    static void id11(int x, int y, int c, int w) {
        if (w == 0) {
            suc[m] = hd[x];
            to[m] = y;
            cap[m] = c;
            cst[m] = 0;
            hd[x] = m++;
            suc[m] = hd[y];
            to[m] = x;
            cap[m] = c;
            cst[m] = 0;
            hd[y] = m++;
        } else {
            addEdge(x, y, c, w);
            addEdge(y, x, c, w);
        }
    }

    static void id5(int x, int y, int c, int w) {
        id11(x, y, c, 0);
        id11(x, y, INF, w);
    }

    static int[] Q = new int[N], F = new int[N], pre = new int[N];
    static int cz, op;
    static boolean[] inQ = new boolean[N];

    static boolean spfa() {
        cz = 0;
        op = 1;
        Arrays.fill(inQ, false);
        Arrays.fill(D, INF);
        D[Q[cz] = s] = 0;
        F[s] = INF;

        while (cz < op) {
            int u = Q[cz++ & mask];
            inQ[u] = false;

