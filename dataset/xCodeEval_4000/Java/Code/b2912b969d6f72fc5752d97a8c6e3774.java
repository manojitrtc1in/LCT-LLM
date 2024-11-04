import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.Random;


public class Main {

    InputReader in;
    Printer out;

    long mod = 1000000007;

    private void start() throws Exception {
        int n = in.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        ArrayList<ArrayList<Integer>> operations = new ArrayList<>();

        if (a[0] != n && a[n - 1] != n) {
            int i = find(a, n);
            int j = n - 1;

            if (i > j) {
                int c = i;
                i = j;
                j = c;
            }

            ArrayList<Integer> operation = new ArrayList<>();
            for (int z = 0; z < i; z++) {
                operation.add(1);
            }
            operation.add(j - i + 1);
            for (int z = j + 1; z < n; z++) {
                operation.add(1);
            }

            operations.add(operation);
            a = apply(a, i, j);







        }

        for (int cur = n - 1; cur >= 1; cur--) {
            int index1 = find(a, cur + 1);

            int i = find(a, cur);
            int j = a[n - 1] == n ? cur - 1 : n - cur;







            if (i > j) {
                int c = i;
                i = j;
                j = c;
            }
            if (i == j) {
                continue;
            }

            ArrayList<Integer> operation = new ArrayList<>();
            for (int z = 0; z < i; z++) {
                operation.add(1);
            }
            operation.add(j - i + 1);
            for (int z = j + 1; z < n; z++) {
                operation.add(1);
            }
            operations.add(operation);

            a = apply(a, i, j);
        }

        if (a[0] == n && n > 1) {
            ArrayList<Integer> operation = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                operation.add(1);
            }
            operations.add(operation);
        }

