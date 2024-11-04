


import java.util.*;
import java.util.Map.Entry;
import java.util.stream.*;
import java.lang.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.io.*;

public class id11 {
    static private final String INPUT = "input.txt";
    static private final String OUTPUT = "output.txt";
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static PrintWriter out = new PrintWriter(System.out);
    static DecimalFormat df = new DecimalFormat("0.0000000");
    final static int mod = (int) (1e9 + 7);
    final static int MAX = Integer.MAX_VALUE;
    final static int MIN = Integer.MIN_VALUE;
    final static long INF = Long.MAX_VALUE;
    final static long NEG_INF = Long.MIN_VALUE;
    static Random rand = new Random();

    


    public static void main(String[] args) throws IOException {
        long time = System.currentTimeMillis();
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;

        


        input();
        preprocess();
        int t = 1;
        t = readInt();
        while (t-- > 0) {
            solve();
        }
        out.flush();

        


        if (!oj)
            System.out.println(Arrays.deepToString(new Object[] { System.currentTimeMillis() - time + " ms" }));
    }

    private static void solve() throws IOException {
        int n = readInt();
        int[] arr = id0(n);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = Math.max(ans, arr[i]);

        out.println(Math.min(solve(arr, ans), solve(arr, ans + 1)));
    }

    private static long solve(int[] arr, int tar) {
        long one = 0, two = 0;
        for (int i = 0; i < arr.length; i++) {
            two += (tar - arr[i]) / 2;
            one += ((tar - arr[i]) & 1);
        }
        long ops = one + two;
        if (two > one) {
            two -= one;
            ops += two / 3;
            if (two % 3 != 0)
                ops++;
        } else if (one > two) {
            one -= two;
            ops += one - 1;
        }
        return ops;
    }

    private static void preprocess() {

    }

    

    

    

    


    


    static class Pair {
        int first, second;

        Pair(int f, int s) {
            first = f;
            second = s;
        }

        public int compareTo(Pair o) {
            if (this.first == o.first)
                return this.second - o.second;
            return this.first - o.first;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == this)
                return true;
            if (obj == null)
                return false;
            if (this.getClass() != obj.getClass())
                return false;
            Pair other = (Pair) (obj);
            if (this.first != other.first)
                return false;
            if (this.second != other.second)
                return false;
            return true;

        }

        @Override
        public int hashCode() {
            return this.first ^ this.second;
        }

