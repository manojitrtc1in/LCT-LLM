

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

    static long[] f = new long[1000001];

    static long InverseEuler(long n, long MOD) {
        return pow(n, MOD - 2, MOD);
    }

    static long C(int n, int r, long MOD) {

        return (f[n] * ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) % MOD;
    }


    static int[] h = {0, 0, -1, 1};
    static int[] v = {1, -1, 0, 0};


    static class Pair2 {
        int a, b;

        public Pair2(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair2 pair2 = (Pair2) o;
            return (a == pair2.a &&
                    b == pair2.b) || (a == pair2.b &&
                    b == pair2.a);
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b) + Objects.hash(b, a);
        }
    }


    static long l[][] = new long[1001][1001];

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
            return id10(0, n - 1, 0, l, r);
        }

        private long id10(int l, int r, int pos, int ql, int qr) {
            if (l > qr || r < ql) return 0L;
            if (l >= ql && r <= qr) {
                return sumtree[pos];
            }
            int mid = (l + r) >> 1;
            return id10(l, mid, 2 * pos + 1, ql, qr) + id10(mid + 1, r, 2 * pos + 2, ql, qr);
        }

        public long getCount(int l, int r) {
            return id7(0, n - 1, 0, l, r);
        }

        private long id7(int l, int r, int pos, int ql, int qr) {
            if (l > qr || r < ql) return 0L;
            if (l >= ql && r <= qr) {
                return count[pos];
            }
            int mid = (l + r) >> 1;
            return id7(l, mid, 2 * pos + 1, ql, qr) + id7(mid + 1, r, 2 * pos + 2, ql, qr);
        }

        public int[] id1(int l, int r) {
            return id6(0, n - 1, 0, l, r);
        }

        private int[] id6(int l, int r, int pos, int ql, int qr) {
            if (l > qr || r < ql) return null;
            if (l >= ql && r <= qr) {
                int[] returs = new int[30];
                for (int i = 0; i < 30; ++i) {
                    returs[i] = tree[pos][i];
                }
                return returs;
            }
            int mid = (l + r) >> 1;

            int[] left = id6(l, mid, 2 * pos + 1, ql, qr);
            int[] right = id6(mid + 1, r, 2 * pos + 2, ql, qr);
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
    static boolean answer = true;

    static int VISITED = 1;
    static int VISITING = 2;

    public static class MD {
        public static class Pair {
            int val;
            int count;
            int cost;

            public Pair(int val, int count, int cost) {
                this.val = val;
                this.count = count;
                this.cost = cost;
            }
        }

        Deque<Pair> dq = new LinkedList<>();


        public long get() {
            return dq.getFirst().val;
        }
    }

    static long ans = 0;


    public static class Pair {
        int from, to;

        public Pair(int from, int to) {
            this.from = Math.min(from, to);
            this.to = Math.max(from, to);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Pair pair = (Pair) o;
            return from == pair.from &&
                    to == pair.to;
        }

        @Override
        public int hashCode() {
            return Objects.hash(from, to);
        }
    }
    public static void main(String[] args) throws Exception {
        


























        InputReader in = new InputReader(System.in);

































        int t = in.readInt();
        while (t-- > 0) {


            int n = in.readInt();

            List<List<Integer>> tree = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                tree.add(new ArrayList<>());
            }


            for (int i = 0; i < n-1; ++i) {
                int from = in.readInt();
                int to = in.readInt();
                from --;
                to--;
                tree.get(from).add(to);
                tree.get(to).add(from);
            }

            Long[] sz = new Long[n];

            dfss(tree, 0, sz, -1);

            long ans = 0;

            int m  = in.readInt();

            Integer[] mul = new Integer[m];
            for (int i = 0; i < m; ++i) {
                mul[i] = in.readInt();
            }

            sz[0] = -1L;
            for (int i = 1; i < n; ++i) {
                sz[i] = sz[i]*(n-sz[i]);
            }

            Arrays.sort(mul,Collections.reverseOrder());
            Arrays.sort(sz, Collections.reverseOrder());
            long[] newmul = new long[n-1];
            if (m >= n-1) {
                int i = m-1, j = n-2;
                for (; j > 0; --i, --j) {
                    newmul[j] = mul[i];
                }
                long last = 1;

                for (; i >= 0; --i) {
                    last *= mul[i];
                    last %= 1000000007;
                }
                assert (j == 0);
                newmul[j] = last;

            } else {
                int i = 0;
                for (; i < m; ++i) {
                    newmul[i] = mul[i];
                }
                for (; i < n-1; ++i) {
                    newmul[i] = 1;
                }
            }

            for (int i = 0; i < n-1; ++i) {
                ans += (sz[i] * newmul[i]) % 1000000007;
                ans %= 1000000007;
            }
            System.out.println(ans);






        }

        








    }

    private static void dfss(List<List<Integer>> tree, int node, Long[] sz, int last) {
        sz[node] = 1L;
        for (int i = 0; i < tree.get(node).size(); ++i) {
            int ntb = tree.get(node).get(i);
            if (ntb != last) {
                dfss(tree, ntb, sz, node);

                sz[node] += sz[ntb];
            }
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
                biggest = ntb;
            }
        }
        if (biggest != -1) {



            long id3 = sum[biggest];
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
                        Integer id8 = entry.getKey();
                        Integer counts = entry.getValue();
                        if (node == 3) {


                        }
                        if (colorCounts.get(biggest).getOrDefault(id8, 0) + counts > max[biggest]) {
                            if (node == 3) {


                            }
                            max[biggest] = colorCounts.get(biggest).getOrDefault(id8, 0) + counts;
                            colorCounts.get(biggest).put(id8, colorCounts.get(biggest).getOrDefault(id8, 0) + counts);
                            id3 = id8;
                        } else if (colorCounts.get(biggest).getOrDefault(id8, 0) + counts == max[biggest]) {
                            if (node == 3) {


                            }
                            colorCounts.get(biggest).put(id8, colorCounts.get(biggest).getOrDefault(id8, 0) + counts);
                            id3 += id8;
                        } else {
                            if (node == 3) {


                            }
                            colorCounts.get(biggest).put(id8, colorCounts.get(biggest).getOrDefault(id8, 0) + counts);
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

    static long gcd(long a, long b) {

        while (b != 0) {
            long t = a;
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

    class Solution {
        public int maxDistance(int[] position, int m) {
            Arrays.sort(position);

            int hi = 1000000000;
            int lo = 1;

            while (lo < hi) {
                int mi = (lo + hi + 1) / 2;
                if (check(position, mi, m)) {
                    lo = mi;
                } else {
                    hi = mi - 1;
                }
            }

            return lo;
        }

        private boolean check(int[] position, int minimumDistance, int m) {
            

            int id5 = position[0];
            int id9 = m - 1;
            for (int i = 1; i < position.length && id9 != 0; ) {
                if (position[i] - id5 < minimumDistance) {
                    

                    i++;
                } else {
                    

                    id5 = position[i];
                    id9--;
                }
            }
            return id9 == 0;
        }
    }


}

































