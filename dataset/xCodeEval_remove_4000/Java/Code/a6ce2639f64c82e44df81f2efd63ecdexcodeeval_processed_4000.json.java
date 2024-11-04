

import java.io.*;
import java.util.*;

public class TestClass {

    static final class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int read() throws IOException {
            if (curChar >= numChars) {
                curChar = 0;
                numChars = stream.read(buf);
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public final int readInt() throws IOException {
            return (int) readLong();
        }

        public final long readLong() throws IOException {
            int c = read();
            while (id2(c)) {
                c = read();
                if (c == -1) throw new IOException();
            }
            boolean negative = false;
            if (c == '-') {
                negative = true;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id2(c));
            return negative ? -res : res;
        }

        public final int[] id0(int size) throws IOException {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public final long[] id4(int size) throws IOException {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public final String readString() throws IOException {
            int c = read();
            while (id2(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = read();
            } while (!id2(c));
            return res.toString();
        }

        private boolean id2(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }

    static long mulmod(long a, long b,
                       long mod) {
        long res = 0; 

        a = a % mod;
        while (b > 0) {
            

            if (b % 2 == 1) {
                res = (res + a) % mod;
            }

            

            a = (a * 2) % mod;

            

            b /= 2;
        }

        

        return res % mod;
    }

    static long pow(long a, long b, long MOD) {
        long x = 1, y = a;
        while (b > 0) {
            if (b % 2 == 1) {
                x = (x * y);
                if (x > MOD) x %= MOD;
            }
            y = (y * y);
            if (y > MOD) y %= MOD;
            b /= 2;
        }
        return x;
    }

    static long[] f = new long[100011];

    static long InverseEuler(long n, long MOD) {
        return pow(n, MOD - 2, MOD);
    }

    static long C(int n, int r, long MOD) {

        return (f[n] * ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) % MOD;
    }


    static int[] h = {0, 0, -1, 1};
    static int[] v = {1, -1, 0, 0};


    static class Pair2 {
        public long cost;
        int node;

        public Pair2(long cos, int node) {
            this.cost = cos;
            this.node = node;
        }
    }


    static long l[][] = new long[100011][6];

    static long compute_hash(String s) {
        int p = 31;
        int m = 1000000007;
        long hash_value = 0;
        long p_pow = 1;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }

    public static class SegmentTree {
        int[][] tree;
        long[] sumtree;
        long[] count;
        int n;

        public SegmentTree(int[] nodes) {
            tree = new int[nodes.length * 4][31];
            sumtree = new long[nodes.length * 4];
            count = new long[nodes.length * 4];
            n = nodes.length;
            build(0, n - 1, 0, nodes);
        }

        private void build(int l, int r, int pos, int[] nodes) {
            if (l == r) {
                sumtree[pos] = nodes[l];
                boolean neg = false;
                if (nodes[l] < 0) {
                    neg = true;
                }
                count[pos] = 1;
                if (neg) {
                    count[pos] = -1;
                }
                for (int i = 0; i < 31; ++i) {
                    tree[pos][i] = (neg ? -1 : 1) * (((nodes[l] < 0 ? -1 * nodes[l] : nodes[l]) & (1 << i)) != 0 ? 1 : 0);
                }
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, 2 * pos + 1, nodes);
            build(mid + 1, r, 2 * pos + 2, nodes);
            sumtree[pos] = sumtree[2 * pos + 1] + sumtree[2 * pos + 2];
            count[pos] = count[2 * pos + 1] + count[2 * pos + 2];

            for (int i = 0; i < 31; ++i) {
                tree[pos][i] = tree[2 * pos + 1][i] + tree[2 * pos + 2][i];
            }
        }

        public long getSum(int l, int r) {
            return id8(0, n - 1, 0, l, r);
        }

        private long id8(int l, int r, int pos, int ql, int qr) {
            if (l > qr || r < ql) return 0L;
            if (l >= ql && r <= qr) {
                return sumtree[pos];
            }
            int mid = (l + r) >> 1;
            return id8(l, mid, 2 * pos + 1, ql, qr) + id8(mid + 1, r, 2 * pos + 2, ql, qr);
        }

        public long getCount(int l, int r) {
            return id6(0, n - 1, 0, l, r);
        }

        private long id6(int l, int r, int pos, int ql, int qr) {
            if (l > qr || r < ql) return 0L;
            if (l >= ql && r <= qr) {
                return count[pos];
            }
            int mid = (l + r) >> 1;
            return id6(l, mid, 2 * pos + 1, ql, qr) + id6(mid + 1, r, 2 * pos + 2, ql, qr);
        }

        public int[] id1(int l, int r) {
            return id5(0, n - 1, 0, l, r);
        }

        private int[] id5(int l, int r, int pos, int ql, int qr) {
            if (l > qr || r < ql) return null;
            if (l >= ql && r <= qr) {
                int[] returs = new int[30];
                for (int i = 0; i < 30; ++i) {
                    returs[i] = tree[pos][i];
                }
                return returs;
            }
            int mid = (l + r) >> 1;

            int[] left = id5(l, mid, 2 * pos + 1, ql, qr);
            int[] right = id5(mid + 1, r, 2 * pos + 2, ql, qr);
            if (left == null) return right;
            if (right == null) return left;
            

            for (int i = 0; i < 30; ++i) {
                left[i] += right[i];
            }
            return left;
        }


    }

    static int counter = 0;
    static int[] In;
    static int[] Out;
    private static int[] flatten;
    private static int[][] lca;
    static long answer = 0;

    static int VISITED = 1;
    static int VISITING = 2;

    public static void main(String[] args) throws Exception {
        


























        InputReader in = new InputReader(System.in);























        int n = in.readInt();

        int[] color  = new int[n];

        for (int i = 0; i < n; ++i) {
            color[i] = in.readInt();
        }

        List<Map<Integer, Integer>> colorCounts = new ArrayList<>();
        List<List<Integer>> tree = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            tree.add(new ArrayList<>());
            colorCounts.add(new HashMap<>());
        }

        for (int i = 0; i < n-1; ++i) {
            int from = in.readInt();
            int to = in.readInt();
            from--;
            to--;
            tree.get(from).add(to);
            tree.get(to).add(from);
        }

        int[] size = new int[n];
        int[] max = new int[n];
        long[] sum = new long[n];


        dfs(tree, 0, -1, size, max, sum, color, colorCounts);

        for (int i = 0; i < n; ++i) {
            System.out.print(sum[i] +  " " );
        }

    }

    private static void dfs(List<List<Integer>> tree, int node, int last, int[] size, int[] max, long[] sum, int[] color, List<Map<Integer, Integer>> colorCounts) {
        size[node] = 1;
        int biggest = -1;
        List<Integer> childs = new ArrayList<>();
        for (int i = 0; i < tree.get(node).size(); ++i) {
            int ntb = tree.get(node).get(i);

            if (ntb != last) {
                dfs(tree, ntb, node, size, max, sum, color, colorCounts);
                size[node] += size[ntb];
                childs.add(ntb);
                if (biggest == -1) {
                    biggest = ntb;
                } else {
                    if (size[biggest] < size[ntb]) {
                        biggest = ntb;
                    }
                }
            }
        }
        if (biggest != -1) {



            long id3 =  sum[biggest];
            if (colorCounts.get(biggest).getOrDefault(color[node], 0) == max[biggest]) {
                colorCounts.get(biggest).put(color[node], colorCounts.get(biggest).get(color[node]) + 1);
                id3 = color[node];
                max[biggest] = max[biggest] + 1;
            } else if (colorCounts.get(biggest).getOrDefault(color[node], 0) + 1 == max[biggest]) {
                colorCounts.get(biggest).put(color[node], colorCounts.get(biggest).getOrDefault(color[node], 0) + 1);
                id3 += color[node];



            } else {
                colorCounts.get(biggest).put(color[node], colorCounts.get(biggest).getOrDefault(color[node], 0) + 1);
            }




            for (int i = 0; i < childs.size(); ++i) {
                if (childs.get(i) != biggest) {

                    int noder = childs.get(i);



                    for (Map.Entry<Integer, Integer> entry : colorCounts.get(noder).entrySet()) {
                        Integer id7 = entry.getKey();
                        Integer counts = entry.getValue();
                        if (node == 3) {


                        }
                        if (colorCounts.get(biggest).getOrDefault(id7, 0) + counts > max[biggest]) {
                            if (node == 3) {


                            }
                            max[biggest] = colorCounts.get(biggest).getOrDefault(id7, 0) + counts;
                            colorCounts.get(biggest).put(id7, colorCounts.get(biggest).getOrDefault(id7, 0) + counts);
                            id3 = id7;
                        } else if (colorCounts.get(biggest).getOrDefault(id7, 0) + counts == max[biggest]) {
                            if (node == 3) {


                            }
                            colorCounts.get(biggest).put(id7, colorCounts.get(biggest).getOrDefault(id7, 0) + counts);
                            id3 += id7;
                        } else {
                            if (node == 3) {


                            }
                            colorCounts.get(biggest).put(id7, colorCounts.get(biggest).getOrDefault(id7, 0) + counts);
                        }
                    }

                }
            }




            sum[node] = id3;
            max[node] = max[biggest];
            colorCounts.set(node, colorCounts.get(biggest));
        } else {
            sum[node] = color[node];
            max[node] = 1;
            HashMap<Integer, Integer> e = new HashMap<>();
            e.put(color[node], 1);
            colorCounts.set(node, e);
        }
    }

    private static long solved(Long pos, TreeMap<Long, Long> mapPos, Map<Long, Long> dp) {
        if (!mapPos.containsKey(pos)) return 0;
        if (dp.containsKey(pos)) return dp.get(pos);
        long len = solved(pos + mapPos.get(pos), mapPos, dp) + mapPos.get(pos);
        dp.put(pos, len);
        return len;
    }

    private static long solve(int pos, int curK, int k, int[] arr, int m, long[][] dp) {
        System.out.println(pos);
        if (pos == arr.length) {
            if (curK == k) return 0;
            return -1000000000000L;
        }

        if (curK > k) return -1000000000000L;

        if (dp[pos][curK] != -1) return dp[pos][curK];

        long with = -1000000000000L;
        if (curK < k)
            with = solve(pos + 1, curK + 1, k, arr, m, dp) + arr[pos] * (((curK + 1) % m));
        long without = solve(pos + 1, curK, k, arr, m, dp);

        return dp[pos][curK] = Math.max(with, without);
    }

    static int countFreq(String pattern, String text) {
        int m = pattern.length();
        int n = text.length();
        int res = 0;

        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text.charAt(i + j) != pattern.charAt(j)) {
                    break;
                }
            }
            if (j == m) {
                res++;
                j = 0;
            }
        }
        return res;
    }




    private static void preprocess(int pos, int[][] pre, List<List<Integer>> tree, int[] traverse, int depth, int last, int[] tin, int[] tout) {
        tin[pos] = counter++;
        traverse[depth] = pos;

        for (int i = 0; depth - (1 << i) >= 0; ++i) {
            pre[pos][i] = traverse[depth - (1 << i)];
        }

        for (int i = 0; i < tree.get(pos).size(); ++i) {
            if (tree.get(pos).get(i) != last)
                preprocess(tree.get(pos).get(i), pre, tree, traverse, depth + 1, pos, tin, tout);
        }
        tout[pos] = counter++;
    }

    static int gcd(int a, int b) {

        while (b != 0) {
            int t = a;
            a = b;
            b = t % b;
        }
        return a;
    }


    static boolean submit = true;

    static void debug(String s) {
        if (!submit)
            System.out.println(s);
    }

    static void debug(int s) {
        if (!submit)
            System.out.println(s);
    }





}

































