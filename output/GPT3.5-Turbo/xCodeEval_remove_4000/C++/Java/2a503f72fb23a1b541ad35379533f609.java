import java.util.*;
import java.io.*;

class Main {
    static final int INF = (int)1e9;
    static final int MAXN = 100;
    static final int MAXM = (int)1e6 + 9;

    static int[] D = new int[MAXN];
    static int[] hd = new int[MAXN];
    static int[] suc = new int[MAXM];
    static int[] to = new int[MAXM];
    static int[] cap = new int[MAXM];
    static int[] cst = new int[MAXM];
    static int n, m, s, t;
    static long flow, cost;
    static int mask = 65535;

    static void add_edge(int x, int y, int c, int w) {
        suc[m] = hd[x];
        to[m] = y;
        cap[m] = c;
        cst[m] = w;
        hd[x] = m++;
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
            add_edge(x, y, c, w);
            add_edge(y, x, c, w);
        }
    }

    static void id5(int x, int y, int c, int w) {
        id11(x, y, c, 0);
        id11(x, y, INF, w);
    }

    static boolean spfa() {
        int cz = 0, op = 1;
        boolean[] inQ = new boolean[n];
        Arrays.fill(inQ, false);
        Arrays.fill(D, INF);
        D[Q[cz] = s] = 0;
        F[s] = INF;
        while (cz < op) {
            int u = Q[cz++ & mask];
            inQ[u] = false;
            for (int i = hd[u]; i != -1; i = suc[i]) {
                int v = to[i], c = cap[i], w = cst[i];
