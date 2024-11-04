
import java.io.*;
import java.util.*;

public final class Main {

    

    static PrintWriter out = new PrintWriter(System.out);
    static FastReader in = new FastReader();
    static Pair[] moves = new Pair[]{new Pair(-1, 0), new Pair(0, 1), new Pair(1, 0), new Pair(0, -1)};
    static Pair[] movesDiagonal = new Pair[]{new Pair(-1, -1), new Pair(-1, 1), new Pair(1, -1), new Pair(1, 1)};

    static int mod = (int) (1e9 + 7);
    static int mod2 = 998244353;

    public static void main(String[] args) {
        int tt = i();
        while (tt-- > 0) {
            solve();
        }
        out.flush();
    }

    public static void solve() {

        int[] a = input(4);
        String s = s();
        int n = s.length();
        int ac = a[0] + a[2] + a[3];
        int bc = a[1] + a[2] + a[3];

        int ad = 0;
        int bd = 0;

        List<Integer> xa = new ArrayList<>();
        List<Integer> xb = new ArrayList<>();
        List<Integer> xc = new ArrayList<>();

        int left = 0;
        char start = s.charAt(0);
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'A') {
                ad++;
            } else {
                bd++;
            }

            if (i + 1 == n || s.charAt(i + 1) == s.charAt(i)) {
                

                char end = s.charAt(i);
                int len = i - left + 1;
                int p = len / 2;
                if (start == end) {
                    if (p > 0) {
                        xc.add(p);
                    }
                } else {
                    if (start == 'A') {
                        xa.add(p);
                    } else {
                        xb.add(p);
                    }
                }

                if (i + 1 < n) {
                    left = i + 1;
                    start = s.charAt(i + 1);
                }
            }
        }

        if (ad != ac || bd != bc) {
            out.println("NO");
            return;
        }

        xa.sort(Comparator.comparingInt(x -> -x));
        xb.sort(Comparator.comparingInt(x -> -x));
        long xasum = sum(xa);
        long xbsum = sum(xb);
        long xcsum = sum(xc);

        int c = a[2];
        int d = a[3];

        if (xasum >= c && xbsum >= d) {
            out.println("YES");
        } else if (xasum < c && xbsum >= d) {
            xasum += xcsum;
            int diff = (int) (xbsum - d);
            for (int x : xb) {
                if (diff > x) {
                    diff -= x;
                    xasum += (x - 1);
                } else {
                    xasum += Math.max(diff - 1, 0);
                    break;
                }
            }
            if (xasum >= c) {
                out.println("YES");
            } else {
                out.println("NO");
            }

        } else if (xbsum < d && xasum >= c) {
            xbsum += xcsum;
            int diff = (int) (xasum - c);
            for (int x : xa) {
                if (diff > x) {
                    diff -= x;
                    xbsum += (x - 1);
                } else {
                    xbsum += Math.max(diff - 1, 0);
                    break;
                }
            }
            if (xbsum >= d) {
                out.println("YES");
            } else {
                out.println("NO");
            }

        } else {
            if (xcsum >= (c - xasum) + (d - xbsum)) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }


    }

    

    static long upperDiv(long a, long b) {
        return (a / b) + ((a % b == 0) ? 0 : 1);
    }

    static long sum(List<Integer> a) {
        long sum = 0;
        for (int x : a) {
            sum += x;
        }
        return sum;
    }

    static long sum(int[] a) {
        long sum = 0;
        for (int x : a) {
            sum += x;
        }
        return sum;
    }

    static int[] preint(int[] a) {
        int[] pre = new int[a.length + 1];
        pre[0] = 0;
        for (int i = 0; i < a.length; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        return pre;
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

    static int[][] inputWithIdx(int N) {
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

    

    static int lowerbound(List<Long> a, long x) {
        int l = 0;
        int r = a.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (a.get(m) <= x) {
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

    static void shuffleAndSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr);
    }

    static void shuffleAndSort(int[][] arr, Comparator<? super int[]> comparator) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int[] temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr, comparator);
    }

    static void shuffleAndSort(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            long temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr);
    }

    static boolean isPerfectSquare(double number) {
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
        int l = 0;
        int r = arr.length - 1;
        while (l < r) {
            swap(arr, l, r);
            l++;
            r--;
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
        return new Node(GCD(a.val, b.val));
    }

    static int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }
}