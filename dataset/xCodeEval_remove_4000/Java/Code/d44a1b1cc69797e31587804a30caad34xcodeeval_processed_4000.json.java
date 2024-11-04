
import java.io.*;
import java.util.*;

public final class Main {

    static PrintWriter out = new PrintWriter(System.out);
    static FastReader in = new FastReader();
    static Pair[] moves = new Pair[]{new Pair(-1, 0), new Pair(0, 1), new Pair(1, 0), new Pair(0, -1)};
    static int mod = (int) (1e9 + 7);
    static int mod2 = 998244353;

    public static void main(String[] args) {
        int tt = i();
        while (tt-- > 0) {
            solve();
        }
        out.flush();
    }

    static int[] arr;

    public static void solve() {

        ThreePair impo = null;
        ThreePair crew = null;

        List<ThreePair> impolist = new ArrayList<>();
        List<ThreePair> crewlist = new ArrayList<>();

        int n = i();
        











        for (int i = 1; i < n; i += 3) {
            int ask = ask(i, i + 1, i + 2);
            if (ask == 0) {
                if (impo == null) {
                    impo = new ThreePair(i, i + 1, i + 2);
                } else {
                    impolist.add(new ThreePair(i, i + 1, i + 2));
                }
            }
            if (ask == 1) {
                if (crew == null) {
                    crew = new ThreePair(i, i + 1, i + 2);
                } else {
                    crewlist.add(new ThreePair(i, i + 1, i + 2));
                }
            }
        }

        Map<Boolean, List<Integer>> map = get(impo, crew);

        int ii = map.get(false).get(0);
        int jj = map.get(true).get(0);

        List<Integer> impos = new ArrayList<>();
        impos.addAll(map.get(false));
        impos.addAll(get(ii, jj, impolist, crewlist));

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < impos.size(); i++) {
            sb.append(impos.get(i));
            if (i + 1 < impos.size()) {
                sb.append(" ");
            }
        }
        out.println("! " + impos.size() + " " + sb.toString());
        out.flush();
    }

    private static List<Integer> get(int ii, int jj, List<ThreePair> impolist, List<ThreePair> crewlist) {
        List<Integer> ans = new ArrayList<>();
        for (ThreePair tp : impolist) {
            int x = tp.i;
            int y = tp.j;
            int z = tp.k;
            int ask = ask(x, y, jj);
            if (ask == 1) {
                ans.add(z);
                ask = ask(x, ii, jj);
                if (ask == 1) {
                    ans.add(y);
                } else {
                    ans.add(x);
                }
            } else {
                ans.add(x);
                ans.add(y);
                ask = ask(z, ii, jj);
                if (ask == 0) {
                    ans.add(z);
                }
            }
        }

        for (ThreePair tp : crewlist) {
            int x = tp.i;
            int y = tp.j;
            int z = tp.k;
            int ask = ask(x, y, ii);
            if (ask == 0) {
                ask = ask(x, ii, jj);
                if (ask == 1) {
                    ans.add(y);
                } else {
                    ans.add(x);
                }
            } else {
                ask = ask(z, ii, jj);
                if (ask == 0) {
                    ans.add(z);
                }
            }
        }
        return ans;
    }

    static Map<Boolean, List<Integer>> get(ThreePair impo, ThreePair crew) {
        int a1 = impo.i;
        int a2 = impo.j;
        int a3 = impo.k;
        int b1 = crew.i;
        int b2 = crew.j;
        int b3 = crew.k;

        int ask = ask(a1, a2, b1);
        if (ask == 1) {
            Map<Boolean, List<Integer>> ans = ask(a3, b1, new int[]{a1, a2, b2, b3});
            ans.get(true).add(b1);
            ans.get(false).add(a3);
            return ans;
        }

        ask = ask(a1, a2, b2);
        if (ask == 1) {
            Map<Boolean, List<Integer>> ans = ask(a3, b2, new int[]{a1, a2, b3});
            ans.get(true).add(b2);
            ans.get(false).add(a3);
            ans.get(false).add(b1);
            return ans;
        }

        

        ask = ask(a1, b1, b2);
        if (ask == 1) {
            Map<Boolean, List<Integer>> ans = ask(a1, b1, new int[]{a3, b3});
            ans.get(true).add(b1);
            ans.get(true).add(b2);
            ans.get(false).add(a1);
            ans.get(false).add(a2);
            return ans;
        }
        ask = ask(a1, b1, b3);
        if (ask == 1) {
            Map<Boolean, List<Integer>> ans = ask(a1, b1, new int[]{a3});
            ans.get(true).add(b1);
            ans.get(true).add(b3);
            ans.get(false).add(a1);
            ans.get(false).add(a2);
            ans.get(false).add(b2);
            return ans;
        }

        Map<Boolean, List<Integer>> ans = ask(a1, b2, new int[]{a3});
        ans.get(true).add(b2);
        ans.get(true).add(b3);
        ans.get(false).add(a1);
        ans.get(false).add(a2);
        ans.get(false).add(b1);
        return ans;
    }

    static Map ask(int a, int b, int[] arr) {
        Map<Boolean, List<Integer>> map = new HashMap<>();
        map.put(true, new ArrayList<>());
        map.put(false, new ArrayList<>());
        for (int x : arr) {
            int ask = ask(a, b, x);
            if (ask == 1) {
                map.get(true).add(x);
            } else {
                map.get(false).add(x);
            }
        }
        return map;
    }

    static int ask(int a, int b, int c) {
        out.println("? " + a + " " + b + " " + c);
        out.flush();
        return i();
    }

    static long[] pre(int[] a) {
        long[] pre = new long[a.length + 1];
        pre[0] = 0;
        for (int i = 0; i < a.length; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        return pre;
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

    static int[][] id2(int N) {
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