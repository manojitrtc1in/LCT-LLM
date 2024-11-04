import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.util.Comparator.*;

public class Main {
    FastScanner in;
    PrintWriter out;
    ArrayList<Integer>[] graph;
    ArrayList<GraphPair>[] weightedGraph;
    long mod = 998_244_353L; 

    boolean multitests = false;

    private void solve() throws IOException {
        

        

        

        

        solveC_check();
        

        

        

        

        

        

        

        

        


        

        

        

        

    }

    private void solveA() throws IOException {
        int a1 = in.nextInt(), a2 = in.nextInt(), k1 = in.nextInt(), k2 = in.nextInt();
        int n = in.nextInt();
        if (k1 > k2) {
            int a = a1;
            a1 = a2;
            a2 = a;
            int k = k1;
            k1 = k2;
            k2 = k;
        }

        int max_k1 = min(n / k1, a1), max_k2 = min((n - max_k1 * k1) / k2, a2);
        out.print(max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)) + " " + (max_k1 + max_k2));
    }

    boolean[] colored, interes;
    int[] haveCol;

    private void solveB() throws IOException {
        int n = in.nextInt(), k = in.nextInt();
        colored = new boolean[n];
        for (int i = 0; i < k; i++)
            colored[in.nextInt() - 1] = true;

        interes = new boolean[n];
        haveCol = new int[n];
        graph = in.nextGraph(n, n - 1, false);

        dfs(0, -1);
        dfs2(0, -1, false);

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (interes[i])
                cnt++;

        out.println(cnt);
        for (int i = 0; i < n; i++)
            if (interes[i])
                out.print(i + 1 + " ");
    }

    private void dfs(int v, int p) {
        haveCol[v] = colored[v] ? 1 : 0;
        for (int u : graph[v]) {
            if (u != p) {
                dfs(u, v);
                haveCol[v] += haveCol[u] > 0 ? 1 : 0;
            }
        }
    }

    private void dfs2(int v, int p, boolean up) {
        interes[v] = !colored[v] && graph[v].size() - (p == -1 ? 0 : 1) == haveCol[v] && (p == -1 || up);
        for (int u : graph[v]) {
            if (u != p) {
                dfs2(u, v, up || colored[v] || haveCol[v] > 1 || (haveCol[v] == 1 && haveCol[u] == 0));
            }
        }
    }

    private long solveC(int nn, int[] aa) throws IOException {
        int n = nn, m = 0;
        int[] a = copyOf(aa, n);

        for (int x = 1; x <= 20; x++) {
            boolean have = false;
            for (int i = 0; i < n && !have; i++)
                have = a[i] == x;

            if (have) {
                for (int i = 0; i < n; i++)
                    if (a[i] == x)
                        a[i] = m;
                m++;
            }
        }

        long[][] cntSuff = new long[m][n];
        for (int i = 0; i < m; i++) {
            cntSuff[i][n - 1] = a[n - 1] == i ? 1 : 0;
            for (int j = n - 2; j >= 0; j--)
                cntSuff[i][j] = cntSuff[i][j + 1] + (a[j] == i ? 1 : 0);
        }

        long[][] ansSuff = new long[m][n];
        for (int i = 0; i < m; i++) {
            ansSuff[i][n - 1] = 0;
            for (int j = n - 2; j >= 0; j--)
                ansSuff[i][j] = ansSuff[i][j + 1] + (a[j] == i ? 0 : cntSuff[i][j + 1]);
        }

        long[][][] minusAnsSuff = new long[m][m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                minusAnsSuff[i][j][n - 1] = 0;
                for (int k = n - 2; k >= 0; k--) {
                    minusAnsSuff[i][j][k] = minusAnsSuff[i][j][k + 1] + (a[k] != j ? 0 : cntSuff[i][k + 1]);
                }
            }
        }

        long[] ans = new long[1 << m];
        fill(ans, (long) 25e17 / 1613);
        ans[0] = 0;

        for (int mask = 0; mask < (1 << m); mask++) {
            for (int next = 0; next < m; next++) {
                if ((mask & (1 << next)) == 0) {

                    int minus = 0;
                    for (int del = 0; del < m; del++)
                        if ((mask & (1 << del)) > 0)
                            minus += minusAnsSuff[next][del][0];

                    ans[mask | (1 << next)] = min(ans[mask | (1 << next)], ans[mask] + ansSuff[next][0] - minus);
                }
            }
        }

        return ans[(1 << m) - 1];
    }

    private long solveC_right(int nn, int[] aa) throws IOException {
        final int M = 20 + 1;
        final long INF = 1000L * 1000 * 1000 * 1000 * 1000 * 1000;

        long[] d = new long[1 << M];
        long[][] cnt = new long[M][M];
        ArrayList<Integer>[] col = new ArrayList[M];
        for (int i = 0; i < M; i++)
            col[i] = new ArrayList<>();

        int n = nn;
        for (int i = 0; i < n; i++)
            col[aa[i] - 1].add(i);

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == j || col[i].size() == 0 || col[j].size() == 0)
                    continue;

                int pos2 = 0;
                for (int pos1 = 0; pos1 < col[i].size(); pos1++) {
                    while (true) {
                        if (pos2 == col[j].size() - 1 || col[j].get(pos2 + 1) > col[i].get(pos1))
                            break;

                        pos2++;
                    }
                    if (col[i].get(pos1) > col[j].get(pos2)) {
                        cnt[i][j] += pos2 + 1;
                    }
                }
            }
        }

        for (int mask = 0; mask < (1 << 20); mask++) {
            d[mask] = INF;
        }
        d[0] = 0;
        for (int mask = 0; mask < (1 << 20); mask++) {
            ArrayList<Integer> was = new ArrayList<>();
            for (int i = 0; i < 20; i++) {
                if ((mask & (1 << i)) > 0) {
                    was.add(i);
                }
            }
            for (int i = 0; i < 20; i++) {
                if ((mask & (1 << i)) > 0)
                    continue;

                long sum = 0;
                for (int j = 0; j < was.size(); j++) {
                    sum += cnt[was.get(j)][i];
                }
                int nmask = mask | (1 << i);
                d[nmask] = min(d[nmask], d[mask] + sum);
            }
        }
        return d[(1 << 20) - 1];
    }

    private void solveC_check() throws IOException {
        

        int n = in.nextInt();
        int[] a = in.nextIntArray(n);
        out.println(solveC_right(n, a));
    }

    private void solveD() throws IOException {
        int n = in.nextInt();
        char[] s = in.next().toCharArray();

        int[] sum = new int[2], cnt = new int[2];
        for (int i = 0; i < n; i++)
            if (s[i] != '?')
                sum[i / (n / 2)] += s[i] - '0';
            else
                cnt[i / (n / 2)]++;

        if (sum[0] + (cnt[0] + 1) / 2 * 9 > sum[1] + (cnt[1] + cnt[0] % 2) / 2 * 9)
            out.println("Monocarp");
        else if (sum[1] + (cnt[1] + 1) / 2 * 9 > sum[0] + (cnt[0] + cnt[1] % 2) / 2 * 9)
            out.println("Monocarp");
        else
            out.println("Bicarp");
    }

    class Type {
        int color, cnt;

        Type(int color, int cnt) {
            this.color = color;
            this.cnt = cnt;
        }
    }

    private void solveE() throws IOException {
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        PriorityQueue<Type> pq = new PriorityQueue<>(comparingInt(o -> -o.cnt));
        for (int i = 0; i < m; i++)
            pq.add(new Type(i, in.nextInt()));

        int[] color = new int[n], cnt = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0 || cnt[i - 1] < k || pq.peek().color != color[i - 1]) {
                Type cur = pq.poll();
                color[i] = cur.color;
                cnt[i] = i == 0 || color[i] != color[i - 1] ? 1 : cnt[i - 1] + 1;
                cur.cnt--;
                if (cur.cnt > 0)
                    pq.add(cur);
            } else if (pq.size() == 1) {
                out.println(-1);
                return;
            } else {
                Type f = pq.poll();
                Type cur = pq.poll();
                color[i] = cur.color;
                cnt[i] = color[i] != color[i - 1] ? 1 : cnt[i - 1] + 1;
                cur.cnt--;
                pq.add(f);
                if (cur.cnt > 0)
                    pq.add(cur);
            }
        }

        for (int i = 0; i < n; i++)
            out.print(color[i] + 1 + " ");
    }

    private void solveF() throws IOException {
        int pos = 0, neg = 0, zero = 0;
        long posSum = 0, negSum = 0, zeroSum = 0;

        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int ai = in.nextInt();

            if (ai > 0) {
                pos++;
            } else if (ai == 0) {
                zero = i + 1;
                pos = neg = 0;
            } else { 

                int swap = pos;
                pos = neg;
                neg = swap + 1;
            }

            zeroSum += zero;
            posSum += pos;
            negSum += neg;
        }

        out.println(negSum + " " + zeroSum + " " + posSum);
    }

    private void solveG() throws IOException {
        int n = in.nextInt();
        char[] s = in.next().toCharArray(), t = in.next().toCharArray();

        int[] sa = new int[n], ta = new int[n];
        int sas = 0, tas = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i])
                continue;

            if (s[i] == 'a')
                sa[sas++] = i;
            else
                ta[tas++] = i;
        }

        if (sas % 2 + tas % 2 == 1) {
            out.println(-1);
            return;
        }

        out.println((sas + 1) / 2 + (tas + 1) / 2);
        while (sas > 1) {
            out.println(sa[sas - 1] + 1 + " " + (sa[sas - 2] + 1));
            sas -= 2;
        }
        while (tas > 1) {
            out.println(ta[tas - 1] + 1 + " " + (ta[tas - 2] + 1));
            tas -= 2;
        }
        if (sas + tas == 2) {
            out.println(sa[sas - 1] + 1 + " " + (sa[sas - 1] + 1));
            out.println(sa[sas - 1] + 1 + " " + (ta[tas - 1] + 1));
        }
    }

    private void solveH() throws IOException {
        int n = in.nextInt();
        long[] x = in.nextLongArray(n);
        int[][] map = new int[n][];
        for (int i = 0; i < n; i++) {
            map[i] = new int[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int v = 1;

                int l = -1, r = j;
                while (l + 1 < r) {
                    int m = (l + r) / 2;
                    if (x[i] - x[j] <= x[j] - x[m])
                        l = m;
                    else
                        r = m;
                }

                if (l >= 0 && x[i] - x[j] == x[j] - x[l])
                    v += map[j][l];
                else
                    v++;

                map[i][j] = v;
                if (v > ans)
                    ans = v;
            }
        }
        out.println(ans);
    }

    private void solveI() throws IOException {
        

    }

    private void solveJ() throws IOException {
        int n = in.nextInt();
        long P = in.nextLong(), Q = in.nextLong(), D = (long) 1e6;
        long[] a = in.nextLongArray(n);
        shuffleLong(a);
        sort(a);

        long[] up = new long[n], cntDown = new long[n];
        fill(up, 1);
        for (int i = 0; i < n; i++) {
            for (long x = a[i] - 1; x <= a[i] + 1; x++) {
                int id = binSearch(a, x);
                if (id < n && a[id] == x) {
                    up[id] *= (x == a[i] - 1 ? D - P : x == a[i] + 1 ? D - Q : P + Q);
                    up[id] %= mod;
                    cntDown[id]++;
                }
            }
        }

        long bigUp = binpowmod(D, n), sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (bigUp - up[i] * binpowmod(D, n - cntDown[i]) % mod + mod) % mod;
            sum %= mod;
        }
        out.println(sum * binpowmod(bigUp, mod - 2) % mod);
    }

    int binSearch(long[] a, long x) {
        int l = -1, r = a.length;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (a[m] < x)
                l = m;
            else
                r = m;
        }
        return r;
    }

    private void solveK() throws IOException {
        int n = in.nextInt();
        out.println(n * n * 3 / 4);
        for (int i = 1; i <= n; i += 2) {
            for (int j = 1; j <= n; j += 2) {
                out.println("1 " + (i + 1) + " " + j + " 2");
                out.println("1 " + i + " " + (j + 1) + " 2");
                out.println("2 " + i + " " + j + " 1");
            }
        }
    }

    private void solveL() throws IOException {
        int n = in.nextInt(), k = in.nextInt();
        char[] s = new StringBuilder(in.next()).reverse().append(in.next()).toString().toCharArray();

        int first = -1, last = -1;
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == '1') {
                if (first == -1)
                    first = i < n ? i : i + k + 1;
                last = i < n ? i : i + k + 1;
            }
        }

        int ans = last, pos = 0;
        for (int i = 1; i < 2 * n; i++) {
            int curPos = i < n ? i : i + k + 1;
            if (max(abs(first - curPos), abs(last - curPos)) < ans) {
                ans = max(abs(first - curPos), abs(last - curPos));
                pos = curPos;
            }
        }

        out.println(ans);
        if (pos < n)
            out.println("2 " + (n - pos));
        else
            out.println("1 " + (pos - n - k));
    }

    void shuffleInt(int[] a) {
        Random random = new Random();
        for (int i = a.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            int swap = a[j];
            a[j] = a[i];
            a[i] = swap;
        }
    }

    void shuffleLong(long[] a) {
        Random random = new Random();
        for (int i = a.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            long swap = a[j];
            a[j] = a[i];
            a[i] = swap;
        }
    }

    void reverseInt(int[] a) {
        for (int i = 0, j = a.length - 1; i < j; i++, j--) {
            int swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }

    void reverseLong(long[] a) {
        for (int i = 0, j = a.length - 1; i < j; i++, j--) {
            long swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }

    int maxInt(int[] a) {
        int max = a[0];
        for (int i = 1; i < a.length; i++)
            if (max < a[i])
                max = a[i];
        return max;
    }

    long maxLong(long[] a) {
        long max = a[0];
        for (int i = 1; i < a.length; i++)
            if (max < a[i])
                max = a[i];
        return max;
    }

    int minInt(int[] a) {
        int min = a[0];
        for (int i = 1; i < a.length; i++)
            if (min > a[i])
                min = a[i];
        return min;
    }

    long minLong(long[] a) {
        long min = a[0];
        for (int i = 1; i < a.length; i++)
            if (min > a[i])
                min = a[i];
        return min;
    }

    long sumInt(int[] a) {
        long s = 0;
        for (int i = 0; i < a.length; i++)
            s += a[i];
        return s;
    }

    long sumLong(long[] a) {
        long s = 0;
        for (int i = 0; i < a.length; i++)
            s += a[i];
        return s;
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long binpowmod(long a, long n) {
        long res = 1;
        a %= mod;
        n %= mod - 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }

    class GraphPair implements Comparable<GraphPair> {
        int v;
        long w;

        GraphPair(int v, long w) {
            this.v = v;
            this.w = w;
        }

        public int compareTo(GraphPair o) {
            return w != o.w ? Long.compare(w, o.w) : Integer.compare(v, o.v);
        }
    }

    ArrayList<Integer>[] createGraph(int n) throws IOException {
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();
        return graph;
    }

    ArrayList<GraphPair>[] createWeightedGraph(int n) throws IOException {
        ArrayList<GraphPair>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();
        return graph;
    }

    class FastScanner {
        StringTokenizer st;
        BufferedReader br;

        FastScanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s), 32768);
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        boolean hasNext() throws IOException {
            return br.ready() || (st != null && st.hasMoreTokens());
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            return a;
        }

        int[][] nextIntTable(int n, int m) throws IOException {
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i][j] = in.nextInt();
            return a;
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        long[] nextLongArray(int n) throws IOException {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextLong();
            return a;
        }

        long[][] nextLongTable(int n, int m) throws IOException {
            long[][] a = new long[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i][j] = in.nextLong();
            return a;
        }

        ArrayList<Integer>[] nextGraph(int n, int m, boolean directed) throws IOException {
            ArrayList<Integer>[] graph = createGraph(n);
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1, u = in.nextInt() - 1;
                graph[v].add(u);
                if (!directed)
                    graph[u].add(v);
            }
            return graph;
        }

        ArrayList<GraphPair>[] nextWeightedGraph(int n, int m, boolean directed) throws IOException {
            ArrayList<GraphPair>[] graph = createWeightedGraph(n);
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1, u = in.nextInt() - 1;
                long w = in.nextLong();
                graph[v].add(new GraphPair(u, w));
                if (!directed)
                    graph[u].add(new GraphPair(v, w));
            }
            return graph;
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }

        boolean hasNextLine() throws IOException {
            return br.ready();
        }
    }

    private void run() throws IOException {
        in = new FastScanner(System.in); 

        out = new PrintWriter(System.out); 


        for (int t = multitests ? in.nextInt() : 1; t-- > 0; )
            solve();

        out.flush();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void solve0A() throws IOException {
        out.print(in.nextInt() * in.nextInt());
    }

    private void solve0B() throws IOException {
        int n = in.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.next();
        }
        for (int i = s.length - 1; i >= 0; i--) {
            out.println(s[i]);
        }
    }

    class Box {
        int cnt, size;

        Box(int cnt, int size) {
            this.cnt = cnt;
            this.size = size;
        }
    }

    private void solve0C() throws IOException {
        int n = in.nextInt(), m = in.nextInt();
        Box[] b = new Box[m];
        for (int i = 0; i < m; i++) {
            b[i] = new Box(in.nextInt(), in.nextInt());
        }
        sort(b, comparingInt(o -> -o.size));
        int ans = 0;
        for (int i = 0; i < m && n > 0; i++) {
            ans += min(n, b[i].cnt) * b[i].size;
            n -= min(n, b[i].cnt);
        }
        out.println(ans);
    }

    private void solve0D() throws IOException {
        long a = in.nextLong(), b = in.nextLong(), x = in.nextLong(), y = in.nextLong();
        long g = gcd(x, y);
        x /= g;
        y /= g;
        long k = min(a / x, b / y);
        out.println(x * k + " " + (y * k));
    }
}