        out.println(operations.size());
        for (ArrayList<Integer> operation: operations) {
            out.print(operation.size() + " ");
            for (int val: operation) {
                out.print(val + " ");
            }
            out.println();
        }
    }

    int[] apply(int a[], int i, int j) {
        int n = a.length;

        int[] b = new int[n];

        int index = 0;
        for (int k = n - 1; k > j; k--) {
            b[index++] = a[k];
        }
        for (int k = i; k <= j; k++) {
            b[index++] = a[k];
        }
        for (int k = i - 1; k >= 0; k--) {
            b[index++] = a[k];
        }

        return b;
    }

    int find(int a[], int val) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == val) {
                return i;
            }
        }
        return 0;
    }

    long power(long x, long n) {
        if (n <= 0) {
            return 1;
        }

        long y = power(x, n / 2);

        if ((n % 2) == 0) {
            return (y * y) % mod;
        } else {
            return (((y * y) % mod) * x) % mod;
        }
    }

    class Pair {
        int start;
        int end;

        Pair(int s, int e) {
            start = s;
            end = e;
        }

        public String toString() {
            return "start " + start + " end " + end;
        }
    }

    long gcd(long a, long b) {
        return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).longValue();
    }

    public static void main(String[] args) throws Exception {
        InputReader in;
        PrintStream out;



        in = new InputReader(System.in);
        out = System.out;

        Main main = new Main();

        main.in = in;
        main.out = new Printer(out, false);

        main.start();
        main.out.flush();
    }

    private static class InputReader {

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, nextInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return nextString();
        }

        public interface SpaceCharFilter {

            public boolean isSpaceChar(int ch);
        }
    }

    private static class Printer {

        PrintStream out;
        StringBuilder buffer = new StringBuilder();
        boolean autoFlush;

        public Printer(PrintStream out) {
            this.out = out;
        }

        public Printer(PrintStream out, boolean autoFlush) {
            this.out = out;
            this.autoFlush = autoFlush;
        }

        public void println() {
            buffer.append("\n");

            if (autoFlush) {
                flush();
            }
        }

        public void println(int n) {
            println(Integer.toString(n));
        }

        public void println(long n) {
            println(Long.toString(n));
        }

        public void println(double n) {
            println(Double.toString(n));
        }

        public void println(float n) {
            println(Float.toString(n));
        }

        public void println(boolean n) {
            println(Boolean.toString(n));
        }

        public void println(char n) {
            println(Character.toString(n));
        }

        public void println(byte n) {
            println(Byte.toString(n));
        }

        public void println(short n) {
            println(Short.toString(n));
        }

        public void println(Object o) {
            println(o.toString());
        }

        public void println(Object ... args) {
            print(args);
            println();
        }

        public void print(Object ... args) {
            for (int i = 0; i < args.length; i++) {
                Object item = args[i];
                buffer.append(item.toString());

                if (i < args.length - 1) {
                    buffer.append(" ");
                }
            }
            if (autoFlush) {
                flush();
            }
        }

        public void println(String s) {
            buffer.append(s).append("\n");

            if (autoFlush) {
                flush();
            }
        }

        public void print(char s) {
            buffer.append(s);

            if (autoFlush) {
                flush();
            }
        }

        public void print(String s) {
            buffer.append(s);

            if (autoFlush) {
                flush();
            }
        }

        public void flush() {
            try {
                BufferedWriter log = new BufferedWriter(new OutputStreamWriter(out));
                log.write(buffer.toString());

                log.flush();
                buffer = new StringBuilder();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private class PairSet<T, S> {

        HashMap<T, HashSet<S>> map = new HashMap<>();

        public void add(T a, S b) {
            if (map.containsKey(a)) {
                map.get(a).add(b);
            }

            HashSet<S> set = new HashSet<>();
            set.add(b);
            map.put(a, set);
        }

        public boolean contains(T a, S b) {
            if (map.containsKey(a)) {
                return map.get(a).contains(b);
            }

            return false;
        }
    }

    private class Bit {

        int N;
        long ft1[], ft2[];

        Bit(int n) {
            N = n;
            ft1 = new long[N + 1];
            ft2 = new long[N + 1];
        }

        void update(long ft[], int p, long v) {
            for (; p <= N; p += p & (-p)) {
                ft[p] += v;


            }
        }

        void update(int a, int b, long v) {
            update(ft1, a, v);
            update(ft1, b + 1, -v);
            update(ft2, a, v * (a - 1));
            update(ft2, b + 1, -v * b);
        }

        long query(long ft[], int b) {
            long sum = 0;
            for (; b > 0; b -= b & (-b)) {
                sum += ft[b];


            }

            return sum;
        }

        long query(int b) {
            return query(ft1, b) * b - query(ft2, b);
        }

        long query(int a, int b) {
            return query(b) - query(a - 1);
        }
    }

    class Bipartite {

        int m, n;
        boolean[][] graph;
        boolean seen[];
        int matchL[];   

        int matchR[];   


        public Bipartite(boolean[][] graph) {
            this.graph = graph;
            m = graph.length;
            n = graph[0].length;

            matchL = new int[m];
            matchR = new int[n];
            seen = new boolean[n];
        }

        int maximumMatching() {
            

            

            Arrays.fill(matchL, -1);
            Arrays.fill(matchR, -1);

            int count = 0;
            for (int i = 0; i < m; i++) {
                Arrays.fill(seen, false);
                if (bpm(i)) {
                    count++;
                }
            }
            return count;
        }

        boolean bpm(int u) {
            

            for (int v = 0; v < n; v++) {
                if (!graph[u][v] || seen[v]) {
                    continue;
                }
                seen[v] = true;
                

                if (matchR[v] == -1 || bpm(matchR[v])) {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            }
            return false;
        }
    }

    public static Set<Integer[]> getPermutationsRecursive(Integer[] num) {
        if (num == null) {
            return null;
        }

        Set<Integer[]> perms = new HashSet<>();

        

        if (num.length == 0) {
            perms.add(new Integer[0]);
            return perms;
        }

        

        

        int first = num[0];
        Integer[] remainder = Arrays.copyOfRange(num, 1, num.length);
        Set<Integer[]> subPerms = getPermutationsRecursive(remainder);
        for (Integer[] subPerm : subPerms) {
            for (int i = 0; i <= subPerm.length; ++i) { 

                Integer[] newPerm = Arrays.copyOf(subPerm, subPerm.length + 1);
                for (int j = newPerm.length - 1; j > i; --j) {
                    newPerm[j] = newPerm[j - 1];
                }
                newPerm[i] = first;
                perms.add(newPerm);
            }
        }

        return perms;
    }

    public class SuffixArray {

        
        

        public int[] suffixArray(CharSequence S) {
            int n = S.length();
            Integer[] order = new Integer[n];
            for (int i = 0; i < n; i++) {
                order[i] = n - 1 - i;
            }

            

            Arrays.sort(order, (a, b) -> Character.compare(S.charAt(a), S.charAt(b)));

            int[] sa = new int[n];
            int[] classes = new int[n];
            for (int i = 0; i < n; i++) {
                sa[i] = order[i];
                classes[i] = S.charAt(i);
            }
            

            


            for (int len = 1; len < n; len *= 2) {
                int[] c = classes.clone();
                for (int i = 0; i < n; i++) {
                    

                    

                    classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;
                }
                

                

                int[] cnt = new int[n];
                for (int i = 0; i < n; i++) {
                    cnt[i] = i;
                }
                int[] s = sa.clone();
                for (int i = 0; i < n; i++) {
                    

                    

                    int s1 = s[i] - len;
                    

                    if (s1 >= 0) {
                        sa[cnt[classes[s1]]++] = s1;
                    }
                }
            }
            return sa;
        }

        

        public int[] rotationArray(CharSequence S) {
            int n = S.length();
            Integer[] order = new Integer[n];
            for (int i = 0; i < n; i++) {
                order[i] = i;
            }
            Arrays.sort(order, (a, b) -> Character.compare(S.charAt(a), S.charAt(b)));
            int[] sa = new int[n];
            int[] classes = new int[n];
            for (int i = 0; i < n; i++) {
                sa[i] = order[i];
                classes[i] = S.charAt(i);
            }
            for (int len = 1; len < n; len *= 2) {
                int[] c = classes.clone();
                for (int i = 0; i < n; i++) {
                    classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && c[(sa[i - 1] + len / 2) % n] == c[(sa[i] + len / 2) % n] ? classes[sa[i - 1]] : i;
                }
                int[] cnt = new int[n];
                for (int i = 0; i < n; i++) {
                    cnt[i] = i;
                }
                int[] s = sa.clone();
                for (int i = 0; i < n; i++) {
                    int s1 = (s[i] - len + n) % n;
                    sa[cnt[classes[s1]]++] = s1;
                }
            }
            return sa;
        }

        

        public int[] lcp(int[] sa, CharSequence s) {
            int n = sa.length;
            int[] rank = new int[n];
            for (int i = 0; i < n; i++) {
                rank[sa[i]] = i;
            }
            int[] lcp = new int[n - 1];
            for (int i = 0, h = 0; i < n; i++) {
                if (rank[i] < n - 1) {
                    for (int j = sa[rank[i] + 1];
                         Math.max(i, j) + h < s.length() && s.charAt(i + h) == s.charAt(j + h);
                         ++h) {
                    }
                    lcp[rank[i]] = h;
                    if (h > 0) {
                        --h;
                    }
                }
            }
            return lcp;
        }

        public void main() {
            String s1 = "abcab";
            int[] sa1 = suffixArray(s1);

            

            for (int p : sa1) {
                System.out.println(s1.substring(p));
            }

            System.out.println("lcp = " + Arrays.toString(lcp(sa1, s1)));

            

            Random rnd = new Random(1);
            for (int step = 0; step < 100000; step++) {
                int n = rnd.nextInt(100) + 1;
                StringBuilder s = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    s.append((char) ('\1' + rnd.nextInt(10)));
                }
                int[] sa = suffixArray(s);
                int[] ra = rotationArray(s.toString() + '\0');
                int[] lcp = lcp(sa, s);
                for (int i = 0; i + 1 < n; i++) {
                    String a = s.substring(sa[i]);
                    String b = s.substring(sa[i + 1]);
                    if (a.compareTo(b) >= 0
                            || !a.substring(0, lcp[i]).equals(b.substring(0, lcp[i]))
                            || (a + " ").charAt(lcp[i]) == (b + " ").charAt(lcp[i])
                            || sa[i] != ra[i + 1]) {
                        throw new RuntimeException();
                    }
                }
            }
            System.out.println("Test passed");
        }
    }

    class LazySegmentTree {

        final int MAX = 262146;
        int tree[] = new int[MAX];
        int lazy[] = new int[MAX];

        void updateRangeUtil(int si, int ss, int se, int us,
                             int ue, int diff) {
            if (lazy[si] != 0) {
                tree[si] += (se - ss + 1) * lazy[si];

                if (ss != se) {
                    lazy[si * 2 + 1] += lazy[si];
                    lazy[si * 2 + 2] += lazy[si];
                }

                lazy[si] = 0;
            }

            if (ss > se || ss > ue || se < us) {
                return;
            }

            if (ss >= us && se <= ue) {
                tree[si] += (se - ss + 1) * diff;

                if (ss != se) {
                    lazy[si * 2 + 1] += diff;
                    lazy[si * 2 + 2] += diff;
                }
                return;
            }

            int mid = (ss + se) / 2;
            updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
            updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

            tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
        }

        void updateRange(int n, int us, int ue, int diff) {
            updateRangeUtil(0, 0, n - 1, us, ue, diff);
        }

        int getSumUtil(int ss, int se, int qs, int qe, int si) {
            if (lazy[si] != 0) {
                tree[si] += (se - ss + 1) * lazy[si];

                if (ss != se) {
                    lazy[si * 2 + 1] += lazy[si];
                    lazy[si * 2 + 2] += lazy[si];
                }

                lazy[si] = 0;
            }

            if (ss > se || ss > qe || se < qs) {
                return 0;
            }
            if (ss >= qs && se <= qe) {
                return tree[si];
            }

            int mid = (ss + se) / 2;
            return getSumUtil(ss, mid, qs, qe, 2 * si + 1)
                    + getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
        }

        int getSum(int n, int qs, int qe) {
            

            if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }

            return getSumUtil(0, n - 1, qs, qe, 0);
        }

        void constructSTUtil(int arr[], int ss, int se, int si) {
            

            if (ss > se) {
                return;
            }

            
            if (ss == se) {
                tree[si] = arr[ss];
                return;
            }

            
            int mid = (ss + se) / 2;
            constructSTUtil(arr, ss, mid, si * 2 + 1);
            constructSTUtil(arr, mid + 1, se, si * 2 + 2);

            tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
        }

        void constructST(int arr[], int n) {
            

            constructSTUtil(arr, 0, n - 1, 0);
        }

        public void main() {
            int arr[] = {1, 3, 5, 7, 9, 11};
            int n = arr.length;
            LazySegmentTree segTree = new LazySegmentTree();

            

            segTree.constructST(arr, n);

            

            System.out.println("Sum of values in given range = "
                    + segTree.getSum(n, 1, 3));

            

            segTree.updateRange(n, 1, 5, 10);

            

            System.out.println("Updated sum of values in given range = "
                    + segTree.getSum(n, 1, 3));
        }
    }

    class SegmentTreeRMQ {

        int st[]; 


        

        int minVal(int x, int y) {
            return (x < y) ? x : y;
        }

        

        

        int getMid(int s, int e) {
            return s + (e - s) / 2;
        }

        
        int RMQUtil(int ss, int se, int qs, int qe, int index) {
            

            

            if (qs <= ss && qe >= se) {
                return st[index];
            }

            

            if (se < qs || ss > qe) {
                return Integer.MAX_VALUE;
            }

            

            int mid = getMid(ss, se);
            return minVal(RMQUtil(ss, mid, qs, qe, 2 * index + 1),
                    RMQUtil(mid + 1, se, qs, qe, 2 * index + 2));
        }

        

        

        int RMQ(int n, int qs, int qe) {
            

            if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }

            return RMQUtil(0, n - 1, qs, qe, 0);
        }

        

        

        int constructSTUtil(int arr[], int ss, int se, int si) {
            

            

            if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
            }

            

            

            int mid = getMid(ss, se);
            st[si] = minVal(constructSTUtil(arr, ss, mid, si * 2 + 1),
                    constructSTUtil(arr, mid + 1, se, si * 2 + 2));
            return st[si];
        }

        
        void constructST(int arr[], int n) {
            


            

            int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));

            

            int max_size = 2 * (int) Math.pow(2, x) - 1;
            st = new int[max_size]; 


            

            constructSTUtil(arr, 0, n - 1, 0);
        }

        

        public void main(String args[]) {
            int arr[] = {1, 3, 2, 7, 9, 11};
            int n = arr.length;
            SegmentTreeRMQ tree = new SegmentTreeRMQ();

            

            tree.constructST(arr, n);

            int qs = 1;  

            int qe = 5;  


            

            System.out.println("Minimum of values in range [" + qs + ", "
                    + qe + "] is = " + tree.RMQ(n, qs, qe));
        }
    }

    class DisjointUnionSets {

        int[] rank, parent;
        int n;

        

        public DisjointUnionSets(int n) {
            rank = new int[n];
            parent = new int[n];
            this.n = n;
            makeSet();
        }

        

        void makeSet() {
            for (int i = 0; i < n; i++) {
                

                

                parent[i] = i;
            }
        }

        

        int find(int x) {
            

            

            if (parent[x] != x) {
                

                

                

                parent[x] = find(parent[x]);

                

                

                

            }

            return parent[x];
        }

        

        

        void union(int x, int y) {
            

            int xRoot = find(x), yRoot = find(y);

            

            

            if (xRoot == yRoot) {
                return;
            }

            

            if (rank[xRoot] < rank[yRoot]) 

            

            {
                parent[xRoot] = yRoot;
            } 

            else if (rank[yRoot] < rank[xRoot]) 

            

            {
                parent[yRoot] = xRoot;
            } else 

            {
                

                

                parent[yRoot] = xRoot;

                

                

                rank[xRoot] = rank[xRoot] + 1;
            }
        }
    }
}