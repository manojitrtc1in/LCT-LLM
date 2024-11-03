
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class KuroniAndAntihype {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);



        

        int MAXBIT = 18;
        int N = sc.nextInt();
        a = new int[N + 1];
        id = new int[N + 1];
        comps = new ArrayList[N + 1];
        Arrays.setAll(id, i -> i);
        Arrays.setAll(comps, i -> new ArrayList<>());
        for (int i = 0; i <= N; i++) {
            if (i > 0)
                a[i] = sc.nextInt();
            comps[i].add(i);
        }
        int compCt = N + 1;
        int full = (1 << MAXBIT) - 1;
        int[] deg = new int[N + 1];
        while (compCt > 1) {
            
            int[][] topEdges = new int[2][1 << MAXBIT];
            Arrays.fill(topEdges[0], -1);
            Arrays.fill(topEdges[1], -1);
            for (int i = 0; i <= N; i++) {
                maximize(topEdges, a[i], i);
            }
            for (int mask = 0; mask <= full; mask++) {
                for (int bit = 1; bit < 1 << MAXBIT; bit <<= 1) {
                    if (((mask & bit) > 0)) {
                        int submask = mask - bit;
                        

                        maximize(topEdges, mask, topEdges[0][submask]);
                        maximize(topEdges, mask, topEdges[1][submask]);
                    }
                }
            }
            

            ArrayList<int[]> edges = new ArrayList<>();
            for (int node = 0; node <= N; node++) {
                
                if (find(node) == node) {
                    

                    

                    

                    int best = -1;
                    int[] edge = {-1, -1};
                    for (int i : comps[node]) {
                        int complement = full - a[i];
                        int first = topEdges[0][complement];
                        int second = topEdges[1][complement];
                        

                        

                        if (first != -1 && node != find(first) && a[i] + a[first] > best) {
                            best = a[i] + a[first];
                            edge[0] = i;
                            edge[1] = first;
                        } else if (second != -1 && node != find(second) && a[i] + a[second] > best) {
                            best = a[i] + a[second];
                            edge[0] = i;
                            edge[1] = second;
                        }
                    }
                    if (edge[0] != -1) {
                        edges.add(edge);
                    }
                }
            }
            for (int[] edge : edges) {
                if (find(edge[0]) != find(edge[1])) {
                    
                    deg[edge[0]]++;
                    deg[edge[1]]++;
                    unite(edge[0], edge[1]);
                    compCt--;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i <= N; i++) {
            

            

            

            

            

            ans += (long) (deg[i] - 1) * a[i];
        }
        out.println(ans);
        out.close();
    }

    static void generate() {
        int N = 10000;
        System.out.println(N);
        for (int i = 0; i < N; i++) {
            System.out.print((int) (random() * 10000) + " ");
        }
        System.out.println();
    }

    static int[] id, a;
    static ArrayList<Integer>[] comps;

    static void maximize(int[][] topEdges, int mask, int alt) {
        if (alt == -1) return;
        

        int first = topEdges[0][mask];
        int second = topEdges[1][mask];
        

        

        if (first == -1 || a[alt] > a[first]) {
            if (first != -1 && find(alt) != find(first)) {
                

                

                topEdges[1][mask] = first;
            }
            topEdges[0][mask] = alt;
        } else if (find(alt) != find(first) && (second == -1 || (a[alt] > a[second] && find(alt) != find(first)))) {
            

            

            topEdges[1][mask] = alt;
        }
        if (topEdges[0][mask] != -1 && topEdges[1][mask] != -1)
            ASSERT(find(topEdges[0][mask]) != find(topEdges[1][mask]));
    }

    static int find(int u) {
        if (u == -1) return -1;
        return id[u] == u ? u : (id[u] = find(id[u]));
    }

    static void unite(int u, int v) {
        if ((u = find(u)) != (v = find(v))) {
            if (comps[u].size() < comps[v].size()) {
                int temp = u;
                u = v;
                v = temp;
            }
            id[v] = u;
            comps[u].addAll(comps[v]);
        }
    }

    static class FastScanner {
        private int BS = 1 << 16;
        private char NC = (char) 0;
        private byte[] buf = new byte[BS];
        private int bId = 0, size = 0;
        private char c = NC;
        private double cnt = 1;
        private BufferedInputStream in;

        public FastScanner() {
            in = new BufferedInputStream(System.in, BS);
        }

        public FastScanner(String s) {
            try {
                in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
            } catch (Exception e) {
                in = new BufferedInputStream(System.in, BS);
            }
        }

        private char getChar() {
            while (bId == size) {
                try {
                    size = in.read(buf);
                } catch (Exception e) {
                    return NC;
                }
                if (size == -1) return NC;
                bId = 0;
            }
            return (char) buf[bId++];
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public int[] nextInts(int N) {
            int[] res = new int[N];
            for (int i = 0; i < N; i++) {
                res[i] = (int) nextLong();
            }
            return res;
        }

        public long[] nextLongs(int N) {
            long[] res = new long[N];
            for (int i = 0; i < N; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        public long nextLong() {
            cnt = 1;
            boolean neg = false;
            if (c == NC) c = getChar();
            for (; (c < '0' || c > '9'); c = getChar()) {
                if (c == '-') neg = true;
            }
            long res = 0;
            for (; c >= '0' && c <= '9'; c = getChar()) {
                res = (res << 3) + (res << 1) + c - '0';
                cnt *= 10;
            }
            return neg ? -res : res;
        }

        public double nextDouble() {
            double cur = nextLong();
            return c != '.' ? cur : cur + nextLong() / cnt;
        }

        public double[] nextDoubles(int N) {
            double[] res = new double[N];
            for (int i = 0; i < N; i++) {
                res[i] = nextDouble();
            }
            return res;
        }

        public String next() {
            StringBuilder res = new StringBuilder();
            while (c <= 32) c = getChar();
            while (c > 32) {
                res.append(c);
                c = getChar();
            }
            return res.toString();
        }

        public String nextLine() {
            StringBuilder res = new StringBuilder();
            while (c <= 32) c = getChar();
            while (c != '\n') {
                res.append(c);
                c = getChar();
            }
            return res.toString();
        }

        public boolean hasNext() {
            if (c > 32) return true;
            while (true) {
                c = getChar();
                if (c == NC) return false;
                else if (c > 32) return true;
            }
        }
    }
    static void ASSERT(boolean assertion, String message) {
        if (!assertion) throw new AssertionError(message);
    }
    static void ASSERT(boolean assertion) {
        if (!assertion) throw new AssertionError();
    }
}