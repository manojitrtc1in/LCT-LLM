import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        InputStream inputStream;
        if (args.length > 0 && args[0].equals("devTesting")) {
            try {
                inputStream = new FileInputStream(args[1]);
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        } else {
            inputStream = System.in;
        }
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int n, m, q, logn;
        List<Integer>[] graph, ids;
        int[] persons, parents, heights;
        BitSet vis;

        void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            q = in.nextInt();
            logn = (int) Math.ceil(Math.log(n) / Math.log(2));
            graph = (ArrayList<Integer>[]) new ArrayList[n + 1];
            ids = (ArrayList<Integer>[]) new ArrayList[n + 1];
            for (int i = 0; i <= n; ++i) {
                graph[i] = new ArrayList<>();
                ids[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; ++i) {
                int v = in.nextInt();
                int u = in.nextInt();
                graph[v].add(u);
                graph[u].add(v);
            }
            persons = new int[m + 1];
            for (int i = 1; i <= m; ++i) {
                persons[i] = in.nextInt();
                ids[persons[i]].add(i);
            }
            for (int i = 1; i <= n; ++i) {
                Collections.sort(ids[i]);
            }
            parents = new int[n + 1];
            heights = new int[n + 1];
            vis = new BitSet();
            dfs(1);
            int[][][] table = new int[logn + 1][n + 1][11];
            pre(table, parents);
            for (int i = 0; i < q; ++i) {
                int v = in.nextInt();
                int u = in.nextInt();
                int a = in.nextInt();
                int[] get = Arrays.copyOfRange(query(table, v, u), 1, a + 1);
                int k = 0;
                for (int x : get) {
                    if (k < a && x < Integer.MAX_VALUE / 2) {
                        ++k;
                    }
                }
                out.print(k);
                for (int j = 0; j < k; ++j) {
                    out.print(" " + get[j]);
                }
                out.println();
            }
        }
        
        void pre(int[][][] table, int[] parents) {
            Arrays.fill(table[0][0], Integer.MAX_VALUE / 2);
            table[0][0][0] = 0;
            for (int v = 1; v <= n; ++v) {
                Arrays.fill(table[0][v], Integer.MAX_VALUE / 2);
                table[0][v][0] = parents[v];
                for (int i = 1; i <= Math.min(ids[v].size(), 10); ++i) {
                    table[0][v][i] = ids[v].get(i - 1);
                }
            }
            for (int i = 1; 1 << i < n; ++i) {
                for (int v = 0; v <= n; ++v) {
                    table[i][v][0] = table[i - 1][table[i - 1][v][0]][0];                        
                    int[] ptr = {1, 1};
                    if (table[i - 1][v][0] == 0 && table[i - 1][v][1] >= Integer.MAX_VALUE / 2 && table[i - 1][table[i - 1][v][0]][1] >= Integer.MAX_VALUE / 2) {
                        continue;
                    }
                    for (int j = 1; j <= 10; ++j) {
                        if (ptr[0] <= 10 && table[i - 1][v][ptr[0]] < table[i - 1][table[i - 1][v][0]][ptr[1]]) {
                            table[i][v][j] = table[i - 1][v][ptr[0]++];
                        } else {
                            table[i][v][j] = table[i - 1][table[i - 1][v][0]][ptr[1]++];
                        }
                    }
                }
                
            }
        }
        
        int[] query(int[][][] table, int u, int v) {
            if (u == v) {
                return table[0][u];
            }
            if (heights[u] < heights[v]) {
                int temp = u;
                u = v;
                v = temp;
            }
            int[] uaux = Arrays.copyOf(table[0][u], 11);
            for (int i = logn; i >= 0; --i) {
                if (heights[u] - (1 << i) >= heights[v]) {
                    uaux = merge(table[i][u], uaux, 10);
                    uaux[0] = table[i][u][0];
                    u = uaux[0];
                }
            }
            int[] vaux = Arrays.copyOf(table[0][v], 11);
            if (uaux[0] == v) {
                int[] ret = merge(uaux, vaux, 10);
                return ret;
            }
            for (int i = logn; i >= 0; --i) {
                if (table[i][u][0] != 0 && table[i][u][0] != table[i][v][0]) {
                    uaux = merge(uaux, table[i][u], 10);
                    uaux[0] = table[i][u][0];
                    u = uaux[0];
                    vaux = merge(vaux, table[i][v], 10);
                    vaux[0] = table[i][v][0];
                    v = vaux[0];                        
                }
            }
            uaux = merge(uaux, table[0][u], 10);
            uaux[0] = table[0][u][0];
            u = uaux[0];
            vaux = merge(vaux, table[0][v], 10);
            vaux[0] = table[0][v][0];
            v = vaux[0];
                        
            if (uaux[0] != 0) {
                uaux = merge(uaux, table[0][u], 10);
                uaux[0] = table[0][u][0];
                u = uaux[0];
            }
            int[] ret = merge(uaux, vaux, 10);
            return ret;
        }
        
        int[] merge(int[] a, int[] b, int cnt) {
            int[] ptr = {1, 1}, ret = new int[cnt + 1];
            Arrays.fill(ret, Integer.MAX_VALUE / 2);
            ret[0] = a[0];
            int i = 1;
            while (i <= cnt && ptr[0] <= 10 && ptr[1] <= 10) {
                if (ptr[0] <= cnt && a[ptr[0]] < b[ptr[1]]) {
                    ret[i++] = a[ptr[0]++];
                } else {
                    if (a[ptr[0]] > b[ptr[1]]) {
                        ret[i++] = b[ptr[1]];                       
                    }
                    ++ptr[1];
                }
            }
            return ret;
        }
        
        void dfs(int v) {
            vis.set(v);
            for (int w : graph[v]) {
                if (!vis.get(w)) {
                    parents[w] = v;
                    heights[w] = heights[v] + 1;
                    dfs(w);
                }
            }
        }

        int i(long x) {
            return (int) x;
        }

        <T> void id0(T[] a, int s, int e) {
            Queue<T> queue = new PriorityQueue<>();
            for (int i = s; i <= e; ++i) {
                queue.add(a[i]);
            }
            for (int i = s; i <= e; ++i) {
                a[i] = queue.poll();
            }
        }

    }

    static class InputReader {

        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public boolean hasInput() {
            try {
                if (tokenizer != null && tokenizer.hasMoreTokens()) {
                    return true;
                }
                reader.mark(1);
                int ch = reader.read();
                if (ch != -1) {
                    reader.reset();
                    return true;
                }
                return false;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

    }
}














