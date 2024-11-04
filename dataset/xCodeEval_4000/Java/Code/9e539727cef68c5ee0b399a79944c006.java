

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
import java.util.Set;

public class Main {

    InputReader in;
    Printer out;

    long MOD = 1000000007;
    int n, m;
    ArrayList<Query> qList = new ArrayList<>();
    ArrayList<Integer>[] list;

    private void start() throws Exception {
        n = in.nextInt();
        m = in.nextInt();
        int q = in.nextInt();

        int arr[][] = new int[n + 1][m + 1];
        int len[] = new int[n + 1];

        list = new ArrayList[q + 1];

        for (int i = 0; i <= q; i++) {
            list[i] = new ArrayList<>();
        }

        int cur = 0;

        for (int I = 1; I <= q; I++) {
            int type = in.nextInt();

            if (type == 1) {
                int i = in.nextInt();
                int j = in.nextInt();

                Query qu = new Query();
                qu.ind = I;
                qu.i = i;
                qu.j = j;
                qu.type = type;

                qList.add(qu);

                list[cur].add(I);
                cur = I;
            } else if (type == 2) {
                int i = in.nextInt();
                int j = in.nextInt();

                Query qu = new Query();
                qu.ind = I;
                qu.i = i;
                qu.j = j;
                qu.type = type;

                qList.add(qu);

                list[cur].add(I);
                cur = I;
            } else if (type == 3) {
                int i = in.nextInt();

                Query qu = new Query();
                qu.ind = I;
                qu.i = i;
                qu.type = type;

                qList.add(qu);

                list[cur].add(I);
                cur = I;
            } else {
                int k = in.nextInt();

                Query qu = new Query();
                qu.ind = I;
                qu.k = k;
                qu.type = type;

                qList.add(qu);

                list[k].add(I);
                cur = I;
            }
        }

        int ans = 0;
        for (int child : list[0]) {
            dfs(child, ans, len, arr);
        }

        for (Query qu : qList) {
            out.println(qu.ans);
        }
    }

    void dfs(int root, int ans, int len[], int[][] state) {



        Query qu = qList.get(root - 1);

        if (qu.type == 1) {
            boolean changed = false;

            if (state[qu.i][qu.j] == 0) {
                state[qu.i][qu.j] = 1;
                len[qu.i]++;
                ans++;

                changed = true;
            }


















            qu.ans = ans;

            for (int child : list[root]) {
                dfs(child, ans, len, state);
            }

            if (changed) {
                state[qu.i][qu.j] = 0;
                len[qu.i]--;
                ans--;
            }
        } else if (qu.type == 2) {
            boolean changed = false;

            if (state[qu.i][qu.j] == 1) {
                state[qu.i][qu.j] = 0;
                len[qu.i]--;
                ans--;

                changed = true;
            }


















            qu.ans = ans;

            for (int child : list[root]) {
                dfs(child, ans, len, state);
            }

            if (changed) {
                state[qu.i][qu.j] = 1;
                len[qu.i]++;
                ans++;
            }
        } else if (qu.type == 3) {
            for (int j = 1; j <= m; j++) {
                if (state[qu.i][j] == 0) {
                    state[qu.i][j] = 1;
                    len[qu.i]++;
                    ans++;
                } else {
                    state[qu.i][j] = 0;
                    len[qu.i]--;
                    ans--;
                }
            }



















            qu.ans = ans;

            for (int child : list[root]) {
                dfs(child, ans, len, state);
            }

            for (int j = 1; j <= m; j++) {
                if (state[qu.i][j] == 0) {
                    state[qu.i][j] = 1;
                    len[qu.i]++;
                    ans++;
                } else {
                    state[qu.i][j] = 0;
                    len[qu.i]--;
                    ans--;
                }
            }
        } else if (qu.type == 4) {
            qu.ans = ans;

            for (int child : list[root]) {
                dfs(child, ans, len, state);
            }
        }
    }

    class Query {

        int ans, type;
        int ind, i, j, k;
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

        int indexOfSec;

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
}
