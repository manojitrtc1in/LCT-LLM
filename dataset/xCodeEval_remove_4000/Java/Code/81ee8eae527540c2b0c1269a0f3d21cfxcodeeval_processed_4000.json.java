
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public final class Main {

    

    static PrintWriter out = new PrintWriter(System.out);
    static FastReader in = new FastReader();
    static Pair[] moves = new Pair[]{new Pair(-1, 0), new Pair(0, 1), new Pair(1, 0), new Pair(0, -1)};
    static int mod = (int) (1e9 + 7);
    static int mod2 = 998244353;

    public static void main(String[] args) {
        int tt = 1;
        while (tt-- > 0) {
            solve();
        }
        out.flush();
    }

    public static void solve() {
        int n = i();
        int k = i();
        int[] a = input(n);

        if (k == 0) {
            out.println(n);
            for (int i = 1; i <= n; i++) {
                out.print(i + " ");
            }
            out.println();
            return;
        }

        Map<Integer, Integer> no = new HashMap<>();
        for (int i = 0; i < n; i++) {
            no.put(a[i], i + 1);
        }

        

        int l = Integer.highestOneBit(k);
        int lb = -1;
        int mask = 0;
        for (int i = 30; i >= 0; i--) {
            int b = 1 << i;
            if (b == l) {
                lb = i;
                break;
            }
            mask += b;
        }

        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int m = mask & a[i];
            if (!map.containsKey(m)) {
                map.put(m, new ArrayList<>());
            }
            map.get(m).add(a[i]);
        }
        List<Integer> ans = new ArrayList<>();
        Set<Entry<Integer, List<Integer>>> entries = map.entrySet();

        out:
        for (Entry<Integer, List<Integer>> entry : entries) {
            List<Integer> value = entry.getValue();

            id4 trie = new id4(31);

            for (int i = 0; i < value.size(); i++) {
                int cur = value.get(i);
                trie.add(cur);
            }

            for (int i = 0; i < value.size(); i++) {
                int cur = value.get(i);
                if ((cur & l) == l) {
                    continue;
                }
                long xm = trie.id2(cur);
                if (xm >= k) {
                    int op = (int) (cur ^ xm);
                    if (no.containsKey(op)) {
                        ans.add(cur);
                        ans.add(op);
                        continue out;
                    }
                }
            }
            ans.add(value.get(0));
        }
        if (ans.size() == 1) {
            out.println(-1);
            return;
        }
        out.println(ans.size());
        for (int x : ans) {
            out.print(no.get(x) + " ");
        }
        out.println();
    }


    public static class L {

        public int[] a;
        public int p = 0;

        public L(int n) {
            a = new int[n];
        }

        public L add(int n) {
            if (p >= a.length) {
                a = Arrays.copyOf(a, a.length * 3 / 2 + 1);
            }
            a[p++] = n;
            return this;
        }

        public int size() {
            return p;
        }

        public L clear() {
            p = 0;
            return this;
        }

        public int[] toArray() {
            return Arrays.copyOf(a, p);
        }

        @Override
        public String toString() {
            return Arrays.toString(toArray());
        }
    }


    public static class id4 {

        

        public L next;
        public int gen;
        public int W;

        public id4(int W) {
            this.W = W;
            this.next = new L(2);
            this.gen = 1;
            this.next.add(-1).add(-1);
        }

        public void add(long s) {
            int cur = 0;
            for (int d = W - 1; d >= 0; d--) {
                int v = (int) (s >>> d & 1);
                int nex = next.a[cur * 2 + v];
                if (nex == -1) {
                    nex = next.a[cur * 2 + v] = gen++;
                    next.add(-1).add(-1);
                }
                cur = nex;
            }
        }

        public long id2(long x) {
            if (gen == 1) {
                return 0;
            }
            int cur = 0;
            long ret = 0;
            for (int d = W - 1; d >= 0; d--) {
                if (cur == -1) {
                    ret |= x << -d >>> -d;
                    break;
                }
                int xd = (int) (x >>> d & 1);
                if (next.a[cur * 2 | xd ^ 1] != -1) {
                    ret |= 1L << d;
                    cur = next.a[cur * 2 | xd ^ 1];
                } else {
                    cur = next.a[cur * 2 | xd];
                }
            }
            return ret;
        }

        public int[] des() {
            int[] des = new int[gen];
            for (int i = gen - 1; i >= 0; i--) {
                if (next.a[2 * i] != -1) {
                    des[i] += des[next.a[2 * i]];
                }
                if (next.a[2 * i + 1] != -1) {
                    des[i] += des[next.a[2 * i + 1]];
                }
                if (des[i] == 0) {
                    des[i] = 1;
                }
            }
            return des;
        }

        public int mex(long x, int[] des) {
            int ret = 0;
            for (int cur = 0, d = W - 1; d >= 0 && cur != -1; d--) {
                int xd = (int) (x >>> d & 1);
                if (next.a[2 * cur | xd] != -1 && des[next.a[2 * cur | xd]] == 1 << d) {
                    ret |= 1 << d;
                    cur = next.a[2 * cur | xd ^ 1];
                } else {
                    cur = next.a[2 * cur | xd];
                }
            }
            return ret;
        }

        public boolean contains(long x, int low) {
            int cur = 0;
            for (int d = W - 1; d >= low; d--) {
                int v = (int) (x >>> d & 1);
                int nex = next.a[cur * 2 + v];
                if (nex == -1) {
                    return false;
                }
            }
            return true;
        }
    }

    static long sum(int[] a) {
        long sum = 0;
        for (int x : a) {
            sum += x;
        }
        return sum;
    }

    static long[] pre(int[] a) {
        long[] pre = new long[a.length + 1];
        pre[0] = 0;
        for (int i = 0; i < a.length; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        return pre;
    }

    static long[] post(int[] a) {
        long[] post = new long[a.length + 1];
        post[0] = 0;
        for (int i = 0; i < a.length; i++) {
            post[i + 1] = post[i] + a[a.length - 1 - i];
        }
        return post;
    }

    static long[] pre(long[] a) {
        long[] pre = new long[a.length + 1];
        pre[0] = 0;
        for (int i = 0; i < a.length; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        return pre;
    }

    static void print(char A[]) {
        for (char c : A) {
            out.print(c);
        }
        out.println();
    }

    static void print(boolean A[]) {
        for (boolean c : A) {
            out.print(c + " ");
        }
        out.println();
    }

    static void print(int A[]) {
        for (int c : A) {
            out.print(c + " ");
        }
        out.println();
    }

    static void print(long A[]) {
        for (long i : A) {
            out.print(i + " ");
        }
        out.println();
    }

    static void print(List<Integer> A) {
        for (int a : A) {
            out.print(a + " ");
        }
    }

    static int i() {
        return in.nextInt();
    }

    static long l() {
        return in.nextLong();
    }

    static double d() {
        return in.nextDouble();
    }

    static String s() {
        return in.nextLine();
    }

    static String c() {
        return in.next();
    }

    static int[][] id3(int N) {
        int A[][] = new int[N][2];
        for (int i = 0; i < N; i++) {
            A[i] = new int[]{i, in.nextInt()};
        }
        return A;
    }

    static int[] input(int N) {
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }
        return A;
    }

    static long[] inputLong(int N) {
        long A[] = new long[N];
        for (int i = 0; i < A.length; i++) {
            A[i] = in.nextLong();
        }
        return A;
    }

    static int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }

    static long GCD(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }

    static long LCM(int a, int b) {
        return (long) a / GCD(a, b) * b;
    }

    static long LCM(long a, long b) {
        return a / GCD(a, b) * b;
    }

    

    static int lowerbound(int[] a, int x) {
        int l = 0;
        int r = a.length - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (a[m] <= x) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    static void shuffle(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
    }

    static void id1(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr);
    }

    static void id1(int[][] arr, Comparator<? super int[]> comparator) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int[] temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr, comparator);
    }

    static void id1(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            long temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr);
    }

    static boolean id0(double number) {
        double sqrt = Math.sqrt(number);
        return ((sqrt - Math.floor(sqrt)) == 0);
    }

    static void swap(int A[], int a, int b) {
        int t = A[a];
        A[a] = A[b];
        A[b] = t;
    }

    static void swap(char A[], int a, int b) {
        char t = A[a];
        A[a] = A[b];
        A[b] = t;
    }

    static long pow(long a, long b, int mod) {
        long pow = 1;
        long x = a;
        while (b != 0) {
            if ((b & 1) != 0) {
                pow = (pow * x) % mod;
            }
            x = (x * x) % mod;
            b /= 2;
        }
        return pow;
    }

    static long pow(long a, long b) {
        long pow = 1;
        long x = a;
        while (b != 0) {
            if ((b & 1) != 0) {
                pow *= x;
            }
            x = x * x;
            b /= 2;
        }
        return pow;
    }

    static long modInverse(long x, int mod) {
        return pow(x, mod - 2, mod);
    }

    static boolean isPrime(long N) {
        if (N <= 1) {
            return false;
        }
        if (N <= 3) {
            return true;
        }
        if (N % 2 == 0 || N % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= N; i = i + 6) {
            if (N % i == 0 || N % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    public static String reverse(String str) {
        if (str == null) {
            return null;
        }
        return new StringBuilder(str).reverse().toString();
    }

    public static void reverse(int[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            int tmp = arr[i];
            arr[arr.length - 1 - i] = tmp;
            arr[i] = arr[arr.length - 1 - i];
        }
    }

    public static String repeat(char ch, int repeat) {
        if (repeat <= 0) {
            return "";
        }
        final char[] buf = new char[repeat];
        for (int i = repeat - 1; i >= 0; i--) {
            buf[i] = ch;
        }
        return new String(buf);
    }

    public static int[] manacher(String s) {
        char[] chars = s.toCharArray();
        int n = s.length();
        int[] d1 = new int[n];
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : Math.min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && chars[i - k] == chars[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        return d1;
    }

    public static int[] kmp(String s) {
        int n = s.length();
        int[] res = new int[n];
        for (int i = 1; i < n; ++i) {
            int j = res[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = res[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                ++j;
            }
            res[i] = j;
        }
        return res;
    }
}

class Pair {

    int i;
    int j;

    Pair(int i, int j) {
        this.i = i;
        this.j = j;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Pair pair = (Pair) o;
        return i == pair.i && j == pair.j;
    }

    @Override
    public int hashCode() {
        return Objects.hash(i, j);
    }
}

class ThreePair {

    int i;
    int j;
    int k;

    ThreePair(int i, int j, int k) {
        this.i = i;
        this.j = j;
        this.k = k;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        ThreePair pair = (ThreePair) o;
        return i == pair.i && j == pair.j && k == pair.k;
    }

    @Override
    public int hashCode() {
        return Objects.hash(i, j);
    }
}

class FastReader {

    BufferedReader br;
    StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

class Node {

    int val;

    public Node(int val) {
        this.val = val;
    }
}


class ST {

    int n;
    Node[] st;

    ST(int n) {
        this.n = n;
        st = new Node[4 * Integer.highestOneBit(n)];
    }

    void build(Node[] nodes) {
        build(0, 0, n - 1, nodes);
    }

    private void build(int id, int l, int r, Node[] nodes) {
        if (l == r) {
            st[id] = nodes[l];
            return;
        }
        int mid = (l + r) >> 1;
        build((id << 1) + 1, l, mid, nodes);
        build((id << 1) + 2, mid + 1, r, nodes);
        st[id] = comb(st[(id << 1) + 1], st[(id << 1) + 2]);
    }

    void update(int i, Node node) {
        update(0, 0, n - 1, i, node);
    }

    private void update(int id, int l, int r, int i, Node node) {
        if (i < l || r < i) {
            return;
        }
        if (l == r) {
            st[id] = node;
            return;
        }
        int mid = (l + r) >> 1;
        update((id << 1) + 1, l, mid, i, node);
        update((id << 1) + 2, mid + 1, r, i, node);
        st[id] = comb(st[(id << 1) + 1], st[(id << 1) + 2]);
    }

    Node get(int x, int y) {
        return get(0, 0, n - 1, x, y);
    }

    private Node get(int id, int l, int r, int x, int y) {
        if (x > r || y < l) {
            return new Node(0);
        }
        if (x <= l && r <= y) {
            return st[id];
        }
        int mid = (l + r) >> 1;
        return comb(get((id << 1) + 1, l, mid, x, y), get((id << 1) + 2, mid + 1, r, x, y));
    }

    Node comb(Node a, Node b) {
        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }
        return new Node(a.val | b.val);
    }
}