        @Override
        public String toString() {
            return this.first + " " + this.second;
        }
    }

    static class DequeNode {
        DequeNode prev, next;
        int val;

        DequeNode(int val) {
            this.val = val;
        }

        DequeNode(int val, DequeNode prev, DequeNode next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }

    


    private static void input() {
        FileInputStream instream = null;
        PrintStream outstream = null;
        try {
            instream = new FileInputStream(INPUT);
            outstream = new PrintStream(new FileOutputStream(OUTPUT));
            System.setIn(instream);
            System.setOut(outstream);
        } catch (Exception e) {
            System.err.println("Error Occurred.");
        }

        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(readLine());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readString() throws IOException {
        return next();
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    static int[] id0(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = readInt();
        return arr;
    }

    static int[][] id1(int n, int m) throws IOException {
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++)
            arr[i] = id0(m);
        return arr;
    }

    static List<Integer> id3(int n) throws IOException {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(readInt());
        return list;
    }

    static long[] id4(int n) throws IOException {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = readLong();
        return arr;
    }

    static long[][] id10(int n, int m) throws IOException {
        long[][] arr = new long[n][m];
        for (int i = 0; i < n; i++)
            arr[i] = id4(m);
        return arr;
    }

    static List<Long> id14(int n) throws IOException {
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(readLong());
        return list;
    }

    static char[] id2(int n) throws IOException {
        return readString().toCharArray();
    }

    static char[][] readMatrix(int n, int m) throws IOException {
        char[][] mat = new char[n][m];
        for (int i = 0; i < n; i++)
            mat[i] = id2(m);
        return mat;
    }

    


    private static void id15(List<Integer> list) {
        for (int i = 0; i < list.size(); i++)
            out.print(list.get(i) + " ");
        out.println(" ");
    }

    private static void id13(List<Long> list) {
        for (int i = 0; i < list.size(); i++)
            out.print(list.get(i) + " ");
        out.println(" ");
    }

    private static void id8(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            out.print(arr[i] + " ");
        out.println(" ");
    }

    private static void id5(int[][] arr) {
        for (int i = 0; i < arr.length; i++)
            id8(arr[i]);
    }

    private static void id7(long[] arr) {
        for (int i = 0; i < arr.length; i++)
            out.print(arr[i] + " ");
        out.println(" ");
    }

    private static void id9(long[][] arr) {
        for (int i = 0; i < arr.length; i++)
            id7(arr[i]);
    }

    


    private static boolean isInteger(String s) {
        try {
            Integer.parseInt(s);
        } catch (NumberFormatException e) {
            return false;
        } catch (NullPointerException e) {
            return false;
        }
        return true;
    }

    private static boolean isLong(String s) {
        try {
            Long.parseLong(s);
        } catch (NumberFormatException e) {
            return false;
        } catch (NullPointerException e) {
            return false;
        }
        return true;
    }

    


    private static void sort(int[] arr) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list);
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void reverseSort(int[] arr) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list, Collections.reverseOrder());
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void sort(long[] arr) {
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list);
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void reverseSort(long[] arr) {
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list, Collections.reverseOrder());
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    


    private static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    private static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    private static long power(long a, long b) {
        if (b == 0)
            return 1L;
        long ans = power(a, b >> 1);
        ans *= ans;
        if ((b & 1) == 1)
            ans *= a;
        return ans;
    }

    private static int mod_power(int a, int b, int mod) {
        if (b == 0)
            return 1;
        int temp = mod_power(a, b >> 1, mod);
        temp %= mod;
        temp = (int) ((1L * temp * temp) % mod);
        if ((b & 1) == 1)
            temp = (int) ((1L * temp * a) % mod);
        return temp;
    }

    private static int multiply(int a, int b) {
        return (int) ((((1L * a) % mod) * ((1L * b) % mod)) % mod);
    }

    private static boolean isPrime(long n) {
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    private static long nCr(long n, long r) {
        if (n - r > r)
            r = n - r;
        long ans = 1L;
        for (long i = r + 1; i <= n; i++)
            ans *= i;
        for (long i = 2; i <= n - r; i++)
            ans /= i;
        return ans;
    }

    


    private static List<Integer> id6(int n) {
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }
        

        List<Integer> list = new ArrayList<>();
        for (int i = 2; i <= n; i++)
            if (prime[i])
                list.add(i);
        return list;
    }

    private static int[] id12(int n) {
        int[] primes = new int[n];
        for (int i = 0; i < n; i++)
            primes[i] = i;
        for (int i = 2; i * i < n; i++) {
            if (primes[i] != i)
                continue;
            for (int j = i * i; j < n; j += i) {
                if (primes[j] == j)
                    primes[j] = i;
            }
        }
        return primes;
    }

    


    private static boolean isPalindrome(String str) {
        int i = 0, j = str.length() - 1;
        while (i < j)
            if (str.charAt(i++) != str.charAt(j--))
                return false;
        return true;
    }

    private static String reverseString(String str) {
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString();
    }

    private static String sortString(String str) {
        int[] arr = new int[256];
        for (char ch : str.toCharArray())
            arr[ch]++;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 256; i++)
            while (arr[i]-- > 0)
                sb.append((char) i);
        return sb.toString();
    }

    


    private static int LIS(int arr[], int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int idx = find1(list, arr[i]);
            if (idx < list.size())
                list.set(idx, arr[i]);
            else
                list.add(arr[i]);
        }
        return list.size();
    }

    private static int find1(List<Integer> list, int val) {
        int ret = list.size(), i = 0, j = list.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (list.get(mid) >= val) {
                ret = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ret;
    }

    private static int LNDS(int[] arr, int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int idx = find2(list, arr[i]);
            if (idx < list.size())
                list.set(idx, arr[i]);
            else
                list.add(arr[i]);
        }
        return list.size();
    }

    private static int find2(List<Integer> list, int val) {
        int ret = list.size(), i = 0, j = list.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (list.get(mid) <= val) {
                i = mid + 1;
            } else {
                ret = mid;
                j = mid - 1;
            }
        }
        return ret;
    }

    


    

    private static int lower_bound(List<Integer> list, int val) {
        int ans = -1, lo = 0, hi = list.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (list.get(mid) <= val) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private static int lower_bound(List<Long> list, long val) {
        int ans = -1, lo = 0, hi = list.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (list.get(mid) <= val) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private static int lower_bound(int[] arr, int val) {
        int ans = -1, lo = 0, hi = arr.length - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] <= val) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private static int lower_bound(long[] arr, long val) {
        int ans = -1, lo = 0, hi = arr.length - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] <= val) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    

    private static int upper_bound(List<Integer> list, int val) {
        int ans = list.size(), lo = 0, hi = ans - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (list.get(mid) >= val) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    private static int upper_bound(List<Long> list, long val) {
        int ans = list.size(), lo = 0, hi = ans - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (list.get(mid) >= val) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    private static int upper_bound(int[] arr, int val) {
        int ans = arr.length, lo = 0, hi = ans - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] >= val) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    private static int upper_bound(long[] arr, long val) {
        int ans = arr.length, lo = 0, hi = ans - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] >= val) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    


    private static int find(int x, int[] parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }

    private static boolean union(int x, int y, int[] parent, int[] rank) {
        int lx = find(x, parent), ly = find(y, parent);
        if (lx == ly)
            return false;
        if (rank[lx] > rank[ly])
            parent[ly] = lx;
        else if (rank[lx] < rank[ly])
            parent[lx] = ly;
        else {
            parent[lx] = ly;
            rank[ly]++;
        }
        return true;
    }

    


    public static class SegmentTree {
        int n;
        long[] arr, tree;

        SegmentTree(long[] arr) {
            this.arr = arr;
            this.n = arr.length;
            this.tree = new long[(n << 2)];
            build(1, 0, n - 1);
        }

        void build(int id, int start, int end) {
            if (start == end)
                tree[id] = arr[start];
            else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                build(left, start, mid);
                build(right, mid + 1, end);
                tree[id] = Math.min(tree[left], tree[right]);
            }
        }

        long query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }

        long query(int id, int start, int end, int l, int r) {
            if (end < l || r < start)
                return INF;
            if (start == end)
                return tree[id];
            else if (l <= start && end <= r)
                return tree[id];
            else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                return Math.min(query(left, start, mid, l, r), query(right, mid + 1, end, l, r));
            }
        }
    }

    


    static class Trie {
        class Node {
            Node[] children;
            boolean isEnd;

            Node() {
                children = new Node[26];
            }
        }

        Node root;

        Trie() {
            root = new Node();
        }

        public void insert(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null)
                    curr.children[ch - 'a'] = new Node();
                curr = curr.children[ch - 'a'];
            }
            curr.isEnd = true;
        }

        public boolean find(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null)
                    return false;
                curr = curr.children[ch - 'a'];
            }
            return curr.isEnd;
        }
    }

    


    static class FT {
        long[] tree;
        int n;

        FT(int[] arr, int n) {
            this.n = n;
            this.tree = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                update(i, arr[i - 1]);
            }
        }

        void update(int idx, int val) {
            while (idx <= n) {
                tree[idx] += val;
                idx += idx & -idx;
            }
        }

        long query(int l, int r) {
            return getSum(r) - getSum(l - 1);
        }

        long getSum(int idx) {
            long ans = 0L;
            while (idx > 0) {
                ans += tree[idx];
                idx -= idx & -idx;
            }
            return ans;
        }
    }

    


    static class BIT {
        long[][] tree;
        int n, m;

        BIT(int[][] mat, int n, int m) {
            this.n = n;
            this.m = m;
            tree = new long[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    update(i, j, mat[i - 1][j - 1]);
                }
            }
        }

        void update(int x, int y, int val) {
            while (x <= n) {
                int t = y;
                while (t <= m) {
                    tree[x][t] += val;
                    t += t & -t;
                }
                x += x & -x;
            }
        }

        long query(int x1, int y1, int x2, int y2) {
            return getSum(x2, y2) - getSum(x1 - 1, y2) - getSum(x2, y1 - 1) + getSum(x1 - 1, y1 - 1);
        }

        long getSum(int x, int y) {
            long ans = 0L;
            while (x > 0) {
                int t = y;
                while (t > 0) {
                    ans += tree[x][t];
                    t -= t & -t;
                }
                x -= x & -x;
            }
            return ans;
        }
    }
}