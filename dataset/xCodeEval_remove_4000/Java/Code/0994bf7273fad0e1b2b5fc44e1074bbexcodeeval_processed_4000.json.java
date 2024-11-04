

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.Serializable;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Set;
import java.util.Stack;

public class Main {

    InputReader in;
    Printer out;

    long MOD = 1000000007;

    private void start() throws Exception {
        String str = in.next();
        int n = str.length();

        int forward[] = new int[str.length()];
        int backward[] = new int[str.length()];

        Arrays.fill(forward, -1);
        Arrays.fill(backward, -1);

        Stack<Integer> stack = new Stack();
        for (int i = 0; i < n; i++) {
            char c = str.charAt(i);

            if (c == '(') {
                stack.push(i);
            } else if (!stack.isEmpty()) {
                int val = stack.pop();

                forward[val] = i;
            }
        }































        ArrayList<Pair<Integer, Integer>> intervals = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (forward[i] != -1) {
                intervals.add(new Pair<>(i, forward[i]));
            }
        }
        Collections.sort(intervals, (Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) -> {
            if (p1.key.intValue() != p2.key) {
                return p1.key - p2.key;
            }

            return p1.value - p2.value;
        });

        int q = in.nextInt();
        ArrayList<Query> list = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;

            Query query = new Query(i, l, r);
            list.add(query);
        }

        Collections.sort(list, (Query A, Query B) -> {
            if (A.l != B.l) {
                return A.l - B.l;
            }

            return A.r - B.r;
        });

        int addedIndex = 0;
        Bit bit = new Bit(n);
        for (Pair<Integer, Integer> pair : intervals) {
            bit.update(pair.value + 1, pair.value + 1, 1);
        }












        outer:
        for (Query query : list) {
            if (addedIndex >= intervals.size()) {
                break;
            }

            Pair<Integer, Integer> pair = intervals.get(addedIndex);
            while (pair.key < query.l) {
                bit.update(pair.value + 1, pair.value + 1, -1);
                addedIndex++;

                if (addedIndex >= intervals.size()) {
                    break outer;
                }
                
                pair = intervals.get(addedIndex);
            }

            query.res = 2 * bit.query(1, query.r + 1);
            


        }

        Collections.sort(list, (Query A, Query B) -> {
            return A.index - B.index;
        });
        for (Query query : list) {
            out.println(query.res);
        }
    }

    class Query {

        int l, r;
        int index;
        long res;

        Query(int ind, int l, int r) {
            index = ind;
            this.l = l;
            this.r = r;
        }

        @Override
        public String toString() {
            return (l + 1) + "=" + (r + 1);
        }
    }

    Pair<Integer, Integer> diameter(int root, HashSet<Integer> visited, ArrayList<Integer>[] list) {
        visited.add(root);

        int maxI = root, max = -1;
        for (int child : list[root]) {
            if (visited.contains(child)) {
                continue;
            }

            Pair<Integer, Integer> pair = diameter(child, visited, list);
            if (max < pair.value) {
                maxI = pair.key;
                max = pair.value;
            }
        }

        return new Pair<>(maxI, max + 1);
    }

    long power(long x, long n) {
        if (n <= 0) {
            return 1;
        }
        long y = power(x, n / 2);

        if ((n & 1) == 1) {
            return (((y * y) % MOD) * x) % MOD;
        }

        return (y * y) % MOD;
    }

    public long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
        return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).longValue();
    }

    public Integer[] input(int n) {
        Integer a[] = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        return a;
    }

    public static void main(String[] args) throws Exception {
        InputReader in;
        PrintStream out;





        in = new InputReader(System.in);
        out = System.out;

        Main main = new Main();

        main.in = in;
        main.out = new Printer(out);

        main.start();
        main.out.flush();
    }

    private static class InputReader {

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id9 filter;

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
            while (id2(c)) {
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
            } while (!id2(c));
            return res * sgn;
        }

        public String nextString() {
            int c = read();
            while (id2(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!id2(c));
            return res.toString();
        }

        public double nextDouble() {
            int c = read();
            while (id2(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id2(c) && c != '.') {
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
                while (!id2(c)) {
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
            while (id2(c)) {
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
            } while (!id2(c));
            return res * sgn;
        }

        public boolean id2(int c) {
            if (filter != null) {
                return filter.id2(c);
            }
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return nextString();
        }

        public interface id9 {

            public boolean id2(int ch);
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

        public void println(Object[] o) {
            println(Arrays.deepToString(o));
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

    private class Pair<T, U> implements Serializable {

        int id3;

        private T key;

        public T getKey() {
            return key;
        }

        private U value;

        public U getValue() {
            return value;
        }

        public Pair(T key, U value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public String toString() {
            return key + "=" + value;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }

            final Pair other = (Pair) obj;
            if (!this.key.equals(other.key)) {
                return false;
            }

            return this.value.equals(other.value);
        }

        @Override
        public int hashCode() {
            return key.hashCode() + 13 * value.hashCode();
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

    class id5 {

        int m, n;
        boolean[][] graph;
        boolean seen[];
        int matchL[];   

        int matchR[];   


        public id5(boolean[][] graph) {
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

    public static Set<Integer[]> id6(Integer[] num) {
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
        Set<Integer[]> id4 = id6(remainder);
        for (Integer[] subPerm : id4) {
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

    class id7 {

        final int MAX = 262146;
        int tree[] = new int[MAX];
        int lazy[] = new int[MAX];

        void id8(int si, int ss, int se, int us,
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
            id8(si * 2 + 1, ss, mid, us, ue, diff);
            id8(si * 2 + 2, mid + 1, se, us, ue, diff);

            tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
        }

        void updateRange(int n, int us, int ue, int diff) {
            id8(0, 0, n - 1, us, ue, diff);
        }

        int id10(int ss, int se, int qs, int qe, int si) {
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
            return id10(ss, mid, qs, qe, 2 * si + 1)
                    + id10(mid + 1, se, qs, qe, 2 * si + 2);
        }

        int getSum(int n, int qs, int qe) {
            

            if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }

            return id10(0, n - 1, qs, qe, 0);
        }

        void id0(int arr[], int ss, int se, int si) {
            

            if (ss > se) {
                return;
            }

            
            if (ss == se) {
                tree[si] = arr[ss];
                return;
            }

            
            int mid = (ss + se) / 2;
            id0(arr, ss, mid, si * 2 + 1);
            id0(arr, mid + 1, se, si * 2 + 2);

            tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
        }

        void constructST(int arr[], int n) {
            

            id0(arr, 0, n - 1, 0);
        }

        public void main() {
            int arr[] = {1, 3, 5, 7, 9, 11};
            int n = arr.length;
            id7 segTree = new id7();

            

            segTree.constructST(arr, n);

            

            System.out.println("Sum of values in given range = "
                    + segTree.getSum(n, 1, 3));

            

            segTree.updateRange(n, 1, 5, 10);

            

            System.out.println("Updated sum of values in given range = "
                    + segTree.getSum(n, 1, 3));
        }
    }

    class id1 {

        int[] rank, parent;
        int n;

        

        public id1(int n) {
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